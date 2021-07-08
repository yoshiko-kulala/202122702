#include <stdio.h>
int main(void)
{
	char str[7];	/* 文字列を格納する配列 */
	
	str[0] = 'S';
	str[1] = 't';
	str[2] = 'r';
	str[3] = 'i';
	str[4] = 'n';
	str[5] = 'g';
	str[6] = '\0';

	printf("文字列strは%sです。\n", str);	/* 表示 */
	
	return (0);
}