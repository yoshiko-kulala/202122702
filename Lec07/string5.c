#include <stdio.h>
void del_digit(char str[])
{
    for(int i=0;i<100;i++){//とりあえず上限の100文字まで
        if(str[i]=='\0')break;//ナル文字でループ抜ける
        if(str[i]>='0'&&str[i]<='9'){//もし数字だった時
            for(int j=i;j<100;j++){//残り全てを詰める
                str[j]=str[j+1];
            }
        }
    }
}
int main(void)
{
	char str[100];
	printf("文字列strを入力！：str = 　");
	scanf("%s",str);
	
	printf("数字の削除！\n");
	
	del_digit(str);
	
	printf("str = %s\n",str);
	
	return(0);
}