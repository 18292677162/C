#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<windows.h>
int main()
{
	PSeqList seqList;
	SeqListInit(&seqList);

	printf("β��:\n");
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);

	printf("\nͷ��:\n");
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 1);
	SeqListPrint(&seqList);

	printf("\nָ��λ�ò���:\n");
	SeqListInsert(&seqList, 3, 4);
	SeqListPrint(&seqList);

	printf("\nβɾ:\n");
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("\nͷɾ:\n");
	SeqListPopFront(&seqList);
	SeqListPrint(&seqList);

	printf("\nɾ���±�Ϊ2��Ԫ��:\n");
	SeqListErase(&seqList, 2);
	SeqListPrint(&seqList);

	printf("\nɾ����һ��������6:\n");
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);
	printf("\n");
	SeqListRemove(&seqList, 6);
	SeqListPrint(&seqList);

	printf("\nɾ������������6:\n");
	SeqListRemoveAll(&seqList, 6);
	SeqListPrint(&seqList);


	//printf("\nð������:\n");
	//SeqListPushBack(&seqList, 1);
	//SeqListPushBack(&seqList, 8);
	//SeqListPushBack(&seqList, 2);
	//SeqListPushBack(&seqList, 6);
	//SeqListPrint(&seqList);
	////BubbleSort(&seqList);
	//SeqListPrint(&seqList);
	//printf("\nѡ������:\n");
	//SelectSort(&seqList);
	//SeqListPrint(&seqList);
	//SelectSortOP(&seqList);

	printf("\n");
	system("pause");
	return 0;
}