#include "ProjectHead.h"
#include "PlayerUser.h"

auto PlayerUser::UsePin() -> int
{
	int result;
	std::cout << "���ϴ� ��ġ�� ���� �Է��� �ּ���." << std::endl;
	std::cin >> result;
	std::cin.sync();
	std::cout << "�Է��� �� : " << result << std::endl;
	return result;
}

auto PlayerUser::Set_name() -> void
{
	printf("\n �̸��� ������ �ּ��� \n");
	std::getline(std::cin, username);
	std::cout << "�Էµ� ���� �̸� : " << username << std::endl;
	std::cin.sync();
}