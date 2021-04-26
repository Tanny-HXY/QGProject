#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
#include "menu.h"


int main(void) {
	BinarySortTree T; 
	int flag = 0; // ����Ƿ��ʼ�� 
	while (1) {
		menu();
		int userkey;
		int judge = scanf("%d", &userkey);
		// �Ƿ������� 
		if (!judge) {
			printf("�Ƿ����룡\n");
			while (getchar() != '\n');
			system("pause");
			system("cls");
			continue;
		}
		switch(userkey) {
			case 1: {
				if (BST_init(&T))
				printf("��ʼ���ɹ���\n");
				flag = 1; 
				system("pause");
				system("cls");
				break;
			}
			
			case 2: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				else {
					ElemType data;
					printf("������������:");
					int judge = scanf("%d", &data);
					if (!judge) {
						printf("�Ƿ����룡\n");
						while (getchar() != '\n');
					}
					else if (BST_insert(&T, data))
					printf("����ɹ���\n");
					system("pause");
					system("cls");
					break;
				}
			}
			
			case 3: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else {
					ElemType data;
					printf("����������ɾ�����ݣ�");
					int judge = scanf("%d", &data);
					if (!judge) {
						printf("�Ƿ����룡\n");
						while (getchar() != '\n');
					}
					else if (!BST_search(&T, data))
					printf("ɾ��ʧ�ܣ������ڴ����ݣ�\n");
					else {
						BST_delete(&T, data);
						printf("ɾ���ɹ���\n");
					}
				}
				system("pause");
				system("cls");
				break;
			}
			
			case 4: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else {
					ElemType data;
					printf("�������ѯ���ݣ�");
					int judge = scanf("%d", &data);
					if (judge == 0) {
						printf("�Ƿ����룡\n");
						while (getchar() != '\n');
					}
					else if (BST_search(&T, data))
					printf("�����������д��ڣ�\n");
					else
					printf("�����ڴ����ݣ�\n");
				}
				system("pause");
				system("cls"); 
				break;
			}
			
			case 5: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_preorderR(&T, visit);
				system("pause");
				system("cls");
				break;
			}
			
			case 6: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_inorderR(&T, visit);
				system("pause");
				system("cls");
				break;
			}
			
			case 7: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_postorderR(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 8: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_preorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 9: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_inorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 10: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_postorderI(&T, visit);
				printf("\n");
				system("pause");
				system("cls");				
				break;
			}
			
			case 11: {
				if (!flag) {
					printf("���ȳ�ʼ��������������\n");
					system("pause");
					system("cls");
					break;
				}
				if (T.root == NULL)
				printf("���Ȳ������ݣ�\n");
				else
				BST_levelOrder(&T, visit);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 0: {
				printf("�˳��ɹ���\n");
				return 0;
				break;
			}
			
			default: {
				printf("�Ƿ����룡\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}


