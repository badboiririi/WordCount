// WordCount.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fl=NULL;
	char c[20] = "D:\input.txt";
	char s[2];//����-c or -w
	int i;//��ȡ��ǰ�ַ�
	int count1 = 0;//ͳ���ַ���
	int count2 = 1;//ͳ�Ƶ��������ı���Ϊ�����Ȼ��һ�������������ֵΪ1
	fl = fopen(c, "r");
	scanf("%s", s);
	if (!strcmp(s, "-c")){
		goto case1;
	}
	else {
		goto case2;
	}
case1:
	while ((i = fgetc(fl)) != EOF)//ͨ�������ȡ�ַ����ķ���ͳ�������ַ�������
		count1++;
	printf("�ַ�����%d", count1);
	fclose(fl);
	return 0;
case2:
	char s1[1024]="";
	fgets(s1, 1000, fl);
	for (int a = 0; a<strlen(s1); a++){
		if (s1[a] == ' ' || s1[a] == ',' || s1[a] == '\t'){//�����ȡ���ո񣬶��Ż��Ʊ����ʼ�ж�
			if (s1[a + 1] != ' ' && s1[a + 1] != ',' && s1[a + 1] != '\t')//������ǿո񣬶��Ż��Ʊ����������ո�ֿ�������������
				count2++;//�������ͼ�1
		}
	}
	if (s1[strlen(s1)] == ' ' || s1[strlen(s1)] == ',' || s1[strlen(s1)] == '\t')//����ı�������ǿո񣬶��Ż��Ʊ���������ĵ��������ʵ�ʵĶ�1
		count2--;//�����Ҫ����1
	printf("��������%d\n", count2);
	fclose(fl);
	return 0;
}