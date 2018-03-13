/* 
 * File:   main.h
 * Author: Jim Apger
 *
 * Created on March 13, 2018
 */

float convertTemperatureF(unsigned short tempL, unsigned short tempH){
    unsigned int binaryTemperatureC = 0;
    float temperatureCprecise=0.0, tCprecise=0.0;
    
    binaryTemperatureC=((unsigned int)tempH << 8 ) + (unsigned int)tempL;		//put both value in one variable
    //  Per the DS18B20 datasheet, the temp is stores with 4 digits of binary precision
    //  See https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf
    if(binaryTemperatureC & 0x08){ //if 1st digit of binary precision is 1, 2 to the -1
        tCprecise=0.5;
    }
    if(binaryTemperatureC & 0x04){  //if 2st digit of binary precision is 1, 2 to the -2
        tCprecise=tCprecise+0.25;
    }
    if(binaryTemperatureC & 0x02){  //if 13rd digit of binary precision is 1, 2 to the -3
        tCprecise=tCprecise+0.125;
    }
    if(binaryTemperatureC & 0x01){  //if 4th digit of binary precision is 1, 2 to the -4
        tCprecise=tCprecise+0.0625;
    }
    temperatureCprecise=(binaryTemperatureC >> 4) + tCprecise;
    return (temperatureCprecise * 9)/5 + 32;
}

