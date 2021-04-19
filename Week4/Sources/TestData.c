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
		printf("文件打开错误！\n");
		exit(0);
	}
	// 利用时间作为随机数生成的种子，利用每一刻的时间实现伪随机 
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
		printf("文件打开错误！\n");
		exit(0);
	}
	// 利用时间作为随机数生成的种子，利用每一刻的时间实现伪随机 
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
