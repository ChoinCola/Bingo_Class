#include "ProjectHead.h"
#include "PlayerUser.h"

auto PlayerUser::UsePin() -> int
{
	int result;
	std::cout << "���ϴ� ��ġ�� ���� �Է��� �ּ���." << std::endl;
	std::cin >> result;
	std::cout << "�Է��� �� : " << result << std::endl;
	return result;
}