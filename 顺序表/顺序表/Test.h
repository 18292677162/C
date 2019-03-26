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
	int size;			//˳����Ѵ��������ǰ�����±�
}	PSeqList;

//��ʼ�� 
void InitSeqList(PSeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;		//��ʼ��size
	memset(pSeq->arr, 0, MAX_SIZE*sizeof(DataType));	//	�������
}

//ɾ��
void Destroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//β������ 
void PushBack(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//���������˳�������
	if (pSeq->size >= MAX_SIZE){
		printf("˳�������\n");
		assert(0);
		return;
	}

	//һ�����
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}

//β��ɾ�� 
void PopBack(PSeqList *pSeq)
{
	assert(pSeq);

	//���������˳���Ϊ��
	if (pSeq->size <= 0){
		printf("˳���Ϊ��\n");
		assert(0);
		return;
	}

	//һ�����
	pSeq->size--;
}

//ͷ������ 
void PushFront(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//���������˳�������
	if (pSeq->size >= MAX_SIZE){
		printf("˳�������\n");
		assert(0);
		return;
	}

	//һ�����
	//����������һλ
	for (int i = pSeq->size; i > 0; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	//����
	pSeq->arr[0] = data;
	pSeq->size++;
}

//ͷ��ɾ�� 
void PopFront(PSeqList *pSeq){
	assert(pSeq);
	
	//���������˳���Ϊ��
	if (pSeq->size <= 0){
		printf("˳���Ϊ��\n");
		assert(0);
		return;
	}

	//һ�����
	//������ǰ����һλ
	for (int i = 0; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}

	//ɾ�����һλ
	pSeq->size--;
}

//����ָ��Ԫ�� 
int Find(PSeqList *pSeq, DataType data)
{
	//��˳���������
	for (int i = 0; i < pSeq->size; i++){
		if (pSeq->arr[i] == data){
			//�ҵ��󷵻��±�
			return i;
		}
	}
	//û�ҵ�����-1������ʧ��
	return -1;
}

//ָ��λ�ò��� 
void Insert(PSeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//���������˳�������
	if (pSeq->size >= MAX_SIZE){
		printf("˳�������\n");
		assert(0);
		return;
	}

	//һ�����
	//��pos������������һλ
	for (int i = pSeq->size; i > pos; i--){
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	
	//����
	pSeq->arr[pos] = data;
	pSeq->size++;
}

//ɾ��ָ���±�Ԫ�� 
void Erase(PSeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);

	//���������˳���Ϊ��
	if (pSeq->size <= 0){
		printf("˳���Ϊ��\n");
		assert(0);
		return;
	}

	//һ�����
	//��pos��������ǰ����һλ
	for (int i = pos; i < pSeq->size; i++){
		pSeq->arr[i] = pSeq->arr[i + 1];
	}
	//ɾ�����һλ����
	pSeq->size--;
}

//ɾ�������ĵ�һ��ָ��Ԫ�� 
void Remove(PSeqList *pSeq, DataType data)
{
	int pos = Find(pSeq, data);
	if (pos == -1){
		printf("û�ҵ�\n");
		return;
	}
	Erase(pSeq, pos);
}
//ɾ�����е�ָ��Ԫ�� 
void RemoveAll(PSeqList *pSeq, DataType data)
{
	assert(pSeq);

	//����һ������ɾ��
	int pos = 0;
	while ((pos = Find(pSeq, data)) != -1){
		Erase(pSeq, pos);
	}
	return;
	//�����������������飬�ٽ����ݰ��
	//�������������鸲��
}
//����˳���Ĵ�С 
int Size(PSeqList *pSeq)
{ 
	assert(pSeq);
	return pSeq->size;
}

//�ж�˳����Ƿ�Ϊ�� 
int Empty(PSeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0){
		printf("˳���Ϊ��\n");
			return 1;
	}

	printf("˳���Ϊ��\n");
	return 0;
}
//ð�����򣨴�С����
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

//ѡ������ 
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

//ѡ��������Ż� 
void SelectSortOP(PSeqList pSeq);
//���ֲ��� 
int BinarySearch(PSeqList pSeq, DataType data);
//���ֲ��ҵݹ�д�� 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);

//��ӡ 
void PrintSeqList(PSeqList *pSeq)
{
	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->arr[i]);
	}
}
#endif