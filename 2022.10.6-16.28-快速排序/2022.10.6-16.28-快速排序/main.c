#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ����˵����
// a -- �����������
// l -- �������߽�(���磬����ʼλ�ÿ�ʼ������l=0)
// r -- ������ұ߽�(���磬�����ֹ������ĩβ����r=a.length-1)

void Quick_Sort(int a[], int l, int r) {
	if (l < r) {
		int i, j, x;
		i = l;
		j = r;
		x = a[i];
		while(i<j) {
			while (i<j && a[j]>x) {
				j--; // ���������ҵ�һ��С��x����
			}
			if (i < j) {
				a[i++] = a[j]; // ��С��x��ֵ�������
			}
			while (i < j && a[i] < x) {
				i++; // ���������ҵ�һ������x����
			}
			if (i < j) {
				a[j--] = a[i]; // ������x��ֵ�����ұ�
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