#define _CRT_SECURE_NO_WARNINGS		//VS��������ԭ����Ҫ��ӵĺ궨��

/*1.Դ����Ĵ� */
/*
#include<stdio.h>
int main(void)
{
	int a[10] = { 27, 13, 5, 32, 23, 3, 17, 43, 55, 39 };
	void sort(int[], int);
	int i;
	sort(a, 10);	//a[0]��Ϊa
	for (i = 0; i < 10; i++)
		printf("%6d", a[i]);
	printf("\n");
	return 0;
}
 void sort(int b[], int n)
 {
	 int i, j, t;
	 for (i = 0; i < n - 1; i++)	
		 for (j = 0; j < n - i - 1; j++)
			 if (b[j] > b[j + 1])	//��Ϊ���ں�
				t = b[j], b[j] = b[j + 1], b[j + 1] = t;
}


 /* 2.Դ�������ơ��޸ġ��滻 */
 /* ��1�� */
 /*
#include<stdio.h>
#define M 10	//������
#define N 3		//��Ȧ������
int main(void)
{
	int a[M], b[M];	// ����a���Ȧ���˵ı�ţ�����b��ų�Ȧ�˵ı��
	int i, j, k;
	for (i = 0; i < M; i++)			//��Ȧ���˰�˳����1��M
		a[i] = i + 1;
	for (i = M, j = 0; i > 1; i--) 
	{
		// i��ʾȦ���˸�������ʼΪM����ʣ1����ʱ����ѭ����j��ʾ��ǰ�����˵�λ��
		for (k = 1; k <= N; k++)			// 1��N����
			if (++j > i - 1) 
				j = 0;// ���һ���˱������һ���˽��ű����γ�һ��Ȧ
		b[M - i] = j ? a[j - 1] : a[i - 1];	// ������ΪN���˵ı�Ŵ�������b����գ�
		if (j)
			for (k = --j; k < i; k++)	// ѹ������a��ʹ����ΪN���˳�Ȧ 
				a[k]=a[k+1];	//������˲�ǰ���˵Ŀ�λ����գ�
	}
	for (i = 0; i < M - 1; i++)		// �����������Ȧ�˵ı��
		printf("%6d", b[i]);
	printf("%6d\n", a[0]);			// ���Ȧ�����һ���˵ı��
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#define M 10	//������
#define N 3		//��Ȧ������
int main(void)
{
	int a[M];	// ����a���Ȧ���˵ı�ţ�����b��ų�Ȧ�˵ı��
	int i, j, k;
	for (i = 0; i < M; i++)			//��Ȧ���˰�˳����1��M
		a[i] = i + 1;
	for (i = M, j = 0, k=1; i > 1; k++,j++)
	{	// i��ʾȦ���˸�������ʼΪM����ʣ1����ʱ����ѭ����j��ʾ��ǰ�����˵�λ��
			if (j > M-1)	//����������β���ͷ����
				j = 0;
			while(a[j] == 0)	//����ǰ���������ѱ�������������ǣ�
				j++;	//��ֱ��δ���������˱���
			if (k == N)		//��������ΪN
			{
				printf("%6d", a[j]);	//�����������Ȧ��
				a[j] = 0;	//�Ա������������
				i--;	//ʣ������-1
				k = 0;	//���±���
			}
	}
	for (i = 0; i < M - 1; i++)
		if(a[i])
			printf("\n%6d\n", a[i]);			// ���Ȧ�����һ���˵ı��
	return 0;
}


/* 3.���ٵ����� */
/* Դ���� */
/*
#include<stdio.h>
void strncat(char[], char[], int);
int main(void)
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strncat(a, b, 4);
	printf("%s\n", a);
	return 0;
}
void strncat(char s[], char t[], int n)
{
	int i = 0, j;
	while (s[i++]);
	for (j = 0; j < n && t[j];)
		s[i++] = t[j++];
	s[i] = '\0';
}


/* �޸ĺ� */
/*
#include<stdio.h>
void strncat(char[], char[], int);
int main(void)
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strncat(a, b, 4);
	printf("%s\n", a);
	return 0;
}
void strncat(char s[], char t[], int n)
{
	int i = 0, j;
	while (s[i])
		i++;
	for (j = 0; j < n && t[j];)
		s[i++] = t[j++];
	s[i] = '\0';
}


/* 4.������� */
/* (1) */
/*
#include<stdio.h>
int main()
{
	int src[3][4], res[4][3];
	int i, j;
	printf("������һ��3��4�ľ���\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &src[i][j]);
	printf("ԭ����\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", src[i][j]);	//���ԭ����
			res[j][i] = src[i][j];		//Ԫ��ת��
		}
		putchar('\n');
	}
	printf("ת�þ���\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d\t", res[i][j]);	//���ת�þ���
		putchar('\n');
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
int main()
{
	int num,bits;
	char bin[40];
	int i;
	bits = sizeof(int) * 8;	//��������ռ��λ��
	printf("������һ��������");
	scanf("%d", &num);
	for (i = 0; i < bits; i++)
		bin[i] = (num & (1 << (bits - i - 1))) ? '1' : '0';	
		//������������ÿλ���ַ���ʽ����
	bin[i] = 0;	//����ַ���������
	puts(bin);
	return 0;
}


/* (3) */
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
	char name[10];
	int score;
}stu;

void QuickSort(stu a[],int left,int right)	//�������򣨽���
{
	int i = left, j = right;
	stu key = a[left];	//�ؼ�ֵ
	if (left < right)
	{
		while (i < j)
		{
			while (i<j && a[j].score<=key.score)	//�Ҳ���һ�����ڹؼ�ֵ�ķŵ�ǰ��
				j--;
			a[i] = a[j];
			while (i < j && a[i].score >= key.score)	//�����һ��С�ڹؼ�ֵ�ķŵ�����
				i++;
			a[j] = a[i];
		}
		a[i] = key;	//���ùؼ�ֵ
		QuickSort(a, left, i - 1);	//��߲��ֿ���
		QuickSort(a, i + 1, right);		//�ұ߲��ֿ���
	}
}

