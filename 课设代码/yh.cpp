#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream>
#include"data.h"
using namespace std;




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
                ||QT[time].str1=="while_do"||QT[time].str1=="do"||QT[time].str1=="pro_end"||QT[time].str1=="CALL_END"||QT[time].str1=="for_end"||QT[time].str1=="while_end")
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
    /*for(i=0;i<t_num;i++)
        cout<<T[i].name;*/
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
//char ccc[10];
int lengths;
lengths = s.length();
//ccc[length] = '\0';
for(int k=0;k<lengths;k++)
{
    if((s[k]<'0'||s[k]>'9')&&s[k]!='.')
    {
        return 0;
    }
}
   return 1;
}
int Jun(int m)
{
    int j,k;
    for(j=0;j<=DAG[m].a_num;j++)
    {
        if(DAG[m].A[j]!="NULL")
        {
              return 1;
        }
        else
            return 0;
    }
}
int Ex_jun(int w,int &q)
{
    int i;
    for(i=0;i<=DAG[w].a_num;i++)
    {
           if(TT(DAG[w].A[i])!=0)
           {
               q=i;
               return 1;
           }
    }
        return 0;
}
void CH(int j)
{
    int m,l;
    JUN=j;
        for(m=0;m<n_num;m++)
         {
             if(DAG[m].W=="NULL"&&Jun(m)==1)//叶节点同时附加信息不为空
             {
                 for(l=0;l<DAG[m].a_num;l++)
                 {
                     if(TT(DAG[m].A[l])==1&&DAG[m].A[l]!="NULL")
                     {
                         QTF[JUN].str1="=";
                         QTF[JUN].str2=DAG[m].M;
                         QTF[JUN].str3="NULL";
                         QTF[JUN].str4=DAG[m].A[l];
                         JUN++;
                         break;
                     }
                 }
             }
              else if(DAG[m].W!="NULL")
             {
                 QTF[JUN].str1=DAG[m].W;
                 QTF[JUN].str2=DAG[m].left;
                 QTF[JUN].str3=DAG[m].right;
                 QTF[JUN].str4=DAG[m].M;
                 JUN++;
                 for(l=0;l<=DAG[m].a_num;l++)
                 {

                         if(TT(DAG[m].A[l])==1&&DAG[m].A[l]!="NULL")
                         {
                             QTF[JUN].str1="=";
                             QTF[JUN].str2=DAG[m].M;
                             QTF[JUN].str3="NULL";
                             QTF[JUN].str4=DAG[m].A[l];
                             JUN++;
                         }
                 }
             }
          }
}
void youhua()
{
    int i,j,k,v,l;
    CNT=0;
    JUN=0;
    for(v=0;v<100;v++)
    {
        QTF[v].str1="NULL";
        QTF[v].str2="NULL";
        QTF[v].str3="NULL";
        QTF[v].str4="NULL";
    }
    for(i=0;i<=d_num;i++)
    {
        DAG[i].a_num=0;
        DAG[i].W="NULL";
        DAG[i].M="NULL";
        DAG[i].left="NULL";
        DAG[i].right="NULL";
        DAG[i].left_num=0;
        DAG[i].right_num=0;
        for(k=0;k<=10;k++)
        {
            DAG[i].A[k]="NULL";
        }
    }
    int B[20];
    for(i=0;i<=20;i++)
    {
        B[i]=-1;
    }
    int b=0;
    n_num=0;
    for(i=0;i<=d_num;i++)//各基本快
    {
        b=0;
        for(j=PARTITION[i].first;j<=PARTITION[i].last;j++)
        {
        if(((QT[j].str1=="+"||QT[j].str1=="-"||QT[j].str1=="*"||QT[j].str1=="/")&&(isnum(QT[j].str2)==0||isnum(QT[j].str3)==0))
           ||((QT[j].str1=="=")&&(isnum(QT[j].str2)!=1))||((QT[j].str1=="=")&&(isnum(QT[j].str2)==1))||((QT[j].str1=="+"||QT[j].str1=="-"
            ||QT[j].str1=="*"||QT[j].str1=="/")&&isnum(QT[j].str2)==1&&isnum(QT[j].str3)==1))
        {
        fenk(i,j);
        B[b]=j;
        b++;
        }
        else
        {
                QTF[CNT].str1=QT[j].str1;
                QTF[CNT].str2=QT[j].str2;
                QTF[CNT].str3=QT[j].str3;
                QTF[CNT].str4=QT[j].str4;
                CNT++;
            }
        }
        for(v=0;v<=b;v++)
        {
            if(B[v]!=-1)
            {
                CH(B[v]);
                v=v+JUN-2;
            }
        }
    for(k=0;k<20;k++)
    {
        DAG[k].a_num=0;
        DAG[k].W="NULL";
        DAG[k].M="NULL";
        DAG[k].left="NULL";
        DAG[k].right="NULL";
        DAG[k].left_num=0;
        DAG[k].right_num=0;
        for(j=0;j<10;j++)
        {
            DAG[k].A[j]="NULL";
        }
    }
    for(l=0;l<=b;l++)
    {
        B[l]=0;
    }
    }
    for(v=0;v<QTCNT;v++)
    {
        QT[v].str1="NULL";
        QT[v].str2="NULL";
        QT[v].str3="NULL";
        QT[v].str4="NULL";
    }
    for(l=0;l<=CNT;l++)
    {
        if(QTF[l].str1!="NULL"||QTF[l].str2!="NULL"||QTF[l].str3!="NULL"||QTF[l].str4!="NULL")
        QT[l].str1=QTF[l].str1;
        QT[l].str2=QTF[l].str2;
        QT[l].str3=QTF[l].str3;
        QT[l].str4=QTF[l].str4;
    }
    int qt_num=0;
   for(i=0;i<=QTCNT;i++)
    {
        if(!((QT[i].str1=="NULL")&&(QT[i].str2=="NULL")&&(QT[i].str3=="NULL")&&(QT[i].str4=="NULL")))
        {
        QTF[qt_num].str1=QT[i].str1;
        QTF[qt_num].str2=QT[i].str2;
        QTF[qt_num].str3=QT[i].str3;
        QTF[qt_num].str4=QT[i].str4;
        qt_num++;
        }
    }
    for(j=0;j<qt_num;j++)
    {
        QT[j].str1=QTF[j].str1;
        QT[j].str2=QTF[j].str2;
        QT[j].str3=QTF[j].str3;
        QT[j].str4=QTF[j].str4;
    }
    QTCNT=qt_num;
}
int TT(string s)
{
   for(int v=0;v<=t_num;v++)
{
   if(s==T[v].name)
   {
       return 0;
   }
}
    return 1;
}


