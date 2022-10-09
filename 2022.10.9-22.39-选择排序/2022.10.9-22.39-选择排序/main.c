#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 选择排序
// 参数说明
// a -- 待排序的数组
// n -- 数组的长度
void select_sort(int a[], int n) {
	int i; // 有序区的末尾位置
	int j; // 无序区的起始位置
	int min;

	for (i = 0; i < n; i++) {
		min = i;
		// 找出“a[i+1]...a[n]”之间的最小元素，并赋值给min。
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		// 若 min != i, 则交换 a[i] 和 a[min]。
		// 交换之后，保证了a[0]...a[i]之间的元素是有序的。
		if (min != i) {
			swap(&a[i], &a[min]);
		}
	}
}


int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	select_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}