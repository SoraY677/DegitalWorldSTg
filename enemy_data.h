#ifndef DEF_ENEMY_DATA

#define DEF_ENEMY_DATA

#define ENEMY_ORDER_MAX 500 

//�G�̃f�[�^(�e�L�X�g���瓾���f�[�^�̑���p)
typedef struct{
	//�J�E���^,�ړ��p�^�[��,�G�̎��
	int cnt,pattern,knd;
	//�������ƈړ��X�s�[�h
	double x,y,sp;
	//�e���J�n����,�e���̎��,�F,�̗�,�e�̎��,�؍ݎ���,�A�C�e��(6���)
	int bltime,blknd,col,hp,blknd2,wait,item_n[6];
}ENEMY_ORDER;

void load_story();

#endif

