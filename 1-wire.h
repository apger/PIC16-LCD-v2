
#define OW_PIN_DIRECTION 	TRISAbits.TRISA5
#define OW_WRITE_PIN  		LATAbits.LATA5
#define OW_READ_PIN			PORTAbits.RA5
#define	SET		1
#define	CLEAR	0
#define	HIGH	1
#define	LOW		0
#define	OUTPUT	0
#define	INPUT 	1

#define RS RC0
#define EN RC1
#define D4 RC2
#define D5 RC3
#define D6 RC4
#define D7 RC5


/**********************************************************************
* Function:        void drive_OW_low (void)
* PreCondition:    None
* Input:		   None	
* Output:		   None	
* Overview:		   Configure the OW_PIN as Output and drive the OW_PIN LOW.	
***********************************************************************/
void drive_OW_low (void)
{
	OW_PIN_DIRECTION = OUTPUT;
	OW_WRITE_PIN=LOW;
}

/**********************************************************************
* Function:        void drive_OW_high (void)
* PreCondition:    None
* Input:		   None	
* Output:		   None	
* Overview:		   Configure the OW_PIN as Output and drive the OW_PIN HIGH.	
***********************************************************************/
void drive_OW_high (void)
{
	OW_PIN_DIRECTION = OUTPUT;
	OW_WRITE_PIN = HIGH;	
}

/**********************************************************************
* Function:        unsigned char read_OW (void)
* PreCondition:    None
* Input:		   None	
* Output:		   Return the status of OW pin.	
* Overview:		   Configure as Input pin and Read the status of OW_PIN 	
***********************************************************************/
unsigned char read_OW (void)
{
	unsigned char read_data=0;
	OW_WRITE_PIN = INPUT;
	 if (HIGH == OW_READ_PIN)
	 	read_data = SET;
	 else 	
		read_data = CLEAR;
	return read_data;
}

/**********************************************************************
* Function:        unsigned char OW_reset_pulse(void)
* PreCondition:    None
* Input:		   None	
* Output:		   Return the Presence Pulse from the slave.	
* Overview:		   Initialization sequence start with reset pulse.
*				   This code generates reset sequence as per the protocol
***********************************************************************/
unsigned char OW_reset_pulse(void)
{
	unsigned char presence_detect;
  	drive_OW_low(); 				// Drive the bus low
 	__delay_us(500);	  			// 480 - 640
 	drive_OW_high ();  				// Release the bus
	__delay_us(100);				// 60 - 240
	presence_detect = read_OW();	//Sample for presence pulse from slave
    __delay_us(410);	  			// 45 - 180 recovery
	drive_OW_high ();		    	// Release the bus
	return presence_detect;
}	

/**********************************************************************
* Function:        void OW_write_bit (unsigned char write_data)
* PreCondition:    None
* Input:		   Write a bit to 1-wire slave device.
* Output:		   None
* Overview:		   This function used to transmit a single bit to slave device.
*				   
***********************************************************************/

void OW_write_bit (unsigned char write_bit)
{
	if (write_bit)
	{
		//writing a bit '1'
		drive_OW_low(); 				// Drive the bus low
		__delay_us(6);				// delay 6 microsecond (us)
		drive_OW_high ();  				// Release the bus
		__delay_us(64);				// delay 64 microsecond (us)
	}
	else
	{
		//writing a bit '0'
		drive_OW_low(); 				// Drive the bus low
		__delay_us(60);				// delay 60 microsecond (us)
		drive_OW_high ();  				// Release the bus
		__delay_us(10);				// delay 10 microsecond for recovery (us)
	}
}	

/**********************************************************************
* Function:        unsigned char OW_read_bit (void)
* PreCondition:    None
* Input:		   None
* Output:		   Return the status of the OW PIN
* Overview:		   This function used to read a single bit from the slave device.
*				   
***********************************************************************/
unsigned char OW_read_bit (void)
{
	unsigned char read_data; 
	//reading a bit 
	drive_OW_low(); 						// Drive the bus low
	__delay_us(6);						// delay 6 microsecond (us)
	drive_OW_high ();  						// Release the bus
	__delay_us(9);						// delay 9 microsecond (us)
	read_data = read_OW();					//Read the status of OW_PIN
	__delay_us(65);						// delay 55 microsecond (us)	
	return read_data;
}

/**********************************************************************
* Function:        void OW_write_byte (unsigned char write_data)
* PreCondition:    None
* Input:		   Send byte to 1-wire slave device
* Output:		   None
* Overview:		   This function used to transmit a complete byte to slave device.
*				   
***********************************************************************/
void OW_write_byte (unsigned char write_data)
{
	unsigned char loop;
	for (loop = 0; loop < 8; loop++)
	{
		OW_write_bit(write_data & 0x01); 	//Sending LS-bit first
		write_data >>= 1;					// shift the data byte for the next bit to send
	}	
}	

/**********************************************************************
* Function:        unsigned char OW_read_byte (void)
* PreCondition:    None
* Input:		   None
* Output:		   Return the read byte from slave device
* Overview:		   This function used to read a complete byte from the slave device.
*				   
***********************************************************************/
unsigned char OW_read_byte (void)
{
	unsigned char loop, result=0;
	for (loop = 0; loop < 8; loop++)
	{
		result >>= 1; 				// shift the result to get it ready for the next bit to receive
		if (OW_read_bit())
		result |= 0x80;				// if result is one, then set MS-bit
	}
	return result;					
}	
