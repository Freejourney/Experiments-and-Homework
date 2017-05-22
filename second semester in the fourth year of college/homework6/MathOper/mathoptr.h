//mathoptr.h
#ifndef MATHOPRATOR_H
#define MATHOPRATOR_H

#include <iostream>

struct MathOperator
{
	char op;
	int ipre, spre;
	explicit MathOperator(char ch = '+');
	bool operator>=(MathOperator optr) const { return (spre >= optr.ipre); }
};
MathOperator::MathOperator(char ch)
{
	op = ch;
	switch(op)
	{
	case '+':
	case '-': ipre = 1; spre = 1; break;
	case '*':
	case '/': ipre = 2; spre = 2; break;
	case '(': ipre = 3; spre = -1; break;
	case ')': ipre = 0; spre = 0; break;
	}
}
#endif
