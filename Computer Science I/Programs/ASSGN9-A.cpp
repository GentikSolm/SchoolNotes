/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN9-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.11.2019
  Purpose: Reverse strings using pointers
*/
#include <iostream>
#include <string>
#include "ASSGN9-A_func.cpp"
using std::cout;
using std::string;
using std::endl;
void reverse(char word[]);
	//Pre condtion: word is a cstring with some value.
	//Post conditon: word is reversed


int main(){
// these are the test cases
	char str1[] = "time";
	char str2[] = "straw";
	char str3[] = "deliver";
	char str4[] = "star";
	char str5[] = "knits";

	cout << "The strings before reversing: " << endl;
	cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

	reverse(str1);
	reverse(str2);
	reverse(str3);
	reverse(str4);
	reverse(str5);

	cout << "The strings after reversing: " << endl;
	cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;
	return 0;
}
