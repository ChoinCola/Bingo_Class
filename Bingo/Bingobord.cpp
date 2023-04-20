#include "Bingobord.h"

auto Make_bord(int bord_size) -> std::vector<Hole>
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::vector<int> defnum(bord_size * bord_size); // ���� �迭�� �ӽù迭 ����.

	for (int i = 0; i < bord_size * bord_size; i++) { // ��ȯ
		defnum[i] = i + 1; // �迭�� ���� ����
	}

	std::shuffle(defnum.begin(), defnum.end(), gen); // �����Ͽ� �ӽù迭�� �������� ����

	std::vector<Hole> bord(bord_size * bord_size); // ���� �迭 ����.

	for (int i = 0; i < bord_size * bord_size; i++) { // �ӽù迭���� �����͸� ����.
		bord[i].number = defnum[i];
		bord[i].now = false;
	}

	delete &defnum; // �ӽù迭 ����

	return bord;
}

auto Input_pin(int userpin, std::vector<Hole>& bord) -> void
{
	for (int i = 0; i < sizeof(bord) / sizeof(bord[0]); i++) { // bord ��ü��ȯ.
		if (bord[i].number == userpin) {
			bord[i].now = true;
			return;
		}
	}
	assert("�´� �ɹ�ȣ�� ã�� �� �����ϴ�. ��������!!!!");
}

auto Bingobord::Chack_bord(int&& userpin, std::string&& username, int&& bord_size) -> int
{
	int count;
	for(count = 0 ; count < list_size; count++ )
		if (this->blist[count].username == username) { // ���� �̸��� �ش��ϴ� blist�� ã���� ���,
			Input_pin(userpin, blist[count].bord); // ������ ���� ��ġ�� ���� �ɴ´�.
			bord_now = count;
			return count;
		}

	blist.push_back(BoNa{ Make_bord(bord_size), username }); // �´��̸��� ���� ��� ���ο� �������� �����Ѵ�.
	list_size++; // ������ ��!
	bord_now = -1;
	return -1;
}

auto Bingobord::Get_Mybord(std::string& username) -> std::vector<Hole>
{
	for (int i = 0; i < list_size; i++) {
		if (blist[i].username == username)
			return blist[i].bord;
	}

	assert("���� ������ ã�� �� �����ϴ�!!!");
}

auto Bingobord::Delete_Bord() -> void
{
	for (int i = 0; i < list_size; i++) { 
		delete& blist[i].bord; 
	}
	list_size = 0;
	delete& blist;
}