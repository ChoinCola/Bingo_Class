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
	int list_size;
	int bord_size;

public:
	auto Chack_bord(int&& userpin) -> bool; // ����� ����üũ�ϰ� ������ ���� ��������.
	auto Creat_Bord(std::string username) -> void;
	auto Get_Mybord(std::string& username)->std::vector<Hole>;
	auto Print_Allbord() -> void;
	Bingobord();
	~Bingobord();
	
	// ��� : ���� üũ�ϰ� ���� �� ���� ���� ���� �� �ڽ��� ���� ����.
	//		  �ڽ��� ���� ���� Ȯ���ϰ� ���带 ������.
};