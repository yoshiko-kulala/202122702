#include <stdio.h>

void mul(int ma[2][3],int mb[3][2],int mc[2][2]){
    for(int i=0;i<2;i++){//計算
		for(int j=0;j<2;j++){
			for(int k=0;k<3;k++){
				mc[i][j]+=ma[i][k]*mb[k][j];
			}
		}
	}
}

int main(void)
{
	int mx[2][3] = { 0};
	int my[3][2] = { 0};
	int mz[2][2] = { 0};
	
	printf("mx:\n");
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&mx[i][j]);
		}
	}
	
	printf("my:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&my[i][j]);
		}
	}

	mul(mx,my,mz);

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++)
			printf("%3d", mz[i][j]);
		putchar('\n');
	}
    return (0);
}