#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = (LQNode*)malloc(sizeof(LQNode));
	Q->rear = Q->front;
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	LQNode *p, *q;
	p = Q->front->next;
	while (q != NULL) { // ѭ���������ͷ� 
		q = p->next;
		free(p);
		p = q;
	}
	free(Q->front); // �ͷ�ͷָ�� 
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
LQStatus IsEmptyLQueue(const LQueue *Q) {
	if (Q->length == 0)
	return TRUE;
	else
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
LQStatus GetHeadLQueue(LQueue *Q, NodePtr* data) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	*data = Q->front->next->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
LQStatus EnLQueue(LQueue *Q, NodePtr data) {
	LQNode *p = (LQNode*)malloc(sizeof(LQNode));
	p->data = data;
	Q->rear->next = p;// β��������½ڵ� 
	p->next = NULL;// β�����һ��Ϊ��
	Q->rear = p;// �ٽ�βָ��ָ�����һ����㼴�¼���Ľ�� 
	Q->length++;
	return TRUE; 
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
LQStatus DeLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	LQNode *p; // ��ͷ���ӣ� ��ͷ���ָ���ͷ�ĺ�һ����� 
	p = Q->front->next;
	Q->front->next = p->next;
	Q->length--;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return;
	LQNode *p, *q;
	p = Q->front->next;
	while(q) {// �ͷ����нڵ� 
		q = p->next;
		free(p);
		p = q;
	}
	Q->rear = Q->front;// ͷβָ��ָ��ͷ��� 
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
//LQStatus TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
//	if (IsEmptyLQueue(Q))
//	return FALSE;
//	LQNode *p;
//	p = Q->front->next;
//	int count = 1;
//	while (p != NULL) {
//		(*foo)(p->data);
//		p = p->next;
//		count++;
//		if (count % 5 == 0)// ÿ������� 
//		printf("\n");
//	}
//	return TRUE;
//}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q, int type) {// ���ݲ�ͬ���������������ͬ��ֵ 
	if (type == 1)
	printf("%d ", *(int*)q);
	if(type == 3)
	printf("%c ", *(char*)q);
	if(type == 2)
	printf("%.2lf ", *(double*)q);
	if (type == 4)
	printf("%s ", (char*)q);
}
