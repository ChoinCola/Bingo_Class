#include "AIuser.h"
#include "ProjectHead.h"

AIuser::AIuser() {
	widthlength = WIDTHLENGTH;
}

auto AIuser::Set_name() -> void
{
	printf("\n �̸��� ������ �ּ��� : \n");
	std::getline(std::cin, username);
	std::cin.sync();
	std::cout << "�Էµ� AI �̸� : " << username << std::endl;
}

auto AIuser::Victory_contdition(std::vector<Hole> point) -> int
{
	// ���� �¸����� : ��� ���� ���� üũ�Ǿ��� ��,
	// �밢���� ���� üũ�Ǿ��� ��.
	// �밢�� ��ǥ�� ������, 0 -> 6������, 4 ->4 ������,
	// ���μ��ΰ� 6�ϰ�� 0 -> 7 5 -> 10 �� ����.
	// ���μ��ΰ� 7�ϰ�� 0 -> 8 6 -> 12 �� ����, 
	// ��, �����Ͱ� �Էµ� ��� ���ϴ� �밢���� ��� ������ ���μ��� + 1
	// ���ϴ��� ��� ������ ���μ���-1 + ���μ���-1 ������.

	// �ΰ����� �����
	// �·� = (�� ���� üũ�� ���� �� / �� ��ü�� ��) + �� ���� ������ ��ġ�� ���� ���� / 3 * 0.1

	int bingo_count = 0;
	int vector_count = 0;

	std::vector<pos> Pos(1);

	for (int i = 0; i < widthlength; i++) { // ����
		for (int j = 0; j < widthlength; j++) { // ����  ��ü��ȯ

			int chack_length = 0; // ���� üũ
			int chack_width = 0; // ���� üũ
			int chack_right_diagonal = 0; // �����ϴܴ밢�� üũ
			int chack_left_diagonal = 0; // ���� �ϴ� �밢�� üũ

			for (int ki = 0; ki < widthlength; ki++) // ����üũ
				chack_length += point[j * widthlength + ki].now;

			for (int kj = 0; kj < widthlength; kj++) // ����üũ
				chack_width += point[i + widthlength * kj].now;

			if (i - j == 0) { // ������ �밢�� üũ
				for (int kk = 0; kk < widthlength; kk++) // �밢�� üũ
				{
					chack_right_diagonal += point[widthlength * kk + kk].now;
				}
			}
			else if (i + j == widthlength - 1) { // ������ �밢�� üũ
				for (int kk = 0; kk < widthlength; kk++) // �밢�� üũ
				{
					chack_left_diagonal += point[(widthlength - 1) * kk + widthlength - 1].now;
				}
			}
			int allc = chack_length + chack_width + chack_right_diagonal + chack_left_diagonal;

			if (Pos[vector_count].Odds < allc / widthlength && point[i + j * widthlength].now == false) {
				Pos[vector_count].Odds = allc / widthlength;
				Pos[vector_count].number = point[i + j * widthlength].number;
			}
			else if (Pos[vector_count].Odds == allc / widthlength && point[i + j * widthlength].now == false) {
				pos def;
				def.number = point[i + j * widthlength].number;
				def.Odds = allc / widthlength;
				Pos.push_back(def); // �� �ڿ� �߰�.
				vector_count++;
			}
		}
	}


	if (vector_count == 0) {
		std::cout << "AI�� �� : " << Pos[0].number << std::endl;
		return Pos[0].number;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, vector_count-1);

	int result = Pos[dist(gen)].number;

	std::cout << username << " AI�� �� : " << result << std::endl;
	return result;
}