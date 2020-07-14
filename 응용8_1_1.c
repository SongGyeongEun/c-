#include <stdio.h> //ǥ�� ����� ��ġ ��� ���� ��� 
#include <stdlib.h> //ǥ�� ���̺귯�� ��� ���� ��� 
#include <conio.h> // �ܼ� ����� ��� ���� ��� 
#include <windows.h> // ������ ��� ���� ��� 

void move_arrow_key(char chr, int* x, int* y, int x_b, int y_b); //����Ű �Լ� ����
void gotoxy(int x, int y); //Ŀ�� ���� �Լ� ����
void draw_check01(int c, int r); //�׸� �׸��� �Լ� ����
void game_control(void); //���� ���� �Լ� ����

int main(void) // main �Լ� ����
{
	game_control(); //���� ���� �Լ� ����
	return 0;
}

void gotoxy(int x, int y) //Ŀ�� ���� �Լ� ����
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r) //�׸� �׸��� �Լ� ����
{
	int i, j;
	unsigned char a = 0xa6; //char ���� a ����  
	unsigned char b[12]; //char ���� b ����
	for (i = 1; i < 12; i++)  //b[1] ���� b[11]���� ���� 1�� ������ �ݺ� 
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]); //ȭ�鿡 ���� a�� ���� b[3]�� ��� 
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[8]); //���� i�� 0�̻� c-1�̸����� ȭ�鿡 ���� a�� ���� b[4]�� �ݺ� ��� 
	printf("%c%c", a, b[4]); //ȭ�鿡 ���� a�� ���� b[4]�� ���
	printf("\n"); //�� �ٲ� ǥ�� 
	for (i = 0; i < r - 1; i++) //���� i�� 0�̻� r-1�̸����� �Ʒ� �Ʒ� ������� �ݺ� 
	{
		printf("%c%c", a, b[7]); //ȭ�鿡 ���� a�� ���� b[7]�� ���
		for (j = 0; j < c - 1; j++)
			printf("%c%c", a, b[11]); //���� j�� 0�̻� c-1�̸����� ȭ�鿡 ���� a�� ���� b[11]�� �ݺ� ���
		printf("%c%c", a, b[9]); //ȭ�鿡 ���� a�� ���� b[9]�� ���
		printf("\n"); //�� �ٲ� ǥ��
	}
	printf("%c%c", a, b[6]); //ȭ�鿡 ���� a�� ���� b[9]�� ���
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[10]); //���� i�� 0�̻� c-1�̸����� ȭ�鿡 ���� a�� ���� b[10]�� �ݺ� ���
	printf("%c%c", a, b[5]); //ȭ�鿡 ���� a�� ���� b[5]�� ���
	printf("\n"); //�� �ٲ� ǥ��
}

void game_control(void) // ���� ���� �Լ� ���� 
{
	int x = 1, y = 1; //int ���� x,y ���� 
	char key; //char ���� key ���� 
	do // �Ʒ� ������� �ݺ� 
	{
		gotoxy(1, 1);
		draw_check01(18, 18);
		gotoxy(x, y);
		printf("��");
		gotoxy(1, 21);
		printf("����Ű�� �����ÿ�.");
		key = getch();
		if (key == 27)
			exit(0);
		else if (key >= 72)
			move_arrow_key(key, &x, &y, 37, 19); //�����κ�
	} while (1);
}

void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b) // ����Ű ���� �Լ� ���� 
{
	switch (key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1 = *y1 - 1;
		if (*y1 < 1)	*y1 = 1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1 = *x1 - 2;             //������������ 2�� ����
		if (*x1 < 1)	*x1 = 1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1 = *x1 + 2;               //������������ 2�� ����
		if (*x1 > x_b)  *x1 = x_b; //x��ǥ�� �ִ밪(���)
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1 = *y1 + 1;
		if (*y1 > y_b)  *y1 = y_b; //y��ǥ�� �ִ밪(���)
		break;
	default:
		return;
	}
}
