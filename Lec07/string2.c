#include <stdio.h>
int str_char(const char str[],int moji)
{
    for(int i=0;i<52;i++){
        if(str[i]==moji)return i;
    }
    return -1;
}
int main(void)
{
	int no;
	char ch[10];
	
	printf("英文字を入力してください　：");
	scanf("%s",ch);
	
	no = str_char("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",ch[0]);
	
	if(no >= 0 && no <= 25)
		printf("それは英大文字の%d番目です。\n",no+1);
	else if (no >= 26 && no <= 51)
		printf("それは英小文字の%d番目です。\n",no-25);
	else 
		printf("それは英文字ではありません\n");
	return(0);
}