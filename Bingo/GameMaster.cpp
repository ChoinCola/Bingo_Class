#include "GameMaster.h"
#include "ProjectHead.h"

GameMaster::GameMaster()
{
	widthlength = WIDTHLENGTH;
	how_many_bingo = HOW_M_BINGO;
}

auto Victory_contdition(std::vector<Hole> point, int widthlength) -> int
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
			chack_length += !point[i * widthlength + j].now;
			chack_width += !point[j * widthlength + i].now;
		}
		if (chack_length == 0) bingo_count++;
		if (chack_width == 0) bingo_count++;

		chack_right_diagonal += !point[(widthlength + 1) * i].now;
		chack_left_diagonal += !point[(widthlength - 1) + ((widthlength - 1) * i)].now;
	}
	if (chack_right_diagonal == 0) bingo_count++;
	if (chack_right_diagonal == 0) bingo_count++;

	return bingo_count;
}

auto GameMaster::Chack_Winner(std::vector<Hole> point, std::string username) -> bool
{
	int defc = Victory_contdition(point, this->widthlength);

	if (defc >= how_many_bingo) {
		std::cout << username << " 가 승리 하였습니다." << std::endl;
		return 1;
	}
	return 0;
}
