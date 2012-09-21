#include "a05.h"
// Модели команд для варианта A05
#include <iostream>

using namespace std;

#define B(v, n) ((v) >> (n) & 1)
#define N(v, n) (! B(v, n))

static const USS CMDS[] = {
	SUBI(2, 3),
	SUBI(3, 9),
	DEC(2),
	DEC(3),
	ICALL,
	SEZ,
	BREQ(2),
	BRVS(2),
	LDDZ(2),
	LSR(2),
	CLZ
};

SimCoreA::SimCoreA(USL sizepmem, USL sizedmem) : SimCore(sizepmem,sizedmem) {
	memcpy(pmem, CMDS, sizeof CMDS);
	reg[0] = 1; // setup registers
	reg[1] = 8;
	reg[2] = 0xDF;
	reg[3] = 0x88;
	reg[4] = 0x7F;
	reg[6] = 0x21;
	reg[7] = 0x45;
	reg[8] = 0x11;

	reg[31] = 0;  // Set Z
	reg[30] = 6;

	ports[SPL] = 200; // setup stack
	ports[SPH] = 0;

	dmem[200] = 0; // return address
	dmem[201] = 0;
}


void SimCoreA::subi() {
	USC Rd = reg[d_SUBI];
	int k = K_SUBI;
	USC R  = Rd - k;
	reg[d_SUBI] = R;	

	outLog("SUBI R%d, K\t; %d = %d - %d", d_SUBI, R, Rd, k);

	SET_H(N(Rd, 3) && B(k, 3)  ||  B(k, 3) && B(R, 3)  ||  B(R, 3) && N(Rd, 3));
	SET_V(B(Rd, 7) && N(k, 7) && N(R, 7)  ||  N(Rd, 7) && B(k, 7) && B(R, 7));
	SET_N(B(R, 7));
	SET_Z(R == 0);
	SET_C(N(Rd, 7) && B(k, 7)  ||  B(k, 7) && B(R, 7)  ||  B(R, 7) && N(Rd, 7));
	SET_S(SREG_N ^ SREG_V);

	clock++;
}

void SimCoreA::dec() {
	USC Rd = reg[d_DEC];
	Rd--;
	reg[d_DEC] = Rd;

	outLog("DEC R%d\t\t; R%d --=1; R%d=%d", d_DEC, d_DEC, d_DEC, Rd);

	SET_S(SREG_N ^ SREG_V);
	SET_N(B(Rd, 7));
	SET_Z(Rd == 0);
	SET_V(B(Rd, 7) && N(Rd, 6) && N(Rd, 5) && N(Rd, 4) && B(Rd, 3) && B(Rd, 3) && B(Rd, 2) && B(Rd, 1) && B(Rd, 0));

	clock++;
}


void SimCoreA::icall() {

	USS z = (reg[31] << 8) | reg[30];

	outLog("ICALL\t\t;");

	USS stack = pc + 1;
	USS sp = ports[SPH] << 8 || ports[SPL];
	dmem[sp - 1] = stack >> 8 & 0xFF;
	dmem[sp] = stack & 0xFF;

	sp -= 2;
	ports[SPH] = sp >> 8 & 0xFF;
	ports[SPL] = sp & 0xFF;

	pc = --z;

	clock += 3;

}

void SimCoreA::breq(){

	int k = K_BREQ;
	if (B(k, 6))
		k -= 128;

	if (SREG_Z == 1) {
		outLog("BREQ %d\t\t; jump %d, Z==1", K_BREQ, k);
		pc += k;
		clock += 2;
	} else{
		outLog("BREQ %d\t\t; not jump %d, Z==0", K_BREQ, k);
		clock++;
	}
}

void SimCoreA::brvs(){

	int k = K_BRVS;
	if (B(k, 6))
		k -= 128;

	if (SREG_V == 1) {
		outLog("BRVS %d\t\t; jump %d, V==1", K_BREQ, k);
		pc += k;
		clock += 2;
	} else{
		outLog("BRVS %d\t\t; not jump %d, V==0", K_BREQ, k);
		clock++;
	}
}


void SimCoreA::lddz() {
	USS z = (reg[31] << 8) | reg[30];
	reg[d_LDDZ] = dmem[z];

	outLog("LD R%d, Z\t; R%d = %d", d_LDDZ, d_LDDZ, reg[d_LDDZ]);
	clock += 2;
}

void SimCoreA::lsr() {

	USC Rd = reg[d_LSR];
	USC R = reg[d_LSR] >> 1;
	reg[d_LSR] = R;

	outLog("LSR R%d\t\t; %d = %d >> 1", d_LSR, R, Rd);

	SET_S(SREG_N ^ SREG_V);
	SET_V(SREG_N ^ SREG_C);
	SET_N(0);
	SET_Z(N(R, 7) && N(R, 6) && N(R, 5) && N(R, 4) && N(R, 3) && N(R, 2) && N(R, 1) && N(R, 0));
	SET_C(B(Rd, 0));

	clock++;
}


void SimCoreA::clz() {

	SET_Z(0);
	outLog("CLZ\t\t; Z = 0");
	clock++;
}


void SimCoreA::sez() {

	SET_Z(1);
	outLog("SEZ\t\t; Z = 1");
	clock++;
}


void SimCoreA::test_dec() {
    outLog("TEST_DEC");
    cout << "Test 1" << endl;
    cmd = DEC(0);
    reg[0] = 11;
    SET_V(1);
    SET_S(1);
    SET_N(1);
    SET_Z(0);
    show();
    dec();
    show();
    cout << endl;

    cout << "Test 2" << endl;
    cmd = DEC(0);
    reg[0] = 0x40;
    SET_V(1);
    SET_S(1);
    SET_N(0);
    SET_Z(1);
    show();
    dec();
    show();
    outLog("END_TEST_DEC");
}

int SimCoreA::step(){
	cmd = pmem[pc++];

	if (IS_SUBI)	subi();
	else if (IS_DEC)	dec();
	else if (IS_ICALL)	icall();
	else if (IS_BREQ)	breq();
	else if (IS_BRVS)	brvs();
	else if (IS_LDDZ)	lddz();
	else if (IS_LSR)	lsr();
	else if (IS_CLZ)	clz();
	else if (IS_SEZ)	sez();
	else {
		outLog("%02x %02x", cmd >> 8 & 0xFF, cmd & 0xFF);
		return 1;
	}

	return 0;
}
