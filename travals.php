<?php

	$path = Etc::getpath();
	$content = new Path();
	$db = new Db();
	//$db->test();
	//echo Html::br();
	if(count($path)>0){
		// travals page
	}
	else{
		// main page
		$content->requestpath();
	}

?>