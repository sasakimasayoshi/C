//214010 佐々木正義
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX 100

struct NODE{
	char name[24];
	struct NODE *next;
	struct NODE *before;
}work[MAX];


main()
{
	struct NODE *sento,*saigo,*trace;
	int n,no,cnt=0,size,i,addno;

	printf("Start 214010 佐々木正義\n");

	n=0;
	sento=saigo=&work[n];

	printf("名前入力:");
	scanf("%s",work[n].name);

	cnt=0;

	work[n].next=NULL;
	work[n].before=NULL;

	size =strlen(work[n].name);
	if(size>23){
		printf("文字数>23エラー\n");
	}
	//++n;

	while(1){
		printf("\n(991:先頭/992:最後/999:END/994:Dump/995:出力/996:昇順SORT編成/997:降順SORT編成/998再編成/101-199:追加/200-299:変更/300-399:削除)処理番号入力:");
		scanf("%d",&no);

		if(no==991 || no==992 || no==999 || no==994 || no==995 || no==996 || no==997 || no==998 || no>=101 && no<400){
			if(no==999){
				break;
			}

			++n;

			switch(no){
					 case 991:
						printf("名前入力:");
						scanf("%s",work[n].name);
						size =strlen(work[n].name);
						if(size>23){
							printf("文字数>23エラー\n");
						}
						else{
							//++n;
							work[n].next=sento;
							sento->before=&work[n];
							sento=&work[n];
							work[n].before=NULL;
							cnt++;
						}
						break;

				case 992:
						printf("名前入力:");
						scanf("%s",work[n].name);
						size =strlen(work[n].name);
						if(size>23){
							printf("文字数>23エラー\n");
						}
						else{
							//++n;
							saigo->next=&work[n];
							work[n].before=saigo;
							saigo=saigo->next;
							work[n].next=NULL;
							cnt++;
						}
						break;

				default:
					break;
			}

			if(no>=100 && no<200){
				if(no==100){
					printf("処理番号エラー:%d\n",no);
				}
				else if(no>(cnt+100)){
					printf("処理番号エラー:%d\n",no);
				}
				else{
					addno=no%100;
					printf("名前入力:");
					scanf("%s",work[n].name);
					size =strlen(work[n].name);
					if(size>23){
						printf("文字数>23エラー\n");
					}
					else{
						work[n].next=&work[n];
						work[n].before=&work[n-1];
						for(i=cnt;addno<i;i--){
							work[i].before=&work[i-1];
						}
						saigo->before=&work[n+1];

						//saigo->next=&work[n];
						//work[n].next=saigo;
						//saigo=saigo->next;
						work[n].next=NULL;
						cnt++;
					}
				}
			}
		}
		else{
			printf("処理番号エラー:%d\n",no);
		}
	}

	printf("前から出力\n");

	for(trace=sento;trace!=NULL;trace=trace->next){
		printf("%s ",trace->name);
	}

	printf("\n\n後ろから出力\n");

	for(trace=saigo;trace!=NULL;trace=trace->before){
		printf("%s ",trace->name);
	}
	return 0;
}


