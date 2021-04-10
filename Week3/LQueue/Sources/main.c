#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "menu.h" 



int main(void) {
	LQueue Q;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': {
				count++;
				system("cls");
				InitLQueue(&Q);
				printf("初始化成功！\n");
				system("pause");
				system("cls"); 
				break;
			}
			
			case '2': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				int type; 
				printf("请输入数据数据类型(1代表整数，2代表小数，3代表字符，4代表字符串)\n");
				scanf("%d", &type);
				switch(type) { // 不同数据类型输出不同值，利用type做检测 
					case 1:{
						int data;
						printf("请输入数据：");
						int judge = scanf("%d", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							(EnLQueue(&Q, &data, type));
							printf("进队成功！\n");	
						}
						break;
					}
					
					case 2:{
						double data;
						printf("请输入数据：");
						int judge = scanf("%lf", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							(EnLQueue(&Q, &data, type));
							printf("进队成功！\n");	
						}						
						break;
					}
					
					case 3:{
						char* data;
						int judge = scanf("%s", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							EnLQueue(&Q, &data, type);
							printf("进队成功！\n");
							while (getchar() != '\n');	
						}
						break;
					}		
					
					case 4:{
						char data[30];
						printf("请输入数据:");
						int judge = scanf("%s", data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							EnLQueue(&Q, data, type);
							printf("进队成功！\n");	
						}
						break;
					}
					default:{
						printf("数据类型错误！\n");
						while(getchar() != '\n');
						break;
					}
				}
				system("pause");
				system("cls");
				break;
				
			}
			
			case '3': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				if (DeLQueue(&Q)) 
					printf("出队成功！\n");
				else {
					printf("出队失败！\n");
					printf("队列为空！\n"); 
			    }
				system("pause");
				system("cls"); 
				break;
			}
			
			case '4': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyLQueue(&Q)) {
					printf("队列为空！\n");
					system("pause");
					system("cls");					
					break;
				}
				void* data;
				if (Q.front->next->type == 1) {
					data = (int*)malloc(sizeof(int));
					if (GetHeadLQueue(&Q, data))
					printf("队头数据为：%d\n", *(int*)data);
				} 
				if (Q.front->next->type == 2) {
					data = (double*)malloc(sizeof(double));
					if (GetHeadLQueue(&Q, data))
					printf("队头数据为：%.2lf\n", *(double*)data);					
				}
				if (Q.front->next->type == 3) {
					data = (char*)malloc(sizeof(char));
					if (GetHeadLQueue(&Q, data))
					printf("队头数据为：%c\n", *(char*)data);					
				}

				if (Q.front->next->type == 4) {
					data = (char*)malloc(sizeof(char)*30);
					if (GetHeadLQueue(&Q, data))
					printf("队头数据为：%s\n", *(char*)data);					
				}
				system("pause");
				system("cls");
				break;
			}
			
			case '5': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyLQueue(&Q))
				printf("此时已为空队列！\n");
				else {
					ClearLQueue(&Q);
					printf("清空成功！\n");
				}
				system("pause");
				system("cls");
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				int length;
				length = LengthLQueue(&Q);
				printf("此时队列的长度为：%d\n", length);
				system("pause");
				system("cls");
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyLQueue(&Q)) 
				printf("是空队列！\n");
				if(!(IsEmptyLQueue(&Q))) 
				printf("不是空队列！\n");
				system("pause");
				system("cls");
				break;
			}

			case '8': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
				if (TraverseLQueue(&Q, LPrint));
				else 
				printf("此时队列为空！\n");
				system("pause");
				system("cls");
				break;				
			}
			 
			case '0': {
				if (!count) {
					system("cls");
					printf("请先初始化队列！\n");
					system("pause");
					system("cls");
					break;
				}
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
	return 0;
}
