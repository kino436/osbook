PREFIX	= /usr/local
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

H8WRITE = ../tools/h8write/kz_h8write	# フラッシュ書き込みツール

H8WRITE_SERDEV = COM1	# シリアル接続先

# コンパイルされたソースコード群
OBJS	= vector.o startup.o main.o
OBJS	+= lib.o serial.o

# 生成する実行形式のファイル名
TARGET	= kzload

# コンパイルオプション
CFLAGS	= -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS	+= -mint32 # intを32ビットにすると掛け算、割り算ができなくなる
CFLAGS	+= -I.
#CFLAGS	+= -g
CFLAGS	+= -Os
CFLAGS	+= -DKZLOAD

# リンクオプション
LFLAGS	= -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

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

# モトローラSレコードフォーマットへの変換ルール
$(TARGET).mot :	$(TARGET)
		$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image :		$(TARGET).mot

# フラッシュROMへの転送
write : 	$(TARGET).mot
		$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

# フォルダの掃除
.PHONY: clean
clean :		
		rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot
