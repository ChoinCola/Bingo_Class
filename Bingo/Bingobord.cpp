#include "Bingobord.h"

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

	assert("보드 내용을 찾을 수 없습니다!!!");
}

auto Bingobord::Delete_Bord() -> void
{
	for (int i = 0; i < list_size; i++) { 
		delete& blist[i].bord; 
	}
	list_size = 0;
	delete& blist;
}