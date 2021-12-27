#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "chooser.h"
#include "data.h"
#include "mystr.h"

data *readKey(data *origArr, int *datasize){
		printf("Enter quantity of reports: ");
		*datasize = Silentchooser();

		origArr = calloc((*datasize)+1, sizeof(data));
		for (int i = 0; i<*datasize; ++i){
			printf("\nReport %d\n", i+1);
			printf("Enter id: ");
			origArr[i].id = Silentchooser();
			printf("Enter level (1-debug, 2-info, 3-warn, 4-error, 5-fatal): ");
			origArr[i].lvl = chooser(5);
			//printf("Enter text: ");
			origArr[i].text = readline("Enter text:");
			printf("TEXTTTT: %s\n", origArr[i].text);
		}
	return origArr;
	}

data *genData(data *origArr, int *datasize){
		//printf("Enter quantity of reports:");
		//*datasize = Silentchooser();
		origArr = calloc(*datasize, sizeof(data));
		int n = rand()%25+5;
		for (int i=0; i<*datasize; ++i){
			origArr[i].id = rand()%100;
			origArr[i].lvl = 1 + rand()%5;
			origArr[i].text = calloc(n+1 , sizeof(char));
			for(int j=0; j<n; j++){
				origArr[i].text[j] = 65 + rand()%(90-65+1);
			}
			//(origArr[i].text)[n] = '\0';
		}
	return origArr;
}

data *inp(data *origArr, int *datasize){
	//const char announcement[] = "Enter a number to select an action: \n";
	const char choose[] = "-----------------------------------------\n1. Read from keyboard\n2. Read from file\n3. Generate random data\n4. Back\n-----------------------------------------\n";

	int flag = 0;

	while (!flag){
		printf("%s\n", choose);
		int res = chooser(4);

		switch(res){
                        case 1:
				return readKey(origArr, datasize);
                                break;
                        case 2:
                               //readFile(origArr);
                                break;
                        case 3:{
				printf("Enter datasize: \n");
				*datasize = Silentchooser();
                                return genData(origArr, datasize);
                                break;}
                        case 4:
                                flag=1;
                                break;
                        default:
                                printf("Something went wrong, try again\n");
                                break;

                }
	}
	return NULL;
}
