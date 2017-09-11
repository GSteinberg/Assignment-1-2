#include <stdio.h>
#include <stdlib.h>

int isFib(unsigned long i) {
	int n = -1;
	long prevFNum, fNum;
	prevFNum = 0;
	fNum = 1;

	if(i != 0) {
		/*generate all the fibonacci numbers under 1000000000 (under the 45th fib number) and check them against i*/
		for(n = 2; n < 45; n++) {
			fNum = prevFNum + fNum;
			prevFNum = fNum - prevFNum;

			if(i == fNum) {
				return n;
			}
		}
	} else {
		return 0;
	}

	/*if i does not correspond to one of those numbers, print -1*/
	return -1;
}

unsigned int count_vowels(unsigned long num) {
	
	int places[10];
	int total = 0;
	int to_twenty[20] = {2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 3, 2, 3, 4, 3, 3, 4, 4, 4};
	int multiples_of_ten[9] = {1, 2, 2, 3, 2, 2, 3, 3, 3};
	
	if(num < 0 || num > 1000000000) {
		return 0;
	}

	/*filling places up with the user inputted number and remaining spaces with zero*/
	int i = 0;
	while (num > 0) {
 		int digit = num % 10;
		places[i] = digit;
		i++;
 		num /= 10;
	}
	int j;
	for(j=i; j < 11; j++) {
		places[j] = 0;
	}

	int one = places[0];
	int ten = places[1];
	int hund = places[2];
	int thou = places[3];
	int ten_thou = places[4];
	int hund_thou = places[5];
	int mil = places[6];
	int ten_mil = places[7];
	int hund_mil = places[8];
	int bil = places[9];

	/*1 billion*/
	if(bil > 0) {
		total += to_twenty[bil] + 3;
	}
	/*250 million*/
	if(hund_mil > 0) {
		total += to_twenty[hund_mil] + 2;
	}
	/*60 million*/
	if(ten_mil > 1) {
		total += multiples_of_ten[ten_mil];
		/*67 million*/
		if(mil > 0) {
			total += to_twenty[mil];
		}
	}
	/*17 million*/
	if(ten_mil == 1) {
		total += to_twenty[mil+10];
	}
	/*1 million*/
	if(mil > 0 && ten_mil == 0) {
		total += to_twenty[mil];
	}
	if(hund_mil > 0 || ten_mil > 0 || mil > 0) {	
		total += 3;
	}

	/*500 thousand*/
	if(hund_thou > 0) {
		total += to_twenty[hund_thou] + 2;
	}
	/*60 thousand*/
	if(ten_thou > 1) {
		total += multiples_of_ten[ten_thou];
		/*67 thousand*/
		if(thou > 0) {
			total += to_twenty[thou];
		}
	}
	/*17 thousand*/
	if(ten_thou == 1) {
		total += to_twenty[thou+10];
	}
	/*1 thousand*/
	if(thou > 0 && ten_thou == 0) {
		total += to_twenty[thou];
	}
	if(hund_thou > 0 || ten_thou > 0 || thou > 0) {	
		total += 3;
	}

	/*500*/
	if(hund > 0) {
		total += to_twenty[hund] + 2;
	}
	/*60*/
	if(ten > 1) {
		total += multiples_of_ten[ten];
		/*67*/
		if(one > 0) {
			total += to_twenty[one];
		}
	}
	/*17*/
	if(ten == 1) {
		total += to_twenty[one+10];
	}
	/*1*/
	if(one > 0 && ten == 0) {
		total += to_twenty[one];
	}

	return total;

}

unsigned int count_ones(long n) {
	long num = n;
 	int binary[63];
	int i = 0, ones = 0;
  
	if(n > 0) {
		/*positive numbers to binary*/
		while(num > 0) {
			binary[i] = num%2;
			num /= 2;
			i++;
		}

	} else {
		/*negative numbers to twos compliment*/
		num = abs(num);
		while(num > 0) {
			binary[i] = num%2;
			num /= 2;
			i++;
		}
		int k;
		for(k = 0; k < i; k++) {
			if(binary[i] == 0) {	
				binary[i] = 1;
			} else if(binary[i] == 1) { 
				binary[i] = 0;
			}
		}
		int b;
		for(b = i; b > 0; b--) {	
			if(binary[b] == 0) {
				binary[b] = 1;
				break;
			} else if(binary[b] == 1) {
				binary[b] = 0;
			}
		}
	} 

	int k;
	for(k = 0; k < i; k++) {
		if(binary[k] == 1) {
			ones++;
		}
	}
	if(num >= 0) {
		return ones;
	} else {
		return ones+1;
	}
}

unsigned long swap_bytes(unsigned long n) {
	unsigned long result;

	int one = n & 0xff;
	n = n >> 8;
	int two = n & 0xff;
	n = n >> 8;
	int three = n & 0xff;
	n = n >> 8;
	int four = n & 0xff;
	n = n >> 8;
	int five = n & 0xff;
	n = n >> 8;
	int six = n & 0xff;
	n = n >> 8;
	int seven = n & 0xff;
	n = n >> 8;
	int eight = n & 0xff;
	

	result = seven;
	result = result << 8;
	result += eight;
	result = result << 8;
	result += five;
	result = result << 8;
	result += six;
	result = result << 8;
	result += three;
	result = result << 8;
	result += four;
	result = result << 8;
	result += one;
	result = result << 8;
	result += two;

	return result;
}

long a4_minus_b4(int a, int b) {
	int num;
	
	num = (a*a*a*a) - (b*b*b*b);
	return num;
}
