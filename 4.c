#define _CRT_SECURE_NO_WARNINGS		//VS��������ԭ����Ҫ��ӵĺ궨��

/* 1.Դ����Ĵ��� */
/*
#include "stdio.h"
#define SUM (a+b)	//������
#define DIF (a-b)		//������
#define SWAP(a,b)  (t=a,a=b,b=t)	//��������
void main()		//��ӣ���
{
	int a,b, t;		//��Ӷ�a�Ķ���
	printf("Input two integers a, b:");
	scanf("%d,%d", &a,&b);
	printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM, SUM* DIF);
	SWAP(a,b);
	printf("\nNow a=%d,b=%d\n",a,b);	//printf����ĸСд
}


/* 2.Դ�����޸��滻�� */
/* (1) */
/*
#include<stdio.h>	//��ӿ�
int max(int x, int y, int z);	//��Ӻ�������
float sum(float x, float y);
void main(void)
{
	int a, b, c;
	float d, e;
	printf("Enter three integers:");
	scanf("%d,%d,%d", &a, &b, &c);
	printf("\nthe maximum of them is %d\n", max(a, b, c));

	printf("Enter two floating point numbers:");
	scanf("%f,%f", &d, &e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}

int max(int x, int y, int z)
{
	int t;
	if (x > y)
		t = x;
	else
		t = y;
	if (t < z)
		t = z;
	return t;
}

float sum(float x, float y)
{
	return x + y;
}


/* (2) */
/*
#include<stdio.h>
#define max(x,y,z) (x>y?(x>z?x:z):(y>z?y:z))	//max�궨��
float sum(float x, float y);
void main(void)
{
	int a, b, c;
	float d, e;
	printf("Enter three integers:");
	scanf("%d,%d,%d", &a, &b, &c);
	printf("\nthe maximum of them is %d\n", max(a, b, c));

	printf("Enter two floating point numbers:");
	scanf("%f,%f", &d, &e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}

float sum(float x, float y)
{
	return x + y;
}


/* 3.���ٵ����� */
/*��1�� */
/*
#include<stdio.h>	//���ͷ�ļ�
#include<assert.h>
int integer_fraction(float x);	//��Ӻ�������
#define  R
void  main(void)
{
	float  r, s;
	int s_integer = 0;
	printf("input a number: ");
	scanf("%f", &r);
#ifdef  R
	s = 3.14159 * r * r;
	printf("area of round is: %f\n", s);
	s_integer = integer_fraction(s);
	printf("the integer fraction of area is %d\n", s_integer);
	assert((s - s_integer) < 1.0);
#endif
}

int integer_fraction(float x)
{
	int i = x;
	return i;
}


/* 4.�������� */
/* (1) */
/*
#include<stdio.h>
#include<math.h>
#define S(a,b,c) ((a+b+c)/2)
#define AREA(s,a,b,c) (sqrt(s*(s-a)*(s-b)*(s-c)))

int CheckTriangle(double a, double b, double c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 0;
	if (a + b > c&& a + c > b&& b + c > a)
		return 1;
	else
		return 0;
}

int main()
{
	double a, b, c, s, area;
	printf("���������������ߣ�");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (CheckTriangle(a, b, c))
	{
		s = S(a, b, c);
		area = AREA(s, a, b, c);
		printf("�����ε����Ϊ��area=%lf\n", area);
	}
	else
		printf("�������\n");
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#define	CHANGE 0

int main()
{
	char s[100], * temp;
	printf("������һ�е籨���֣�\n");
	gets(s);
#if CHANGE==1
	for (temp = s;*temp; temp++)
		if (*temp >= 'a' && *temp <= 'z')
			*temp -= 32;
		else if (*temp >= 'A' && *temp <= 'Z')
			*temp += 32;
	printf("�任��\n");
#elif CHANGE==0
	printf("δ�任��\n");
#endif // 
	
	puts(s);
	return 0;
}

/**/