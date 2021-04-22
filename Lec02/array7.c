#include <stdio.h>
int main(void)
{
	int i,j,k;
	int mx[2][3] = { 0};
	int my[3][2] = { 0};
	int mz[2][2] = { 0};
	
	printf("mx:\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			scanf("%d",&mx[i][j]);
		}
	}
	
	printf("my:\n");
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			scanf("%d",&my[i][j]);
		}
	}

	for(int i=0;i<2;i++){//i,j‚É¶‰E‚³‚ê‚È‚¢‚Æ‚±‚ë‚Í’è”‚Å‘¼‚Íi‚Æj‚ÅŒvŽZ
		for(int j=0;j<2;j++){
			mz[i][j]=mx[i][0]*my[0][j]+mx[i][1]*my[1][j]+mx[i][2]*my[2][j];
		}
	}

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++)
			printf("%3d", mz[i][j]);
		putchar('\n');
	}
return (0);
}