#define _CRT_SECURE_NO_WARNINGS

//해더파일
#include<stdio.h>   //printf()등 함수
#include<windows.h> //gotoxy()등 함수
#include<conio.h>	//_getch()등 함수	
#include<time.h>   //struct tm을 위하여
#include<stdlib.h> //malloc함수를 위하여

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define Selection 4

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

//전역변수 선언
int n;          //메뉴창에서 입력
int key;        //키보드 입력
char show;      // CursorView를 위해 선언
struct list_xy {
	int list_x;
	int list_y;
} a = { 36,15 };//list의 x,y좌표를 묶음
char temp_map[14][56]; //출력할 임시 맵
int q;               //제한시간
//맵
char map3[14][56] = {
{"11111111111111111111111111111111111111111111111111111111"},
{"12000110001001000k10110101010001010101000111100100101011"},
{"11010000100100001000011010010101100000010000100000010011"},
{"11000101000000110101000010101001001010101100101001010101"},
{"10001101010110100101010000101100001010011101101010100101"},
{"11010101010001000010101010010001010101010101010100101011"},
{"11001010100010100000001000100100100010101001010100010101"},
{"11100010001000100010001001000100101010000100000100100101"},
{"10101000101010101111001001000100010011101001001001001011"},
{"11010010001000100100010001001001000000011010000000101011"},
{"10010111010100101010101010101010001001000101110100010101"},
{"10101010101110001000010101001011000100100001k11101l10101"},
{"110001001010000011110000000101000000100100000000100l0031"},
{"11111111111111111111111111111111111111111111111111111111"},
};
char map1[14][56] = {
{"11111111111111111111111111111111111111111111111111111111"},
{"12000000000000000000000000000111000000000000000000000001"},
{"10000000000000000000000000000000000000000000000000000001"},
{"11111111111111111111111111111111111111111111111110000001"},
{"10000000000000000000000111111000000000000000000000000001"},
{"11111111111111111000000000000000011111111111111111111111"},
{"110010101000101000000k1000100100100010101001010100010101"},
{"10000000000000000000000000000000000000000000000000000001"},
{"111111111111111111111111111111l1111111111111111111111111"},
{"11010010001000100100010001001001000000011010000000101011"},
{"10010111010100101010101010101010001001000100000100010101"},
{"10101010101110001000010101001000000100100001000001010101"},
{"11000100101000001111000000010100000010010000000000000031"},
{"11111111111111111111111111111111111111111111111111111111"},
};
char map2[14][56] = {
{"11111111111111111111111111111111111111111111111111111111"},
{"12000000000000000000000000000000000000000000000000000001"},
{"11111111111111111111111111111111111111111111111100000001"},
{"1100000000011000000000010000000100l010000000000000011111"},
{"100011010100001001010100001011000010000111011010100000k1"},
{"11010101111111111111111111111111111111111111111111111111"},
{"100000001100100k1000100111110000000001010010000000000011"},
{"10111000100100110000100000000010011101010001001111000011"},
{"10000101100000000100110011000010010001100101010000100101"},
{"11110111111111111100100100100000101100000100010011010001"},
{"10000100000000000000110011011100100111111110010100100101"},
{"10111110000000000000110111110010000100011100000011001001"},
{"10000000001111111110l00100011001010001010110011001000031"},
{"11111111111111111111111111111111111111111111111111111111"},
};



//함수 선언
int keycontrol(void);           //키 입력
void title_draw(void);          //게임 이름
void textcolor(int, int);        //색 선택
int menu(void);                 //메뉴 창f
void gotoxy(int, int);          //커서 이동
void map_print(int*, int*);      //맵 출력
void CursorView(char show);     // 커서숨기기
int list(int);                  //난이도 선택
void gloop(int);                //게임 루프
void move(int*, int*, int, int, int*, int*);//캐릭터 이동
void drawUI(int*, int*, int*);   //게임 UI
void clear(void);               //엔딩 화면          
void time_out();                //제한 시간

