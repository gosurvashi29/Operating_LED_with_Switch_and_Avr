# define F_CPU 1000000
#include <avr/io.h>
# include <util/delay.h>
void lcd_init();
void disp_cmd(unsigned int cmd);
void disp_data(int cmd);
void disp_num(unsigned int num);
void disp_string(  char *str);
int main(void)
{
	DDRA=0X00;
	DDRB=0XFF;
	PORTA=0XFF;
	DDRC = 0XFF;

	lcd_init();
	while (1)
	{
		if (PINA==0b11111110)
		{
			PORTB=0b00000001;//1
			disp_cmd(0X80);
			disp_num(1);
			
			
		}
		
		else if (PINA==0b11111101)
		{
			PORTB=0b00000010;//2
			disp_cmd(0X81);
			disp_num(2);
		}
	else if (PINA==0b11111011)
	{
		PORTB=0b00000100;//3
		disp_cmd(0X82);
		disp_num(3);
	}
	else if (PINA==0b11110111)
	{
		PORTB=0b00001000;//4
		disp_cmd(0X83);
		disp_num(4);
	}
	else if (PINA==0b11101111)
	{
		PORTB=0b00010000;//5
		disp_cmd(0X84);
		disp_num(5);
	}
	else if (PINA==0b11011111)
	{
		PORTB=0b00100000;//6
		disp_cmd(0X85);
		disp_num(6);
	}
	else if (PINA==0b10111111)
	{
		PORTB=0b01000000;//7
		disp_cmd(0X86);
		disp_num(7);
	}
	else if (PINA==0b01111111)
	{
		PORTB=0b10000000;//8
		disp_cmd(0X87);
		disp_num(8);
	}
	}
	return 0;
}	
	
	void disp_cmd(unsigned int cmd)
	{
		PORTC=((cmd & 0XF0)+0X04);
		_delay_ms(1);
		PORTC=PORTC - 0X04;
		PORTC=(((cmd<<4)& 0XF0)+0X04);
		_delay_ms(1);
		PORTC=PORTC-0X04;
		
	}
	void disp_data( int cmd)
	{
		PORTC=((cmd  & 0XF0)+0X05);
		_delay_ms(1);
		PORTC=PORTC - 0X04;
		PORTC=(((cmd <<4)& 0XF0)+0X05);
		_delay_ms(1);
		PORTC=PORTC-0X04;
		
	}

	void disp_string( char *str)
	{
		int i=0;
		while (str[i]!='\0')
		{
			disp_data (str[i]);
			i++;
			
		}
	}

	void disp_num(unsigned int num)
	{
		int a=0;
		if (num==0)
		{
			disp_data(48);
		}
		disp_cmd (0X04);
		while (num!=0)
		{
			a=num % 10;
			disp_data(a+48);
			num=num/10;
		}
	}
	void lcd_init()
	{
		disp_cmd(0X02);
		disp_cmd(0X28);
		disp_cmd(0X0C);
		disp_cmd(0X06);
	}