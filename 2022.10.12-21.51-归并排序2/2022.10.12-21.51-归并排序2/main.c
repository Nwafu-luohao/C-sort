#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 归并排序：将一个数组中两个相邻有序空间合并成一个

// 参数说明
// a -- 包含两个有序区间的数组
// start -- 第一个有序区间的起始地址
// mid -- 第一个有序区间的结束地址。也是第二个有序区间的起始地址
// end -- 第二个有序区间的结束地址

void merge(int a[], int start, int mid, int end) {
	int* tmp = (int*)malloc((end - start + 1) * sizeof(int));
	// tmp是汇总2个有序区间的临时区域。
	int i = start; // 第一个有序区的索引
	int j = mid + 1; // 第二个有序区的索引
	int k = 0; // 临时区域的索引
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = a[i++];
	}
	while (j <= end) {
		tmp[k++] = a[j++]; // 将两个有序区间合并
	}
	// 排序后的元素，全部都整合到数组a中
	for (i = 0; i < k; i++) {
		a[start + i] = tmp[i];
	}
	free(tmp);
	tmp = NULL;
}

// 对数组a做若干次合并：数组a的总长度为len，将它分为若干个长度为gap的数组；
// 将“没两个相邻的子数组”进项归并排序
// 
// 参数说明
// a -- 待排序的数组
// len -- 数组的长度
// gap -- 子数组的长度

void merge_groups(int a[], int len, int gap) {
	int i;
	int len_2 = 2 * gap; // 两个相邻子数组的长度
	// 将“每两个相邻的子数组”进行合并排序
	for (i = 0; i + 2 * gap - 1 < len; i += (2 * gap)) {
		merge(a, i, i + gap - 1, i + 2 * gap - 1);
	}
	// 若 i+gap-1 < len-1，则剩余一个组数组没有配对
	// 将该自数字合并到已排序的数组中
	if (i + gap - 1 < len - 1) {
		merge(a, i, i + gap - 1, len - 1);
	}
}

// 归并排序 从下往上
// 参数说明
// a -- 待排序的数组
// b -- 数组长度

void merge_sort_down_to_up(int a[], int len) {
	int n;
	if (a == NULL || a <= 0) {
		return;
	}
	for (n = 1; n < len; n *= 2) {
		merge_groups(a, len, n);
	}
}

int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	merge_sort_down_to_up(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}