stu* Dich(stu a[], int key, int n)	//���ַ������ɼ�
{	//keyΪ������ֵ
	int left = 0, right = n - 1,mid;	//���������м�ֵ
	stu *temp;
	for (mid = (left + right) / 2; left < right && a[mid].score != key;mid=(left+right)/2 )
	{	//�ж��м�ֵ�Ƿ��������ֵ���
		if (a[mid].score < key)		//������ֵ�����м�ֵ���������
			right = mid - 1;	//��ȥ�ұ�
		else	//������ֵС���м�ֵ�������Ҳ�
			left = mid + 1;		//��ȥ���
	}
	if (a[mid].score == key)	//���ҵ�
	{
		temp = a + mid;
		return  temp;	//�����ҵ������ݵ�ַ
	}
	else	//δ�ҵ����ؿ�ָ��
		return NULL;
}

int main()
{
	int n,key;
	stu* head,*dest;
	int i;
	printf("��������Ҫ�����ѧ������n��");
	scanf("%d", &n);
	getchar();
	head = (stu*)malloc(sizeof(stu) * n);
	for (i = 0; i < n; i++)
	{
		printf("������");
		gets(head[i].name);
		printf("�ɼ���");
		scanf("%d", &head[i].score);
		getchar();
	}

	QuickSort(head, 0, n - 1);	//�ɼ�����
	printf("���ɼ��Ӹߵ�������\n");
	printf("����    �ɼ�\n");
	for (i = 0; i < n; i++)
		printf("%-8s%d\n", head[i].name, head[i].score);

	printf("��������ҵĳɼ���");	//���ҳɼ�
	scanf("%d", &key);
	dest=Dich(head, key,n);
	if (dest)	//������ָ�벻Ϊ�����ҵ�����������ͳɼ�
		printf("%-8s%d\n", dest->name, dest->score);
	else	//��Ϊ��ָ����δ�ҵ������δ�ҵ�
		printf("δ�ҵ���\n");

	free(head);
	return 0;
}


/* 5.ѡ��������� */
/* ��1�� */
/*
#include<stdio.h>
#include<string.h>
int strnins(char* s, char* t, int n)
{	//sΪ�������ַ�����tΪ�����ַ�����nΪ����λ��
	int len = strlen(s);
	int i, j;
	char temp[10];
	if (n > len)
	{
		printf("����n�����޷����룡");
		return 0;
	}
	else if (n < 0)
	{
		printf("����n����Ϊ�������޷����룡");
		return 0;
	}
	for (i = n, j = 0; s[i];j++,i++)		//��s������Ԫ�ش�����ʱ����
		temp[j] = s[i];
	temp[j] = 0;
	for (i = n, j = 0; t[j];i++,j++)	//����t�ַ�����s
		s[i] = t[j];
	for (j = 0; temp[j]; i++,j++)	//����ʱ�����е�Ԫ�طŻ�ԭ�ַ���
		s[i] = temp[j];
	s[i] = 0;
	return 1;	//�����ɹ�����1
}

int main()
{
	char s[30], t[10];
	int n,flag;
	printf("�������ַ���s��");
	gets(s);
	printf("�������ַ���t��");
	gets(t);
	printf("������n��");
	scanf("%d", &n);
	flag=strnins(s, t, n);
	if(flag)	//�������ɹ����������ַ���
		puts(s);
	return 0;
}


/* ��2�� */
/*
#include<stdio.h>
#define N 8
int chess[N][N];	//����
int times = 0;	//�������
void QueenSet(int x, int y)	//���ûʺ���
{
	if (QueenCheck(x, y) == 1)	//����ܷ�
	{
		chess[x][y] = 1;	//��������
		if (x + 1 == N)		//��Ϊ���һ��
		{
			printf("�ⷨ%d:\n",++times);	//������1
			for (int i = 0; i < N; i++)		//�����ǰ��
			{
				for (int j = 0; j < N; j++)
				{
					if (chess[i][j])
						printf("��");
					else
						printf("��");
				}
				putchar('\n');
			}
			putchar('\n');
		}
		else	//����Ϊ���һ��
			QueenSet(x+1, 0);	//�ж���һ����η���
	}
	chess[x][y] = 0;	//�����ܷţ��򲻷Żʺ�
						//���Ѿ����һ�ֽ⣬��ȥ���Ļʺ�
	if (y + 1 < N)		//��ǰλ���ұ��ܷ�
		QueenSet(x, y + 1);	//���������ұ߷��ûʺ�
	else
		return;		//���ұ߲��ܷ����򷵻�
}

int QueenCheck(int x, int y)	//��飨x��y�����Ƿ��ܷŻʺ�
{
	int i;
	for (i = 0; i < N; i++)		//ֱ��
		if (chess[i][y] == 1 || chess[x][i] == 1)
			return 0;
	for (i = -N; i < N; i++)	//�Խ���
	{
		if (x + i >= 0 && x + i < N && y + i >= 0 && y + i < N)
			if (chess[x + i][y + i] == 1)
				return 0;
		if (x + i >= 0 && x + i < N && y - i >= 0 && y - i < N)
			if (chess[x + i][y - i] == 1)
				return 0;
	}
	return 1;	//�ܷŷ���1����֮����0
}

int main()
{
	QueenSet(0, 0);	//�ӣ�0,0������ʼ�Żʺ�
	return 0;	
}

/**/
