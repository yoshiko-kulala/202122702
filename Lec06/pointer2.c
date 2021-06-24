#include <stdio.h>

void adjust_point(int *n) {
    if(*n<0)*n=0;
    if(*n>100)*n=100;
}

int main(void) {
    
    int n;
    puts("整数を入力してください");
    printf("n：");
    scanf("%d", &n);

    adjust_point(&n);
    
    puts("adjust_pointを実行しました");
    printf("n = %d\n", n);

    return 0;
}
