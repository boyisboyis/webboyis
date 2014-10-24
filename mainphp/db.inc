<?php

	class DB{

		private $host, $dbname, $username, $password, $connect;
		function __construct(){
			require_once 'config/db_config.inc';
			$this->host = trim($host);
			$this->dbname = trim($db_name);
			$this->username = trim($db_username);
			$this->password = trim($db_password);
			self::connectdb();
		}

		function test(){
			echo $this->host."<br/>";
			echo $this->dbname."<br/>";
			echo $this->username."<br/>";
			echo $this->password."<br/>";
		}

		private function connectdb(){
			$this->connect = mysqli_connect($this->host, $this->username, "123261129", $this->dbname) or die("Error".mysqli_error($con));
		}

		/*function otherconnectdb($host, $username, $password, $db){
			return mysqli_connect($host, $username, $password, $db);
		}*/

		private function querry($sql){
			return mysqli_query($this->connect, $sql);
		}

		function get_one($sql){
			return ;
		}

		function get_all($sql){
			return ;
		}

		function disconnect(){
			mysqli_close($this->connect);
			//echo "disconnect";
		}

		function __destruct(){
			self::disconnect();
		}

	}

?>