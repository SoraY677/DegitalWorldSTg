#include "DxLib.h"
#include "player.h"
#include "stage.h"

int img_board[40];

//‰æ‘œ‚Ìƒ[ƒh
void load_board(){
	img_board[10]=LoadGraph("image/board1.png");
	img_board[11]=LoadGraph("image/board2.png");
	img_board[12]=LoadGraph("image/board3.png");
	img_board[20]=LoadGraph("image/board4.png");
}

//•`Ê
void graph_board(){
	DrawGraph(0,0,img_board[10],FALSE);
	DrawGraph(96,0,img_board[11],FALSE);
	DrawGraph(96,1392,img_board[12],FALSE);
	DrawGraph(1152,0,img_board[20],FALSE);
}