#include <stdio.h>
#define NUMBER 16

/* 整数ｘを16進数で表した時の桁数を返す */
/* 例 x=3のときの値:1, x=17のときの値：2, x=300のときの値：3 */
int count_digits(unsigned x) 
{
    unsigned num = x;//この行がなぜ必要かよくわからない
    int digit = 0;

    while(num != 0) {
        digit++;//カウント
		num =num/16;//16で割る
    }
    
    return digit;
}

int main(void) 
{
    unsigned nx;
    int ny;
	
    printf("非負の整数を入力してください：");
    scanf("%u", &nx);
    putchar('\n');

    ny = count_digits(nx);
    printf("16進数での桁数：%d\n", ny);   

    printf("16進数での表示 (桁数確認用)：%x\n", nx);   
    
    return 0;
}