#include <stdio.h>
#include <stdint.h>

int checksec(char file_name[], int* num){	
    FILE* fp = fopen(file_name, "rb");

	if (fp == NULL) {
		printf("It's NULL File\n");
		return 0;
	}
	
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	if (size != 4) {
		printf("File is not 4-byte\n");
		return 0;
	}
	
	fread(num, sizeof(uint32_t), 1, fp);

	fclose(fp);
	
	return 1;
}

uint32_t exchange_num(uint32_t num) {
	return (num << 24) | ((num << 8) & 0xFF0000) | ((num >> 8) & 0xFF00) | (num >> 24);
}

int main(int argc, char* argv[]){
    if (argc != 3) {
		printf("CHECK AGAIN YOUR FAULT");
		return 0;
	}
	
	int num1, num2;
	
	if (checksec(argv[1], &num1)){
        num1 = exchange_num(num1);
    } 
	else return 0;
	
	if (checksec(argv[2], &num2)){
        num2 = exchange_num(num2);
    } 
	else return 0;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
	
	return 0;
}
