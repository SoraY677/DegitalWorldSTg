#include "DxLib.h"
#include "KEYandGAMEPAD.h"
#include "playerMgr.h"
#include "stage.h"
#include "enemyMgr.h"
#include "enemy_data.h"

//���[�v���ɍs������
int ProcessLoop(){
	Keyboard_Update();//�L�[�{�[�h�̓��͏�Ԃ̍X�V
	GetHitPadStateAll();//�Q�[���p�b�h�̓��͏�Ԃ̍X�V
	return 0;
}

int func_state = 0;//�����̏��
int stage_count;


//���C���v���O����
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	//�E�B���h�E���[�h�ύX,DxLib��������,����ʏ���,�w�i�𔒂ɐݒ�
	ChangeWindowMode(FALSE),DxLib_Init(),SetDrawScreen( DX_SCREEN_BACK),SetGraphMode(1920,1440,16),SetBackgroundColor(255,255,255);

	

	//���[�v(�\��ʂɕ`��,���b�Z�[�W����,��ʃN���A,���[�v���ɍs�����̑��̏���)
	while (ScreenFlip()==0  && ProcessMessage()==0 && ClearDrawScreen()==0 && ProcessLoop()==0 ){

		//func_state�̒l�ɂ���ď������e��ς���
		switch(func_state){

	    //�ŏ��̏�����
		case 0:
			    pad_init();//�Q�[���p�b�h�̃R���t�B�O������
                func_state=99;  
			    break;

        //�X�e�[�W�O������
		case 99:
			load_story();//�f�[�^�ǂݍ���
			PlayerMgr_Init();//�v���C���[�̏�����
			enemyMgr_init();//�G�̏�����
			load_board();//�{�[�h�̃��[�h
			func_state=100;
			break;

		//�X�e�[�W���̏���
		case 100:
			stage_count++;

			enemyMgr_enter();//�G�o�^


			PlayerMgr_calc();
			PlayerMgr_Update();//�v���C���[�̓���
			enemyMgr_act();//�G�̓���
			
            PlayerMgr_Draw();//�v���C���[�̕`��
			enemyMgr_Draw();//�G�̕`��
            graph_board();//�{�[�h�̕`��

			
		    break;

	    //�G���[���N�����Ƃ�
	    default:
			printfDx("�s���ȃG���[");
			break;
		
		}
		if(Keyboard_Get(KEY_INPUT_ESCAPE)==1) break;

	}

	PlayerMgr_Fin();//�v���C���[�̏I������

	DxLib_End();
	return 0;
}
