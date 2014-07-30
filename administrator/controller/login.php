<?php
	
	$error = get_text("u_o_p_in");
	if(!isset($_POST['username']) || strlen(trim($_POST['username']))<=0){
		echo $error;
		exit();
	}
	if(!isset($_POST['password']) || $_POST['password']==''){
		echo $error;
		exit();
	}
	$username = $_POST['username'];
	$password = $_POST['password'];
	$sql = "SELECT * FROM admin_web WHERE adminuser='{$username}'";
	$result = sql_getall($sql);
	if(count($result)>0){
		$pass = $result[0]['adminpass'];
		if(check_md5(code_str($password),$pass)){
			echo "ok";
			$_SESSION['admin_login'] = "1";
		}
		else{
			echo $error;
		}
	}
	else{
		echo $error;
		exit();
	}

?>