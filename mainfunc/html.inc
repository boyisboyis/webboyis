<?php

	function link_style($path){
		return "<link type='text/css' rel='stylesheet' href=".$path."></link>";
	}

	function input_hidden($name, $value){
		return "<input id=".$name." type='hidden' name=".$name." value=".$value.">";
	}

	function meta_tags($array=array()){
		if(!empty($array)){
			return "<meta ".create_tags($array)." >";
		}
		return "";
	}

	function create_tags($array){
		$str = "";
		foreach ($array as $key => $value) {
			$str .= $key." = ".$value." ";
		}
		return $str;
	}

	function char_entities($char=""){
		$char_entities = array(
			"copyright" => "&copy;", // ©
			"registrade" => "&reg;"  //®
		);
		if($char!=''){ 
			return $char_entities[$char];
		}
	}

?>