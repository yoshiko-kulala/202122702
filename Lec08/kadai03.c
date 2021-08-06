#include <stdio.h>

#define max_dan 99//表示の都合で99にしてみました

int n=0;//円盤の数
int tower[3][max_dan]={0};//towerの状態
int cou=1;//移動回数

void tower_view();//towerの表示
void move(int dan,int a,int b,int c);//再帰される関数

int main(){
    //段数入力
    printf("円盤の数(0~99)=>");
    scanf("%d",&n);

    //ハノイの塔初期化
    for(int i=0;i<n;i++){
        tower[0][max_dan-i-1]=n-i;
    }

    printf("初期状態\n");
    tower_view();
    printf("\n");
    
    move(n,0,1,2);
    printf("END\r\n");

    return 0;
}

void tower_view(){
    int view_tower[3][max_dan]={0};//表示用配列
    //円盤を下(配列でいうと値が大きい方)に並べる
    for(int i=0;i<3;i++){
        int cou2=1;
        for(int j=max_dan-1;j>=0;j--){
            if(tower[i][j]>0){
                view_tower[i][max_dan-cou2]=tower[i][j];
                cou2++;
            }
        }
    }
    //塔の状態表示
    for(int i=max_dan-n-1;i<max_dan;i++){
        for(int j=0;j<3;j++){
            if(view_tower[j][i]==0)printf("\t ||  ");//円盤無しは"||"
            else printf("\t[%2d]",view_tower[j][i]);
        }
        printf("\r\n");
    }
    printf("-----A-------B-------C------\r\n");//一応地面
}

void move(int dan,int a,int b,int c){//n段の移動をする
    if(dan>0){
        move(dan-1,a,c,b);//n-1段の移動をする
        //max_dan-n-1+danは円盤の大きさも含んでいるので、この時点で下ぞろえ面倒だった
        //viewで調整するのは割と簡単だったのでここでは横にスライドさせる操作のみ行う
        tower[c][max_dan-n-1+dan]=tower[a][max_dan-n-1+dan];//n段目の移動
        tower[a][max_dan-n-1+dan]=0;
        printf("%d回目の移動\r\n",cou);
        printf("%cから%cに移動\r\n",'A'+a,'A'+c);
        tower_view();
        cou++;
        printf("please any key\r\n");
        getchar();//キーボード入力待ち
        move(dan-1,b,a,c);//n-1段目をもとに戻す
    }
}