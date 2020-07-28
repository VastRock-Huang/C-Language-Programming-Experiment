#define _CRT_SECURE_NO_WARNINGS	

/* 1.���ʽ��ֵ�ĳ�����֤�� */
/*
#include<stdio.h>

char u[] = "UVWXYZ";
char v[] = "xyz";
struct T {
	int x;
	char c;
	char* t;
};

int main()
{	
	struct T a[] = { {11,'A',u},{100, 'B',v} }, * p = a;
	printf("(++p)->x is %d\n", (++p)->x);

	p = a;
	printf("p++,p->c is %c\n", (p++, p->c));

	p = a;
	printf("*p++->t, *p->t is %c\n", (*p++->t, *p->t));

	p = a;
	printf("*(++p)->t is %c\n", *(++p)->t);

	p = a;
	printf("*++p->t is %c\n", *++p->t);

	p = a;
	puts(u);
	printf("++*p->t is %c\n", ++ * p->t);	//���Ϊ��W�� ��֪ԭ��

	return 0;
}


/* 2.Դ�����޸��滻�� */
/* ��1�� */
/*
#include "stdio.h"
#include "stdlib.h"
struct s_list{
	int data; // ������
	struct s_list* next; // ָ����
};

void create_list(struct s_list** headp, int* p);
void main(void)
{
	struct s_list* head = NULL, * p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; // 0Ϊ�������  
	create_list(&head, s); // ����������  ���޸�Ϊ��headp��ַ��
	p = head; //����ָ��pָ����ͷ  
	while (p) {
		printf("%d\t", p->data); // ����������ֵ  
		p = p->next; //����ָ��pָ����һ���  
	}
	printf("\n");
}
void create_list(struct s_list** headp, int* p)	//���޸�headp����Ϊ����ָ�룩
{
	struct s_list* loc_head = NULL, * tail;
	if (p[0] == 0) // �൱��*p==0  
		;
	else { // loc_headָ��̬����ĵ�һ�����  
		loc_head = (struct s_list*)malloc(sizeof(struct s_list));
		loc_head->data = *p++; // ��������ֵ  
		tail = loc_head; // tailָ���һ�����  
		while (*p) { // tail��ָ����ָ����ָ��̬�����Ľ��  
			tail->next = (struct s_list*)malloc(sizeof(struct s_list));
			tail = tail->next; // tailָ���´����Ľ��  
			tail->data = *p++; // ���´����Ľ���������ֵ  
		}
		tail->next = NULL; // ��ָ����NULLֵ  
	}
	*headp = loc_head; // ʹͷָ��headpָ���´����������޸�Ϊ*headp��
}


/* ��2�� */
/*
#include "stdio.h"
#include "stdlib.h"
struct s_list {
	int data; // ������
	struct s_list* next; // ָ����
};

void create_list(struct s_list** headp, int* p);
void main(void)
{
	struct s_list* head = NULL, * p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; // 0Ϊ�������  
	create_list(&head, s); // ����������  ���޸�Ϊ��headp��ַ��
	p = head; //����ָ��pָ����ͷ  
	while (p) {
		printf("%d\t", p->data); // ����������ֵ  
		p = p->next; //����ָ��pָ����һ���  
	}
	printf("\n");
}
void create_list(struct s_list** headp, int* p)
{
	struct s_list* New, * end=NULL;
	if (p[0] == 0) // �൱��*p==0  
		;
	else
	{
		end = (struct s_list*)malloc(sizeof(struct s_list));
		end->data = *p++;
		end->next = NULL;
		
		while (*p)
		{
			New= (struct s_list*)malloc(sizeof(struct s_list));
			New->data = *p++;
			New->next = end;
			end = New;
		}
	}
	*headp = end;
}


/* 3.�������� */
/* ��1�� */
/*
#include<stdio.h>

typedef struct bits
{
	unsigned short bit0 : 1;
	unsigned short bit1 : 1;
	unsigned short bit2 : 1;
	unsigned short bit3 : 1;
	unsigned short bit4 : 1;
	unsigned short bit5 : 1;
	unsigned short bit6 : 1;
	unsigned short bit7 : 1;
}bits;


void f0(struct bits b)
{
	printf("the 0 function % d is called!\n", b.bit0);
}

void f1(struct bits b)
{
	printf("the 1 function % d is called!\n", b.bit1);
}
void f2(bits b)
{
	printf("the 2 function % d is called!\n", b.bit2);
}
void f3(bits b)
{
	printf("the 3 function % d is called!\n", b.bit3);
}
void f4(bits b)
{
	printf("the 4 function % d is called!\n", b.bit4);
}
void f5(bits b)
{
	printf("the 5 function % d is called!\n", b.bit5);
}
void f6(bits b)
{
	printf("the 6 function % d is called!\n", b.bit6);
}
void f7(bits b)
{
	printf("the 7 function % d is called!\n", b.bit7);
}


int main()
{
	void (*pfun[8])(bits) = { f0,f1,f2,f3,f4,f5,f6,f7 };
	bits a = { 1,0,1,0,1,1,0,0 };
	if (a.bit0)
		pfun[0](a);
	if (a.bit1)
		pfun[1](a);
	if (a.bit2)
		pfun[2](a);
	if (a.bit3)
		pfun[3](a);
	if (a.bit4)
		pfun[4](a);
	if (a.bit5)
		pfun[5](a);
	if (a.bit6)
		pfun[6](a);
	if (a.bit7)
		pfun[7](a);
	return 0;
}


/* ��2�� */
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define NUMBITS 4
#define NAMELEN 10
#define SCORENUM 4

