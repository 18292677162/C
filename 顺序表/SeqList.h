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
	int size;
} PSeqList;

//初始化 
void SeqListInit(PSeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->arr, 0, MAX_SIZE*sizeof(DataType));
}

//尾部插入 
void SeqListPushBack(PSeqList *pSeq, DataType data)
{
	assert(pSeq);
	
	//特殊情况-满了
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}

	//一般情况
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}

//尾部删除 
void SeqListPopBack(PSeqList *pSeq)
{
	assert(pSeq);

	//特殊情况-空
	if (pSeq->size <= 0){
		printf("空了\n");
		assert(0);
		return;
	}

	//一般情况
	pSeq->size--;
}

//头部插入 
void SeqListPushFront(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//特殊情况-满了
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return 0;
	}

	//一般情况
	//数据整体向后搬移(i表示位置（或数据）)
	for (int i = pSeq->size; i > 0; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	pSeq->arr[0] = data;
	pSeq->size++;
}

//头部删除 
void SeqListPopFront(PSeqList *pSeq)
{
	assert(pSeq);

	//特殊情况-->空了
	if (pSeq->size <= 0){
		printf("空了\n");
		assert(0);
		return;
	}

	//一般情况
	//往前搬 i为位置
	for (int i = 0; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i+1];
	}
	pSeq->size--;
}

//查找指定元素 
int SeqListFind(PSeqList *pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++){
		if (data == pSeq->arr[i]){
			return i;
		}
	}

	return -1;
}

//指定位置插入 
void SeqListInsert(PSeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况-->满了
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}

	//数据搬移 i为位置
	for (int i = pSeq->size; i > pos; i--){
		pSeq->arr[i] = pSeq->arr[i-1];
	}

	pSeq->arr[pos] = data;
	pSeq->size++;
}

//删除指定位置元素 
void SeqListErase(PSeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况->满了
	if (pSeq->size >= MAX_SIZE){
		printf("满了\n");
		assert(0);
		return;
	}

	//删除  i为位置
	for (int i = pos; i < pSeq->size - 1; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}

	pSeq->size--;
}

//删除遇到的第一个指定元素 
void SeqListRemove(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//为空
	if (pSeq->size <= 0){
		printf("空了\n");
		return;
	}

	//通常情况
	int find_pos = SeqListFind(pSeq, data);
	if ( find_pos == -1){
		return;
	}

	SeqListErase(pSeq, find_pos);
}

//删除所有的指定元素 
void SeqListRemoveAll(PSeqList *pSeq, DataType data)
{
	/*
	//数据覆盖，越靠后效率越高
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++) {
		if (data != pSeq->arr[i]) {
			pSeq->arr[j] = pSeq->arr[i];
			j++;
		}
	}
	pSeq->size = j;
	*/
	//重新开辟空间，以空间换时间
	DataType *new_arr = (DataType *)malloc(sizeof(DataType)* pSeq->size);
	int i;
	int j = 0;
	int count = 0;
	for (i = 0; i < pSeq->size; i++){
		if (data != pSeq->arr[i]){
			new_arr[count] = pSeq->arr[i];
			count++;
		}
	}

	//搬回来
	for (i = 0; i < count; i++){
		pSeq->arr[i] = new_arr[j];
		j++;
	}

	pSeq->size = count;

	//释放
	free(new_arr);
}

//返回顺序表的大小 
int SeqListSize(PSeqList *pSeq)
{
	return pSeq->size;
}

//判断顺序表是否为空 
int SeqListIsEmpty(PSeqList *pSeq)
{
	if (pSeq->size <= 0){
		return 1;
	}
	return 0;
}

//冒泡排序 升序
void BubbleSort(PSeqList *pSeq)
{
	assert(pSeq);

}

//选择排序  升序
void SelectSort(PSeqList *pSeq)
{
	assert(pSeq);

}


//选择排序的优化 
void SelectSortOP(PSeqList *pSeq)
{
	assert(pSeq);
}

//二分查找 
int BinarySearch(PSeqList *pSeq, DataType data);
//二分查找递归写法 
int BinarySearch_R(PSeqList *pSeq, int left, int right, DataType d);

//打印 
void SeqListPrint(PSeqList *pSeq)
{
	assert(pSeq);

	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->arr[i]);
	}
	printf("\n");
}