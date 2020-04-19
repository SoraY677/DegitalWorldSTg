
#include "DxLib.h"
#include "player.h"


static PLAYER player; //プレイヤーの実体
static int m_ImgPlayer[8]; //プレイヤーの画像ハンドル

//初期化
void PlayerMgr_Init(){
	LoadDivGraph("image/主人公(仮).png",8,8,1,64,144,m_ImgPlayer);

	Player_Init(&player);
}

void PlayerMgr_calc(){
	Player_calc(&player);
}


//動作計算
void PlayerMgr_Update(){
	   Player_Movement(&player);
}

//描写
void PlayerMgr_Draw(){
	Player_Draw(player,m_ImgPlayer[player.image_num]);
}

//終了処理
void PlayerMgr_Fin(){
	Player_Fin(player);
}