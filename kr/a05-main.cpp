#include <iostream>
#include "a05.h"

#define		ESC	0x1b
// Размеры моделируемой памяти 
#define SIZEPMEM  64  // моделируются первые 64 слова из 65536 у реального ATMega 128
#define SIZEDMEM 256  // моделируются первые 128 слов из  4096 у реального ATMega 128

using namespace std;
const char nvar[] = "A05"; // Номер варианта проекта
extern "C" {
USC inportd();  // Чтение с пинов порта D через ассемблерную программу
void outportb(USC v); // Запись v в порт B  через ассемблерную программу
}

// Основная программа моделирования варианта A05
int main()
{
    SimCoreA core(SIZEPMEM, SIZEDMEM); // Модель ядра МК

    cout << "KP MOP 2012." <<endl;
    cout << "# " << nvar << ". Klyuchnikov D. EVMd-31" << endl;
    
    // Повторение командного цикла
    do {
        core.show();
        cout << "\nEnter -- next step. Esc -- exit";

        if (getch() == ESC)
            break;
    } while (core.step() == 0);
    core.show();
    cout << "\nNormal termination. Press any key to close.\n";
    getch();
    return 0;
}
