#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 对希尔排序中单个数组进行排序
// 参数说明：
// a -- 待排序的数组
// n -- 数组的长度
// i -- 组的起始位置
// gap -- 组的步长

// 组是 从i开始，将相隔gap长度的数都取出 所组成的。

void group_sort(int a[], int n,int i,int gap) {
	int j;
	for (j = i + gap; j < n; j += gap) {
		// 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
		if (a[j] < a[j - gap]) {
			int tmp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k] > tmp) {
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap] = tmp;
		}
	}
}

// 希尔排序

// 参数说明
// a -- 待排序的数组
// n -- 数组的长度

void shell_sort2(int a[], int n) {
	int i, gap;
	// gap为步长，每次减为原来的一半。
	for (gap = n / 2; gap > 0; gap /= 2) {
		// 共gap个数组，对每一组进行直接插入排序
		for (i = 0; i < gap; i++) {
			group_sort(a, n, i, gap);
		}
	}
}

int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	shell_sort2(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}