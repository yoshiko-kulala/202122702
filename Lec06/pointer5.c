#include <stdio.h>
/* 配列vc[0]にaの値、配列vc[1]にbの値、配列vc[2]にcの値をそれぞれ代入する。 */
void setarray(int *vc,int a,int b,int c)
{
    //配列名は先頭のアドレスなので
    vc[0]=a;
    vc[1]=b;
    vc[2]=c;
}
int main(void)
{
	int i,x,y,z;
	int ary[5] = {0};
	printf("配列に代入する整数を3つ入力してください\n");
	printf("整数1：");	
	scanf("%d",&x);
	printf("整数2：");
	scanf("%d",&y);
	printf("整数3：");
	scanf("%d",&z);
	putchar('\n');
	
	setarray(ary,x,y,z);
	
	for(i=0;i<5;i++)
		printf("ary[%d] = %d\n",i,ary[i]);
	return (0);
}