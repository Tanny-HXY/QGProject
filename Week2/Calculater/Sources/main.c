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
	    printf("��������ʼ��ʧ�ܣ�");
	    exit(1);
	}
	printf("���������ʽ:\n");
	scanf("%s", str);
	result = Calculate(&num, &opt, str);
	printf("���Ϊ:%d\n", result);
	return 0;
}
