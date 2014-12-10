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
	<body style="height:100%; overflow: ;" scroll>
		<div id="wrapper" data-ng-controller="adminController" >
			<div id="wrap-left">
				<div id="button-small">a</div>
				<div id="logo"></div>
				<div id="nav">
					<div></div>
				</div>
			</div>
			<div id="wrap-right">
				<div id="right-header"></div>
				<div id="right-content">
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
					<span>aaaaa</span><br/><br/><br/>
				</div>
			</div>
		</div>
		<script type="text/javascript" src="/js/ext/angular"></script>
		<script type="text/javascript">
		/*var appadmin = angular.module('appAdminHome', []);
			appadmin.controller('adminController', function($scope, $http){
				console.log($scope)
			});*/
		</script>
		<script type="text/javascript" src="/js/min/adminhome"></script>
	</body>
</html>