//基本块优化
void fenk(int i,int j)
{
        int co_jun=0;
        int coo_jun=0;
        int con=0;
        int k,v,l;
            //非常数赋值
       if((QT[j].str1=="=")&&(isnum(QT[j].str2)!=1))
            {
             for(v=n_num;v>=0;v--)
                {
                    for(l=0;l<=DAG[v].a_num;l++)
                    {
                     if(DAG[v].A[l]==QT[j].str2)
                     {
                         QT[j].str2=DAG[v].M;
                         break;
                     }
                    }
                }
            if(TT(QT[j].str2)==0)
            {
            DAG[n_num].W="NULL";
            DAG[n_num].M=QT[j].str4;
            DAG[n_num].A[DAG[n_num].a_num]=QT[j].str2;
            DAG[n_num].a_num++;
            con=n_num;
            n_num++;
            coo_jun=1;
             }
            if(coo_jun==1)
            {
                for(k=n_num;k>=0;k--)
                {
                    if(QT[j].str2==DAG[k].M)
                    {
                        DAG[k].A[DAG[k].a_num]=QT[j].str4;
                        DAG[k].a_num++;
                        con=k;
                        break;
                    }
                }
            }
            if(coo_jun!=1)
            {
            DAG[n_num].W="NULL";
            DAG[n_num].M=QT[j].str2;
            DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
            DAG[n_num].a_num++;
            con=n_num;
            n_num++;
            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
           /* if(JUN==0)
            {
                JUN=CNT;
            }
            if(JUN>CNT)
            {
                JUN=CNT;
            }*/
            CNT++;
            }
            //常数赋值
           else if((QT[j].str1=="=")&&(isnum(QT[j].str2)==1))
            {
                for(k=n_num;k>=0;k--)
            {
                if(DAG[k].M==QT[j].str2)
                {
                    DAG[k].A[DAG[k].a_num]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    DAG[k].a_num++;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    DAG[n_num].M=QT[j].str2;
                    DAG[n_num].W="NULL";
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    DAG[n_num].a_num++;
                    con=n_num;
                    n_num++;

            }
                for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                    }
                }
            }
            CNT++;
            }
