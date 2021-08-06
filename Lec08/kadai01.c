#include <stdio.h>
#include <math.h>

#define N 5

double mean(double array[], int n) {
    double sum=0;
    for(int i=0;i<n;i++)sum=sum+array[i];
    return sum/n;
}

double std(double array[], int n) {
    double ave=mean(array,n);
    double sum=0;
    for(int i=0;i<n;i++)sum=sum+(array[i]-ave)*(array[i]-ave);
    return sqrt(sum/n);
}

void standardize(double array[], int n) {
    double ave=mean(array,n),hen=std(array,n);
    for(int i=0;i<n;i++){
        array[i]=(array[i]-ave)/hen;
    }
}

double corr_coef(double x[], double y[], int n) {
    double ave[2]={mean(x,n),mean(y,n)};
    double m_std[2]={std(x,n),std(y,n)};
    double ary_cor=0;
    for(int i=0;i<n;i++){
        ary_cor=ary_cor+(x[i]-ave[0])*(y[i]-ave[1]);
    }
    return ary_cor/(m_std[0]*m_std[1]*n);
}

int main() {

    double x[N] = {5.0, 1.0, 4.0, -1.0, 2.0};
    double y[N] = {3.0, 0.0, 4.0, -2.0, 5.0};
    printf("ave x=>\t%f\r\n",mean(x,N));
    printf("ave y=>\t%f\r\n",mean(y,N));
    printf("std x=>\t%f\r\n",std(x,N));
    printf("std y=>\t%f\r\n",std(y,N));
    printf("standardize x\r\n");
    standardize(x,N);
    for(int i=0;i<N;i++){
        printf("\tx[%d]=>\t%f\r\n",i,x[i]);
    }
    printf("standardize y\r\n");
    standardize(y,N);
    for(int i=0;i<N;i++){
        printf("\ty[%d]=>\t%f\r\n",i,y[i]);
    }
    printf("corr_coef=>\t%f\r\n",corr_coef(x,y,N));
    return 0;
}
