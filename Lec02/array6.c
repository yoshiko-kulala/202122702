#include <stdio.h>
int main(void)
{
	int i;
	int tensu[5];       /* 5�l�̊w���̓_�� */
	int sum = 0;        /* ���v�_ */
	double ave;         /* ���ϓ_ */
	double var = 0.0;   /* ���U */
	puts("�_������͂��Ă��������B");
	for (i = 0; i < 5; i++) {
		printf("%2d�ԁF", i + 1);
		scanf("%d", &tensu[i]);
		sum += tensu[i];
	}
	/* ���ς� ave �Ɋi�[ */

	ave=(double)sum/5;

	/* �w���̓_���ƕ��ς��番�U�� var �Ɍv�Z */

	for(int i=0;i<5;i++)
		var+=(tensu[i]-ave)*(tensu[i]-ave);//���̓��𑫂��Z
	var=var/5;//���Ŋ���

	printf("���v�_�F%5d\n", sum);
	printf("���ϓ_�F%5.1f\n", ave);
	printf("���@�U�F%5.1f\n", var);
}