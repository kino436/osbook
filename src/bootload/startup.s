	.h8300h
	.section .text
	.global	_start
	.type	_start,@function
_start:
	mov.l	#0xffff00,sp	#スタックポインタの設定
	jsr	@_main		#mainの呼び出し

1:
	bra 	1b		#無限ループ
