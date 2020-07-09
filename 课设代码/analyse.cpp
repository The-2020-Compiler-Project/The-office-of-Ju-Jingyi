#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include"data.h"
#include<fstream>
#include<cstring>
#include<math.h>
using namespace std;


/*
extern struct IDD ID[100];
extern int aut[11][8];
extern int num_ID,num_C,num_Synbl;
extern int C_index,I_index,Synbl_index;
extern int i_token,num_token;              //Token��������Token����
extern string strTOKEN;                         //��ǰ����
//int i_str;                              //��ǰ����ָ��
extern int nn,p,m,e,t;                           //β��ֵ��ָ��ֵ��С��λ����ָ�����ţ�����
extern double num;                           //����ֵ
extern char w[50];                            //Դ���򻺳���
extern int i;                                  //Դ���򻺳���ָ��,��ǰ�ַ�Ϊw[i]


extern struct map col1[4];    //����
extern struct map col2[2]; //�ؼ��ֻ��ʶ��
extern struct map col3[1];                    //���
extern struct map *ptr;
extern int num_map;


*/

int analyse()
{
    FILE *fp;
    fstream k("KT.txt");   //��ʼ���ؼ��ֱ�
    string P_line;
    int j=0;
    while(getline(k,P_line))
    {
        KT[j].keyword=P_line;
        j++;
    }

    fstream p("PT.txt");    //��ʼ�������
    string K_line;
    j=0;
    while(getline(p,K_line))
    {
        PT[j].delimiter=K_line;
        j++;

    }

    int s;                                //��ǰ״̬
	if((fp=fopen("CX.txt","r"))==NULL)    //��ȡ�ļ�
    {
        cout<<"��ȡ�ļ�ʧ��"<<endl;
        exit(0);
    }
    else{
        int line=0;
        fgets(w,100,fp);
        while(w[i]=='\n')
        {
            fgets(w,100,fp);
        }
        while (!feof(fp))
        {
            ++line;
            i=0;
            while(w[i]=='\n')
            {
                fgets(w,100,fp);
            }
            do
            {
            while (w[i]==' '||w[i]=='\t')                       //�˿ո�
                i++;

            if ((w[i]>='a' && w[i]<='z')||(w[i]>='A'&&w[i]<='Z')||(w[i]=='_'))                     //�ж��������
            {
                ptr=col2;  num_map=2;
            }
            else if (w[i]>='0' && w[i]<='9')
            {
                ptr=col1;  num_map=4;
            }
            else if (strchr(col3[0].str,w[i])==NULL)
            {
                if(w[i]=='\n')
                {
                    break;
                }
                cout<<"�Ƿ��ַ�"<<w[i]<<endl;
                i++;
                continue;
            }
            else
            {
                ptr=col3;  num_map=1;
            }

            i--;
            s=1;                                   //��ʼ����һ������
            while (s!=0)
            {
                act(s);
                if (s>=11 && s<=14)
                    break;
                i++;                                //getchar()
                s=find_f(s,w[i]);
            }
            if (s==0)
            {
                cout<<"�ʷ����� @"<<(int)(strTOKEN[0])<<"@"<<w[i]<<"@"<<line<<":"<<i<<endl;
            }
            }while (w[i]!='\n');
            fgets(w,100,fp);
        }
        fclose(fp);
	}
	/*for(int i=0;i<num_Synbl;i++)
    {
        cout<<SYNBL[i].NAME<<endl;
    }
    for(int i=0;i<num_C;i++)
    {
        cout<<CT[i]<<endl;
    }*/
    return 1;
}

void act(int s)
{
	int code;
	switch (s)
	{
	case 1:nn=0;m=0;p=0;t=0;e=1;num=0;
		   strTOKEN="";                   //����������ʼ��
		   break;
    case 2:nn=10*nn+w[i]-48;
	       break;
    case 3:t=1;
		   break;
    case 4:nn=10*nn+w[i]-48; m++;
		   break;
    case 5:t=1;
		   break;
    case 6:if (w[i]=='-') e=-1;
		   break;
    case 7:p=10*p+w[i]-48;
		   break;
    case 8:strTOKEN+=w[i];  //��w[i]�еķ���ƴ�ӵ�strTOKEN��β����
		  break;
    case 9:strTOKEN+=w[i];
		  break;
	case 10:strTOKEN+=w[i];
		   break;
    case 11:
            num=nn*pow(10,e*p-m);           //���㳣��ֵ
            C_index=InsertConst(num);
            TOKEN[i_token].kind='C';
            TOKEN[i_token++].addr=C_index;  //���ɳ���Token
            num_token++;
            break;
	case 12:
           code=Reserve_K(strTOKEN);                   //��ؼ��ֱ�
           if (code!=-1)
	 	   {
	 	       TOKEN[i_token].addr=code;
               TOKEN[i_token++].kind='K'; }   //���ɹؼ���Token
			else
			{
			    I_index=InsertID(strTOKEN);
			    TOKEN[i_token].addr=I_index;
                TOKEN[i_token++].kind='I';            //���ɱ�ʶ��Token
                Synbl_index=InsertSYNBL(strTOKEN);
            }
		    num_token++;
			break;
    case 13:
           code=Reserve_P(strTOKEN);                    //������
           if (code!=-1)
	       {
	           TOKEN[i_token].addr=code;
                TOKEN[i_token++].kind='P';
            }   //���ɽ��Token
            else
			{
               strTOKEN=strTOKEN.substr(0, strTOKEN.length() - 1);
               //strTOKEN[strlen(strTOKEN)-1]='\0';           //�����
			   i--;
               code=Reserve_P(strTOKEN);                 //������
               TOKEN[i_token].addr=code;
               TOKEN[i_token++].kind='P';  //���ɽ��Token
			}
			num_token++;
			break;
    case 14:
		    code=Reserve_P(strTOKEN);     //������
            TOKEN[i_token].addr=code;
            TOKEN[i_token++].kind='P';    //���ɽ��Token
			num_token++;
			break;
	}
}
int find_f(int s,char ch)
{
	int i,col=7;
    struct map *p;
	p=ptr;
	for (i=0;i<num_map;i++)
		if (strchr((p+i)->str,ch))
		{
			col=(p+i)->col;
			break;
		}
	return aut[s][col];
}
int InsertConst(double num)
{
	int i;
	for (i=0;i<num_C;i++)
		if (num==CT[i])
			return i;
	CT[i]=num;
	num_C++;
	return i;
}

int Reserve_K(string str)
{
	int i;
	for (i=0;i<100;i++)
		if (!KT[i].keyword.compare(str))
			return i;
	return -1;
}

int Reserve_P(string str)
{
	int i;
	for (i=0;i<100;i++)
		if (!PT[i].delimiter.compare(str))
			return i;
	return -1;
}

int InsertID(string str)
{
	int i;
    for (i=0;i<num_ID;i++)
		if (!ID[i].idname.compare(str))
			return i;
	ID[i].idname=str;
	num_ID++;
	return i;
}

int InsertSYNBL(string str)
{
    int i;
    for(i=0;i<num_Synbl;i++)
        if(!SYNBL[i].NAME.compare(str))
            return i;
    SYNBL[i].NAME=str;
    num_Synbl++;
    return i;
}
