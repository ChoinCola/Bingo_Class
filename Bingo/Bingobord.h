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
	int bord_now;
	Bingobord();
	~Bingobord();
public:
	auto Chack_bord(int&& userpin, std::string&& username, int&& bord_size) -> int; // ����� ����üũ�ϰ� ������ ���� ��������.
	auto Get_Mybord(std::string& username)->std::vector<Hole>;
	auto Print_Allbord() -> void;
	
	// ��� : ���� üũ�ϰ� ���� �� ���� ���� ���� �� �ڽ��� ���� ����.
	//		  �ڽ��� ���� ���� Ȯ���ϰ� ���带 ������.
};