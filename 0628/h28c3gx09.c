//214010 佐々木正義

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BANME 100000000
int so[BANME+1];

int sosu(int s);
int main() {

	
	char henkan[] = {"#<dR?VrBmD6FyH>J9ExX*tZoL3+wTCi2cN5ksA7e%h8pG$vPKaMIO@Q&S=UnfgYW"};
	char dmymoji[10] = {"!014bjlquz"};
	char moji[100][1600];
	int huku[100][1600];
	char c;
	FILE *fp;
	
	int n,i=0,j=0,cnt=0,a=0,flag=0,d,m,y,h=0,sq,key1,key2,key3,g=0,x=0,z,w=1,aa,bb,cc;

	printf("h28c3gx09 214010 佐々木正義\n");

	printf("複合日入力(yyyy mm dd):");
	scanf("%d%d%d",&d,&m,&y);

	if(y%2==0){//偶数
		h = (d+m*10000+y*1000000);
		sq=sqrt(h);
		sq=sqrt(sq);
		key1=sq*1.18;
		
	}
	else//奇数
	{
		h = (d+y*10000+m*1000000);
		sq=sqrt(h);
		sq=sqrt(sq);
		key1=sq*1.18;
	}
	for(g=key1;g>26;){
		g-=26;
	}

	printf("暗号文入力start\n");
	if((fp = fopen("h28c3gx09Fukugo.data", "r")) == NULL ){
		fprintf(stderr,"入力ファイルオープンエラー\n");
		exit(EXIT_FAILURE);
	}

	while((n=fgetc(fp))!=EOF){
		for(a=0;a<10;a++){
			if(dmymoji[a]==n){
				flag=1;
				break;
			}
			else{
				flag=0;
			}
		}
		if(flag==0){
			moji[i][j]=(char)n;
			j++;
			cnt++;
		}
		if(n=='\n'){
			j=0;
			i++;
			
		}
	}

	j=0;
	key2=0;
	while(1){
		c=moji[g-1][j];
		if(c=='\n'){
			break;
		}
		j++;
		key2++;
	}
	key2/=2;
	cnt-=26;
	cnt/=2;
	
	key3= cnt*key2*key1;
	
	printf("key1:%d  key2:%d  key3:%d\n",key1,key2,key3);
	sosu(key3);

	i=0;
	j=0;
	aa=0;
	bb=0;
	while(i<26){
		if(moji[i][j]=='\n'){
			j=0;
			i++;
			aa++;
			bb=0;
		}
		else{
			for(x=0;x<64;x++){
				if(henkan[x]==moji[i][j]){
					if(w==1){
						z=x%16;
						z=z*16;
						//printf("%d",z);
					}
					else if(w==0){
						z+=(x%16);
						//printf("%d",z);
						if(z>255){
							z-=256;
						}
						huku[aa][bb]=z;
						bb++;
						w=2;
					}
					w--;
					break;
				}
			}
			j++;
		}
	}
	
	

	fclose(fp);
}

//素数計算
int sosu(int s){
	int num,mnum,i,j,cur,cnt=0;
	__int64 csum=0;
	char *era;
	time_t a,b;
	a = time(NULL);

	num = 1049999999;

	if ((era = malloc((sizeof(char))*num)) == NULL) 
	{
		printf("ﾒﾓﾘを確保できませんでした｡\n");
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
			if(cnt==s){
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
				printf("特定 %9d番目 : %10d\n",cnt,so[cnt]);
				break;
			}else{
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
			}
			cnt++;
		}
	}

	free(era);
	b = time(NULL);
	printf("実行時間：%d秒\n",b - a);
	printf("特定 %10d番目までのチェックサム : %I64u\n",s,csum);
	return 0;
}


