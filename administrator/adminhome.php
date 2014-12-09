<?php
	
	if(!Etc::login() || !Etc::loginadmin()){
		echo "test";
	}
	$html = new Html();
	$basepath = Path::getbasepath();

?>

<!DOCTYPE html>
<html data-ng-app="appAdminHome">
	<head>
		<title>Admin Page:BoyI's</title>
		<meta charset="UTF-8">
		<meta name="viewport" content="initial-scale=1, width=device-width">
		<link rel="stylesheet" type="text/css" href="/css/min/mainadminhome.css">
	</head>
	<body>
		<div id="wrapper" data-ng-controller="adminController">
			<div id="wrap-left">
				<div id="button-small">a</div>
				<div id="nav"></div>
			</div>
			<div id="wrap-right">
				<div id="right-header"></div>
				<div id="right-content">aaa</div>
			</div>
		</div>
		<script type="text/javascript" src="/js/ext/angular.min.js"></script>
		<script type="text/javascript" src="/js/min/adminhome.min.js"></script>
	</body>
</html>