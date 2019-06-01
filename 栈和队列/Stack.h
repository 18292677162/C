#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE (100)

typedef int StackDataType;

typedef struct Stack {
	StackDataType arr[MAX_SIZE];	 //最大个数
	int top;		//当前个数
}   Stack;

// 初始化/销毁
// 增（只能从栈顶）/删（只能删除栈顶）/查（只能查看栈顶元素）
// 个数 / 是否空 / 是否满
// 增 -> 顺序表的尾插
// 删 -> 顺序表的尾删

void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}

void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top >= 0 && pStack->top < MAX_SIZE);

	//	pStack->arr[pStack->top ++] = data; 顺带top++
	pStack->arr[pStack->top + 1] = data;
	pStack->top++;
}

void StackPop(Stack *pStack)
{
	assert(pStack->top>0);

	pStack->top--;
}

StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);

	return pStack->arr[pStack->top - 1];
}

int StackSize(const Stack *pStack)
{
	return pStack->top;
}

int StackFull(const Stack *pStack)
{
	return  pStack->top >= MAX_SIZE;
}

int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

void StackPrint(const Stack *pStack)
{
	for (int i = 1; i <= pStack->top; i++){
		printf("%d ", pStack->arr[i]);
	}
	printf("top\n");
}

void StackTest()
{
	Stack stack;
	StackInit(&stack);

	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	StackPrint(&stack);

	StackPop(&stack); 
	StackPop(&stack);
	StackPrint(&stack);

	printf("%d \n", StackSize(&stack));
	StackDestroy(&stack);
}