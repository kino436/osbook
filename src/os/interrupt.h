#ifndef _INTERRUPT_H_INCLUDED_
#define _INTERRUPT_H_INCLUDED_

/* 以下は、リンカスクリプトで定義してあるシンボル */
extern char softvec;
#define SOFTVEC_ADDR (&softvec) 

typedef short softvec_type_t; /* ソフトウェア割り込みベクタの種別を表す型の定義 */

typedef void (*softvec_handler_t)(softvec_type_t type, unsigned long sp); /* 割り込みハンドラの型の定義 */

#define SOFTVECS ((softvec_handler_t *)SOFTVEC_ADDR) /* ソフトウェア割り込みベクタの位置 */

#define INTR_ENABLE asm volatile ("andc.b #0x3f,ccr") /* 割り込み有効化 */
#define INTR_DISABLE asm volatile ("orc.b #0xc0,ccr") /* 割り込み無効化 */

/* ソフトウェア割り込みベクタの初期化 */
int softvec_init(void);

/* ソフトウェア割り込みベクタの設定 */
int softvec_setintr(softvec_type_t type, softvec_handler_t handler);

/* 共通割り込みハンドラ */
void interrupt(softvec_type_t type, unsigned long sp);

#endif
