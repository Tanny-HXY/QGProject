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
    				printf("���������ݸ�����");
    				scanf("%d", &count);
    				printf("���������ݣ�");
    				Init_DuL(L, count);
    				TraverseList_DuL(L, visit); 
    				printf("��ʼ���ɹ���\n");
				}
				else 
				printf("��ʼ��ʧ�ܣ�\n");
				system("pause");
				system("cls");
				break;
			case '2':
			    system("cls");
			    ElemType data;
			    int n;
			    printf("������������ݼ���λ�ã�");
			    scanf("%d %d", &data, &n);
			    if (n > GetDuListLength(L)) {
			    	printf("����λ�ô���\n");
			    	break;
				}
				DuLinkedList p = FindDuLNodePosition(L, n);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = data;
			    if (InsertAfterList_DuL(p, q))// ����ʹ�ú�巨 
			    printf("����ɹ���\n");
			    else
			    printf("����ʧ�ܣ�\n");
			    system("pause");
			    system("cls");
			    break;
			case '3':
			    system("cls");
			    ElemType data_2;
			    int num;
			    printf("������������ݼ���λ�ã�");
			    scanf("%d %d", &data_2, &num);
			    if (num > GetDuListLength(L)) {
			    	printf("����λ�ô���\n");
			    	break;
				}
				DuLinkedList m = FindDuLNodePosition(L, num);
				m = m->next; 
				DuLinkedList s = (DuLinkedList)malloc(sizeof(DuLNode));
				s->data = data_2;
			    if (InsertBeforeList_DuL(m, s))// ����ʹ��ǰ�巨 
			    printf("����ɹ���\n");
			    else
			    printf("����ʧ�ܣ�\n");
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
				printf("������Ҫɾ���Ľ�㣺");
				scanf("%d", &position);
				judge = GetDuListLength(L);
				if (position > judge) {
					printf("�����ڸý�㣡\n");
					system("pause");
					system("cls");
					break;
				}
				DuLinkedList r = FindDuLNodePosition(L, position);
				if(DeleteList_DuL(r, &e)) {
					printf("ɾ���������Ϊ��%d\n", e);
					printf("ɾ���ɹ���\n");
				}
				else
				printf("ɾ��ʧ�ܣ�");
				system("pause");
				system("cls");
			    break;
			case '0':
			    system("cls");
				DestroyList_DuL(&L);
				printf("���ٳɹ���\n");
				return 0; 
		}
	}
		
}
