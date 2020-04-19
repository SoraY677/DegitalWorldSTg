
#include "DxLib.h"
#include "KEYandGAMEPAD.h"
#include "player.h"
#include "stage.h"
#include "playerMgr.h"

extern CONFIG configpad;

int imagePlayer_num;

//������
void Player_Init(PLAYER *Player){
	Player->x = FIELD_MAX_X/2;
	Player->y = FIELD_MAX_Y*3/4;
}

//�摜�̐؂�ւ�
void Player_calc(PLAYER *Player){
	Player->cnt++;
	Player->image_num = (Player->cnt%24)/ 3;
}


//�����̌v�Z
void Player_Movement(PLAYER *Player){
	double x,y,mx,my;//���W����p�ϐ�
	double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};//4�����ړ����x
	int inputpad[4];
	inputpad[0]=CheckStatePad(configpad.left);inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down);inputpad[3]=CheckStatePad(configpad.up);
	
	//4�������[�v
	for (int i=0;i<4;i++){
		if (inputpad[i]>0){
			//�Ƃ肠�������̍��W����
			x=Player->x ,y=Player->y;
			//�ړ����x�����
			mx=move_x[i]; my=move_y[i];
          //�ᑬ�ړ����Ȃ�
	      if(CheckStatePad(configpad.slow)>0){
		    //���x��1/3��
		    mx=move_x[i]/3; my=move_y[i]/3;
		  }
		  x += mx; y+=my; //�ړ��������W�ɉ��Z
		  if(!(x<FIELD_X+32 || x > FIELD_MAX_X - 32|| y<FIELD_Y + 72|| y>FIELD_MAX_Y-72)){
		  //���ۂɈړ�
		  Player->x=x , Player->y=y;
		  }
		}
	}

}

//�`�ʏ���
void Player_Draw(PLAYER Player,int image){
	Player.image = image;
	DrawRotaGraph(Player.x,Player.y,1.0,0.0,Player.image,TRUE);
}

//�I������
void Player_Fin(PLAYER Player){
	DeleteGraph(Player.image);
}

