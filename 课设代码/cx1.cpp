#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;


//<Program>->function<Func_Definition><Program>{pro_end()}|PROGRAM_END|<Struct_Definition><Program>
int Program()
{
    //cout<<"ok"<<endl;
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==33))//function?
    {
        n++;
        //cout<<"ok"<<endl;
        if(Func_Definition()==1)
        {
            //cout<<"ok"<<endl;
            if(Program()==1)
            {
                //cout<<"ok"<<endl;
                return 1;
            }
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        //cout<<TOKEN[n].kind<<TOKEN[n].addr;
        if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==34))//PROGRAM_END?
        {
            //cout<<"ok"<<endl;
            QT[QTCNT].str1="pro_end";
            QT[QTCNT].str2="NULL";
            QT[QTCNT].str3="NULL";
            QT[QTCNT].str4="NULL";
            QTCNT++;
            n++;
            //cout<<"ok"<<endl;
            return 1;
        }
        else
        {
            //cout<<"ok"<<endl;
            if(Struct_Definition()==1)
            {
                if(Program()==1)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
    }
}


//<Func_Definition>-><Type>id{func()}(<T0>{func_end()}
int Func_Definition()
{
    if(Type()==1)
    {
        if(TOKEN[n].kind=='I')//id?
        {
            int flag,flag1;
            string s;
            s=ST.top();
            flag=TOKEN[n].addr;
            SYNBL[flag].CAT='f';
            QT[QTCNT].str1="function";
            QT[QTCNT].str2=s;
            QT[QTCNT].str3=SYNBL[flag].NAME;
            QT[QTCNT].str4="NULL";
            //cout<<"ok"<<endl;
            ST.pop();
            flag1=PFCNT;
            SYNBL[flag].ADDR=PFCNT;
            SYNBL[flag].TYPE=-1;
            PFINFL[flag1].RE_TYPE=s;
            PFINFL[flag1].PAR_NUM=0;
            PFINFL[flag1].BEGIN_ADDR=QTCNT;
            PFINFL[flag1].PAR_ADDR=PARACNT;
            PARA[PARACNT].TYPE="begin";
            PARA[PARACNT].NAME=SYNBL[flag].NAME;
            n++;
            PFCNT++;
            QTCNT++;
            PARACNT++;
            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
            {
                n++;
                if(T0()==1)
                {
                    QT[QTCNT].str1="func_end";
                    QT[QTCNT].str2="NULL";
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4="NULL";
                    PFINFL[PFCNT-1].END_ADDR=QTCNT;
                    QTCNT++;
                    //cout<<"ok"<<endl;
                    return 1;
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
    else
        return 0;
}



//<T0>->){<Sub_Program>}|<Para_List>){<Sub_Program>}
int T0()
{
    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
    {
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==3))//{?
        {
            n++;
            //cout<<"OK";
            if(Sub_Program()==1)
            {
                //cout<<"ok";
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==4))//}?
                {
                    //cout<<"ok";
                    n++;
                    return 1;
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
    else
    {
        if(Para_List()==1)
        {
            //cout<<"ok"<<endl;
            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
            {
                PARA[PARACNT].TYPE="end";
                n++;
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==3))//{?
                {
                    n++;
                    if(Sub_Program()==1)
                    {
                        //cout<<"ok"<<endl;
                        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==4))//}?
                        {
                            n++;
                            return 1;
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
            else
                return 0;
        }
        else
        {
            cout<<"函数形参定义有误"<<endl;
            return 0;
        }
    }
}


//<Para_List>-><Type>id{par()}<T1>
int Para_List()
{
    if(Type()==1)
    {
        if(TOKEN[n].kind=='I')
        {
            int flag,flag1;
            flag=TOKEN[n].addr;
            string s;
            s=ST.top();
            ST.pop();
            SYNBL[flag].TYPE=TYPEL_CNT;
            TYPEL[TYPEL_CNT].TYPE=s;
            TYPEL[TYPEL_CNT].ADDR=-1;
            SYNBL[flag].CAT="vn";
            flag1=PARACNT;
            SYNBL[flag].ADDR=flag1;
            PARA[flag1].NAME=SYNBL[flag].NAME;
            PARA[flag1].TYPE=s;
            QT[QTCNT].str1="para_ini";
            QT[QTCNT].str2=PARA[flag1].TYPE;
            QT[QTCNT].str3=PARA[flag1].NAME;
            QT[QTCNT].str4="NULL";
            PFINFL[PFCNT-1].PAR_NUM++;
            QTCNT++;
            n++;
            PARACNT++;
            TYPEL_CNT++;
            if(T1()==1)
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


//<T1>->,<Type>id{par()}<T1>|null
int T1()
{
    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==25))//,?
    {
        n++;
        if(Type()==1)
        {
            if(TOKEN[n].kind=='I')
            {
                int flag,flag1;
                flag=TOKEN[n].addr;
                string s;
                s=ST.top();
                ST.pop();
                SYNBL[flag].TYPE=TYPEL_CNT;
                TYPEL[TYPEL_CNT].TYPE=s;
                TYPEL[TYPEL_CNT].ADDR=-1;
                SYNBL[flag].CAT="vn";
                flag1=PARACNT;
                SYNBL[flag].ADDR=flag1;
                PARA[flag1].NAME=SYNBL[flag].NAME;
                PARA[flag1].TYPE=s;
                QT[QTCNT].str1="para_ini";
                QT[QTCNT].str2=PARA[flag1].TYPE;
                QT[QTCNT].str3=PARA[flag1].NAME;
                QT[QTCNT].str4="NULL";
                PFINFL[PFCNT-1].PAR_NUM++;
                QTCNT++;
                n++;
                PARACNT++;
                TYPEL_CNT++;
                if(T1()==1)
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
        return 1;
}


