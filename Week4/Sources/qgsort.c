#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
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
	// 当左边数组先全都排序完后将右边数组剩余数据存入承载数组 
	if (i == mid + 1) {
		while (j <= end)
		temp[k++] = a[j++];
	}
	// 同理，如果右边先全都排序完将左边数组剩余数据存入承载数组 
	if (j == end + 1) {
		while (i <= mid)
		temp[k++] = a[i++];
	}
	// 最后将承载数组内排序好的数据传回给原数组 
	for (j = 0, i = begin; j < k; i++, j++)
	a[i] = temp[j];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp) {
	// 归并排序本质是分治思想，分治通常可使用递归 
	int mid;
	if (begin >= end)
	return;
	// 二分数组 直至都只剩一个数 
	mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end) { 
	int i, j, t, temp;
	
	if (begin >= end) // 结束递归的条件 
	return;
	i = begin; j = end;
	temp = a[begin]; // 选取第一个数作为基准
	while (i < j) {
		while (a[j] >= temp && i < j) { // 从右往左找一个比基准数小的数 
			j--;
		}
		while (a[i] <= temp && i < j) { // 从左往右找一个比基准数大的数 
			i++;
		}
		// 若还未相遇则交换
		if (i < j) {
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}	
	}
	// i等于j时候将与基准对换位置 
	a[begin] = a[i];
	a[i] = temp;
	QuickSort_Recursion(a, begin, i-1);
	QuickSort_Recursion(a, i+1, end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size) {
	int begin, mid, end;
	begin = 0, end = size - 1;
	mid = Partition(a, begin, end);
	// 使用循环迭代代替递归 
	while (mid > begin) {
		mid = Partition(a, begin, mid - 1);
	}
	while (mid < end) {
		mid = Partition(a, mid + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max) {
	int *count = (int*)malloc(sizeof(int)*(max+1));
	int *SortArray = (int*)malloc(sizeof(int)*size);
	int i, sum;
	
	for (i = 0; i < max+1; i++)
	count[i] = 0;
	
	for (i = 0; i < size; i++)
	SortArray[i] = 0;
	
	// 统计各整数出现次数 
	for (i = 0; i < size; i++)
	count[a[i]]++;
	// 计算小于等于自身的个数 
	for (i = 1; i < max+1; i++) 
	count[i] = count[i] + count[i-1];
	// 在排序数组中暂存 
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
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
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
		for (i = 0; i< size; i++) { // 通过这个循环求出从小到大各位上的数 
			IndexArray[i] = a[i] / tmp % 10;
			Bucket[IndexArray[i]]++;
		}
		// 以下与计数排序算法一样 
		for (i = 1; i < 10; i++)
		Bucket[i] = Bucket[i] + Bucket[i-1];
		
		for (i = size - 1; i >=0; i--) 
		SortArray[--Bucket[IndexArray[i]]] = a[i];
		
		for (i = 0; i< size; i++)
		a[i] = SortArray[i];
		tmp *= 10;	
	}
////	 将排序好的数组传回a 
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size) {
	int p0, p1, p2;
	p0 = p1 = 0;
	p2 = size - 1;
	while (p1 <= p2) {
		if (a[p1] == 2) { // 遍历索引等于2时与对应索引位置交换 
			a[p1] = a[p2];
			a[p2] = 2;
			p2--;
		}
		// 不能让p2的数值为2，否则进行交换时会将2交换至本该为1的位置 
		if (a[p2] == 2)
		p2--;
		
		if (a[p1] == 0) { // 遍历索引等于0时与对应索引位置交换
			a[p1] = a[p0];
			a[p0] = 0;
			p0++;
		}
		// 同理， 即p0,p2指针分别不能指向0或2，然后与p1交换完成排序 
		if (a[p0] == 0)
		p0++;
		
		p1++;
	}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
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
