function flesh()//显示时间
{
    var d = new Date();
    var weekArr = ['星期日','星期一', '星期二', '星期三', '星期四', '星期五', '星期六' ];
    var week = weekArr[d.getDay()];
    var time = d.getFullYear() + "-" + add0(d.getMonth()+1) + "-" + add0(d.getDate()) + " " + week + " " +
    add0(d.getHours()) + ":" + add0(d.getMinutes()) + ":" + add0(d.getSeconds());
    document.getElementById('time').innerHTML=time;
}

function add0(data)//前补0，防抖动
{
    if (data>= 0 && data <= 9)
         data = "0" + data;
    return data;
}

var timeCycle = setInterval(flesh, 10);//刷新时间

function edit(element){
    var text = element.innerHTML;
　  var input = document.createElement('input');
　  input.type = 'text';
    input.value = text;
    input.className = "editor";
    input.setAttribute("maxLength","13");
    element.innerHTML = '';
　  element.appendChild(input);
　  input.focus();
　  input.onblur = function(){
        element.innerHTML = this.value ? this.value : text;
    }
}

swal({
    type: "success",
})//调用swal函数

var app = new Vue({
    el:'#app',
    data:{
        needItems:[],
        wantItems:[],
        needValue:'',
        wantValue:'',
        allNeedChecked:false,
        allWantChecked:false,
    },
    methods:{
        Clear:function()//重置所有数据
        {
            location.reload();
        },
        instruction:function ()//使用说明
        {
            swal("使用说明：1.可先完成一件最需要做的，再完成一件最想要做的，循环往复（完成后打勾）；\n2.双击文本进行修改；\n3.每件事项限制13字。");
        },
        checkAllNeed:function(){
            for(var i = 0; i < this.needItems.length; i++) {
                this.needItems[i].checked = true;
            }
        },
        unCheckAllNeed:function(){
            for(var i = 0; i < this.needItems.length; i++) {
                this.needItems[i].checked = false;
            }
        },
        checkAllWant:function(){
            for(var i = 0; i < this.wantItems.length; i++) {
                this.wantItems[i].checked = true;
            }
        },
        unCheckAllWant:function(){
            for(var i = 0; i < this.wantItems.length; i++) {
                this.wantItems[i].checked = false;
            }
        },
        addNeed:function(){
            if(this.needValue == ''){
                swal("内容不能为空!");
            }
            else{
                this.needItems.push({
                needContent:this.needValue,
                checked:false,
                });
                this.needValue = '';
            }
            
        },
        addWant:function(){
            if(this.wantValue == ''){
                swal("内容不能为空!");
            }
            else{
                this.wantItems.push({
                    wantContent:this.wantValue,
                    checked:false,
                });
                this.wantValue = '';
            }
        },
        deleteNeedItem:function(index){
            this.needItems.splice(index,1);
        },
        deleteWantItem:function(index){
            this.wantItems.splice(index,1);
        },
        deleteAllNeed:function(){
            var n = 0;
            for(var i=0;i<this.needItems.length;i++){
                if(this.needItems[i].checked == true) n++;
            }
            if(n != this.needItems.length){
                this.allNeedChecked=false;
            }
            else{
                this.allNeedChecked=true;
            }
            if(this.allNeedChecked == true) this.needItems = []; 
            this.allNeedChecked = false;
        },
        deleteAllWant:function(){
            var n = 0;
            for(var i=0;i<this.wantItems.length;i++){
                if(this.wantItems[i].checked == true) n++;
            }
            if(n != this.wantItems.length){
                this.allWantChecked=false;
            }
            else{
                this.allWantChecked=true;
            }
            if(this.allWantChecked == true) this.wantItems = [];
            this.allWantChecked = false;
        }
    },
})
