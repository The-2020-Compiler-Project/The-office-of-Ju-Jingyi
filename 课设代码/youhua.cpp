#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream>
#include"data.h"
using namespace std;



/*
void DIVIDE()
{
   //d_num=0;
    int time;
    PARTITION[d_num].first=0;
    for(time=0;time<=QTCNT ;time++)
    {
        if(QT[time].str1=="struct")
        {
                PARTITION[d_num].first=time;
                PARTITION[d_num].last=time;
                PARTITION[++d_num].first=time+1;
                //PARTITION[d_num].first=time;
        }
        else if(QT[time].str1=="function")
        {
            if(d_num==0)
                PARTITION[d_num].first=time;
            else
            {
                PARTITION[d_num].last=time;
                PARTITION[++d_num].first=time+1;
            }
        }
        else if(QT[time].str1=="if_end"||QT[time].str1=="RE_FUNC_CALL"||QT[time].str1=="VO_FUNC_CALL"||QT[time].str1=="else_end")
        {
            PARTITION[d_num].last=time-1;
            PARTITION[++d_num].first=time;
        }
        else if(QT[time].str1=="for"||QT[time].str1=="while"||QT[time].str1=="if"||QT[time].str1=="else"
                ||QT[time].str1=="while_do"||QT[time].str1=="do"||QT[time].str1=="pro_end"||QT[time].str1=="CALL_END")
        {
            PARTITION[d_num].last=time;
            PARTITION[++d_num].first=time+1;
        }
    }
}



void active()
{
    int s_num=0,jap=t_num;
    int i,j,k;
    for(i=0;i<=num_Synbl;i++)
    {
        //cout<<i<<"  ";
        //cout<<SYNBL[i].CAT<<endl;
        if(SYNBL[i].CAT=="v"||SYNBL[i].CAT=="vn")
        {

            string s,s1,ch;
            s=SYNBL[i].NAME;
            s1=".";
            int flag,flag1;
            flag=SYNBL[i].TYPE;
            //cout<<TYPEL[flag].TYPE;
            if(TYPEL[flag].TYPE=="struct")
            {
                //cout<<"ok"<<endl;
                flag1=TYPEL[flag].ADDR+1;
                while(STRUCT[flag1].TYPE!="end")
                {
                    ch=s+s1+STRUCT[flag1].NAME;
                    //cout<<ch<<endl;
                    flag1++;
                    T[s_num+t_num].name=ch;
                    T[s_num+t_num].jun="1";
                    s_num++;
                }
                //cout<<"ok"<<endl;
            }
            else
            {
                T[s_num+t_num].name=SYNBL[i].NAME;
                T[s_num+t_num].jun="1";
                s_num++;
            }
        }
    }
    t_num=t_num+s_num;
    //for(i=0;i<t_num;i++)
    //cout<<T[i].name;
    for(j=0;j<=d_num;j++)
    {
        //cout<<"ok"<<endl;
        for(i=0;i<=t_num;i++)
        {
            if(i>=jap)
            {
                T[i].jun="1";
            }
            else
            {
                T[i].jun="0";
            }
        }
        for(k=PARTITION[j].last;k>=PARTITION[j].first;k--)
        {
            int v;
            for(v=0;v<=t_num;v++)
            {
                if(QT[k].str4==T[v].name)
                {
                    QT[k].jun4=T[v].jun;
                    T[v].jun="0";
                }
                if(QT[k].str3==T[v].name)
                {
                    QT[k].jun3=T[v].jun;
                    T[v].jun="1";
                }
                if(QT[k].str2==T[v].name)
                {
                    QT[k].jun2=T[v].jun;
                    T[v].jun="1";
                }
            }
        }

    }
}






















int isnum(string s)
{
        stringstream sin(s);
        double t;
        char p;
        if(!(sin >> t))
               return 0;
        if(sin >> p)
                return 0;
        else
                return 1;
}


int Jun(int m)
{
    for(int i=0;i<=DAG[m].a_num;i++)
    {
        if(DAG[m].A[i]!="NULL")
        {
            return 1;
        }
        else
            return 0;
    }
}


void youhua()
{
    int n_num=0;
    int co_jun=0;
    int con=0;
    int i,j,k,v,l;
    for(i=0;i<=d_num;i++)//��������
    {
        for(j=PARTITION[i].first;j<=PARTITION[i].last;j++)
        {
            if(QT[j].str1=="="&&isnum(QT[j].str2)!=1)
            {
            DAG[n_num].M=QT[j].str2;
            DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
            DAG[n_num].a_num++;
            n_num++;
            con=n_num;
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
            }

            if(QT[j].str1=="="&&isnum(QT[j].str2)==1)
            {
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==QT[j].str2)
                {
                    DAG[k].A[DAG[k].a_num+1]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    n_num++;
                    DAG[n_num].M=QT[j].str2;
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    con=n_num;
                    DAG[n_num].a_num++;
            }
                for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
            }
            if((QT[j].str1=="+"||QT[j].str1=="-"||QT[j].str1=="*"||QT[j].str1=="/")&&isnum(QT[j].str2)==1&&isnum(QT[j].str3)==1)
            {
                if(QT[j].str1=="+")
                {
                double a,b;
                char J[20];
                stringstream ccc;
                ccc<<QT[j].str2;
                ccc>>a;
                ccc<<QT[j].str3;
                ccc>>b;
                a=a+b;
                sprintf(J,"%.4f",a);
                string ch=J;
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num+1]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    n_num++;
                    DAG[n_num].M=ch;
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    con=n_num;
                    DAG[n_num].a_num++;
            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
                }

                if(QT[j].str1=="-")
                {
                double a,b;
                char J[20];
                stringstream ccc;
                ccc<<QT[j].str2;
                ccc>>a;
                ccc<<QT[j].str3;
                ccc>>b;
                a=a-b;
                sprintf(J,"%.4f",a);
                string ch=J;
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num+1]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    n_num++;
                    DAG[n_num].M=ch;
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    con=n_num;
                    DAG[n_num].a_num++;
            }
                for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
                }

                if(QT[j].str1=="*")
                {
                double a,b;
                char J[20];
                stringstream ccc;
                ccc<<QT[j].str2;
                ccc>>a;
                ccc<<QT[j].str3;
                ccc>>b;
                a=a*b;
                sprintf(J,"%.4f",a);
                string ch=J;
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num+1]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    n_num++;
                    DAG[n_num].M=ch;
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    con=n_num;
                    DAG[n_num].a_num++;
            }
                 for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
                }

                if(QT[j].str1=="/")
               {
                double a,b;
                char J[20];
                stringstream ccc;
                ccc<<QT[j].str2;
                ccc>>a;
                ccc<<QT[j].str3;
                ccc>>b;
                a=a/b;
                sprintf(J,"%.4f",a);
                string ch=J;
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num+1]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    n_num++;
                    DAG[n_num].M=ch;
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    con=n_num;
                    DAG[n_num].a_num++;
            }
                 for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;k++)
                {
                    if(DAG[k].A[v]==QT[j].str4&&k!=con)
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
                }

            }
/*
            //A=BwC
            if((QT[j].str1=="+"||QT[j].str1=="-"||QT[j].str1=="*"||QT[j].str1=="/")&&(isnum(QT[j].str2)==0||isnum(QT[j].str3)==0))
            {
                for(int i=0;i<=n_num;i++)
                        {
                            for(int l;l<=n[i].a_num;l++)
                            {
                                if(n[i].A[l]==QT[j].str2)
                                {
                                    QT[j].str2=n[i].M;
                                }
                            }
                        }
                for(int i=0;i<=n_num;i++)
                        {
                            for(int l;l<=n[i].a_num;l++)
                            {
                                if(n[i].A[l]==QT[j].str3)
                                {
                                    QT[j].str3=n[i].M;
                                }
                            }
                        }
                for(k=n_num;k>=0;k--)
                {
                    if(QT[j].str2==n[k].left&&QT[j].str3==n[k].right&&QT[j].str1==n[k].W)
                    {
                        n[k].A[n[k].a_num]=QT[j].str4;
                        n[k].a_num++;
                        con=k;
                        co_jun=1;
                        break;
                    }
                }
                if(co_jun!=1)
                {
                        n_num++;
                        n[n_num].left=QT[j].str2;
                        for(int i=0;i<=n_num;i++)
                        {
                            if(n[i].M==QT[j].str2)
                            {
                                n[n_num].left_num=i;
                            }
                            for(int l;l<=n[i].a_num;l++)
                            {
                                if(n[i].A[l]==QT[j].str2)
                                {
                                    n[n_num].left_num=i;
                                    n[n_num].left=n[i].M;
                                }
                            }
                        }
                        n[n_num].right=QT[j].str3;
                        for(int i=0;i<=n_num;i++)
                        {
                            if(n[i].M==QT[j].str3)
                            {
                                n[n_num].right_num=i;
                            }
                            for(int l;l<=n[i].a_num;l++)
                            {
                                if(n[i].A[l]==QT[j].str3)
                                {
                                    n[n_num].right_num=i
                                    n[n_num].right=n[i].M;
                                }
                            }
                        }
                        n[n_num].W=QT[j].str1;
                        n[n_num].M=QT[j].str4;
                        con=n_num;
                }
                for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=n[k].a_num;k++)
                {
                    if(n[k].A[v]==QT[j].str4&&k!=con)
                    {
                        n[k].A[v]="NULL";

                    }
                }
            }
            }



            }
            *//*
            co_jun=0;
         for(int m=0;m<=n_num;m++)
         {
             if(DAG[m].W=="NULL"&&Jun(m)==1)//Ҷ�ڵ�ͬʱ������Ϣ��Ϊ��
             {
                 for(int l=0;l<=DAG[m].a_num;l++)
                 {
                     for(int i=0;i<=t_num;i++)
                 {
                     if(DAG[m].A[l]!=T[i].name)
                     {
                         QT[CNT].str1="=";
                         QT[CNT].str2=DAG[m].M;
                         QT[CNT].str3="NULL";
                         QT[CNT].str4=DAG[m].A[l];
                         CNT++;
                         break;
                     }
                 }
                 }

             }
             if(DAG[m].W!="NULL")
             {
                 QT[CNT].str1=DAG[m].W;
                 QT[CNT].str2=DAG[m].left;
                 QT[CNT].str3=DAG[m].right;
                 QT[CNT].str4=DAG[m].M;
                 CNT++;
                 for(int l=0;l<=DAG[m].a_num;l++)
                 {
                     for(int n=0;n<=t_num;n++)
                     {
                         if(DAG[m].A[l]!=T[n].name&&DAG[m].A[l]!="NULL")
                         {
                             QT[CNT].str1="=";
                             QT[CNT].str2=DAG[m].M;
                             QT[CNT].str3="NULL";
                             QT[CNT].str4=DAG[m].A[l];
                             CNT++;
                             break;
                         }
                     }
                 }
             }

         }



        }
    }
    }


*/
