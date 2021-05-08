// WordCount.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fl=NULL;
	char c[20] = "D:\input.txt";
	char s[2];//接收-c or -w
	int i;//读取当前字符
	int count1 = 0;//统计字符数
	int count2 = 1;//统计单词数
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
	printf("字符数：%d", count1);
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
	printf("单词数：%d\n", count2);
	fclose(fl);
	return 0;
}