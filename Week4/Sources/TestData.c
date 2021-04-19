#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 200000


void CreateTestData(void) {
	int *data = (int*)malloc(sizeof(int)*MAXSIZE);
	int i;	
	FILE *fp;
	fp = fopen("data.txt", "a");
	if (fp == NULL) {
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	// ����ʱ����Ϊ��������ɵ����ӣ�����ÿһ�̵�ʱ��ʵ��α��� 
	srand((unsigned)time(NULL));
	for (i = 0; i< MAXSIZE; i++) {
		data[i] = rand()%100;
		fprintf(fp, "%d ", data[i]);
	}
	fclose(fp);
	free(data);
}

void ReadTestData(int length, int* test) {
	int i;
	FILE *fp;
	fp = fopen("data.txt", "r");
	for (i = 0; i< length; i++) 
	fscanf(fp, "%d ", &test[i]);
	fclose(fp);
}

void CreateTestData2(void) {
	int *data = (int*)malloc(sizeof(int)*100);
	int i;	
	FILE *fp;
	fp = fopen("data.txt", "a");
	if (fp == NULL) {
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	// ����ʱ����Ϊ��������ɵ����ӣ�����ÿһ�̵�ʱ��ʵ��α��� 
	srand((unsigned)time(NULL));
	for (i = 0; i< 100; i++) {
		data[i] = rand()%100;
		fprintf(fp, "%d ", data[i]);
	}
	fclose(fp);
	free(data);
}

void ReadTestData2(int* test) {
	int i;
	FILE *fp;
	fp = fopen("data.txt", "r");
	for (i = 0; i< 100; i++) 
	fscanf(fp, "%d ", &test[i]);
	fclose(fp);
}
