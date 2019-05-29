#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/************************************************************************/
/* ���ȷ�������㷨��PCB��                                              */
/************************************************************************/
struct PCB{
	// ��������
	char name[10];
	// ����ʱ��
	int runtime;
	// ���ȼ�
	int frist;
	// ״̬�� RΪ������FΪ���
	char state;
};

// �������Ⱥ���
void pcb(struct PCB *p, int N)
{
	int i;
	printf("��������̵����֡����ȼ�������ʱ��(���磺1 2 1)\n");
	printf("\n");

	for (i = 0; i < N; i++)
	{
		printf("�������%d�����̵���Ϣ:\n", i + 1);
		scanf("%s %d %d", p[i].name, &p[i].frist, &p[i].runtime);
		//���̳�ʼ״̬��Ϊ����
		p[i].state = 'R';
	}
}

//ȷ��������ȼ������ӳ��� 
int max_frist_process(struct PCB *p, int N)
{
	//maxΪ�������������ʼ��Ϊ-10
	int max = -10;
	int i, key;
	for (i = 0; i < N; i++)
	{
		//r��ʾ��������
		if (p[i].state == 'r')
			return -1;
		else
		{
			//�Ӿ���������ѡȡ���������Ľ���
			if (max < p[i].frist && p[i].state == 'R')
			{
				//max���ÿ��ѭ���е����������
				max = p[i].frist;
				key = i;
			}
		}
	}
	//��������������Ľ��������������
	if (p[key].state == 'F')
		return -1;
	else
		return key;
}

void print(struct PCB *p, int N)
{
	int i;
	printf("\n������  ���ȼ� ����ʱ�� ��ǰ״̬\n");
	printf("*****************************************\n");
	//������ʾÿ�����̵�������������Ҫ������ʱ���״̬
	for (i = 0; i < N; i++)
	{
		printf("  %s\t %d\t  %d\t   %c\t\n", p[i].name, p[i].frist, p[i].runtime, p[i].state);
	}
}

void run(struct PCB *p, int N)
{
	int i, j;
	// ���д���
	int t = 0;
	for (j = 0; j < N; j++)
	{
		//���д�����Ϊ������������ʱ��֮��
		t += p[j].runtime;
	}
	printf("\n����û����ǰ����ǰ��״̬��:\n");
	print(p, N);

	vector<string> vec_out;

	for (j = 0; j < t; j++)
	{
		//��������������Ľ���û�������꣬��������
		while (max_frist_process(p, N) != -1)
		{
			//����״̬��Ϊr����ʾ����������
			p[max_frist_process(p, N)].state = 'r';
		}
		for (i = 0; i < N; i++)
		{
			if (p[i].state == 'r')
			{
				//����ǰ���н��̵���������1
				p[i].frist -= 1;
				//Ҫ������ʱ���1
				p[i].runtime--;

				//��ʾÿ�����к��PCB�����
				print(p, N);

				printf("Process: %s, running @ time %d, priority %d, run_time %d\n",
					p[i].name, j, p[i].frist, p[i].runtime);

				string s = p[i].name;
				vec_out.push_back(s);

				{
					if (p[i].runtime == 0)
						//�������򽫸ý���״̬��Ϊ����
						p[i].state = 'F';
					else
						//δ�����꽫��״̬��Ϊ����
						p[i].state = 'R';
				}


			}
		}
	}

	printf("ִ��˳��\n");
	printf("%s", vec_out[0].c_str());
	for (int i = 1; i < vec_out.size(); i++)
	{
		printf("-->%s", vec_out[i].c_str());
	}
}

void PCB_MAIN()
{
	int N;
	printf("��������̵�����:\n");
	scanf("%d", &N);

	struct PCB *p = new struct PCB[N];
	// ��ʼ��
	pcb(p, N);
	// ���̵���ģ��
	run(p, N);

	delete[] p;
}

int main()
{
	PCB_MAIN();
	system("pause");
	return 0;
}
