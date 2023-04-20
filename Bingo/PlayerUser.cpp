#include "ProjectHead.h"
#include "PlayerUser.h"

auto PlayerUser::UsePin() -> int
{
	int result;
	std::cout << "원하는 위치의 수를 입력해 주세요." << std::endl;
	std::cin >> result;
	std::cout << "입력한 수 : " << result << std::endl;
	return result;
}