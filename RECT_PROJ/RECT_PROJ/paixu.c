#include "paixu.h"
#include "malloc.h" 

void mergePass(leixing list[], leixing sorted[], int N, int length);

void adjustHeap(int param1, int j, leixing inNums[]);

int compare_rect(leixing a, leixing b);

void insertionSort(leixing *a, int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		leixing jiaohuan = *(a + i);
		for (j = i; j > 0 && compare_rect(*(a + j - 1), jiaohuan) > 0; --j) {
			*(a + j) = *(a + j - 1);
		}
		*(a + j) = jiaohuan;
	}
}

void quickSort(leixing *a, int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left;
	int j = right;
	leixing yaoshi = a[left];

	while (i < j) {
		while (i < j && compare_rect(a[j], yaoshi) >= 0) {
			j--;
		}
		a[i] = a[j];
		while (i < j && compare_rect(a[i], yaoshi) <= 0) {
			i++;
		}
		a[j] = a[i];
	}

	a[i] = yaoshi;
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}


void mergeSort(leixing liebiao[], int N) {
	leixing * extra = (leixing*)malloc(sizeof(leixing) * N);
	int length = 1;
	while (length < N) {
		mergePass(liebiao, extra, N, length);
		length *= 2;
		mergePass(extra, liebiao, N, length); 
		length *= 2;
	}
}

void mergePass(leixing liebiao[], leixing paixuguo[], int N, int changdu) {
	int i, j, k, p = 0;

	for (i = 0; i < N; i += changdu * 2) {
		if (i + changdu * 2 < N) {
			j = i;
			k = j + changdu;
			while (j < i + changdu && k < i + 2 * changdu) {
				if (compare_rect(liebiao[j], liebiao[k]) > 0) {
					paixuguo[p++] = liebiao[k++];
				}
				else {
					paixuguo[p++] = liebiao[j++];
				}
			}
			while (j < i + changdu) {
				paixuguo[p++] = liebiao[j++];
			}
			while (k < i + 2 * changdu) {
				paixuguo[p++] = liebiao[k++];
			}
		}
		else if (i + changdu < N) {
			j = i;
			k = j + changdu;
			while (j < i + changdu && k < N) {
				if (compare_rect(liebiao[j], liebiao[k])  > 0) {
					paixuguo[p++] = liebiao[k++];
				}
				else {
					paixuguo[p++] = liebiao[j++];
				}
			}
			while (j < i + changdu) {
				paixuguo[p++] = liebiao[j++];
			}
			while (k < N) {
				paixuguo[p++] = liebiao[k++];
			}
		}
		else {
			j = i;
			while (j < N) {
				paixuguo[p++] = liebiao[j++];
			}
		}
	}
}



void adjustHeap(int shuxin1, int j, leixing shuziji[]) {
	leixing jiaohuan = shuziji[shuxin1];
	for (int k = shuxin1 * 2 + 1; k < j; k = k * 2 + 1) {
	
		if (k + 1 < j && compare_rect(shuziji[k], shuziji[k + 1]) < 0) {
			k++;
		}
		
		if (compare_rect(shuziji[k], jiaohuan) > 0) {
			shuziji[shuxin1] = shuziji[k];
			shuxin1 = k;
		}
		else
			break;
	}

	shuziji[shuxin1] = jiaohuan;
}


void heapSort(leixing *shuziji, int shuzi) {

	for (int i = shuzi / 2 - 1; i >= 0; i--) {
	
		adjustHeap(i, shuzi, shuziji);
	}
	
	for (int j = shuzi - 1; j > 0; j--) {
	
		leixing jiaohuan = shuziji[0];
		shuziji[0] = shuziji[j];
		shuziji[j] = jiaohuan;

		adjustHeap(0, j, shuziji);
	}
}

int compare_rect(leixing a, leixing b) {
	return a.kuangdu * a.gaodu - b.kuangdu * b.gaodu;
}

