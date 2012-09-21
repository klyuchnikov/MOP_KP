/*  ioatm128.h - определение адресов внешних регистров ATMega128 
    nvn:  апрель 2009
 */
#ifndef __IOATM128_H__
#define __IOATM128_H__

// АЦП
#define  ADC       	0x04  
#define  ADCL      	0x04   // младлий байт кода АЦП
#define  ADCH      	0x05   // старший байт кода АЦП
#define  ADCSR     	0x06  // регистр состояния-упраления
#define  ADMUX		0x07  // мультиплексор входов
#define  ACSR       0x08  // регистр состояния-управления
// UART 
#define  UBRR       0x09  // Baud Rate Register
#define  UCR        0x0A  // Control Register
#define  USR        0x0B  // Status Register
#define  UDR        0x0C  // Data Register
// SPI 
#define  SPCR       0x0D  //  Control Register
#define  SPSR       0x0E  // Status Register 
#define  SPDR       0x0F  // I/O Data Register
// Port D 
#define  PIND       0x10  // Input Pins, 
#define  DDRD       0x11  // Data Direction Register
#define  PORTD      0x12  // Data Register
// Port C 
#define  PINC       0x13  // Input Pins
#define  DDRC       0x14  // Data Direction Register
#define  PORTC      0x15  // Data Register
//  Port B
#define  PINB       0x16  // Input Pins
#define  DDRB       0x17  // Data Direction Register
#define  PORTB      0x18  // Data Register
// Port A 
#define  PINA       0x19  // Input Pins
#define  DDRA       0x1A  // Data Direction Register
#define  PORTA      0x1B  // Data Register
// EEPROM 
#define  EECR       0x1C  // Control Register
#define  EEDR       0x1D  // Data Register 
#define EEAR        0x1E  // Address Register
#define  EEARL      0x1E  //   младший байт
#define  EEARH      0x1F  //   старший байт
// Watchdog Timer Control Register
#define  WDTCR      0x21
/* Asynchronous mode Status Register */
#define  ASSR       0x22
// Восьмиразрядный таймер-счетчик T/C 2  
#define  OCR2       0x23  // Output Compare Register
#define  TCNT2      0x24  // Timer/Counter 2 
#define  TCCR2      0x25  // Control Register
// Шестнадцатиразрядный таймер-счетчик T/C 1  
#define  ICR1       0x26  // Регистр захвата (Input Capture Register)
#define  ICR1L      0x26  //   младший байт
#define  ICR1H      0x27  //   старший байт
#define  OCR1B      0x28  // Регистр сравнения B 
#define  OCR1BL     0x28  //   младший байт
#define  OCR1BH     0x29  //   старший байт
#define  OCR1A      0x2A  // Регистр сравнения A
#define  OCR1AL     0x2A  //   младший байт
#define  OCR1AH     0x2B  //   старший байт
#define  TCNT1      0x2C  //  Счетчик 
#define  TCNT1L     0x2C  //   младший байт
#define  TCNT1H     0x2D  //   старший байт
#define  TCCR1B     0x2E  //  Регистр управления-состояния B 
#define  TCCR1A     0x2F  //  Регистр управления A 
// Восьмиразрядный таймер счетчик Timer/Counter 0
#define  TCNT0      0x32  // Счетчик
#define  TCCR0      0x33  // Control Register
// Общий регистр состояния МК (MCU general Status Register) 
#define  MCUSR      0x34
// Общий регистр управления МК ( MCU general Control Register)
#define  MCUCR      0x35
// Регистр флагов прерываний от таймеров-счетчиков
#define  TIFR       0x38
// Регистр маски прерываний от таймеров-счетчиков
#define  TIMSK      0x39
// Общий регистр флагов прерываний
#define  GIFR       0x3A
// Общий регистр маски прерываний 
#define  GIMSK      0x3B
// Указатель стека
#define  SP         0x3D
#define  SPL        0x3D  //   младший байт
#define  SPH        0x3E  //   старший байт
// Регистр состояния
#define  SREG       0x3F

