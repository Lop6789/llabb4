#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "chooser.h"
#include "data.h"

void print(data *arr, int *datasize){
	for (int i=0; i<*datasize; i++){
		printf("Report_%d: | id: %d | lvl: %d | text: %s |\n", i+1, arr[i].id, arr[i].lvl, arr[i].text);
	}
}





data *output(data *arr, int *datasize){
	const char choose[] = "-----------------------------------------\n1. Print to console\n2. Write to file\n3. Back\n-----------------------------------------\n";
	int flag = 0;

	while (!flag){
		printf("%s\n", choose);
		int res = chooser(3);

		switch(res){
			case 1:
				print(arr, datasize);
				break;
			case 2:
				//return writeFile();
				break;
			case 3:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
		}
	}
	return NULL;

}
