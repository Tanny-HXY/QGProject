#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"
#include "TestData.h"

#define SIZE_1 10000
#define SIZE_2 50000
#define SIZE_3 200000


int main(void) {
	void menu(void);
	int i;	
	while (1) {
		menu();
		char userkey = getch();
		switch(userkey) {
			case '1':{
				int temp[SIZE_1];
				int test[SIZE_1];
				ReadTestData(SIZE_1, test);
				clock_t istart = clock();
				insertSort(test, SIZE_1);
				clock_t idiff = clock() - istart;
				printf("ֱ�Ӳ���������ʱ��%dms\n", idiff);
				
				ReadTestData(SIZE_1, test);
				clock_t start = clock();
				MergeSort(test, 0, SIZE_1 - 1, temp); 
				clock_t diff = clock() - start;
				printf("�鲢������ʱ��%dms\n", diff);
				
				ReadTestData(SIZE_1, test);
				clock_t qrstart = clock(); 
				QuickSort_Recursion(test, 0, SIZE_1 - 1);
				clock_t qrdiff = clock() - qrstart;
				printf("����������ʱ��%dms\n", qrdiff); 
				
				ReadTestData(SIZE_1, test);
				clock_t qstart = clock();
				QuickSort(test, SIZE_1);
				clock_t qdiff = clock() - qstart;
				printf("�������򣨷ǵݹ飩��ʱ��%dms\n ", qdiff);
				
				ReadTestData(SIZE_1, test);
				clock_t rstart = clock();
				RadixCountSort(test, SIZE_1);
				clock_t rdiff = clock() - rstart;
				printf("��������������ʱ��%dms\n", rdiff);
				system("pause");
				system("cls");
				break;
			}
			
			case '2':{
				int temp[SIZE_2];
				int test[SIZE_2];
				ReadTestData(SIZE_2, test);
				clock_t istart = clock();
				insertSort(test, SIZE_2);
				clock_t idiff = clock() - istart;
				printf("ֱ�Ӳ���������ʱ��%dms\n", idiff); 
				
				ReadTestData(SIZE_2, test);
				clock_t start = clock();
				MergeSort(test, 0, SIZE_2 - 1, temp); 
				clock_t diff = clock() - start;
				printf("�鲢������ʱ��%dms\n", diff);
				
				ReadTestData(SIZE_2, test);
				clock_t qrstart = clock(); 
				QuickSort_Recursion(test, 0, SIZE_2 - 1);
				clock_t qrdiff = clock() - qrstart;
				printf("����������ʱ��%dms\n", qrdiff);
				
				ReadTestData(SIZE_2, test);
				clock_t qstart = clock();
				QuickSort(test, SIZE_2);
				clock_t qdiff = clock() - qstart;
				printf("�������򣨷ǵݹ飩��ʱ��%dms\n ", qdiff);
				
				ReadTestData(SIZE_2, test);
				clock_t rstart = clock();
				RadixCountSort(test, SIZE_2);
				clock_t rdiff = clock() - rstart;
				printf("��������������ʱ��%dms\n", rdiff);
				system("pause");
				system("cls");
				break;
			}
			
			case '3':{
				int temp[SIZE_3];
				int test[SIZE_3];
				ReadTestData(SIZE_3, test);
				clock_t istart = clock();
				insertSort(test, SIZE_3);
				clock_t idiff = clock() - istart;
				printf("ֱ�Ӳ���������ʱ��%dms\n", idiff);
				
				
				ReadTestData(SIZE_3, test);
				clock_t start = clock();
				MergeSort(test, 0, SIZE_3 - 1, temp); 
				clock_t diff = clock() - start;
				printf("�鲢������ʱ��%dms\n", diff);
				
				ReadTestData(SIZE_3, test);
				clock_t qrstart = clock(); 
				QuickSort_Recursion(test, 0, SIZE_3 - 1);
				clock_t qrdiff = clock() - qrstart;
				printf("����������ʱ��%dms\n", qrdiff);
				
				ReadTestData(SIZE_3, test);
				clock_t qstart = clock();
				QuickSort(test, SIZE_3);
				clock_t qdiff = clock() - qstart;
				printf("�������򣨷ǵݹ飩��ʱ��%dms\n ", qdiff);
				
				ReadTestData(SIZE_3, test);
				clock_t rstart = clock();
				RadixCountSort(test, SIZE_3);
				clock_t rdiff = clock() - rstart;
				printf("��������������ʱ��%dms\n", rdiff);				
				system("pause");
				system("cls");
				break;
			}
			
			case '4': {
				int i;
				int test[100];
				int temp[100];
				
				clock_t istart = clock();
				for (i = 0; i < 10000; i++) {
					CreateTestData2();
					ReadTestData2(test);
					insertSort(test, 100); 
				} 
				clock_t idiff = clock() - istart;
				printf("ֱ�Ӳ���������ʱ��%dms\n", idiff);
				
				clock_t start = clock();
				for (i = 0; i < 10000; i++) {
					CreateTestData2();
					ReadTestData2(test);
					MergeSort(test, 0, 99, temp); 
				} 
				clock_t diff = clock() - start;
				printf("�鲢������ʱ��%dms\n", diff);
				
				clock_t qrstart = clock();
				for (i = 0; i < 10000; i++) {
					CreateTestData2();
					ReadTestData2(test);
					QuickSort_Recursion(test, 0, 99); 
				} 
				clock_t qrdiff = clock() - qrstart;
				printf("����������ʱ��%dms\n", qrdiff);
				
				clock_t rstart = clock();
				for (i = 0; i < 10000; i++) {
					CreateTestData2();
					ReadTestData2(test);
					RadixCountSort(test, 100); 
				} 
				clock_t rdiff = clock() - rstart;
				printf("��������������ʱ��%dms\n", rdiff);
				system("pause");
				system("cls");	
				break;
			}
			
			case '5': {
				int i;
				int test[10] = {1, 2, 0, 0, 2, 2, 1, 1, 0, 1};
				printf("�������鵱ǰ˳��Ϊ��\n");
				for (i = 0; i < 10; i++)
				printf("%d ", test[i]);
				printf("\n");
				ColorSort(test, 10);
				printf("�����\n");
				for (i = 0; i < 10; i++)
				printf("%d ", test[i]);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '6': {
				int i, k, num;
				srand((unsigned)time(NULL));
				int *test = (int*)malloc(sizeof(int)*50);
				for (i = 0; i < 50; i++)
				test[i] = rand() % 100;
				printf("��ǰ�����������Ϊ:\n");
				for (i = 0; i < 50; i++) {
					if (i % 10 == 0)
					printf("\n");
					printf("%d ", test[i]);
				}
				printf("\n");
				printf("������k:");
				scanf("%d", &k);
				num = FindKthSmallest(test, 0 , 49, k);
				printf("%d\n", num);
				free(test);
				system("pause");
				system("cls");
				break;
			}
			
			case '0': {
				return 0;
				break;
			}
			
			default: {
				printf("��Ч����\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}

void menu() {
	printf("*******************������������*******************\n");
	printf("1.10000�����������ʱ�����\n");
	printf("2.50000�����������ʱ�����\n");
	printf("3.200000�����������ʱ�����\n");
	printf("4.����С�����������(100����*10k��)\n");
	printf("5.��ɫ����\n"); 
	printf("6.���ҵ�k����\n"); 
	printf("0.�˳�����\n"); 
}
