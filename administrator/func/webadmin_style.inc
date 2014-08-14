<?php
	
	function admin_style_head_tag($type_admin=1){ // 1 is login already, 0 is no login
		$str = "<head>";
		$str .= admin_meta_tags();
		$str .= link_style("/adminwebboyis/css/admin_main.css");
		$str .= javascript_tags('/js/ext/jquery.js');
		if($type_admin==0){
			$str .= javascript_login_admin();
		}
		$str .= "</head>";
		return $str;
	}

	function admin_style_html_element($body, $type_admin){
		$str = "<html>";
		$str .= admin_style_head_tag($type_admin);
		$str .= $body;
		$str .= "</html>";
		return $str;
	}

	function admin_style_header(){
		$str = "<div id='wrap-admin-header'>";
		$str .= "<div class='ah-w'>";
		$str .= "</div>";
		$str .= "</div>";
		return $str;
	}

	function admin_style_footer(){
		$str = "<div id='wrap-admin-footer'>";
		$str .= "<div class='af-w'>";
		$str .= "Webadmin created by ".user_create().", contact me <a href='mailto:".user_create('email')."'>".user_create('email')."</a>";
		$str .= "</div>";
		$str .= "</div>";
		return $str;
	}

	function admin_style($body, $type_admin){
		$str = "<body>";
		$str .= admin_style_header();
		$str .= "<div id='wrap-admin-content'>".$body."</div>";
		$str .= admin_style_footer();
		$str .= "</body>";
		return admin_style_html_element($str, $type_admin);
	}

	function admin_login_style(){
		$str = "<div class='al-w'>";
		$str .= "<div id='admin-login-content'>";
		$str .= "<div class='al-t'>";
		$str .= "<p>LOGIN</p>";
		$str .= "</div>";
		$str .= "<div class='al-c'>";
		$str .= "<div>";
		$str .= "<p id='login-error'></p>";
		$str .= "</div>";
		$str .= "<div id='login-form'>";
		$str .= "<input type='input'  id='username' name='username' class='input_style' placeholder='Username'>";
		$str .= "<div style='margin-top:10px;'></div>";
		$str .= "<input type='password' id='password' name='password' class='input_style' placeholder='Password'>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= "<div id='submit-form'>";
		$str .= "<p>SIGN IN</p>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= "</div>";
		return $str;
	}

	function admin_controller_style($menuselect, $arr_etc=array()){
		$type = "";
		$str = "<div id='left-content'>";
		$str .= "<div>";
		$str .= "<ol class='non-list-style'>";
		$str .= "<li><a href='".$GLOBALS['adminpath']."?menus=addmenu'>ADD MENU</a></li>";
		$str .= "</ol>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= "<div id='right-content'>";
		if($menuselect=="main"){

		}
		else if($menuselect=='addmenu'){
			if(isset($arr_etc['type']) && $arr_etc['type']!=""){
				$type = $arr_etc['type'];
			}
			$str .= "<div id='add-menu'>";
			$str .= admin_addmenu_header();
			$str .= "<div id='add-menu-content'>";
			if($type == "add"){
				$str .= admin_addmenu_add();
			}
			else{
				$str .= admin_addmenu_main();
			}
			$str .= "</div>";
			$str .= "</div>";
			
		}
		$str .= "</div>";
		return $str;
	}

	function admin_addmenu_add(){
		$str = "";
		$str .= "<div>";
		$str .= "<form method='POST' action='?controller=addmenu&mode=add'>";
		$str .= "<table>";
		$str .= "<tr>";
		$str .= "<td class='b-right form-label'>Name TH</td>";
		$str .= "<td><input type='text' name='menuname_th'></td>";
		$str .= "</tr>";
		$str .= "<tr>";
		$str .= "<td class='b-right form-label'>Name EN</td>";
		$str .= "<td><input type='text' name='menuname_en'></td>";
		$str .= "</tr>";
		$str .= "<tr>";
		$str .= "<td class='b-right form-label'>Parent</td>";
		$str .= "<td>";
		$str .= "<select name='menuparent'>";
		$str .= "<option value=0>Main</option>";
		$str .= get_parent_addmenu();
		$str .= "</select>";
		$str .= "</td>";
		$str .= "</tr>";
		$str .= "<tr>";
		$str .= "<td class='b-right form-label'>Position</td>";
		$str .= "<td>";
		$str .= "<select name='menuposition'>";
		$str .= "<option value='left'>LEFT</option>";
		$str .= "<option value='right'>RIGHT</option>";
		$str .= "</select>";
		$str .= "</td>";
		$str .= "</tr>";
		$str .= "<tr>";
		$str .= "<td colspan='2'><input type='submit' value='SUBMIT'></td>";
		$str .= "</tr>";
		$str .= "<table>";
		$str .= "</form>";
		$str .= "</div>";
		return $str;
	}

	function admin_addmenu_header(){
		$str = "";
		$str .=  "<div id='add-menu-header'>";
		$str .= "<div id='add-menu-h-left'>";
		$str .= "<a href='?menus=addmenu&type=add' class='alinkhead'>ADD</a>";
		$str .= "<a href='?controller=addmenu&mode=gen' class='alinkhead'>GEN MENU</a>";
		$str .= "</div>";
		$str .=  "</div>";
		return $str;
	}
	function admin_addmenu_main(){
		$str = "";
		$result = sql_getall("SELECT * FROM menu, translate_menu WHERE menu.menuid = translate_menu.menuid and menu.parentid = 0");
		$str .= "<table>";
		$str .= "<thead>";
		$str .= "<tr>";
		$str .= "<td>NAME</td>";
		$str .= "<td>sequence</td>";
		$str .= "<td>VISIBILITY</td>";
		$str .= "</tr>";
		$str .= "<thead>";
		$str .= "<tbody>";
		$n = count($result);
		if($n<=0){
			$str .= "menu 0";
		}
		else{
			for($i=0;$i<$n;$i++){
				$str .= "<tr>";
				$str .= "<td class='td-main'><a href='#'>".$result[$i]['menu_th']."</a></td>";
				$str .= "<td>";
				if($i>=0 && $i+1<$n){
					$str .= "DOWN";
				}
				if($i>0 && $i-1<$n){
					$str .= "<a href='?controller=addmenu&mode=up&main=1&seq=".$i."'>UP</a>";
				}
				$str .= "</td>";
				if($result[$i]['visible']==0){
					$str .= "<td><a href='#'>SHOW</a></td>";
				}
				else{
					$str .= "<td><a href='#'>HIDE</a></td>";
				}
				$str .= "</tr>";
				$parentid = $result[$i]['menuid'];
				//echo "SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.parentid=".$parentid." ORDER BY seq";
				//echo "<br>";
				$parentdata = sql_getall("SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.parentid=".$parentid." ORDER BY seq");
				$k = count($parentdata);
				if($k > 0){
					for($j=0;$j<$k;$j++){
						$str .= "<tr>";
						$str .= "<td class='td-child'><a href='#'>".$parentdata[$j]['menu_th']."</a></td>";
						$str .= "<td>";
						if($j>=0 && $j+1<$n){
							$str .= "DOWN";
						}
						if($j>0 && $j-1<$n){
							$str .= "UP";
						}
						$str .= "</td>";
						if($parentdata[$j]['visible']==0){
							$str .= "<td><a href='#'>SHOW</a></td>";
						}
						else{
							$str .= "<td><a href='#'>HIDE</a></td>";
						}
						$str .= "</tr>";
					}
				}
				//$result = sql_getall("SELECT * FROM menu, translate_menu WHERE menu.parentid=".$parentid." ORDER BY seq");
			}
			//$str .= "menu ".count($result);
		}
		$str .= "</tbody>";
		$str .= "</table>";
		return $str;
	}

	function admin_meta_tags(){
		$str = "";
		$str .= meta_tags(
			array(
				"name" => "viewport",
				"content" => "'width=device-width, initial-scale=1, maximum-scale=1'"
			)
		);
		return $str;
	}


	function javascript_login_admin(){
		$str = "";
		$str .= javascript_tags("/adminwebboyis/javascript/admin_login.js");
		return $str;
	}

	function get_parent_addmenu(){
		$str = "";
		$sql = "SELECT * FROM menu, translate_menu where menu.menuid = translate_menu.menuid and menu.parentid = 0";
		$result = sql_getall($sql);
		if(count($result) > 0){
			$n = count($result);
			for($i=0; $i<$n; $i++){
				$str .= "<option value='".$result[$i]['menuid']."'>".$result[$i]['menu_th']."</option>";
			}
		}
		return $str;
	}

?>