#define _CRT_SECURE_NO_WARNINGS	

/* 1.�ļ����͵ĳ�����֤�� */
/*
#include <stdio.h>
int main(void)
{
	short a = 0x253f, b = 0x7b7d;	//9535��31613
	char ch;
	FILE* fp1, * fp2;
	fp1 = fopen("d:\\abc1.bin", "wb+");
	fp2 = fopen("d:\\abc2.txt", "w+");
	fwrite(&a, sizeof(char), 1, fp1);
	fwrite(&b, sizeof(char), 1, fp1);
	fprintf(fp2, "%d %d", a, b);

	rewind(fp1); rewind(fp2);
	//puts("fgetc(fp1)");
	while ((ch = fgetc(fp1)) != EOF)
		putchar(ch);
	putchar('\n');

	//puts("fgetc(fp2)");
	while ((ch = fgetc(fp2)) != EOF)
		putchar(ch);
	putchar('\n');

	fclose(fp1);
	fclose(fp2);
	return 0;
}


/* 2.Դ�����޸��滻�� */
/* ��1�� */
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;
	if (argc != 3) {	//����ֵ+1
		printf("Arguments error!\n");
		exit(-1);
	}
	if (strcmp(argv[1], "type"))
	{
		printf("Instruction Error!");
		exit(-1);
	}
	if ((fp = fopen(argv[2], "r")) == NULL) {        // fp ָ�� filename
		printf("Can't open %s file!\n", argv[2]);
		exit(-1);
	}
	while ((ch = fgetc(fp)) != EOF)          // ��filename�ж��ַ�(������ֵ�����ţ�
		putchar(ch);                  // ����ʾ����д�ַ�
	fclose(fp);                      // �ر�filename
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;
	int i=2;
	if (argc < 3) {	//����ֵ+1
		printf("Arguments error!\n");
		exit(-1);
	}

	if (strcmp(argv[1], "type"))
	{
		printf("Instruction Error!");
		exit(-1);
	}

	if ((fp = fopen(argv[2], "r")) == NULL) {        // fp ָ�� filename
		printf("Can't open %s file!\n", argv[2]);
		exit(-1);
	}
	printf("File argv[2]:\n");
	while ((ch = fgetc(fp)) != EOF)          // ��filename�ж��ַ�(������ֵ�����ţ�
		putchar(ch);                  // ����ʾ����д�ַ�

	if (argc > 3)
	{
		for (i = 3; i < argc; i++)
		{
			freopen(argv[i], "r", fp);
			if (!fp)
			{
				printf("Arguments error!\n");
				exit(-1);
			}
			printf("\n\nFile argv[i]:\n",i);
			while ((ch = fgetc(fp)) != EOF)          // ��filename�ж��ַ�(������ֵ�����ţ�
				putchar(ch);                  // ����ʾ����д�ַ�
		}
	}

	fclose(fp);                      // �ر�filename
	return 0;
}

/* 3.�������� */
/* ��1�� */
/*
#include<stdio.h>
#include<stdlib.h>

void upstr(char* s)
{
	int flag = 1;
	while (*s)
	{
		if (*s == ' ')
			flag = 1;
		else if(flag&& *s >= 'a' && *s <= 'z')
		{
			*s -= 0x20;
			flag = 0;
		}
		s++;
	}
}

int main()
{
	char s[100];
	FILE* fp;
	int i;
	printf("������һ��Ӣ�ľ��ӣ�\n");
	gets(s);
	upstr(s);
	puts(s);
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf("File Open Error!");
		exit(-1);
	}
	for (i = 0; s[i]; i++)
	{
		fputc(s[i],fp);
	}
	puts("OK!");


	return 0;
}



/**/