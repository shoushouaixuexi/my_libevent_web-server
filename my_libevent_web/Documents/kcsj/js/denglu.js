function $(id){return document.getElementById(id);}
function denglu(){
	var flag=1;
	if($("name").value.length != 6){
		alert("用户名必须为六位！");
		reset();
		flag=0;
	}
	if(!isNaN($("name").value)){
		alert("用户名不能全为数字！");
		reset();
		flag=0;
	}
	if($("pwd").value==""){
		alert("密码不能为空!");
		flag=0;
	}
	if(flag){
		alert("登录成功!");
		window.location.href = "index.html"
	}
}
function reset(){
	$("name").value = "";
	$("pwd").value = "";
}