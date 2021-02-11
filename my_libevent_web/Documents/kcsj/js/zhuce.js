function $(id){return document.getElementById(id);}
function zhuce(){
	var flag=1;
	if($("name").value.length != 6){
		alert("用户名必须为六位！");
		flag=0;
	}
	if(!isNaN($("name").value)){
		alert("用户名不能全为数字！");
		flag=0;
	}
	if($("pwd1").value !==$("pwd2").value){
		alert("两次密码必须相同！")
		flag=0;
	}
	if($("email").value ==""){
		alert("邮箱不能为空！")
		flag=0;
	}
	if(flag){
		alert("注册成功，请登录!");
		window.location.href = "denglu.html"
	}
}