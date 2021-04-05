#include <stdio.h>
#include "LinkStack.h"


//定义符号优先级
int Priority(char s) {
	switch(s) {
		case '(':// 左括号最高 
			return 3;
		case '*':
		case '/':// 其次乘除 
			return 2;
		case '+':
		case '-':// 最后加减 
			return 1;
		default :
			return 0;
	}
}

int Calculate(LinkStack *num, LinkStack *opt, char *str) {
	int i = 0, tmp = 0, j;
	int result;
	
	while (str[i] != '\0' || !isEmptyLStack(opt)) {
		if (str[i] >= '0' && str[i] <= '9' ) {// 将输入进的计算式的数字转换为int类型的数，并且压入num数栈 
			tmp = tmp * 10 + str[i] - '0';
			i++;
			if (str[i] < '0' || str[i] > '9') {
				pushLStack(num, tmp);
				tmp = 0;
			}
		}
		else {
			// 将符号压入opt操作栈  空栈，不是右括号，优先级比当前栈顶高都压入栈 
			if(isEmptyLStack(opt) || (getTopLStack(opt) == '('
			   && str[i] != ')') || Priority(str[i]) > 
			   Priority(getTopLStack(opt))) {
			   pushLStack(opt, str[i]);
			   i++;
			   continue;
		    }
		    // 当栈顶已经为左括号且遇上右括号时将操作栈内左括号弹出 
		    if (getTopLStack(opt) == '(' && str[i] == ')') {
			    popLStack(opt);
			    i++;
			    continue;
		    }
		    // 当操作栈非空，或栈顶符号优先级小于当前符号时，弹出，并计算数字栈顶两个数 
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
