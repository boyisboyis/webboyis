<?php

	class path{

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

	}

?>