#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "paixu.h"


#define zuida_zhi 35000

void szsj(leixing *data);

int main() {
	clock_t kaishi, jieshu;
	leixing shuzu[zuida_zhi];
	srand(time(NULL));

	szsj(shuzu);
	kaishi = clock();
	insertionSort(shuzu, zuida_zhi);
	jieshu = clock();
	printf("; -)GUJIAKAI 20161795");
	printf("\n________________________________\n");
	printf("|insertionSort time is %lums\t|\r\n", jieshu - kaishi);

	szsj(shuzu);
	kaishi = clock();
	quickSort(shuzu, 0, zuida_zhi - 1);
	jieshu = clock();
	printf("|QuickSort time is %lums\t\t|\r\n",jieshu - kaishi);

	szsj(shuzu);
	kaishi = clock();
	mergeSort(shuzu, zuida_zhi);
	jieshu = clock();
	printf("|MergeSort time is %lums\t\t|\r\n ", jieshu - kaishi);

	szsj(shuzu);
	kaishi = clock();
	heapSort(shuzu, zuida_zhi);
	jieshu = clock();
	printf("|HeapSort time is %lums\t\t|\r\n", jieshu - kaishi);
	printf("|________________________________\n");
	system("pause");



	return 0;
}


void szsj(leixing *shuju) {
	memset(shuju, 0, sizeof(leixing) * zuida_zhi);
	for (int i = 0; i < zuida_zhi; i++) {
		(shuju + i)->gaodu = rand() % 1000;
		(shuju + i)->kuangdu = rand() % 1000;
	}
}
