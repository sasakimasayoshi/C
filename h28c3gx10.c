//214010 ���X�ؐ��`
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

	printf("Start 214010 ���X�ؐ��`\n");

	n=0;
	sento=saigo=&work[n];

	printf("���O����:");
	scanf("%s",work[n].name);

	cnt=0;

	work[n].next=NULL;
	work[n].before=NULL;

	size =strlen(work[n].name);
	if(size>23){
		printf("������>23�G���[\n");
	}
	//++n;

	while(1){
		printf("\n(991:�擪/992:�Ō�/999:END/994:Dump/995:�o��/996:����SORT�Ґ�/997:�~��SORT�Ґ�/998�ĕҐ�/101-199:�ǉ�/200-299:�ύX/300-399:�폜)�����ԍ�����:");
		scanf("%d",&no);

		if(no==991 || no==992 || no==999 || no==994 || no==995 || no==996 || no==997 || no==998 || no>=101 && no<400){
			if(no==999){
				break;
			}

			++n;

			switch(no){
					 case 991:
						printf("���O����:");
						scanf("%s",work[n].name);
						size =strlen(work[n].name);
						if(size>23){
							printf("������>23�G���[\n");
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
						printf("���O����:");
						scanf("%s",work[n].name);
						size =strlen(work[n].name);
						if(size>23){
							printf("������>23�G���[\n");
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
					printf("�����ԍ��G���[:%d\n",no);
				}
				else if(no>(cnt+100)){
					printf("�����ԍ��G���[:%d\n",no);
				}
				else{
					addno=no%100;
					printf("���O����:");
					scanf("%s",work[n].name);
					size =strlen(work[n].name);
					if(size>23){
						printf("������>23�G���[\n");
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
			printf("�����ԍ��G���[:%d\n",no);
		}
	}

	printf("�O����o��\n");

	for(trace=sento;trace!=NULL;trace=trace->next){
		printf("%s ",trace->name);
	}

	printf("\n\n��납��o��\n");

	for(trace=saigo;trace!=NULL;trace=trace->before){
		printf("%s ",trace->name);
	}
	return 0;
}