void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int keycontrol() {
	int n = _getch();
	if (n == ' ') return Selection;            //공백을 입력하여 Selection을 반환
	else if (n == 'w' || n == 'W') return UP;    //w를 누르면 UP을 반환
	else if (n == 'a' || n == 'A') return LEFT;  //a를 누르면 LEFT를 반환
	else if (n == 'd' || n == 'D') return RIGHT; //d를 누르면 RIGHT를 반환
	else if (n == 's' || n == 'S') return DOWN;  //s를 누르면 DOWN을 반환

}

void title_draw(void) {
	system("mode con cols=93 lines=30 | title maze");//콘솔창 사이즈와 이름
	printf(" __   __  _______  _______  _______    _______  _______  _______  _______  _______  _______  \n");
	printf("|  |_|  ||   _   ||       ||       |  |       ||       ||       ||   _   ||       ||       | \n");
	printf("|       ||  |_|  ||____   ||    ___|  |    ___||  _____||      _||  |_|  ||    _  ||    ___| \n");
	printf("|       ||       | ____|  ||   |___   |   |___ | |_____ |     |  |       ||   |_| ||   |___  \n");//타이틀 출력
	printf("|       ||       || ______||    ___|  |    ___||_____  ||     |_ |       ||    ___||    ___| \n");
	printf("| ||_|| ||   _   || |_____ |   |___   |   |___  _____| ||       ||   _   ||   |    |   |___  \n");
	printf("|_|   |_||__| |__||_______||_______|  |_______||_______||_______||__| |__||___|    |_______| \n");
}

int menu() {


	gotoxy(a.list_x, a.list_y);        printf("Press any key to start");
	gotoxy(a.list_x, a.list_y + 2);    printf("      게임 방법");       //메뉴 출력
	gotoxy(a.list_x, a.list_y + 3);    printf("    이동: w,a,s,d");
	gotoxy(a.list_x, a.list_y + 4);    printf("      캐릭터:"); textcolor(lightgreen, black); printf("@"); textcolor(lightgray, black);
	gotoxy(a.list_x, a.list_y + 5);    printf("       도착:"); textcolor(cyan, black); printf("O");       textcolor(lightgray, black);
	gotoxy(a.list_x, a.list_y + 6);    printf("       열쇠:"); textcolor(yellow, black); printf("^");     textcolor(lightgray, black);
	gotoxy(a.list_x, a.list_y + 7);    printf("         문:"); textcolor(lightred, black); printf("*");     textcolor(lightgray, black);


	n = _getch();
	return n;
}



int list(int n) {


	if (n) {

		system("cls");

		title_draw();
		gotoxy(a.list_x, a.list_y);       printf("> 쉬움(1)");
		gotoxy(a.list_x, a.list_y + 1);   printf("  보통(2)");  //난이도 출력
		gotoxy(a.list_x, a.list_y + 2);   printf("  어려움(3)");
		gotoxy(a.list_x, a.list_y + 3);   printf("  종료");
		while (1) {
			int list = keycontrol();
			switch (list) {
			case UP: {
				if (a.list_y > 15) {//y의 최솟값
					gotoxy(a.list_x, a.list_y); printf(" ");//원래 자리에 공백
					gotoxy(a.list_x, --a.list_y); printf(">");//위에 > 출력
				}
				break;
			}
				   //방향키
			case DOWN: {
				if (a.list_y < 18) {//y의 최댓값
					gotoxy(a.list_x, a.list_y); printf(" ");//원래 자리에 공백
					gotoxy(a.list_x, ++a.list_y); printf(">");//밑에 >출력
				}
				break;
			}
			case Selection: return a.list_y - 15;//y의 최솟값이 15이므로, retyrn값이 0~3까지
			}
		}
	}

}

void map_print(int* x, int* y) {

	system("mode con cols=56 lines=20 | title maze");//게임에 알맞은 콘솔크기 출력
	int h, w; //세로,가로
	char tmp;
	for (h = 0; h < 14; h++) { //세로길이
		for (w = 0; w < 56; w++) { //가로길이
			tmp = temp_map[h][w];
			if (tmp == '0') { //길
				textcolor(black, black);
				printf(" ");
			}
			if (tmp == '1') { //벽
				textcolor(lightgray, lightgray);
				printf("#");
			}
			if (tmp == '2') { //플레이어
				*x = w; //가로위치를 전송
				*y = h; //세로위치를 전송
				textcolor(lightgreen, black);
				printf("@");
			}
			if (tmp == '3') { //도착지
				textcolor(cyan, black);
				printf("O");
			}
			if (tmp == 'k') {//열쇠
				textcolor(yellow, black);
				printf("^");
			}
			if (tmp == 'l') {//문
				textcolor(lightred, black);
				printf("*");
			}
		}
		printf("\n");//줄바꾸기
	}
	textcolor(white, black);//원래 색으로
}

