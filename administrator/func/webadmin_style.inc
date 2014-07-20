<?php
	
	function admin_style_head_tag($type_admin=1){ // 1 is login already, 0 is no login
		$str = "<head>";
		$str .= link_style("http://localhost/administrator/css/admin_main.css");
		$str .= "</head>";
		return $str;
	}

	function admin_style_html_element($body, $type_admin){
		$str = "<html>";
		$str .= admin_style_head_tag($type_admin);
		$str .= $body;
		$str .= "</html>";
		return $str;
	}

	function admin_style_header(){
		$str = "<div id='wrap-admin-header'>";
		$str .= "</div>";
		return $str;
	}

	function admin_style_footer(){
		$str = "<div id='wrap-admin-footer'>";
		$str .= "</div>";
		return $str;
	}

	function admin_style($body, $type_admin){
		$str = "<body>";
		$str .= admin_style_header();
		$str .= "<div id='wrap-admin-content'>".$body."</div>";
		$str .= admin_style_footer();
		$str .= "</body>";
		return admin_style_html_element($str, $type_admin);
	}

	function admin_login_style(){
		$str = "<div>";
		$str .= "</div>";
		return $str;
	}

?>