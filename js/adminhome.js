//var loginApp = angular.module('loginApp', []);
//loginApp.controller('loginController', function($scope, $http){
var appadmin = angular.module('appAdminHome', []);
appadmin.controller('adminController', function($scope, $http, $location, $anchorScroll){
	console.log($anchorScroll);
	$anchorScroll();
});

appadmin.run(['$anchorScroll', function($anchorScroll){
	$anchorScroll.yOffset = 50;
}]);

appadmin.directive('scroll', function($timeout) {
	return{
		link: function(scope, element, attr){
			$timeout(function(){
				console.log("test")
			});
		}
	}
});

window.addEventListener("scroll", function(){
	console.log(this.scrollY)
	if(parseInt(this.scrollY) >= 106){
		console.log("access");
		//#right-header
		document.getElementById("right-header").setAttribute("class", "scroll-active");
		document.getElementById("right-content").setAttribute("class", "scroll-active");
	}
	else{
		document.getElementById("right-header").removeAttribute("class");
		document.getElementById("right-content").removeAttribute("class");
	}
});

