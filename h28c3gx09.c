//214010 ç≤ÅXñÿê≥ã`

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {

	char dmymoji[] = {"!014bjlquz"};
	char moji[100][100];
	FILE *fp;
	
	int n,i=0,j=0;
	fp=fopen("h28c3gx09Fukugo.data","r");

	while((n=fgetc(fp))!=EOF){
		for(j=0;n != '\n';j++){

			moji[i][j]=n;
			printf("%c",moji[i][j]);
			
		}
		i++;
	}
	printf("%d",moji[0][0]);
	fclose(fp);
}