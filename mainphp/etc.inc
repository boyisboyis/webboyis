<?php

	class Etc{

		public static function encodemain($en=null){
			if($en==null || $en=="") return;
			$md5 = md5($en);

		}

		public static function getpath(){
			$request_uri = $_SERVER['REQUEST_URI'];
			echo $request_uri;
			$ex = explode("/", $request_uri);
			return array_filter($ex);
		}

		public static function requestpath($path){

		}

	}

?>