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


int main(){
	srand(time(NULL));
	menu(*data.id, *data.lvl, *);
	return 0;
}
