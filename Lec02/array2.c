#include <stdio.h>
int main(void)
{
	int i;
	int vc[5];
	printf("代入する整数を5個入力してください\n");

	for (i = 4; i > -1; i--)//順番逆に
		scanf("%d",vc+i);//アドレスをずらす

	for (i = 0; i < 5; i++)
		printf("vc[%d] = %d\n", i, vc[i]);
	
	return (0);
}