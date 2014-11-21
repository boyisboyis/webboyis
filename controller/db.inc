<?php

	class DB{

		static $host, $dbname, $username, $password, $connect;
		public function __construct($host, $dbname, $username, $password){
			//echo $host;
			self::$host = trim($host);
			self::$dbname = trim($dbname);
			self::$username = trim($username);
			self::$password = trim($password);
			self::connectdb();
			//$this->host = trim("test");
			//echo $this->host;
			//$this->dbname = trim($db_name);
			//$this->username = trim($db_username);
			//$this->password = trim($db_password);
			//$this->connect = mysqli_connect($this->host, $this->username, $this->password, $this->dbname) or die("Error".mysqli_error($con));
		}

		private function connectdb(){
			self::$connect = mysqli_connect(self::$host, self::$username, self::$password, self::$dbname) or die("Error".mysqli_error($con));
		}

		private function query($sql){
			return mysqli_query(self::$connect, $sql);
		}

		public static function get_all($sql){
			$result = self::query($sql);
			$data = array();
			while($row = mysqli_fetch_assoc($result))$data[] = $row;
			return $data;
		}

		private function disconnect(){
			mysqli_close(self::$connect);
			//echo "disconnect";
		}

		public function __destruct(){
			self::disconnect();
		}
/*
		private static $host, $dbname, $username, $password, $connect;
		public function __construct(){
			require_once 'config/db_config.inc';
			$this->host = trim($host);
			$this->dbname = trim($db_name);
			$this->username = trim($db_username);
			$this->password = trim($db_password);
			self::connectdb();
		}

		private function getHost(){
			return $this->host;
		}

		private function getConnect(){
			return $this->connect;
		}

		private function test(){
			echo $this->host."<br/>";
			echo $this->dbname."<br/>";
			echo $this->username."<br/>";
			echo $this->password."<br/>";
		}

		private function test2(){
			echo self::$host."<br/>";
			echo self::$dbname."<br/>";
			echo self::$username."<br/>";
			echo self::$password."<br/>";
		}

		private function connectdb(){
			$this->connect = mysqli_connect($this->host, $this->username, $this->password, $this->dbname) or die("Error".mysqli_error($con));
			//print_r(self::querry("select * from user"));
			//echo "connect";
		}

		/*function otherconnectdb($host, $username, $password, $db){
			return mysqli_connect($host, $username, $password, $db);
		}

		private function querry($sql){
			//self::test();
			//self::test2();
			//self::getHost();
			//return (isset(self::$connect));
			//return mysqli_query($this->connect, $sql);
		}

		/*function get_one($sql){
			if($sql=="") return ;
			$result = get_all($sql);
			if(count($result)==0) return;

		}

		public static function get_all($sql){
			
			//self::test2();
			if($sql=="") return ;
			$result = self::querry($sql);
			return (count($result)==0)?null:$result;
		}

		function disconnect(){
			mysqli_close($this->connect);
			//echo "disconnect";
		}

		function __destruct(){
			self::disconnect();
		}*/
	}

?>