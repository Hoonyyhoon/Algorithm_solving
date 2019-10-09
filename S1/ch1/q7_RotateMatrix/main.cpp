#include<iostream>


bool rotateMatrix(int** matrix, int len) {

  for(int i=0; i<len/2; i++) {
	int st = i;
	int end = len-i-1;
	for(int j = st; j<end; j++){
	  int iter = j-st;
	  int temp = matrix[st][j];
	  matrix[st][j] = matrix[end-iter][st];
	  matrix[end-iter][st] = matrix[end][end-iter];
	  matrix[end][end-iter] = matrix[j][end];
	  matrix[j][end] = temp;
	}
  }
  return false;
}

int main() {
  int **matrix;
  matrix= new int *[4];
  for(int i=0;i<4;i++) matrix[i] = new int[4];

  int cnt =1;
  for(int col=0; col<4; col++){
	for(int row=0; row<4; row++){
	  matrix[row][col] = cnt;
	  cnt++;
	}
  }
  std::cout<<"//before"<<std::endl;

  for(int col=0; col<4; col++) {
	for(int row=0; row<4; row++){
	  std::cout<<matrix[row][col]<<" ";
	}
	std::cout<<std::endl;
  }
  rotateMatrix(matrix, 4);
  std::cout<<"//after"<<std::endl;
  for(int col=0; col<4; col++) {
	for(int row=0; row<4; row++){
	  std::cout<<matrix[row][col]<<" ";
	}
	std::cout<<std::endl;
  }

  return 0;

}

