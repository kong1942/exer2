#include <string.h>
#include <stdio.h>
#include <ctype.h>

long long int Pow(int num,int power){
	long long result=1;
	if(power==0){
		return 1;
	}
	for(int i=0;i<power;i++){
		result = result*num;
	}
	return result;
}
long long int Hash(char *string){
	int len =strlen(string);
	long long int res=0;
	int idx=0;
	for(int i=len-1;i>=0;i--){
		res = res + string[idx] *Pow(65,i);
		idx++;
	}
	return res;
}
int main(){
	char line[1000];
	while(scanf("%s",line)!=EOF){
		printf("%lld\n",Hash(line));
	}
}

