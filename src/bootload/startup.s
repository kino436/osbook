	.h8300h
	.section .text
	.global	_start
	.type	_start,@function
_start:
	mov.l	#0xffff00,sp	#�X�^�b�N�|�C���^�̐ݒ�
	jsr	@_main		#main�̌Ăяo��

1:
	bra 	1b		#�������[�v
