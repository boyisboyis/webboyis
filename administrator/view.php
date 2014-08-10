<?php
	
	require_once ('include.php');
	$type_admin = 1;
	$str = "";
	$etc_ar = array();
	admin_only_computer();
	if(!isset($_SESSION['admin_login']) || check_username_code($_SESSION['admin_login'])){
		$type_admin = 0;
		$str = admin_login_style();
	}
	else if(isset($_SESSION['admin_login'])){
		$menus = "";
		if(!isset($_GET['menus']) || $_GET['menus']==""){
			$menus = "main";
		}
		else{
			$menus = $_GET['menus'];
		}
		if(isset($_GET['type']) && $_GET['type']!=""){
			$etc_ar['type'] = $_GET['type'];
		}
		$str = admin_controller_style($menus, $etc_ar);
	}
	echo admin_style($str, $type_admin);

?>