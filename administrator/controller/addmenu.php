<?php

	if(!isset($_GET['mode']) || trim($_GET['mode'])==""){
		go_path($GLOBALS['adminpath']);
	}
	$mode = trim($_GET['mode']);
	if($mode=="add"){
		addmenu();
	}
	else if($mode=='gen'){
		gen_addmenu();
		go_path("?menus=addmenu");
	}
	else if($mode=='up'){
		menu_up();
	}
	else if($mode=='down'){
		menu_down();
	}
	else if($mode=='show'){
		menu_show();
	}
	else if($mode=="hide"){
		menu_hide();
	}

	function addmenu(){
		if(!isset($_POST['menuname_th'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuname_en'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuposition'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuparent'])){
			go_path($GLOBALS['adminpath']);
		}

		$menuname_th = trim($_POST['menuname_th']);
		$menuname_en = trim($_POST['menuname_en']);
		$menuposition = trim($_POST['menuposition']);
		$menuparent = trim($_POST['menuparent']);


		$sql = "SELECT count(*) FROM menu WHERE position='".$menuposition."' AND parentid=".$menuparent;
		$seq = sql_getone($sql);
		$sql = "INSERT INTO menu (position, seq, parentid) VALUES ('{$menuposition}', $seq , {$menuparent})";
		$result = sql_simple($sql);
		$sql = "SELECT * FROM menu WHERE position='".$menuposition."' AND seq=$seq AND parentid=".$menuparent;
		$result = sql_getall($sql);
		$sql = "INSERT INTO translate_menu (menuid, menu_th, menu_en) VALUES ({$result[0]['menuid']}, '{$menuname_th}', '{$menuname_en}')";
		$result = sql_simple($sql);

		go_path("?menus=addmenu");
	}

	function menu_up(){
		if(!isset($_GET['menuid'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_GET['parentid'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_GET['seq'])){
			go_path($GLOBALS['adminpath']);
		}

		$menuid = $_GET['menuid'];
		$parentid = $_GET['parentid'];
		$seques = $_GET['seq'];
		$sequesup = $seques - 1;
		$sql = "UPDATE menu SET seq={$seques} WHERE parentid={$parentid} AND seq={$sequesup}";
		sql_simple($sql);
		$sql = "UPDATE menu SET seq={$sequesup} WHERE parentid={$parentid} AND menuid={$menuid}";
		sql_simple($sql);
		gen_addmenu();
		go_path("?menus=addmenu");
	}

	function menu_down(){
		if(!isset($_GET['menuid'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_GET['parentid'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_GET['seq'])){
			go_path($GLOBALS['adminpath']);
		}

		$menuid = $_GET['menuid'];
		$parentid = $_GET['parentid'];
		$seques = $_GET['seq'];
		$sequesdown = $seques + 1;
		$sql = "UPDATE menu SET seq={$seques} WHERE parentid={$parentid} AND seq={$sequesdown}";
		sql_simple($sql);
		$sql = "UPDATE menu SET seq={$sequesdown} WHERE parentid={$parentid} AND menuid={$menuid}";
		sql_simple($sql);
		gen_addmenu();
		go_path("?menus=addmenu");
	}

	function menu_show(){
		if(!isset($_GET['menuid'])){
			go_path($GLOBALS['adminpath']);
		}
		$menuid = $_GET['menuid'];
		$sql = "UPDATE menu SET visible = 1 WHERE menuid=".$menuid;//UPDATE `webboyis`.`menu` SET `visible` = '1' WHERE `menu`.`menuid` = 1;
		sql_simple($sql);
		gen_addmenu();
		go_path("?menus=addmenu");
	}

	function menu_hide(){
		if(!isset($_GET['menuid'])){
			go_path($GLOBALS['adminpath']);
		}
		$menuid = $_GET['menuid'];
		$sql = "UPDATE menu SET visible = 0 WHERE menuid=".$menuid;//UPDATE `webboyis`.`menu` SET `visible` = '1' WHERE `menu`.`menuid` = 1;
		sql_simple($sql);
		gen_addmenu();
		go_path("?menus=addmenu");
	}

	function gen_addmenu(){
		$sql = "SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.parentid=0 AND menu.visible=1 ORDER BY menu.seq";
		$topmenu = sql_getall($sql);
		$data = array("th" => array(),"en" => array());
		$n = count($topmenu);
		for($i=0; $i<$n; $i++){
			$sql = "SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.visible=1 AND menu.parentid=".$topmenu[$i]['menuid']." ORDER BY menu.seq";
			$parentmenu = sql_getall($sql);
			foreach ($data as $key => $value) {
				$link = $topmenu[$i]['link'];
				if($link==""){
					$link="/";
				}
				$topdata = array(
					"name" => $topmenu[$i]['menu_'.$key],
					"link" => $link
				);
				$n_parentmenu = count($parentmenu);
				if($n_parentmenu > 0){
					for($j=0;$j<$n_parentmenu;$j++){
						$link = $parentmenu[$j]['link'];
						if($link==""){
							$link="/";
						}
						$parentdata =array(
							"name" => $parentmenu[$j]['menu_'.$key],
							"link" => $link
						);
						$topdata['parent'][] = $parentdata;
					}
				}
				$data[$key][$topmenu[$i]['position']][] = $topdata;
			}
		}
		gen_json_pattern($data);
		//
	}

?>