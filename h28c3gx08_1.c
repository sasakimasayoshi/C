//214010 佐々木正義

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BANME 100000
#define TOKUTEI 10
#define N 5
#include <math.h>
int so[BANME];

int main() {

	printf( "素数h28c3gx08.c 素数計算Start\n");

	//時間計測
	clock_t start, finish;
	start = clock();
	int csum=0;
	int tsum=0;
	printf( "指定%d番目まで 特定%d番目 %d件\n",BANME,TOKUTEI,N);

	int n, cnt = 1;
	so[0]=0;

	for( n = 1; cnt <= BANME;n++  )
	{
		if( isPrimeNum( n ) )
		{
			//printf("%d\n",n);
			//printf("%d  %d\n",cnt,n);
			if(cnt==TOKUTEI)
			{
				so[cnt]=n;
				printf("特定 %9d番目 : %10d\n",cnt,so[cnt]);
				tsum = csum + n%100;
				csum += n%100;
				cnt++;
				
			}
			else
			{
				so[cnt]=n;
				csum =csum + n%100;
				cnt++;
				
			}
		}
	}
	//csum = tsum+csum;
	for(cnt=(BANME-N+1);cnt<=BANME;cnt++)
	{
		printf("　　 %9d番目 : %10d\n",cnt,so[cnt]);
	}
	finish = clock();//時間計測終了
	printf("実行時間: %lf[s]\n",((double)(finish - start)/CLOCKS_PER_SEC));
	printf("特定 %9d番目までのチェックサム : %d\n",TOKUTEI,tsum);
	printf("指定 %9d番目までのチェックサム : %d\n",BANME,csum);

}

int isPrimeNum( int x )
{
	int n;

	if( x == 2 ) return 1;
	if( x < 2 || x % 2 == 0 )
	{
		return 0;
	}
	if(x!=5 && x%5==0) return 0;
	if(x!=7 && x%7==0) return 0;
	for( n = 3; n <= sqrt((double)x); n += 2 )
	{
		if( x % n == 0 )
		{
			return 0;
		}
	}

	return 1;
}
