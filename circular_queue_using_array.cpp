#include <stdio.h>
//#include <stdlib.h>
#include "header.h"
#define  _CRT_SECURE_NO_WARNINGS
#define size 5

int queue[size];//ť �迭 ����
int front = 0; //front ��ġ �Է�
int rear = 0; //rear ��ġ �Է�
int select;//menu ����
int data;//ť�� ���� ���� ������ ����
int i;

void menu()
{
	while (1)
	{
		printf("\n1. �Է� 2. ���� 3. ��� 4.�˻� 5. ���Ͽ��� �Է� 6. ���Ϸ� ��� 7. ����\n");
		printf("������ ����� ��ȣ�� �Է��ϼ���: ");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			add();
			break;
		case 2:
			_delete();
			break;
		case 3:
			print();
			break;
		case 4:
			search();
			break;
		case 5:
			fileinput();
			break;
		case 6:
			fileoutput();
			break;
		case 7:
			return;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���!\n");
			break;
		}
	}
}


void add()
{
	if ((rear + 1) % size == front)
	{
		printf("ť�� ���� á���ϴ�.\n");
		return;
	}
	printf("�߰��� ���ڸ� �Է����ּ���: ");
	scanf_s("%d", &data);
	queue[rear] = data;
	printf("�߰� �Ϸ�Ǿ����ϴ�.\n");
	rear = ++rear%size;
}

void _delete()
{
	if (front == rear)
	{
		printf("queue underflow\n");
		return;
	}
	queue[front] = 0;
	front = ++front%size;
	printf("���� �Ϸ�Ǿ����ϴ�.\n");
}

void print()
{

	if (front < rear)
	{
		for (i = front; i < rear; i++)
		{
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
	else if (front > rear)
	{
		for (i = front; i < size; i++)
		{
			printf("%d ", queue[i]);
		}
		for (i = 0; i < rear; i++)
		{
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
	else if (rear == front)//��ó��. �ڷᰡ �ƹ��͵� ���� ��
	{
		printf("����� �ڷᰡ �����ϴ�.\n");
	}
}

void search()
{
	int search_data = 0;
	if (rear == front)//��ó��. �ڷᰡ �ƹ��͵� ���� ��
	{
		printf("�˻��� �ڷᰡ �����ϴ�.\n");
		return;
	}
	printf("�˻��� ���ڸ� �Է��ϼ���: ");
	scanf("%d", &search_data);
	if (front < rear)
	{
		for (i = front; i < rear; i++)
		{
			if (search_data == queue[i])
			{
				printf("�ڷᰡ �����մϴ�.\n");
				return;
			}
		}
		printf("�ڷᰡ �������� �ʽ��ϴ�.\n");
		return;
	}
	else if (front > rear)
	{
		for (i = front; i < size; i++)
		{
			if (search_data == queue[i])
			{
				printf("�ڷᰡ �����մϴ�.\n");
				return;
			}
		}
		for (i = 0; i < rear; i++)
		{
			if (search_data == queue[i])
			{
				printf("�ڷᰡ �����մϴ�.\n");
				return;
			}
		}
		printf("�ڷᰡ �������� �ʽ��ϴ�.\n");
		return;
	}
}

void fileinput()
{
	int num;
	if ((rear + 1) % size == front)//full
	{
		printf("ť�� ���� á���ϴ�.\n");
		return;
	}
	printf("���ڵ��� �޾ƿ� �����̸��� �Է��ϼ���(.txt): ");
	char name[30];
	scanf("%s", name);
	FILE *  file_input = fopen(name, "rt");
	for (i = rear; fscanf(file_input, "%d ", &num) != EOF; i++)
	{
		if ((rear + 1) % size == front)
		{
			printf("ť�� ���� á���ϴ�.\n");
			return;
		}
		queue[i] = num;
		rear = ++rear%size;
	}
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	fclose(file_input);
}

void fileoutput()
{
	char name[30];
	printf("����� ���� ������ �����̸��� �����ּ���(.txt): ");
	scanf("%s", name);
	FILE * file_output = fopen(name, "wt");
	if (front < rear)
	{
		for (i = front; i < rear; i++)
		{
			fprintf(file_output, "%d ", queue[i]);
		}
		fprintf(file_output, "\n");
	}
	else if (front > rear)
	{
		for (i = front; i < size; i++)
		{
			fprintf(file_output, "%d ", queue[i]);
		}
		for (i = 0; i < rear; i++)
		{
			fprintf(file_output, "%d ", queue[i]);
		}
		fprintf(file_output, "\n");
	}
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
	fclose(file_output);
}