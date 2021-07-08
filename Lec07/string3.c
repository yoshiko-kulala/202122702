#include <stdio.h>
void put_string(const char str[],int no)
{
/* no回出力を繰り返す */
//%5sの時は一文字列あたり5文字の大きさで右によって表示される
//%-5sの時は一文字列あたり5文字の大きさで左によって表示される
//%.2sの時は2文字までしか表示されない、1文字の時に二文字分の大きさに拡張されない
    for(int i=0;i<no;i++){
        printf("%s",str);
        //printf("%5s",str);
        //printf("%-5s",str);
        //printf("%.2s",str);
    }
}
int main(void)
{
	int x;
	char str[100];
	printf("文字列を入力：");
	scanf("%s",str);
	
	printf("繰り返す回数 : ");
	scanf("%d",&x);
	put_string(str,x);
	putchar('\n');
	return(0);
}