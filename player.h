
#ifndef DEF_PLAYER_H //二重インクルード禁止

#define DEF_PLAYER_H

//プレイヤーの構造体
typedef struct{
	double x,y;//座標
	int image;//画像
    int cnt;//カウント
	int image_num;//画像の番号
}PLAYER;

void Player_Init(PLAYER *Player);

void Player_calc(PLAYER *Player);

void Player_Movement(PLAYER *Player);

void Player_Draw(PLAYER Player,int image);

void Player_Fin(PLAYER Player);

#endif 