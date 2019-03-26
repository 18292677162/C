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

// 初始化/销毁
// 插入（队尾插入）/删除（队头删除）/查看队首数据
//链表的尾（NULL）是队列的尾（后进）
//为什么不是尾删头插？因为单链表定义为数据+next，next为尾，故队头先出也就是链表头先出

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

// 插入（尾插）
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = CreateNode(data);

	//队列为空
	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// 删除（头删）
void QueuePop(Queue *pQueue)
{
	
	assert(pQueue != NULL);  //链表地址不为空
	assert(pQueue->front != NULL);  //队列不能为空

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);
	
	//队列只有一个结点
	if (pQueue->front->next == NULL){
		pQueue->rear = NULL;
	}
}

// 查看队首数据
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);

	return pQueue->front->data;
}

// 是否为空
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

// 返回数据个数
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