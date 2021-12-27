#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <readline/readline.h>
#include "mystr.h"

typedef struct __attribute__((__packed__)) data {
	int id, lvl;
	char *text;
	} data;

int comp(const int *p1, const int *p2){
	return *p1-*p2;
}
/*
int *gen_int(int qty){
	int *ptr = malloc(qty*sizeof(int));
	for (int k = 0; k<qty; ++k){
		ptr[k] = rand();
	}
}

int *gen_text(int qty){
        char *ptr = malloc(qty*sizeof(char));
        for (int k = 0; k<qty; ++k){
                ptr[k] = rand();
        }
}

*/



void menu(){
	printf("Enter a number to select an action: \n");
	printf("1. Read from keyboard\n2. Read from file\n3. Generate random data\n4. Quit\n");
	int res = 0;
	scanf("%d", &res);

	switch(res){
		case 1:
			{data *arr = NULL;
			printf("Enter quantity of reports: ");
			int n = 0;
			scanf("%d", &n);
			printf("\n");
			arr = calloc(n+1, sizeof(data));
			for (int i = 0; i<n; ++i){
				printf("\nReport %d\n", i+1);
				printf("Enter id: ");
				scanf("%d", &(arr[i].id));
				printf("Enter level (1-debug, 2-info, 3-warn, 4-error, 5-fatal): ");
				scanf("%d", &(arr[i].lvl));
				char *text = NULL;
				text = get_str();
				arr[i].text = calloc(strlen(text)+1, sizeof(char));
				strcpy(arr[i].text, text);
				free(text);
			}

			for (int j=0; j<n; ++j){
				printf("REP %d: %d %d %s\n",j+1, arr[j].id, arr[j].lvl, arr[j].text);
			}

			qsort(arr, n, sizeof(data), (int(*) (const void*, const void*)) comp);

			printf("Sorted array:\n");
			for (int z = 0; z<n; ++z){
				printf("REP %d: %d %d %s\n",z+1, arr[z].id, arr[z].lvl, arr[z].text);
			}
			free(arr);
			}
			break;
		case 2:
			//readfile();
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			printf("Error, check you input and enter correct number!\n");
	}
}


int main(){
	srand(time(NULL));
	menu();
	return 0;
}
