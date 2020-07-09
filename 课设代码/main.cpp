#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;



stack<string>ST;

double CT[100];
 int tin=0;
 int LENL[100];
 int LENCNT=0;
 struct TYPELD TYPEL[100];
 int TYPEL_CNT=0;
 struct PFINFLD PFINFL[10];
 int PFCNT=0;
 struct STRUCTD STRUCT[10];
 int STCNT=0;
 struct PARAD PARA[30];
int PARACNT=0;

struct QTD QT[100];
int QTCNT=0;
struct KTD KT[100];
 struct PTD PT[100];
 struct SYNBLD SYNBL[100];
 struct TOKEND TOKEN[200];
int n=0;
int func_n=0;
int para_n=0;
int tim=0;


 struct QTDD QTF[100];
 int n_num=0;
 int JUN=0;

int d_num=0;
int t_num=0;
struct PARTITIOND PARTITION[100];
struct TD T[100];
struct DAGD DAG[100];
int CNT=0;
int OBJCNT=0;
struct RDLD RDL;
struct OBJD OBJ[200];
int cnt=0;
stack<int>SEM;
stack<int>SEMbreak;
stack<int>SEMcontinue;

 struct IDD ID[100];
 int aut[11][8]={ 0, 0, 0, 0, 0, 0, 0, 0,
	         0, 2, 0, 0, 0, 8, 9,15,
             0, 2, 3, 5,11, 0, 0,11,
             0, 4, 0, 0, 0, 0, 0, 0,
             0, 4, 0, 5,11, 0, 0,11,
             0, 7, 0, 0, 6, 0, 0, 0,
             0, 7, 0, 0, 0, 0, 0, 0,
             0, 7, 0, 0,11, 0, 0,11,
             0, 8, 0, 0, 0, 8, 0,12,
             0, 0, 0, 0, 0, 0,10,14,
             0, 0, 0, 0, 0, 0, 0,13};
int num_ID=0,num_C=0,num_Synbl=0;
 int C_index,I_index,Synbl_index;
 int i_token=0,num_token=0;              //Token计数器和Token个数
 string strTOKEN;                         //当前单词
//int i_str;                              //当前单词指针
 int nn,p,m,e,t;                           //尾数值，指数值，小数位数，指数符号，类型
 double num;                           //常数值
 char w[100];                            //源程序缓冲区
 int i;                                  //源程序缓冲区指针,当前字符为w[i]


 struct map col1[4]={{"0123456789",1},{".",2},{"Ee",3},{"+-",4}};    //数字
 struct map col2[2]={{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_",5},{"0123456789",1}}; //关键字或标识符
struct map col3[1]={{";:(),+-*/=><{}.",6}};                    //界符
 struct map *ptr;
 int num_map;




int main()
{
    if(analyse()==1)
        cout<<"OK"<<endl;
    int time;
    /*for(time=0;time<num_token;time++)
        cout<<TOKEN[time].kind<<"  "<<TOKEN[time].addr<<endl;
    */

    cout<<Program()<<endl;
    for(time=0;time<QTCNT;time++)
    {
        cout<<QT[time].str1<<"    "<<QT[time].str2<<"    "<<QT[time].str3<<"    "<<QT[time].str4<<endl;
    }
    DIVIDE();
    for(time=0;time<d_num;time++)
    {
        cout<<PARTITION[time].first<<"   "<<PARTITION[time].last<<endl;
    }
    youhua();
    for(time=0;time<QTCNT;time++)
    {
        cout<<QT[time].str1<<"    "<<QT[time].str2<<"    "<<QT[time].str3<<"    "<<QT[time].str4<<endl;
    }
    d_num=0;
    DIVIDE();
    for(time=0;time<d_num;time++)
    {
        cout<<PARTITION[time].first<<"   "<<PARTITION[time].last<<endl;
    }
    active();
    for(time=0;time<QTCNT;time++)
    {
        cout<<QT[time].str1<<"    "<<QT[time].str2<<" "<<QT[time].jun2<<"    "<<QT[time].str3<<" "<<QT[time].jun3<<"    "<<QT[time].str4<<" "<<QT[time].jun4<<endl;
    }
    solve();
    /*for(time=0;time<d_num;time++)
    {
        cout<<PARTITION[time].first<<"   "<<PARTITION[time].last<<endl;
    }
    youhua();
    for(time=0;time<QTCNT;time++)
    {
        cout<<QT[time].str1<<"    "<<QT[time].str2<<"    "<<QT[time].str3<<"    "<<QT[time].str4<<endl;
    }*/
    for(time=0;time<=OBJCNT;time++)
    {
        if(OBJ[time].str1=="JMP"||OBJ[time].str1=="FJ"||OBJ[time].str1=="RET")
            cout<<OBJ[time].str1<<"    "<<OBJ[time].str2<<"    "<<OBJ[time].str4<<endl;
        else
            cout<<OBJ[time].str1<<"    "<<OBJ[time].str2<<"    "<<OBJ[time].str3<<endl;
    }
    return 0;
}

