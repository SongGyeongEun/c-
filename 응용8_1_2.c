#include <stdio.h> //표준 입출력 장치 헤더 파일 사용 
#include <stdlib.h> //표준 라이브러리 헤더 파일 사용 
#include <conio.h> // 콘솔 입출력 헤더 파일 사용 
#include <windows.h> // 윈도우 헤더 파일 사용 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); // 방향키 함수 정의
void gotoxy(int x, int y); // 커서 제어 함수 정의
void draw_check01(int c, int r); // 그림 그리기 함수 정의
void game_control(void); // 게임 제어 함수 정의
void display_stone(int matrix[][20]); //바둑판 출력 함수 정의

int main(void)// main 함수 생성
{
	game_control();
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r)
{
    int i, j;
    unsigned char a=0xa6; // char 변수 a 정의
    unsigned char b[12];  // char 변수 b 정의
    for(i=1;i<12;i++) // b[1] 부터 b[11]까지 점차 1씩 증가를 반복
	b[i]=0xa0+i;
    printf("%c%c",a, b[3]); // 화면에 변수 a와 변수 b[3]를 출력
    for(i=0;i<c-1;i++)
	 printf("%c%c", a, b[8]); // 변수 i가 0이상 c-1 미만 까지 화면에 변수 a와 변수 b[4]를 반복 출력
	printf("%c%c", a, b[4]); //화면에 변수 a와 변수 b[4]를 출력
	printf("\n"); //줄 바꿈 표시 
	for (i = 0; i < r - 1; i++) //변수 i가 0이상 r-1미만까지 아래 아래 실행들을 반복 
    {
	printf("%c%c", a, b[7]); //화면에 변수 a와 변수 b[7]를 출력
	for(j=0;j<c-1;j++)
		printf("%c%c", a, b[11]); //변수 j가 0이상 c-1미만까지 화면에 변수 a와 변수 b[11]를 반복 출력
	printf("%c%c", a, b[9]); //화면에 변수 a와 변수 b[9]를 출력
	printf("\n");
    }
    printf("%c%c", a, b[6]); // 화면에 변수 a와 변수 b[6]를 출력
    for(i=0;i<c-1;i++) 
	printf("%c%c", a, b[10]); // 변수 i가 0 이상 c-1 미만까지 화면에 변수 a와 변수 b[10]를 반복 출력
    printf("%c%c", a, b[5]); // 화면에 변수 a와 변수 b[5]를 출력
    printf("\n");
}

void game_control(void)
{
    int x=1, y=1, matrix[20][20]={0}; //모든 요소의 값을 0으로 초기화
    char key;
    do
    {
	gotoxy(1,1); //커서의 위치를 화면 원점으로 이동
	draw_check01(18, 18); // 바둑판을 표시
	gotoxy(x, y); // 현재 커서의 위치 (x,y)에 바둑돌을 표시
	printf("○");
	display_stone(matrix);
	gotoxy(1, 20);
	printf("방향키로 움직이고 "); //커서의 좌표 x와 y값을 변경
	printf("스페이스 키를 누르시오."); //matrix[(x+1)/2] [y]의 값은 1 로 변경
	key=getch();
	if (key==27)
		exit(0);
	else if (key==32)
		matrix[(x+1)/2][y]=1;
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19); //수정부분
    }while(1);
}

void display_stone(int matrix[][20])
{
	int x, y;
	for(x=1;x<20;x++)
		for(y=1;y<20;y++)
		{
			if (matrix[x][y]==1)
			{
				gotoxy(x*2-1, y);
				printf("●");
			}
		}
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;             //좌측방향으로 2씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
	default:
		return;
	}
}

