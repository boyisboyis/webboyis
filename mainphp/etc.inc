<?php

	class Etc{

		public static function encodemain($en=null){
			if($en==null || $en=="") return;
			$md5 = md5($en);

		}

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

	}

?>