/* Program to reverse given string */


/*
 *   _Aall Good -> i/p
 *
 *   dooG llaA_  -> o/p
 *
 *   
 *
 */

#include <stdio.h>

void swap_char(char* p_start_char, char* p_end_char)
{
    if(*p_start_char == *p_end_char)
	    return;
    *p_start_char = *p_start_char ^ *p_end_char;
    *p_end_char = *p_start_char ^ *p_end_char;
    *p_start_char = *p_start_char ^ *p_end_char;
}

void reverse_string_first_half(char* string)
{
    unsigned int string_len = 0;

    while(string[string_len] != '\0')
	    string_len++;

    for(int i=0; i < string_len/2 ; i++)
    {
        swap_char(&string[i],&string[string_len-1-i]);
    }
}



/* without using any string function*/
void reverse_string_two_pointer(char* string)
{

    int start_index = 0;

    int end_index = 0;

    //find string length
    while(string[end_index] != '\0')
	    end_index++;

    //to point to last character
    --end_index;


    /* can't able to handle case when string is empty */
    while(start_index < end_index)
    {
        swap_char( &string[start_index], &string[end_index] );
	start_index++;
	end_index--;
    }

}



int main()
{
    char string[] = "#";
    reverse_string_two_pointer(string);
    //reverse_string_first_half(string);
    printf("%s\n",string);

}
