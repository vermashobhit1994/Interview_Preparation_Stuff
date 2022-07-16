/* program that takes number from user of any length and then 
 * check Luhn checksum.
 * 176248
 *
 * 1 + (7x2)    + 6  + (2x2) + 4     + (8x2) 
 * 1 + (14)     + 6  + (4)   + 4     + (16)
 * 1 + (1 + 4)  + 6  + (4)   + 4     + (1+6)
 * 1 + (5)      + 6  + (4)   + 4     + (7)      => 27
 *
 *  
 *  sum must be divisible by 10
 *
 */



#include <stdio.h>

#include <stdbool.h>
#include <stdlib.h>


#define MAX_BUFFER_SIZE (1024)

int doubleDigitValue(int digit)
{
    int doubleDigit = digit * 2;

    int sum = 0;

    //sum range from 10 to 18 for 2 digit value
    if(doubleDigit % 10) 
	    sum += 1 + doubleDigit % 10;
    else
	    sum = doubleDigit % 10;

    return doubleDigit;


}



void check_luhn_checksum(void )
{
    char input_char = 0;

    char input_buffer[MAX_BUFFER_SIZE]= {0};

    int i=0;

    int luhn_sum = 0;

    bool even_position = false;

    
    while(1)
    {
	scanf("%c",&input_char);

	//to prevent '\n' or ' ' taking as input 
	if(input_char == '\n' || input_char == ' ' || i > MAX_BUFFER_SIZE)
		break;

	input_buffer[i++]= input_char;
        
	int num = (input_char - '0');
        
	if(even_position == false)
	{
	     luhn_sum += num;
	     even_position = true;
	}
        else
	{
            //num >= 5 && num <= 9   => 10 to 18
            //luhn_sum += num % 10;
	    //luhn_sum += num / 10;

	    luhn_sum += doubleDigitValue(num);

	    even_position = false;
	}
                

    }
        



    int luhn_checksum = luhn_sum + (10 - (luhn_sum % 10) ) ;

    printf("$%d\n",luhn_sum);//123 = 1 + (2x2) + 3

    if(luhn_sum % 10 == 0)
	    printf("%d number luhn checksum is %d\n",atoi(input_buffer), luhn_sum);
    else
	    printf("%d number is %d away from luhn checksum %d\n",atoi(input_buffer), luhn_checksum - luhn_sum, luhn_checksum);
}

int main()
{
    check_luhn_checksum();
}
