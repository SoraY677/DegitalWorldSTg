
#include <math.h>
#include "DxLib.h"
#include "enemy.h"
#include "stage.h"
#include "enemy_data.h"

extern int stage_count;


//������
void enemy_init(){
	
}


//�G�̈ړ����p�^�[���O
void enemy_pattern0(ENEMY *Enemy){
	int t = Enemy->cnt;
	if (t==0)
		Enemy->vy=2;///�������Ă���
	if(t==60)
		Enemy->vy=0;//�~�܂�
	//�o�^���ꂽ���Ԃ����؍݂���
	if (t==60+Enemy->wait)
		Enemy->vy=-2;//�オ���Ă���
	
}

//�����Ă���G�ԍ�������
  int enemy_num_search(ENEMY *Enemy){

	  if (Enemy->flag==0){
		  return 1;
        }
	   return -1;
	  }


//�G�f�[�^�̓o�^
void enemy_enter(ENEMY *Enemy,ENEMY_ORDER Enemy_order){
        Enemy->flag=1;//�t���O
		Enemy->cnt =0;//�J�E���^
		Enemy->pattern=Enemy_order.pattern;//�ړ��p�^�[��
        Enemy->direction=1;//����
		Enemy->x = Enemy_order.x;//���W
		Enemy->y = Enemy_order.y;
		Enemy->speed = Enemy_order.sp;//�X�s�[�h
		Enemy->bltime=	Enemy_order.bltime;//�e�����ˎ���
		Enemy->kind=Enemy_order.knd;//���
		Enemy->blkind =Enemy_order.blknd;//�e���̎��
		Enemy->blkind2=Enemy_order.blknd2;//�e�̎��
		Enemy->color=Enemy_order.col;//�F
		Enemy->wait=Enemy_order.wait;//��؎���
		Enemy->hp=Enemy_order.hp;//�̗�
		Enemy->hp_max=Enemy->hp;//�ő�̗�
		Enemy->vx=0;//���������̑��x
		Enemy->vy=0;//���������̑��x
		Enemy->angle=0;//�p�x
		//���Ƃ��A�C�e��
		for(int j=0;j<6;j++)
			Enemy->item_n[j] = Enemy_order.item_n[j];
		
      }
//�G�̍s��
void enemy_act(ENEMY *Enemy){
	
		
			enemy_pattern0(Enemy);
			Enemy->x += cos(Enemy->angle)*Enemy->speed;
			Enemy->y += sin(Enemy->angle)*Enemy->speed;
			Enemy->x += Enemy->vx;
			Enemy->y += Enemy->vy;
			Enemy->cnt++;
			Enemy->image_num = (Enemy->cnt%16)/2;
			//�G����ʂ���O�ꂽ�����
			if(Enemy->x<-50 || FIELD_MAX_X+50<Enemy->x || Enemy->y<-50 || FIELD_MAX_Y+50<Enemy->y)
				Enemy->flag=0;
		
	
}

//�`��
void enemy_Draw(ENEMY Enemy,int image){
	Enemy.img = image;
	DrawRotaGraph(Enemy.x,Enemy.y,1.0,0.0,Enemy.img,TRUE);
   
}







