<?php

	function style_construct($head,$body){
		$str = "<html>";
		$str .= "<head>";
		$str .= link_style('css/main.css');
		$str .= "</head>";
		$str .= "<body>";
		$str .= $body;
		$str .= "</body>";
		$str .= "</html>";
		return $str;
	}

	function style_header(){
		$str = "<div id='header-wrap'>";
		$str .= "</div>";
		return $str;
	}

	function style_footer(){
		$str = "<div id='footer-wrap'>";
		$str .= "</div>";
		return $str;
	}

	function style_mainweb($content){
		$str = "<div id='wrapper' class='style-mainweb'>";
		$str .= style_header();
		$str .= "<div id='content-wrap'>";
		$str .= "<div id='content-menu-left'>";
		$str .= "</div>";
		$str .= "<div id='content-menu-center'>";
		$str .= $content;
		$str .= "</div>";
		$str .= "<div id='content-menu-right'>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= style_footer();
		$str .= "</div>";
		return $str;
	}

?>