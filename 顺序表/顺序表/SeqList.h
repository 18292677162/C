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

//��ʼ�� 
void SeqListInit(PSeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->arr, 0, MAX_SIZE*sizeof(DataType));
}

//β������ 
void SeqListPushBack(PSeqList *pSeq, DataType data)
{
	assert(pSeq);
	
	//�������-����
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}

	//һ�����
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}

//β��ɾ�� 
void SeqListPopBack(PSeqList *pSeq)
{
	assert(pSeq);

	//�������-��
	if (pSeq->size <= 0){
		printf("����\n");
		assert(0);
		return;
	}

	//һ�����
	pSeq->size--;
}

//ͷ������ 
void SeqListPushFront(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//�������-����
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return 0;
	}

	//һ�����
	//��������������(i��ʾλ�ã������ݣ�)
	for (int i = pSeq->size; i > 0; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	pSeq->arr[0] = data;
	pSeq->size++;
}

//ͷ��ɾ�� 
void SeqListPopFront(PSeqList *pSeq)
{
	assert(pSeq);

	//�������-->����
	if (pSeq->size <= 0){
		printf("����\n");
		assert(0);
		return;
	}

	//һ�����
	//��ǰ�� iΪλ��
	for (int i = 0; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i+1];
	}
	pSeq->size--;
}

//����ָ��Ԫ�� 
int SeqListFind(PSeqList *pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++){
		if (data == pSeq->arr[i]){
			return i;
		}
	}

	return -1;
}

//ָ��λ�ò��� 
void SeqListInsert(PSeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//�������-->����
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}

	//���ݰ��� iΪλ��
	for (int i = pSeq->size; i > pos; i--){
		pSeq->arr[i] = pSeq->arr[i-1];
	}

	pSeq->arr[pos] = data;
	pSeq->size++;
}

//ɾ��ָ��λ��Ԫ�� 
void SeqListErase(PSeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//�������->����
	if (pSeq->size >= MAX_SIZE){
		printf("����\n");
		assert(0);
		return;
	}

	//ɾ��  iΪλ��
	for (int i = pos; i < pSeq->size - 1; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}

	pSeq->size--;
}

//ɾ�������ĵ�һ��ָ��Ԫ�� 
void SeqListRemove(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//Ϊ��
	if (pSeq->size <= 0){
		printf("����\n");
		return;
	}

	//ͨ�����
	int find_pos = SeqListFind(pSeq, data);
	if ( find_pos == -1){
		return;
	}

	SeqListErase(pSeq, find_pos);
}

//ɾ�����е�ָ��Ԫ�� 
void SeqListRemoveAll(PSeqList *pSeq, DataType data)
{
	/*
	//���ݸ��ǣ�Խ����Ч��Խ��
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++) {
		if (data != pSeq->arr[i]) {
			pSeq->arr[j] = pSeq->arr[i];
			j++;
		}
	}
	pSeq->size = j;
	*/
	//���¿��ٿռ䣬�Կռ任ʱ��
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

	//�����
	for (i = 0; i < count; i++){
		pSeq->arr[i] = new_arr[j];
		j++;
	}

	pSeq->size = count;

	//�ͷ�
	free(new_arr);
}

//����˳���Ĵ�С 
int SeqListSize(PSeqList *pSeq)
{
	return pSeq->size;
}

//�ж�˳����Ƿ�Ϊ�� 
int SeqListIsEmpty(PSeqList *pSeq)
{
	if (pSeq->size <= 0){
		return 1;
	}
	return 0;
}

//ð������ ����
void BubbleSort(PSeqList *pSeq)
{
	assert(pSeq);

}

//ѡ������  ����
void SelectSort(PSeqList *pSeq)
{
	assert(pSeq);

}


//ѡ��������Ż� 
void SelectSortOP(PSeqList *pSeq)
{
	assert(pSeq);
}

//���ֲ��� 
int BinarySearch(PSeqList *pSeq, DataType data);
//���ֲ��ҵݹ�д�� 
int BinarySearch_R(PSeqList *pSeq, int left, int right, DataType d);

//��ӡ 
void SeqListPrint(PSeqList *pSeq)
{
	assert(pSeq);

	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->arr[i]);
	}
	printf("\n");
}