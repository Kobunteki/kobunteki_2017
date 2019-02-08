#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)

#define GPFCON (*((volatile unsigned int*)0x56000050))
#define GPFDAT (*((volatile unsigned int*)0x56000054))
#define GPGCON (*((volatile unsigned int*)0x56000060))
#define GPGDAT (*((volatile unsigned int*)0x56000064))




void delay(unsigned int jiffy)
{
	while (jiffy--);
}


int led_on(unsigned int led_no)
{

	if (4 == led_no)
	{
		GPFCON = 0x100;
	}
	else if (5 == led_no)
	{
		GPFCON = 0x400;
	}
	GPFDAT = 0;      
}




int main()
{
	int val = 0;
	int val_1,val_2;

	GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
	GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));
	
	/*key configuration with gpio as input port*/
	/*GPF0(s2) GPF2(s3) GPG3(s4)*/
	GPFCON &= ~((3 << 0) | (3 << 4));
	GPGCON &= ~((3 << 6)); 


	while(1)
	{
		
		GPGDAT &= ~((1<<4)|(1<<5)|(1<<6));
		
		val_1 = GPFDAT;
		val_2 = GPGDAT; 
		//*pGPFDAT &= ~(7 << 4);
		//*pGPFDAT |= (val << 4);
		//val ++;
		//delay(50000);

		if (val_1 & (1<<0)) /*EINT0 -------> d12 gpf6*/
		{/*up*/
			GPFDAT |= (1 << 6); 
		}
		else
		{/*down*/
			GPFDAT &= ~(1 << 6);
		}

		if (val_1 & (1<<2)) /*EINT2 -------> d11 gpf5*/
		{/*up*/
			GPFDAT |= (1 << 5); 
		}
		else
		{/*down*/
			GPFDAT &= ~(1 << 5); 
		}
		
		if (val_2 & (1<<3)) /*EINT11 -------> d10 gpf4*/
		{/*up*/
			GPFDAT |= (1 << 4); 
		}
		else
		{/*down*/
			GPFDAT &= ~(1 << 4); 
		}


		
/*		if (8 == val)
		{
			val = 0;
		}
		*/
	}
	return 0;
}
