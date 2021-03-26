// You need to complete this program for your second project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <vector>
#include <set>
using std::stack;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;

struct Point{
  int x, y;
  bool operator<(const Point& pt)const{
    return (x < pt.x) || ((!(pt.x < x)) && (y > pt.y));
  }
};

//Credit to Geeks for Geeks for implementations and helper functions.
Point nextToTop(stack<Point> &S){
  // A utility function to find next to top in a stack
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
int distSq(Point p1, Point p2){
  // A utility function to return square of distance
  // between p1 and p2
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(Point p, Point q, Point r){
  // To find orientation of ordered triplet (p, q, r).
  // The function returns following values
  // 0 --> p, q and r are colinear
  // 1 --> Clockwise
  // 2 --> Counterclockwise
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
Point p0;
  //global for compare function, very useful.
int compare(const void *vp1, const void *vp2){
  // A function used by library function qsort() to sort an array of
  // points with respect to the first point
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}
std::set<Point> hull; // stores result for quick hull
int findSide(Point p1, Point p2, Point p){
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}
int lineDist(Point p1, Point p2, Point p){
    return abs ((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}
void quickHull(vector<Point> a, int n, Point p1, Point p2, int side){
      int ind = -1;
      int max_dist = 0;

      // finding the point with maximum distance
      // from L and also on the specified side of L.
      for (int i=0; i<n; i++)
      {
          int temp = lineDist(p1, p2, a[i]);
          if (findSide(p1, p2, a[i]) == side && temp > max_dist)
          {
              ind = i;
              max_dist = temp;
          }
      }

      // If no point is found, add the end points
      // of L to the convex hull.
      if (ind == -1)
      {
          hull.insert(p1);
          hull.insert(p2);
          return;
      }

      // Recur for the two parts divided by a[ind]
      quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
      quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
  }


int main(int argc, char *argv[])
{
  if (argc < 3) std::cout << "wrong format! should be \"a.exe algType dataFile\"\n";
  else {
    std::string algType = argv[1];
    std::string dataFilename = argv[2];

    std::string outputFile;
    //read your data points from dataFile (see class example for the format)
    ifstream dataFile;
    dataFile.open(dataFilename);
    vector<Point> points;
    int i = 0;
    int x, y;
    Point temp;
    while(dataFile >> x >> y){
      temp.x = x;
      temp.y = y;
      points.push_back(temp);
    }

    dataFile.close();
    vector<Point> result;


    if (algType[0]=='G') {
      //call your Graham Scan algorithm to solve the problem

      int n = points.size();
      int ymin = points[0].y, min = 0;
      for (int i = 1; i < n; i++){
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
      }
      Point temp = points[0];
      points[0] = points[min];
      points[min] = temp;
      p0 = points[0];
      qsort(&points[1], n-1, sizeof(Point), compare);
      int m = 1;
      for (int i=1; i<n; i++){
         while (i < n-1 && orientation(p0, points[i],points[i+1]) == 0) i++;
         points[m] = points[i];
         m++;  // Update size of modified array
      }
      // Create an empty stack and push first three points
      // to it.
      stack<Point> S;
      S.push(points[0]);
      S.push(points[1]);
      S.push(points[2]);

      // Process remaining n-3 points
      for (int i = 3; i < m; i++){
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();
        S.push(points[i]);
      }
      // Now stack has the output points, print contents of stack
      outputFile = "hull_G.txt";
      ofstream outFile;
      outFile.open(outputFile);
      while (!S.empty()){
        Point p = S.top();
        outFile << p.x << ' ' << p.y << std::endl;
        S.pop();
      }
      outFile.close();
    }

    else if (algType[0]=='J') {
      //call your Javis March algorithm to solve the problem
      int left = 0;
      //we dont need to check against its self
      for(int i = 1; i < points.size(); i++){
        if(points[i].x < points[left].x ) left = i;
      }
      int p = left, q;
      do{
        result.push_back(points[p]);
        q = (p+1)%points.size();
        for(int i = 0; i < points.size(); i++){
          int orient = (points[i].y - points[p].y)*(points[q].x - points[i].x) - (points[i].x - points[p].x)*(points[q].y - points[i].y);
          if(orient < 0){
            q = i;
          }
        }
        p = q;
      }while (p != left);
      outputFile = "hull_J.txt";
      ofstream outFile;
      outFile.open(outputFile);
      for(int i = 0; i < result.size(); i++){
        outFile << result[i].x << ' ' << result[i].y << std::endl;
      }
      outFile.close();
    }

    else {
      //call your Quickhull algorithm to solve the problem
      int n = points.size();
      int min_x = 0, max_x = 0;
      for (int i=1; i<n; i++){
        if (points[i].x < points[min_x].x) min_x = i;
        if (points[i].x > points[max_x].x) max_x = i;
      }
      quickHull(points, n, points[min_x], points[max_x], 1);
      quickHull(points, n, points[min_x], points[max_x], -1);

      vector<Point> result;
      result.push_back(*hull.begin());
      // Point test, test2;
      // test.x = 0;
      // test.y = 0;
      // test2.x = 0;
      // test2.y = 24;
      // hull.insert(test);
      // hull.insert(test2);
      // for(Point iter : hull){
      //   cout << iter.x << ' ' << iter.y << std::endl;
      // }

      std::set<Point>::iterator last, next;
      std::set<Point>::iterator start = hull.begin();
      while((++start)->x == hull.begin()->x){
        next = start;
        if((++next)->x == hull.begin()->x){
          // cout << start->x << ' '<< start->y << std::endl;
          hull.erase(*start);
          start = hull.begin();
        }
      }
      // cout << std::endl;
      // cout << std::endl;
      std::set<Point>::reverse_iterator rnext;
      std::set<Point>::reverse_iterator rstart = hull.rbegin();
      while((++rstart)->x == hull.rbegin()->x){
        rnext = rstart;
        if((++rnext)->x == hull.rbegin()->x){
          // cout << rstart->x << ' '<< rstart->y << std::endl;
          hull.erase(*rstart);
          rstart = hull.rbegin();
        }
      }
      hull.erase(hull.begin());
      for(std::set<Point>::iterator iter = hull.begin(); iter != hull.end();){
        if(iter->y > result[0].y){
          result.push_back(*iter);
          last = iter;
          iter++;
          hull.erase(*last);
        }
        else{
          iter++;
        }

      }

      for(std::set<Point>::reverse_iterator iter = hull.rbegin(); iter != hull.rend(); iter++){
        rnext = iter;
        rnext++;
        // cout << rnext->x << std::endl;
        if(iter == hull.rbegin() && rnext->x == hull.rbegin()->x){
          result.push_back(*rnext);
          result.push_back(*iter);
          iter++;
          iter++;
        }
        result.push_back(*iter);

      }
      outputFile = "hull_Q.txt";
      ofstream outFile;
      outFile.open(outputFile);
      for(int i = 0; i < result.size(); i++){
        outFile << result[i].x << ' ' << result[i].y << std::endl;
      }
      outFile.close();
    }
    //write your convex hull to the outputFile (see class example for the format)
    //you should be able to visulize your convex hull using the "ConvexHull_GUI" program.
	}
	return 0;
}