// Векторы прерываний
#define    RESET_vect           (0x00)
#define    INT0_vect            (0x02)
#define    INT1_vect            (0x04)
#define    TIMER2_COMP_vect     (0x06)
#define    TIMER2_OVF_vect      (0x08)
#define    TIMER1_CAPT1_vect    (0x0A)
#define    TIMER1_COMPA_vect    (0x0C)
#define    TIMER1_COMPB_vect    (0x0E)
#define    TIMER1_OVF1_vect     (0x10)
#define    TIMER0_OVF0_vect     (0x12)
#define    SPI_STC_vect         (0x14)
#define    UART_RX_vect         (0x16)
#define    UART_UDRE_vect       (0x18)
#define    UART_TX_vect         (0x1A)
#define    ADC_vect             (0x1C)
#define    EE_RDY_vect          (0x1E)
#define    ANA_COMP_vect        (0x20)

      //  === Номера разрядов битовых полей  === //
// Разряды SREG
#define    FL_C        0  // флаг переноса C
#define    FL_Z        1  // флаг нуля Z
#define    FL_N        2  // флаг отрицательного знака результата N
#define    FL_V        3  // флаг переполнения V
#define    FL_S        4  // флаг фактического знака результата S
#define    FL_H        5  // флаг переноса из полубайта H
#define    FL_T        6  // флаг копирования T
#define    FL_I        7  // флаг общего разрешения пререваний I
			
/* MCU general Status Register */    
#define    EXTRF       1
#define    PORF        0
/* General Interrupt MaSK register */
#define    INT1        7
#define    INT0        6
/* General Interrupt Flag Register */
#define    INTF1       7
#define    INTF0       6                   
/* Timer/Counter Interrupt MaSK register */
#define    OCIE2       7 
#define    TOIE2       6 
#define    TICIE1      5
#define    OCIE1A      4
#define    OCIE1B      3
#define    TOIE1       2
#define    TOIE0       0
/* Timer/Counter Interrupt Flag register */
#define    OCF2         7
#define    TOV2         6
#define    ICF1         5
#define    OCF1A        4
#define    OCF1B        3
#define    TOV1         2
#define    TOV0         0
/* MCU general Control Register */ 
#define    SE           6
#define    SM1          5
#define    SM0          4
#define    ISC11        3
#define    ISC10        2
#define    ISC01        1
#define    ISC00        0
/* Timer/Counter 0 Control Register */
#define    CS02         2
#define    CS01         1
#define    CS00         0
/* Timer/Counter 1 Control Register */
#define    COM1A1       7
#define    COM1A0       6
#define    COM1B1       5
#define    COM1B0       4
#define    PWM11        1
#define    PWM10        0
/* Timer/Counter 1 Control and Status Register */
#define    ICNC1        7
#define    ICES1        6
#define    CTC1         3
#define    CS12         2
#define    CS11         1
#define    CS10         0
/* Timer/Counter 2 Control Register */
#define    PWM2         6
#define    COM21        5
#define    COM20        4
#define    CTC2         3
#define    CS22         2
#define    CS21         1
#define    CS20         0
/* Asynchronous mode Status Register */
#define    AS2          3
#define    TCN2UB       2
#define    OCR2UB       1
#define    TCR2UB       0
/* Watchdog Timer Control Register */                         
#define    WDTOE        4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0    
 /* EEPROM Control Register */
