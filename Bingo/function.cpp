#include "ProjectHead.h"

auto Print_Bingo(int* point, int widthlength) -> void
{
	for (int i = 0; i < widthlength; i++) printf("  ");
	printf("빙고");
	for (int i = 0; i < widthlength; i++) printf("  ");
	printf("\n\n");

	for (int i = 0; i < widthlength; i++) {
		for (int j = 0; j < widthlength; j++) {
			Ten_or_One(point + (widthlength * i) + j);
		}
		printf("\n\n");
	}
}

auto Random_input(int* point, int widthlength) -> void
{
	int count = 0; // 순환용 카운트
	int random = 0; // 랜덤 카운트

	for (; count < widthlength * widthlength; count++) {
		srand((unsigned int)time(NULL) + random);
		*(point + count) = rand() % (widthlength * widthlength) + 1;
		for (int i = 0; i < count; i++) {
			if (*(point + count) == *(point + i)) {
				count--;
				break; // 중복검사.
			}
		}
		random++;
	}
}

auto User_input(int* point, int widthlength, int data) -> void
{
	for (int i = 0; i < widthlength * widthlength; i++) {
		if (*(point + i) == data) {
			*(point + i) = 0;
			return;
		}
	}
	printf("잘못 입력 하였습니다. 다시 입력해 주세요!\n");
}

auto Bingo_chack(int* point, int widthlength, int how_many_bingo) -> int
{
	// 빙고 승리조건 : 행과 열이 전부 체크되었을 때,
	// 대각선이 전부 체크되었을 때.
	// 대각선 좌표의 공통점, 0 -> 6씩증가, 4 ->4 씩증가,
	// 가로세로가 6일경우 0 -> 7 5 -> 10 씩 증가.
	// 가로세로가 7일경우 0 -> 8 6 -> 12 씩 증가, 
	// 즉, 데이터가 입력될 경우 우하단 대각선의 경우 데이터 가로세로 + 1
	// 좌하단의 경우 데이터 가로세로-1 + 가로세로-1 증가함.

	int bingo_count = 0;
	int chack_right_diagonal = 0; // 우측하단대각선 체크
	int chack_left_diagonal = 0; // 좌측 하단 대각선 체크

	for (int i = 0; i < widthlength; i++) {
		int chack_length = 0; // 가로 체크
		int chack_width = 0; // 세로 체크

		for (int j = 0; j < widthlength; j++) {
			chack_length += *(point + (widthlength * i) + j);
			chack_width += *(point + (widthlength * j) + i);
		}
		if (chack_length == 0) bingo_count++;
		if (chack_width == 0) bingo_count++;

		chack_right_diagonal += *(point + ((widthlength + 1) * i));
		chack_left_diagonal += *(point + (widthlength - 1) + ((widthlength - 1) * i));

		if (bingo_count >= how_many_bingo) return 1;
	}
	if (chack_right_diagonal == 0) bingo_count++;
	if (chack_right_diagonal == 0) bingo_count++;
	if (bingo_count > how_many_bingo) return 1;
	return 0;
}

auto AI_set(int* list, int widthlength, int data) -> void
{
	int* def_data = new int[widthlength * widthlength];

	for (int i = 0; i < widthlength * widthlength; i++) {
		if (*(list + i) == -1)
			*(def_data + i) = *(list + i);
	}
}

auto Ten_or_One(int* point) ->void
{
	if (*point >= 10) printf("[%d] ", *point);
	else if (*point == 0) printf("[◆] ");
	else if (*point == -1) printf("[◇] ");
	else printf("[0%d] ", *point);
}
