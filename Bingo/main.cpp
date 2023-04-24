#include "ProjectHead.h"


/*

	빙고 게임 재설계.

	클래스 분류
	플레이어
	AI플레이어
	빙고보드
	게임마스터

	클래스 간의 동작사항.

	[플레이어 동작] 

	인풋
	외부인풋을 받는다.

	내부연산
	외부 인풋을 리턴변수로 지정한다.

	아웃풋
	리턴변수를 빙고보드에 전달한다.

	[AI플레이어 동작]

	인풋
	빙고보드를 입력받는다.
	
	내부연산
	현재 판에대한 가장 최적의 수를 예상한다.

	아웃풋
	리턴변수를 빙고보드에 전달한다.

	[빙고보드 동작]

	인풋
	핀 번호 와 유저정보를 입력받는다.
	
	내부연산
	유저에 해당되는 빙고보드가 없다면, 빙고보드 생성자로 없다는 결과를 전달한다.
	입력된 규격의 빙고보드를 생성하고, 2진트리구조의 숫자 좌표값을 생성한다.
	입력된 숫자가 위치한 빙고보드의 위치를 체크해준다.

	아웃풋
	입력받은 핀 번호가 빙고보드 내부의 수가 맞는지 판별여부 bool
	전체 빙고보드판을 게임마스터에 전달한다.

	[게임마스터 동작]

	인풋
	빙고보드를 입력받는다.

	내부연산
	빙고보드의 승리조건을 연산한다.
	승리조건을 만족한 플레이어를 확인하고 있을 시 출력에서 종료한다.

	아웃풋
	승리자가 있을 시 종료여부와 승리자의 이름을 메인에 반환한다.

	[메인문 동작사항]
	
	while(종료여부) {
	인원 수 입력
	int* 빙고보드
	빙고보드 동작

	플레이어 동작
	빙고 보드 동작
	AI 플레이어 동작
	빙고 보드 동작

	게임마스터 동작

	메인문에서 종료여부 확인

	}

*/

int main()
{
	int user_count;
	PlayerUser player;
	Bingobord Game_bord;
	GameMaster Game_Master;

	std::string Player_name;
	player.Set_name(); // 유저의 이름 입력.
	Game_bord.Creat_Bord(player.username); // 이름대로 보드 생성

	std::cout << "같이 플레이 할 AI의 수를 입력해주세요 : ";
	std::cin >> user_count;
	std::cin.ignore();
	std::vector<AIuser> AI(user_count); // AI 수 입력

	for (int i = 0; i < user_count; i++) {// AI의 개수 만큼 이름을 지정해준다.
		std::cout << i + 1 << "번째 AI의 이름 입니다." << std::endl;
		AI[i].Set_name();
		Game_bord.Creat_Bord(AI[i].username); // 이름대로 보드 생성
	}

	// 게임준비 완료
	Sleep(1000);
	system("cls");
	printf("게임을 시작합니다!\n");
	Sleep(1000);
	system("cls");
	while (true) {
		
		Game_bord.Print_Allbord();
		while (Game_bord.Chack_bord(player.UsePin())) {}

		Game_Master.Chack_Winner(Game_bord.Get_Mybord(player.username), player.username); // 게임 마스터가 승리여부를 판별함.
		Sleep(1000);
		for (int i = 0; i < user_count; i++) {
			Game_bord.Chack_bord(AI[i].Victory_contdition(Game_bord.Get_Mybord(AI[i].username))); // AI가 자신의 보드를 가져와서 최선의 핀 위치를 공략함.

			if (Game_Master.Chack_Winner(Game_bord.Get_Mybord(player.username), player.username)) {
				Game_bord.Print_Allbord();// 게임 마스터가 승리여부를 판별함.
				exit(0);
			}
			else if (Game_Master.Chack_Winner(Game_bord.Get_Mybord(AI[i].username), AI[i].username)) {
				Game_bord.Print_Allbord();// 게임 마스터가 승리여부를 판별함.
				exit(0);
			}

			Sleep(1000);
		}
		system("cls");
	}
}