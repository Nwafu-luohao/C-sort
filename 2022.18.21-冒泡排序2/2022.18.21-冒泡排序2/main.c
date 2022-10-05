#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort1(int a[], int n) {
	int i, j;
	int flag = 1;
	for (i = n - 1; i > 0; i--) {
		// ���������ݷ�ĩβ
		flag = 1; // ���������Ѿ����
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag = 0; // ��������������û�����
			}
		}
		if (flag) { // �����Ѿ���ɣ��˳�ѭ��
			break;
		}
	}
}

int main() {
	int arr[] = { 9,5,1,6,2,3,0,8,4,7 };
	bubble_sort1(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}