# cse-220-homework3
Name: Maximus Abdelnour
ID: 116154053

# Bit Manipulation
Files: BitManipulation.c, BitManipulation (executable), Makefile

## Functions:
1. int main(int argc, char* argv[])
2. int GetBit(int num, int pos); // Return -1 on invalid input
3. int SetBit(int num, int pos); // Return -1 on invalid input
4. int ClearBit(int num, int pos); // Return -1 on invalid input
5. int ReversBit(int num);
6. int CountBit(int num);
7. int PowerofTwo(unsigned int num);

## Test Cases:
1. int GetBit(int num, int pos);

	//Testing regular number 12: 
	assert(GetBit(12, 2) == 1);

	//Testing 0 and -1 cases: 
	assert(GetBit(0, 0) == 0);
    assert(GetBit(-1, 0) == 1); 

	//Testing edge cases: 
	assert(GetBit(0xFFFFFFFF, 0) == 1)

	//Testing negative test cases: 
	assert(GetBit(-10, 0) == 0);   

    //Testing the sign bit:
    assert(GetBit(-10, (sizeof(int)*8 - 1)) == 1);  

	//Testing invalid positions:
    assert(GetBit(12, -2) == -1);
	assert(GetBit(10, 32)==-1); 

2. int SetBit(int num, int pos);

	//Testing regular number 12:
    assert(SetBit(12, 4) == 28);

    //Testing 0 and -1:
	assert(SetBit(0, 1) == 2);
	assert(SetBit(-1, 1) == -1);

    //Testing when position is at an active bit:
	assert(SetBit(2,1) == 2);

    //Testing negative numbers:
	assert(SetBit(-10, 0) == -9);

    //Testing the sign bit:
    assert(SetBit(-1>>1, (sizeof(int)*8 - 1)) == -1);

    //Testing invalid positions:
	assert(SetBit(2,-1) == -1);
	assert(SetBit(2,32) == -1);

3. int ClearBit(int num, int pos);

	//Testing regular number 12:
    assert(ClearBit(12, 2) == 8);

    //Testing 0 and -1:
	assert(ClearBit(0, 1) == 0);
	assert(ClearBit(-1, 0) == -2);

    //Testing when position is at an unactive bit:
	assert(ClearBit(2, 0) == 2);

    //Testing negative numbers:
	assert(ClearBit(-9, 0) == -10);

    //Testing the sign bit:
    assert(ClearBit(1 << (sizeof(int)*8 - 1), sizeof(int)*8 - 1) == 0);

    //Testing invalid positions:
	assert(ClearBit(2,-1) == -1);
	assert(ClearBit(2,32) == -1);

4. int ReversBit(int num); 

    //Testing regular numbers:
	assert(ReversBit(2) == 1 << (sizeof(int)*8 - 2));
    assert(ReversBit(1 << (sizeof(int)*8 - 1)) == 1);
    //Testing 0 and -1:
    assert(ReversBit(0) == 0);
	assert(ReversBit(-1) == -1);
    //Testing reversing a number twice
    assert(ReversBit(ReversBit(12)) == 12);

5. int CountBit(int num);

	//Testing regular numbers:
	assert(CountBit(2) == 1);
    //Testing 0 and -1:
    assert(CountBit(0) == 0);
	assert(CountBit(-1) == sizeof(int)*8);
    //Testing negative numbers
    assert(CountBit(-10) == sizeof(int)*8 - 2);

6. int PowerofTwo(unsigned int num);

	//Testing regular numbers:
    assert(PowerofTwo(2) == 1);
	assert(PowerofTwo(15) == 0);
    //Testing 0:
    assert(PowerofTwo(0) == 1);

# IEEE 754 Float 
Files: float.c, float (executable), Makefile

## Functions:
1. int main(int argc, char* argv[])
2. float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) // Cuts off unused bits in sign_bit/fraction (based on case using 0xABCDEF in the fraction on the pdf)

## Test Cases: 
    //Normal Test Cases:
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

    //Special/Edge Cases:
    // +/- 0
    printf("f = %g\n", construct_float_sf(0x00, 0x00, 0x000000));
    printf("f = %g\n", construct_float_sf(0x01, 0x00, 0x000000));
    // Sign bit not being 0/1
    printf("f = %g\n", construct_float_sf(0x02, 0x76, 0x299B6F));
    // Fraction not being within the read 23 bits
    printf("f = %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));
    printf("f = %g\n", construct_float_sf(0x01, 0x89, 0xABCDEF));
