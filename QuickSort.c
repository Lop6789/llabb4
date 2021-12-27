#include <stdio.h>
#include <stdlib.h>
#include "chooser.h"
#include "data.h"
#include <string.h>
/*int compstr(const void *p1, const void *p2){
		const data *ptr1 = (const data *)p1;
		const data *ptr2 = (const data *)p2;
		return srtlen(()prt1->id) - str
}
*/
/*
int len (int ptr){
	int n = 0;
	while (ptr>0){
		n++;
		ptr /= 10;
	}
	return n;
}

void *max(void *origArr, size_t datasize, size_t size, int (*compar)(const void *, const void*)){
	void *mxm = calloc(1, size);
	for (int i=0; i<datasize; ++i){
		if(compar(origArr+i*size, mxm)>0) memcpy(mxm, origArr+i*size, size);
	}
	return mxm;
}
*/
void swap (void *p1, void *p2, size_t size){
	void *temp = malloc(size);
	memcpy (temp, p1, size);
	memcpy (p1, p2, size);
	memcpy (p2, temp, size);
	free(temp);
}


void QuickSort(void *origArr, size_t datasize, size_t size,
				int (*compar)(const void *, const void*)){
	if (datasize-1<=0) return;

	int l = 0, r = datasize-1, x = (l+r)/2;
	void *piv = origArr+x*size;

	do{
		while (compar(origArr+l*size, piv)<0){
			l++;
		}

		while(compar(origArr+r*size, piv)>0){
			r--;
		}

		if (l<=r){
			swap(origArr+l*size, origArr+r*size, size);
			l++;
			r--;
		}
	}while (l<=r);
	if (r>0) QuickSort (origArr, r+1, size, compar);
	if (l<datasize) QuickSort (origArr+l*size, datasize-l, size, compar);
}

void ShellSort(void *origArr, size_t datasize, size_t size,
                                int (*compar)(const void *,const void*)){
	for (int gap = datasize/2; gap>0; gap /= 2){
		for (int i = gap; i<datasize; i++){
			for (int j = i - gap; j>=0 && compar(origArr+j*size, origArr+(j+gap)*size)>0; j-=gap){
				swap(origArr+j*size, origArr+(j+gap)*size, size);
			}
		}
	}

}
/*
void RadixSort(int *origArr, size_t datasize, size_t size,
                                int (*compar)(const void *,const void*)){
	int max_el = max(origArr, datasize, size, compar);
	int qty = len(max_el, size, compar);
	int del = 1, r = 0;
	int container[10][10], container_c[10];
	for (p=0; p<qty; p++){
		for (int i=0; i<10; i++){
			container[i] = 0;
		}
		for (int j = 0; j<datasize; j++){
			r = (origArr[j]/del)%10;
			container[r][container_c[r]] = origArr[i];
			container_c[r]++;
		}
		int j=0;
		for (int k=0; k<10; k++){
			for (int m = 0; m<container_c[k]; m++){
				a[i] = container[k][j];
				j++;
			}
		}
		del*=10;
	}

}
*/
