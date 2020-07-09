#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream>
#include"data.h"
using namespace std;



void CODE_BDS()
            {
                if((QT[cnt].str1=="+")||(QT[cnt].str1=="-")||(QT[cnt].str1=="*")||(QT[cnt].str1=="/"))
                {
                    if(RDL.NAME=="0")
                    {
                        OBJ[OBJCNT].str1="LD";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=QT[cnt].str2;
                        OBJCNT++;
                        if(QT[cnt].str1=="+")
                        {
                            OBJ[OBJCNT].str1="ADD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;
                            OBJCNT++;

                        }
                        if(QT[cnt].str1=="-")
                        {
                            OBJ[OBJCNT].str1="SUB";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;
                            OBJCNT++;

                        }
                        if(QT[cnt].str1=="*")
                        {
                            OBJ[OBJCNT].str1="MUL";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;
                            OBJCNT++;

                        }
                        if(QT[cnt].str1=="/")
                        {
                            OBJ[OBJCNT].str1="DIV";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;
                            OBJCNT++;

                        }

                    }

                    else if(RDL.NAME==QT[cnt].str2)
                    {
                        if(QT[cnt].jun2=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            if(QT[cnt].str1=="+")
                            {
                                OBJ[OBJCNT].str1="ADD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                             if(QT[cnt].str1=="-")
                            {
                                OBJ[OBJCNT].str1="SUB";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                            if(QT[cnt].str1=="*")
                            {
                                OBJ[OBJCNT].str1="MUL";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                            if(QT[cnt].str1=="/")
                            {
                                OBJ[OBJCNT].str1="DIV";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                        }
                         if(QT[cnt].jun2=="0")
                        {
                                if(QT[cnt].str1=="+")
                            {
                                OBJ[OBJCNT].str1="ADD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                             if(QT[cnt].str1=="-")
                            {
                                OBJ[OBJCNT].str1="SUB";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                            if(QT[cnt].str1=="*")
                            {
                                OBJ[OBJCNT].str1="MUL";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                            if(QT[cnt].str1=="/")
                            {
                                OBJ[OBJCNT].str1="DIV";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                        }
                    }

                    else if(RDL.NAME==QT[cnt].str3)
                    {

                        if((QT[cnt].str1=="+"||"*")&&QT[cnt].jun3=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            OBJCNT++;
                            if(QT[cnt].str1=="+")
                            {
                                OBJ[OBJCNT].str1="ADD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str2;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                             if(QT[cnt].str1=="*")
                            {
                                OBJ[OBJCNT].str1="MUL";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str2;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                        }
                        else if((QT[cnt].str1=="-"||"/")&&QT[cnt].jun3=="0")
                        {

                             if(QT[cnt].str1=="-")
                            {
                                OBJ[OBJCNT].str1="SUB";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str2;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }

                             if(QT[cnt].str1=="/")
                            {
                                OBJ[OBJCNT].str1="DIV";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str2;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                        }
                    }
                    else
                    {
                        if(RDL.ZT=="1")

                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=RDL.NAME;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            if(QT[cnt].str1=="+")
                            {
                                OBJ[OBJCNT].str1="ADD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="-")
                            {
                                OBJ[OBJCNT].str1="SUB";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="*")
                            {
                                OBJ[OBJCNT].str1="MUL";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="/")
                            {
                                OBJ[OBJCNT].str1="DIV";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                        }
                        else
                        {
                             OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                             if(QT[cnt].str1=="+")
                            {
                                OBJ[OBJCNT].str1="ADD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="-")
                            {
                                OBJ[OBJCNT].str1="SUB";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="*")
                            {
                                OBJ[OBJCNT].str1="MUL";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                             if(QT[cnt].str1=="/")
                            {
                                OBJ[OBJCNT].str1="DIV";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                RDL.NAME=QT[cnt].str4;
                                 RDL.ZT=QT[cnt].jun4;
                                OBJCNT++;

                            }
                        }
                    }
                }
            }
            void CODE_FODO()
            {
                if(QT[cnt].str1=="do")
                {
                    OBJ[OBJCNT].str1="FJ";
                    OBJ[OBJCNT].str2="R";
                    SEM.push(OBJCNT);
                    RDL.NAME="0";
                    OBJCNT++;

                }
            }
            void CODE_WHDO()
            {
                if(QT[cnt].str1=="while_do")
                {
                    if(RDL.NAME=="0")
                    {
                        OBJ[OBJCNT].str1="LD";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=QT[cnt].str2;
                        OBJCNT++;
                        OBJ[OBJCNT].str1="FJ";
                        OBJ[OBJCNT].str2="R";
                        SEM.push(OBJCNT);
                        OBJCNT++;

                    }
                    if(RDL.NAME==QT[cnt].str2)
                    {
                        if(QT[cnt].jun2=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            RDL.NAME="0";
                            OBJCNT++;

                        }
                    else
                    {
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            RDL.NAME="0";
                            OBJCNT++;

                    }
                }
    if(RDL.NAME!=QT[cnt].str2&&RDL.NAME!="0")
    {
        if(RDL.ZT=="1")
        {
            OBJ[OBJCNT].str1="ST";
            OBJ[OBJCNT].str2="R";
            OBJ[OBJCNT].str3=RDL.NAME;
            OBJCNT++;
            OBJ[OBJCNT].str1="LD";
            OBJ[OBJCNT].str2="R";
            OBJ[OBJCNT].str3=QT[cnt].str2;
            OBJCNT++;
            OBJ[OBJCNT].str1="FJ";
            OBJ[OBJCNT].str2="R";
            SEM.push(OBJCNT);
            RDL.NAME="0";
            OBJCNT++;

        }
        else
        {
             OBJ[OBJCNT].str1="LD";
            OBJ[OBJCNT].str2="R";
            OBJ[OBJCNT].str3=QT[cnt].str2;
            OBJCNT++;
            OBJ[OBJCNT].str1="FJ";
            OBJ[OBJCNT].str2="R";
            SEM.push(OBJCNT);
            RDL.NAME="0";
            OBJCNT++;

        }
    }
}

            }
            void CODE_ELSE()
            {
                if(QT[cnt].str1=="else")
                {
                    if(RDL.ZT=="1")
                    {
                        int flag;
                         OBJ[OBJCNT].str1="ST";
                         OBJ[OBJCNT].str2="R";
                         OBJ[OBJCNT].str3=RDL.NAME;
                         OBJCNT++;
                         flag=SEM.top();
                         SEM.pop();
                         OBJ[flag].str4=OBJCNT+1;
                         OBJ[OBJCNT].str1="JMP";
                         SEM.push(OBJCNT);
                         OBJCNT++;

                    }
                     if(RDL.ZT=="0")
                    {
                        int flag;

                         flag=SEM.top();
                         SEM.pop();
                         OBJ[flag].str4=OBJCNT+1;
                         OBJ[OBJCNT].str1="JMP";
                         SEM.push(OBJCNT);
                         OBJCNT++;
                    }
                }


            }
            void CODE_FZ()
            {
                if(QT[cnt].str1=="=")
                {
                    if(RDL.ZT=="0")
                    {
                        OBJ[OBJCNT].str1="LD";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=QT[cnt].str2;
                        OBJCNT++;
                        RDL.NAME=QT[cnt].str4;
                        RDL.ZT=QT[cnt].jun4;

                    }
                    if(RDL.NAME==QT[cnt].str4)
                    {
                        if(QT[cnt].jun4=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                        else
                        {
                             RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                    }
                    if(RDL.NAME!=QT[cnt].str2 && RDL.NAME!=QT[cnt].str4)
                    {
                        if(RDL.ZT=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=RDL.NAME;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                        if(RDL.ZT=="0")
                        {
                             OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                    }
                }
            }
            void CODE_IE()
            {
                if(QT[cnt].str1=="else_end")
                {
                    if(RDL.ZT=="1")
                    {
                        int flag;
                         OBJ[OBJCNT].str1="ST";
                         OBJ[OBJCNT].str2="R";
                         OBJ[OBJCNT].str3=RDL.NAME;
                         OBJCNT++;
                         flag=SEM.top();
                         SEM.pop();
                         OBJ[flag].str4=OBJCNT;

                    }

                }

            }
            void CODE_IF()
            {
                if(QT[cnt].str1=="if")
                {
                    if(RDL.NAME=="0")
                    {
                        OBJ[OBJCNT].str1="LD";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=QT[cnt].str2;
                        OBJCNT++;
                        OBJ[OBJCNT].str1="FJ";
                        OBJ[OBJCNT].str2="R";
                        SEM.push(OBJCNT);
                        OBJCNT++;

                    }
                    if(RDL.NAME==QT[cnt].str2)
                    {
                        if(QT[cnt].jun2=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            OBJCNT++;
                            RDL.NAME="0";
                        }
                        else
                        {
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            OBJCNT++;
                            RDL.NAME="0";
                        }
                    }
                    if(RDL.NAME!=QT[cnt].str2&&RDL.NAME!="0")
                    {
                        if(RDL.ZT=="1")
                        {
                            OBJ[OBJCNT].str1="ST";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=RDL.NAME;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            RDL.NAME="0";
                            OBJCNT++;

                        }
                        else
                        {
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str2;
                            OBJCNT++;
                            OBJ[OBJCNT].str1="FJ";
                            OBJ[OBJCNT].str2="R";
                            SEM.push(OBJCNT);
                            RDL.NAME="0";
                            OBJCNT++;

                        }
                    }
                }
            }
        /*   void CODE_IFEND()
            {
                if(QT[cnt].str1=="if_end")
                {
                    if(RDL.ZT=="1")
                    {
                        int flag;
                         OBJ[OBJCNT].str1="ST";
                         OBJ[OBJCNT].str2="R";
                         OBJ[OBJCNT].str3=RDL.NAME;
                         OBJCNT++;
                         flag=SEM.top();
                         SEM.pop();
                         OBJ[flag].str4=OBJCNT;

                    }

                }
            }*/
            void CODE_PD()
            {
                if(QT[cnt].str1==">")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="GT";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="<")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="LT";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="==")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="EQ";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1==">=")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="GE";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="<=")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="LE";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="!=")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="NE";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="&&")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="AND";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                if(QT[cnt].str1=="||")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="OR";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;

                }
                /*
                if(QT[cnt].str1=="!")
                {
                    OBJ[OBJCNT].str1="LD";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str2;
                    OBJCNT++;
                    OBJ[OBJCNT].str1="NO";
                    OBJ[OBJCNT].str2="R";
                    OBJ[OBJCNT].str3=QT[cnt].str3;
                    OBJCNT++;
                    cnt++;
                }*/
            }
            void CODE_while()
            {
                if(QT[cnt].str1=="while")
                {
                    SEM.push(OBJCNT);

                }
            }
            void CODE_WE()
            {
                if(QT[cnt].str1=="while_end")
                {
                    if(RDL.ZT=="1")
                    {
                        int flag;
                        OBJ[OBJCNT].str1="ST";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=RDL.NAME;
                        OBJCNT++;
                        RDL.NAME="0";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[flag].str4=OBJCNT+1;
                        OBJ[OBJCNT].str1="JMP";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[OBJCNT].str4=flag;
                        OBJCNT++;

                    }
                     if(RDL.ZT=="0")
                    {
                        int flag;
                        RDL.NAME="0";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[flag].str4=OBJCNT+1;
                        OBJ[OBJCNT].str1="JMP";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[OBJCNT].str4=flag;
                        OBJCNT++;

                    }
                }
            }
            void CODE_FOR()
            {
                if(QT[cnt].str1=="for")
                {

                    SEM.push(OBJCNT);

                }
            }
            void CODE_FOREND()
            {
                if(QT[cnt].str1=="for_end")
                {
                    if(RDL.ZT=="1")
                    {
                        int flag;
                        OBJ[OBJCNT].str1="ST";
                        OBJ[OBJCNT].str2="R";
                        OBJ[OBJCNT].str3=RDL.NAME;
                        OBJCNT++;
                        RDL.NAME="0";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[flag].str4=OBJCNT+1;
                        OBJ[OBJCNT].str1="JMP";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[OBJCNT].str4=flag;
                        OBJCNT++;
                    }
                    if(RDL.ZT=="0")
                    {
                        int flag;
                        RDL.NAME="0";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[flag].str4=OBJCNT+1;
                        OBJ[OBJCNT].str1="JMP";
                        flag=SEM.top();
                        SEM.pop();
                        OBJ[OBJCNT].str4=flag;
                        OBJCNT++;
                    }
                }
            }
            void CODE_RE_FUNC_CALL()
            {
                if(QT[cnt].str1=="RE_FUNC_CALL")
                {
                    SEM.push(cnt);

                    while(QT[cnt].str1=="PAR_ASS")
                    {
                        if(RDL.ZT=="0")
                        {
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            OBJCNT++;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                        if(RDL.NAME==QT[cnt].str3)
                        {
                            if(QT[cnt].jun3=="1")
                            {
                                OBJ[OBJCNT].str1="ST";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                            else
                            {
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                        }
                        if(RDL.NAME!=QT[cnt].str3 && RDL.NAME!=QT[cnt].str4)
                        {
                            if(RDL.ZT=="1")
                            {
                                OBJ[OBJCNT].str1="ST";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=RDL.NAME;
                                OBJCNT++;
                                OBJ[OBJCNT].str1="LD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                            if(RDL.ZT=="0")
                            {
                                OBJ[OBJCNT].str1="LD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                        }

                    }
                    if(QT[cnt].str1=="CALL_END")
                    {
                        int flag;//调用函数的那条四元式在QT中为第几行
                        flag=SEM.top();
                        SEM.pop();
                        string s;
                        s=QT[flag].str3;
                        int rukou,chukou;
                        for(int i=0;i<num_Synbl;i++)
                        {
                            int hanghao;

                            if(s==SYNBL[i].NAME)
                            {
                                hanghao=SYNBL[i].ADDR;
                            }
                            rukou=PFINFL[hanghao].BEGIN_ADDR;
                            chukou=PFINFL[hanghao].END_ADDR;
                        }
                        OBJ[OBJCNT].str1="CALL";
                        OBJ[OBJCNT].str2=s;
                        OBJ[OBJCNT].str4=rukou;
                        OBJCNT++;

                    }
                }
            }
            void CODE_VO_FUNC_CALL()
            {
                if(QT[cnt].str1=="VO_FUNC_CALL")
                {
                    SEM.push(cnt);

                    while(QT[cnt].str1=="PAR_ASS")
                    {
                        if(RDL.ZT=="0")
                        {
                            OBJ[OBJCNT].str1="LD";
                            OBJ[OBJCNT].str2="R";
                            OBJ[OBJCNT].str3=QT[cnt].str3;
                            OBJCNT++;
                            RDL.NAME=QT[cnt].str4;
                            RDL.ZT=QT[cnt].jun4;

                        }
                        if(RDL.NAME==QT[cnt].str3)
                        {
                            if(QT[cnt].jun3=="1")
                            {
                                OBJ[OBJCNT].str1="ST";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                            else
                            {
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                        }
                        if(RDL.NAME!=QT[cnt].str3 && RDL.NAME!=QT[cnt].str4)
                        {
                            if(RDL.ZT=="1")
                            {
                                OBJ[OBJCNT].str1="ST";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=RDL.NAME;
                                OBJCNT++;
                                OBJ[OBJCNT].str1="LD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                            if(RDL.ZT=="0")
                            {
                                OBJ[OBJCNT].str1="LD";
                                OBJ[OBJCNT].str2="R";
                                OBJ[OBJCNT].str3=QT[cnt].str3;
                                OBJCNT++;
                                RDL.NAME=QT[cnt].str4;
                                RDL.ZT=QT[cnt].jun4;

                            }
                        }

                    }
                    if(QT[cnt].str1=="CALL_END")
                    {
                        int flag;//调用函数的那条四元式在QT中为第几行
                        flag=SEM.top();
                        SEM.pop();
                        string s;
                        s=QT[flag].str2;
                        int rukou,chukou;
                        for(int i=0;i<num_Synbl;i++)
                        {
                            int hanghao;

                            if(s==SYNBL[i].NAME)
                            {
                                hanghao=SYNBL[i].ADDR;
                            }
                            rukou=PFINFL[hanghao].BEGIN_ADDR;
                            chukou=PFINFL[hanghao].END_ADDR;
                        }
                        OBJ[OBJCNT].str1="CALL";
                        OBJ[OBJCNT].str2=s;
                        OBJ[OBJCNT].str4=rukou;
                        OBJCNT++;

                    }
                }
            }


void solve()
{
    DIVIDE();
    active();
    //cout<<"ok"<<endl;
    int i;
    for(i=0;i<d_num;i++)
    {
        cnt=PARTITION[i].first;
        while(cnt<=PARTITION[i].last)
        {
            //cout<<"ok"<<endl;
            if(QT[cnt].str1=="+"||QT[cnt].str1=="-"||QT[cnt].str1=="*"||QT[cnt].str1=="/")
            {
                CODE_BDS();

                //cout<<"ok"<<endl;
            }
            if(QT[cnt].str1=="while_do")
            {
                CODE_WHDO();

                //cout<<"ok"<<endl;
            }
            if(QT[cnt].str1=="do")
            {
                CODE_FODO();

            }
            if(QT[cnt].str1=="else")
            {
                CODE_ELSE();

                //cout<<"ok"<<endl;
            }
            if(QT[cnt].str1=="=")
            {
                CODE_FZ();

            }
            if(QT[cnt].str1=="else_end")
            {
                CODE_IE();

            }
            if(QT[cnt].str1=="if")
            {
                CODE_IF();

            }
           /* if(QT[cnt].str1=="if_end")
            {
                CODE_IFEND();

            }*/
            if(QT[cnt].str1==">"||QT[cnt].str1=="<"||QT[cnt].str1=="=="||QT[cnt].str1==">="||QT[cnt].str1=="<="||QT[cnt].str1=="!="||QT[cnt].str1=="&&"||QT[cnt].str1=="||")
            {
                CODE_PD();

            }
            if(QT[cnt].str1=="while")
            {
                CODE_while();

            }
            if(QT[cnt].str1=="while_end")
            {
                CODE_WE();

            }
            if(QT[cnt].str1=="for")
            {
                CODE_FOR();

            }
            if(QT[cnt].str1=="for_end")
            {
                CODE_FOREND();

            }
            if(QT[cnt].str1=="RE_FUNC_CALL")
            {
                CODE_RE_FUNC_CALL();

            }
            if(QT[cnt].str1=="VO_FUNC_CALL")
            {
                CODE_VO_FUNC_CALL();

            }

            cnt++;
    }
    RDL.NAME="0";
    RDL.ZT="0";
}
}
