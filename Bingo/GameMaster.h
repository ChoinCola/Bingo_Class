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
	

public:
	auto Chack_Winner(std::vector<Hole> point, std::string username) -> bool;
	GameMaster();
	// ��� : ���� ���带 Ȯ���ϰ� ����Ѵ�. �¸����� �޼����� 0/3 �̷������� ���� ǥ���Ѵ�.
	//			���� �¸������� �޼��Ͽ��� ���, �޾ƿ� ������ �̸��� �¸��ڷ� ǥ���Ѵ�. �� �� ��������.

};

