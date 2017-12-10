#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 50
#define MAP_Y 30

#define start_x 45
#define start_y 25

int x[1000], y[1000]; 
int length; //몸길이를 기억 
int speed; //게임 속도 
int dir; //이동방향 저장 
int key; //입력받은 키 저장 

void gotoxy(int x, int y, char* s) { //x값을 2x로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf함수 삽입  
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void title(void); //게임 시작화면 
void reset(void); //게임을 초기화 
void draw_map(void); // 게임판 테두리를 그림 
void move(int dir); //뱀머리를 이동 
void game_over(void); //게임 오버를 확인 

// 메인함수
int main() {
	title();

	while (1) {
		if (kbhit()) do 
		{ 
			key = getch(); 
		} while (key == 224); //키 입력받음
		Sleep(speed);

		switch (key) { //입력받은 키를 파악하고 실행
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			if ((dir == LEFT&&key != RIGHT) || (dir == RIGHT&&key != LEFT) || (dir == UP&&key != DOWN) ||
				(dir == DOWN&&key != UP))//180회전이동을 방지하기 위해 필요.
				dir = key;
			key = 0; // 키값을 저장하는 함수를 reset 
			break;
		case ESC: //ESC키를 누르면 프로그램 종료 
			exit(0);
		}
		move(dir);
	}
}

//타이틀 화면
void title(void) {
	int i, j;

	while (kbhit()) getch(); //버퍼에 있는 키값을 버림 

	draw_map();    //맵 테두리를 그림 
	for (i = MAP_ADJ_Y + 1; i<MAP_ADJ_Y + MAP_Y - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
		for (j = MAP_ADJ_X + 1; j<MAP_ADJ_X + MAP_X - 1; j++) gotoxy(j, i, "  ");
	}

	while (1) {
		if (kbhit()) { //키입력받음 
			key = getch();
			if (key == ESC) exit(0); // ESC키면 종료 
			else break; //아니면 그냥 계속 진행 
		}
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
		Sleep(400);

	}
	reset(); // 게임을 초기화  
}

//값 초기화 함수
void reset(void) {
	int i;
	system("cls"); //화면을 지움 
	draw_map(); //맵 테두리를 그림 
	while (kbhit()) getch(); //버퍼에 있는 키값을 버림 

	dir = LEFT; // 방향 초기화  
	speed = 150; // 속도 초기화 
	length = 1; //뱀 길이 초기화 
	for (i = 0; i<length; i++) { //뱀 몸통값 입력 
		x[i] = start_x;
		y[i] = start_y;
		gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "ㅇ");
	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "ㅎ"); //뱀 머리 그림 
}

void draw_map(void) { //맵 테두리 그리는 함수 
	int i, j;
	for (i = 0; i<MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
	}
	for (i = MAP_ADJ_Y + 1; i<MAP_ADJ_Y + MAP_Y - 1; i++) {
		gotoxy(MAP_ADJ_X, i, "■");
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "■");
	}
	for (i = 0; i<MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "■");
	}
}

void move(int dir) {
	int i;

	if (x[0] == 0 || x[0] == MAP_X - 1 || y[0] == 0 || y[0] == MAP_Y - 1) { //벽과 충돌했을 경우 
		game_over();
		return; //game_over에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 
				//return을 사용하여 move의 나머지 부분이 실행되지 않도록 합니다. 
	}

	for (i = 1; i<length; i++) { //자기몸과 충돌했는지 검사 
		if (x[0] == x[i] && y[0] == y[i]) {
			game_over();
			return;
		}
	}

	for (i = length - 1; i>0; i--) { //몸통좌표를 한칸씩 옮김 
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "ㅇ"); //머리가 있던곳을 몸통으로 고침 
	if (dir == LEFT) --x[0]; //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경 
	if (dir == RIGHT) ++x[0];
	if (dir == UP) --y[0];
	if (dir == DOWN) ++y[0];
	gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "ㅎ"); //새로운 머리좌표값에 머리를 그림 
}

void game_over(void) { //게임종료 함수 
	Sleep(500);
	while (kbhit()) getch();
	key = getch();
	title();
}
