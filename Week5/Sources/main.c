#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
#include "menu.h"


int main(void) {
	BinarySortTree T; 
	int flag = 0; // 检测是否初始化 
	while (1) {
		menu();
		int userkey;
		int judge = scanf("%d", &userkey);
		// 非法输入检测 
		if (!judge) {
			printf("非法输入！\n");
			while (getchar() != '\n');
			system("pause");
			system("cls");
			continue;
		}
		switch(userkey) {
			case 1: {
				if (BST_init(&T))
				printf("初始化成功！\n");
				flag = 1; 
				system("pause");
				system("cls");
				break;
			}
			
			case 2: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				else {
					ElemType data;
					printf("请输入结点数据:");
					int judge = scanf("%d", &data);
					if (!judge) {
						printf("非法输入！\n");
						while (getchar() != '\n');
					}
					else if (BST_insert(&T, data))
					printf("插入成功！\n");
					system("pause");
					system("cls");
					break;
				}
			}
			
			case 3: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else {
					ElemType data;
					printf("请输入所需删除数据：");
					int judge = scanf("%d", &data);
					if (!judge) {
						printf("非法输入！\n");
						while (getchar() != '\n');
					}
					else if (!BST_search(&T, data))
					printf("删除失败，不存在此数据！\n");
					else {
						BST_delete(&T, data);
						printf("删除成功！\n");
					}
				}
				system("pause");
				system("cls");
				break;
			}
			
			case 4: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else {
					ElemType data;
					printf("请输入查询数据：");
					int judge = scanf("%d", &data);
					if (judge == 0) {
						printf("非法输入！\n");
						while (getchar() != '\n');
					}
					else if (BST_search(&T, data))
					printf("此数据在树中存在！\n");
					else
					printf("不存在此数据！\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			
			case 5: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_preorderR(&T, visit);
				system("pause");
				system("cls");
				break;
			}
			
			case 6: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_inorderR(&T, visit);
				system("pause");
				system("cls");
				break;
			}
			
			case 7: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_postorderR(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 8: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_preorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 9: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_inorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 10: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_postorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");				
				break;
			}
			
			case 11: {
				if (!flag) {
					printf("请先初始化二叉排序树！\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("请先插入数据！\n");
				else
				BST_levelOrder(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 0: {
				printf("退出成功！\n");
				return 0;
				break;
			}
			
			default: {
				printf("非法输入！\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}


