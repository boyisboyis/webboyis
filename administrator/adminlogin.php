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
			//echo $html->link_tag($basepath."/css/min/main.css");
			echo $html->link_tag($basepath."/css/min/mainadmin.css");
		?>
	</head>
	<body data-ng-controller='loginController as data' data-ng-init="state.checkerror=false;state.check=false">
		<div id='wrapper'>
			<div>
				<h1>LOGIN</h1>
			</div>
			<div>
				<form name="loginForm" autocomplete="off"  novalidate>
					<div class="input-group">
						<input data-ng-focus="focus(1)" data-ng-blur="blur(1)" type="text" name="username" data-ng-model="data.username" required="required" autocomplete="off">
						<span class="bglight" data-ng-class="{enter: events.ustatee, leave: events.ustatel}"></span>
						<span class="bottombar" data-ng-class="{enter: events.ustatee, leave: events.ustatel}"></span>
						<label class="animate" data-ng-class="{enter: events.ufocused, leave: events.uleaved}">Username</label>
						<!-- <input data-ng-init="ufocused = false; uleaved = false" data-ng-focus="ufocused = true; uleaved = false" data-ng-blur="ufocused = false; uleaved = true" type="text" name="username" data-ng-model="data.username" required="required" autocomplete="off">
						<span class="bglight" ng-class="{enter: ufocused, leave: uleaved}"></span>
						<span class="bottombar" ng-class="{enter: ufocused, leave: uleaved}"></span>
						<label class="animate" ng-class="{enter: ufocused, leave: uleaved}">Username</label> -->
					</div>
					<div class="input-group">
						<input data-ng-focus="focus(2)" data-ng-blur="blur(2)" type="password" name="password" data-ng-model="data.password" required="required" autocomplete="off">
						<span class="bglight" data-ng-class="{enter: events.pstatee, leave: events.pstatel}"></span>
						<span class="bottombar" data-ng-class="{enter: events.pstatee, leave: events.pstatel}"></span>
						<label class="animate" data-ng-class="{enter: events.pfocused, leave: events.pleaved}">Password</label>
					</div>
					<div id="show-state">
						<span class="success" data-ng-show="state.check">Login Success</span>
						<span class="error" data-ng-show="state.checkerror">{{data.error}}</span>
					</div>
					<div>
						<button name="submit" data-ng-click="checkLogin()" data-ng-disabled="loginForm.$invalid">Login</button>
					</div>
				</form>
				<!-- <div>
					<p data-ng-show="data.ele.complete">Login Complete</p>
				</div> -->
			</div>
		</div>
		<?php
			echo $html->script_tag($basepath."/js/ext/angular.min.js");
		?>
		<script type="text/javascript">
			var loginApp = angular.module('loginApp', []);
			loginApp.controller('loginController', function($scope, $http){
			$scope.data = {
				username : "",
				password : "",
				error : "",
				check : ""
			}
			$scope.events = {
				ufocused : false,
				uleaved : false,
				ustatee : false,
				ustatel : false,
				pfocused : false,
				pleaved : false,
				pstatee : false,
				pstatel : false
			}
			$scope.focus = function(res){
				console.log(this);
				var i = parseInt(res);
				if(i == 1){
					if(typeof $scope.data.username == "undefined" || $scope.data.username == ""){
						$scope.events.ufocused = true;
						$scope.events.uleaved = false;
					}
					$scope.events.ustatel = false;
					$scope.events.ustatee = true;
				}
				else if(i == 2){
					if(typeof $scope.data.password == "undefined" || $scope.data.password == ""){
						$scope.events.pfocused = true;
						$scope.events.pleaved = false;
					}
					$scope.events.pstatel = false;
					$scope.events.pstatee = true;
				}
			}

			$scope.blur = function(res){
				var i = parseInt(res);
				if(i==1){
					console.log($scope.data.username)
					if(typeof $scope.data.username == "undefined" || $scope.data.username == ""){
						$scope.events.ufocused = false;
						$scope.events.uleaved = true;
					}
					$scope.events.ustatel = true;
					$scope.events.ustatee = false;
				}
				else if(i == 2){
					if(typeof $scope.data.password == "undefined" || $scope.data.password == ""){
						$scope.events.pfocused = false;
						$scope.events.pleaved = true;
					}
					$scope.events.pstatel = true;
					$scope.events.pstatee = false;
				}
			}

			$scope.checkLogin = function(){
					var url = "boyisadmin/controller/checklogin";
					$scope.state.checkerror = false;
					$scope.state.check = false;
					$http({
						"method" : "POST",
						"url" : url,
						"data" : {username: $scope.data.username, password : $scope.data.password},
						"headers" : {'Content-Type': 'application/x-www-form-urlencoded'}
					}).success(function(data,status){
						console.log(data, status);
						if(status == 200 && data.status == "success"){
							$scope.state.check = true;
							setTimeout(function(){
								window.location.href = data.url;
							}, 1000);
						}
						else{
							$scope.data.error = data.desc;
							$scope.state.checkerror = true;
						}
					});
				}
			});		
		</script>
	</body>
</html>