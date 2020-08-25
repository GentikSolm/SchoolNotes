#ifndef PROGRESS_H
#define PROGRESS_H
#include <string>
using std::string;

void progIcon(double totalIter);
	/*
	Asthetic function for creating a progres indicator and
	percent.
	Prereq: totalIter >= 1
	returns: nothing

	NOTE: If using function, refrain from using cout between
	function calls untill progicon is complete.

	NOTE: If unsure of task completion, use progIcon(-1) to
	reset the funtion.

	*/


void progBar(double totalIter);
	/*
	Asthetic function for creating a progres bar and
	percent.
	Prereq: totalIter >= 1
	returns: nothing

	NOTE: If using function, refrain from using cout between
	function calls untill progicon is complete.

	NOTE: If unsure of task completion, use progBar(-1) to
	reset the funtion.
	*/
#endif
