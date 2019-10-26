#include "paixu.h"
#include "malloc.h"  

void tongguoshijian(leixing list[], leixing sorted[], int N, int length);

void adjustHeap(int yuansu, int j, leixing shuzidingyi[]);

void insertionSort(leixing *a, int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		leixing jiaohuan = *(a + i);
		for (j = i; j > 0 && *(a + j - 1) > jiaohuan; --j) {
			*(a + j) = *(a + j - 1);
		}
		*(a + j) = jiaohuan;
	}
}

void quickSort(leixing *v, int zuobian, int youbian) {
	if (zuobian >= youbian) {
		return;
	}
	int z = zuobian;
	int j = youbian;
	leixing yaoshi = v[zuobian];

	while (z < j) {
		while (z < j && yaoshi <= v[j]) {
			j--;
		}
		v[z] = v[j];
		while (z < j && yaoshi >= v[z]) {
			z++;
		}
		v[j] = v[z];
	}

	v[z] = yaoshi;
	quickSort(v, zuobian, z - 1);
	quickSort(v, z + 1, youbian);
}


void mergeSort(leixing list[], int E) {
	leixing * kuozhan = (leixing *)malloc(sizeof(leixing) * E);
	int changdu = 1; 
	while (changdu < E) {
		tongguoshijian(list, kuozhan, E, changdu); 
		changdu *= 2;
		tongguoshijian(kuozhan, list, E, changdu); 
		changdu *= 2;
	}
}

void tongguoshijian(leixing liebiao[], leixing sorted[], int S, int changdu) {
	int e, j, g, p = 0;

	for (e = 0; e < S; e += changdu * 2) {
		if (e + changdu * 2 < S) {
			j = e;
			g = j + changdu;
			while (j < e + changdu && g < e + 2 * changdu) {
				if (liebiao[j] > liebiao[g]) {
					sorted[j++] = liebiao[g++];
				}
				else {
					sorted[j++] = liebiao[j++];
				}
			}
			while (j < e + changdu) {
				sorted[j++] = liebiao[j++];
			}
			while (g < e + 2 * changdu) {
				sorted[j++] = liebiao[g++];
			}
		}
		else if (e + changdu < S) {
			j = e;
			g = j + changdu;
			while (j < e + changdu && g < S) {
				if (liebiao[j] > liebiao[g]) {
					sorted[j++] = liebiao[g++];
				}
				else {
					sorted[j++] = liebiao[j++];
				}
			}
			while (j < e + changdu) {
				sorted[j++] = liebiao[j++];
			}
			while (g < S) {
				sorted[j++] = liebiao[g++];
			}
		}
		else {
			j = e;
			while (j < S) {
				sorted[j++] = liebiao[j++];
			}
		}
	}
}


void adjustHeap(int yuansu1, int j, leixing shuzidingyi[]) {
	leixing temp = shuzidingyi[yuansu1];
	for (int k = yuansu1 * 2 + 1; k < j; k = k * 2 + 1) {
	
		if (k + 1 < j && shuzidingyi[k] < shuzidingyi[k + 1]) {
			k++;
		}
		
		if (shuzidingyi[k] > temp) {
			shuzidingyi[yuansu1] = shuzidingyi[k];
			yuansu1 = k;
		}
		else
			break;
	}

	shuzidingyi[yuansu1] = temp;
}


void heapSort(leixing *shuzidingyi, int nums) {

	for (int i = nums / 2 - 1; i >= 0; i--) {
	
		adjustHeap(i, nums, shuzidingyi);
	}
	
	for (int j = nums - 1; j > 0; j--) {
	
		leixing jiaohuan = shuzidingyi[0];
		shuzidingyi[0] = shuzidingyi[j];
		shuzidingyi[j] = jiaohuan;

		adjustHeap(0, j, shuzidingyi);
	}
}
