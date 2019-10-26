#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "paixu.h"



#define zuida_zhi 200000
void zhengshu(leixing * data);
void fudian(leixing * data);
void zifu(leixing * data);

int main() {
	clock_t kaishi, tingzhi;
	leixing shuzu[zuida_zhi];
	srand(time(NULL));

	zhengshu(shuzu);
	kaishi = clock();
	insertionSort(shuzu, zuida_zhi);
	tingzhi = clock();
	printf("; -)GUJIAKAI 20161795");
		printf("\n________________________________\n");
	printf("|insertionSort time is %lums\t|\r\n", tingzhi - kaishi);
	
	zhengshu(shuzu);
	kaishi = clock();
	quickSort(shuzu, 0, zuida_zhi - 1);
	tingzhi = clock();
	printf("|QuickSort time is %lums\t\t|\r\n", tingzhi - kaishi);
	
	zhengshu(shuzu);
	kaishi = clock();
	mergeSort(shuzu, zuida_zhi);
	tingzhi = clock();
	printf("|MergeSort time is %lums\t\t|\r\n ", tingzhi - kaishi);
	
	zhengshu(shuzu);
	kaishi = clock();
	heapSort(shuzu, zuida_zhi);
	tingzhi = clock();
	printf("|HeapSort time is %lums\t\t|\r\n", tingzhi - kaishi);
	printf("|________________________________\n");
	system("pause");
	return 0;
	
}


void zhengshu(leixing * data) {
	memset(data, 0, sizeof(leixing) * zuida_zhi);
	for (int i = 0; i < zuida_zhi; i++) {
		*(data + i) = rand() % 10000;
	}
}

void fudian(leixing * data) {
	memset(data, 0, sizeof(leixing) * zuida_zhi);
	float temp;
	for (int i = 0; i < zuida_zhi; i++) {
		temp = (float)(rand() % 100000) / 100;
		*(data + i) = temp;
	}
}

void zifu(leixing * data) {
	memset(data, 0, sizeof(leixing) * zuida_zhi);
	char metachar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	for (int i = 0; i < zuida_zhi; i++) {
		*(data + i) = metachar[rand() % 62];;
	}
}
