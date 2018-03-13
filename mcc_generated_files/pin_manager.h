/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F15325
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS               TRISAbits.TRISA4
#define LED_LAT                LATAbits.LATA4
#define LED_PORT               PORTAbits.RA4
#define LED_WPU                WPUAbits.WPUA4
#define LED_OD                ODCONAbits.ODCA4
#define LED_ANS                ANSELAbits.ANSA4
#define LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_GetValue()           PORTAbits.RA4
#define LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_SetPushPull()    do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_SetOpenDrain()   do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 aliases
#define RA5_TRIS               TRISAbits.TRISA5
#define RA5_LAT                LATAbits.LATA5
#define RA5_PORT               PORTAbits.RA5
#define RA5_WPU                WPUAbits.WPUA5
#define RA5_OD                ODCONAbits.ODCA5
#define RA5_ANS                ANSELAbits.ANSA5
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()           PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetPushPull()    do { ODCONAbits.ODCA5 = 1; } while(0)
#define RA5_SetOpenDrain()   do { ODCONAbits.ODCA5 = 0; } while(0)
#define RA5_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RC0 aliases
#define RC0_TRIS               TRISCbits.TRISC0
#define RC0_LAT                LATCbits.LATC0
#define RC0_PORT               PORTCbits.RC0
#define RC0_WPU                WPUCbits.WPUC0
#define RC0_OD                ODCONCbits.ODCC0
#define RC0_ANS                ANSELCbits.ANSC0
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()           PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()      do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()    do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetPushPull()    do { ODCONCbits.ODCC0 = 1; } while(0)
#define RC0_SetOpenDrain()   do { ODCONCbits.ODCC0 = 0; } while(0)
#define RC0_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 aliases
#define RC1_TRIS               TRISCbits.TRISC1
#define RC1_LAT                LATCbits.LATC1
#define RC1_PORT               PORTCbits.RC1
#define RC1_WPU                WPUCbits.WPUC1
#define RC1_OD                ODCONCbits.ODCC1
#define RC1_ANS                ANSELCbits.ANSC1
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()           PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()      do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()    do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetPushPull()    do { ODCONCbits.ODCC1 = 1; } while(0)
#define RC1_SetOpenDrain()   do { ODCONCbits.ODCC1 = 0; } while(0)
#define RC1_SetAnalogMode()  do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode() do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 aliases
#define RC2_TRIS               TRISCbits.TRISC2
#define RC2_LAT                LATCbits.LATC2
#define RC2_PORT               PORTCbits.RC2
#define RC2_WPU                WPUCbits.WPUC2
#define RC2_OD                ODCONCbits.ODCC2
#define RC2_ANS                ANSELCbits.ANSC2
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()           PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetPushPull()    do { ODCONCbits.ODCC2 = 1; } while(0)
#define RC2_SetOpenDrain()   do { ODCONCbits.ODCC2 = 0; } while(0)
#define RC2_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 aliases
#define RC3_TRIS               TRISCbits.TRISC3
#define RC3_LAT                LATCbits.LATC3
#define RC3_PORT               PORTCbits.RC3
#define RC3_WPU                WPUCbits.WPUC3
#define RC3_OD                ODCONCbits.ODCC3
#define RC3_ANS                ANSELCbits.ANSC3
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()           PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetPushPull()    do { ODCONCbits.ODCC3 = 1; } while(0)
#define RC3_SetOpenDrain()   do { ODCONCbits.ODCC3 = 0; } while(0)
#define RC3_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 aliases
#define RC4_TRIS               TRISCbits.TRISC4
#define RC4_LAT                LATCbits.LATC4
#define RC4_PORT               PORTCbits.RC4
#define RC4_WPU                WPUCbits.WPUC4
#define RC4_OD                ODCONCbits.ODCC4
#define RC4_ANS                ANSELCbits.ANSC4
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()           PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetPushPull()    do { ODCONCbits.ODCC4 = 1; } while(0)
#define RC4_SetOpenDrain()   do { ODCONCbits.ODCC4 = 0; } while(0)
#define RC4_SetAnalogMode()  do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode() do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 aliases
#define RC5_TRIS               TRISCbits.TRISC5
#define RC5_LAT                LATCbits.LATC5
#define RC5_PORT               PORTCbits.RC5
#define RC5_WPU                WPUCbits.WPUC5
#define RC5_OD                ODCONCbits.ODCC5
#define RC5_ANS                ANSELCbits.ANSC5
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()           PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetPushPull()    do { ODCONCbits.ODCC5 = 1; } while(0)
#define RC5_SetOpenDrain()   do { ODCONCbits.ODCC5 = 0; } while(0)
#define RC5_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/