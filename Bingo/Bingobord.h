#pragma once
#include "Hole.h"
#include "ProjectHead.h"

class Bingobord 
{
	class BoNa
	{
	public: // 내부Class는 public설정을 해주어도 된다. 어차피 내부에서는 privet이기 떄문
		std::vector<Hole> bord;
		std::string username;
	};

	std::vector<BoNa> blist;
	int list_size = 0;
	int bord_now;
public:
	
	auto Chack_bord(int&& userpin, std::string&& username, int&& bord_size) -> int; // 선언시 보드체크하고 없을시 보드 생성까지.
	auto Get_Mybord(std::string& username)->std::vector<Hole>;
	auto Delete_Bord() -> void;
	std::string username;
};