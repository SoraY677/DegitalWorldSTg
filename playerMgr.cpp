
#include "DxLib.h"
#include "player.h"


static PLAYER player; //�v���C���[�̎���
static int m_ImgPlayer[8]; //�v���C���[�̉摜�n���h��

//������
void PlayerMgr_Init(){
	LoadDivGraph("image/��l��(��).png",8,8,1,64,144,m_ImgPlayer);

	Player_Init(&player);
}

void PlayerMgr_calc(){
	Player_calc(&player);
}


//����v�Z
void PlayerMgr_Update(){
	   Player_Movement(&player);
}

//�`��
void PlayerMgr_Draw(){
	Player_Draw(player,m_ImgPlayer[player.image_num]);
}

//�I������
void PlayerMgr_Fin(){
	Player_Fin(player);
}