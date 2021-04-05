#include <stdio.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes) {
	s->size = sizes;
	s->top = -1;// 在没有数据入栈时top为-1，每入栈一个+1，即一直指向栈顶 
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));// 开辟一个空间，即数组 
	return SUCCESS; 
}


Status isEmptyStack(SqStack *s) {
	if (s->top == -1)
	return SUCCESS;
	else
	return ERROR;
}


Status getTopStack(SqStack *s,ElemType *e) {
	if (isEmptyStack(s))
	return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}


Status clearStack(SqStack *s) {
	if (isEmptyStack(s))
	return ERROR;
<<<<<<< HEAD
	s->size = s->top + s->size + 1;// 将栈的空间恢复至最大 
=======
	s->size = size;// 将栈的空间恢复至最大 
>>>>>>> d9faf681d231405c6aafd7e1436ba74aea48a39b
	s->top = -1;
	return SUCCESS;
}


Status destroyStack(SqStack *s) {
	free(s->elem);// 释放空间，销毁栈 
	return SUCCESS;
}


Status stackLength(SqStack *s,int *length) {
	if (isEmptyStack(s))
	return ERROR;
	*length = s->top+1;
	return SUCCESS;
}


Status pushStack(SqStack *s,ElemType data) {
	if (!s->size)
	return ERROR;
	s->top++;// 栈顶指针指向下一个位置 
	s->elem[s->top] = data;// 栈顶赋值 
	s->size--;// 栈的空间-1 
	return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data) {
	if (isEmptyStack(s))
	return ERROR;
	*data = s->elem[s->top];// 取出栈顶元素 
	s->top--;// 栈顶指针下移 
	s->size++;// 栈的空间+1 
	return SUCCESS;
}
