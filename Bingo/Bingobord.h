#pragma once
#include "Hole.h"
#include "ProjectHead.h"

class Bingobord 
{
	class BoNa
	{
	public: // ����Class�� public������ ���־ �ȴ�. ������ ���ο����� privet�̱� ����
		std::vector<Hole> bord;
		std::string username;
	};

	std::vector<BoNa> blist;
	int list_size = 0;
	int bord_now;
public:
	
	auto Chack_bord(int&& userpin, std::string&& username, int&& bord_size) -> int; // ����� ����üũ�ϰ� ������ ���� ��������.
	auto Get_Mybord(std::string& username)->std::vector<Hole>;
	auto Delete_Bord() -> void;
	std::string username;
};