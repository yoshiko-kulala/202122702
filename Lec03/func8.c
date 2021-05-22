#include <stdio.h>
/*---要素数noの配列v2の全要素を2倍して逆順に配列v1に格納 ---*/

void intary_rcpy(int *v1,const int v2[],int no){
    for(int i=0;i<no;i++){
        v1[i]=v2[no-1-i]*2;//2倍して逆順に代入
    }
}  


int main(void){
	int i;
	int vx[5],vy[5];
	
	for(i=0;i<5;i++){
		printf("vx[%d]：",i);
		scanf("%d",&vx[i]);
	}
	
	intary_rcpy(vy,vx,5); /* 配列vxを2倍してvyに逆順にコピー */
	
	puts("配列vyに配列vxの要素を2倍して逆順に格納しました。");
	for(i=0;i<5;i++)
		printf("vy[%d]＝%d\n",i,vy[i]);
	
	return (0);
}