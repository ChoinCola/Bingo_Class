#include "GameMaster.h"
#include "ProjectHead.h"

GameMaster::GameMaster()
{
	widthlength = WIDTHLENGTH;
	how_many_bingo = HOW_M_BINGO;
}

auto Victory_contdition(std::vector<Hole> point, int widthlength) -> int
{
	// ���� �¸����� : ��� ���� ���� üũ�Ǿ��� ��,
	// �밢���� ���� üũ�Ǿ��� ��.
	// �밢�� ��ǥ�� ������, 0 -> 6������, 4 ->4 ������,
	// ���μ��ΰ� 6�ϰ�� 0 -> 7 5 -> 10 �� ����.
	// ���μ��ΰ� 7�ϰ�� 0 -> 8 6 -> 12 �� ����, 
	// ��, �����Ͱ� �Էµ� ��� ���ϴ� �밢���� ��� ������ ���μ��� + 1
	// ���ϴ��� ��� ������ ���μ���-1 + ���μ���-1 ������.

	int bingo_count = 0;
	int chack_right_diagonal = 0; // �����ϴܴ밢�� üũ
	int chack_left_diagonal = 0; // ���� �ϴ� �밢�� üũ

	for (int i = 0; i < widthlength; i++) {
		int chack_length = 0; // ���� üũ
		int chack_width = 0; // ���� üũ

		for (int j = 0; j < widthlength; j++) {
			chack_length += !point[i * widthlength + j].now;
			chack_width += !point[j * widthlength + i].now;
		}
		if (chack_length == 0) bingo_count++;
		if (chack_width == 0) bingo_count++;

		chack_right_diagonal += !point[(widthlength + 1) * i].now;
		chack_left_diagonal += !point[(widthlength - 1) + ((widthlength - 1) * i)].now;
	}
	if (chack_right_diagonal == 0) bingo_count++;
	if (chack_right_diagonal == 0) bingo_count++;

	return bingo_count;
}

auto GameMaster::Chack_Winner(std::vector<Hole> point, std::string username) -> bool
{
	int defc = Victory_contdition(point, this->widthlength);

	if (defc >= how_many_bingo) {
		std::cout << username << " �� �¸� �Ͽ����ϴ�." << std::endl;
		return 1;
	}
	return 0;
}
