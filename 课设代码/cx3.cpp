#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
using namespace std;

//<Operation>-><Ass_Statement>|<If>|<While>|<Re_Statement>|<For>|<Func_Call>
int Operation()
{
    if(Ass_Statement()==1)
        return 1;
    else if(If()==1)
    {
        //cout<<"OK";
        return 1;
    }
    else if(While()==1)
        return 1;
    else if(Re_Statement()==1)
        return 1;
    else if(For()==1)
    {
        //cout<<"ok"<<endl;
        return 1;
    }
    else if(Func_Call()==1)
        return 1;
    else if(Break()==1)
        return 1;
    else if(Continue()==1)
        return 1;
    else
    {
        cout<<"有无法识别的操作语句"<<endl;
        return 0;
    }
}

//<Ass_Statement>->id{push()}=<Expression>;{=()}
int Ass_Statement()
{
    if(TOKEN[n].kind=='I')
    {
        //cout<<"ok"<<endl;
        if(struct_id()==1)
        {
            n++;
        }
        else
        {
        int flag1;
        flag1=TOKEN[n].addr;
        ST.push(SYNBL[flag1].NAME);
        //cout<<ST.top()<<"123"<<endl;
        n++;
        }
        if(TOKEN[n].kind=='P'&&TOKEN[n].addr==9)//=?
        {
            n++;
            if(Expression()==1)
            {
                if(TOKEN[n].kind=='P'&&TOKEN[n].addr==0)//;?
                {
                    string s,s1;
                    s=ST.top();
                    //cout<<s<<"OK";
                    //cout<<SYNBL[flag1].NAME;
                    ST.pop();
                    s1=ST.top();
                    ST.pop();
                    QT[QTCNT].str1="=";
                    QT[QTCNT].str2=s;
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4=s1;
                    QTCNT++;
                    n++;
                    return 1;
                }
                else
                {
                    cout<<"赋值语句结束未加分号"<<endl;
                    return 0;
                }
            }
            else
                return 0;
        }
        else
        {
            cout<<"赋值语句赋值符号不正确"<<endl;
            return 0;
        }
    }
    else
    {
        return 0;
    }
}



