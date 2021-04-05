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
	while (1) {
		printf("���������ʽ(����q�˳�):\n");
	    scanf("%s", str);
	    if (str[0] == 'q')
		return 0; 
	    result = Calculate(&num, &opt, str);
	    printf("���Ϊ:%d\n", result);
	} 
}
