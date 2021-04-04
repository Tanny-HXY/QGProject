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
            		printf("���������ݸ�����");
            		scanf("%d", &count);
            		printf("���������ݣ�");
            		Init(L, count);
            		TraverseList(L, visit);
            		printf("��ʼ������ɹ���\n");
				}
            	else
            	printf("��ʼ������ʧ�ܣ�\n");
            	system("pause");
				system("cls");
				break; 
            case '2':
            	system("cls");
				int d, position; 
                printf("��������������������λ�ã�");
			    scanf("%d %d",&d, &position);
			    if(L != NULL);
			    LinkedList p = FindNodePosition(L, position);// �ҵ�Ҫ�������ǰһ����� 
				LinkedList q = (LinkedList)malloc(sizeof(LNode));// ����һ���µĽ�� 
				q->data = d;
				if (!p)
				printf("����ʧ�ܣ�\n"); 
			    else if (InsertList(p, q))
			    printf("����ɹ���\n");
			    else
			    printf("����ʧ�ܣ�\n");
				system("pause");
				system("cls"); 
			    break; 
            case '3':
            	system("cls");
            	if (L->next == NULL)
            	printf("������Ϊ�ձ�\n");
            	TraverseList(L, visit);
            	system("pause");
            	system("cls");
            	break;
            case '4':
            	system("cls");
            	printf("��ʱ����Ϊ\n"); 
				TraverseList(L, visit);
            	if (ReverseList(&L)) {
            	printf("��ת����ɹ�\n");
            	printf("��ʱ����Ϊ\n");
            	TraverseList(L, visit);
                }
            	else
            	printf("��ת����ʧ��\n");
            	system("pause");
				system("cls"); 
            	break;
            case '5':
            	system("cls");
            	if (L->next->next == NULL)
            	printf("�����С��2�޷���ż����");
            	else{
            	printf("��ʱ����Ϊ\n");
            	TraverseList(L, visit);
				LinkedList NewHead = ReverseEvenList(&L); 
            	printf("��ż��ת�ɹ���\n");
            	printf("��ʱ����Ϊ\n");
            	TraverseList(NewHead, visit);
                }
                system("pause");
                system("cls");
            	break;
            case '6':
            	system("cls");
            	LinkedList mid = FindMidNode(&L);
            	printf("�м����ֵΪ%d\n", mid->data);
				system("pause");
            	system("cls");
            	break;
            case '7':
            	system("cls");
            	int n, elem;
            	printf("������ɾ���Ľ�㣺");
            	scanf("%d", &n);
            	if (DeleteList(FindNodePosition(L, n), &elem)) {
				printf("���ɾ���ɹ���\n");
				printf("�ý�������Ϊ:%d\n", elem);	
				}
				else
				printf("ɾ��ʧ�ܣ�\n");
				system("pause");
				system("cls");
            	break;
            case '8':
            	system("cls");
            	int data;
            	printf("��������ҵ����ݣ�");
            	scanf("%d", &data);
            	if (SearchList(L, data))
            	printf("�����д��ڸ����ݣ�\n");
            	else
            	printf("�����в����ڸ����ݣ�\n");
            	system("pause");
            	system("cls");
            	break;
            case '9':
            	system("cls");
            	LinkedList LoopList = CreateLoopList();
            	if (IsLoopList(LoopList)) 
            	printf("�������л�\n");
            	else
            	printf("������û�л�\n");
            	system("pause");
            	system("cls");
            	break;
            case '0':
            	system("cls");
            	DestroyList(&L);
            	system("cls");
            	printf("���ٳɹ�!");
            	return 0;
            	break;
        }
    }
    return 0;
}
