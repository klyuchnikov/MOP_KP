#ifndef __A00_H__
#define __A00_H__

#include "atmega128.h"

// SUBI             0101 kkkk dddd kkkk
#define COP_SUBI    0x5000
#define IS_SUBI     ((cmd & 0xF000) == COP_SUBI)
#define d_SUBI     (cmd >> 4 & 0xF)
#define K_SUBI      ((cmd & 0xF) | (cmd >> 4 & 0xF0))
#define SUBI(d, k)  (COP_SUBI | (k & 0xF) | (k << 4 & 0xF00) | (d << 4 & 0xF0))

// DEC              1001 010d dddd 1010
#define COP_DEC		0x940A
#define IS_DEC		((cmd & 0xFE0F) == COP_DEC)
#define d_DEC		(cmd >> 4 & 0x1F)
#define DEC(d)		(COP_DEC | (d << 4 & 0x1F0))

// ICALL            1001 0101 xxxx 1001
#define COP_ICALL	0x9509
#define IS_ICALL    ((cmd & 0xFF0F) == COP_ICALL)
#define X_ICALL     (cmd >> 4 & 0xF)
#define ICALL	    COP_ICALL

// BREQ             1111 00kk kkkk k001
#define COP_BREQ    0xF001
#define IS_BREQ     ((cmd & 0xFC07) == COP_BREQ)
#define K_BREQ      (cmd >> 3 & 0x7F)
#define BREQ(k)     (COP_BREQ | ((k) << 3 & 0x3F8))

// BRVS             1111 00kk kkkk k011
#define COP_BRVS    0xF003
#define IS_BRVS     ((cmd & 0xFC07) == COP_BRVS)
#define K_BRVS      (cmd >> 3 & 0x7F)
#define BRVS(k)     (COP_BRVS | ((k) << 3 & 0x3F8))

// LD Rd, Z         1000 000d dddd 0000
#define COP_LDDZ    0x8000
#define IS_LDDZ     ((cmd & 0xFE0F) == COP_LDDZ)
#define d_LDDZ      (cmd >> 4 & 0x1F)
#define LDDZ(d)     (COP_LDDZ | ((d) << 4 & 0x1F0))

// LSR             1001 010d dddd 0110
#define COP_LSR    0x9406
#define IS_LSR     ((cmd & 0xFC0F) == COP_LSR)
#define d_LSR      (cmd >> 4 & 0x1F)
#define LSR(k)     (COP_LSR | ((k) << 4 & 0x1F0))

// CLZ              1001 0100 1001 1000
#define COP_CLZ     0x9498
#define IS_CLZ      (cmd == COP_CLZ)
#define CLZ         COP_CLZ

// SEZ              1001 0100 0001 1000
#define COP_SEZ     0x9418
#define IS_SEZ      (cmd == COP_SEZ)
#define SEZ         COP_SEZ

class SimCoreA: public SimCore {
public:
    SimCoreA(USL sizepmem, USL sizedmem);
    int step();

	void subi();
	void dec();
	void icall();
	void breq();
	void brvs();
	void lddz();
	void lsr();
	void clz();
	void sez();
	void test_dec();
};

#endif
