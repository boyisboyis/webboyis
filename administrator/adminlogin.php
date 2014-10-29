<?php
	
	$html = new Html();
	$basepath = Path::getbasepath();
	//echo Path::getbasepath();
	//about 6.30

?>

<!DOCTYPE html>
<html>
	<head>
		<title>Login Admin</title>
		<meta charset="UTF-8">
		<?php
			echo $html->script_tag($basepath."/js/ext/angular.min.js", true);
			echo $html->link_tag($basepath."/css/min/main.css");
			echo $html->link_tag($basepath."/css/min/mainadmin.css");
		?>
	</head>
	<body>
		<div id="wrapper" data-ng-app='' data-ng-controller="loginController">
			<div id='box-login'>
				<div>
					<form name='loginForm' novalidate>
						<div>
							<span>Username: </span>
							<input type="text" name="username" data-ng-model='username' required>
							<span class='' data-ng-show="loginForm.username.$dirty && loginForm.username.$invalid">
								<span data-ng-show="loginForm.username.$error.required">Required</span>
							</span>
						</div>
						<div>
							<span>Password: </span><input type="password" name='password' data-ng-model='password' required>
						</div>
						<div>
							<button data-ng-disabled="loginForm.username.$invalid || loginForm.password.$invalid">Login</button>
						</div>
					</form>
					<!-- <p data-ng-bind='username'></p>
					<p data-ng-bind='password'></p> -->
				</div> 
			</div>
		</div>
		<script type="text/javascript">
		function loginController($scope, $http){
			//sskkk
		}
		</script>
	</body>
</html>