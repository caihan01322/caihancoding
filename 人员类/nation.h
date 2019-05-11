#ifndef NATION_H
#define NATION_H

#include <stdio.h>
#include <stdlib.h> //函数system需要

//民族名称的最大长度
#define MAX_NATION_NAME_LEN 10
//民族最大数目
#define MAX_NATION_NUM      56+2
//默认民族代码01（汉族）
#define DEFAULT_CODE 01
//存放民族代码、名称对照表的文件
#define FNAME "NationCodeName.txt"

//存放民族代码和民族名称
struct Nation {
    int code;
    char name[MAX_NATION_NAME_LEN+1];
};

//功    能：将存放民族代码、名称对照表的文件读入数组nation中
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//返    回：民族代码、名称对照表的记录条数
int getNationTable(struct Nation nation[]);

//功    能：显示民族代码、名称对照表
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：无
void showNationTable(struct Nation nation[],int n);

//功    能：返回(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//          code(用户输入的)待判断的民族代码
//返    回：民族代码存在返回其对应的下标，否则返回-1
int getIndexOfCode(struct Nation nation[],int n,int code);

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine(void);

//功    能：获得(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：用户输入的民族代码在民族表中对应的下标
int getIndexOfChoice(struct Nation nation[],int n);

#endif
