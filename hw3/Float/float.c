#include <stdio.h>


float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
    /* DO NOT CHANGE THE DECLARATION OF "f" (This will be converted to float later) */
    unsigned int f = 0; // DO NOT CHANGE
    /*------------------------------------------------------------------------------*/

    /* Start Coding Here */
    f |= (sign_bit & 0x1); /*0x1 ensures to cut off any extra 1s */
    f = f << 8;
    f |= (exponent & 0x00FF); /*0xFF cuts off any ones produced*/
    f <<= 23;
    f |= (fraction & 0x7FFFFF); /*0x7FFFFF ensures to cut off any extra 1s */
    
    
    /*-------------------*/
    
    /* DO NOT CHANGE THE RETURN VALUE (This returns the binary representation of "f" as float) */
    return *((float*)&f); // DO NOT CHANGE
    /* ----------------------------------------------------------------------------------------*/
}

#ifndef STUDENT_MAIN /* Do not remove this line*/
int main(int argc, char* argv[])
{
    (void) argc; // to supress compiler warning
    (void)argv;  // to supress compiler warning
    printf("f = %g\n", construct_float_sf(0x00, 0x7F, 0x000000));
    printf("f = %g\n", construct_float_sf(0x01, 0x7F, 0x000000));
    printf("f = %g\n", construct_float_sf(0x00, 0x81, 0x300000));
    printf("f = %g\n", construct_float_sf(0x01, 0x81, 0x300000));
    printf("f = %g\n", construct_float_sf(0x00, 0x7F, 0x200000));
    printf("f = %g\n", construct_float_sf(0x01, 0x7F, 0x200000));
    printf("f = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));
    printf("f = %g\n", construct_float_sf(0x01, 0x76, 0x299B6F));
    printf("f = %g\n", construct_float_sf(0x00, 0x90, 0x7973C0));
    printf("f = %g\n", construct_float_sf(0x01, 0x90, 0x7973C0));

    printf("f = %g\n", construct_float_sf(0x00, 0x00, 0x000000));
    printf("f = %g\n", construct_float_sf(0x01, 0x00, 0x000000));
    printf("f = %g\n", construct_float_sf(0x02, 0x76, 0x299B6F));
    printf("f = %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));
    printf("f = %g\n", construct_float_sf(0x01, 0x89, 0xABCDEF));
    return 0;
}
#endif /* Do not remove this line*/