char* scorename[] = { "Ӣ��","�ߵ���ѧ","��ͨ����","C���Գ������" };

typedef struct stu {
	int num;
	char name[NAMELEN];
	int scores[SCORENUM+1];
	float ave;
}STU;

typedef struct node {
	STU per;
	struct node* next;
}Node;

int inputstu(STU* e)
{
	STU temp;
	int i;
	printf("ѧ��:");
	scanf("%d%*c",&temp.num);
	if (!temp.num)
		return 0;
	printf("����:");
	gets(temp.name);
	for (i = 0,temp.scores[4]=0; i < SCORENUM; i++)
	{
		printf("%s:", scorename[i]);
		scanf("%d", &temp.scores[i]);
		temp.scores[4] += temp.scores[i];
	}
	temp.ave = temp.scores[4] * 1.0 / SCORENUM;
	*e = temp;
	return 1;

}

Node* addstu()
{
	Node* head = NULL,*temp=NULL;
	STU e;
	while(inputstu(&e))
	{
		if (!head)
		{
			head = (Node*)malloc(sizeof(Node));
			head->per = e;
			temp = head;
		}
		else
		{
			temp->next = (Node*)malloc(sizeof(Node));
			temp->next->per= e;
			temp = temp->next;
		}
	}
	if(temp)
		temp->next = NULL;
	return head;
}

void putstu(Node *head)
{
	Node* temp = head;
	int i;
	if (temp)
	{
		printf("ѧ��    ����    ");
		for (i = 0; i < SCORENUM; i++)
			printf("%-13s", scorename[i]);
		putchar('\n');
	}

	while (temp)
	{
		printf("%-8d%-8s", temp->per.num, temp->per.name);
		for (i = 0; i < SCORENUM; i++)
			printf("%-13d", temp->per.scores[i]);
		putchar('\n');
		temp = temp->next;
	}
}

