#include "Bingobord.h"

Bingobord::Bingobord()
{
	bord_size = WIDTHLENGTH;
	list_size = 0;
}
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

	//delete &defnum; // �ӽù迭 ����

	return bord;
}

auto Input_pin(int userpin, std::vector<Hole>& bord, int bord_size) -> bool
{
	for (int i = 0; i < bord_size * bord_size; i++) { // bord ��ü��ȯ.
		if (bord[i].number == userpin) {
			if (bord[i].now == false) {
				bord[i].now = true;
				return 0;
			}
			else
				return 1;
		}
	}
	assert("�´� �ɹ�ȣ�� ã�� �� �����ϴ�. ��������!!!!");
}

auto Bingobord::Chack_bord(int&& userpin) -> bool
{
	bool result;
	for(int count = 0 ; count < list_size; count++ ) {
		result = Input_pin(userpin, blist[count].bord, bord_size); // ������ ���� ��ġ�� ���� �ɴ´�. ��� ���带 ��ȸ�Ͽ� ����.
	}
	return result;
}

auto Bingobord::Creat_Bord(std::string username) -> void
{
	blist.push_back(BoNa{ Make_bord(bord_size), username }); // �´��̸��� ���� ��� ���ο� �������� �����Ѵ�.
	list_size++; // ������ ��!
}

auto Bingobord::Get_Mybord(std::string& username) -> std::vector<Hole>
{
	for (int i = 0; i < list_size; i++) {
		if (blist[i].username == username)
			return blist[i].bord;
	}

	printf("\n ���尪�� ã�� �� �����ϴ�. ��ȯ����! \n �ٽ� �õ����ּ���!\n");
	return blist[0].bord;
}

auto Bingobord::Print_Allbord() -> void
{
	for (int i = 0; i < list_size; i++) {
		std::cout << std::setw(bord_size * 2) << std::setfill(' ') << std::right << std::string(bord_size * 2 - blist[i].username.length(), ' ') 
			<< blist[i].username << std::string(bord_size * 2 + 2 - blist[i].username.length(), ' '); // �̸� ���
	}
	std::cout << std::endl;
	for (int j = 0; j < bord_size; j++) { // ���� �� ���
		for (int i = 0; i < list_size; i++) { // ���� ���� ��������
			for (int k = 0; k < bord_size; k++) { // �ش� ���� �ش纸����ġ
				if (blist[i].bord[(j * bord_size) + k].now == true)
					printf("[��]");
				else
					std::cout << (blist[i].bord[(j * bord_size) + k].number < 10 ? std::setw(2) : std::setw(0)) << std::left << "[" <<
					std::right << blist[i].bord[(j * bord_size) + k].number << "]";
			}
			printf("  ");
		}
		printf("\n");
	}
}

Bingobord::~Bingobord()
{
	for (int i = 0; i < list_size; i++) { 
		delete& blist[i].bord; 
	}
	list_size = 0;
	delete& blist; 
}