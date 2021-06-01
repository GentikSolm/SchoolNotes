.PHONY: all
all : main

main : seamCarve.o SeamFuncs.o
	g++ -std=c++17 seamCarve.o SeamFuncs.o -o seamCarve

seamCarve.o : seamCarve.cpp SeamFuncs.h
	g++ -std=c++17 -c seamCarve.cpp

SeamFuncs.o : SeamFuncs.cpp
	g++ -std=c++17 -c SeamFuncs.cpp
.PHONY: clean
clean :
	@rm -f seamCarve *.o
