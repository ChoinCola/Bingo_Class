#pragma once
#include "ProjectHead.h"

class AIuser
{
	int widthlength;
	
	class pos
	{
	public:
		int number = 0;
		double Odds = -1.0;
	};
	

public:
	AIuser();
	std::string username;
	auto Victory_contdition(std::vector<Hole> point) -> int; // 선언 시, 자신의 보드데이터를 받고. 핀을 넣을 숫자를 출력함.
	auto Set_name() -> void; // 선언 시 자신의 유저 이름을 정한다.
};

