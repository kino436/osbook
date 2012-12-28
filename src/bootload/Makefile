PREFIX	= /usr/local
ARCH 	= h8300-elf
BINDIR	= $(PREFIX)/bin
ADDNAME	= $(ARCH)-

# ���p����c�[���ނ̎w��
AR	= $(BINDIR)/$(ADDNAME)ar
AS	= $(BINDIR)/$(ADDNAME)as
CC	= $(BINDIR)/$(ADDNAME)gcc
LD	= $(BINDIR)/$(ADDNAME)ld
NM	= $(BINDIR)/$(ADDNAME)nm
OBJCOPY	= $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP	= $(BINDIR)/$(ADDNAME)objdump
RANLIB	= $(BINDIR)/$(ADDNAME)ranlib
STRIP	= $(BINDIR)/$(ADDNAME)strip

H8WRITE = ../tools/h8write/kz_h8write	# �t���b�V���������݃c�[��

H8WRITE_SERDEV = COM1	# �V���A���ڑ���

# �R���p�C�����ꂽ�\�[�X�R�[�h�Q
OBJS	= vector.o startup.o main.o
OBJS	+= lib.o serial.o

TARGET	= kzload	# ����������s�`���̃t�@�C����

# �R���p�C���I�v�V����
CFLAGS	= -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS	+= -mint32 # int��32�r�b�g�ɂ���Ɗ|���Z�A����Z���ł��Ȃ��Ȃ�
CFLAGS	+= -I.
#CFLAGS	+= -g
CFLAGS	+= -Os
CFLAGS	+= -DKZLOAD

# �����N�I�v�V����
LFLAGS	= -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all :		$(TARGET)

# ���s�`���̐������[��
$(TARGET) :	$(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
		cp $(TARGET) $(TARGET).elf
		$(STRIP) $(TARGET)

# *.c�t�@�C���̃R���p�C�����[��
.c.o :		$<
		$(CC) -c $(CFLAGS) $<

# *.s�t�@�C���̃R���p�C�����[��
.s.o :		$<
		$(CC) -c $(CFLAGS) $<

# ���g���[��S���R�[�h�t�H�[�}�b�g�ւ̕ϊ����[��
$(TARGET).mot :	$(TARGET)
		$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image :		$(TARGET).mot

# �t���b�V��ROM�ւ̓]��
write : 	$(TARGET).mot
		$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

# �t�H���_�̑|��
clean :		\rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot