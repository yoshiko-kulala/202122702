#include <stdio.h>
/*---文字列の長さを返す関数---*/
unsigned str_length(const char str[])
{
    for(int i=0;1;i++){
        if(str[i]=='\0')return i+1;//文字数なので1を足す
    }
}

void put_rstring(const char str[])
{
    for(int i=str_length(str)-2;i>-1;i--){//文字数が返ってくるのとナル文字を避けるため-2する
        printf("%c",str[i]);
    }
}
int main(void)
{
	char str[100];
	printf("文字列を入力：");
	scanf("%s",str);
	
	printf("逆にすると次のようになります \n");
	put_rstring(str);
         putchar('\n');
	return(0);
}