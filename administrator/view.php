<?php
	
	require_once ('include.php');
	$type_admin = 1;
	$str = "";
	admin_only_computer();
	if(!isset($_SESSION['admin_login']) || check_username_code($_SESSION['admin_login'])){
		$type_admin = 0;
		$str = admin_login_style();
	}
	else if(isset($_SESSION['admin_login'])){
		$str = admin_controller_style();
	}
	echo admin_style($str, $type_admin);

?>