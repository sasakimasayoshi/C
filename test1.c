#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BANME 100000000
int b[BANME];
int *a=NULL;
int cntmax=BANME;
void set_f(int i, int max)
{
  int j;
  for (j = 2; j <= (max / i); j++) a[i * j] = 2;
  return;
}

int main(void)
{

	a = (int *)malloc(sizeof(int) * 100000000);
  if( a == NULL ){
    printf( "メモリ確保に失敗しました\n" );
    return -1;
  }
	/*if ((a = (unsigned char *)malloc(table_bytes * sizeof(char))) == NULL) 
	{
		printf("ﾒﾓﾘを確保できませんでした｡\n");
		exit(0);
	}*/
  int max=2000, i,cnt=0;
	for(i=0;i<2000;i++)
	{
		a[i]=1;
	}

  //printf("最大値："); scanf("%d", &max);
	
  for (i = 2; i <= max; i++) {

    if (a[i] != 2) { a[i] = 1; set_f(i, max); }
  }
  for (i = 2; i <= max; i++) {
    if (a[i] == 1){

			b[cnt]=a[i];
			cnt++;
		} //printf("%d  ", i);
  }
  printf("%d\n",cnt);
  return 0;
} 