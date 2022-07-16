/* program to convert given number to desired base */



#include <stdio.h>
#include <stdlib.h>



void convertNumToGivenBase(char* numberInString, int base, char* desiredNumInString)
{
	int maxNumberBits = sizeof(char*) * 8;
	int num = atoi(numberInString);

	printf("%d\n",maxNumberBits);

		unsigned int mask = 0;
		unsigned int desiredArrayIndex = 0;

	//first assume that number is in binary
    switch(base)
    {
	case 2:
	        //loop start from LSB
	        for(int i=maxNumberBits-1; i >= 0;i--)
		{
		    desiredNumInString[desiredArrayIndex++] = num & (0x1U << i)?'1' : '0';
		    if (i % 4 == 0 )
			   desiredNumInString[desiredArrayIndex++] = ' '; 
		    
		}		
                break;
	case 16:
		break;
        default:

    }
}

int main()
{
    int num = -1;
    char inputBuffer[1000] = {0};
    sprintf(inputBuffer, "%d",num);

    char outputBuffer[100] = {0}; 

    bzero(outputBuffer,sizeof(outputBuffer) );
    convertNumToGivenBase(inputBuffer, 16, outputBuffer);

    printf("input: %s\n output: %s\n",inputBuffer, outputBuffer);
}
