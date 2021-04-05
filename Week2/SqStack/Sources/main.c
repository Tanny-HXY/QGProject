#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#include "menu.h"


<<<<<<< HEAD
=======
int size;
>>>>>>> d9faf681d231405c6aafd7e1436ba74aea48a39b
int main(void) {
	SqStack s;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': {
				count++;
				system("cls");
				printf("请输入栈的大小:");
				if (scanf("%d", &size)) {
					if (initStack(&s, size))
				    printf("初始化成功！\n");
				}
				else
				printf("输入非法字符，初始化失败！\n");
				system("pause");
				system("cls"); 
				break;
			}
			
			case '2': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				printf("请输入数据:");
				if (!(scanf("%d", &data))) {
				    printf("非法输入！\n");
				    printf("进栈失败！\n");
				    fflush(stdin);// 清除输入缓冲区的错误数据
				    system("pause");
				    system("cls");
				    break;
				}
				if (!s.size && s.top != -1) 
				printf("进栈失败！已经满栈！\n");
				if(pushStack(&s, data))
				printf("进栈成功！\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '3': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				if (popStack(&s, &data)) {
					printf("出栈成功！\n");
					printf("栈顶数据为：%d\n",data);
				}
				else {
					printf("出栈失败！\n");
					printf("栈为空栈！\n"); 
			    }
				system("pause");
				system("cls"); 
				break;
			}
			
			case '4': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				if (getTopStack(&s, &data))
				printf("栈顶数据为：%d\n", data);
				if (!(getTopStack(&s, &data)))
				printf("栈为空栈！\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '5': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				if (isEmptyStack(&s))
				printf("此时已为空栈！\n");
				if (clearStack(&s))
				printf("清空成功！\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				int length;
				if(!(stackLength(&s, &length)))
				printf("此时为空栈！\n");
				if(stackLength(&s, &length))
				printf("此时栈的长度为：%d\n", length);
				system("pause");
				system("cls");
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				if (isEmptyStack(&s)) 
				printf("是空栈！\n");
				if(!(isEmptyStack(&s))) 
				printf("不是空栈！\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '0': {
				if (!count) {
					system("cls");
					printf("请先初始化栈！\n");
					system("pause");
					system("cls");
					break;
				}
				if (destroyStack(&s))
				printf("销毁成功！\n");
				system("pause"); 
				return 0; 
				break;
			}
			
			default: {
				printf("您输入了非法字符，请重新输入！\n");
				system("pause");
				system("cls"); 
				break;
			}
		}
	}
}
