#include <stdio.h>
int main(void)
{
	int i;
	int vc[5];
	printf("‘ã“ü‚·‚é®”‚ğ5ŒÂ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

	for (i = 4; i > -1; i--)//‡”Ô‹t‚É
		scanf("%d",vc+i);//ƒAƒhƒŒƒX‚ğ‚¸‚ç‚·

	for (i = 0; i < 5; i++)
		printf("vc[%d] = %d\n", i, vc[i]);
	
	return (0);
}