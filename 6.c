#define _CRT_SECURE_NO_WARNINGS	

/* 1.Դ����Ĵ��� */
/*
#include "stdio.h"
void main(void)
{
	float f;		//����һ��float����
	float* p=&f;	//��ָ��ָ����ǰ�ı���
	scanf("%f", p);
	printf("%f\n", *p);
}


/* 2.Դ�������ơ��޸ġ��滻�� */
/*
#include "stdio.h"
#include "string.h"
void main(void)
{
	char* (*p)(char* dest,char* src)=NULL;		//��Ӻ���ָ��p�Ķ��壨��գ�
	char a[80], b[80], c[160], * result = c;
	int choice, i;
	do {
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tinput a number (1-3) please!\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice>3);		//�Ĵ�choice>5��Ϊ>3
	switch (choice) {
	case 1:
		p = strcpy;
		break;
	case 2:
		p = strcat;
		break;
	case 3:
		goto down;
	}
	getchar();
	printf("input the first string please!\n");
	i = 0;
	gets(a);	//�����ַ���a����գ�
	printf("input the second string please!\n");
	i = 0;
	gets(b);	//�����ַ���b����գ�
	result = p(a, b);	//���ú���ָ�루��գ�
	printf("the result is %s\n", result);
down:
	;
}


/* 3.���ٵ����� */
/* (1) */
/*
#include "stdio.h"
char* strcpy(char*, char*);
void main(void)
{
	char a[20], b[60] = "there is a boat on the lake.";
	printf("%s\n", strcpy(a, b));

}
char* strcpy(char* s, char* t)
{
	while (*s++ = *t++)
		;
	return (s);
}


/* (2) */
/*
#include "stdio.h"
char* strcpy(char*, char*);
void main(void)
{
	char a[60], b[60] = "there is a boat on the lake.";		//���ַ�����a�������Ӵ�
	printf("%s\n", strcpy(a, b));

}
char* strcpy(char* s, char* t)
{
	char* p = s;	//����µ�ָ��p��ʹ�����䶯��ָ��Ϊp����Ϊs
	while (*p++ = *t++)
		;
	return (s);
}


/* 4.�������� */
/* ��1�� */
/*
#include<stdio.h>

char changec(char c)
{
	if (c < 10)
		return c | '0';
	else
		return c - 10 + 'A';
}

int main()
{
	long a=0x1234ABCD;
	char* pc = (char*)&a,c;
	int i = 0;
	printf("������һ����������");
	scanf("%lx", &a);
	printf("��������\n�ֽ�  ����λ  ����λ\n");
	for (i = 0; i < 4; i++)
	{
		printf("No.%d  ", i+1);
		c = changec((*pc>>4) & 0xf);
		printf("%6c  ", c);
		c = changec(*pc & 0xf);
		printf("%6c\n", c);
		pc++;
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#define N 5

void changestr(char *p)
{
	int j,flag;
	if (p[0])
	{
		for (flag = 1, j = 0; p[j]; j++)
		{
			if (p[j] == ' ' && flag)
				flag = 0;
			else if (p[j] == ' ' && !flag)
				continue;
			else
				flag = 1;
			putchar(p[j]);
		}
		putchar('\n');
	}
}

int main()
{
	int i;
	char s[N][80];
	char* p[N];
	printf("�������ı���\n");
	for (i = 0; i < N; i++)
	{
		p[i] = s[i];
		gets(p[i]);
	}
	printf("����������\n");
	for(i=0;i<N;i++)
		changestr(p[i]);
	return 0;
}



/* (4) */
/*
#include<stdio.h>
#define N 3		//ѧ����
#define M 2		//�γ�����

void inputscorenames(char(*s)[10])
{
	int i;
	printf("������%d�ſγ̵����ƣ�\n", M);
	for (i = 0; i < M; i++)
		scanf("%s",*(s+i));
}

void inputscores(float(*p)[M],char (*s)[10])
{
	int i, j;
	printf("��ֱ�����%d��ѧ����%d�ųɼ���\n",N,M);
	for (i = 0; i < N; i++)
	{
		printf("��%d��ѧ����\n", i+1);
		for (j = 0; j < M; j++)
		{
			printf("%s:", *(s + j));
			scanf("%f", *(p + i) + j);
		}
	}		
}

void putstuave(float(*p)[M])
{
	int i, j;
	float sum;
	for (i = 0; i < N; i++)
	{
		for (sum = 0, j = 0; j < M; j++)
			sum += *(*(p + i) + j);
		printf("��%d��ͬѧ��ƽ���ɼ�Ϊ��%.2f\n", i+1, sum/M);
	}	
}

void putscoave(float(*p)[M],char (*s)[10],float* scoave)
{
	int i, j;
	float sum;
	for (i = 0; i < M; i++)
	{
		for (sum = 0, j = 0; j < N; j++)
			sum += *(*(p + j) + i);
		*(scoave + i) = sum/N;
		printf("%s�γ�ƽ���ɼ�Ϊ��%.2f\n", *(s+i), *(scoave+i));
	}
}

void underavenum(float(*p)[M], char(*s)[10], float* scoave)
{
	int num;
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (num = 0, j = 0; j < N; j++)
			if (*(*(p + j) + i) < *(scoave + i))
				num++;
		printf("����%sƽ���ɼ�������%d\n", *(s + i), num);
	}
}

void highlownum(float(*p)[M], char(*s)[10], float* score)
{
	int high, low;
	int i, j;
	for (i = 0;i < M; i++)
	{
		for (high = low = 0, j = 0; j < N; j++)
			if (*(*(p + j) + i) < 60)
				low++;
			else if (*(*(p + j) + i) > 90)
				high++;
		printf("%s������������%d\t90������������%d\n", *(s + i), low,high);
	}
}

int main()
{
	char scorenames[M][10];
	float scores[N][M];
	float scoave[M];
	inputscorenames(scorenames);
	inputscores(scores, scorenames);
	putchar('\n');
	putstuave(scores);		//���ÿ��ѧ��ƽ���ɼ�
	putchar('\n');
	putscoave(scores, scorenames, scoave);	//���ÿ��ƽ���ɼ�
	putchar('\n');
	underavenum(scores, scorenames, scoave);	//ÿ�ŵ���ƽ���ֵ�����
	putchar('\n');
	highlownum(scores, scorenames, scoave);	//�����񼰹�90����
	return 0;
}


/* 5.ѡ���� */
/* ��1�� */
/*
#include<stdio.h>

int main()
{
	char num[2][32];
	char result[32];
	int i,j;
	int temp;

	for (i = 0; i < 31; i++)
		result[i] = '0';
	result[i] = 0;

	for (i = 0; i < 2; i++)
	{
		printf("��%d������",i+1);
		num[i][0] = '0';
		for (j = 1; j < 21; j++)
			num[i][j] = getchar();
		if (getchar() != '.')
		{
			printf("Input Eorror!");
			exit(1);
		}
		for (j = 21; j < 31; j++)
			num[i][j] = getchar();
		num[i][j] = 0;
		getchar();
	}

	for (j = 31; j >= 0; j--)
	{
		temp =result[j]+ num[0][j] + num[1][j] - 3 * '0';
		if (temp >= 10)
			result[j - 1]++;
		result[j] = temp % 10+'0';	
	}

	printf("a+b=");
	if (result[0] != '0')
		putchar(result[0]);
	for (i = 1; i < 21; i++)
		putchar(result[i]);
	putchar('.');
	for (; i < 31; i++)
		putchar(result[i]);
	return 0;

}


/* (2) */
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char* (*p[2])(char*, const char*) = { strstr,strcat };
	char s1[40], s2[20];
	char* temp;
	printf("�������һ���ַ�����");
	gets(s1);
	printf("������ڶ����ַ�����");
	gets(s2);
	
	printf("\nִ��p[0]��strstr��:\n");
	if ((temp = p[0](s1, s2)))
		printf("s2��s1�Ӵ�:%s\n", temp);
	else
		printf("s2����s1�Ӵ�\n");

	printf("\nִ��p[1]��strcat��:\n");
	printf("%s\n", p[1](s1, s2));
	
	return 0;
}


/* (3) */
/*
#include<stdio.h>

int main(int argc, char* argv[])
{
	int i;
	printf("�����в�������:%d\n�ֱ�Ϊ:\n", argc);
	for (i = 0; i < argc; i++)
		puts(*(argv + i));
	return 0;
	
}

/**/