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
	int count2 = 1;//统计单词数，文本不为空则必然有一个单词所以设初值为1
	fl = fopen(c, "r");
	scanf("%s", s);
	if (!strcmp(s, "-c")){
		goto case1;
	}
	else {
		goto case2;
	}
case1:
	while ((i = fgetc(fl)) != EOF)//通过逐个读取字符数的方法统计所有字符的数量
		count1++;
	printf("字符数：%d", count1);
	fclose(fl);
	return 0;
case2:
	char s1[1024]="";
	fgets(s1, 1000, fl);
	for (int a = 0; a<strlen(s1); a++){
		if (s1[a] == ' ' || s1[a] == ',' || s1[a] == '\t'){//如果读取到空格，逗号或制表符则开始判断
			if (s1[a + 1] != ' ' && s1[a + 1] != ',' && s1[a + 1] != '\t')//如果不是空格，逗号或制表符相连，则空格分开的是两个单词
				count2++;//单词数就加1
		}
	}
	if (s1[strlen(s1)] == ' ' || s1[strlen(s1)] == ',' || s1[strlen(s1)] == '\t')//如果文本的最后是空格，逗号或制表符，则计算的单词数会比实际的多1
		count2--;//因此需要减掉1
	printf("单词数：%d\n", count2);
	fclose(fl);
	return 0;
}