<?php

	class DB{

		private $host, $dbname, $username, $password;
		function __construct(){
			require_once 'config/db_config.inc';
			$this->host = $host;
			$this->dbname = $db_name;
			$this->username = $db_username;
			$this->password = $db_password;
		}

		function test(){
			echo $this->host;
			echo $this->dbname;
			echo $this->username;
			echo $this->password;
		}

		function __destruct(){
			self::disconnect();
		}

		function disconnect(){
			//echo "disconnect";
		}

	}

?>