void modifystu(Node* head)
{
	int pick;
	int num;
	int i;
	char name[NAMELEN];
	Node* temp = head;
	printf("��������ҷ�ʽ��0.��ѧ�� 1.������\n");
	scanf("%d%*c", &pick);
	while(pick<0||pick> 1)
	{
		printf("������������ҷ�ʽ��0.��ѧ�� 1.������\n");
		scanf("%d%*c", &pick);
	}
	if (pick == 0)
	{
		printf("������ѧ�ţ�");
		scanf("%d%*c", &num);
	}
	else
	{
		printf("������������");
		gets(name);
	}
	for (; temp; temp = temp->next)
	{
		if ((!pick && temp->per.num == num)||(pick&&!strcmp(name,temp->per.name)))
		{
			printf("���ҵ���\n");
			printf("ѧ��    ����    ");
			for (i = 0; i < SCORENUM; i++)
				printf("%-13s", scorename[i]);
			putchar('\n');
			printf("%-8d%-8s", temp->per.num, temp->per.name);
			for (i = 0; i < SCORENUM; i++)
				printf("%-13d", temp->per.scores[i]);
			putchar('\n');
			break;
		}
	}
	if (!temp)
	{
		printf("δ�ҵ���\n");
		Sleep(500);
		return;
	}
	printf("�������޸ĵ��0.ѧ�� 1.���� ");
	for (i = 0; i < SCORENUM; i++)
		printf("%d.%s", i + 2, scorename[i]);
	putchar('\n');
	scanf("%d", &pick);
	while (pick<0||pick>5)
	{
		printf("\n����������:");
		scanf("%d", &pick);
	}
	if (pick == 0)
	{
		printf("������ѧ�ţ�");
		scanf("%d", &temp->per.num);
	}
	else if(pick==1)
	{
		printf("������������");
		gets(temp->per.name);
	}
	else
	{
		printf("������ɼ���");
		scanf("%d", &temp->per.scores[pick - 2]);
	}
	printf("\n�޸ĳɹ���\n");
	Sleep(500);
	return;
}

void putstu2(Node* head)
{
	Node* temp = head;
	int i;
	if (temp)
	{
		printf("ѧ��    ����    ");
		for (i = 0; i < SCORENUM; i++)
			printf("%-13s", scorename[i]);
		printf("�ܳɼ�  ƽ���ɼ�");
		putchar('\n');
	}

	while (temp)
	{
		printf("%-8d%-8s", temp->per.num, temp->per.name);
		for (i = 0; i < SCORENUM; i++)
			printf("%-13d", temp->per.scores[i]);
		printf("%-8d%-.2f", temp->per.scores[4], temp->per.ave);
		putchar('\n');
		temp = temp->next;
	}
}


void sortstu1(Node* head)
{
	Node* tempi, * tempj;
	STU temp;
	int len,i,j;
	for (tempi = head, len = 0; tempi; tempi = tempi->next)
		len++;
	for(i=1,tempi=head;i<=len-1;i++)
		for(tempj=tempi,j=0;j<len-i;j++,tempj=tempj->next)
			if (tempj->next->per.ave < tempj->per.ave)
			{
				temp = tempj->next->per;
				tempj->next->per = tempj->per;
				tempj->per = temp;
			}
	putstu2(head);
}

int main()
{
	int flag = 1;
	int pick;
	Node* head = NULL;
	head=addstu(head);
	while (flag)
	{
		printf("\n\n\n0.�˳�\n");
		printf("1.���ÿ��ѧ���ĸ�����Ϣ\n");
		printf("2.�޸�ָ��ѧ����ָ�������������\n");
		printf("3.�����λͬѧ��ѧ�š����������ſγ̵��ܳɼ���ƽ���ɼ�\n");
		printf("4.����ƽ���ɼ�������������\n");
		scanf("%d", &pick);
		while (pick<0||pick>4)
		{
			printf("����������");
			scanf("%d", &pick);
		}
		switch (pick)
		{
		case 0:flag = 0;
			break;
		case 1:putstu(head);
			break;
		case 2:modifystu(head);
			break;
		case 3:putstu2(head);
			break;
		case 4:sortstu1(head);
			break;
		}
	}
}



/**/