#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "LQueue.h"
#include "binary_sort_tree.h"


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_Status BST_init(BinarySortTreePtr T) {
	T->root = NULL;
	return succeed;
}


/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BST_Status BST_insert(BinarySortTreePtr T, ElemType data) {
	// �����ڵ㻹δ��ֵ���ȸ�ֵ���ڵ� 
	if (T->root == NULL) {
		NodePtr root = (NodePtr)malloc(sizeof(BSTNode));
		T->root =root;
		root->value = data;
		root->left = NULL;
		root->right = NULL;
		return succeed;
	}
	// ��������Ϊ���в����ڵ����� 
	if (!BST_search(T, data)) {
		NodePtr temp = T->root;
		// ����һ���½ڵ� 
		NodePtr p = (NodePtr)malloc(sizeof(BSTNode));
		p->value = data;
		p->left = NULL;
		p->right = NULL;
		// ��������λ�� 
		while (temp != NULL) {
		// �������ֵ�ȵ�ǰ�ڵ�ֵ����ָ��ָ���Һ��� 
			if (data > temp->value) {
				if (temp->right == NULL)
				break;
				else {
					temp = temp->right;
					continue;
				}
			}
		// �������ֵ�ȵ�ǰ�ڵ�ֵС��ָ��ָ������
			if (data < temp->value) {
				if (temp->left== NULL)
				break;
				else {
					temp = temp->left;
					continue;
				}
			} 
		}
		if (data > temp->value) {
			temp->right = p;
		}
		else {
			temp->left = p;
		}
	}
	return succeed;

}


/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BST_Status BST_delete(BinarySortTreePtr T, ElemType data) {
	// ���������ݲ������򱨴� 
	if (T->root == NULL || !BST_search(T, data))
	return failed;
	NodePtr temp = T->root;
	NodePtr p, q;
	// ���ұ�ɾ�����ݵĽ�� 
	while (temp != NULL) {
		if (data == temp->value)
		break;
		if (data > temp->value) {
			temp = temp->right;
			continue;
		}
		if (data < temp->value) {
			temp = temp->left;
			continue;
		}
	}
	// ����ɾ���û����������ֱ��ɾ��
	if (temp->left == NULL && temp->right == NULL) {
		// ����ɾ���Ϊ����� 
		if (temp == T->root) {
			free(T->root);
			T->root = NULL;
		}
		// ����ɾ���ΪҶ�ڵ�
		else {
			p = FindParent(T->root, temp);
			if (p->left == temp)
			p->left = NULL;
			else
			p->right = NULL;
			free(temp);	
		}
	}
	// ����ɾ���ֻ���ң��������������ң���������������������
	else if (temp->left == NULL && temp->right != NULL) {
		p = temp;
		q = p->right;
		p->value = q->value; 
		p->right = q->right; // �Ͽ���� 
		p->left = q->left;
		free(q); // �ͷŽ��
		q = NULL; 
	}
	else if (temp->right == NULL && temp->left != NULL) {
		p = temp;
		q = p->left; 
		p->value = q->value;
		p->left = q->left;
		p->right = q->right;
		free(q);
		q = NULL; 
	}
	// ����ɾ���������������������������������������ҽ�����������ɾ������� 
	else { 
		p = temp;
		// ��ָ���ɾ������� 
		temp = temp->left;
		// ���������������ҽ�� 
		while (temp->right != NULL) {
			temp = temp->right;
		}
		p->value = temp->value;
		// ������������������ڶ������һ�� 
		if (temp->left != NULL) {
			p = temp;
			q = q->left;
			p->value = q->value;
			p->left = q->left;
			p->right = q->right;
			free(q);
			q = NULL; 
		}
		// ��Ϊ��ʱ�Ѿ������ҽ�㣬�ʲ����ܴ���������������û�������������������� 
		else {
			free(temp);
			temp = NULL;
		}
	}
	return succeed; 
}


/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BST_Status BST_search(BinarySortTreePtr T, ElemType data) {
	if (T->root == NULL)
	return failed;
	NodePtr temp = T->root;
	while (temp != NULL) {
		if (temp->value == data)
		return succeed;
		// �����ѯֵ�ȵ�ǰ�ڵ�ֵ����ָ��ָ���Һ��� 
		if (data > temp->value) {
			temp = temp->right;
			continue;
		}
		// �����ѯֵ�ȵ�ǰ�ڵ�ֵС��ָ��ָ������
		if (data < temp->value) {
			temp = temp->left;
			continue;
		} 
	}
	return failed;
}


