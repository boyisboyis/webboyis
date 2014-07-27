<?php
	
	if(!isset($_POST['username']) || strlen(trim($_POST['username']))<=0){
		echo '1';
		exit();
	}
	if(!isset($_POST['password']) || $_POST['password']==''){
		echo '2';
		exit();
	}

	$_SESSION['admin_login'] = "test";
	echo "ok";


?>