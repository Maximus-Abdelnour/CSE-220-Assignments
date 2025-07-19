#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int GetBit(int num, int pos);
int SetBit(int num, int pos);
int ClearBit(int num, int pos);
int ReversBit(int num);
int CountBit(int num);
int PowerofTwo(unsigned int num);



#ifndef STUDENT_MAIN /* Do not remove this line*/
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	assert(GetBit(12, 2) == 1);
	assert(GetBit(0, 0) == 0); 
	assert(GetBit(-1, 0) == 1); 
	assert(GetBit(0xFFFFFFFF, 0) == 1);
	assert(GetBit(-10, 0) == 0);
	assert(GetBit(-10, (sizeof(int)*8 - 1)) == 1);  
	assert(GetBit(12, -2) == -1);
	assert(GetBit(10, 32)==-1); 

	assert(SetBit(12, 4) == 28);
	assert(SetBit(0, 1) == 2);
	assert(SetBit(-1, 1) == -1);
	assert(SetBit(2,1) == 2);
	assert(SetBit(-10, 0) == -9);
	assert(SetBit(-1>>1, (sizeof(int)*8 - 1)) == -1);
	assert(SetBit(2,-1) == -1);
	assert(SetBit(2,32) == -1);
	

	assert(ClearBit(12, 2) == 8);
	assert(ClearBit(0, 1) == 0);
	assert(ClearBit(-1, 0) == -2);
	assert(ClearBit(2, 0) == 2);
	assert(ClearBit(-9, 0) == -10);
	assert(ClearBit(1 << (sizeof(int)*8 - 1), sizeof(int)*8 - 1) == 0); 
	assert(ClearBit(2,-1) == -1);
	assert(ClearBit(2,32) == -1);


	assert(ReversBit(2) == 1 << (sizeof(int)*8 - 2));
	assert(ReversBit(1 << (sizeof(int)*8 - 1)) == 1);
	assert(ReversBit(0) == 0);
	assert(ReversBit(-1) == -1);
	assert(ReversBit(ReversBit(12)) == 12);
	

	assert(CountBit(2) == 1);
	assert(CountBit(0) == 0);
	assert(CountBit(-1) == sizeof(int)*8);
	assert(CountBit(-10) == sizeof(int)*8 - 2);
	
	assert(PowerofTwo(2) == 1);
	assert(PowerofTwo(15) == 0);
	assert(PowerofTwo(0) == 1);
	return 0;
}
#endif /* Do not remove this line*/

int GetBit(int num, int pos) {
	/*Returns -1 on invalid positions*/
	if (pos < 0 || pos >= sizeof(int)*8) {
		return -1;
	}
	return (num >> pos) & 1;
}
int SetBit(int num, int pos) {
	/*Returns -1 on invalid positions*/
	if (pos < 0 || pos >= sizeof(int)*8) {
		return -1;
	}
	return num | (1 << pos);
}
int ClearBit(int num, int pos) {
	/*Returns -1 on invalid positions*/
	if (pos < 0 || pos >= sizeof(int)*8) {
		return -1;
	}
	/*Returns removes the bit at pos with the and statement*/
	return num & ~(1 << pos);
}
int ReversBit(int num) {
	/*Goes through num from LSB to MSB, shifting the result by a bit while inserting*/
	int result;
	result = 0;
	for (int i = 0; i < sizeof(int)*8; i++) {
		result = result << 1;
		result |= GetBit(num, i);
	}
	return result;
}
int CountBit(int num) {
	/*Made unsigned as >> does not shift the sign bit*/
	unsigned int unsignedNum;
	unsignedNum = (unsigned int)num;

	/*While num has active bits, it is shifted left and the LSB is checked*/
	int result;
	result = 0;
	while (unsignedNum != 0) {
		result += unsignedNum & 1;
		unsignedNum = unsignedNum >> 1;
	}
	return result;
}

int PowerofTwo(unsigned int num){
	/*Edge case of num = 0 (only number which has no 1s)*/
	if (num == 0) {
		return 1;
	}

	/* Finds and skips the first active bit which occurs in num*/
	while (!(num & 1)) {
		num = num >> 1;
	}
	num = num >> 1;

	/*If there still is an active bit, then num isn't a power of two*/
	return !(num > 0);
}