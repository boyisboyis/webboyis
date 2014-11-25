<?php
	
	$html = new Html();
	$basepath = Path::getbasepath();
	//echo Path::getbasepath();
	//about 6.30

?>

<!DOCTYPE html>
<html data-ng-app='loginApp'>
	<head>
		<title>Login Admin</title>
		<meta charset="UTF-8">
		<?php
			echo $html->link_tag($basepath."/css/min/main.css");
			echo $html->link_tag($basepath."/css/min/mainadmin.css");
		?>
	</head>
	<body data-ng-controller='loginController as data' data-ng-init="data.ele = {complete:false}">
		<div id='wrapper'>
			<div>
				<h1>Login</h1>
			</div>
			<div>
				<form name="loginForm" autocomplete="off"  novalidate>
					<div class="input-group">
						<input type="text" name="username" data-ng-model="data.username" required="required" focus-me="focusInput" autocomplete="off">
						<label data-ng-view="animate">Username</label>
					</div>
					<div class="input-group">
						<input type="password" name="password" data-ng-model="data.password" required="required" autocomplete="off">
						<label >Password</label>
					</div>
					<div>
						<button name="submit" data-ng-click="checkLogin()" data-ng-disabled="loginForm.$invalid">Login</button>
					</div>
				</form>
				<div>
					<p data-ng-show="data.ele.complete">Login Complete</p>
				</div>
			</div>
		</div>
		<?php
			echo $html->script_tag($basepath."/js/ext/angular.min.js");
		?>
		<script type="text/javascript">
			var loginApp = angular.module('loginApp', []);
			loginApp.directive("fucusMe", function($timeout){
				return {
					link: function(scope, element, attrs){
						console.log(scope, element, attrs);
					}
				};
			});
			loginApp.controller('loginController', function($scope, $http){
				//$scope.data.username = null;
				//$scope.data.password = null;
				console.log($scope);
				$scope.checkLogin = function(){
					var url = "boyisadmin/controller/checklogin";
					$http({
						"method" : "POST",
						"url" : url,
						"data" : {username: $scope.data.username, password : $scope.data.password},
						"headers" : {'Content-Type': 'application/x-www-form-urlencoded'}
					}).success(function(data,status){
						console.log(data, status);
					})
					
					/*$http.post(, data).success(function(res){
						console.log(res);
					});*/
					$scope.data.ele.complete = {
						show : true
					};
				}
			});
			
		</script>
	</body>
</html>