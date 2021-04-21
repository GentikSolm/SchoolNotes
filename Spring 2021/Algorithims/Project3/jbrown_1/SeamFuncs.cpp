#include "SeamFuncs.h"
#include <algorithm>
#include <iostream>

int** genEnergyMatrix(int** imageMatrix, int rows, int cols){
  // Returns a dynamic array that contains the energy of each cell.
  // Must be deleted after being called!
  // imageMatrix must have all its values already populated.
  int** energyMat = new int*[rows];
  for(int i = 0; i < rows; i++){
    energyMat[i] = new int [cols];
  }
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      //Check all corner and boundary cases:
      if(i == 0 && j == 0){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i+1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i][j+1])));
      }
      else if(i == 0 && (j == cols-1)){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i][j-1])) + abs((imageMatrix[i][j])-(imageMatrix[i+1][j])));
      }
      else if((i == rows-1) && j == 0){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i-1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i][j+1])));
      }
      else if((i == rows-1) && (j == cols-1)){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i-1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i][j-1])));
      }
      else if(i==0){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i][j+1])) + abs((imageMatrix[i][j])-(imageMatrix[i][j-1])) + abs((imageMatrix[i][j])-(imageMatrix[i+1][j])));
      }
      else if(i==rows-1){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i][j+1])) + abs((imageMatrix[i][j])-(imageMatrix[i][j-1])) + abs((imageMatrix[i][j])-(imageMatrix[i-1][j])));
      }
      else if(j == 0){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i][j+1])) + abs((imageMatrix[i][j])-(imageMatrix[i-1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i+1][j])));
      }
      else if(j == cols-1){
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i][j-1])) + abs((imageMatrix[i][j])-(imageMatrix[i+1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i-1][j])));
      }
      else{
        energyMat[i][j] = (abs((imageMatrix[i][j])-(imageMatrix[i-1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i+1][j])) + abs((imageMatrix[i][j])-(imageMatrix[i][j-1])) + abs((imageMatrix[i][j])-(imageMatrix[i][j+1])));
      }
    }
  }
  return energyMat;
}
int** vertE(int** energyMat, int rows, int cols){
  int** sumEnergyMat = new int*[rows];
  for(int i=0; i<rows; i++){
    sumEnergyMat[i] = new int[cols];
  }
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(i==0){
        sumEnergyMat[i][j] = energyMat[i][j];
      }
      else{
        if(j==0){
          sumEnergyMat[i][j] = energyMat[i][j] + std::min(sumEnergyMat[i-1][j], sumEnergyMat[i-1][j+1]);
        }
        else if(j==(cols-1)){
          sumEnergyMat[i][j] = energyMat[i][j] + std::min(sumEnergyMat[i-1][j-1], sumEnergyMat[i-1][j]);
        }
        else{
          sumEnergyMat[i][j] = energyMat[i][j] + std::min(std::min(sumEnergyMat[i-1][j-1], sumEnergyMat[i-1][j]), sumEnergyMat[i-1][j+1]);
        }
      }
    }
  }
  return sumEnergyMat;
}
void delEnergyMatrix(int** mat1, int** mat2,  int rows){
  // This deletes two dynamic matricies each with n rows.
  // This is done togeather so that there only needs to be one for loop.
  for(int i = 0; i < rows; i++){
    delete[] mat1[i];
    delete[] mat2[i];
  }
  delete[] mat1;
  delete[] mat2;
}
void vertSeam(int** imageMatrix, int** energySumMat, int rows, int cols){
  int minLoc = 0;
  int min = energySumMat[rows-1][minLoc];
  for(int j=0; j<cols; j++) {
    if(energySumMat[rows-1][j] < min) {
      minLoc = j;
      min = energySumMat[rows-1][j];
    }
  }

  for(int iter = minLoc; iter < (cols-1); iter++){
    imageMatrix[rows-1][iter] = imageMatrix[rows-1][iter+1];
  }

  for(int i=(rows-2); i>=0;i--){
    if(minLoc==0){
      if(energySumMat[i][minLoc] < energySumMat[i][minLoc+1]){
        minLoc = minLoc;
      }
      else if(energySumMat[i][minLoc+1] < energySumMat[i][minLoc]){
        minLoc = minLoc+1;
      }
    }
    else if(minLoc==(cols-1)){
      if(energySumMat[i][minLoc] < energySumMat[i][minLoc-1]){
        minLoc = minLoc;
      }
      else if(energySumMat[i][minLoc-1] < energySumMat[i][minLoc]){
        minLoc = minLoc-1;
      }
    }
    else {
      if((energySumMat[i][minLoc] < energySumMat[i][minLoc-1]) && (energySumMat[i][minLoc] <= energySumMat[i][minLoc+1])){
        minLoc = minLoc;
      }
      else if((energySumMat[i][minLoc+1] < energySumMat[i][minLoc]) && (energySumMat[i][minLoc+1] < energySumMat[i][minLoc-1])){
        minLoc = minLoc+1;
      }
      else if((energySumMat[i][minLoc-1] <= energySumMat[i][minLoc]) && (energySumMat[i][minLoc-1] <= energySumMat[i][minLoc+1])){
        minLoc = minLoc-1;
      }
      else if((energySumMat[i][minLoc-1] < energySumMat[i][minLoc]) && (energySumMat[i][minLoc+1] < energySumMat[i][minLoc]) && (energySumMat[i][minLoc+1] == energySumMat[i][minLoc-1])){
        minLoc = minLoc-1;
      }
      else{
        static int mono = 0;
        if(mono == 0){
          std::cout << energySumMat[i][minLoc-1] << std::endl;
          std::cout << energySumMat[i][minLoc] << std::endl;
          std::cout << energySumMat[i][minLoc+1] << std::endl;
        }
        mono++;
        minLoc = minLoc-1;
      }
    }
    for(int iter = minLoc; iter < (cols-1); iter++){
      imageMatrix[i][iter] = imageMatrix[i][iter+1];
    }
  }
}
