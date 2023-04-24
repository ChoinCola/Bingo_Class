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
	int list_size;
	int bord_size;

public:
	auto Chack_bord(int&& userpin) -> bool; // 선언시 보드체크하고 없을시 보드 생성까지.
	auto Creat_Bord(std::string username) -> void;
	auto Get_Mybord(std::string& username)->std::vector<Hole>;
	auto Print_Allbord() -> void;
	Bingobord();
	~Bingobord();
	
	// 기능 : 보드 체크하고 있을 시 핀을 박음 없을 시 자신의 보드 생성.
	//		  자신의 보드 값을 확인하고 보드를 가져옴.
};