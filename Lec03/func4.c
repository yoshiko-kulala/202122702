#include <stdio.h>
/*---二乗値を返す---*/
int sqr(int x){
	return (x*x);
}
/* ----四乗値を返す関数pow4 ---*/

pow4(no){
    return sqr(no)*sqr(no);//^2の^2で^4を返す
}


int main(void){
	int no;
	
	printf("整数を入力してください：");
	scanf("%d",&no);
	
	printf("その数の四乗値は%dです。\n",pow4(no));
	
	return (0);
}