#include "ProjectHead.h"


/*

	���� ���� �缳��.

	Ŭ���� �з�
	�÷��̾�
	AI�÷��̾�
	������
	���Ӹ�����

	Ŭ���� ���� ���ۻ���.

	[�÷��̾� ����] 

	��ǲ
	�ܺ���ǲ�� �޴´�.

	���ο���
	�ܺ� ��ǲ�� ���Ϻ����� �����Ѵ�.

	�ƿ�ǲ
	���Ϻ����� �����忡 �����Ѵ�.

	[AI�÷��̾� ����]

	��ǲ
	�����带 �Է¹޴´�.
	
	���ο���
	���� �ǿ����� ���� ������ ���� �����Ѵ�.

	�ƿ�ǲ
	���Ϻ����� �����忡 �����Ѵ�.

	[������ ����]

	��ǲ
	�� ��ȣ �� ���������� �Է¹޴´�.
	
	���ο���
	������ �ش�Ǵ� �����尡 ���ٸ�, ������ �����ڷ� ���ٴ� ����� �����Ѵ�.
	�Էµ� �԰��� �����带 �����ϰ�, 2��Ʈ�������� ���� ��ǥ���� �����Ѵ�.
	�Էµ� ���ڰ� ��ġ�� �������� ��ġ�� üũ���ش�.

	�ƿ�ǲ
	�Է¹��� �� ��ȣ�� ������ ������ ���� �´��� �Ǻ����� bool
	��ü ���������� ���Ӹ����Ϳ� �����Ѵ�.

	[���Ӹ����� ����]

	��ǲ
	�����带 �Է¹޴´�.

	���ο���
	�������� �¸������� �����Ѵ�.
	�¸������� ������ �÷��̾ Ȯ���ϰ� ���� �� ��¿��� �����Ѵ�.

	�ƿ�ǲ
	�¸��ڰ� ���� �� ���Ῡ�ο� �¸����� �̸��� ���ο� ��ȯ�Ѵ�.

	[���ι� ���ۻ���]
	
	while(���Ῡ��) {
	�ο� �� �Է�
	int* ������
	������ ����

	�÷��̾� ����
	���� ���� ����
	AI �÷��̾� ����
	���� ���� ����

	���Ӹ����� ����

	���ι����� ���Ῡ�� Ȯ��

	}

*/

int main()
{
	int user_count;
	PlayerUser player;
	Bingobord Game_bord;
	GameMaster Game_Master;

	std::string Player_name;
	player.Set_name(); // ������ �̸� �Է�.
	Game_bord.Creat_Bord(player.username); // �̸���� ���� ����

	std::cout << "���� �÷��� �� AI�� ���� �Է����ּ��� : ";
	std::cin >> user_count;
	std::cin.ignore();
	std::vector<AIuser> AI(user_count); // AI �� �Է�

	for (int i = 0; i < user_count; i++) {// AI�� ���� ��ŭ �̸��� �������ش�.
		std::cout << i + 1 << "��° AI�� �̸� �Դϴ�." << std::endl;
		AI[i].Set_name();
		Game_bord.Creat_Bord(AI[i].username); // �̸���� ���� ����
	}

	// �����غ� �Ϸ�
	Sleep(1000);
	system("cls");
	printf("������ �����մϴ�!\n");
	Sleep(1000);
	system("cls");
	while (true) {
		
		Game_bord.Print_Allbord();
		while (Game_bord.Chack_bord(player.UsePin())) {}

		Game_Master.Chack_Winner(Game_bord.Get_Mybord(player.username), player.username); // ���� �����Ͱ� �¸����θ� �Ǻ���.
		Sleep(1000);
		for (int i = 0; i < user_count; i++) {
			Game_bord.Chack_bord(AI[i].Victory_contdition(Game_bord.Get_Mybord(AI[i].username))); // AI�� �ڽ��� ���带 �����ͼ� �ּ��� �� ��ġ�� ������.

			if (Game_Master.Chack_Winner(Game_bord.Get_Mybord(player.username), player.username)) {
				Game_bord.Print_Allbord();// ���� �����Ͱ� �¸����θ� �Ǻ���.
				exit(0);
			}
			else if (Game_Master.Chack_Winner(Game_bord.Get_Mybord(AI[i].username), AI[i].username)) {
				Game_bord.Print_Allbord();// ���� �����Ͱ� �¸����θ� �Ǻ���.
				exit(0);
			}

			Sleep(1000);
		}
		system("cls");
	}
}