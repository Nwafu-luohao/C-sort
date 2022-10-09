#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ѡ������
// ����˵��
// a -- �����������
// n -- ����ĳ���
void select_sort(int a[], int n) {
	int i; // ��������ĩβλ��
	int j; // ����������ʼλ��
	int min;

	for (i = 0; i < n; i++) {
		min = i;
		// �ҳ���a[i+1]...a[n]��֮�����СԪ�أ�����ֵ��min��
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		// �� min != i, �򽻻� a[i] �� a[min]��
		// ����֮�󣬱�֤��a[0]...a[i]֮���Ԫ��������ġ�
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