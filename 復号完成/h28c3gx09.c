//214010 佐々木正義

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BANME 100000000
int so[BANME+1];
__int64 csum=0,simo2;


int sosu(int s);
int main() {

	
	char henkan[] = {"#<dR?VrBmD6FyH>J9ExX*tZoL3+wTCi2cN5ksA7e%h8pG$vPKaMIO@Q&S=UnfgYW"};
	char dmymoji[10] = {"!014bjlquz"};
	char moji[100][1600];
	int hukugo[100][1600];
	char c;
	char *fname = "h28c3gx09.ans";
	FILE *fp;
	FILE *fp1;
	clock_t start;
	
	int n,i=0,j=0,cnt=0,dmycnt=0,flag=0,d,m,y,hiduke=0,sq,key1,key2,key3,gyo=0,hencnt=0,code,a=0,b=0,span=0,spantotal=0,huku,moto;

	start = clock();

	printf("h28c3gx09 214010 佐々木正義\n");

	printf("復号日入力(yyyy mm dd):");
	scanf("%d%d%d",&y,&m,&d);

	if(d%2==0){//偶数
		hiduke = (y+m*10000+d*1000000);
		sq=sqrt(hiduke);
		sq=sqrt(sq);
		key1=sq*1.18;
	}
	else//奇数
	{
		hiduke = (y+d*10000+m*1000000);
		sq=sqrt(hiduke);
		sq=sqrt(sq);
		key1=sq*1.18;
	}
	for(gyo=key1;gyo>26;){
		gyo-=26;
	}
	

	printf("暗号文入力start\n");
	if((fp = fopen("h28c3gx09Fukugo.data", "r")) == NULL ){
		fprintf(stderr,"入力ファイルオープンエラー\n");
		exit(EXIT_FAILURE);
	}

	while((n=fgetc(fp))!=EOF){
		for(dmycnt=0;dmycnt<10;dmycnt++){
			if(dmymoji[dmycnt]==n){
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
		c=moji[gyo-1][j];
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

	printf("素数計算start %d番目まで\n",key3);

	sosu(key3);//素数呼び出し

	printf("復号start\n");


	simo2=csum/10;
	simo2=(int)simo2*10;
	span=(int)csum-simo2;

	if(span==0)
	{
		span=10;
	}

	i=0;
	j=0;
	flag=1;
	while(i<26){
		if(moji[i][j]=='\n'){
			hukugo[a][b]='\n';
			j=0;
			i++;
			a++;
			b=0;
		}
		else{
			for(hencnt=0;hencnt<64;hencnt++){
				if(henkan[hencnt]==moji[i][j]){
					if(flag==1){
						code=hencnt%16;
						code=code*16;
					}
					else if(flag==0){
						code+=(hencnt%16);
						while(code>255){
							code-=256;
						}
						spantotal=spantotal+span;
						simo2=so[key3-spantotal]/100;
						simo2=(int)simo2*100;
						huku=(int)so[key3-spantotal]-simo2;
						moto=code-key2-huku;
						hukugo[a][b]=moto;
						b++;
						flag=2;
					}
					flag--;
					break;
				}
			}
			j++;
		}
	}
	
	printf("原文出力start\n");

	fp1 = fopen( fname, "w" );
	if( fp1 == NULL ){
    printf( "%sファイルが開けません\n", fname );
    return -1;
  }
	for( i=0,j=0; i<26; i++){
		while(1){
    	fputc( hukugo[i][j], fp1 );
			j++;
			if(hukugo[i][j]=='\n'){
				fputc( hukugo[i][j], fp1 );
				j=0;
				break;
			}
		}
  }
	printf("復号処理全体：%.3f秒\n",(double)(clock()-start)/(double)CLOCKS_PER_SEC);

	fclose(fp);
	fclose(fp1);
	printf("h28c3gx09 END");
}

//素数計算
int sosu(int s){
	int num,mnum,i,j,cur,cnt=0;
	char *era;
	clock_t start;
	start = clock();

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
				break;
			}else{
				so[cnt]=i+i+3;
				csum += so[cnt]%100;
			}
			cnt++;
		}
	}

	free(era);
	printf("%d番目:%d\n",s,so[cnt]);
	printf("素数処理時間：%.3f秒\n",(double)(clock()-start)/(double)CLOCKS_PER_SEC);
	printf("素数チェックサム : %I64u\n",csum);

	return 0;
}
