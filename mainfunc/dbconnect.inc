<?php
	
	function init_db(){
		GLOBAL $connection_db;
		require_once('config/db_config.inc');
		$connection_db = mysqli_connect($host,$db_username,$db_password,$db_name);
		if(mysqli_connect_errno()){
			require_once("errormessages/db_error.php");
			exit();
		}
	}

	function sql_getone($sql){
		$result = exec_sql($sql);
		return $result;
	}

	function sql_getall($sql){
		$result = exec_sql($sql);
		return $result;
	}

	function sql_simple($sql){
		$result = exec_sql($sql);
		return $result;
	}

	function exec_sql($sql){
		GLOBAL $connection_db;
		$result = mysqli_query($connection_db, $sql);
		return $result;
	}

	function close_db(){
		GLOBAL $connection_db;
		mysqli_close($connection_db);
	}

?>