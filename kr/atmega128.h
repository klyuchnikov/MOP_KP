// vim: ts=4
#ifndef __ATMEGA128_H__
#define __ATMEGA128_H__

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include <string.h>
#include "ioatm128.h"

typedef  unsigned short USS;
typedef  unsigned long  USL;
typedef  unsigned char  USC;

#define  COP_IN     0xB000
#define  COP_OUT	0xB800
#define  COP_LDI	0xE000
#define  COP_ANDI	0x7000
#define  COP_ORI	0x6000
#define  COP_RJMP   0xC000
#define  COP_BREQ   0xF001
#define  COP_NOP    0
#define  COP_BREAK	0x9598
#define  COP_CLC	0x9488
#define  COP_SEC	0x9408

// Маски форматов команд, имеющих поля операндов (классификация команд по форматам)
#define	 F000  0xF000 // ANDI,CBR,CPI,LDI,ORI,RCALL,RJMP,SBCI,SBR,SUBI      Rd, K
#define  F800  0xF800 // IN, OUT
#define  FC00  0xFC00 // ADC,ADD,AND,BRBC,BRBS,CLR,CP,CPC,CPSE,EOR,LSL,MOV,MUL,OR,ROL,SBC,SUB,TST  Rd, Rr
#define  FE00  0xFE00 // ASR, ... Rd
#define  FF00  0xFF00 // ADIW, ... парами регистров
// ...
// Выделение флагов SREG
#define SREG_C	   ((ports[SREG]>> FL_C) & 1)
#define SET_C(v)   (((v)==1)?(ports[SREG] |= (1 << FL_C)): (ports[SREG] &= ~(1 << FL_C)))
#define SREG_Z	   ((ports[SREG] >> FL_Z) & 1)
#define SET_Z(v)   (((v)==1)?(ports[SREG]|=(1 << FL_Z)): (ports[SREG] &= ~(1 << FL_Z)))
#define SREG_N	   ((ports[SREG] >> FL_N) & 1)
#define SET_N(v)   (((v)==1)?(ports[SREG]|=(1 << FL_N)): (ports[SREG] &= ~(1 << FL_N)))
#define SREG_V	   ((ports[SREG] >> FL_V) & 1)
#define SET_V(v)   (((v)==1)?(ports[SREG]|=(1 << FL_V)): (ports[SREG] &= ~(1 << FL_V)))
#define SREG_S	   ((ports[SREG] >> FL_S) & 1)
#define SET_S(v)   (((v)==1)?(ports[SREG]|=(1 << FL_S)): (ports[SREG] &= ~(1 << FL_S)))
#define SREG_H	   ((ports[SREG] >> FL_H) & 1)
#define SET_H(v)   (((v)==1)?(ports[SREG]|=(1 << FL_H)): (ports[SREG] &= ~(1 << FL_H)))
#define SREG_T	   ((ports[SREG] >> FL_T) & 1)
#define SET_T(v)   (((v)==1)?(ports[SREG]|=(1 << FL_T)): (ports[SREG] &= ~(1 << FL_T)))
#define SREG_I	   ((ports[SREG] >> FL_I) & 1)
#define SET_I(v)   (((v)==1)?(ports[SREG]|=(1 << FL_I)): (ports[SREG] &= ~(1 << FL_I)))

// Модель ядра микроконтроллера
class SimCore {
public:
    USL clock;		// Счетчик тактов
    USS pc;			// Счетчик команд
    USS cmd; 		// Регистр команд (16-разрядный код команды)
    USS *pmem;		// Память команд
    USS lenpmem;    // Число слов программной памяти
    USC *dmem;		// Память данных
    USS lendmem;    // Число слов программной памяти
    USC *reg;		// Указатель на область регистров
    USC *ports;		// Указатель на область портов
    std::ofstream fileLog;   // Файл протокола

    SimCore(USL sizepmem, USL sizedmem);
    // virtual int step();
    void outLog(const char fmtstring[], ... /* args */);
    virtual void showStat();
    virtual void showPMem(int start, int end);
    virtual void showDMem(int start, int end);
    virtual void show(); // Показ состояния объектов
    // Модели команд
    virtual void in() {		outLog("#IN"); clock++; }
    virtual void out()  {	outLog("#OUT"); clock++; }
    virtual void nop()  {	outLog("#NOP"); clock++; }
    virtual void _break() {	outLog("#BREAK"); clock++; }
    virtual void ldi()  {	outLog("#LDI"); clock++; }
    virtual void andi() {	outLog("#ANDI"); clock++; }
    virtual void ori() { 	outLog("#ORI"); clock++; }
    virtual void rjmp() {	outLog("#RJMP"); clock += 2; }
    virtual void sec()  {	outLog("#SEC"); SET_C(1); clock++; }
    virtual void clc()  {	outLog("#CLC"); SET_C(0); clock++; }
};	


int getch();

#endif
