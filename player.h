
#ifndef DEF_PLAYER_H //��d�C���N���[�h�֎~

#define DEF_PLAYER_H

//�v���C���[�̍\����
typedef struct{
	double x,y;//���W
	int image;//�摜
    int cnt;//�J�E���g
	int image_num;//�摜�̔ԍ�
}PLAYER;

void Player_Init(PLAYER *Player);

void Player_calc(PLAYER *Player);

void Player_Movement(PLAYER *Player);

void Player_Draw(PLAYER Player,int image);

void Player_Fin(PLAYER Player);

#endif 