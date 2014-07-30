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
		$ret = "";
		if(mysqli_num_rows($result) > 0){
			$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
			$ret = current($row);
		}
		return $ret;
	}

	function sql_getall($sql){
		$result = exec_sql($sql);
		$ret = array();
		if(mysqli_num_rows($result) > 0){
			while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC)) {
				$ret[] = $row;
			}
		}
		return $ret;
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