<?php

	if(!isset($_GET['mode']) || trim($_GET['mode'])==""){
		go_path($GLOBALS['adminpath']);
	}
	$mode = trim($_GET['mode']);
	if($mode == 'add'){
		addtopic();
	}

	function addtopic(){
		if(!isset($_POST['subject'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuparent'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['textarea'])){
			go_path($GLOBALS['adminpath']);
		}

		$subject = trim($_POST['subject']);
		$menu = trim($_POST['menuparent']);
		$text = trim($_POST['textarea']);
		echo $subject;
		echo $menu;
		echo $text;
	}

?>