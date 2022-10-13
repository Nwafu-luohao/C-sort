#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// Ͱ����
// 
// ����˵��
// a -- ����������
// n -- ����a�ĳ���
// max -- ����a�����ֵ�ķ�Χ

void Bucket_Sort(int a[], int n, int max) {
	int i, j=0;
	int *buckets = (int*)malloc((max+1)*sizeof(int));
	// ��buckets�е��������ݶ���ʼ��Ϊ0
	memset(buckets, 0, (max+1) * sizeof(int));
	// 1.����
	for (i = 0; i < n; i++) {
		buckets[a[i]]++;
		printf("%d : %d\n", a[i], buckets[a[i]]);
	}
	printf("\n");
	// 2.����
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