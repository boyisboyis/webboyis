<?php
	
	if(!isset($_POST['username']) || strlen(trim($_POST['username']))<=0){
		echo '1';
		exit();
	}
	if(!isset($_POST['password']) || $_POST['password']==''){
		echo '2';
		exit();
	}
	$username = $_POST['username'];
	$password = $_POST['password'];
	$sql = "SELECT * FROM admin_web WHERE adminuser='{$username}'";
	$result = sql_getone($sql);
	$rowcount=mysqli_num_rows($result);
	if($rowcount>0){

	}
	else{
		echo '3';
		exit();
	}
	// if(check_md5()){

	// }
	//$_SESSION['admin_login'] = "test";
	//echo "ok";


?>