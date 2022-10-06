#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 参数说明：
// a -- 待排序的数组
// l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
// r -- 数组的右边界(例如，排序截止到数组末尾，则r=a.length-1)

void Quick_Sort(int a[], int l, int r) {
	if (l < r) {
		int i, j, x;
		i = l;
		j = r;
		x = a[i];
		while(i<j) {
			while (i<j && a[j]>x) {
				j--; // 从右向左找第一个小于x的数
			}
			if (i < j) {
				a[i++] = a[j]; // 将小于x的值放在左边
			}
			while (i < j && a[i] < x) {
				i++; // 从左向右找第一个大于x的数
			}
			if (i < j) {
				a[j--] = a[i]; // 将大于x的值放在右边
			}
		}
		a[i] = x;
		Quick_Sort(a, l, i - 1);
		Quick_Sort(a, i+1, r);
	}
}

int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	Quick_Sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}