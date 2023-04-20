#include "ProjectHead.h"

auto Print_Bingo(int* point, int widthlength) -> void
{
	for (int i = 0; i < widthlength; i++) printf("  ");
	printf("����");
	for (int i = 0; i < widthlength; i++) printf("  ");
	printf("\n\n");

	for (int i = 0; i < widthlength; i++) {
		for (int j = 0; j < widthlength; j++) {
			Ten_or_One(point + (widthlength * i) + j);
		}
		printf("\n\n");
	}
}

auto Random_input(int* point, int widthlength) -> void
{
	int count = 0; // ��ȯ�� ī��Ʈ
	int random = 0; // ���� ī��Ʈ

	for (; count < widthlength * widthlength; count++) {
		srand((unsigned int)time(NULL) + random);
		*(point + count) = rand() % (widthlength * widthlength) + 1;
		for (int i = 0; i < count; i++) {
			if (*(point + count) == *(point + i)) {
				count--;
				break; // �ߺ��˻�.
			}
		}
		random++;
	}
}

auto User_input(int* point, int widthlength, int data) -> void
{
	for (int i = 0; i < widthlength * widthlength; i++) {
		if (*(point + i) == data) {
			*(point + i) = 0;
			return;
		}
	}
	printf("�߸� �Է� �Ͽ����ϴ�. �ٽ� �Է��� �ּ���!\n");
}

auto Bingo_chack(int* point, int widthlength, int how_many_bingo) -> int
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
			chack_length += *(point + (widthlength * i) + j);
			chack_width += *(point + (widthlength * j) + i);
		}
		if (chack_length == 0) bingo_count++;
		if (chack_width == 0) bingo_count++;

		chack_right_diagonal += *(point + ((widthlength + 1) * i));
		chack_left_diagonal += *(point + (widthlength - 1) + ((widthlength - 1) * i));

		if (bingo_count >= how_many_bingo) return 1;
	}
	if (chack_right_diagonal == 0) bingo_count++;
	if (chack_right_diagonal == 0) bingo_count++;
	if (bingo_count > how_many_bingo) return 1;
	return 0;
}

auto AI_set(int* list, int widthlength, int data) -> void
{
	int* def_data = new int[widthlength * widthlength];

	for (int i = 0; i < widthlength * widthlength; i++) {
		if (*(list + i) == -1)
			*(def_data + i) = *(list + i);
	}
}

auto Ten_or_One(int* point) ->void
{
	if (*point >= 10) printf("[%d] ", *point);
	else if (*point == 0) printf("[��] ");
	else if (*point == -1) printf("[��] ");
	else printf("[0%d] ", *point);
}
