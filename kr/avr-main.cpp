#include "ioatm128.h"
/*
#if false

// Для поддержки 
#define  A00
// #define  A01
// #define  A02
// #define  A03
// #define  A04
// #define  A05
// #define  A06
#ifdef A00
# include "a00.h"
#endif

// Определение КОП для каскада маскоориентированных switch
#define COP_IN   0xB000
#define COP_OUT  0xB100
#define COP_LDI  0xE000
#define COP_IN   0xB000
#define COP_IN   0xB000

// Выполнение шага программы: дешифрация КОП + Запуск функции
// Возвращает 1, если команда останова, иначе 0.
int SimCoreA::step(){
    cmd = pmem[pc++];
    switch(cmd){
    case COP_NOP: nop(); break;
    case COP_BREAK: _break(); return(1);
        // дальше все команды формата FFFF
    default:
        switch(cmd & F000){
        case COP_LDI: ldi();  break;
        case COP_ORI: ori();  break;
        case COP_ANDI: andi();  break;
        case COP_RJMP: rjmp(); break;
            // дальше все команды формата F000
        default:
            switch(cmd & F800){
            case COP_IN: in(); break;
            case COP_OUT: out(); break;
            default: ;
                // дальше другие форматы
            };
        };
    };
    return 0;
}

#endif
*/