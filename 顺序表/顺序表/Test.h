#if 0
#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE (100)

typedef int DataType;

typedef struct SeqList{
	DataType arr[MAX_SIZE];
	int size;			//顺序表已存个数；当前可用下标
}	PSeqList;

//初始化 
void InitSeqList(PSeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;		//初始化size
	memset(pSeq->arr, 0, MAX_SIZE*sizeof(DataType));	//	清空容器
}

//删除
void Destroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//尾部插入 
void PushBack(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//特殊情况：顺序表满了
	if (pSeq->size >= MAX_SIZE){
		printf("顺序表已满\n");
		assert(0);
		return;
	}

	//一般情况
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}

//尾部删除 
void PopBack(PSeqList *pSeq)
{
	assert(pSeq);

	//特殊情况：顺序表为空
	if (pSeq->size <= 0){
		printf("顺序表为空\n");
		assert(0);
		return;
	}

	//一般情况
	pSeq->size--;
}

//头部插入 
void PushFront(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//特殊情况：顺序表满了
	if (pSeq->size >= MAX_SIZE){
		printf("顺序表满了\n");
		assert(0);
		return;
	}

	//一般情况
	//数据向后搬移一位
	for (int i = pSeq->size; i > 0; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	//插入
	pSeq->arr[0] = data;
	pSeq->size++;
}

//头部删除 
void PopFront(PSeqList *pSeq){
	assert(pSeq);
	
	//特殊情况：顺序表为空
	if (pSeq->size <= 0){
		printf("顺序表为空\n");
		assert(0);
		return;
	}

	//一般情况
	//数据向前搬移一位
	for (int i = 0; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}

	//删除最后一位
	pSeq->size--;
}

//查找指定元素 
int Find(PSeqList *pSeq, DataType data)
{
	//按顺序遍历查找
	for (int i = 0; i < pSeq->size; i++){
		if (pSeq->arr[i] == data){
			//找到后返回下标
			return i;
		}
	}
	//没找到返回-1代表函数失败
	return -1;
}

//指定位置插入 
void Insert(PSeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况：顺序表满了
	if (pSeq->size >= MAX_SIZE){
		printf("顺序表满了\n");
		assert(0);
		return;
	}

	//一般情况
	//将pos后数据向后搬移一位
	for (int i = pSeq->size; i > pos; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	
	//插入
	pSeq->arr[pos] = data;
	pSeq->size++;
}

//删除指定下标元素 
void Erase(PSeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);

	//特殊情况：顺序表为空
	if (pSeq->size <= 0){
		printf("顺序表为空\n");
		assert(0);
		return;
	}

	//一般情况
	//将pos后数据向前搬移一位
	for (int i = pos; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}
	//删除最后一位数据
	pSeq->size--;
}

//删除遇到的第一个指定元素 
void Remove(PSeqList *pSeq, DataType data)
{
	int pos = Find(pSeq, data);
	if (pos == -1){
		printf("没找到\n");
		return;
	}
	Erase(pSeq, pos);
}
//删除所有的指定元素 
void RemoveAll(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//方法一：遍历删除
	int pos = 0;
	while ((pos = Find(pSeq, data)) != -1){
		Erase(pSeq, pos);
	}
	return;
	//方法二：构造新数组，再将数据搬回
	//方法三：新数组覆盖
}
//返回顺序表的大小 
int Size(PSeqList *pSeq)
{ 
	assert(pSeq);
	return pSeq->size;
}

//判断顺序表是否为空 
int Empty(PSeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0){
		printf("顺序表为空\n");
			return 1;
	}

	printf("顺序表不为空\n");
	return 0;
}
//冒泡排序（从小到大）
void BubbleSort(PSeqList *pSeq)
{
	assert(pSeq);
	int tmp = 0;
	for (int n = 0; n < pSeq->size; n++){
		for (int i = pSeq->size - 1; i > 0; i--){
			if (pSeq->arr[i - 1] > pSeq->arr[i]){
				tmp = pSeq->arr[i];
				pSeq->arr[i] = pSeq->arr[i - 1];
				pSeq->arr[i - 1] = tmp;
			}
		}
	}
}

//选择排序 
void SelectSort(PSeqList *pSeq)
{
	assert(pSeq);
	int tmp = 0;
	int min = 0;
	for (int n = 0; n < pSeq->size; n++){
		for (int i = n; i < pSeq->size; i++){
			if (pSeq->arr[i] < pSeq->arr[min]){
				min = i;
			}
		}
		if (min != n + 1){
			tmp = pSeq->arr[min];
			pSeq->arr[min] = pSeq->arr[n];
			pSeq->arr[n] = tmp;
		}
	}
	return;
}

//选择排序的优化 
void SelectSortOP(PSeqList pSeq);
//二分查找 
int BinarySearch(PSeqList pSeq, DataType data);
//二分查找递归写法 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);

//打印 
void PrintSeqList(PSeqList *pSeq)
{
	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->arr[i]);
	}
}
#endif