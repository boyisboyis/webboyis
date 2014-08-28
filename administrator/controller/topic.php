<?php

	if(!isset($_GET['mode']) || trim($_GET['mode'])==""){
		go_path($GLOBALS['adminpath']);
	}
	$mode = trim($_GET['mode']);
	if($mode == 'add'){
		addnewtopic();
	}

	function addnewtopic(){
		if(!isset($_POST['subject'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuparent'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['shownow'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['textarea'])){
			go_path($GLOBALS['adminpath']);
		}

		$subject = trim($_POST['subject']);
		$menuid = trim($_POST['menuparent']);
		$text = trim($_POST['textarea']);
		$shownow = trim($_POST['shownow']);
		/*echo $subject.br();
		echo $menuid.br();
		echo $text.br();
		echo $shownow.br();*/
		$arr = array();
		$arr['subject'] = $subject;
		$arr['text'] = htmlentities($text, ENT_QUOTES);
		//print_r($arr);
		$filename = code_str((new DateTime())->getTimestamp().code_str(rand(0,1000)));
		$sql = "SELECT count(*) FROM topic WHERE menuid=$menuid";
		$topicseq = sql_getone($sql) + 1;
		if($shownow=='noshow'){
			$sql = "INSERT INTO topic (menuid, filename, showtopic, topicseq, datecreate, dateupdate) VALUES ({$menuid}, '{$filename}', 0, {$topicseq}, NOW(), NOW());";
		}
		else{
			$sql = "INSERT INTO topic (menuid, filename, showtopic, topicseq, datecreate, dateupdate, dateshow) VALUES ({$menuid}, '{$filename}', 1, {$topicseq}, NOW(), NOW(), NOW());";
		}
		//echo $sql.br();
		$result = sql_simple($sql);
		//$sql = "INSERT INTO topic (menuid, filename, topic, datecreate, dateupdate,dateshow) VALUES ()";
		create_file_json($arr, "data/topic/".$menuid.'/',$filename);
		go_path("?menus=topic");
		//create_file_json();
	}

?>