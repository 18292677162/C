#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/************************************************************************/
/* 优先服务调度算法（PCB）                                              */
/************************************************************************/
struct PCB{
	// 进程名称
	char name[10];
	// 运行时间
	int runtime;
	// 优先级
	int frist;
	// 状态， R为就绪，F为完成
	char state;
};

// 构造优先函数
void pcb(struct PCB *p, int N)
{
	int i;
	printf("请输入进程的名字、优先级、运行时间(例如：1 2 1)\n");
	printf("\n");

	for (i = 0; i < N; i++)
	{
		printf("请输入第%d个进程的信息:\n", i + 1);
		scanf("%s %d %d", p[i].name, &p[i].frist, &p[i].runtime);
		//进程初始状态均为就绪
		p[i].state = 'R';
	}
}

//确定最大优先级进程子程序 
int max_frist_process(struct PCB *p, int N)
{
	//max为最大优先数，初始化为-10
	int max = -10;
	int i, key;
	for (i = 0; i < N; i++)
	{
		//r表示正在运行
		if (p[i].state == 'r')
			return -1;
		else
		{
			//从就绪进程中选取优先数最大的进程
			if (max < p[i].frist && p[i].state == 'R')
			{
				//max存放每次循环中的最大优先数
				max = p[i].frist;
				key = i;
			}
		}
	}
	//具有最大优先数的进程若已运行完毕
	if (p[key].state == 'F')
		return -1;
	else
		return key;
}

void print(struct PCB *p, int N)
{
	int i;
	printf("\n进程名  优先级 运行时间 当前状态\n");
	printf("*****************************************\n");
	//依次显示每个进程的名、优先数、要求运行时间和状态
	for (i = 0; i < N; i++)
	{
		printf("  %s\t %d\t  %d\t   %c\t\n", p[i].name, p[i].frist, p[i].runtime, p[i].state);
	}
}

void run(struct PCB *p, int N)
{
	int i, j;
	// 运行次数
	int t = 0;
	for (j = 0; j < N; j++)
	{
		//运行次数即为各个进程运行时间之和
		t += p[j].runtime;
	}
	printf("\n进程没运行前，当前的状态是:\n");
	print(p, N);

	vector<string> vec_out;

	for (j = 0; j < t; j++)
	{
		//具有最大优先数的进程没有运行完，让其运行
		while (max_frist_process(p, N) != -1)
		{
			//将其状态置为r，表示其正在运行
			p[max_frist_process(p, N)].state = 'r';
		}
		for (i = 0; i < N; i++)
		{
			if (p[i].state == 'r')
			{
				//将当前运行进程的优先数减1
				p[i].frist -= 1;
				//要求运行时间减1
				p[i].runtime--;

				//显示每次运行后各PCB的情况
				print(p, N);

				printf("Process: %s, running @ time %d, priority %d, run_time %d\n",
					p[i].name, j, p[i].frist, p[i].runtime);

				string s = p[i].name;
				vec_out.push_back(s);

				{
					if (p[i].runtime == 0)
						//运行完则将该进程状态置为结束
						p[i].state = 'F';
					else
						//未运行完将其状态置为就绪
						p[i].state = 'R';
				}


			}
		}
	}

	printf("执行顺序：\n");
	printf("%s", vec_out[0].c_str());
	for (int i = 1; i < vec_out.size(); i++)
	{
		printf("-->%s", vec_out[i].c_str());
	}
}

void PCB_MAIN()
{
	int N;
	printf("请输入进程的数量:\n");
	scanf("%d", &N);

	struct PCB *p = new struct PCB[N];
	// 初始化
	pcb(p, N);
	// 进程调度模拟
	run(p, N);

	delete[] p;
}

int main()
{
	PCB_MAIN();
	system("pause");
	return 0;
}
