#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <readline/readline.h>
#include "mystring.h"

typedef struct __attribute__((__packed__)) data {
	int id, lvl;
	char *text;
	} data;

int comp(const int *p1, const int *p2){
	return *p1 - *p2;
}

/*int *gen_int(int qty){
	int *ptr = malloc(qty*sizeof(int));
	for (int k = 0; k<qty; ++k){
		ptr[k].id = rand();
		ptr[k].lvl = rand();
		ptr[k].text = rand();
	}
}
*/
int *gen_text(int qty){
        char *ptr = malloc(qty*sizeof(char));
        for (int k = 0; k<qty; ++k){
                ptr[k] = rand();
        }
}





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
				text = readline("Enter text: ");
				arr[i].text = calloc(strlen(text)+1, sizeof(char));
				strcpy(arr[i].text, text);
				free(text);
			}

			for (int j=0; j<n; ++j){
				printf("REP %d: %d %d %s\n",j+1, arr[j].id, arr[j].lvl, arr[j].text);
			}

			printf("Choose action:\n1. Insert element\n2. Insert element in sorted array\n3. Delete n elements from array[index]\n4. Sort array\n");
			int res1 = 0;
			scanf("%d", &res1);
			switch (res1){
				case 1:
					//insert()
					break;
				case 2:
					//sort()
					//insert()
					break;
				case 3:
					//del();
					break;
				case 4:
					{printf("Enter the key of sorting\n(1 - Sort by id; 2 - Sort by level; 3 - sort by text)\n");
					int res2 = 0;
					scanf("%d", &res2);
					switch(res2){
						case 1:
							qsort(arr, n, sizeof(data), (int(*) (const void*, const void*)) comp);
							break;
						case 2:
							qsort(arr, n, sizeof(data), (int(*) (const void*, const void*)) comp);
							break;
						case 3:
							qsort(arr, n, sizeof(data), (int(*) (const void*, const void*)) comp);
							break;
						default:
							printf("Enter correct number!");

					}
					break;
				default:
					printf("Enter correct number!");
				}
			}

			for (int z = 0; z<n; ++z){
				printf("REP %d: %d %d %s\n",z+1, arr[z].id, arr[z].lvl, arr[z].text);
			}
			free(arr);
			}
			//scanf("Enter");
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
