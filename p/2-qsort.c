#include <stdio.h>
#include <stdlib.h>


int Compare(const void *a,const void *b){
	int c = *(int *)a;
	int d = *(int *)b;
	if(c<d){
		return -1;
	}
	else if(c==d){
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	int num;
	int arr[10000];
	int idx=0;
	while(scanf("%d",&num)!=EOF){
		arr[idx]=num;
		idx++;
	}
	qsort((void *)arr,idx,sizeof(int),Compare);
	for(int i=0;i<idx;i++){
		printf("%d\n",arr[i]);
	}
	
}
