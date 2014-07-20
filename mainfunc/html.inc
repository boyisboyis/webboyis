<?php

	function link_style($path){
		return "<link type='text/css' rel='stylesheet' href=".$path."></link>";
	}

	function input_hidden($name, $value){
		return "<input id=".$name." type='hidden' name=".$name." value=".$value.">";
	}

?>