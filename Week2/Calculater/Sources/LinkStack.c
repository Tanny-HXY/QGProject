#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>


// ��ʼ��ջ 
Status initLStack(LinkStack *s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!(s->top))
	return ERROR;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}


// �ж�ջ�Ƿ�Ϊ�� 
Status isEmptyLStack(LinkStack *s) {
	if (s->count == 0) // �ж�ջ�Ƿ�Ϊ�ռ��ڵ����Ƿ�Ϊ0 
	return SUCCESS;
	else
	return ERROR;
}


// �õ�ջ��Ԫ��
int getTopLStack(LinkStack *s) {
	if (isEmptyLStack(s)) // ��ջʱû��ջ��Ԫ�� 
	return ERROR;
	return s->top->data;
}


// ���ջ
Status clearLStack(LinkStack *s) {
	if (s->top->next == NULL)
	return ERROR;
	LinkStackPtr p, q;
	p = s->top;
	while (s->count > 0) {// ˫ָ������ͷŽ�����ջ 
		q = p->next;
		free(p);
		s->count--;
		p = q;
	}
	return SUCCESS;
}


// ����ջ
Status destroyLStack(LinkStack *s) {
	LinkStackPtr p, q;
	p = s->top;
	while (s->count > 0) {// �����ջ���Ʋ�����Ҫ�ͷ�topָ�� 
		q = p->next;
		free(p);
		s->count--;
		p = q;
	}
	free(s->top);
	s->top = NULL;
	return SUCCESS;
}


// ���ջ����
Status LStackLength(LinkStack *s,int *length) {
	if (isEmptyLStack(s))
	return ERROR;
	*length = s->count;
	return SUCCESS;
}


// ��ջ
Status pushLStack(LinkStack *s,ElemType data) {
	LinkStackPtr S;
	S = (LinkStackPtr)malloc(sizeof(StackNode));
	S->next = s->top;
	S->data = data;
	s->top = S;
	s->count++;
	return SUCCESS;
}


// ��ջ
int popLStack(LinkStack *s) {
	if (isEmptyLStack(s))
	return ERROR;
	int e;
	LinkStackPtr S;
	S = s->top;
	e = S->data;
	s->top = S->next;
	free(S);
	s->count--;
	return e;
}


