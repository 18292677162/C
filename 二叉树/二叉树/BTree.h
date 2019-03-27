#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/* Binary Tree */

typedef int TDataType;

typedef struct BTreeNode {
	TDataType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;

BTreeNode *CreateNode(TDataType data)
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));

	node->data = data;
	node->left = node->right = NULL;

	return node;
}

//返回值
//1. 数的根节点
//2. 创建树使用的字符个数
BTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize)
{
	if (size <= 0){
		*pUsedSize = 0;
		return NULL;
	}

	int leftUse, rightUse;
	int rootValue = preOrder[0];
	if (rootValue == -1) {
		*pUsedSize = 1;
		return NULL;
	}

	BTreeNode *root = CreateNode(rootValue);

	root->left = CreateTree(preOrder + 1, size - 1, &leftUse);
	root->right = CreateTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);

	//汇报使用情况
	*pUsedSize = 1 + leftUse + rightUse;

	return root;
}

//前序/中序/后序
void PreOrder(BTreeNode *root)
{
	if (NULL == root){
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTreeNode *root)
{
	if (NULL == root){
		return;
	}
	InOrder(root->left);
	printf("%d ", root);
	InOrder(root->right);
}

void PostOrder(BTreeNode *root)
{
	if (NULL == root){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// 求树的结点个数
// 1. 用子问题的方式求解
// 2. 用遍历求解

// 利用后序遍历的方式计数结点个数
int GetSize1(BTreeNode *root)
{
	if (NULL == root){
		return 0;
	}

	int left = GetSize1(root->left);
	int right = GetSize1(root->right);

	return left + right;
}

int count = 0;
void GetSize2(BTreeNode *root)
{
	if (NULL == root){
		return;
	}

	GetSize2(root->left);
	GetSize2(root->right);
	count++;
}

// 获取二叉树中叶子结点的个数 
int GetLeafSize(BTreeNode *root)
{
	//空树
	if (NULL == root){
		return 0;
	}
	else{
		//度为零的树-叶子节点
		if (NULL == root->left&&NULL == root->right){
			return 1;
		}
		else{
			//不是空树也不是度为零的树
			return GetLeafSize(root->left) + GetLeafSize(root->right);
		}
	}
}

// 销毁 
void DestroyBinTree(BTNode** pRoot);

// 前序非递归遍历 
void PreOrderNor(BTNode* pRoot);

// 中序非递归遍历 
void InOrderNor(BTNode* pRoot);

// 后续非递归遍历 
void PostOrderNor(BTNode* pRoot);

// 层序遍历 
void LevelOrder(BTNode* pRoot);

// 获取二叉树中第K层结点的个数 
int GetLevelKSize(BTreeNode *root, int k)
{
	assert(k >= 1);
	if (NULL == root){
		//空树
		return 0;
	}

	if (1 == k){
		//第一层一个节点，返回1
		return 1;
	}

	//也就是子树的k-1层
	int left = GetLevelKSize(root->left, k - 1);
	int right = GetLevelKSize(root->right, k - 1);

	return left + right;
}


// 获取二叉树的高度 
int Height(BTNode* pRoot);

// 检测一个节点是否在二叉树中 
int IsBTNodeInBinTree(BTNode* pRoot, BTNode* pNode);

// 获取二叉树中某个结点的双亲 
BTNode* GetBTNodeParent(BTNode* pRoot, BTNode* pNode);

// 二叉树的镜像递归&非递归 
void MirrorBinTreeNor(BTNode* pRoot);
void MirrorBinTree(BTNode* pRoot);

// 检测一棵二叉树是否为完全二叉树 
int IsCompleteBinTree(BTNode* pRoot);

// 获取某个结点的左孩子 
BTNode* LeftChild(BTNode* pNode);

// 获取某个结点的右孩子 
BTNode* RightChild(BTNode* pNode);

void BtreeTest()
{
	;
}

