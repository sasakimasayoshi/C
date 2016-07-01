//214002 大川拓也
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sosu(int a);

unsigned long int so[100000001];
unsigned long int cnt_pr=0;
__int64 csum=0,s;
int main(void)
{
	
	unsigned int sq_i;
	int i_pr=2,br,span,span_kei=0;
	int key1,key2,key3,key_gu,key_ki,gyou,readline,year,mon,day,k,l=0,ans,i=2,j=0,sum_s=0,sum_t=0,flag=0,huku_mod,huku_mod2,w,x,y,z;
	char moji[100][1600],kaku;
	char hukugo[100][1600];

	int cnt[100],cnt_kei=0,cnt2;
	char dmymoji[10] = {"!014bjlquz"};
	char henkan[] = {"#<dR?VrBmD6FyH>J9ExX*tZoL3+wTCi2cN5ksA7e%h8pG$vPKaMIO@Q&S=UnfgYW"};

	
	FILE *fp1;
	FILE *fp2;


	for(i=0;i<100;i++)
	{
		cnt[i]=0;
	}
	printf("h28c3gx09 214002　大川拓也\n");
	printf("復号日入力(yyyy mm dd): ");
	scanf("%d%d%d",&year,&mon,&day);
	printf("暗号文入力start\n");
	
//ファイル読み込み
	if((fp1=fopen("h28c3gx09Fukugo.data","r"))==NULL)
	{
		printf("FILE OPEN ERROR\n");
		exit(1);
	}

	if((fp2=fopen("a.data","w"))==NULL)
	{
		printf("FILE OPEN ERROR\n");
		exit(1);
	}
	i=0;
	j=0;
	while (( readline = fgetc(fp1)) != EOF ) 
	{
		//ダミー文字と一致したら格納しない
		for(k=0;k<10;k++)
		{
			if(dmymoji[k]==readline)
			{
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			moji[i][j]=(char)readline;
			j++;
			cnt[i]++;
			cnt_kei++;
		}
		if(readline=='\n')
		{
			i++; 
			j=0;
			
			
		}
		flag=0;
		
	}
	fclose(fp1);

//第一キーの計算
	//偶数の場合
	if(day%2==0)
	{
		key_gu=year+mon*10000+day*1000000;
		key_gu=sqrt(key_gu);
		key1=(int)sqrt(key_gu)*1.18;
	}
	else
	{
		key_ki=year+day*10000+mon*1000000;
		key_ki=sqrt(key_ki);
		key1=(int)sqrt(key_ki)*1.18;
	}
		

//第二キーの計算
	gyou=key1;
	while(gyou>=i)
	{
		gyou=gyou-i;
	}
	key2=(cnt[gyou-1]-1)/2;

//第三キーの計算
	key3=(cnt_kei-i)/2*key1*key2;

//素数の計算
	
	sosu(key3);

	s=csum/10;
	s=(int)s*10;
	span=(int)csum-s;

	if(span==0)
	{
		span=10;
	}

//復号処理
	j=0;
	for(l=0;l<i;l++)
	{
		k=0;
		while(moji[l][k]!='\n')
		{
			for(j=0;j<100;j++)
			{
				if(henkan[j]==moji[l][k])
				{
					huku_mod=j%16;
					if(k%2==0)
					{
						huku_mod2=huku_mod;
					}
					//元の値に変換し格納
					else
					{
						x=huku_mod2*16+huku_mod;
						while(x>255)
						{
							x=x-256;
						}
						span_kei=span_kei+span;
						s=so[key3-span_kei]/100;
						s=(int)s*100;
						w=(int)so[key3-span_kei]-s;
						y=x-key2-w;

						hukugo[l][k]=y;
						printf("%c",hukugo[l][k]);
					}
				break;
				}
			}
			k++;
		}
		hukugo[l][k]='\n';
		printf("\n");
	}






//ファイル書き出し
	for(l=0;l<i;l++)
	{
	/*	k=0;
		cnt2=(cnt[l]-1)/2;
		while(k<cnt2)
		{*/
			fputs(hukugo[l],fp2);
		//	k++;
	//	}
		//fputs("\n",fp2);
	}
	fclose(fp2);
	printf("%d %d %d %d ",key1,key2,key3,csum);
	printf("%d ",span);
	

return 0;
}	




int sosu(int a){
	int num,mnum,i,j,cur,cnt=0;
	char *era;
//	time_t a,b;
//	a = time(NULL);

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
//チェックサムの計算
	so[0]=0;
	so[1]=2;
	csum += so[1]%100;
	cnt = 2;
	for(i = 0; i < num; i++){
		if(era[i]){
			if(cnt==a){
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
//	b = time(NULL);
//	printf("実行時間：%d秒\n",b - a);
	return 0;
}
	
