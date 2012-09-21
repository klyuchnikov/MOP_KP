#include "atmega128.h"
//
SimCore::SimCore(USL sizepmem, USL sizedmem){
    clock = 0;
    lenpmem = sizepmem;
    lendmem = sizedmem;
    pmem = (USS *) malloc(lenpmem*sizeof(USS));
    dmem = (USC *) malloc(lendmem);
    memset(pmem,0,sizepmem*sizeof(USS));
    memset(dmem,0,sizedmem);
    pc = 0;
    reg  = dmem;
    ports = dmem+32;
    fileLog.open("log.dat", std::ios::out);
    fileLog << "  Cycle  PC    Command\n";
}

// Вывод аргументов, форматируемых форматной строкой fmtstring
// в файл протокола fileLog
void SimCore::outLog(const char fmtstring[], ... /* args */){
    char buf[128];
    va_list ap;
    va_start(ap, fmtstring);
    sprintf(buf,"%6ld %04X: ", clock, pc);
    vsprintf(strchr(buf, 0), fmtstring, ap);
    fileLog << buf << "\n";
    fileLog.flush();
}

// Вывод на консоль состояния МК
void  SimCore::showStat(){
    using namespace std;
    cout << "\nCycles "  << "      PC  ";
    cout << " C " << "Z " << "N " << "V " << "S " << "H "<< "T "<< "I\n";
    cout.width(8);
    cout.fill('0');
    cout << clock << "    ";
    cout.width(4);
    cout << hex << pc << "  ";
    cout << SREG_C << " ";
    cout << SREG_Z << " ";
    cout << SREG_N << " ";
    cout << SREG_V << " ";
    cout << SREG_S << " ";
    cout << SREG_H << " ";
    cout << SREG_T << " ";
    cout << SREG_I;
}

// Дамп программной памяти от адреса start (д.б. кратен 8) до адреса end
void  SimCore::showPMem(int start, int end){
    using namespace std;
    int n;
    cout << "\npmem:  ";
    for (n = 0; n < 8; n++) {
        cout.width(4);
        cout.fill('0');
        cout << hex << n;
        cout << "  ";
    }

    for (n = start; n <= end; n++) {
        if (n % 8 == 0) {
            cout << "\n";
            cout.width(4);
            cout.fill('0');
            cout << n << " ";
        }
        cout << "  ";
        cout.width(4);
        cout.fill('0');
        cout << hex << pmem[n];
    }

}

// Дамп памяти данных от адреса start (д.б. кратен 16)  до адреса end
void  SimCore::showDMem(int start, int end){
    using namespace std;
    int n;
    cout << "\ndmem: ";
    for (n = 0; n < 16; n++) {
        cout << " ";
        cout.width(2);
        cout.fill('0');
        cout << hex << n;
    }
    for (n = start; n <= end; n++) {
        if (n % 16 == 0) {
            cout << "\n";
            cout.width(4);
            cout.fill('0');
            cout << n << "  ";
        }
        cout <<  " ";
        cout.width(2);
        cout.fill('0');
        cout << hex << (USS)dmem[n];
    }

}

void SimCore::show(){
    showStat();
    showPMem(0, lenpmem-1);
    showDMem(0, lendmem-1);
}

int getch() {
    int c;
    scanf("%c", &c);
    return c;
}

