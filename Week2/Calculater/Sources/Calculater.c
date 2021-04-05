#include <stdio.h>
#include "LinkStack.h"


//����������ȼ�
int Priority(char s) {
	switch(s) {
		case '(':// ��������� 
			return 3;
		case '*':
		case '/':// ��γ˳� 
			return 2;
		case '+':
		case '-':// ���Ӽ� 
			return 1;
		default :
			return 0;
	}
}

int Calculate(LinkStack *num, LinkStack *opt, char *str) {
	int i = 0, tmp = 0, j;
	int result;
	
	while (str[i] != '\0' || !isEmptyLStack(opt)) {
		if (str[i] >= '0' && str[i] <= '9' ) {// ��������ļ���ʽ������ת��Ϊint���͵���������ѹ��num��ջ 
			tmp = tmp * 10 + str[i] - '0';
			i++;
			if (str[i] < '0' || str[i] > '9') {
				pushLStack(num, tmp);
				tmp = 0;
			}
		}
		else {
			// ������ѹ��opt����ջ  ��ջ�����������ţ����ȼ��ȵ�ǰջ���߶�ѹ��ջ 
			if(isEmptyLStack(opt) || (getTopLStack(opt) == '('
			   && str[i] != ')') || Priority(str[i]) > 
			   Priority(getTopLStack(opt))) {
			   pushLStack(opt, str[i]);
			   i++;
			   continue;
		    }
		    // ��ջ���Ѿ�Ϊ������������������ʱ������ջ�������ŵ��� 
		    if (getTopLStack(opt) == '(' && str[i] == ')') {
			    popLStack(opt);
			    i++;
			    continue;
		    }
		    // ������ջ�ǿգ���ջ���������ȼ�С�ڵ�ǰ����ʱ������������������ջ�������� 
		    if ((str[i] != '\0' && !isEmptyLStack(opt)) || 
		        (str[i] == ')' && getTopLStack(opt) != '(')
			    || Priority(str[i]) <= Priority(getTopLStack(opt))) {	
			    switch(popLStack(opt)) {
				    case '+':
					    pushLStack(num, popLStack(num) + popLStack(num));
					    break;
				    case '-':
					    j = popLStack(num);
					    pushLStack(num, popLStack(num) - j);
					    break;
				    case '*':
					    pushLStack(num, popLStack(num) * popLStack(num));
					    break;
				    case '/':
				 	    j = popLStack(num);
					    pushLStack(num, popLStack(num) / j);
					    break;	
			    }   
			    continue;
		    }
	    }
	}
	return popLStack(num);
} 
