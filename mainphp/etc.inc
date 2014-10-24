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
				if($ex[$i]!="" && $ex[$i]!=null){
					$arr[] = $ex[$i];
				}
			}
			//echo $request_uri;
			//$ex = array_filter(explode("/", $request_uri));
			//self::show_arr($arr);
			if(count($arr) > 0){
				//$last = $ex[count($ex)-1];
				$re = explode('?', $arr[count($arr)-1]);
				$arr[count($arr)-1] = $re[0];
				//$ex[count($ex)-1];
			}
			//self::show_arr($arr);
			return $arr;
		}

		public static function requestpath($path){

		}

		public static function show_arr($arr){
			echo "<pre>";
			print_r($arr);
			echo "</pre>";
		}

	}

?>