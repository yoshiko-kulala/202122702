/* 二つの変数の値を交換する */
#include <stdio.h>

/* ポインタを使わず単にpxとpyの値をそのまま入れ替える */
void swap_v(int px, int py) {
    py = px - py;
    px -= py;
    py += px;
}

/* ポインタを使ってpxとpyの値を入れ替える */
void swap_p(int *px, int *py) {
    *px ^= *py;
    *py ^= *px;
    *px ^= *py;
}

int main(void) {

    int na, nb;
    puts("二つの整数を入力してください");
    printf("整数A：");
    scanf("%d",&na);
    printf("整数B：");
    scanf("%d",&nb);

    swap_v(na, nb);
 
    puts("swap_vを実行しました。");
    printf("整数Aは%dです。\n",na);
    printf("整数Bは%dです。\n",nb);

    swap_p(&na, &nb);

    puts("swap_pを実行しました。");
    printf("整数Aは%dです。\n",na);
    printf("整数Bは%dです。\n",nb);

    return (0);
}