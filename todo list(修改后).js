//显示动态时间
 function flesh() {
  var d = new Date();
  var weekArr = ['星期日','星期一', '星期二', '星期三', '星期四', '星期五', '星期六' ];
  var week = weekArr[d.getDay()];
  var time = d.getFullYear() + "-" + add0(d.getMonth()+1) + "-" + add0(d.getDate()) + " " + week + " " +
  add0(d.getHours()) + ":" + add0(d.getMinutes()) + ":" + add0(d.getSeconds());
  document.getElementById('time').innerHTML=time;
}

//刷新时间
var timeCycle = setInterval(flesh, 10);

//前补0，防抖动
function add0(data) {
  if (data>= 0 && data <= 9)
       data = "0" + data;
  return data;
}

//重置所有数据
function Clear() {
  location.reload();
}

$(document).ready(function(){
  $("#need_to_do").keyup(function(){
      if(event.keyCode == 13){
        $("#needButton").click();
      }
  });
  //添加,删除和修改"需要做的"事项
  $("#needButton").click(function(){
  var li = document.createElement("li");
  var need = document.getElementById("need_to_do").value;
  var text = document.createTextNode(need);
  var label = document.createElement("label");
  label.appendChild(text);
  label.setAttribute("font-size","19px");
  label.setAttribute("ondblclick","edit(this)");
  li.appendChild(label);
  var input = document.createElement("input");
  li.appendChild(input);
  input.setAttribute("type","checkbox");

  if (need == '')
    alert("内容不能为空!");
  else
    document.getElementById("need list").appendChild(li);
  document.getElementById("need_to_do").value = "";

  var a = document.createElement("a");
  var x = document.createTextNode('x');
  a.className = "close";
  a.setAttribute("href","javascript:void(0);");
  a.appendChild(x);
  li.appendChild(a);

  var close = document.getElementsByClassName("close");
  for (var i = 0; i < close.length; i++) {
    close[i].onclick = function() {
    this.parentElement.style.display = "none";  //'x' 所在父元素即 li 整行不显示
    }
  }
  });
});

$(document).ready(function(){
  $("#want_to_do").keyup(function(){
      if(event.keyCode == 13){
        $("#wantButton").click();
      }    
  });
  //添加，删除和修改"想要做的"事项
  $("#wantButton").click(function(){
  var li = document.createElement("li");
  var want = document.getElementById("want_to_do").value;
  var text = document.createTextNode(want);
  var label = document.createElement("label");
  label.appendChild(text);
  label.setAttribute("font-size","19px");
  label.setAttribute("ondblclick","edit(this)");
  li.appendChild(label);
  var input = document.createElement("input");
  li.appendChild(input);
  input.setAttribute("type","checkbox");
  
  if (want == '')
    alert("内容不能为空!"); 
  else
    document.getElementById("want list").appendChild(li);
  document.getElementById("want_to_do").value = "";

  var a = document.createElement("a");
  var x = document.createTextNode('x');
  a.className = "close";
  a.setAttribute("href","javascript:void(0);");
  a.appendChild(x);
  li.appendChild(a);

  var close = document.getElementsByClassName("close");
  for (var i = 0; i < close.length; i++) {
    close[i].onclick = function() {
      this.parentElement.style.display = "none";    //'x' 所在父元素即 li 整行不显示
    }
  }
  });
});

//
function instruction(){
  alert("使用说明：1.可先完成一件最需要做的，\n再完成一件最想要做的，循环往复；\n2.双击文本进行修改；\n3.每件事项限制13字。");
}

//实现删除功能
function edit(element){
  　var text = element.innerHTML;
    /*对于innerHTML 属性，几乎所有的元素都有innerHTML属性，它是一个字符串，
    用来设置或获取位于对象起始和结束标签内的HTML。(获取HTML当前标签的起始和结束里面的内容)*/
  　var input = document.createElement('input');
  　input.type = 'text';
    input.value = text;
    input.className = "editor";
    input.setAttribute("maxLength","13");
    element.innerHTML = '';/*清空innerHTML中的数据,以便下次再使用innerHTML*/
  　element.appendChild(input);
  　input.focus();
  　input.onblur = function(){
        element.innerHTML = this.value ? this.value : text;
        //一般而言，在Javascript中，this指向函数执行时的当前对象。this 是保留关键字，你不能修改 this 的值。
    }
}
