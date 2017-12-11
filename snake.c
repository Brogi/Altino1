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
int length; //�����̸� ��� 
int speed; //���� �ӵ� 
int dir; //�̵����� ���� 
int key; //�Է¹��� Ű ���� 

void gotoxy(int x, int y, char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void title(void); //���� ����ȭ�� 
void reset(void); //������ �ʱ�ȭ 
void draw_map(void); // ������ �׵θ��� �׸� 
void move(int dir); //��Ӹ��� �̵� 
void game_over(void); //���� ������ Ȯ�� 

// �����Լ�
int main() {
	title();

	while (1) {
		if (kbhit()) do 
		{ 
			key = getch(); 
		} while (key == 224); //Ű �Է¹���
		Sleep(speed);

		switch (key) { //�Է¹��� Ű�� �ľ��ϰ� ����
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			if ((dir == LEFT&&key != RIGHT) || (dir == RIGHT&&key != LEFT) || (dir == UP&&key != DOWN) ||
				(dir == DOWN&&key != UP))//180ȸ���̵��� �����ϱ� ���� �ʿ�.
				dir = key;
			key = 0; // Ű���� �����ϴ� �Լ��� reset 
			break;
		case ESC: //ESCŰ�� ������ ���α׷� ���� 
			exit(0);
		}
		move(dir);
	}
}

//Ÿ��Ʋ ȭ��
void title(void) {
	int i, j;

	while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 

	draw_map();    //�� �׵θ��� �׸� 
	for (i = MAP_ADJ_Y + 1; i<MAP_ADJ_Y + MAP_Y - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
		for (j = MAP_ADJ_X + 1; j<MAP_ADJ_X + MAP_X - 1; j++) gotoxy(j, i, "  ");
	}

	while (1) {
		if (kbhit()) { //Ű�Է¹��� 
			key = getch();
			if (key == ESC) exit(0); // ESCŰ�� ���� 
			else break; //�ƴϸ� �׳� ��� ���� 
		}
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
		Sleep(400);

	}
	reset(); // ������ �ʱ�ȭ  
}

//�� �ʱ�ȭ �Լ�
void reset(void) {
	int i;
	system("cls"); //ȭ���� ���� 
	draw_map(); //�� �׵θ��� �׸� 
	while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 

	dir = LEFT; // ���� �ʱ�ȭ  
	speed = 150; // �ӵ� �ʱ�ȭ 
	length = 1; //�� ���� �ʱ�ȭ 
	for (i = 0; i<length; i++) { //�� ���밪 �Է� 
		x[i] = start_x;
		y[i] = start_y;
		gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "��");
	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "��"); //�� �Ӹ� �׸� 
}

void draw_map(void) { //�� �׵θ� �׸��� �Լ� 
	int i, j;
	for (i = 0; i<MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "��");
	}
	for (i = MAP_ADJ_Y + 1; i<MAP_ADJ_Y + MAP_Y - 1; i++) {
		gotoxy(MAP_ADJ_X, i, "��");
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "��");
	}
	for (i = 0; i<MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "��");
	}
}

void move(int dir) {
	int i;

	if (x[0] == 0 || x[0] == MAP_X - 1 || y[0] == 0 || y[0] == MAP_Y - 1) { //���� �浹���� ��� 
		game_over();
		return; //game_over���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� 
				//return�� ����Ͽ� move�� ������ �κ��� ������� �ʵ��� �մϴ�. 
	}

	for (i = 1; i<length; i++) { //�ڱ���� �浹�ߴ��� �˻� 
		if (x[0] == x[i] && y[0] == y[i]) {
			game_over();
			return;
		}
	}

	for (i = length - 1; i>0; i--) { //������ǥ�� ��ĭ�� �ű� 
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "��"); //�Ӹ��� �ִ����� �������� ��ħ 
	if (dir == LEFT) --x[0]; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ���� 
	if (dir == RIGHT) ++x[0];
	if (dir == UP) --y[0];
	if (dir == DOWN) ++y[0];
	gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 
}

void game_over(void) { //�������� �Լ� 
	Sleep(500);
	while (kbhit()) getch();
	key = getch();
	title();
}
