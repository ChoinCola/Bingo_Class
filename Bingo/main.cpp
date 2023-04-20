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
	int list[WIDTHLENGTH][WIDTHLENGTH] = { NULL };
	int data, chack = 0;

	Random_input(list[0], WIDTHLENGTH);

	while (chack != 1) {
		system("cls");
		Print_Bingo(list[0], WIDTHLENGTH);
		printf("체크하려는 칸을 입력해 주세요! : ");
		scanf_s("%d", &data);
		User_input(list[0], WIDTHLENGTH, data);
		chack = Bingo_chack(list[0], WIDTHLENGTH, HOW_M_BINGO);
	}
	if (chack == 1) {
		system("cls");
		Print_Bingo(list[0], WIDTHLENGTH);
		printf("성공하셨습니다 축하드립니다!\n");
	}
	return 0;
}

