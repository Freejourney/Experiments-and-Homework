//中缀表达式
//MathOperMain.cpp
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include "stack.h"
#include "mathoptr.h"
using namespace std;

int isoperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(');
}
int iswhitespace(char ch)
{
	return (ch == 32 || ch == '\t' || ch == '\n');
}
void Error(char * c)
{
	cerr << c << endl;
	exit(1);
}
void Evaluate(Stack<double> & OpndS, MathOperator optr)
{
	double opnd1 = OpndS.Pop();
	double opnd2 = OpndS.Pop();
	switch(optr.op)
	{
	case '+': OpndS.Push(opnd2+opnd1); break;
	case '-': OpndS.Push(opnd2-opnd1); break;
	case '*': OpndS.Push(opnd2*opnd1); break;
	case '/': OpndS.Push(opnd2/opnd1); break;
	}
}

int main()
{
	int rank = 0;
	char ch;
	double number;
	MathOperator optr1, optr2;
	Stack<double> opndS;
	Stack<MathOperator> optrS;

	cout << "input an infix: " << endl;
	while(cin.get(ch) && ch != '=')
	{
		if(isdigit(ch) || ch == '.')
		{
			cin.putback(ch);
			cin >> number;
			rank++;
			if(rank>1)
				Error("Operator expected!");
			opndS.Push(number);
		}
		else if(isoperator(ch))
		{
			if(ch != '(')
				rank--;
			if(rank < 0)
				Error("Operand expected");
			optr1 = MathOperator(ch);
			while(!optrS.Empty() && optrS.Top() >= optr1)
			{
				optr2 = optrS.Pop();
				Evaluate(opndS, optr2);
			}
			optrS.Push(optr1);
		}
		else if(ch == ')')
		{
			optr1 = MathOperator(ch);
			while(!optrS.Empty() && optrS.Top() >= optr1)
			{
				optr2 = optrS.Pop();
				Evaluate(opndS, optr2);
			}
			if(optrS.Empty())
				Error("Missing left parenthesis");
			optrS.Pop();
		}
		else if(!iswhitespace(ch))
			Error("Invalid input");
	}
	if(rank != 1)
		Error("Operand expected!");
	while(!optrS.Empty())
	{
		optr2 = optrS.Pop();
		if(optr2.op == '(')
			Error("Missing right parenthesis");
		Evaluate(opndS, optr2);
	}
	cout << "The value is " << opndS.Pop() << endl;


	system("pause");
	return 0;
}
