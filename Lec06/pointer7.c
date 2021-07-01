#include <stdio.h>

int fib_sub(int n) {
    //フィボナッチ求める
    if(n == 0)return 0;
    if(n == 1)return 1;
    return fib_sub(n-1) + fib_sub(n-2);
}

int fib(int n, int *fib_last, int *fib_second_last) {
    //フィボナッチの一個前とかを入れる
    *fib_last=fib_sub(n-1);
    *fib_second_last=fib_sub(n-2);
    return fib_sub(n-1)+fib_sub(n-2);
}

int main(void) {

    int n;
    int fib_last, fib_second_last;

    printf("n = ");
    scanf("%d",&n);

    printf("fib(n) = %d\n",fib(n,&fib_last,&fib_second_last));
    printf("fib(n-1) = %d, fib(n-2) = %d\n",fib_last,fib_second_last);
    
    return 0; 
}