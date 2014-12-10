<?php

	class Path{

		public function getpath(){
			$request_uri = $_SERVER['REQUEST_URI'];
			$ex = explode("/", $request_uri);
			$n = count($ex);
			$arr = array();
			for($i=0;$i<$n;$i++){
				if($ex[$i]!="" && !is_null($ex[$i])){
					$arr[] = $ex[$i];
				}
			}
			if(count($arr) > 0){
				$re = explode('?', $arr[count($arr)-1]);
				$arr[count($arr)-1] = $re[0];
			}
			return $arr;
		}

		public function getbasepath(){
			$http = isset($_SERVER['HTTPS'])?"https://":"http://";
			return $http.$_SERVER["HTTP_HOST"];
		}

		public function requestPath($path="home", $file=""){
			$path_path = array(
				"home" => "home.php",
				"boyisadmin" => "administrator/adminhome.php",
				"boyisadmin_login" => "administrator/adminlogin.php",
			);
			$path_ext = array(
				"angular" => "js/ext/angular.min.js"
			);
			$path_js = array(
				"adminhome" => "js/min/adminhome.min.js"
			);
			if($path == "ext" && isset($path_ext[$file])){
				echo file_get_contents($path_ext[$file]);
			}
			else if($path == "min" && isset($path_js[$file])){
				echo file_get_contents($path_js[$file]);
			}
			else if($path!="" && isset($path_path[$path])){
				require_once $path_path[$path];
			}
			else{
			 	require_once $path_path['home'];
			}
		}

		public function requestController($path){
			$path_admin_controller = array(
				"loginadmin" => "administrator/controller/admin_login.php",
				"checkloginadmin" => "administrator/controller/admin_login.php"
			);
			if(isset($path_admin_controller[$path])){
				require_once $path_admin_controller[$path];
			}
		}

		public function requestOtherPath($path){
			if(file_exists($path)) require_once $path;
			return "";
		}

	}

?>