<?php

	function style_construct($head,$body){
		$str = "<html>";
		$str .= "<head>";
		$str .= "</head>";
		$str .= "<body>";
		$str .= $body;
		$str .= "</body>";
		$str .= "</html>";
		return $str;
	}

	function style_header(){
		$str = "<div>";
		$str .= "</div>";
		return $str;
	}

	function style_footer(){
		$str = "<div>";
		$str .= "</div>";
		return $str;
	}

	function style_mainweb($content){
		$str = style_header();
		$str .= "<div>";
		$str .= "<div>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= style_footer();
		return $str;
	}

	function not_found(){
		echo "<div></div>";
	}

?>