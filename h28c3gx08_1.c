//214010 ���X�ؐ��`

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

	printf( "�f��h28c3gx08.c �f���v�ZStart\n");

	//���Ԍv��
	clock_t start, finish;
	start = clock();
	int csum=0;
	int tsum=0;
	printf( "�w��%d�Ԗڂ܂� ����%d�Ԗ� %d��\n",BANME,TOKUTEI,N);

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
				printf("���� %9d�Ԗ� : %10d\n",cnt,so[cnt]);
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
		printf("�@�@ %9d�Ԗ� : %10d\n",cnt,so[cnt]);
	}
	finish = clock();//���Ԍv���I��
	printf("���s����: %lf[s]\n",((double)(finish - start)/CLOCKS_PER_SEC));
	printf("���� %9d�Ԗڂ܂ł̃`�F�b�N�T�� : %d\n",TOKUTEI,tsum);
	printf("�w�� %9d�Ԗڂ܂ł̃`�F�b�N�T�� : %d\n",BANME,csum);

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
