#include "defines.h"

extern void start(void);	/* �X�^�[�g�A�b�v */

/*
 * ���荞�݃x�N�^�̐ݒ�
 * �����J�X�N���v�g�̒�`�ɂ��A�擪�Ԓn�ɔz�u�����B
 */
void (*vectors[])(void) = {
	start, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
};	// start()�ւ̃|�C���^��ݒ�
