// You need to complete this program for your second project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Point{
  int x, y;
};

int main(int argc, char *argv[])
{
  if (argc < 3) std::cout << "wrong format! should be \"a.exe algType dataFile\"";
  else {
    std::string algType = argv[1];
    std::string dataFilename = argv[2];

    std::string outputFile;
    //read your data points from dataFile (see class example for the format)
    ifstream dataFile;
    dataFile.open(dataFilename);
    vector<Point> points;
    int i = 0;
    while(dataFile >> x >> y){
      points[i].x = x;
      points[i].y = y;
      i++;
    }
    dataFile.close();
    vector<Point> result;


    if (algType[0]=='G') {
      //call your Graham Scan algorithm to solve the problem
      outputFile = "hull_G.txt";
    }


    else if (algType[0]=='J') {
      //call your Javis March algorithm to solve the problem
      int left = 0;
      //we dont need to check against its self
      for(int i = 1; i < points.length(); i++){
        if(points[i].x < points[left].x ) left = i;
      }
      int p = left, q;
      do{
        result.append(points[p]);
        q = 0;
        for(int i = 0; i < points.length(); i++){
          int orient = (points[i].y - points[p].y)*(points[q].x - points[i].x) - (points[i].x - points[p].x)*(points[q].y - points[i].y)
          if(orient < 0) q = i;
        }
        p = q;
      }while (p != left);
      outputFile = "hull_J.txt";
      ofstream outFile;
      outFile.open(outputFile);
      for(int i = 0; i < result.length(); i++){
        outFile << result[i].x << ' ' << result[i].y << std::endl;
      }
    }


    else {
      //call your Quickhull algorithm to solve the problem
      outputFile = "hull_Q.txt";
    }

    //write your convex hull to the outputFile (see class example for the format)
    //you should be able to visulize your convex hull using the "ConvexHull_GUI" program.
	}
	return 0;
}
