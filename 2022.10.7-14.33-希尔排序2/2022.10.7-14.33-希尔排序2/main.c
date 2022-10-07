#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ��ϣ�������е��������������
// ����˵����
// a -- �����������
// n -- ����ĳ���
// i -- �����ʼλ��
// gap -- ��Ĳ���

// ���� ��i��ʼ�������gap���ȵ�����ȡ�� ����ɵġ�

void group_sort(int a[], int n,int i,int gap) {
	int j;
	for (j = i + gap; j < n; j += gap) {
		// ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
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

// ϣ������

// ����˵��
// a -- �����������
// n -- ����ĳ���

void shell_sort2(int a[], int n) {
	int i, gap;
	// gapΪ������ÿ�μ�Ϊԭ����һ�롣
	for (gap = n / 2; gap > 0; gap /= 2) {
		// ��gap�����飬��ÿһ�����ֱ�Ӳ�������
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