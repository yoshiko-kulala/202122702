#include <stdio.h>
/*---二乗値を返す---*/
void alert(int no){
    for(int i=0;i<no;i++){
        printf("Alert!\a\n");//一応両方実装
    }
}

int main(void){
    int n=0;
	printf("整数を入力してください：");
	scanf("%d",&n);
	
	alert(n);
	
	return 0;
}