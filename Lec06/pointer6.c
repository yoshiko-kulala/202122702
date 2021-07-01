#include<stdio.h>

int set_max_min(int* max, int* min) {
    int input=0,cou=0;
    //最初の値をminとmaxにいれる
    scanf("%d",&input);
    cou++;
    *min=input;
    *max=input;
    //負の値が来るまで待機
    while(1){
        scanf("%d",&input);
        if(input<0)break;
        cou++;
        if(*min>input)*min=input;
        if(*max<input)*max=input;
    }
    return cou;
}

int main(void){

    int min, max, num;
    num = set_max_min(&max, &min);
    printf("The number of inputs = %d\n",num);
    printf("Min = %d\n",min);
    printf("Max = %d\n",max);

    return 0;
}