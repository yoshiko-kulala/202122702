#include <stdio.h>
int main(void)
{
	int i;
	int vx[8];

	for(i = 0; i < 8; i++) {
		printf("vx[%d]:", i);
		scanf("%d", &vx[i]);
	}

	for(int i=0;i<4;i++){//�ϐ��g�킸��swap��������Ă݂܂���
		vx[i] ^= vx[7-i];
		vx[7-i] ^= vx[i];
		vx[i] ^= vx[7-i];
	}

	for(i = 0; i < 8; i++) {
		printf("vx[%d]=%d\n", i, vx[i]);
	}
	return (0);
}