/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	else {
		LinkStack s;
		initLStack(&s);// ��ʼ��ջ 
		NodePtr root = T->root;
		pushLStack(&s, root);
		NodePtr temp;
		while (!isEmptyLStack(&s)) {
			// ���ں����г�ջ���ʴ˴���ȡջ��Ԫ���൱�ڵ�����ÿ��ջһ������ջ������������ 
			getTopLStack(&s, &temp);
			popLStack(&s, &temp);
			visit(temp);
			// ����ջ���Ƚ���������ԣ������Ƚ�ջ�Һ����ٽ�ջ���� 
			if (temp->right != NULL)
			pushLStack(&s, temp->right);
			if (temp->left != NULL)
			pushLStack(&s, temp->left);
		}
		// ����ջ 
		destroyLStack(&s);
		temp = NULL;
		return succeed; 
	}
}


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	preorder(T->root, visit);
	return succeed;
}


/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	else {
		LinkStack s;
		// ��ʼ��ջ 
		initLStack(&s); 
		NodePtr root = T->root; 
		NodePtr temp = root;
		// �������ÿ�����ҵ���ǰ���ڵ������ĺ��� 
		while (temp != NULL || !isEmptyLStack(&s)) {
			while (temp != NULL) {
				pushLStack(&s, temp);
				temp = temp->left;
			}
			getTopLStack(&s, &temp);
			popLStack(&s, &temp);
			visit(temp);
			// ��ǰ���ڵ����������Һ��� 
			temp = temp->right;
		}
		// ����ջ  
		destroyLStack(&s);
		temp = NULL;
		return succeed; 
	}
}


/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	NodePtr root = T->root;
	inorder(root, visit);
	return succeed;
}


/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	else {
		LinkStack s1, s2;
		// ��ʼ��ջ 
		initLStack(&s1);
		initLStack(&s2); 
		NodePtr root = T->root;
		pushLStack(&s1, root); // ���ڵ���ջ 
		NodePtr temp ;
		/* ��������߼�����Ϊ������->�Һ���->��������ջ�����ԣ�����˳��Ϊ����->�Һ���->����
		����ʹ������ջ����ջ����һ��ջ���˳�򻥻��������Һ��Ӹ� */ 
		while (!isEmptyLStack(&s1)) {
			getTopLStack(&s1, &temp);
			pushLStack(&s2, temp);
			popLStack(&s1, &temp);
			if (temp->left != NULL)
			pushLStack(&s1, temp->left);
			if (temp->right != NULL)
			pushLStack(&s1, temp->right); 
		}
		// ���
		while (!isEmptyLStack(&s2)) {
			getTopLStack(&s2, &temp);
			visit(temp);
			popLStack(&s2, &temp);
		}
		temp = NULL;
		// ����ջ 
		destroyLStack(&s1);
		destroyLStack(&s2);  
		return succeed; 
	}
}


/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	NodePtr root = T->root;
	postorder(root, visit);
	return succeed;
}


/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr)) {
	if (T->root == NULL)
	return failed;
	else {
		NodePtr temp = T->root;
		// ��ʼ������ 
		LQueue Q;
		InitLQueue(&Q);
		EnLQueue(&Q, temp);
		while (!IsEmptyLQueue(&Q)) {
			GetHeadLQueue(&Q, &temp);
			(*visit)(temp);
			if (temp->left != NULL) {
				EnLQueue(&Q, temp->left);
			}
			if (temp->right != NULL) {
				EnLQueue(&Q, temp->right);
			}
			DeLQueue(&Q); 
		}
	return succeed; 
	}
}


void preorder(NodePtr root, void (*visit)(NodePtr)) {
	if (root == NULL)
	return;
	(*visit)(root);
	preorder(root->left, visit);
	preorder(root->right, visit);
}


void inorder(NodePtr root, void (*visit)(NodePtr)) {
	if (root == NULL)
	return;
	preorder(root->left, visit);
	(*visit)(root);
	preorder(root->right, visit);
}


void postorder(NodePtr root, void (*visit)(NodePtr)) {
	if (root == NULL)
	return;
	preorder(root->left, visit);
	preorder(root->right, visit);
	(*visit)(root);
}


void visit(NodePtr root) {
	printf("%d ", root->value);
}


NodePtr FindParent(NodePtr p, NodePtr child) {
	if (p == NULL) {
		return NULL;
	}
	if (p->left == child || p->right == child)
	return p;
	// ���������еݹ���� 
	else if (p->left != NULL)
	FindParent(p->left, child);
	// �Һ������еݹ���� 
	else if (p->right != NULL)
	FindParent(p->right, child);
} 
