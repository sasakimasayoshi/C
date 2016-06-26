#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define BANME 100000000
#define TOKUTEI 10
#define N 20
int so[BANME+1];


int main(){
	int num,mnum,i,j,cur,cnt=0;
	__int64 csum=0;
	__int64 tsum=0;
	char *era;
	time_t a,b;
	a = time(NULL);

	num = 1049999999;

	if ((era = malloc((sizeof(char))*num)) == NULL) 
	{
		printf("��؂��m�ۂł��܂���ł����\n");
		exit(0);
	}

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
				csum += so[cnt]%100;
				printf("���� %9d�Ԗ� : %10d\n",cnt,so[cnt]);
				tsum = csum;
				break;
			}
			else if(cnt==BANME){
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
				break;
			}else if(cnt==TOKUTEI){
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
				printf("���� %9d�Ԗ� : %10d\n",cnt,so[cnt]);
				tsum = csum;
			}else{
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
			}
			cnt++;
		}
	}

	for(cnt=(BANME-N+1);cnt<=BANME;cnt++){
		printf("�@�@ %9d�Ԗ� : %10d\n",cnt,so[cnt]);
	}
	free(era);
	b = time(NULL);
	printf("���s���ԁF%d�b\n",b - a);
	printf("���� %10d�Ԗڂ܂ł̃`�F�b�N�T�� : %I64u\n",TOKUTEI,tsum);
	printf("�w�� %10d�Ԗڂ܂ł̃`�F�b�N�T�� : %I64u\n",BANME,csum);
	return 0;
}