#ifndef UNTITLED_SORT_H
#define UNTITLED_SORT_H

struct rectangle {
	float kuangdu;
	float gaodu;
};

#define leixing struct rectangle

void insertionSort(leixing *a, int n);

void quickSort(leixing *a, int left, int right);

void  mergeSort(leixing list[], int N);

void  heapSort(leixing *  inNums, int nums);



#endif //UNTITLED_SORT_H