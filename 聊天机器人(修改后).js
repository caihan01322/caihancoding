$(document).ready(function(){
        var status=document.getElementById("status");
    $.ajax({
        url:"http://www.tuling123.com/openapi/api",
        type:"post",
        dataType:"json",
        data:{
            key:"15d644a4c07c4a2ca4772f139289b4bb",
            info:"",
            userId:"123456"
        },
        success: function(){
            status.innerHTML="(在线)";
        },
        error: function(){
            status.innerHTML="(离线)";
        },
    });
});

$(document).ready(function(){
$("#cheat").keyup(function(){
    if(event.keyCode == 13){
        $("#button").click();
    }
});
/*当按钮被松开时，发生 keyup 事件。
语法：$(selector).keyup()*/
/*(event.keyCode == 13)：键码13为回车
irFirefox2.0中不支持 window.event.keyCode,
但是我们可以用event.which代替。
但是为了使其能更具有普遍的兼容性，最好用event.keyCode|| event.which.*/
$("#button").click(function(){
    var list=document.getElementById("list");
    var I=document.createElement("div");
    var Robot=document.createElement("div");
    var talkI=document.createElement("div");
    var talkRobot=document.createElement("div");
    var myData=document.getElementById("cheat").value;
$.ajax({
    url:"http://www.tuling123.com/openapi/api",
    type:"post",
    dataType:"json",
    data:{
        key:"15d644a4c07c4a2ca4772f139289b4bb",
        info:myData,
        userId:"123456"
    },
    success: function(data){
        $("#status").fadeOut(500);
        $("#status").fadeIn(500);
        $("#status").fadeOut(500);
        $("#status").fadeIn(500);
        $("#status").fadeOut(500);
        $("#status").fadeIn(500);

        list.appendChild(I);
        I.setAttribute("id","I");
        I.appendChild(talkI);
        talkI.setAttribute("class","talkI");
        talkI.innerText="I："+myData;

        list.appendChild(Robot);
        Robot.setAttribute("id","Robot");
        Robot.appendChild(talkRobot);
        talkRobot.setAttribute("class","talkRobot");
        talkRobot.innerText="Robot："+data.text;

        document.getElementById("cheat").value="";

        $("#list").scrollTop($("#list")[0].scrollHeight);
        /*scrollTop() 方法返回或设置匹配元素的滚动条的垂直位置。
        scroll top offset 指的是滚动条相对于其顶部的偏移。
        如果该方法未设置参数，则返回以像素计的相对滚动条顶部的偏移。
        语法：$(selector).scrollTop(offset)
        参数	描述
        offset	可选。规定相对滚动条顶部的偏移，以像素计。*/
        /*scrollHeight: 获取对象的滚动高度。
        scrollWidth:获取对象的滚动宽度。
        一定要写$("#list")[0].scrollHeight;而不是$("#list").scrollHeight;*/
    },
    error: function(){
        alert("Error!");
    },
});
});
});
