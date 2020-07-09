#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;

/*
extern stack<string>str;

extern double CT[100];
extern int tin;
extern int LENL[100];

extern struct TYPELD TYPEL[100];
extern int TYPEL_CNT;
extern struct PFINFLD PFINFL[10];
extern int PFCNT;
extern struct PARAD PARA[10];
extern int PARACNT;
extern struct QTD QT[10];
extern int QTCNT;
extern struct KTD KT[100];
extern struct PTD PT[100];
extern struct SYNBLD SYNBL[100];
extern struct TOKEND TOKEN[100];
extern int n;

*/




int struct_id()
{
    int flag,flag1;
    flag=TOKEN[n].addr;
    flag1=SYNBL[flag].TYPE;
    string s1,s2,s3,ch;
    s1=SYNBL[flag].NAME;
    //cout<<s1<<endl;
    //cout<<TYPEL[flag1].TYPE<<endl;
    if(TYPEL[flag1].TYPE=="struct")
    {
        //cout<<"ok"<<endl;
        //cout<<s1;
        int flag2;
        flag2=TYPEL[flag1].ADDR;
        n++;
        //cout<<TOKEN[n].kind<<TOKEN[n].addr;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==21))//.?
        {
            n++;
            s2=".";
            //cout<<s1<<s2;
            if(TOKEN[n].kind=='I')
            {
                int i=flag2+1,j;
                j=TOKEN[n].addr;
                s3=SYNBL[j].NAME;
                while(STRUCT[i].TYPE!="end")
                {
                    if(STRUCT[i].NAME==SYNBL[j].NAME)
                    {
                        ch=s1+s2+s3;
                        ST.push(ch);
                        return 1;
                    }
                    i++;
                }
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











