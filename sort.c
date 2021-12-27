#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>
#include "chooser.h"
#include "data.h"
#include "QuickSort.h"
//#include "sf.h"
int compid (const void *p1, const void *p2){
	const data *ptr1 = (const data *)p1;
	const data *ptr2 = (const data *)p2;
	return (ptr1->id) - (ptr2->id);
}

int complvl(const void *p1, const void *p2){
	const data *ptr1 = (const data *)p1;
	const data *ptr2 = (const data *)p2;
	return (ptr1->lvl) - (ptr2->lvl);
}

int comptext (const void *p1, const void *p2){
	const data *ptr1 = (const data *)p1;
	const data *ptr2 = (const data *)p2;
	return strcmp(ptr1->text, ptr2->text);
}

void sort(data *origArr,int *datasize){
	const char choose[] = "-----------------------------------------\n1. Quick sort\n2. Shell sort\n3. Radix sort\n4. Back\n-----------------------------------------";
	int flag = 0;
	while(!flag){
		printf("%s\n", choose);
		int res = chooser(4);
       		switch(res){
                	case 1:
				{printf("Enter key of sorting:\n1 - Sort by id\n2 - Sort by lvl\n3 - Sort by text\n");
				int key = chooser(3);
				switch(key){
					case 1:
						{
						clock_t start = clock();
						QuickSort(origArr, *datasize, sizeof(data), (int (*)(const void *,const void *)) compid);
						clock_t end = clock();
						double time = ((double)(end - start)) / CLOCKS_PER_SEC;
						printf("Time: %.10lf\n", time);
						}break;

					case 2:	{clock_t start = clock();
						QuickSort(origArr, *datasize, sizeof(data), (int (*)(const void *,const void *)) complvl);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
						break;
						}
					case 3:
						{clock_t start = clock();
						QuickSort(origArr, *datasize, sizeof(data), (int (*)(const void *,const void *)) comptext);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
						break;
						}
					default:
						printf("Try again\n");
						break;
				}
                        	}break;
                	case 2:
				{printf("Enter key of sorting:\n1 - Sort by id\n2 - Sort by lvl\n3 - Sort by text\n");
                                int key = chooser(3);
                                switch(key){
                                        case 1:{clock_t start = clock();
                                                ShellSort(origArr, *datasize, sizeof(data) ,compid);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        case 2:{clock_t start = clock();
                                                ShellSort(origArr, *datasize, sizeof(data), complvl);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        case 3:{
						clock_t start = clock();
                                                ShellSort(origArr, *datasize, sizeof(data), comptext);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        default:
                                                printf("Try again\n");
                                                break;
                                }
                                }
				break;

                	case 3:/*
				{printf("Enter key of sorting:\n1 - Sort by id\n2 - Sort by lvl\n3 - Sort by text\n");
                                int key = chooser(3);
                                switch(key){
                                        case 1:{
						clock_t start = clock();
                                                RadixSort(origArr, *datasize, sizeof(data), compid);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        case 2:{clock_t start = clock();
                                                RadixSort(origArr, *datasize, sizeof(data), complvl);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        case 3:{clock_t start =clock();
                                                RadixSort(origArr, *datasize, sizeof(data) ,comptext);
						clock_t end = clock();
                                                double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                                                printf("Time: %.10lf\n", time);
                                                break;
						}
                                        default:
                                                printf("Try again\n");
                                                break;
                                }*/
				//}
                                break;

                	case 4:
				flag=1;
				break;

                	default:
                        	printf("Something went wrong, try again\n");
				break;
                	}
	}


}
