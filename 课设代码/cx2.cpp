#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;



//<Sub_Program>-><Var><Statement>
int Sub_Program()
{
    if(Var()==1)
    {
        //cout<<"ok"<<endl;
        if(Statement()==1)
        {
            //cout<<"ok";
            return 1;
        }
        else
            return 0;
    }
    else
    {
        cout<<"变量初始化定义有误"<<endl;
        return 0;
    }
}


//<Var>->begin|<Type><Var_Name>;<Var>
int Var()
{
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==9))//begin?
    {
        n++;
        return 1;
    }
    else
    {
        if(Type()==1)
        {
            //cout<<"ok"<<endl;
            if(Var_Name()==1)
            {
                //cout<<"ok"<<endl;
                if(TOKEN[n].kind=='P'&&TOKEN[n].addr==0)//;?
                {
                    n++;
                    if(Var()==1)
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
}

//<Type>->int{push()}|char{push()}|bool{push()}|void{push()}|struct id
int Type()
{
    if(TOKEN[n].kind=='K'&&(TOKEN[n].addr==0||TOKEN[n].addr==1||TOKEN[n].addr==4||TOKEN[n].addr==11||TOKEN[n].addr==15))
    {
        if(TOKEN[n].addr==15)//struct?
        {
            n++;
            if(TOKEN[n].kind=='I')//id?
            {
                int i=TOKEN[n].addr;
                //SYNBL[i].CAT="t";
                //SYNBL[i].ADDR=;
                string ch;
                ch=SYNBL[i].NAME;
                //cout<<ch<<endl;
                ST.push(ch);
                n++;
                return 1;
            }
            else
                return 0;
        }
        else
        {
        int i;
        i=TOKEN[n].addr;
        //cout<<KT[i].keyword<<endl;
        ST.push(KT[i].keyword);
        n++;
        return 1;
        }
    }
    else
    {
        cout<<"有无法识别的定义类型"<<endl;
        return 0;
    }
}

//<Var_Name>->id{Var()}<T3>
int Var_Name()
{
    if(TOKEN[n].kind=='I')
    {
        int flag,flag1;
        flag=TOKEN[n].addr;
        string s;
        s=ST.top();
        //ST.pop();
        SYNBL[flag].CAT="v";
        flag1=TYPEL_CNT;
        SYNBL[flag].TYPE=flag1;
        QT[QTCNT].str1="ini";
        QT[QTCNT].str2=s;
        QT[QTCNT].str3=SYNBL[flag].NAME;
        QT[QTCNT].str4="NULL";
        QTCNT++;
        SYNBL[flag].ADDR=LENCNT;
        if(s=="int")
        {
            LENL[LENCNT]=4;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
        }
        else if(s=="char")
        {
            LENL[LENCNT]=1;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
        }
        else if(s=="bool")
        {
            LENL[LENCNT]=1;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
        }
        else
        {
            TYPEL[flag1].TYPE="struct";
            TYPEL[flag1].NA=s;
            int time;
            for(time=0;time<STCNT;time++)
            {
                if(STRUCT[time].NAME==s)
                {
                    break;
                }
            }
            TYPEL[flag1].ADDR=time;
            time++;
            while(STRUCT[time].TYPE!="end")
            {
                string ch=".";
                QT[QTCNT].str1="ini";
                QT[QTCNT].str2=STRUCT[time].TYPE;
                QT[QTCNT].str3=SYNBL[flag].NAME+ch+STRUCT[time].NAME;
                QT[QTCNT].str4="NULL";
                QTCNT++;
                time++;
            }
        }
        LENCNT++;
        n++;
        TYPEL_CNT++;
        if(T3()==1)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}



//<T3>->,id{Var()}<T3>|null
int T3()
{
    if(TOKEN[n].kind=='P'&&TOKEN[n].addr==25)//,?
    {
        n++;
        if(TOKEN[n].kind=='I')
        {
        int flag,flag1;
        flag=TOKEN[n].addr;
        string s;
        s=ST.top();
        //ST.pop();
        SYNBL[flag].CAT="v";
        flag1=TYPEL_CNT;
        SYNBL[flag].TYPE=flag1;
        QT[QTCNT].str1="ini";
        QT[QTCNT].str2=s;
        QT[QTCNT].str3=SYNBL[flag].NAME;
        QT[QTCNT].str4="NULL";
        QTCNT++;
        SYNBL[flag].ADDR=LENCNT;
        if(s=="int")
        {
            LENL[LENCNT]=4;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
            LENCNT++;
        }
        else if(s=="char")
        {
            LENL[LENCNT]=1;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
            LENCNT++;
        }
        else if(s=="bool")
        {
            LENL[LENCNT]=1;
            TYPEL[flag1].TYPE=s;
            TYPEL[flag1].ADDR=-1;
            LENCNT++;
        }
        else
        {
            TYPEL[flag1].TYPE="struct";
            TYPEL[flag1].NA=s;
            int time;
            for(time=0;time<STCNT;time++)
            {
                if(STRUCT[time].NAME==s)
                {
                    break;
                }
            }
            TYPEL[flag1].ADDR=time;
            time++;
            while(STRUCT[time].TYPE!="end")
            {
                string ch=".";
                QT[QTCNT].str1="ini";
                QT[QTCNT].str2=STRUCT[time].TYPE;
                QT[QTCNT].str3=SYNBL[flag].NAME+ch+STRUCT[time].NAME;
                QT[QTCNT].str4="NULL";
                QTCNT++;
                time++;
            }
        }
        n++;
        TYPEL_CNT++;
        if(T3()==1)
            return 1;
        else
            return 0;
        }
        else
            return 0;
    }
    else
    {
        ST.pop();
        return 1;
    }
}



//<Statement>-><Operation><T2>
int Statement()
{
    if(Operation()==1)
    {
        //cout<<"ok"<<endl;
        if(T2()==1)
        {
            //cout<<"ok"<<endl;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}


//<T2>->end|<Operation><T2>
int T2()
{
    //cout<<TOKEN[n].kind<<TOKEN[n].addr<<endl;
    if(TOKEN[n].kind=='K'&&TOKEN[n].addr==10)//end?
    {
        //cout<<"ok";
        n++;
        return 1;
    }
    else
    {
        if(Operation()==1)
        {
            if(T2()==1)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
}
