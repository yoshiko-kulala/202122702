#include<stdio.h>

/* n個からr個選び出す組み合わせの数 nCrの計算 */
//ヒント通りの分岐を書いたら動きました(確率久しぶりすぎてなんも分からない)
int combination(int n, int r) {
    if (r==0||n==r) //この分岐なしで動くと思ったけど値が小さくなると動かない
        return (1);
    else if (r==1) //この分岐無くても動きそうな気がする
        return (n);
    else
        return  combination(n-1, r-1) + combination(n-1, r) ;
}

int main(void)
{
    int n, r;

    printf("nCrの計算を行います\n");
    printf("n: "); 
    scanf("%d", &n);
    printf("r: "); 
    scanf("%d", &r);

    printf("nCr = %d\n", combination(n, r));

    return (0);
}