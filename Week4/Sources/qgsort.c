#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >=0; j--) {
			if (a[j] > temp)
			a[j+1] = a[j];
			else 
			break;
		}
		a[j+1] = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
	int t;
	int i, j, k;
	i = begin; j = mid + 1; k = 0;
	
	while (i <= mid && j <= end) {
		if (a[i] < a[j])
		temp[k++] = a[i++];
		else
		temp[k++] = a[j++];
	}
	// �����������ȫ����������ұ�����ʣ�����ݴ���������� 
	if (i == mid + 1) {
		while (j <= end)
		temp[k++] = a[j++];
	}
	// ͬ������ұ���ȫ�������꽫�������ʣ�����ݴ���������� 
	if (j == end + 1) {
		while (i <= mid)
		temp[k++] = a[i++];
	}
	// ��󽫳�������������õ����ݴ��ظ�ԭ���� 
	for (j = 0, i = begin; j < k; i++, j++)
	a[i] = temp[j];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp) {
	// �鲢�������Ƿ���˼�룬����ͨ����ʹ�õݹ� 
	int mid;
	if (begin >= end)
	return;
	// �������� ֱ����ֻʣһ���� 
	mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end) { 
	int i, j, t, temp;
	
	if (begin >= end) // �����ݹ������ 
	return;
	i = begin; j = end;
	temp = a[begin]; // ѡȡ��һ������Ϊ��׼
	while (i < j) {
		while (a[j] >= temp && i < j) { // ����������һ���Ȼ�׼��С���� 
			j--;
		}
		while (a[i] <= temp && i < j) { // ����������һ���Ȼ�׼������� 
			i++;
		}
		// ����δ�����򽻻�
		if (i < j) {
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}	
	}
	// i����jʱ�����׼�Ի�λ�� 
	a[begin] = a[i];
	a[i] = temp;
	QuickSort_Recursion(a, begin, i-1);
	QuickSort_Recursion(a, i+1, end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size) {
	int begin, mid, end;
	begin = 0, end = size - 1;
	mid = Partition(a, begin, end);
	// ʹ��ѭ����������ݹ� 
	while (mid > begin) {
		mid = Partition(a, begin, mid - 1);
	}
	while (mid < end) {
		mid = Partition(a, mid + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end) {
	int i, j, t, temp;
	i = begin, j = end;
	temp = a[begin];
	while (i < j) {
		while (i < j && a[j] >= temp)
		j--;
		while (i < j && a[i] <= temp)
		i++;
		if (i < j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[begin] = a[i];
	a[i] = temp;
	
	return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max) {
	int *count = (int*)malloc(sizeof(int)*(max+1));
	int *SortArray = (int*)malloc(sizeof(int)*size);
	int i, sum;
	
	for (i = 0; i < max+1; i++)
	count[i] = 0;
	
	for (i = 0; i < size; i++)
	SortArray[i] = 0;
	
	// ͳ�Ƹ��������ִ��� 
	for (i = 0; i < size; i++)
	count[a[i]]++;
	// ����С�ڵ�������ĸ��� 
	for (i = 1; i < max+1; i++) 
	count[i] = count[i] + count[i-1];
	// �������������ݴ� 
	for (i = size - 1; i>=0; i--) {
		count[a[i]]--;
		SortArray[count[a[i]]] = a[i];
	} 

	for (i = 0; i < size; i++)
	a[i] = SortArray[i];
	
	free(count);
	free(SortArray);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size) {
	int *IndexArray = (int*)malloc(sizeof(int)*size);
	int *Bucket = (int*)malloc(sizeof(int)*10);
	int *SortArray = (int*)malloc(sizeof(int)*size);
	
	int tmp, i, max;
	tmp = 1;
	max = a[0];
	
	for (i=0; i<size; i++)
	if (a[i]>max)
	max = a[i];
	
	while (max / tmp) {
		memset(Bucket, 0, sizeof(int)*10);
		for (i = 0; i< size; i++) { // ͨ�����ѭ�������С�����λ�ϵ��� 
			IndexArray[i] = a[i] / tmp % 10;
			Bucket[IndexArray[i]]++;
		}
		// ��������������㷨һ�� 
		for (i = 1; i < 10; i++)
		Bucket[i] = Bucket[i] + Bucket[i-1];
		
		for (i = size - 1; i >=0; i--) 
		SortArray[--Bucket[IndexArray[i]]] = a[i];
		
		for (i = 0; i< size; i++)
		a[i] = SortArray[i];
		tmp *= 10;	
	}
////	 ������õ����鴫��a 
//	for (i = 0; i< size; i++)
//	a[i] = SortArray[i];
	
	free(Bucket);
	free(SortArray);
	free(IndexArray);
	Bucket = NULL;
	SortArray = NULL;
	IndexArray = NULL;
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size) {
	int p0, p1, p2;
	p0 = p1 = 0;
	p2 = size - 1;
	while (p1 <= p2) {
		if (a[p1] == 2) { // ������������2ʱ���Ӧ����λ�ý��� 
			a[p1] = a[p2];
			a[p2] = 2;
			p2--;
		}
		// ������p2����ֵΪ2��������н���ʱ�Ὣ2����������Ϊ1��λ�� 
		if (a[p2] == 2)
		p2--;
		
		if (a[p1] == 0) { // ������������0ʱ���Ӧ����λ�ý���
			a[p1] = a[p0];
			a[p0] = 0;
			p0++;
		}
		// ͬ�� ��p0,p2ָ��ֱ���ָ��0��2��Ȼ����p1����������� 
		if (a[p0] == 0)
		p0++;
		
		p1++;
	}
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
 int FindKthSmallest(int *a, int begin, int end, int k) {
 	int  i, j, t, temp;
 	if (begin >= end)
	return a[k-1];
	i = begin;
	j = end;
	temp = a[begin];
	
	while (i < j) {
		while (i < j && a[j] >= temp)
		j--;
		while (i < j && a[i] <= temp)
		i++;
		if (i < j) {
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	a[begin] = a[i];
	a[i] = temp;
	FindKthSmallest(a, begin, i - 1, k);
	FindKthSmallest(a, i + 1, end, k);
}
