#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char string[100];
	int i;
	while(scanf("%s",string)!=EOF){
		int len = strlen(string);
		for(i=0;i<len/2;i++){
			if(string[i]!=string[len-i-1]){
				break;
			}
		}
		if(i>=len/2){
			printf("%s\n",string);
		}
	}
	
}