//常数表达式
       else if((QT[j].str1=="+"||QT[j].str1=="-"||QT[j].str1=="*"||QT[j].str1=="/")&&isnum(QT[j].str2)==1&&isnum(QT[j].str3)==1)
            {
                if(QT[j].str1=="+")
                {
                double a,b,c;
                char J[20];
                stringstream ccc,vvv;
                ccc<<QT[j].str2;
                ccc>>a;
                vvv<<QT[j].str3;
                vvv>>b;
                c=a+b;
                sprintf(J,"%.4f",c);
                string ch=J;
                for(k=n_num;k>0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    DAG[k].a_num++;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    DAG[n_num].M=ch;
                    DAG[n_num].W="NULL";
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    DAG[n_num].a_num++;
                    con=n_num;
                    n_num++;

            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                        break;
                    }
                }
                }
                }
                if(QT[j].str1=="-")
                {
                double a,b,c;
                char J[20];
                stringstream ccc,vvv;
                ccc<<QT[j].str2;
                ccc>>a;
                vvv<<QT[j].str3;
                vvv>>b;
                c=a-b;
                sprintf(J,"%.4f",c);
                string ch=J;
                for(k=n_num;k>0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    DAG[k].a_num++;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    DAG[n_num].M=ch;
                    DAG[n_num].W="NULL";
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    DAG[n_num].a_num++;
                    con=n_num;
                    n_num++;

            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                        break;
                    }
                }
                }
                }

                if(QT[j].str1=="*")
                {
                double a,b,c;
                char J[20];
                stringstream ccc,vvv;
                ccc<<QT[j].str2;
                ccc>>a;
                vvv<<QT[j].str3;
                vvv>>b;
                c=a*b;
                sprintf(J,"%.4f",c);
                string ch=J;
                for(k=n_num;k>0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    DAG[k].a_num++;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    DAG[n_num].M=ch;
                    DAG[n_num].W="NULL";
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    DAG[n_num].a_num++;
                    con=n_num;
                    n_num++;

            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                        break;
                    }
                }
                }
                }

               if(QT[j].str1=="/")
                {
                double a,b,c;
                char J[20];
                stringstream ccc,vvv;
                ccc<<QT[j].str2;
                ccc>>a;
                vvv<<QT[j].str3;
                vvv>>b;
                c=a/b;
                sprintf(J,"%.4f",c);
                string ch=J;
                for(k=n_num;k>0;k--)
            {
                if(DAG[k].M==ch)
                {
                    DAG[k].A[DAG[k].a_num]=QT[j].str4;
                    con=k;
                    co_jun=1;
                    DAG[k].a_num++;
                    break;
                }
            }
            if(co_jun!=1)
            {
                    DAG[n_num].M=ch;
                    DAG[n_num].W="NULL";
                    DAG[n_num].A[DAG[n_num].a_num]=QT[j].str4;
                    DAG[n_num].a_num++;
                    con=n_num;
                    n_num++;

            }
            for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";
                        break;
                    }
                }
                }
                }
                CNT++;
            }
//表达式
  else if((QT[j].str1=="+"||QT[j].str1=="-"||QT[j].str1=="*"||QT[j].str1=="/")&&(isnum(QT[j].str2)==0||isnum(QT[j].str3)==0))
            {
                int q;
                for(k=0;k<=n_num;k++)
                {
                    for(l=0;l<=DAG[k].a_num;l++)
                    {
                        if(DAG[k].A[l]==QT[j].str2)
                        {
                            if(Ex_jun(k,q)==1)
                            {
                                QT[j].str2=DAG[k].A[q];
                                    coo_jun=1;
                                    break;
                                    }
                                    else
                                    {
                                        QT[j].str2=DAG[k].M;
                                        coo_jun=1;
                                        break;
                                    }
                                }
                            }
                            if(coo_jun==1)
                                break;
                        }
                for(k=0;k<=n_num;k++)
                        {
                            for(l=0;l<=DAG[k].a_num;l++)
                            {
                                if(DAG[k].A[l]==QT[j].str3)
                                {
                                    if(Ex_jun(k,q)==1)
                                    {
                                    QT[j].str3=DAG[k].A[q];
                                    break;
                                    }
                                    else
                                    {
                                        QT[j].str3=DAG[k].M;
                                        break;
                                    }


                                }
                            }
                        }
                for(k=n_num;k>=0;k--)
                {
                    if((QT[j].str2==DAG[k].left)&&(QT[j].str3==DAG[k].right)&&(QT[j].str1==DAG[k].W))
                    {
                        DAG[k].A[DAG[k].a_num]=QT[j].str4;
                        DAG[k].a_num++;
                        con=k;
                        co_jun=1;
                        break;
                    }
                }
                if(co_jun==0)
                {
                        DAG[n_num].left=QT[j].str2;
                        /*for(k=0;k<=n_num;k++)
                        {
                            if(DAG[k].M==QT[j].str2)
                            {
                                DAG[n_num].left_num=k;
                            }
                            for(l=0;l<=DAG[k].a_num;l++)
                            {
                                if(DAG[k].A[l]==QT[j].str2)
                                {
                                    DAG[n_num].left_num=k;
                                    DAG[n_num].left=DAG[k].M;
                                }
                            }
                        }*/
                        DAG[n_num].right=QT[j].str3;
                       /* for(k=0;k<=n_num;k++)
                        {
                            if(DAG[k].M==QT[j].str3)
                            {
                                DAG[n_num].right_num=k;
                            }
                            for(l=0;l<=DAG[k].a_num;l++)
                            {
                                if(DAG[k].A[l]==QT[j].str3)
                                {
                                    DAG[n_num].right_num=k;
                                    DAG[n_num].right=DAG[i].M;
                                }
                            }
                        }*/
                        DAG[n_num].W=QT[j].str1;
                        DAG[n_num].M=QT[j].str4;
                        con=n_num;
                        n_num++;
                }
                for(k=n_num;k>=0;k--)
            {
                for(v=0;v<=DAG[k].a_num;v++)
                {
                    if((DAG[k].A[v]==QT[j].str4)&&(k!=con))
                    {
                        DAG[k].A[v]="NULL";

                    }
                }
            }
            CNT++;
            }
            co_jun=0;
            coo_jun=0;
}
