#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SeamFuncs.h"
using std::cout;
using std::string;

int main(int argc, char** argv){

  if(argc != 4) {
    cout << "Invalid number of args, should be:\nSeamCarve.exe file.pgm [Vertical seams] [Horizontal seams]\n";
    return 0;
  }

  int vert = atoi(argv[2]), horiz = atoi(argv[3]), rows, cols, grey;
  string fileName = argv[1];
  string outFileName = fileName.substr(0, fileName.size()-4);
  outFileName = outFileName + "_processed.pgm";

  std::ifstream image;
  image.open(fileName.c_str());
  string input;
  getline(image, input);
  getline(image, input);
  image >> cols >> rows >> grey;
  int** imageMatrix = new int*[rows];
  for(int i = 0; i< rows; i++){
    imageMatrix[i] = new int [cols];
  }
  for(int x = 0; x < rows; x++){
    for(int y = 0; y < cols; y++){
      image >> imageMatrix[x][y];
    }
  }
  image.close();
  for(int i = 0; i < vert; i++){
    int** energyMat = genEnergyMatrix(imageMatrix, rows, cols);
    int** energySumMat = vertE(energyMat, rows, cols);
    vertSeam(imageMatrix, energySumMat, rows, cols);
    delEnergyMatrix(energyMat, energySumMat, rows);
    cols--;
  }
  for(int i = 0; i < horiz; i++){
    int** energyMat = genEnergyMatrix(imageMatrix, rows, cols);
    int** energySumMat = horizE(energyMat, rows, cols);
    horizSeam(imageMatrix, energySumMat, rows, cols);
    delEnergyMatrix(energyMat, energySumMat, rows);
    rows--;
  }
  std::ofstream outFile;
  outFile.open(outFileName.c_str());
  outFile << "P2\n" << "#Seam Carved image of " << fileName << "\n" << cols << rows << std::endl << "255" << std::endl;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols-1; j++){
      outFile << imageMatrix[i][j] << ' ';
    }
    outFile << imageMatrix[i][cols-1] << std::endl;
    //stops extra space at the end of a line, instead starts new line
  }
  outFile.close();
  for (int i=0; i<rows; i++) {
    delete[] imageMatrix[i];
  }
  delete[]imageMatrix;
  return 0;
}
