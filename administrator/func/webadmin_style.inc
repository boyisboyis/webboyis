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
		$str .= "<p class='login-error'></p>";
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

	function admin_controller_style(){
		$str = "<div id='left-content'>";
		$str .= "<div>";
		$str .= "<ol class='non-list-style'>";
		$str .= "<li><a href='".$GLOBALS['adminpath']."?addmenu=left'>ADD MENU</a></li>";
		$str .= "</ol>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= "<div id='right-content'>";
		$str .= "</div>";
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

?>