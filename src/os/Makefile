PREFIX	= ~/osbook/tools
ARCH 	= h8300-elf
BINDIR	= $(PREFIX)/bin
ADDNAME	= $(ARCH)-

# 利用するツール類の指定
AR	= $(BINDIR)/$(ADDNAME)ar
AS	= $(BINDIR)/$(ADDNAME)as
CC	= $(BINDIR)/$(ADDNAME)gcc
LD	= $(BINDIR)/$(ADDNAME)ld
NM	= $(BINDIR)/$(ADDNAME)nm
OBJCOPY	= $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP	= $(BINDIR)/$(ADDNAME)objdump
RANLIB	= $(BINDIR)/$(ADDNAME)ranlib
STRIP	= $(BINDIR)/$(ADDNAME)strip

# コンパイルされたソースコード群
OBJS	= startup.o main.o interrupt.o
OBJS	+= lib.o serial.o

# sources of kozos
OBJS	+= kozos.o syscall.o test08_1.o

# 生成する実行形式のファイル名
TARGET	= kozos

# コンパイルオプション
CFLAGS	= -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS	+= -mint32 # intを32ビットにすると掛け算、割り算ができなくなる
CFLAGS	+= -I.
#CFLAGS	+= -g
CFLAGS	+= -Os
CFLAGS	+= -DKOZOS

# リンクオプション
LFLAGS	= -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o
.SUFFIXES: .S .o

all :		$(TARGET)

# 実行形式の生成ルール
$(TARGET) :	$(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
		cp $(TARGET) $(TARGET).elf
		$(STRIP) $(TARGET)

# *.cファイルのコンパイルルール
.c.o :		$<
		$(CC) -c $(CFLAGS) $<

# *.sファイルのコンパイルルール
.s.o :		$<
		$(CC) -c $(CFLAGS) $<

# *.Sファイルのコンパイルルール
.S.o :		$<
		$(CC) -c $(CFLAGS) $<


# フォルダの掃除
.PHONY: clean
clean :		
		rm -f $(OBJS) $(TARGET) $(TARGET).elf
