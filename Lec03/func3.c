#include <stdio.h>

int cube(no){
    return no*no*no;,//三乗を返す
}

int main(void){
	int no;
	
	printf("整数を入力してください：");
	scanf("%d",&no);
	
	printf("その数の三乗値は%dです。\n",cube(no));
	
	return (0);
}
