//用户输入(选择)民族
#include "nation.h"

//功    能：将存放民族代码、名称对照表的文件读入数组nation中
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//返    回：民族代码、名称对照表的记录条数
int getNationTable(struct Nation nation[]) {
    FILE *fp=fopen(FNAME,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a存放民族代码、名称对照表的文件[%s]不存在！\n",FNAME);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&nation[n].code,nation[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//功    能：显示民族代码、名称对照表
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：无
void showNationTable(struct Nation nation[],int n) {
    for (int i=0;i<n;i++) {
        printf("[%02d]",nation[i].code);
        printf("%-*s",MAX_NATION_NAME_LEN+2,nation[i].name);
    }
}

//功    能：返回(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//          code(用户输入的)待判断的民族代码
//返    回：民族代码存在返回其对应的下标，否则返回-1
int getIndexOfCode(struct Nation nation[],int n,int code) {
    for (int i=0;i<n;i++) {
        if (nation[i].code==code) return i;
    }
    return -1;
}

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine(void) {
    while (getchar()!='\n')
        continue;
}

//功    能：获得(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：用户输入的民族代码在民族表中对应的下标
int getIndexOfChoice(struct Nation nation[],int n) {
    int code=0;   //用户输入的民族代码
    int index=-1; //用户输入的民族代码在民族表中对应的下标
    while (1) {
        showNationTable(nation,n); //显示民族代码、名称对照表
        
        if (code==0) printf("\n请");
        else         printf("\a\n输入错误，请重新");
        printf("输入国家代码和<回车>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&code);
            eatLine();            //跳过本行剩余的其他字符和<回车>键
        }
        else                      //用户直接按<回车>，得到默认值：汉族
            code=DEFAULT_CODE;    //默认民族代码01（汉族）
        
        if ((index=getIndexOfCode(nation,n,code))!=-1)
            break;                //合法的民族代码
        
        system("cls"); //清屏
        code=-1;
    }
    
    return index;
}
