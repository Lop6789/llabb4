#include <stdio.h>
#include <stdlib.h>

int mystrlen(char* str){
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void *mymemcpy(void *dest, void *src, int n){
        char *source = src;
        char *destination = dest;
        for (int p=0; p<n; ++p){
                destination[p] = source[p];
        }
        return dest;
}

char *myreadline()
{
    char buf[81] = {0};  // BUFFSIZE
    char *res = NULL;
    int len = 0;
    int n = 0;

   // printf("Enter string: ");
    do {
	n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = mystrlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            mymemcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *mystrtok(char *string, char *delim){
	static char *now = NULL;
	if(string){
		now = string;
	}
	if (!now || !*now){
		return NULL;
	}
	char *result = now;

	while(*now && *now!=*delim){
		++now;
	}

	if(*now){
		*now=0;
		do{
			++now;
		}while(*now==*delim);
	}

	return result;


}
