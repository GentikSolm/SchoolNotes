Made my Josh brown
4/21/21
This program seam carves an image with a user defined amount of vertical and horizontal seams (in that order).
To compile the program, simply use:
  make all
To run the program, use:
  ./seamCarve imageFile.pgm [vert Seams] [horizontal seams]
For example, to run seamCarve on bug.pgm, with 10 vert seams and 5 horizontal seams:
  ./seamCarve bug.pgm 10 5

Main functionality is split into 4 different functions which can be found in SeamFuncs.cpp
These take care of creating dynamic arrays as well as deleting them, and cutting seams and stitching back
the original array.

The program first creates an array of the image file, then finds the energy matrix of that
data, finds the total energy matrix, and the finds and cuts the seams, then repeats this process
for horizontal seams, by transposing the matrix and re applying the same functions.
finally it writes back the new image to the original file name + _processed.pmg
