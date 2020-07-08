#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
using namespace std;


#ifndef DATA_H
#define DATA_H

int Program();
int Func_Definition();
int T0();
int Para_List();
int T1();
int Sub_Program();
int Var();
int Type();
int Expression();
int T4();
int Item();
int T5();
int Factor();
int Cal_Number();
int Ass_Statement();
int Var_Name();
int Operation();
int Statement();
int T3();
int T2();
int Re_Statement();
int While();
int For();
int For_Statement();
int If();
int If_Statement();
int Else();
int Func_Call();
int T6();
int T7();
int T8();
int Break();
int Continue();

int analyse();
void act(int s);
int find_f(int s,char ch);
int InsertConst(double num);
int Reserve_K(string str);
int Reserve_P(string str);
int InsertID(string str);
int InsertSYNBL(string str);


void DIVIDE();
void active();
void youhua();

void solve();

void CODE_BDS();
void CODE_FODO();
void CODE_WHDO();
void CODE_ELSE();
void CODE_FZ();
void CODE_IE();
void CODE_IF();
void CODE_IFEND();
void CODE_PD();
void CODE_while();
void CODE_WE();
void CODE_FOR();
void CODE_FOREND();
void CODE_RE_FUNC_CALL();
void CODE_VO_FUNC_CALL();
void CODE_INI();
void CODE_PARA_INI();
void CODE_BREAK();
void CODE_CONTINUE();


int Struct_Definition();
int Struct_Content();



int struct_id();

int isnum(string s);
int Jun(int m);
int Ex_jun(int w,int &q);
void CH(int j);
void fenk(int i,int j);
int TT(string s);


struct TOKEND{
    char kind;
    int addr;
};

struct KTD{
    string keyword;
};

struct PTD{
    string delimiter;
};


struct SYNBLD{
    string NAME;
    int TYPE;
    string CAT;
    int ADDR;
};

struct TYPELD{
    string TYPE;
    string NA;
    int ADDR;
};

struct STRUCTD{
    string TYPE;
    string NAME;
};

struct PFINFLD{
    string RE_TYPE;
    int PAR_NUM;
    int PAR_ADDR;
    int BEGIN_ADDR;
    int END_ADDR;
};



struct PARAD{
    string TYPE;
    string NAME;
};

struct QTD{
    string str1;
    string str2;
    string str3;
    string str4;
    string jun2;
    string jun3;
    string jun4;
};

struct IDD
{
    string idname;
};

struct map                             //当前字符到状态转换矩阵列标记的映射
{
	char str[60];
	int col;
};

struct PARTITIOND
{
    int first;
    int last;
};

struct TD
{
    string name;
    string jun;
};

struct DAGD
{
    string M;
    string W;
    string A[10];
    string left;
    int left_num;
    string right;
    int right_num;
    int a_num=0;
};



struct RDLD
{
    string ZT;
    string NAME;
};

struct OBJD
{
    string str1;
    string str2;
    string str3;
    int str4;
};


struct QTDD
{
    string str1;
    string str2;
    string str3;
    string str4;
};


extern stack<string>ST;
extern stack<int>SEM;

extern double CT[100];
extern  int tin;
extern  int LENL[100];
extern int LENCNT;
extern  struct TYPELD TYPEL[100];
 extern int TYPEL_CNT;
 extern struct PFINFLD PFINFL[10];
 extern int PFCNT;
 extern struct STRUCTD STRUCT[10];
extern int STCNT;
 extern struct PARAD PARA[30];
extern int PARACNT;
extern struct QTD QT[100];
extern int QTCNT;
extern struct KTD KT[100];
 extern struct PTD PT[100];
extern  struct SYNBLD SYNBL[100];
 extern struct TOKEND TOKEN[200];
extern int n;
extern int func_n;
extern int para_n;
extern int tim;


extern struct QTDD QTF[100];
extern int n_num;
extern int JUN;


extern int d_num;
extern int t_num;
extern struct PARTITIOND PARTITION[100];
extern struct TD T[100];
extern struct DAGD DAG[100];
extern int CNT;
extern int OBJCNT;



extern struct RDLD RDL;
extern struct OBJD OBJ[200];
extern int cnt;
extern stack<int>SEMbreak;
extern stack<int>SEMcontinue;


extern  struct IDD ID[100];
extern  int aut[11][8];
extern int num_ID,num_C,num_Synbl;
 extern int C_index,I_index,Synbl_index;
 extern int i_token,num_token;              //Token计数器和Token个数
 extern string strTOKEN;                         //当前单词
//int i_str;                              //当前单词指针
 extern int nn,p,m,e,t;                           //尾数值，指数值，小数位数，指数符号，类型
 extern double num;                           //常数值
 extern char w[100];                            //源程序缓冲区
 extern int i;                                  //源程序缓冲区指针,当前字符为w[i]


extern  struct map col1[4];    //数字
extern  struct map col2[2]; //关键字或标识符
extern struct map col3[1];                    //界符
extern  struct map *ptr;
extern  int num_map;

#endif // DATA_H
