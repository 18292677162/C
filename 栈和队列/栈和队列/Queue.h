#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

typedef struct QNode{
	struct QNode *next;
	QDataType data;
}	QNode;

typedef struct Queue{
	QNode *front;
	QNode *rear;
}	Queue;

// ��ʼ��/����
// ���루��β���룩/ɾ������ͷɾ����/�鿴��������
//�����β��NULL���Ƕ��е�β�������
//Ϊʲô����βɾͷ�壿��Ϊ��������Ϊ����+next��nextΪβ���ʶ�ͷ�ȳ�Ҳ��������ͷ�ȳ�

void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

void QueueDestroy(Queue *pQueue)
{
	QNode *cur, *next;
	for (cur = pQueue->front; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
}

static QNode *CreateNode(QDataType data)
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node);

	node->data = data;
	node->next = NULL;

	return node;
}

// ���루β�壩
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = CreateNode(data);

	//����Ϊ��
	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// ɾ����ͷɾ��
void QueuePop(Queue *pQueue)
{
	
	assert(pQueue != NULL);  //�����ַ��Ϊ��
	assert(pQueue->front != NULL);  //���в���Ϊ��

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);
	
	//����ֻ��һ�����
	if (pQueue->front->next == NULL){
		pQueue->rear = NULL;
	}
}

// �鿴��������
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);

	return pQueue->front->data;
}

// �Ƿ�Ϊ��
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

// �������ݸ���
int QueueSize(const Queue *pQueue)
{
	int size = 0;
	for (QNode *cur = pQueue->front; cur != NULL; cur = cur->next){
		size++;
	}
	return size;
}

void QueuePrint(const Queue *pQueue)
{
	printf("float ");
	for (QNode *cur = pQueue->front; cur != NULL; cur = cur->next){
		printf("%d ", cur->data);
	}
	printf("rear ");
	printf("\n");
}

void QueueTest()
{
	Queue queue;
	QueueInit(&queue);

	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	QueuePrint(&queue);

	QueuePop(&queue);
	QueuePop(&queue);
	QueuePop(&queue);
	QueuePrint(&queue);

	QueueFront(&queue);

	printf("%d\n", QueueSize(&queue));

	QueueDestroy(&queue);
}