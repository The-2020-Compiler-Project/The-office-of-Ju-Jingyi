#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;



//<Func_Call>->F_CALLid<T6>
int Func_Call()
{
    //cout<<"ok"<<endl;
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==35))//F_CALL?
    {
        //cout<<"ok"<<endl;
        n++;
        if(TOKEN[n].kind=='I')
        {
            //cout<<"ok"<<endl;
            n++;
            if(T6()==1)
            {
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


//<T6>->=id(<T7>|(<T7>

int T6()
{
    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==9))//=?
    {
        int f=TOKEN[n-1].addr;
        string s=SYNBL[f].NAME;
        ST.push(s);
        n++;
        if(TOKEN[n].kind=='I')
        {
            int flag1=TOKEN[n].addr;
            func_n=flag1;
            int flag2=SYNBL[flag1].ADDR;
            string s1,s2;
            char wen[20];
            sprintf(wen,"%d",tin);
            string ch=wen;
            string zh="t";
            ch=zh+ch;
            s1=SYNBL[flag1].NAME;
            s2=PFINFL[flag2].RE_TYPE;
            QT[QTCNT].str1="RE_FUNC_CALL";
            QT[QTCNT].str2=s2;
            QT[QTCNT].str3=s1;
            QT[QTCNT].str4=ch;
            ST.push(ch);
            T[t_num].name=ch;
                T[t_num].jun="0";
                t_num++;
            n++;
            QTCNT++;
            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
            {
                n++;
                if(T7()==1)
                {
                    string a,b;
                    a=ST.top();
                    ST.pop();
                    b=ST.top();
                    ST.pop();
                    QT[QTCNT].str1="CALL_END";
                    QT[QTCNT].str2="NULL";
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4="NULL";
                    QTCNT++;
                    QT[QTCNT].str1="=";
                    QT[QTCNT].str2=a;
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4=b;
                    QTCNT++;
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
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
        {
            int flag1=TOKEN[n-1].addr;
            func_n=flag1;
            int flag2=SYNBL[flag1].ADDR;
            string s1,s2;
            s1=SYNBL[flag1].NAME;
            s2=PFINFL[flag2].RE_TYPE;
            QT[QTCNT].str1="VO_FUNC_CALL";
            QT[QTCNT].str2=s1;
            QT[QTCNT].str3="NULL";
            QT[QTCNT].str4="NULL";
            n++;
            QTCNT++;
            if(T7()==1)
            {
                QT[QTCNT].str1="CALL_END";
                QT[QTCNT].str2="NULL";
                QT[QTCNT].str3="NULL";
                QT[QTCNT].str4="NULL";
                QTCNT++;
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
}



//<T7>->);|id<T8>);

int T7()
{
    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
    {
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
        {
            n++;
            return 1;
        }
        else
            return 0;
    }
    else
    {
        if(TOKEN[n].kind=='I')
        {
            int flag,flag1,flag2;
            flag=TOKEN[n].addr;
            flag1=SYNBL[func_n].ADDR;
            flag2=PFINFL[flag1].PAR_ADDR;
            para_n=flag2+1;
            string s1,s2,s3;
            s1=PARA[para_n].TYPE;
            s2=PARA[para_n].NAME;
            s3=SYNBL[flag].NAME;
            QT[QTCNT].str1="PAR_ASS";
            QT[QTCNT].str2=s1;
            QT[QTCNT].str3=s3;
            QT[QTCNT].str4=s2;
            QTCNT++;
            para_n++;
            n++;
            if(T8()==1)
            {
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
                {
                    n++;
                    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
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
}


//<T8>->,id<T8>|null

int T8()
{
    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==25))//,?
    {
        n++;
        if(TOKEN[n].kind=='I')
        {
            int flag,flag1,flag2;
            flag=TOKEN[n].addr;
            flag1=SYNBL[func_n].ADDR;
            flag2=PFINFL[flag1].PAR_ADDR;
            string s1,s2,s3;
            s1=PARA[para_n].TYPE;
            s2=PARA[para_n].NAME;
            s3=SYNBL[flag].NAME;
            QT[QTCNT].str1="PAR_ASS";
            QT[QTCNT].str2=s1;
            QT[QTCNT].str3=s3;
            QT[QTCNT].str4=s2;
            QTCNT++;
            para_n++;
            n++;
            if(T8()==1)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 1;
}
