<?php

	class Etc{

		public static function encodemain($en=null){
			if($en==null || $en=="") return;
			$md5 = md5($en);
		}

		public static function decodemain($de=null){
			if($de==null || $de=="") return;

		}

		public static function passwordencode($en=null){
			if($en==null || $en=="") return;
			return md5(md5($en).":passwordcodeboyis");
		}

		public static function genuserid(){
			return md5(time());
		}

		public static function show_arr($arr){
			echo "<pre>";
			print_r($arr);
			echo "</pre>";
		}

		public static function level_access(){
			if(self::login()){
				return true;
			}
			return false;
		}

		public static function login(){
			return (isset($_SESSION['member']) && $_SESSION['member'])?true:false;
		}

		public static function loginadmin(){
			return (isset($_SESSION['admin']) && $_SESSION['admin'])?true:false;
		}

		public static function getAuth($auth=""){
			$data = explode(",", $auth);
			if($auth=="" || count($data) <= 0) return;
			$ret = array();
			foreach($data as $value){
				$e = explode(":", $value);
				$ret[$e[0]] = $e[1];
			} 
			return $ret;
		}

	}

?>