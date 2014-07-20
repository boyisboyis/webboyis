<?php

	function admin_style_header(){
		$str = "<div id='wrap-amin-header'>";
		$str .= "</div>";
	}

	function admin_style_footer(){
		$str = "<div id='wrap-amin-footer'>";
		$str .= "</div>";
	}

	function admin_style($body){
		$str = admin_style_header();
		$str .= $body;
		$str .= admin_style_footer();
	}

?>