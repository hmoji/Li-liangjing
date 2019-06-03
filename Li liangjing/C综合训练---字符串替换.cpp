#include"stdafx.h"
#include<stdio.h>
#include<string.h>
int main() {
	FILE *file1,*work;
	FILE *file2;
	file1 = fopen("filein.txt", "r");
	if (file1 == NULL) {
		printf("文件不存在！");
		return -1;
	}
	file2 = fopen("fileout.txt", "w");
	char ori[10], rep[10];
	scanf("%s", ori);
	scanf("%s", rep);
	char n;
	int flag=0;
	while (file1 != NULL) {
		n = fgetc(file1);
		if (n == ori[0]) {
			work = file1;
			for (int i = 1; i < strlen(ori); i++) {
				if (fgetc(work) != ori[i]) {
					flag = 1;
				}
			}
		}
		else {
			flag = 1;
		}
		if (flag == 1) {
			fputc(n, file2);
		}
		else {
			for (int i = 0; i < strlen(rep); i++) {
				fputc(rep[i], file2);
			}
			fseek(file1, strlen(ori) - 1, 1);
		}
		flag = 0;
	}
	fclose(file1);
	fclose(file2);
}