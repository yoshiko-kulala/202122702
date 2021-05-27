/* 符号無し整数の任意のビットを操作 */
#include <stdio.h>
/* 整数ｘ中のセットされたビット数を返す */
int count_bits(unsigned x)
{
	int count = 0;
	
	while (x) {
		if(x & 1U) count++;
		x >>= 1;
	}
	
	return (count);
}
/* unsigned型のビット数を返す */
int int_bits(void)
{
	return (count_bits(~0U));
}
/* unsigned型のビット内容を表示 */
void print_bits(unsigned x)
{
	int i;
	
	for(i=int_bits()-1;i>=0;i--)
		putchar(((x >> i) & 1U) ? '1' : '0');
}

unsigned set(unsigned x, int pos) 
{
    unsigned y=1<<(pos-1);//ビットシフトしてpos桁目のみ1の変数yをつくる
    return x|y;//論理和をとる
}

int main(void)
{
	unsigned nx,pos;
	
	puts("符号無し整数ｘのposビット目を操作します。");
	printf("非負の整数ｘを入力してください：");
	scanf("%u", &nx);
	printf("操作するビット位置posを入力してください：");
	scanf("%u", &pos);
	
	printf("\nx＝");
	print_bits(nx);
	printf("\nset(x,pos)＝");
	print_bits(set(nx,pos));
	putchar('\n');
	return (0);
}