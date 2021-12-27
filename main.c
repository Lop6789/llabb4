#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "chooser.h"
#include "data.h"
#include "inp.h"
#include "output.h"
#include "edit.h"
#include "sort.h"
#include "QuickSort.h"
void fullfree(data *origArr, int datasize){
	for (int i = 0; i<datasize; i++){
		free(origArr[i].text);
	}
}


int main(){
	srand(time(NULL));
	//const char announcement[] = "Enter a number to select an action: \n";
	const char choose[] = "-----------------------------------------\n1. Input Data\n2. Output Data\n3. Process Data\n4. Time\n5. Quit\n-----------------------------------------\n";
	int flag = 0;
	data *origArr = NULL;
	int datasize = 0;
	//data *editArr = NULL;

	while (!flag){
		printf("%s\n",choose);
		int res = chooser(5);

		switch(res){
			case 1:
				origArr = inp(origArr, &datasize);
				break;
			case 2:
				output(origArr, &datasize);
				break;
			case 3:
				edit(origArr, &datasize);
				break;
			case 4:	{
				printf("Enter max qty of tests: \n");
				int qty = Silentchooser();
				for (int i=0; i<qty; ++i){
					datasize=pow(2,i);
					origArr = genData(origArr, &datasize);
					clock_t start = clock();
					ShellSort(origArr, datasize, sizeof(data), compid);
					clock_t end = clock();
					double time = ((double)(end - start))/CLOCKS_PER_SEC;
					printf("N: %d | Time: %.10lf\n", datasize, time);
					fullfree(origArr, datasize);
					free(origArr);
				}
				printf("NEXT SORTING -------------------------------------------------------------------\n");
				for (int i=0; i<qty; ++i){
                                        datasize=pow(2,i);
                                        origArr = genData(origArr, &datasize);
                                        printf("N: %d \n", datasize);
                                        sort(origArr, &datasize);
                                        fullfree(origArr, datasize);
                                        free(origArr);
                                }

				}
				break;
			case 5:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;

		}

	}
	fullfree(origArr, datasize);
	free(origArr);
	//free(editData);
	return 0;
}
