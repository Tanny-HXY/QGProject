#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>


// 初始化栈 
Status initLStack(LinkStack *s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!(s->top))
	return ERROR;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}


// 判断栈是否为空 
Status isEmptyLStack(LinkStack *s) {
	if (s->count == 0) // 判断栈是否为空及节点数是否为0 
	return SUCCESS;
	else
	return ERROR;
}


// 得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e) {
	if (isEmptyLStack(s)) // 空栈时没有栈顶元素 
	return ERROR;
	*e = s->top->data;
	return SUCCESS;
}


// 清空栈
Status clearLStack(LinkStack *s) {
	if (s->top->next == NULL)
	return ERROR;
	LinkStackPtr p, q;
	p = s->top;
	while (s->count > 0) {// 双指针递推释放结点清空栈 
		q = p->next;
		free(p);
		s->count--;
		p = q;
	}
	return SUCCESS;
}


// 销毁栈
Status destroyLStack(LinkStack *s) {
	LinkStackPtr p, q;
	p = s->top;
	while (s->count > 0) {// 与清空栈类似不过需要释放top指针 
		q = p->next;
		free(p);
		s->count--;
		p = q;
	}
	free(s->top);
	s->top = NULL;
	return SUCCESS;
}


// 检测栈长度
Status LStackLength(LinkStack *s,int *length) {
	if (isEmptyLStack(s))
	return ERROR;
	*length = s->count;
	return SUCCESS;
}


// 入栈
Status pushLStack(LinkStack *s,ElemType data) {
	LinkStackPtr S;
	S = (LinkStackPtr)malloc(sizeof(StackNode));
	S->next = s->top;
	S->data = data;
	s->top = S;
	s->count++;
	return SUCCESS;
}


// 出栈
Status popLStack(LinkStack *s,ElemType *data) {
	if (isEmptyLStack(s))
	return ERROR;
	LinkStackPtr S;
	*data = s->top->data;
	S = s->top;
	s->top = S->next;
	free(S);
	s->count--;
	return SUCCESS;
}


