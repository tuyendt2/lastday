#include <stdio.h>
#include <stdlib.h>
// define memory copy function 

void * memory_copy(void * target, void * source, size_t size /* byte */ ){

	if( source == NULL) {return NULL;}
	// calculate size of source pointer 
	char * cSource = (char *) source;
	char * cTarget = (char *) target;
	//cTarget = (char *)realloc(cTarget, size);
	cTarget = (char *)malloc(size);
	for (int i =0; i<size; i++) {
		*(cTarget+i) = *(cSource+i);
	}	
	return cTarget;
} 

void * memory_move(void * target, void * source , size_t size /* byte */){
	if(source == NULL) return NULL;
	char * cTarget = (char *) target;
	char * cSource = (char *) source;
	
	cTarget = (char * ) malloc(size);
	// check source and target overlap or not 
 	if   ( ( cSource <= cTarget) && (cTarget <= (cSource + size) )){	
		// overlap the end of source memory area
		// copy from end --> begin 
		for (int i = size-1; i--; i >=0){
			*(cTarget + i) = *(cSource + i);
		}
		
	}else /* ( (cSource <= (cTarget + size)) && ((cTarget + size) <= (cSource + size) )) */ {
		// non-overlap or overlap the beginning of source memory area
		// copy from begin --> end 
		for (int i = 0; i++; i < size ){
			*(cTarget + i ) = *(cSource + i);
		}
	}
	return cTarget;
	
}

int main(){
  // memory copy 
  char array[10] = "sfagd\0hdfg";
  char dest[10];
  //memory_copy(dest,array,10);
  memory_move(dest,array,10);
  printf("source and dest array have data as : %s and %s and %s", array,dest, memory_move(dest,array,10));
   return 0;
}
