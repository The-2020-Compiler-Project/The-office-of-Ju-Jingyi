#include<iostream>
#include<stack>
#include <stdlib.h>
#include <stdio.h>
#include<string>
using namespace std;

struct TOKEND
{
     char kind;
     int addr;
}TOKEN[];
stack<string> str;
int Sub_Program(struct TOKEND TOKEN,int &n);
int Statement(struct TOKEND TOKEN,int &n);
int Var(struct TOKEND TOKEN,int &n);
int Type(struct TOKEND TOKEN,int &n);

int Expression(struct TOKEND TOKEN,int &n);
int T4(struct TOKEND TOKEN,int &n);
int Item(struct TOKEND TOKEN,int &n);
int T5(struct TOKEND TOKEN,int &n);
int Factor(struct TOKEND TOKEN,int &n);
int Cal_Number(struct TOKEND TOKEN,int &n);


