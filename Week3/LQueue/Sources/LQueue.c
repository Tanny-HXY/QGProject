#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = (Node*)malloc(sizeof(Node));
	Q->rear = Q->front;
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	Node *p, *q;
	p = Q->front->next;
	while (q != NULL) { // 循环逐个结点释放 
		q = p->next;
		free(p);
		p = q;
	}
	free(Q->front); // 释放头指针 
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->length == 0)
	return TRUE;
	else
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	switch(Q->front->next->type) {
		case 1: {
			memcpy(e, Q->front->next->data, sizeof(int));
			break;
		}
		case 2: {
			memcpy(e, Q->front->next->data, sizeof(double));			
			break;
		}
		case 3: {
			memcpy(e, Q->front->next->data, sizeof(char));			
			break;
		}
		case 4: {
			memcpy(e, Q->front->next->data, sizeof(char)*30);
			break;
		}
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data, int type) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->type = type;
	switch(p->type) {
		case 1:{
			p->data = (int*)malloc(sizeof(int));
			memcpy(p->data, data, sizeof(int));
			break;
		}
					
		case 2:{
			p->data = (double*)malloc(sizeof(double));
			memcpy(p->data, data, sizeof(double));
			break;
		}
					
		case 3:{
			p->data = (char*)malloc(sizeof(char));
			memcpy(p->data, data, sizeof(char));
			break;
		}
					
		case 4:{
			p->data = (char*)malloc(sizeof(char)*30);
			memcpy(p->data, data, sizeof(char)*30);	
			break;
		}
					
		default:{
			printf("数据类型有误！\n");
			break;
		} 
	}
	Q->rear->next = p;// 尾结点后入队新节点 
	p->next = NULL;// 尾结点下一个为空
	Q->rear = p;// 再将尾指针指向最后一个结点即新加入的结点 
	Q->length++; 
	return TRUE; 
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	Node *p; // 队头出队， 将头结点指向队头的后一个结点 
	p = Q->front->next;
	Q->front->next = p->next;
	Q->length--;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return;
	Node *p, *q;
	p = Q->front->next;
	while(q) {// 释放所有节点 
		q = p->next;
		free(p);
		p = q;
	}
	Q->rear = Q->front;// 头尾指针指回头结点 
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int type)) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	Node *p;
	p = Q->front->next;
	int count = 1;
	while (p != NULL) {
		(*foo)(p->data, p->type);
		p = p->next;
		count++;
		if (count % 5 == 0)// 每五个换行 
		printf("\n");
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q, int type) {// 根据不同的数据类型输出不同的值 
	if (type == 1)
	printf("%d ", *(int*)q);
	if(type == 3)
	printf("%c ", *(char*)q);
	if(type == 2)
	printf("%.2lf ", *(double*)q);
	if (type == 4)
	printf("%s ", (char*)q);
}
