#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_ntoh(char *filename){
	FILE *file = fopen(filename, "rb");
	if(file == NULL){
		printf("Error Opening\n");
		return 0;
	}
	
	uint32_t num;
	size_t read_size = fread(&num, 1, sizeof(num), file);
	

	if (read_size < sizeof(num)){
		printf("Error Reading\n");
		return 0;
	}

	fclose(file);
	return ntohl(num);
}


int main(int argc, char *argv[]){
	uint32_t num1 = read_ntoh(argv[1]);
       	uint32_t num2 = read_ntoh(argv[2]);
	uint32_t summ = num1 + num2;
	
	printf("%d(0x%x) +  %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, summ, summ);
	return 0;
}
