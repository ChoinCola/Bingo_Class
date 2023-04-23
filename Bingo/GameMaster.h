#pragma once
#include "Hole.h"
#include "ProjectHead.h"
class GameMaster
{
	int widthlength;
	int how_many_bingo;

	class Users
	{
		int Vic_count = 0;
		std::string username;
	};
	GameMaster();

public:
	auto Chack_Winner(std::vector<Hole> point, std::string username) -> void;
	
	// 기능 : 받은 보드를 확인하고 출력한다. 승리조건 달성률을 0/3 이런식으로 같이 표시한다.
	//			만약 승리조건을 달성하였을 경우, 받아온 보드의 이름을 승리자로 표시한다. 그 후 게임종료.

};

