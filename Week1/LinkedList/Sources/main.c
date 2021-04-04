#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "linkedList.h"
#include "menu.h"

LinkedList L = NULL;

int main(void) {
    while (1){
        menu();
        char userKey = getch();
        switch (userKey) {
            case '1':
            	system ("cls");
            	if (InitList(&L)) {
					int count;
            		printf("请输入数据个数：");
            		scanf("%d", &count);
            		printf("请输入数据：");
            		Init(L, count);
            		TraverseList(L, visit);
            		printf("初始化链表成功！\n");
				}
            	else
            	printf("初始化链表失败！\n");
            	system("pause");
				system("cls");
				break; 
            case '2':
            	system("cls");
				int d, position; 
                printf("请输入你想插入的数据与位置：");
			    scanf("%d %d",&d, &position);
			    if(L != NULL);
			    LinkedList p = FindNodePosition(L, position);// 找到要插入结点的前一个结点 
				LinkedList q = (LinkedList)malloc(sizeof(LNode));// 创建一个新的结点 
				q->data = d;
				if (!p)
				printf("插入失败！\n"); 
			    else if (InsertList(p, q))
			    printf("插入成功！\n");
			    else
			    printf("插入失败！\n");
				system("pause");
				system("cls"); 
			    break; 
            case '3':
            	system("cls");
            	if (L->next == NULL)
            	printf("此链表为空表\n");
            	TraverseList(L, visit);
            	system("pause");
            	system("cls");
            	break;
            case '4':
            	system("cls");
            	printf("此时链表为\n"); 
				TraverseList(L, visit);
            	if (ReverseList(&L)) {
            	printf("反转链表成功\n");
            	printf("此时链表为\n");
            	TraverseList(L, visit);
                }
            	else
            	printf("反转链表失败\n");
            	system("pause");
				system("cls"); 
            	break;
            case '5':
            	system("cls");
            	if (L->next->next == NULL)
            	printf("结点数小于2无法奇偶逆序");
            	else{
            	printf("此时链表为\n");
            	TraverseList(L, visit);
				LinkedList NewHead = ReverseEvenList(&L); 
            	printf("奇偶反转成功！\n");
            	printf("此时链表为\n");
            	TraverseList(NewHead, visit);
                }
                system("pause");
                system("cls");
            	break;
            case '6':
            	system("cls");
            	LinkedList mid = FindMidNode(&L);
            	printf("中间结点的值为%d\n", mid->data);
				system("pause");
            	system("cls");
            	break;
            case '7':
            	system("cls");
            	int n, elem;
            	printf("请输入删除的结点：");
            	scanf("%d", &n);
            	if (DeleteList(FindNodePosition(L, n), &elem)) {
				printf("结点删除成功！\n");
				printf("该结点的数据为:%d\n", elem);	
				}
				else
				printf("删除失败！\n");
				system("pause");
				system("cls");
            	break;
            case '8':
            	system("cls");
            	int data;
            	printf("请输入查找的数据：");
            	scanf("%d", &data);
            	if (SearchList(L, data))
            	printf("链表中存在该数据！\n");
            	else
            	printf("链表中不存在该数据！\n");
            	system("pause");
            	system("cls");
            	break;
            case '9':
            	system("cls");
            	LinkedList LoopList = CreateLoopList();
            	if (IsLoopList(LoopList)) 
            	printf("该链表有环\n");
            	else
            	printf("该链表没有环\n");
            	system("pause");
            	system("cls");
            	break;
            case '0':
            	system("cls");
            	DestroyList(&L);
            	system("cls");
            	printf("销毁成功!");
            	return 0;
            	break;
        }
    }
    return 0;
}
