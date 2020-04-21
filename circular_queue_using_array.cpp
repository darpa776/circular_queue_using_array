#include <stdio.h>
//#include <stdlib.h>
#include "header.h"
#define  _CRT_SECURE_NO_WARNINGS
#define size 5

int queue[size];//큐 배열 선언
int front = 0; //front 위치 입력
int rear = 0; //rear 위치 입력
int select;//menu 선택
int data;//큐에 넣을 값을 저장할 변수
int i;

void menu()
{
	while (1)
	{
		printf("\n1. 입력 2. 삭제 3. 출력 4.검색 5. 파일에서 입력 6. 파일로 출력 7. 종료\n");
		printf("수행할 기능의 번호를 입력하세요: ");
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
			printf("잘못 입력하셨습니다. 다시 입력해주세요!\n");
			break;
		}
	}
}


void add()
{
	if ((rear + 1) % size == front)
	{
		printf("큐가 가득 찼습니다.\n");
		return;
	}
	printf("추가할 숫자를 입력해주세요: ");
	scanf_s("%d", &data);
	queue[rear] = data;
	printf("추가 완료되었습니다.\n");
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
	printf("삭제 완료되었습니다.\n");
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
	else if (rear == front)//맨처음. 자료가 아무것도 없을 때
	{
		printf("출력할 자료가 없습니다.\n");
	}
}

void search()
{
	int search_data = 0;
	if (rear == front)//맨처음. 자료가 아무것도 없을 때
	{
		printf("검색할 자료가 없습니다.\n");
		return;
	}
	printf("검색할 숫자를 입력하세요: ");
	scanf("%d", &search_data);
	if (front < rear)
	{
		for (i = front; i < rear; i++)
		{
			if (search_data == queue[i])
			{
				printf("자료가 존재합니다.\n");
				return;
			}
		}
		printf("자료가 존재하지 않습니다.\n");
		return;
	}
	else if (front > rear)
	{
		for (i = front; i < size; i++)
		{
			if (search_data == queue[i])
			{
				printf("자료가 존재합니다.\n");
				return;
			}
		}
		for (i = 0; i < rear; i++)
		{
			if (search_data == queue[i])
			{
				printf("자료가 존재합니다.\n");
				return;
			}
		}
		printf("자료가 존재하지 않습니다.\n");
		return;
	}
}

void fileinput()
{
	int num;
	if ((rear + 1) % size == front)//full
	{
		printf("큐가 가득 찼습니다.\n");
		return;
	}
	printf("숫자들을 받아올 파일이름을 입력하세요(.txt): ");
	char name[30];
	scanf("%s", name);
	FILE *  file_input = fopen(name, "rt");
	for (i = rear; fscanf(file_input, "%d ", &num) != EOF; i++)
	{
		if ((rear + 1) % size == front)
		{
			printf("큐가 가득 찼습니다.\n");
			return;
		}
		queue[i] = num;
		rear = ++rear%size;
	}
	printf("입력이 완료되었습니다.\n");
	fclose(file_input);
}

void fileoutput()
{
	char name[30];
	printf("출력을 위해 생성할 파일이름을 적어주세요(.txt): ");
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
	printf("출력이 완료되었습니다.\n");
	fclose(file_output);
}