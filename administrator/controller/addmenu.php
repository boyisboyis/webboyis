<?php

	if(!isset($_GET['mode']) || trim($_GET['mode'])==""){
		go_path($GLOBALS['adminpath']);
	}
	$mode = trim($_GET['mode']);
	if($mode==1){
		addmenu();
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

?>