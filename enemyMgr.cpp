#include "DxLib.h"
#include "enemy.h"
#include "enemy_data.h"

static ENEMY enemy[ENEMY_MAX];//“G‚ÌÀ‘Ì
extern ENEMY_ORDER enemy_order[ENEMY_ORDER_MAX];
extern int stage_count;
static int m_ImgEnemy[8];//“G‚Ì‰æ‘œŠi”[ƒnƒ“ƒhƒ‹

void enemyMgr_init(){
	LoadDivGraph("image/enemy2.png",8,8,1,96,96,m_ImgEnemy);

	enemy_init();
}

//‚ ‚¢‚Ä‚¢‚é“G”Ô†‚ğ•Ô‚·
int enemy_num_search(){
	for(int i=0;i<ENEMY_MAX;i++){
		if(enemy[i].flag==0){
			return i;
		}
	}
		return -1;//‘S•”–„‚Ü‚Á‚Ä‚¢‚½ê‡‚ÍƒGƒ‰[‚ğ•Ô‚·
	
}


void enemyMgr_enter(){ 
	int i,t;
	for(t=0;t<ENEMY_ORDER_MAX;t++){
		if (enemy_order[t].cnt==stage_count){
			if((i=enemy_num_search())!=-1){
	     enemy_enter(&enemy[i],enemy_order[t]);
	  }
    }
   }
}


void enemyMgr_act(){
	for(int i=0; i<ENEMY_MAX;i++){
		if(enemy[i].flag==1){
	     enemy_act(&enemy[i]);
	   }
    }
}
void enemyMgr_Draw(){
	int i;
	for (i=0;i<ENEMY_MAX;i++){
		if(enemy[i].flag==1){
			enemy_Draw(enemy[i],m_ImgEnemy[enemy[i].image_num]);
		}
    }
}

