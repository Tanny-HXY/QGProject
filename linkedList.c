#include "F:\QGProject1\linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visit(ElemType e) {
	printf("%d ", e); 
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));
    if (*L == NULL) {
    	printf("�����ڴ�ռ�ʧ�ܣ�");
    	return ERROR;
	}
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p, q;// ʹ������ָ�룬һ���ͷŵ�ǰ��㣬һ��������һ�����  
    p = *L;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }// ����һ�����ָ���ʱ����ѭ������ʱpָ�����һ����� 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */

Status InsertList(LNode *p, LNode *q) {  
    q->next = p->next;// �����Ƚ�qָ��p����һ�� 
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) { 
	LinkedList q;
	if (p->next == NULL)// ���p���Ϊ���һ������򷵻ش��� 
	return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p;
    ElemType e;
    p = L->next;
    while (p != NULL) {
    	e = p->data;
        (*visit)(e);
        p = p->next;
    }
    printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LinkedList p = L->next;
	while (p->data != e) {
        p = p->next;
        if (p == NULL)// ���������δ���ָ����ݣ������ݲ����� 
        return ERROR;
    }
    
    return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    // ����ͷ����ƶ��洢��ǰ����ǰһ����㣬����rearָ��ǰ���ĺ�һ�������ɱ�����������򽻻� 
	if ((*L)->next == NULL || (*L)->next->next == NULL)// ������Ϊ�ջ�ֻ��һ���ڵ�ʱ���� 
	return ERROR;  
    LinkedList front, rear;
    front = (*L)->next;
    (*L)->next = NULL;
    rear = NULL;
    while (front != NULL) { 
        rear = front->next;// rear��Զ�ǵ�ǰ���ĺ�һ�� 
        front->next = (*L)->next;// ʹ��ǰ���ָ��ǰһ����� 
        (*L)->next = front;// ͷָ����� 
        front = rear;// ���������ƶ� 
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList fptr, sptr;
    sptr = fptr = L;
    // ���ÿ���ָ�룬���һ������ɻ�������ָ��ؽ�"׷��"��ָ�룬����� 
    while (fptr != NULL && fptr->next != NULL ) {
        sptr = sptr->next;
        fptr = fptr->next->next;
        if (sptr == fptr)
        return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {// ֻ�����������ʱ��Ч��ԭ���벻���� 
    LinkedList front, rear, temp;
    int i = 0;
    front = (*L)->next;
    rear = front->next;
    temp = front;
    (*L)->next = rear;// ͷָ��ָ��ڶ������ 
    if (rear->next == NULL) {// ���ֻ���������ֻ��Ҫ����λ�ü��� 
    	rear->next = front;
    	front->next = NULL;
    	return *L; 
	}
    // temp�洢ż������λ���ܹ���Ϊ�м���������ż���Ļ��� 
    while (front->next != NULL && front != NULL) {
		rear = front->next;
		if(i) {
    	temp->next = rear;
    	temp = front;
        }
    	i++;
    	front->next = rear->next;
    	rear->next = front;
    	front = front->next;
	}
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	// ����ָ�����������ʱ����ָ��ָ���м��� 
    LinkedList fptr, sptr;
    sptr = fptr = *L;
    while (fptr != NULL && fptr->next != NULL) {
        sptr = sptr->next;// ��ָ�� 
        fptr = fptr->next->next;// ��ָ�� 
    }
    return sptr;
}

/**
 *  @name        : LNode* FindNodePosition(LinkedList L, int i)
 *	@description : find the node before the expected node in the linked list
 *	@param		 : L(the head node) i(position)
 *	@return		 : LNode
 *  @notice      : None
 */
LNode* FindNodePosition(LinkedList L, int i) {
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
 *  @name        : LNode* CreateLoopList(void)
 *	@description : Create a looplist to test IsLoopList()
 *	@param		 : void
 *	@return		 : LNode
 *  @notice      : None
 */
LNode* CreateLoopList(void) {
	LinkedList p, q, head;
	head = p = (LinkedList)malloc(sizeof(LNode));
	srand(time(0));
	int i = 0;
	for (i = 0;i < 10; i++) {
		q = (LinkedList)malloc(sizeof(LNode));
		q->data = rand()%100 + 1;
		p->next = q;
		p = q;
	}
	p->next = head;
	return head;
}

/**
 *  @name        : void Init(Linkedist L, int n)
 *	@description : Initialize a list
 *	@param		 : Linkedist L, int n
 *	@return		 : None
 *  @notice      : None
 */
void Init(LinkedList L, int n) {
	LinkedList p, q;
	int i = 0;
	p = L;
	ElemType e;
	while (i < n) {
		scanf("%d", &e);
		q = (LinkedList)malloc(sizeof(LNode));
		q->data = e;
		p->next = q;
		p = q;
		i++;
	}
	p->next = NULL;
}
