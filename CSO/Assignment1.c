/*
Virag Kiss
CSO Assignment 1
30/09/2020
Version 1.0
*/


#include <stdio.h>
#include <string.h>

/*
add left -> right : dir = num + 1 , sign => +1, ... -1/10000
add right -> left : dir = num - 1 , sign => -1/10000, ... +1

add pos + neg left -> right : dir = num + 2, sign => + then - consistently
add pos + neg right -> left : dir = num -2 , sign => - then + consistently

*/


float addFloat (float num, float sign, float dir) { 
	float sum = 0.0;
	for (int x = 1; x < 10001; x=x+1) {
		//sum = sum + sign * (1.0/(float)x);
		sum = sum + sign * (1.0/num);
		num = num + dir;
		sign = -sign;
	} return sum;
}

double addDouble (double num, double sign, double dir) {
	double sum = 0.0;
	for (int x = 1; x < 10001; x=x+1) {
		//sum = sum + sign * (1.0/(double)x);
		sum = sum + sign * (1.0/num);
		num = num + dir;
		sign = -sign;
	} return sum;
}

float addPosNeg_float(float num, float dir) {
	float sum = 0.0;
	for (int x = 0; x < 5000; x=x+1) {
		sum = sum + 1.0/num;
		num = num + dir;
	} return sum;
}

float addPosNeg_double(double num, double dir) {
	double sum = 0.0;
	for (int x = 0; x < 5000; x=x+1) {
		sum = sum + 1.0/num;
		num = num + dir;
	} return sum;
}

void lefttoright (float num) {

	printf("===============================================\n");
	printf("LEFT TO RIGHT\n");
	printf("===============================================\n");

	//add all
	float sign = 1.0;
	float dir = 1.0;
	float sum1 = addFloat(num, sign, dir);
	double dsum1 = addDouble((double)num, (double)sign, (double)dir);

	//add positive numbers float and double
	dir = 2.0;
	float sumpos = addPosNeg_float(num, dir);
	double dsumpos = addPosNeg_double((double)num, (double)dir);

	//add negative numbers float and double
	num = - (num + 1.0);
	dir = -2.0;
	float sumneg = addPosNeg_float(num, dir);
	double dsumneg = addPosNeg_double((double)num, (double)dir);

	//sum up
	float sum2 = sumpos + sumneg;
	double dsum2 = dsumpos + dsumneg;

	//print results
	printf("-------------- For float numbers ---------------\n");
    printf("Sum of all terms left to right: %30.30f", sum1); printf("\n");
    printf("Sum of p+n terms left to right: %30.30f", sum2); printf("\n");
    printf("\n");
    printf("-------------- For double numbers ---------------\n");
    printf("Sum of all terms left to right: %30.30f", dsum1); printf("\n");
    printf("Sum of p+n terms left to right: %30.30f", dsum2); printf("\n");
    printf("\n");

}

void righttoleft(float num){

	printf("===============================================\n");
	printf("RIGHT TO LEFT\n");
	printf("===============================================\n");

	float sign = -1.0;
	float dir = -1.0;
	float sum1 = addFloat(num, sign, dir);
	double dsum1 = addDouble((double)num, (double)sign, (double)dir);

	num = -num;
	dir = 2.0;
	float sumpos = addPosNeg_float(num, dir);
	double dsumpos = addPosNeg_double((double)num, (double)dir);

	num = -(num + 1.0);
	dir = -2.0;
	float sumneg = addPosNeg_float(num, dir);
	double dsumneg = addPosNeg_double((double)num, (double)dir);
	
	//sum up
	float sum2 = sumpos + sumneg;
	double dsum2 = dsumpos + dsumneg;

	//print
	printf("-------------- For float numbers ---------------\n");
    printf("Sum of all terms right to left: %30.30f", sum1); printf("\n");
    printf("Sum of p+n terms right to left: %30.30f", sum2); printf("\n");
    printf("\n");
    printf("-------------- For double numbers ---------------\n");
    printf("Sum of all terms right to left: %30.30f", dsum1); printf("\n");
    printf("Sum of p+n terms right to left: %30.30f", dsum2); printf("\n");
    printf("\n");

}


void main() {

	printf("START MAIN \n");

	float n1 = 1.0; float n2 = 10000.0;
	lefttoright(n1);
	righttoleft(n2);
}


