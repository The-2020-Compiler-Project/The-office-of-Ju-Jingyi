#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;


//<Expression>-><Item><T4>
int Expression()
{
    if(Item()==1)
    {
        if(T4()==1)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}


//<T4>->w0{push()}<Item>{geq()}<T4>|null
int T4()
{
    if(TOKEN[n].kind=='P'&&(TOKEN[n].addr==7||TOKEN[n].addr==8))//w0?
    {
        string s;
        if(TOKEN[n].addr==7)
            s="+";
        if(TOKEN[n].addr==8)
            s="-";
        ST.push(s);
        n++;
        if(Item()==1)
        {
            string a,b,c;
                a=ST.top();
                ST.pop();
                b=ST.top();
                ST.pop();
                c=ST.top();
                ST.pop();
                string i="t";
                char j[100];
                sprintf(j,"%d",tin);
                string ch=j;
                ch=i+ch;
                QT[QTCNT].str1=b;
                QT[QTCNT].str2=c;
                QT[QTCNT].str3=a;
                QT[QTCNT].str4=ch;
                ST.push(ch);
                T[t_num].name=ch;
                T[t_num].jun="0";
                t_num++;
                tin++;
                QTCNT++;
            if(T4()==1)
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
        return 1;
}

//<Item>-><Factor><T5>
int Item()
{
    if(Factor()==1)
    {
        if(T5()==1)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

//<T5>->w1{push()}<Factor>{geq()}<T5>|null
int T5()
{
    if(TOKEN[n].kind=='P'&&(TOKEN[n].addr==5||TOKEN[n].addr==6))//w1?
    {
        string s;
        if(TOKEN[n].addr==5)
            s="*";
        if(TOKEN[n].addr==6)
            s="/";
        ST.push(s);
        n++;
        if(Factor()==1)
        {
            string a,b,c;
                a=ST.top();
                ST.pop();
                b=ST.top();
                ST.pop();
                c=ST.top();
                ST.pop();
                string i="t";
                char j[100];
                sprintf(j,"%d",tin);
                string ch=j;
                ch=i+ch;
                QT[QTCNT].str1=b;
                QT[QTCNT].str2=c;
                QT[QTCNT].str3=a;
                QT[QTCNT].str4=ch;
                ST.push(ch);
                T[t_num].name=ch;
                T[t_num].jun="0";
                t_num++;
                tin++;
                QTCNT++;
            if(T5()==1)
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
        return 1;
}

//<Factor>->(<Expression>)|<Cal_Number>
int Factor()
{
    if(TOKEN[n].kind=='P'&&TOKEN[n].addr==1)//(?
    {
        n++;
        if(Expression()==1)
        {
            if(TOKEN[n].kind=='P'&&TOKEN[n].addr==2)//)?
            {
                n++;
                return 1;
            }
        }
        else
            return 0;
    }
    else
    {
        if(Cal_Number()==1)
            return 1;
        else
            return 0;
    }
}


//<Cal_Number>->id{push()}|constant{push()}
int Cal_Number()
{
    if(TOKEN[n].kind=='I'||TOKEN[n].kind=='C')
    {
        if(TOKEN[n].kind=='I')
        {
            if(struct_id()==1)
            {
                n++;
            }
            else
            {
            int i=0;
            i=TOKEN[n].addr;
            ST.push(SYNBL[i].NAME);
            n++;
            }
            return 1;
        }
        else
        {
            int i=0;
            char j[100];
            i=TOKEN[n].addr;
            char buf[100];
            sprintf(buf, "%.4f",CT[i]);
            string ch=buf;
            ST.push(ch);
            n++;
            return 1;
        }
    }
    else
        return 0;
}

