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
						<input data-ng-focus="focus(1)" data-ng-blur="blur(1)" type="text" name="username" data-ng-model="data.username" required="required" autocomplete="off">
						<span class="bglight" ng-class="{enter: data.ustate, leave: !data.ustate}"></span>
						<span class="bottombar" ng-class="{enter: data.ustate, leave: data.ustate}"></span>
						<label class="animate" ng-class="{enter: data.ufocused, leave: data.uleaved}">Username</label>
						<!-- <input data-ng-init="ufocused = false; uleaved = false" data-ng-focus="ufocused = true; uleaved = false" data-ng-blur="ufocused = false; uleaved = true" type="text" name="username" data-ng-model="data.username" required="required" autocomplete="off">
						<span class="bglight" ng-class="{enter: ufocused, leave: uleaved}"></span>
						<span class="bottombar" ng-class="{enter: ufocused, leave: uleaved}"></span>
						<label class="animate" ng-class="{enter: ufocused, leave: uleaved}">Username</label> -->
					</div>
					<div class="input-group">
						<input data-ng-focus="pfocused = true; pleaved = false" data-ng-blur="pfocused = false; pleaved = true" type="password" name="password" data-ng-model="data.password" required="required" autocomplete="off">
						<span class="bglight" ng-class="{enter: pfocused, leave: pleaved}"></span>
						<span class="bottombar" ng-class="{enter: pfocused, leave: pleaved}"></span>
						<label class="animate" ng-class="{enter: pfocused, leave: pleaved}">Password</label>
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
			loginApp.controller('loginController', function($scope, $http){
			$scope.data = {
				ufocused : false,
				uleaved : false,
				ustate : false
			}
			$scope.focus = function(res){
				var i = parseInt(res);
				if(i==1){
					if(typeof $scope.data.username == "undefined" || $scope.data.username == ""){
						$scope.data = {
							ufocused : true,
							uleaved : false
						}
					}
					$scope.data.ustate = true;
				}
			}

			$scope.blur = function(res){
				var i = parseInt(res);
				if(i==1){
					if(typeof $scope.data.username == "undefined" || $scope.data.username == ""){
						$scope.data = {
							ufocused : false,
							uleaved : true
						}
					}
				}
			}

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
					
					$scope.data.ele.complete = {
						show : true
					};
				}
			});

			
		</script>
	</body>
</html>