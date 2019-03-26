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

BTreeNode *CreateNode(int data)
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

//����ֵ
//1. ���ĸ��ڵ�
//2. ������ʹ�õ��ַ�����