//<If>->if(<If_Statement>){If()}{<Sub_Program>}{if_end()}<Else>
int If()
{
    if(TOKEN[n].kind=='K'&&TOKEN[n].addr==5)//if?
    {
        //cout<<"ok"<<endl;
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
        {
            n++;
            if(If_Statement()==1)
            {
                //cout<<"ok"<<endl;
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
                {
                    n++;
                    string s;
                    s=ST.top();
                    ST.pop();
                    QT[QTCNT].str1="if";
                    QT[QTCNT].str2=s;
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4="NULL";
                    QTCNT++;
                    if(TOKEN[n].kind=='P'&&TOKEN[n].addr==3)//{?
                    {
                        n++;
                        if(Sub_Program()==1)
                        {
                            //cout<<"OK";
                            if(TOKEN[n].kind=='P'&&TOKEN[n].addr==4)//}?
                            {
                                //cout<<"OK";
                                n++;
                                QT[QTCNT].str1="if_end";
                                QT[QTCNT].str2="NULL";
                                QT[QTCNT].str3="NULL";
                                QT[QTCNT].str4="NULL";
                                QTCNT++;
                                if(Else()==1)
                                {
                                    //cout<<"OK";
                                    return 1;
                                }
                                else
                                {
                                    cout<<"else语句格式有误"<<endl;
                                    return 0;
                                }
                            }
                            else
                            {
                                cout<<"if语句缺少}"<<endl;
                                return 0;
                            }
                        }
                        else
                        {
                            cout<<"if语句子程序定义有误"<<endl;
                            return 0;
                        }
                    }
                    else
                    {
                        cout<<"if语句缺少{"<<endl;
                        return 0;
                    }
                }
                else
                    return 0;
            }
            else
            {
                cout<<"if判断语句格式有误"<<endl;
                return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}



//<Else>->else{else()}{<Sub_Program>}{else_end()}|null
int Else()
{
    if(TOKEN[n].kind=='K'&&TOKEN[n].addr==6)//else?
    {
        QT[QTCNT].str1="else";
        QT[QTCNT].str2="NULL";
        QT[QTCNT].str3="NULL";
        QT[QTCNT].str4="NULL";
        QTCNT++;
        n++;
        if(TOKEN[n].kind=='P'&&TOKEN[n].addr==3)//{?
            {
                n++;
                if(Sub_Program()==1)
                {
                    if(TOKEN[n].kind=='P'&&TOKEN[n].addr==4)//}?
                    {
                        n++;
                        QT[QTCNT].str1="else_end";
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
                {
                    cout<<"else子程序有误"<<endl;
                    return 0;
                }
            }
            else
                return 0;
    }
    else
        return 1;
}


//<If_Statement>->id{push()}w2{push()}id{push()}{ifs()}
int If_Statement()
{
    int i=0;
    if(TOKEN[n].kind=='I')
    {
        //cout<<"ok"<<endl;
        if(struct_id()==1)
        {
            n++;
        }
        else
        {
        //cout<<"ok"<<endl;
        i=TOKEN[n].addr;
        ST.push(SYNBL[i].NAME);
        n++;
        }
        //cout<<"ok"<<endl;
        if(TOKEN[n].kind=='P'&&(TOKEN[n].addr==26||TOKEN[n].addr==11||TOKEN[n].addr==12||TOKEN[n].addr==10||TOKEN[n].addr==13||TOKEN[n].addr==14))//> < >= <= == !=?
        {
            //cout<<"ok"<<endl;
            i=TOKEN[n].addr;
            ST.push(PT[i].delimiter);
            n++;
            if(TOKEN[n].kind=='I')
            {
                //cout<<"ok"<<endl;
                if(struct_id()==1)
                {
                    n++;
                }
                else
                {
                    //cout<<"ok"<<endl;
                i=TOKEN[n].addr;
                ST.push(SYNBL[i].NAME);
                }
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
                ST.push(ch);
                QT[QTCNT].str1=b;
                QT[QTCNT].str2=c;
                QT[QTCNT].str3=a;
                QT[QTCNT].str4=ch;
                T[t_num].name=ch;
                T[t_num].jun="0";
                t_num++;
                QTCNT++;
                tin++;
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



//<While>->while{While()}(<If_Statement>){do()}{<Sub_Program>}{while_end()}
int While()
{
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==7))//while?
    {
        n++;
        QT[QTCNT].str1="while";
        QT[QTCNT].str2="NULL";
        QT[QTCNT].str3="NULL";
        QT[QTCNT].str4="NULL";
        QTCNT++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
        {
            n++;
            if(If_Statement()==1)
            {
                //string s;
                //s=ST.top();
                //ST.POP();
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
                {
                    string s;
                    s=ST.top();
                    ST.pop();
                    QT[QTCNT].str1="while_do";
                    QT[QTCNT].str2=s;
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4="NULL";
                    QTCNT++;
                    n++;
                    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==3))//{?
                    {
                        n++;
                        if(Sub_Program()==1)
                        {
                            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==4))//}?
                            {
                                n++;
                                QT[QTCNT].str1="while_end";
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
                        {
                            cout<<"while语句子程序有误"<<endl;
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
            {
                cout<<"while判断语句有误"<<endl;
                return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}



//<Re_Statement>->return<Expression>;{return()}
int Re_Statement()
{
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==32))//return?
    {
        n++;
        if(Expression()==1)
        {
            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
            {
                string s;
                s=ST.top();
                ST.pop();
                QT[QTCNT].str1="return";
                QT[QTCNT].str2=s;
                QT[QTCNT].str3="NULL";
                QT[QTCNT].str4="NULL";
                QTCNT++;
                n++;
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


//<For>->for(<For_Statement>){do()}{<Sub_Program>}{for_end()}
int For()
{
    //cout<<"ok"<<endl;
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==8))//for?
    {
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==1))//(?
        {
            n++;
            if(For_Statement()==1)
            {
                //cout<<"ok"<<endl;
                if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==2))//)?
                {
                    QT[QTCNT].str1="do";
                    QT[QTCNT].str2="NULL";
                    QT[QTCNT].str3="NULL";
                    QT[QTCNT].str4="NULL";
                    QTCNT++;
                    n++;
                    if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==3))//{?
                    {
                        n++;
                        if(Sub_Program()==1)
                        {
                            //cout<<"ok"<<endl;
                            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==4))//}?
                            {
                                //cout<<"ok"<<endl;
                                string s1,s2,s3,s4;
                                int time;
                                for(time=0;time<tim;time++)
                                {
                                    s4=ST.top();
                                    ST.pop();
                                    s3=ST.top();
                                    ST.pop();
                                    s2=ST.top();
                                    ST.pop();
                                    s1=ST.top();
                                    ST.pop();
                                    QT[QTCNT].str1=s1;
                                    QT[QTCNT].str2=s2;
                                    QT[QTCNT].str3=s3;
                                    QT[QTCNT].str4=s4;
                                    QTCNT++;
                                }
                                //cout<<s1<<s2<<s3<<s4<<endl;
                                QT[QTCNT].str1="for_end";
                                QT[QTCNT].str2="NULL";
                                QT[QTCNT].str3="NULL";
                                QT[QTCNT].str4="NULL";
                                QTCNT++;
                                n++;
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
            else
            {
                cout<<"for语句格式有误"<<endl;
                return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}




//<For_Statement>-><Ass_Statement><If_Statement>;<Ass_Statement>
int For_Statement()
{
    if(Ass_Statement()==1)
    {
        QT[QTCNT].str1="for";
        QT[QTCNT].str2="NULL";
        QT[QTCNT].str3="NULL";
        QT[QTCNT].str4="NULL";
        QTCNT++;
        if(If_Statement()==1)
        {
            if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
            {
                n++;
                int flag=QTCNT;
                if(Ass_Statement()==1)
                {
                    int time,flag1=QTCNT;
                    tim=0;
                    for(time=flag1-1;time>=flag;time--)
                    {
                        ST.push(QT[time].str1);
                        //cout<<QT[time].str1<<endl;
                        ST.push(QT[time].str2);
                        //cout<<QT[time].str2<<endl;
                        ST.push(QT[time].str3);
                        //cout<<QT[time].str3<<endl;
                        ST.push(QT[time].str4);
                        //cout<<QT[time].str4<<endl;
                        QTCNT--;
                        tim++;
                    }
                    /*QTCNT--;
                    ST.push(QT[QTCNT].str1);
                    ST.push(QT[QTCNT].str2);
                    ST.push(QT[QTCNT].str3);
                    ST.push(QT[QTCNT].str4);
                    QTCNT--;
                    ST.push(QT[QTCNT].str1);
                    ST.push(QT[QTCNT].str2);
                    ST.push(QT[QTCNT].str3);
                    ST.push(QT[QTCNT].str4);*/
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


//<Break>->break;
int Break()
{
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==29))//break?
    {
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
        {
            n++;
            QT[QTCNT].str1="break";
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



//<Continue>->continue;
int Continue()
{
    if((TOKEN[n].kind=='K')&&(TOKEN[n].addr==28))//continue?
    {
        n++;
        if((TOKEN[n].kind=='P')&&(TOKEN[n].addr==0))//;?
        {
            n++;
            QT[QTCNT].str1="continue";
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
