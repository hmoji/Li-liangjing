#include"stdafx.h"
#include<stdio.h>
#include<string.h>
int main() {
	FILE *file1;
	FILE *file2;
	file1 = fopen("filein.txt", "r");
	if (file1 == NULL) {
		printf("�ļ������ڣ�");
		return -1;
	}
	file2 = fopen("fileout.txt", "w");
	char ori[10], rep[10];
	scanf("%s", ori);
	scanf("%s", rep);

}