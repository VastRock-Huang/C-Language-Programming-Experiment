#define _CRT_SECURE_NO_WARNINGS		//VS��������ԭ����Ҫ��ӵĺ궨��

/* 1.Դ����Ĵ��� */
/*
#include <stdio.h>
void main(void)
{
	int i, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);	//��Ϊ&n
	for (i = 1; i <= n; i++)	//���Ÿ�Ϊ�ֺ�
		s = s * i;
	printf("%d! = %lld", n, s);
}


/* 2.Դ�����޸��滻�� */
/* ��1��*/
/* while�滻 */
/*
#include<stdio.h>
int main()
{
	int i = 1, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);
	while (i <= n)
	{
		s *= i;
		i++;
	}
	printf("while�滻:\n%d!=%lld\n", n, s);
	return 0;
}

/* do-while�滻 */
/*
#include<stdio.h>
int main()
{
	int i = 1, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);
	do
	{
		s *= i;
		i++;
	}while(i<=n);
	printf("do-while�滻:\n%d!=%lld", n, s);
	return 0;
}

/* (2) */
/*
#include<stdio.h>
int main()
{
	int S, n=0,factorial=1;		//factorialΪ�׳�ֵ
	printf("Please enter int S:");
	scanf("%d", &S);
	while (factorial < S)
	{
		n++;
		factorial *= n;
	}
	printf("n=%d\n", n);
	return 0;
}

/* 3.�������� */
/* ��1�� */
/* ifʵ�� */
/*
#include<stdio.h>
int main()
{
	float x, tax1;		//tax1Ϊif�ó�˰��
	printf("���빤�ʽ�");
	scanf("%f", &x);
	if (x < 1000)		//���ݹ��ʷ�����ȡ˰�ifʵ�֣�
		tax1 = 0;
	else if (x >= 1000 && x < 2000)
		tax1 = x * 0.05;
	else if (x >= 2000 && x < 3000)
		tax1 = x * 0.1;
	else if (x >= 3000 && x < 4000)
		tax1 = x * 0.15;
	else if (x >= 4000 && x < 5000)
		tax1 = x * 0.2;
	else
		tax1 = x * 0.25;
	printf("\n��ȡ˰����(if)��%g\n", tax1);
	return 0;
}

/* switch ʵ�� */
/*
#include<stdio.h>
int main()
{
	float x, tax2;		//tax2Ϊswitch�ó�˰��
	printf("���빤�ʽ�");
	scanf("%f", &x);
	switch ((int)x / 1000)	//���ݹ��ʷ�����ȡ˰�switchʵ�֣�
	{
	case 0:tax2 = 0;
		break;
	case 1:tax2 = x * 0.05;
		break;
	case 2:tax2 = x * 0.1;
		break;
	case 3:tax2 = x * 0.15;
		break;
	case 4:tax2 = x * 0.2;
		break;
	default:tax2 = x * 0.25;
	}
	printf("\n��ȡ˰����(switch)��%g\n", tax2);
	return 0;
}


/* (2) */
/* ������ */
/*
#include<stdio.h>
int main()
{
	char s[100];
	int i=0;
	printf("������һ���ַ���");
	gets(s,99);
	printf("\n������ַ���");
	while(s[i])
	{
		putchar(s[i]);		//�����ǰ�±��ַ�
		if (s[i] == ' ')	//����ǰ�ַ�Ϊ�ո�
			for (; s[i] == ' '; i++);	//������ж�֮���ַ���һֱ���ǿո��ַ�Ϊֹ
		else
			i++;
	}
	return 0;
}

/* ������ */
/*
#include<stdio.h>
int main()
{
	char c;
	int flag = 1;
	printf("������һ���ַ���");
	while ((c=getchar())!='\n')
	{
		if (c == ' ' && !flag)		
		//����ǰ�ַ�Ϊ�ո���flagΪ0����������ѭ��
			continue;
		else if (c == ' ')	//���������Ϊ�ո���flag����
			flag = 0;
		else
			flag = 1;		//����Ϊ�ո�flag��1
		putchar(c);
	}
	putchar('\n');
	return 0;
}


/* (3) */
/*
#include<stdio.h>
int main()
{
	int i, j,num;
	for (i = 0; i < 10; i++)
	{
		putchar('\t');
		for (j = 0; j < (9 - i) * 2; j++)
			putchar(' ');		//���ǰ��ո�
		for (j = 0,num=1; j <= i; j++)
		{
			if (j)		//����ֵ��Ϊ��һ��
				num =num* (i - j + 1) / j;	//���չ�ʽC(i,j)=C(i,j-1)*��i-j+1)/j
			printf("%-4d",num);	//����ֵΪ��һ����ֱ�����1
		}
		putchar('\n');
	}
	return 0;
}


/* (4) */
/*
#include<stdio.h>
int main()
{
	int num,temp,flag=0;	//flag����ȥ��ǰ��0
	printf("������һ��������:");
	scanf("%d", &num);
	if (num > 0)
	{
		printf("��ת����Ϊ��");
		while(num)
		{
			temp = num % 10;
			if (temp!= 0 && !flag)
				flag = 1;	//������һ����Ϊ0������flag��1
			if(flag)	//��flag=1ʱ�������
				printf("%d", temp);
			num /= 10;
		}
		printf("\n");
	}
	else
		printf("�������!\n");
	return 0;
}

/* 4.ѡ���� */
/*
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	double x1,x2;
	srand((unsigned)time(NULL));
	x2 = rand();	//����һ���������Ϊ���Ƹ�������ֵ
	do
	{
		x1 = x2;
		x2 = x1 - (3 * x1 * x1 * x1 - 4 * x1 * x1 - 5 * x1 + 13) / (9 * x1 * x1 - 8 * x1 - 5);
		//����ʽ����
	} while (fabs(x2 - x1) > 1e-6);		//������ֵ��ֵ���ھ���ֵ�����ѭ��
	printf("���Ƹ���%lf\n", x2);
	return 0;
}

/**/
