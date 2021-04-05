#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "Calculater.h"
#define MAXSIZE 10000 

int main(void) {
	LinkStack num, opt;
	int result;
	char str[MAXSIZE] = {0};
	if (!(initLStack(&num)) || !(initLStack(&opt))) {
	    printf("计算器初始化失败！");
	    exit(1);
	}
	while (1) {
		printf("请输入计算式(输入q退出):\n");
	    scanf("%s", str);
	    if (str[0] == 'q')
		return 0; 
	    result = Calculate(&num, &opt, str);
	    printf("结果为:%d\n", result);
	} 
}
