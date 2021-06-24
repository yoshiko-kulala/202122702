#include <stdio.h>

int main(void){
    int a,b;
    int *p;
    a=10; b=20;

    /* ポインタpにaのアドレスを代入 */
    //pの値がaのアドレスになる、他変化なし
    p=&a;

    printf("(1) a=%3d b=%3d *p=%3d\n",a,b,*p); /* 値を表示 */
    printf("(1) &a=%p &b=%p p=%p\n",&a,&b,p); /* アドレスを表示 */

    /* ポインタpの指す先の値に「30（整数値）」を代入 */
    //pのポインタ先はaなのでaの値が30になる、*pも30になる
    *p=30;

    printf("(2) a=%3d b=%3d *p=%3d\n",a,b,*p);
    printf("(2) &a=%p &b=%p p=%p\n",&a,&b,p);

    /* aに「100（整数値）」をｂに「200（整数値）」を代入 */
    //a,bの値が代入値に変わる
    a=100;
    b=200;

    printf("(3) a=%3d b=%3d *p=%3d\n",a,b,*p);
    printf("(3) &a=%p &b=%p p=%p\n",&a,&b,p);

    /* ポインタpにbのアドレスを代入 */
    //pの値がbのアドレスになる、他変化なし
    p=&b;

    printf("(4) a=%3d b=%3d *p=%3d\n",a,b,*p);
    printf("(4) &a=%p &b=%p p=%p\n",&a,&b,p);
	
    return (0);
}