#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BANME 50000000
#define TOKUTEI 10
#define N 20
int so[BANME+1];


int main(){

	int num,mnum,i,j,cur,cnt=0;
	long csum=0;
	long tsum=0;
	char *era;
	time_t a,b;
	a = time(NULL);

	num = 1049999999;
	era = malloc((sizeof(char))*num);

	for(i = 0; i < num; i++){
		era[i] = 1;
	}
	mnum = 32403;
	for(i = 0; i < mnum; i++){
		if(era[i]){
			cur = i+i+3;
			for(j = cur+i; j < num; j += cur){
				era[j] = 0;
			}
		}
	}
	so[0]=0;
	so[1]=2;
	csum += so[1]%100;
	cnt = 2;
	for(i = 0; i < num; i++){
		if(era[i]){
			if(cnt==BANME && BANME==TOKUTEI){
				so[cnt]=i+i+3;
				csum =csum + so[cnt]%100;
				printf("特定 %9d番目 : %10d\n",cnt,so[cnt]);
				tsum = csum;
				break;
			}
			else if(cnt==BANME){
				so[cnt]=i+i+3;
				csum =csum + so[cnt]%100;
				break;
			}else if(cnt==TOKUTEI){
				so[cnt]=i+i+3;
				csum =csum + so[cnt]%100;
				printf("特定 %9d番目 : %10d\n",cnt,so[cnt]);
				tsum = csum;
			}else{
				so[cnt]=i+i+3;
				csum =csum + so[cnt]%100;
			}
			cnt++;
		}
	}

	for(cnt=(BANME-N+1);cnt<=BANME;cnt++){
		printf("　　 %9d番目 : %10d\n",cnt,so[cnt]);
	}
	free(era);
	b = time(NULL);
	printf("実行時間：%d秒\n",b - a);
	printf("特定 %10ld番目までのチェックサム : %d\n",TOKUTEI,tsum);
	printf("指定 %10ld番目までのチェックサム : %d\n",BANME,csum);
	return 0;
}