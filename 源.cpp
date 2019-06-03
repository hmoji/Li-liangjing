#include"stdafx.h"
#include<stdio.h>
typedef struct {
	char name[10];
	int bri;
	char num[20];
}fri;
fri *p;
void sort(int l, int r) {//¿ìËÙÅÅÐò
	if (l >= r)
		return;
	int i = l, j = r;
	fri key = p[l];
	while (i < j) {
		while (i < j&&key.bri <= p[j].bri) {
			j--;
		}
		p[i] = p[j];
		while (i < j&&key.bri >= p[i].bri) {
			i++;
		}
		p[j] = p[i];
	}
	p[i] = key;
	sort(l, i - 1);
	sort(i + 1, r);
}
int main() {
	int n;
	printf("input n:");
	scanf("%d", &n);
	p = (fri*)malloc(n * sizeof(fri));
	for (int i = 0; i < n; i++) {
		printf("Input the name,birthday,number of the %d friend:", i + 1);
		scanf("%s", p[i].name);
		scanf("%d", &p[i].bri);
		scanf("%s", p[i].num);
	}
	sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%s %d %s\n", p[i].name, p[i].bri, p[i].num);
	}
}