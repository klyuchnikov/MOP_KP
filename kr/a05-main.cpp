#include <iostream>
#include "a05.h"

#define		ESC	0x1b
// ������� ������������ ������ 
#define SIZEPMEM  64  // ������������ ������ 64 ����� �� 65536 � ��������� ATMega 128
#define SIZEDMEM 256  // ������������ ������ 128 ���� ��  4096 � ��������� ATMega 128

using namespace std;
const char nvar[] = "A05"; // ����� �������� �������
extern "C" {
USC inportd();  // ������ � ����� ����� D ����� ������������ ���������
void outportb(USC v); // ������ v � ���� B  ����� ������������ ���������
}

// �������� ��������� ������������� �������� A05
int main()
{
    SimCoreA core(SIZEPMEM, SIZEDMEM); // ������ ���� ��

    cout << "KP MOP 2012." <<endl;
    cout << "# " << nvar << ". Klyuchnikov D. EVMd-31" << endl;
    
    // ���������� ���������� �����
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
