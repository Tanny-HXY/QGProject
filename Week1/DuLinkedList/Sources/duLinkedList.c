#include "F:\QGProject2\duLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void visit(ElemType e) {
	printf("%d ", e);
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc((sizeof(DuLNode)));
	(*L)->next = *L;// ��ͷ��ǰ�����̶�ָ���Լ� 
	(*L)->prior = *L;
	if (*L == NULL)
	return ERROR;
	
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p, q;
	p = (*L)->next;// �뵥����һģһ���������ͷ��ڴ� 
	while(p != *L) {
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	q->prior = p->prior;// q��ǰ��ָ��p�ĺ�� 
	p->prior->next = q;// p��ǰ���ĺ��ָ��q 
	q->next = p;
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLinkedList q;
	q = p->next;// qΪҪɾ���Ľ�� 
	*e = q->data;// ȡ��ɾ������е����� 
	p->next = q->next;// ʹp�ĺ��ָ��q�ĺ�� 
	q->next->prior = p;// ʹq�ĺ�̵�ǰ��ָ��p 
	free(q);// ��ʱq��ǰ�������Ѿ����ӣ��ͷŽ��q 
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None 
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList judge = L->next;
	ElemType e;
	while (judge != L) {// ����һȦ������������ 
		e = judge->data;
		(*visit)(e);
		judge = judge->next;
	}
	printf("\n");
}

/**
 *  @name        : void Init_DuL(DuLinkedList L, int count)
 *	@description : Create a DuList
 *	@param		 : L(the head node), int count
 *	@return		 : None 
 *  @notice      : None
 */
void Init_DuL(DuLinkedList L, int count) {
	DuLinkedList p, q;
	p = L;
	int i = 0;
	ElemType e;
	while (i < count) {
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		p->next = q;// ǰһ�����ĺ��ָ���½��q 
		q->prior = p;// �½ڵ�q��ǰ��ָ��p 
		p = q;// �ƶ�p 
		scanf("%d", &e);
		q->data = e;
		i++;
	}
	p->next = L;//���ʹ���һ���ڵ�ĺ��ָ��ͷ��� 
	L->prior = p;//ʹͷ���ǰ��ָ�����һ����� ���һ����״˫������ 
}

/**
 *  @name        : LNode* FindDuLNodePosition(LinkedList L, int i)
 *	@description : find the node before the expected node in the linked list
 *	@param		 : L(the head node) i(position)
 *	@return		 : DuLNode
 *  @notice      : None
 */
DuLNode* FindDuLNodePosition(DuLinkedList L, int i) {
	int n = 1;
	while(n < i) {
		n++;
		L = L->next;
	}
	if (L!=NULL)
	return L;
	if (L == NULL)
	return NULL;
}

/**
 *  @name        : int GetDuListLength(DuLinkedList L)
 *	@description : Get the DuList Length 
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int GetDuListLength(DuLinkedList L) {
	DuLinkedList p = L->next;
	int n = 0;
	if (L->next == L)
	return 0;
	
	while (p != L) {
		n++;
		p = p->next;
	}
	return n; 
}
