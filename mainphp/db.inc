<?php

	class DB{

		private $host, $dbname, $username, $password;
		function __construct(){
			require_once '../config/db_config.inc';
		}
	}

?>