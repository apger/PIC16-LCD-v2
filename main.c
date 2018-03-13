/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F15325
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "1-wire.h";
#include "lcd.h";
#include "main.h";
#include <stdio.h>
#include <string.h>

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    Lcd_Init();

    while (1)
    {
        int flag,i;
        char deviceSerialNum[64];
        char buffer[20];
        unsigned char serial_number[8];
        unsigned short tempL, tempH;
        float temperatureFprecise=0.0;
        
        flag=OW_reset_pulse();
        if(!flag) //device holding line low equals presence
        {
            LED_SetLow();  //LED ON
            OW_write_byte(0x33);   // Send a command to read a serial number
            __delay_us(20);
            for(i=0; i<8; i++){
                serial_number[i] = OW_read_byte();
            }
            //reversing the order of the 8 bytes read from the wire. No need to reverse bits
            sprintf(deviceSerialNum,"%02X%02X%02X%02X%02X%02X%02X%02X",serial_number[7],serial_number[6],serial_number[5],serial_number[4],serial_number[3],serial_number[2],serial_number[1],serial_number[0]);
        
            flag=OW_reset_pulse();
            OW_write_byte(0xCC);   //Skip ROM
            OW_write_byte(0x44);   //Convert T -  To initiate a temperature measurement and A-to-D conversion
            __delay_ms(750);
            flag=OW_reset_pulse();
            OW_write_byte(0xCC);   //Skip ROM
            OW_write_byte(0xBE);   //Read scratchpad
            tempL = OW_read_byte();
            tempH = OW_read_byte();
       
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String(" 1-wire Present");
            Lcd_Set_Cursor(2,1);
            sprintf(buffer, "%s", deviceSerialNum);
            Lcd_Write_String(buffer);
            __delay_ms(2000);
            temperatureFprecise = convertTemperatureF(tempL,tempH);
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("Temperature:");
            Lcd_Set_Cursor(2,1);
            sprintf(buffer, "  %2.5f", temperatureFprecise);
            Lcd_Write_String(buffer);
            __delay_ms(2000);    //placeholder for inserting a debug break
        }
        else
        {
            LED_SetHigh();  //LED OFF
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String(" 1-wire Missing");
            __delay_ms(2000);
            for(i=0;i<16;i++){
                __delay_ms(100);
                Lcd_Shift_Left();
            }
        }
    }
}