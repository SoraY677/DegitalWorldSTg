

#ifndef DEF_ENEMY_H

#define DEF_ENEMY_H

#define ENEMY_MAX 30

#include "enemy_data.h"

typedef struct{
	double x,y;//���W
	double vx,vy;//���x����
    double speed;//�X�s�[�h
	double angle;//�p�x
	//�t���O,�J�E���^,�ړ��p�^�[��,����,�G�̎��,HP,�ő�HP,���Ƃ��A�C�e��,�摜
	int flag,cnt,pattern,direction,kind,hp,hp_max,item_n[6],img,image_num;
	//�e���J�n����, �e���̎��,�e�̎��,�F,���,�ҋ@����,��؎���
	int bltime,blkind,blkind2,color,state,wtime,wait;
}ENEMY;



void enemy_init();

void enemy_pattern0(ENEMY *Enemy);

void enemy_enter(ENEMY *Enemy, ENEMY_ORDER Enemy_order);

void enemy_act(ENEMY *Enemy);

void enemy_Draw(ENEMY Enemy,int image);

#endif