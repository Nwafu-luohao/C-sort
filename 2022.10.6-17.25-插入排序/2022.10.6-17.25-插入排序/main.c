#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 参数说明：
// a -- 待排序的数组
// n -- 数组的长度

void Insert_Sort(int a[], int n) {
	int i, j, k;
	for (i = 1; i < n; i++) {
		// 为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
		for (j = i - 1; j >= 0; j--) {
			if (a[j] < a[i]) {
				break;
			}
		}
		// 如果找到了一个合适的位置
		if (j != i - 1) {
			// 将比a[i]大的数据向后移
			int temp = a[i];
			for (k = i - 1; k > j; k--) {
				a[k + 1] = a[k];
			}
			// 将a[i]放到正确的位置上
			a[k + 1] = temp;
		}
	}
}

int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	Insert_Sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}