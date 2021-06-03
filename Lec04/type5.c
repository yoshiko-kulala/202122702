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

int set_n(nx,pos,no){
    //"1U"をnビット左にシフトした値から１を引き (これでnビット目まで全て1のビット表現が作られる), 
    //さらに，これをpos-1ビット左にシフトしたものをunsigned型の変数に保存する
    //（これでposからpos+n-1ビットまでが全て1のビット表現が作られる）. この変数をmaskとする.
    unsigned mask=((1<<no)-1)<<(pos-1);
    //xとmaskの論理和をsetの返り値とする.
    return nx|mask;
}

int main(void)
{
	unsigned nx;
	int pos,no;
	
	puts("符号無し整数ｘのposビット目からno個のビットを操作します。");
	printf("非負の整数ｘを入力してください：");
	scanf("%u", &nx);
	printf("操作するビット位置posを入力してください：");
	scanf("%d", &pos);
	printf("操作するビット数noを入力してください：");
	scanf("%d", &no);
	
	printf("\nx＝");
	print_bits(nx);
	printf("\nset_n(x,pos,no)＝");
	print_bits(set_n(nx,pos,no));
	putchar('\n');
	return (0);
}
