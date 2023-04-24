#include "ProjectHead.h"
#include "PlayerUser.h"

auto PlayerUser::UsePin() -> int
{
	int result;
	std::cout << "원하는 위치의 수를 입력해 주세요." << std::endl;
	std::cin >> result;
	std::cin.sync();
	std::cout << "입력한 수 : " << result << std::endl;
	return result;
}

auto PlayerUser::Set_name() -> void
{
	printf("\n 이름을 지정해 주세요 \n");
	std::getline(std::cin, username);
	std::cout << "입력된 유저 이름 : " << username << std::endl;
	std::cin.sync();
}