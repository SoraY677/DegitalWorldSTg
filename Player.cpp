
#include "DxLib.h"
#include "KEYandGAMEPAD.h"
#include "player.h"
#include "stage.h"
#include "playerMgr.h"

extern CONFIG configpad;

int imagePlayer_num;

//初期化
void Player_Init(PLAYER *Player){
	Player->x = FIELD_MAX_X/2;
	Player->y = FIELD_MAX_Y*3/4;
}

//画像の切り替え
void Player_calc(PLAYER *Player){
	Player->cnt++;
	Player->image_num = (Player->cnt%24)/ 3;
}


//動きの計算
void Player_Movement(PLAYER *Player){
	double x,y,mx,my;//座標代入用変数
	double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};//4方向移動速度
	int inputpad[4];
	inputpad[0]=CheckStatePad(configpad.left);inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down);inputpad[3]=CheckStatePad(configpad.up);
	
	//4方向ループ
	for (int i=0;i<4;i++){
		if (inputpad[i]>0){
			//とりあえず今の座標を代入
			x=Player->x ,y=Player->y;
			//移動速度も代入
			mx=move_x[i]; my=move_y[i];
          //低速移動中なら
	      if(CheckStatePad(configpad.slow)>0){
		    //速度を1/3に
		    mx=move_x[i]/3; my=move_y[i]/3;
		  }
		  x += mx; y+=my; //移動分を座標に加算
		  if(!(x<FIELD_X+32 || x > FIELD_MAX_X - 32|| y<FIELD_Y + 72|| y>FIELD_MAX_Y-72)){
		  //実際に移動
		  Player->x=x , Player->y=y;
		  }
		}
	}

}

//描写処理
void Player_Draw(PLAYER Player,int image){
	Player.image = image;
	DrawRotaGraph(Player.x,Player.y,1.0,0.0,Player.image,TRUE);
}

//終了処理
void Player_Fin(PLAYER Player){
	DeleteGraph(Player.image);
}

