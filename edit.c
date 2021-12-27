#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "chooser.h"
#include "data.h"
#include "sort.h"


data *edit(data *origArr, int *datasize){
	const char choose[] = "-----------------------------------------\n1. Add by index\n2. Add to sorted array\n3. Delete by indexes\n4. Sort\n5. Back\n-----------------------------------------\n";
	int flag = 0;
	while (!flag){
		printf("%s\n", choose);
		int res = chooser(5);
		switch(res){
			case 1:/*
				{printf("Enter index: \n");
				int ind = chooser(*datasize);
				return addInd(origArr, datasize, ind);
				}*/
				break;
			case 2:
				//addSorted(origArr, datasize);
				break;
			case 3:/*
				{printf("Enter start index: \n");
				inds = chooser(*datasize);
				printf("Enter end index: \n");
				inde = chooser(*datasize);
				return delInd(origarr, datasize, inds, inde);
				}break;
				*/
			case 4:
				sort(origArr, datasize);
				break;
			case 5:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
			}
	}
	return NULL;
}
