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
		// 将最大的数据放末尾
		flag = 1; // 假设排序还已经完成
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag = 0; // 发生交换，排序没有完成
			}
		}
		if (flag) { // 排序已经完成，退出循环
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