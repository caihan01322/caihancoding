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
    },
    error: function(){
        alert("Error!");
    },
});
});
});