void gloop(int mapcode) {

	int x, y;//플레이어 좌표
	int k = 0;   //열쇠
	int play = 1; //실행 여부

	switch (mapcode) {
	case 0: memcpy(temp_map, map1, sizeof(temp_map)); break; //temp_map에 map1을 복사
	case 1: memcpy(temp_map, map2, sizeof(temp_map)); break; //temp_map에 map2를 복사
	case 2: memcpy(temp_map, map3, sizeof(temp_map));        //temp_map에 map3를 복사

	}
	map_print(&x, &y); //map프린트
	while (play) {//일단은 1롤 초기화 종료될경우 0
		drawUI(&x, &y, &k); //UI로 현재 좌표랑 열쇠 갯수를 프린트
		switch (keycontrol()) {
		case UP:   move(&x, &y, 0, -1, &k, &play);
			break;
		case DOWN: move(&x, &y, 0, 1, &k, &play);
			break;
		case RIGHT:move(&x, &y, 1, 0, &k, &play);
			break;
		case LEFT: move(&x, &y, -1, 0, &k, &play);
			break;
		}
	}
	clear();
}

void move(int* x, int* y, int move_x, int move_y, int* k, int* play) {//	플레이어 좌표2개 ,얼마나 이동하는지 2개,실행여부
	char mapob = temp_map[*y + move_y][*x + move_x];
	textcolor(white, black);

	if (mapob == '0' || mapob == '2') {
		gotoxy(*x, *y); printf(" ");

		textcolor(lightgreen, black);
		gotoxy(*x + move_x, *y + move_y); printf("@");

		*x += move_x;
		*y += move_y;
	}
	if (mapob == 'k') {
		*k += 1;
		temp_map[*y + move_y][*x + move_x] = '0';
		gotoxy(*x + move_x, *y + move_y);
		printf(" ");
	}
	if (mapob == 'l') {
		if (*k > 0) {
			*k -= 1;
			temp_map[*y + move_y][*x + move_x] = '0';
			gotoxy(*x + move_x, *y + move_y);
			printf(" ");
		}

	}
	if (mapob == '3') {
		*play = 0;
	}
}

void drawUI(int* x, int* y, int* k) {
	textcolor(white, black);
	gotoxy(3, 17); printf("위치 : %02d, %02d", *x, *y);

	textcolor(yellow, black);
	gotoxy(20, 17); printf("열쇠 : %d개", *k);


}


void clear() {

	char* name = (char*)malloc(sizeof(char) * 40);//이름 입력
	char* date = (char*)malloc(sizeof(char) * 50);//현재 시간
	time_t t = time(NULL);
	struct tm ti = *localtime(&t);

	FILE* User_name = NULL;

	system("cls");
	gotoxy(22, 5); printf("게임 클리어!!");
	Sleep(2000);
	gotoxy(20, 7); printf("이름을 입력하세요\n");

	gotoxy(23, 8); scanf("%100[^\n]s", name);
	gotoxy(20, 10); printf("재시작 합니다!!");
	Sleep(1500);

	User_name = fopen("User.txt", "w");
	sprintf(date, "\n날짜 : %d-%d-%d %d:%d:%d", ti.tm_year + 1900, ti.tm_mon + 1, ti.tm_mday, ti.tm_hour, ti.tm_min, ti.tm_sec);
	fprintf(User_name, name);
	fprintf(User_name, date);

	fclose(User_name);

	free(name);
	free(date);

}




int main() {

	while (1) {
		CursorView(show);
		title_draw();
		menu();

		int listcode = list(n);

		system("cls");

		switch (listcode) {
		case 0:gloop(0); break;
		case 1:gloop(1); break;
		case 2:gloop(2); break;
		case 3: return 0;
		}
		a.list_y = 15;

	}

}