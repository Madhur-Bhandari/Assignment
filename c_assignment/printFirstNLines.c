#include <stdio.h>
#include <stdlib.h>

char ** firstnumlines(FILE * inputfp, unsigned int num){
int max=0;
char ** headbuff = (char **) calloc(num, sizeof(char *));

/**
while(fgets(*headbuff,255,inputfp)){
if(num==0){
break;
}
//fscanf(inputfp,"%c",&headbuff[max]);
num--;
}
*/
for(unsigned int i = 0; i < num; i++){
headbuff[i] = (char *) calloc(255, sizeof(char));
fgets(headbuff[i],255,inputfp);
}
return headbuff;
}



int main() {
FILE * inputfp = fopen("input.txt", "r");

int num=10;
char ** firstlines = firstnumlines(inputfp,num);

for(int i=0;i<num;i++){
	if(firstlines[i] != NULL){
		printf("%s",firstlines[i]);
	}
}
printf("\n");
fclose(inputfp);
free(firstlines);
}
