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
	auto Victory_contdition(std::vector<Hole> point) -> int; // ���� ��, �ڽ��� ���嵥���͸� �ް�. ���� ���� ���ڸ� �����.
	auto Set_name() -> void; // ���� �� �ڽ��� ���� �̸��� ���Ѵ�.
};

