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
	int count2 = 1;//ͳ�Ƶ�����
	fl = fopen(c, "r");
	scanf("%s", s);
	if (!strcmp(s, "-c")){
		goto case1;
	}
	else {
		goto case2;
	}
case1:
	while ((i = fgetc(fl)) != EOF)
		count1++;
	printf("�ַ�����%d", count1);
	fclose(fl);
	return 0;
case2:
	char s1[1024]="";
	fgets(s1, 1000, fl);
	for (int a = 0; a<strlen(s1); a++){
		if (s1[a] == ' ' || s1[a] == ',' || s1[a] == '\t'){
			if (s1[a + 1] != ' ' && s1[a + 1] != ',' && s1[a + 1] != '\t')
				count2++;
		}
	}
	if (s1[strlen(s1)] == ' ' || s1[strlen(s1)] == ',' || s1[strlen(s1)] == '\t')
		count2--;
	printf("��������%d\n", count2);
	fclose(fl);
	return 0;
}