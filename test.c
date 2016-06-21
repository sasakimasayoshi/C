#include <stdio.h>
#include <time.h>

#define PNMAX 2100000000 /* 求める素数はPNMAXより小さくなくてはならない */
#define SQRT_PNMAX 45826 /*PNMAXの平方根を切り上げで*/
#define NUMBER 100000000 /*NUMBER番目の素数を求める*/
#define DIVISION 30 /* DIVISIONごとにわける*/
#define PRIMES 8 /* {1,7,11,13,17,19,23,29} */
const char numbertable[PRIMES] = {1,7,11,13,17,19,23,29};

char results[PNMAX/DIVISION][PRIMES]={0};


int del_prime(int n){ //ふるいにかける。==1ならば素数でない。
unsigned int i,j;
for(i=2;i*n<=PNMAX;i++){
for(j=0;j<PRIMES;j++){
if ( ((i*n)%DIVISION) == numbertable[j] ){
results[(i*n)/DIVISION][j]=1;
break;
}
}
}
return 0;
}

int chk_prime(unsigned int n){//素数なら1を返し、素数でなければ0を返す。1からDIVISIONまで用
unsigned int i;
if(n<2){return 0;}
if(n==2){return 1;}
for(i=2;i<n;i++){
if(n%i==0){
return 0;
}
}
return 1;
}

int main(){
unsigned int i,j,count=3;
clock_t start;
start=clock();

for(i=7;i<= DIVISION;i++){ 
if(chk_prime(i) == 1){
del_prime(i);
count++;
}
}
for( i=DIVISION+1;i<SQRT_PNMAX;i+=2 ){ //DIVISION%2 ==0以外のときはi++にかえる
for(j=0;j<PRIMES;j++){
if( ((i%DIVISION) == numbertable[j])&&
(results[i/DIVISION][j]==0)){
del_prime(i);
}
}
}
for(i=1;i<PNMAX/DIVISION;i++){
for(j=0;j<PRIMES;j++){
if(results[i][j]==0){
count++;
if(count==NUMBER){
printf("the number is : %d\nthe time is : %f(sec)\n",i*DIVISION+numbertable[j],(double)(clock() - start) / CLOCKS_PER_SEC);
return 0;
}
}
}
}
return 0;
}