#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0
/* Data Register, Port A */ 
#define    PA7      7
#define    PA6      6
#define    PA5      5
#define    PA4      4
#define    PA3      3
#define    PA2      2
#define    PA1      1
#define    PA0      0
/* Data Direction Register, Port A */
#define    DDA7     7
#define    DDA6     6
#define    DDA5     5
#define    DDA4     4
#define    DDA3     3
#define    DDA2     2
#define    DDA1     1
#define    DDA0     0
/* Input Pins, Port A */
#define    PINA7    7
#define    PINA6    6
#define    PINA5    5
#define    PINA4    4
#define    PINA3    3
#define    PINA2    2
#define    PINA1    1
#define    PINA0    0
/* Data Register, Port B */  
#define    PB7      7
#define    PB6      6
#define    PB5      5
#define    PB4      4
#define    PB3      3
#define    PB2      2
#define    PB1      1
#define    PB0      0
/* Data Direction Register, Port B */
#define    DDB7     7
#define    DDB6     6
#define    DDB5     5
#define    DDB4     4
#define    DDB3     3
#define    DDB2     2
#define    DDB1     1
#define    DDB0     0
/* Input Pins, Port B */
#define    PINB7    7
#define    PINB6    6
#define    PINB5    5
#define    PINB4    4
#define    PINB3    3
#define    PINB2    2
#define    PINB1    1
#define    PINB0    0
/* Data Register, Port C */
#define    PC7      7
#define    PC6      6
#define    PC5      5
#define    PC4      4
#define    PC3      3
#define    PC2      2
#define    PC1      1
#define    PC0      0
/* Data Direction Register, Port C */
#define    DDC7     7
#define    DDC6     6
#define    DDC5     5
#define    DDC4     4
#define    DDC3     3
#define    DDC2     2
#define    DDC1     1
#define    DDC0     0
/* Input Pins, Port C */
#define    PINC7    7
#define    PINC6    6
#define    PINC5    5
#define    PINC4    4
#define    PINC3    3
#define    PINC2    2
#define    PINC1    1
#define    PINC0    0
/* Data Register, Port D */
#define    PD7      7
#define    PD6      6
#define    PD5      5
#define    PD4      4
#define    PD3      3
#define    PD2      2
#define    PD1      1
#define    PD0      0
/* Data Direction Register, Port D */
#define    DDD7     7
#define    DDD6     6
#define    DDD5     5
#define    DDD4     4
#define    DDD3     3
#define    DDD2     2
#define    DDD1     1
#define    DDD0     0
/* Input Pins, Port D */
#define    PIND7     7
#define    PIND6     6
#define    PIND5     5
#define    PIND4     4
#define    PIND3     3
#define    PIND2     2
#define    PIND1     1
#define    PIND0     0
/* SPI Control Register */
#define    SPIE     7
#define    SPE      6
#define    DORD     5
#define    MSTR     4
#define    CPOL     3
#define    CPHA     2
#define    SPR1     1
#define    SPR0     0
/* SPI Status Register */
#define    SPIF     7
#define    WCOL     6
/* UART Status Register */
#define    RXC      7
#define    TXC      6
#define    UDRE     5
#define    FE       4
#define    OR       3
/* UART Control Register */
#define    RXCIE    7
#define    TXCIE    6
#define    UDRIE    5
#define    RXEN     4
#define    TXEN     3
#define    CHR9     2
#define    RXB8     1
#define    TXB8     0
/* Analog Comparator Control and Status Register */
#define    ACD      7
#define    ACO      5
#define    ACI      4
#define    ACIE     3
#define    ACIC     2
#define    ACIS1    1
#define    ACIS0    0
/* ADC MUX */
#define    MUX2     2
#define    MUX1     1
#define    MUX0     0
/* ADC Control and Status Register */
#define    ADEN     7
#define    ADSC     6
#define    ADFR     5
#define    ADIF     4
#define    ADIE     3
#define    ADPS2    2
#define    ADPS1    1
#define    ADPS0    0  
/* Pointer definition   */
#define    XL       r26
#define    XH       r27
#define    YL       r28
#define    YH       r29
#define    ZL       r30
#define    ZH       r31
/* Contants */
#define    RAMEND   $25F    /*Last On-Chip SRAM location*/
#define    XRAMEND  $25F
#define    E2END    $1FF
#define    FLASHEND $1FFF
 
#endif
