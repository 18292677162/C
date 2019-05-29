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

//����ֵ
//1. ���ĸ��ڵ�
//2. ������ʹ�õ��ַ�����
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

	//�㱨ʹ�����
	*pUsedSize = 1 + leftUse + rightUse;

	return root;
}

//ǰ��/����/����
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

// �����Ľ�����
// 1. ��������ķ�ʽ���
// 2. �ñ������

// ���ú�������ķ�ʽ����������
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

// ��ȡ��������Ҷ�ӽ��ĸ��� 
int GetLeafSize(BTreeNode *root)
{
	//����
	if (NULL == root){
		return 0;
	}
	else{
		//��Ϊ�����-Ҷ�ӽڵ�
		if (NULL == root->left&&NULL == root->right){
			return 1;
		}
		else{
			//���ǿ���Ҳ���Ƕ�Ϊ�����
			return GetLeafSize(root->left) + GetLeafSize(root->right);
		}
	}
}

// ���� 
void DestroyBinTree(BTNode** pRoot);

// ǰ��ǵݹ���� 
void PreOrderNor(BTNode* pRoot);

// ����ǵݹ���� 
void InOrderNor(BTNode* pRoot);

// �����ǵݹ���� 
void PostOrderNor(BTNode* pRoot);

// ������� 
void LevelOrder(BTNode* pRoot);

// ��ȡ�������е�K����ĸ��� 
int GetLevelKSize(BTreeNode *root, int k)
{
	assert(k >= 1);
	if (NULL == root){
		//����
		return 0;
	}

	if (1 == k){
		//��һ��һ���ڵ㣬����1
		return 1;
	}

	//Ҳ����������k-1��
	int left = GetLevelKSize(root->left, k - 1);
	int right = GetLevelKSize(root->right, k - 1);

	return left + right;
}


// ��ȡ�������ĸ߶� 
int Height(BTNode* pRoot);

// ���һ���ڵ��Ƿ��ڶ������� 
int IsBTNodeInBinTree(BTNode* pRoot, BTNode* pNode);

// ��ȡ��������ĳ������˫�� 
BTNode* GetBTNodeParent(BTNode* pRoot, BTNode* pNode);

// �������ľ���ݹ�&�ǵݹ� 
void MirrorBinTreeNor(BTNode* pRoot);
void MirrorBinTree(BTNode* pRoot);

// ���һ�ö������Ƿ�Ϊ��ȫ������ 
int IsCompleteBinTree(BTNode* pRoot);

// ��ȡĳ���������� 
BTNode* LeftChild(BTNode* pNode);

// ��ȡĳ�������Һ��� 
BTNode* RightChild(BTNode* pNode);

void BtreeTest()
{
	;
}

