#include <stdio.h>

void calc_ave_gakusei(int score[4][3], double ave_gakusei[4]){
    for(int i=0;i<4;i++)ave_gakusei[i]=(score[i][0]+score[i][1]+score[i][2])/3;
}

void calc_ave_kyoka(int score[4][3], double ave_kyoka[3]){
    for(int i=0;i<3;i++)ave_kyoka[i]=(score[0][i]+score[1][i]+score[2][i]+score[3][i])/4;
}

int main(void)
{
    int score[4][3]={
        {10,15,20},
        {30,35,40},
        {50,55,60},
        {70,75,80}
    };

    double ave_kyoka[3]={0};
    double ave_gakusei[4]={0};

    calc_ave_gakusei(score,ave_gakusei);
    calc_ave_kyoka(score, ave_kyoka);

    printf("教科毎の平均点");
    for(int i=0;i<3;i++){
        printf("%f\n",ave_kyoka[i]);
    }
    printf("学生毎の平均点");
    for(int i=0;i<4;i++){
        printf("%f\n",ave_gakusei[i]);
    }

    return (0);
}