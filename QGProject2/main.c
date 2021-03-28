#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"

DuLinkedList L = NULL;

int main(void) {
    while (1) {
    	menu();
    	char userKey = getch();
    	switch (userKey) {
    		case '1':
    			system("cls");
    			if(InitList_DuL(&L)) {
    				int count;
    				printf("请输入数据个数：");
    				scanf("%d", &count);
    				printf("请输入数据：");
    				Init_DuL(L, count);
    				TraverseList_DuL(L, visit); 
    				printf("初始化成功！\n");
				}
				else 
				printf("初始化失败！\n");
				system("pause");
				system("cls");
				break;
			case '2':
			    system("cls");
			    ElemType data;
			    int n;
			    printf("请输入插入数据及其位置：");
			    scanf("%d %d", &data, &n);
			    if (n > GetDuListLength(L)) {
			    	printf("插入位置错误！\n");
			    	break;
				}
				DuLinkedList p = FindDuLNodePosition(L, n);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = data;
			    if (InsertAfterList_DuL(p, q))// 插入使用后插法 
			    printf("插入成功！\n");
			    else
			    printf("插入失败！\n");
			    system("pause");
			    system("cls");
			    break;
			case '3':
			    system("cls");
			    ElemType data_2;
			    int num;
			    printf("请输入插入数据及其位置：");
			    scanf("%d %d", &data_2, &num);
			    if (num > GetDuListLength(L)) {
			    	printf("插入位置错误！\n");
			    	break;
				}
				DuLinkedList m = FindDuLNodePosition(L, num);
				m = m->next; 
				DuLinkedList s = (DuLinkedList)malloc(sizeof(DuLNode));
				s->data = data_2;
			    if (InsertBeforeList_DuL(m, s))// 插入使用前插法 
			    printf("插入成功！\n");
			    else
			    printf("插入失败！\n");
			    system("pause");
			    system("cls");
			    break;
			case '4':
			    system("cls");
			    TraverseList_DuL(L, visit);
			    system("pause");
			    system("cls");
			    break;
			case '5':
			    system("cls");
				ElemType e;
				int position, judge;
				printf("请输入要删除的结点：");
				scanf("%d", &position);
				judge = GetDuListLength(L);
				if (position > judge) {
					printf("不存在该结点！\n");
					system("pause");
					system("cls");
					break;
				}
				DuLinkedList r = FindDuLNodePosition(L, position);
				if(DeleteList_DuL(r, &e)) {
					printf("删除结点数据为：%d\n", e);
					printf("删除成功！\n");
				}
				else
				printf("删除失败！");
				system("pause");
				system("cls");
			    break;
			case '0':
			    system("cls");
				DestroyList_DuL(&L);
				printf("销毁成功！\n");
				return 0; 
		}
	}
		
}
