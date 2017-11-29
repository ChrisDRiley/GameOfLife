#include <stdio.h>
#include <stdlib.h>

void PrintGrid(char n[40][80]);
int CheckNeighbors(int i, int j, char n[40][80]);
void DoGeneration(char n[40][80]);
int main(int argc, char* argv[]) {
	size_t size = 1;
	int gens = atoi(argv[2]);
	FILE* file = fopen(argv[1], "r");
	unsigned char game[400];
 	fread(game, size, 400, file);
	int row = -1;
	int col = -1;
	char grid[40][80];
	int arr_c = 0;
	int bit_c = 7;
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			int bit = game[arr_c] >> bit_c & 1;
			if(bit == 1){
				grid[i][j] = '0';
			}
			else{
				grid[i][j] = ' ';
			}
			bit_c--;
			if(bit_c == -1){
				bit_c = 7;
				arr_c++;
			}
		
		}
	}
	for(int i = 0; i < gens; i++){
		DoGeneration(grid);
	}
	PrintGrid(grid);
	

}
void PrintGrid(char n[40][80]){
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			printf("%c",n[i][j]);
}
		printf("\n");
}
}
void DoGeneration(char n[40][80]){
	char temp[40][80];
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			int count = CheckNeighbors(i,j,n);
			if((n[i][j] == '0' && count == 2) || (n[i][j] == '0' && count == 3)){
				temp[i][j] = '0';
			}
			else if(n[i][j] == '0'){
				temp[i][j] = ' ';
			}
			else if(count == 3){
				temp[i][j] = '0';
			}
			else{
				temp[i][j] = ' ';
			}
		}
	}
	for(int i = 0; i < 40; i++){
		for(int j = 0; j< 80; j++){
			n[i][j] = temp[i][j];
		}
	}
	
}

int CheckNeighbors(int i, int j, char n[40][80]){
	int count = 0;
	if(i != 0){
		if(n[i-1][j] == '0'){
			count++;
		}
		if(j != 0){
			if(n[i-1][j-1] == '0'){
				count++;
			}
		}
		if(j != 79){
			if(n[i-1][j+1] == '0'){
				count++;
			}
		}
	}
	if(j != 0){
		if(n[i][j-1] == '0'){
			count++;
		}
		if(j != 79){
			if(n[i][j+1] == '0'){
				count++;
			}
		}
	}
	if(i != 39){
		if(n[i+1][j] == '0'){
			count++;
		}
		if(j != 0){
			if(n[i+1][j-1] == '0'){
				count++;
			}
		}
		if(j != 79){
			if(n[i+1][j+1] == '0'){
				count++;
			}
		}
	}
	return count;
}
	


