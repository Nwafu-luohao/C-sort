#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 桶排序
// 
// 参数说明
// a -- 待排序数组
// n -- 数组a的长度
// max -- 数组a中最大值的范围

void Bucket_Sort(int a[], int n, int max) {
	int i, j=0;
	int *buckets = (int*)malloc((max+1)*sizeof(int));
	// 将buckets中的所有数据都初始化为0
	memset(buckets, 0, (max+1) * sizeof(int));
	// 1.计数
	for (i = 0; i < n; i++) {
		buckets[a[i]]++;
		printf("%d : %d\n", a[i], buckets[a[i]]);
	}
	printf("\n");
	// 2.排序
	for (i = 0; i < max+1; i++) {
		while ((buckets[i]--) > 0) {
			a[j++] = i;
		}
	}

}



int main() {
	int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
	Bucket_Sort(arr, 10,9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}