#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ����˵����
// a -- �����������
// n -- ����ĳ���

void Insert_Sort(int a[], int n) {
	int i, j, k;
	for (i = 1; i < n; i++) {
		// Ϊa[i]��ǰ���a[0...i-1]������������һ�����ʵ�λ��
		for (j = i - 1; j >= 0; j--) {
			if (a[j] < a[i]) {
				break;
			}
		}
		// ����ҵ���һ�����ʵ�λ��
		if (j != i - 1) {
			// ����a[i]������������
			int temp = a[i];
			for (k = i - 1; k > j; k--) {
				a[k + 1] = a[k];
			}
			// ��a[i]�ŵ���ȷ��λ����
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