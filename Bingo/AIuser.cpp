#include "AIuser.h"
#include "ProjectHead.h"

AIuser::AIuser() {
	widthlength = WIDTHLENGTH;
}

auto AIuser::Set_name() -> void
{
	printf("\n 이름을 지정해 주세요 : \n");
	std::getline(std::cin, username);
	std::cin.sync();
	std::cout << "입력된 AI 이름 : " << username << std::endl;
}

auto AIuser::Victory_contdition(std::vector<Hole> point) -> int
{
	// 빙고 승리조건 : 행과 열이 전부 체크되었을 때,
	// 대각선이 전부 체크되었을 때.
	// 대각선 좌표의 공통점, 0 -> 6씩증가, 4 ->4 씩증가,
	// 가로세로가 6일경우 0 -> 7 5 -> 10 씩 증가.
	// 가로세로가 7일경우 0 -> 8 6 -> 12 씩 증가, 
	// 즉, 데이터가 입력될 경우 우하단 대각선의 경우 데이터 가로세로 + 1
	// 좌하단의 경우 데이터 가로세로-1 + 가로세로-1 증가함.

	// 인공지능 연산식
	// 승률 = (줄 내의 체크된 개수 수 / 줄 전체의 수) + 그 점이 영향을 끼치는 줄의 개수 / 3 * 0.1

	int bingo_count = 0;
	int vector_count = 0;

	std::vector<pos> Pos(1);

	for (int i = 0; i < widthlength; i++) { // 가로
		for (int j = 0; j < widthlength; j++) { // 세로  전체순환

			int chack_length = 0; // 가로 체크
			int chack_width = 0; // 세로 체크
			int chack_right_diagonal = 0; // 우측하단대각선 체크
			int chack_left_diagonal = 0; // 좌측 하단 대각선 체크

			for (int ki = 0; ki < widthlength; ki++) // 가로체크
				chack_length += point[j * widthlength + ki].now;

			for (int kj = 0; kj < widthlength; kj++) // 세로체크
				chack_width += point[i + widthlength * kj].now;

			if (i - j == 0) { // 정방향 대각선 체크
				for (int kk = 0; kk < widthlength; kk++) // 대각선 체크
				{
					chack_right_diagonal += point[widthlength * kk + kk].now;
				}
			}
			else if (i + j == widthlength - 1) { // 역방향 대각선 체크
				for (int kk = 0; kk < widthlength; kk++) // 대각선 체크
				{
					chack_left_diagonal += point[(widthlength - 1) * kk + widthlength - 1].now;
				}
			}
			int allc = chack_length + chack_width + chack_right_diagonal + chack_left_diagonal;

			if (Pos[vector_count].Odds < allc / widthlength && point[i + j * widthlength].now == false) {
				Pos[vector_count].Odds = allc / widthlength;
				Pos[vector_count].number = point[i + j * widthlength].number;
			}
			else if (Pos[vector_count].Odds == allc / widthlength && point[i + j * widthlength].now == false) {
				pos def;
				def.number = point[i + j * widthlength].number;
				def.Odds = allc / widthlength;
				Pos.push_back(def); // 맨 뒤에 추가.
				vector_count++;
			}
		}
	}


	if (vector_count == 0) {
		std::cout << "AI의 수 : " << Pos[0].number << std::endl;
		return Pos[0].number;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, vector_count-1);

	int result = Pos[dist(gen)].number;

	std::cout << username << " AI의 수 : " << result << std::endl;
	return result;
}