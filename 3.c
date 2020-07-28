#define _CRT_SECURE_NO_WARNINGS	
/* 1.Դ����Ĵ��� */
/*
#include "stdio.h"
long sum_fac(int n);	//��������
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
}
long sum_fac(int n)
{
	long s = 0;
	int i;
	long fac=1;	//fac����ֵ
	for (i = 1; i <= n; i++)
	{
		fac *= i;
		s += fac;
	}	//�������
	return s;
}


/* 2.Դ�����޸��滻�� */
/* ��1�� */
/*
#include "stdio.h"
long sum_fac(int n);	//��������
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
}

long sum_fac(int n)
{
	static long s = 0;
	static long fac = 1;
	fac *= n;	//��n!
	s += fac;	// s=s+n!
	return s;
}


/* (2) */
/*
#include "stdio.h"
double sum_fac(int n);	//��������
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %lf\n", k, sum_fac(k));
}

double sum_fac(int n)
{
	static double s = 0;
	static double fac = 1;
	fac *= n;	//��n!
	s += 1/ fac;	// s=s+1/n!
	return s;
}


/* 3.���ٵ����� */
/*
#include<stdio.h>
void main(void)
{
	int i, k;
	long sum = 0, * p = &sum;
	scanf("%d", &k);
	for (i = 1; i <= k; i++) {
		sum += fabonacci(i);
		printf("i=%d\tthe sum is %ld\n", i, *p);
	}
}
long fabonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fabonacci(n - 1) + fabonacci(n - 2);
}


/* 4.�������� */
/* ��1�� */
/*
#include<stdio.h>
MaxDiv(int a, int b)
{
	if (a % b != 0)	//��������Ϊ0�������Ϊ��������������Ϊ����շת���
		return MaxDiv(b, a % b);
	else	//������Ϊ0�����Ϊ���Լ��
		return  b;
}

int main()
{
	int a, b,result;
	printf("����������������");
	scanf("%d %d", &a, &b);
	if (a <= 0 || b <= 0)
		printf("�������\n");
	else
	{
		result=MaxDiv(a, b);
		printf("���Լ��Ϊ��%d\n", result);
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#include<math.h>
IsPrime(int n)	//�ж�n�Ƿ�Ϊ����
{
	int i;
	double temp=sqrt(n);
	for (i = 2; i <= temp; i++)
		if (n % i == 0)		//������Ϊ0��Ϊ����
			return 0;
	return 1;	//��һֱ��������Ϊ����
}

void Goldbach(int n)	//��֤n�����°ͺղ������
{
	int temp,a;
	for (temp = n / 2, a = 2; a <= temp; a++)
		if (IsPrime(a) && IsPrime(n - a))	//�ж�a��n-a�Ƿ�Ϊ����
		{
			printf("%d=%d+%d\n", n, a, n - a);	//��Ϊ�����������������
			return;
		}
	printf("�������°ͺղ���!\n");
}

int main()
{
	int n;
	printf("������һ�����ڵ���4��ż����");
	scanf("%d", &n);
	if (n % 2 || n < 4)
			printf("�������\n");
	else
		Goldbach(n);
	return 0;
}


/* (3) */
/*
#include<stdio.h>
#include<math.h>
#define BEGIN 10
#define END 20
IsPrime(int n)	//�ж�n�Ƿ�Ϊ����
{
	int i;
	double temp = sqrt(n);
	for (i = 2; i <= temp; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void Goldbach(int n)	//��֤n�����°ͺղ������
{
	int temp, a;
	for (temp = n / 2, a = 2; a <= temp; a++)
		if (IsPrime(a) && IsPrime(n - a))
		{
			printf("%d=%d+%d\n", n, a, n - a);
			return;
		}
	printf("�������°ͺղ���!\n");
}

int main()
{
	int i;
	printf("GOLDBACH'S CONJECTURE:\n");
	printf("Every even number n>=4 is the sum of two primes.\n");
	for (i = BEGIN; i <= END; i+=2)
		Goldbach(i);	//��֤BEGIN��END��ż���ĸ�°ͺղ���
	return 0;
}

/**/