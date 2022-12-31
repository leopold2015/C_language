#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

static void compute(sqstack *snum, datatype * op)
{
	datatype n1,n2, n;
	st_pop(snum, &n2);
	st_pop(snum, &n1);

	switch(*op)
	{
		case '+':
			n = n1 + n2;
			break;
		case '-':
			n = n1 - n2;
			break;
		case '*':
			n = n1 * n2;
			break;
		case '/':
			n = n1 / n2;
			break;
		default:
			exit(1);
	}

	st_push(snum, &n);

}

static int get_pri(int op)
{
	switch(op)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '\':
			return 2;
	
	}

}

static void deal_op(sqstack *snum, sqstack *sop, int op)
{
	datatype old_op;
	if(st_isempty(sop) || op == '(')
	{
		st_push(sop, &op);
		return ;

	}

	st_top(sop, &old_op);
	if(get_pri(op) > get_pri(old_op))
	{
		st_push(sop, &op);
		return;

	}

	while(get_pri(op) <= get_pri(old_op))
	{
		st_pop(sop, &old_op);
		compute(snum, &old_op);
		if(st_isempty(sop))
			break;

		st_top(sop, &old_op);
	}
	st_push(sop, &op);

}


static void deal_bracket(sqstack *snum, sqstack *sop)
{
	datatype old_op;
	st_top(sop, &old_op);

	while(old_op != '(')
	{
		st_pop(sop, &old_op);
		compute(snum, &old_op);
		st_top(sop, &old_op);
	}
	st_pop(sop, &old_op);
}

int main()
{
	char str[] = "(11+3)*2-5";
	sqstack *snum, *sop;
	int value = 0;
	int flag = 0;
	int i;
	datatype old_op;

	snum = st_create();
	if(snum == NULL)
		exit(1);

	sop = st_create();
	if(sop == NULL)
		exit(1);

	while(str[i] != '\0')
	{
		if(str[i] > '0' && str[i] < '9')
		{
			value = value * 10 + (str[i] - '0');
			flag = 1;
		}
		else  // is a op
		{
			if(flag)
			{
				st_push(snum, &value);

				flag = 0;
				value = 0;
			}
			if(str[i] == ')')
			{
				deal_bracket(snum, sop);

			}
			else  // ( + - * /
			{
				deal_op(snum, sop, str[i]);
			}
		}
		i++;
	}

	if(flag)
		st_push(snum, &value);

	while(!st_isempty(sop))
	{
		st_pop(sop, &old_op);
		compute(snum, &old_op);
	}
	
	datatype result;
	st_top(snum, &result);
	printf("the result is %d\n", result);

	st_destroy(snum);
	st_destroy(sop);

	exit(0);
}
