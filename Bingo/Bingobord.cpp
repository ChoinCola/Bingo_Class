#include "Bingobord.h"

Bingobord::Bingobord()
{
	bord_size = WIDTHLENGTH;
	list_size = 0;
	bord_now = 0;
}
auto Make_bord(int bord_size) -> std::vector<Hole>
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::vector<int> defnum(bord_size * bord_size); // 숫자 배열할 임시배열 생성.

	for (int i = 0; i < bord_size * bord_size; i++) { // 순환
		defnum[i] = i + 1; // 배열에 숫자 기입
	}

	std::shuffle(defnum.begin(), defnum.end(), gen); // 셔플하여 임시배열을 무작위로 섞음

	std::vector<Hole> bord(bord_size * bord_size); // 보드 배열 생성.

	for (int i = 0; i < bord_size * bord_size; i++) { // 임시배열값에 데이터를 기입.
		bord[i].number = defnum[i];
		bord[i].now = false;
	}

	delete &defnum; // 임시배열 날림

	return bord;
}

auto Input_pin(int userpin, std::vector<Hole>& bord) -> void
{
	for (int i = 0; i < sizeof(bord) / sizeof(bord[0]); i++) { // bord 전체순환.
		if (bord[i].number == userpin) {
			bord[i].now = true;
			return;
		}
	}
	assert("맞는 핀번호를 찾을 수 없습니다. 디버깅오류!!!!");
}

auto Bingobord::Chack_bord(int&& userpin, std::string&& username, int&& bord_size) -> int
{
	int count;
	for(count = 0 ; count < list_size; count++ )
		if (this->blist[count].username == username) { // 유저 이름에 해당하는 blist를 찾았을 경우,
			Input_pin(userpin, blist[count].bord); // 보드의 숫자 위치에 핀을 꽃는다.
			bord_now = count;
			return count;
		}

	blist.push_back(BoNa{ Make_bord(bord_size), username }); // 맞는이름이 없을 경우 새로운 보드판을 생성한다.
	list_size++; // 사이즈 업!
	bord_now = -1;
	return -1;
}

auto Bingobord::Get_Mybord(std::string& username) -> std::vector<Hole>
{
	for (int i = 0; i < list_size; i++) {
		if (blist[i].username == username)
			return blist[i].bord;
	}

	printf("\n 보드값을 찾을 수 없습니다. 반환오류! \n 다시 시도해주세요!\n");
	return blist[0].bord;
}

auto Bingobord::Print_Allbord() -> void
{
	for (int i = 0; i < list_size; i++) {
		std::cout << std::setw(bord_size * 5 - 1) << blist[i].username; // 이름출력
	}
	std::cout << std::endl;
	for (int j = 0; j < bord_size; j++) { // 한줄 씩 출력
		for (int i = 0; i < list_size; i++) { // 보드 개수 조건참조
			for (int k = 0; k < bord_size; k++) { // 해당 줄의 해당보드위치
				if (blist[i].bord[(j * bord_size) + k].now = true)
					printf("[//] ");
				else
					std::cout << std::setw(4) << std::left << "[" <<
					std::right << blist[i].bord[(j * bord_size) + k].number << "] ";
			}
		}
	}
}

Bingobord::~Bingobord()
{
	for (int i = 0; i < list_size; i++) { 
		delete& blist[i].bord; 
	}
	list_size = 0;
	delete& blist;
}