#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	Q->front = Q->rear = 0;
	Q->length = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
	int i;
	for(i = 0; i < MAXQUEUE; i++)
	free(Q->data[i]);
	return;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
	if (Q->length == MAXQUEUE)
	return TRUE;
	else 
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
	if (Q->length == 0)
	return TRUE;
	else
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
	if (IsEmptyAQueue(Q))
	return FALSE;
	switch(type) {
		case 1: {
			memcpy(e, Q->data[Q->front], sizeof(int));
			break;
		}
		case 2: {
			memcpy(e, Q->data[Q->front], sizeof(double));			
			break;
		}
		case 3: {
			memcpy(e, Q->data[Q->front], sizeof(char));			
			break;
		}
		default: {
			break;
		}
	}
	return TRUE;	 
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
	return Q->length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data) {
	if (IsFullAQueue(Q))
	return FALSE;
	switch(type) {
		case 1:{
			Q->data[Q->rear] = (int*)malloc(sizeof(int));
			memcpy(Q->data[Q->rear], data, sizeof(int));
			break;
		}
					
		case 2:{
			Q->data[Q->rear] = (double*)malloc(sizeof(double));
			memcpy(Q->data[Q->rear], data, sizeof(double));
			break;
		}
					
		case 3:{
			Q->data[Q->rear] = (char*)malloc(sizeof(char));
			memcpy(Q->data[Q->rear], data, sizeof(char));
			break;
		}
										
		default:{
			printf("数据类型有误！\n");
			break;
		}
	}
	Q->length++;
	datatype[Q->rear] = type;		
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;	
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
	return FALSE;
	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	Q->front = Q->rear = 0;
	Q->length = 0;
	return;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int datatype)) {
	int i = Q->front;
	for (; i != Q->rear; i = (i + 1)%MAXQUEUE) {
		(*foo)(Q->data[i], datatype[i]);
	}
	return TRUE;
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q, int datatype) {
	if (datatype == 1)
	printf("%d ", *(int*)q);
	if (datatype == 2)
	printf("%.2lf ", *(double*)q);
	if(datatype == 3)
	printf("%c ", *(char*)q);
} 
