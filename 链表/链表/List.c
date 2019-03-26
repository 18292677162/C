//#include "List.h"
//#include "Test.h"

//int main()
//{
//
//	ListNode *first;
//	ListInit(&first);
//
//	printf("%d \n", GetListLength(&first));
//	ListPushFront(&first, 1);
//	ListPushFront(&first, 2);
//	ListPushFront(&first, 3);
//	ListPushFront(&first, 4);
//	ListPrint(&first);
//
//	ListPushBack(&first, 5);
//	ListPushBack(&first, 6);
//	ListPushBack(&first, 7);
//	ListPushBack(&first, 8);
//	ListPrint(&first);
//
//	ListPopBack(&first);
//	ListPopBack(&first);
//	ListPrint(&first);
//
//	ListPopFront(&first);
//	ListPopFront(&first);
//	ListPrint(&first);
//
//	ListNode *result = ListFind(first, 5);
//	ListInsert(&first, result, 0);
//
//	ListPrint(&first);
//
//	result = ListFind(first, 0);
//	ListErase(&first, result);
//	ListPrint(&first);
//
//	printf("%d \n", GetListLength(&first));
//	ListDestroy(&first);
//	printf("%d \n", GetListLength(&first));
//	ListPrint(&first);
//
//	system("pause");
//	return 0;
//}