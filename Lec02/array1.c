#include <stdio.h>
int main(void)
{
	int i;
	int vc[5];
	printf("������鐮����5���͂��Ă�������\n");

	for (i = 0; i < 5; i++)
		scanf("%d",vc+i);//�A�h���X�����炷

	for (i = 0; i < 5; i++)
		printf("vc[%d] = %d\n", i, vc[i]);
	
	return (0);
}