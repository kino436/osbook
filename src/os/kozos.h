#ifndef _KOZOS_H_INCLUDED_
#define _KOZOS_H_INCLUDED_

#include "defines.h"
#include "syscall.h"

/* システム・コール */
kz_thread_id_t kz_run(kz_func_t func, char *name, int stacksize, int argc, char *argv[]);	/* スレッド起動 */
void kz_exit(void); /* スレッド終了 */

/* ライブラリ関数 */
void kz_start(kz_func_t func, char *name, int stacksize, int argc, char *argv[]);	/* 初期スレッドを起動し、OS動作開始 */
void kz_sysdown(void);	/* 致命的なエラーのとき呼び出す */
void kz_syscall(kz_syscall_type_t type, kz_syscall_param_t *param); /* システム・コールを実行 */

/* ユーザ・スレッド */
int test08_1_main(int argc, char *argv[]);	/* ユーザ・スレッドのメイン関数 */

#endif
