Made by Josh Brown
Thanks to GeeksForGeeks for help with algorithms.

To Compile, use the command:
gcc main.cpp -lstdc++
This uses the gcc compiler, and makes sure it uses the correct linker; being c++.
To run program, call with one of the following options:
  J   -Jarvis March
  G   -Grahm Scan
  Q   -Quick Hull
Followed by a txt file of the points you wish to examine.
My program then loads all the points from the selected file into a vector,
and passes that vector to the desired convex hull algorithm.
Each algorithm is very vanilla, and is programed like one might expect,
with the exception of quick hull. Since it is made with a recursive approach, making
sure that the points in the output file were in the right place was extremely difficult. To
sole this, i do multiple iterative passes over the result to get it into the proper form.
This includes removing unnecessary points (like ones that intersect two other points perfectly)
and rearranging points that are out of order. This process proved to be very difficult.
