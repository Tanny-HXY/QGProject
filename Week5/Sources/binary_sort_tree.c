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
	// 若根节点还未赋值则先赋值根节点 
	if (T->root == NULL) {
		NodePtr root = (NodePtr)malloc(sizeof(BSTNode));
		T->root =root;
		root->value = data;
		root->left = NULL;
		root->right = NULL;
		return succeed;
	}
	// 插入数据为树中不存在的数据 
	if (!BST_search(T, data)) {
		NodePtr temp = T->root;
		// 生成一个新节点 
		NodePtr p = (NodePtr)malloc(sizeof(BSTNode));
		p->value = data;
		p->left = NULL;
		p->right = NULL;
		// 搜索插入位置 
		while (temp != NULL) {
		// 如果插入值比当前节点值大则将指针指向右孩子 
			if (data > temp->value) {
				if (temp->right == NULL)
				break;
				else {
					temp = temp->right;
					continue;
				}
			}
		// 如果插入值比当前节点值小则将指针指向左孩子
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
	// 空树或数据不存在则报错 
	if (T->root == NULL || !BST_search(T, data))
	return failed;
	NodePtr temp = T->root;
	NodePtr p, q;
	// 查找被删除数据的结点 
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
	// 若待删结点没有子树，则直接删除
	if (temp->left == NULL && temp->right == NULL) {
		// 若待删结点为根结点 
		if (temp == T->root) {
			free(T->root);
			T->root = NULL;
		}
		// 若待删结点为叶节点
		else {
			p = FindParent(T->root, temp);
			if (p->left == temp)
			p->left = NULL;
			else
			p->right = NULL;
			free(temp);	
		}
	}
	// 若待删结点只有右（左）子树，则用右（左）子树数据替代结点数据
	else if (temp->left == NULL && temp->right != NULL) {
		p = temp;
		q = p->right;
		p->value = q->value; 
		p->right = q->right; // 断开结点 
		p->left = q->left;
		free(q); // 释放结点
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
	// 若待删结点既有右子树又有左子树，则用左子树的最右结点数据替代待删结点数据 
	else { 
		p = temp;
		// 先指向待删结点左孩子 
		temp = temp->left;
		// 查找左子树的最右结点 
		while (temp->right != NULL) {
			temp = temp->right;
		}
		p->value = temp->value;
		// 若还有左子树，则与第二种情况一样 
		if (temp->left != NULL) {
			p = temp;
			q = q->left;
			p->value = q->value;
			p->left = q->left;
			p->right = q->right;
			free(q);
			q = NULL; 
		}
		// 因为此时已经是最右结点，故不可能存在右子树，所以没有左子树即不存在子树 
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
		// 如果查询值比当前节点值大则将指针指向右孩子 
		if (data > temp->value) {
			temp = temp->right;
			continue;
		}
		// 如果查询值比当前节点值小则将指针指向左孩子
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
		initLStack(&s);// 初始化栈 
		NodePtr root = T->root;
		pushLStack(&s, root);
		NodePtr temp;
		while (!isEmptyLStack(&s)) {
			// 由于后面有出栈，故此处获取栈顶元素相当于迭代，每出栈一个，入栈他的两个孩子 
			getTopLStack(&s, &temp);
			popLStack(&s, &temp);
			visit(temp);
			// 由于栈的先进后出的特性，我们先进栈右孩子再进栈左孩子 
			if (temp->right != NULL)
			pushLStack(&s, temp->right);
			if (temp->left != NULL)
			pushLStack(&s, temp->left);
		}
		// 销毁栈 
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
		// 初始化栈 
		initLStack(&s); 
		NodePtr root = T->root; 
		NodePtr temp = root;
		// 中序遍历每次先找到当前根节点的最左的孩子 
		while (temp != NULL || !isEmptyLStack(&s)) {
			while (temp != NULL) {
				pushLStack(&s, temp);
				temp = temp->left;
			}
			getTopLStack(&s, &temp);
			popLStack(&s, &temp);
			visit(temp);
			// 当前根节点输出后，输出右孩子 
			temp = temp->right;
		}
		// 销毁栈  
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
		// 初始化栈 
		initLStack(&s1);
		initLStack(&s2); 
		NodePtr root = T->root;
		pushLStack(&s1, root); // 根节点入栈 
		NodePtr temp ;
		/* 后序遍历逻辑抽象为：左孩子->右孩子->根，根据栈的特性，代码顺序为：根->右孩子->左孩子
		我们使用两个栈，出栈至另一个栈完成顺序互换即左孩子右孩子根 */ 
		while (!isEmptyLStack(&s1)) {
			getTopLStack(&s1, &temp);
			pushLStack(&s2, temp);
			popLStack(&s1, &temp);
			if (temp->left != NULL)
			pushLStack(&s1, temp->left);
			if (temp->right != NULL)
			pushLStack(&s1, temp->right); 
		}
		// 输出
		while (!isEmptyLStack(&s2)) {
			getTopLStack(&s2, &temp);
			visit(temp);
			popLStack(&s2, &temp);
		}
		temp = NULL;
		// 销毁栈 
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
		// 初始化队列 
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
	// 左子树族中递归查找 
	else if (p->left != NULL)
	FindParent(p->left, child);
	// 右孩子族中递归查找 
	else if (p->right != NULL)
	FindParent(p->right, child);
} 
