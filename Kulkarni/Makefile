TARGET = kulkarni
VAC_CPU = mips
SRCS = kulkarni.c
VAC_IFACE = $(VAC_CPU)_iface.h

CC := ecc -target mips32r2-linux
CFLAGS = -static -O0 -I$(VAC_CPU_MIPS_PATH)

TMP = /tmp

vpath $(VAC_IFACE) $(VAC_CPU_MIPS_PATH)

NBITS = 2 4 8 12 16

EXE = $(foreach N, $(NBITS), $(addsuffix .$(N).$(VAC_CPU), $(TARGET)))

all: $(EXE)

$(TARGET).%.$(VAC_CPU): $(SRCS)
	$(CC) $(CFLAGS) -DVAC_IFACE='"$(VAC_IFACE)"' -DNBITS=$* -o $(TMP)/$@ $^
	mv $(TMP)/$@ .

clean:
	rm -rf $(EXE)
