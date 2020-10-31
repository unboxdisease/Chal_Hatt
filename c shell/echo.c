#include "headers.h"
void echo ( char** input ,int size ){
    for(int i=1;i<size-1;i++){
		printf("%s ",input[i]);
	}
	printf("%s ",input[size-1]);
	printf("\n");
	
}