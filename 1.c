#define _CRT_SECURE_NO_WARNINGS		//VS��������ԭ����Ҫ��ӵĺ궨��
/* 1��Դ����Ĵ��� */
/*
#include<stdio.h>
#define PI 3.14159	//ȥ���ֺţ�
void main( void )
{
   int f ;
   short p, k ;
   double c , r , s ;
   short newint;	//task3�������newint

// for task 1
   printf("Input  Fahrenheit:" ) ;
   scanf("%d", &f ) ;	//scanf�βα����&
   c = 1.0*5/9*(f-32) ;	//��֤5/9���Ϊ������Ҫ��1.0
   printf( " \n %d (F) = %.2f (C)\n\n ", f, c ) ;

// for task 2 
	printf("input the radius r:");
	scanf("%lf", &r);	//double���͸�ʽ�����Ϊ%lf
	s = PI*r*r;
	printf("\nThe acreage is %.2f\n\n",s);	//ȥ��printf�βα��е�&

// for task 3 
	printf("input hex int k, p :");
	scanf("%hx %hx", &k, &p );
	newint = (p&0xff00)|(k&0xff00)>>8;	//��<<��Ϊ>> ��Ϊ���ֽ�
	printf("new int = %hx\n\n",newint);

}


/* 2��Դ�����޸��滻�� */
/*
#include<stdio.h>

void main( )
{
   int a, b;
   printf("Input two integers:");
   scanf("%d %d",&a,&b);
   //a=a+b;	//����һ
   //b=a-b;
   //a=a-b;
   a=a^b; //������
   b=a^b;
   a=a^b;
   printf("\na=%d,b=%d",a,b);
}


/* 3���������� */
/* (1)  */
/*
#include<stdio.h>

int main()
{
	char c;
	printf("Input a char:\n");
	c=getchar();
	c=(c>='A'&&c<='Z')?c+32:c;		//��Ϊ��д��ĸ�任ΪСд��ĸ�����򲻱�
	printf("%c\n",c);
	return 0;
}

/* (2) */
/*
#include<stdio.h>
#include<math.h>

int main()
{
	unsigned short x, m, n;
	printf("����x��16���ƣ���m��0~15����n��1~16-m��:\n");
	scanf("%hx%hd%hd", &x, &m, &n);
	if(m>=0&&m<=15 && n>=1&& m<=16-m)	//�ж�m��n��ֵ�Ƿ��ں���Χ��
	{
		x = x >> m;
		x = x << (16 - n);
		printf("result=%hx\n",x);	//������
	}
	else
		printf("�������\n");		//�����������ʾ���˳�
	return 0;
}


/* (3) */
/*
#include<stdio.h>
int main()
{
	char temp;	//��ʱ���������ַ�
	int i,flag=1;
	unsigned long bin;	//��ʱ���������1��0
	unsigned long savenum=0;	//���������IP��ַ
	unsigned long byte[4] = { 0xff000000,0x00ff0000,0x0000ff00,0x000000ff };
	printf("������32λIP��ַ: ");
	for(i=0;i<32&&flag;i++)	//����32λIP��ַ
	{
		temp=getchar();		//����32λIP��ַ
		if(temp=='1'||temp=='0')	//�Ϸ����ж�
		{
			bin=temp=='1'?1:0;	//���������1��0
			savenum|=bin<<(31-i);		//����IPÿһ���ֵ�����
		}
		else
		{
			flag = 0;	//����Ƿ��ַ����˳�ѭ��
			printf("\n�������\n");	//�зǷ���������ʾ�������
		}
	}
	if (flag)
	{
		printf("\nIP Adress:");
		for (i = 0; i < 4; i++)
			printf("%lu.", (byte[i] & savenum) >> (3 - i) * 8);
			//���IP��ַÿһ���ֵ�����
		printf("\b \n");
	}		
	return 0;
}
/**/