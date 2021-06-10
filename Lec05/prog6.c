#include <stdio.h>
int main(void){
    int ch,n_count=0;
    while(1){
        ch=getchar();
        if(ch=='0')break;//0の時ループを出る
        if(ch=='\n')n_count++;//\nの時加算
    }
	printf("行数：%d\n", n_count);
	return(0);
}