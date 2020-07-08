#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream>
#include"data.h"
using namespace std;



//<Struct_Definition>->struct id{<Struct_Content>
int Struct_Definition()
{
    if(TOKEN[n].kind=='K'&&TOKEN[n].addr==15)//struct?
    {
        n++;
        //cout<<"ok"<<endl;
        if(TOKEN[n].kind=='I')//id?
        {
            int i;
            i=TOKEN[n].addr;
            SYNBL[i].CAT="t";
            SYNBL[i].TYPE=TYPEL_CNT;
            SYNBL[i].ADDR=-1;
            TYPEL[TYPEL_CNT].TYPE="struct";
            TYPEL[TYPEL_CNT].NA=SYNBL[i].NAME;
            TYPEL[TYPEL_CNT].ADDR=STCNT;
            STRUCT[STCNT].TYPE="begin";
            STRUCT[STCNT].NAME=SYNBL[i].NAME;
            QT[QTCNT].str1="struct";
            QT[QTCNT].str2=SYNBL[i].NAME;
            QT[QTCNT].str3="NULL";
            QT[QTCNT].str4="NULL";
            QTCNT++;
            STCNT++;
            TYPEL_CNT++;
            n++;
            //cout<<"ok"<<endl;
            if(TOKEN[n].kind='P'&&TOKEN[n].addr==3)//{?
            {
                n++;
                if(Struct_Content()==1)
                {
                    //cout<<"ok"<<endl;
                    return 1;
                }
                else
                {
                    cout<<"结构体定义有误"<<endl;
                    return 0;
                }
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

//<Struct_Content>->}|<Type>id;<Struct_Content>
int Struct_Content()
{
    if(TOKEN[n].kind=='P'&&TOKEN[n].addr==4)//}?
    {
            n++;
            STRUCT[STCNT].TYPE="end";
            STCNT++;
            return 1;
    }
    else if(Type()==1)
    {
        //cout<<"ok"<<endl;
        if(TOKEN[n].kind=='I')//id?
        {
            string s;
            s=ST.top();
            ST.pop();
            int flag;
            flag=TOKEN[n].addr;
            TYPEL[TYPEL_CNT].TYPE=s;
            TYPEL[TYPEL_CNT].ADDR=-1;
            STRUCT[STCNT].TYPE=s;
            STRUCT[STCNT].NAME=SYNBL[flag].NAME;
            //cout<<s;
            STCNT++;
            TYPEL_CNT++;
            n++;
            if(TOKEN[n].kind=='P'&&TOKEN[n].addr==0)//;?
            {
                //cout<<"ok"<<endl;
                n++;
                if(Struct_Content()==1)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

