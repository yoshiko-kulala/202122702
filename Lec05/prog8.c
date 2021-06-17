#include<stdio.h>

void swap(int data[], int i, int j)
{
    int temp;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void permutation(int data[], int left, int right) 
{
    int i;
    if(right+1 <= 1){//n<=1の時表示
        for(int j=0;j<(sizeof data / sizeof data[0])+1;j++){
            printf("%d ", data[j]);
        }
        printf("\n");
    }
    else{
        for(i=0; i <right+1; i++){//i<nになるまでループ
            swap(data, 0, right+1-1);//swap
            permutation(data,left,right-1);//再帰
            swap(data, right-1, i);//swap戻す
        }
    }
}

int main() 
{
    int data[] = {1,2,3};
    /* int data[] = {1,2,3,4}; */
    /* int data[] = {1,2,3,4,5}; */
    int n = sizeof data / sizeof data[0];
    permutation(data, 0, n-1);

    return 0;
}