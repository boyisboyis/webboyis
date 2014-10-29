<?php

	class Path{

		public static function getpath(){
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

		public static function getbasepath(){
			$http = isset($_SERVER['HTTPS'])?"https://":"http://";
			return $http.$_SERVER["HTTP_HOST"];
		}

		public static function requestpath($path="home", $file=""){
			if($path=='home'){
				require_once 'home.php';
			}
			else if($path=='boyisadmin'){
				require_once 'administrator/adminhome.php';
			}
			else if($path=='boyisadmin_login'){
				require_once 'administrator/adminlogin.php';
			}
			else if($path=='ext'){
				if($file=="angular"){
					echo file_get_contents("js/ext/angular.min.js");
				}
			}
			else{
				require_once 'home.php';
			}
		}

		public static function requestController($path){
			if($path=="loginadmin"){
				require_once 'administrator/controller/admin_login.php';
			}
		}

	}

?>