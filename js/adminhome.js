//var loginApp = angular.module('loginApp', []);
//loginApp.controller('loginController', function($scope, $http){
var appadmin = angular.module('appAdminHome', ['ngRoute', 'ngAnimate']);

appadmin.config(['$routeProvider', function($routeProvider){
	 $routeProvider.when('/boyisadmin/user/',{
	 	templateUrl: '/boyisadmin/test.html',
	 	controller : 'UserCtrl'
	 })
}]);

/*appadmin.controller('UserCtrl', function($scope){
	$scope.ttt = "test";
});
*/
appadmin.controller('adminController', function($scope, $http){
	$scope.model ={
		test : false
	}
});



checkHeaderHeight(window);
window.addEventListener("scroll", function(){
	checkHeaderHeight(this);
});


function checkHeaderHeight(t){
	if(parseInt(t.scrollY) >= 155){
		document.getElementById("right-header").setAttribute("class", "scroll-active");
		document.getElementById("right-content").setAttribute("class", "scroll-active");
	}
	else{
		document.getElementById("right-header").removeAttribute("class");
		document.getElementById("right-content").removeAttribute("class");
	}
}

