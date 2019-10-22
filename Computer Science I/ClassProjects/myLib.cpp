#include "myLib.h"
#include <string>
#include <fstream>
namespace cs1{
	void fileCopy(std::string sourceFile, std::string targetFile){
		using std::cout;
		using std::ifstream;
		using std::fstream;
		// does file copy regardless of file type
		std::ifstream input;
		std::fstream output;
		input.open(sourceFile, std::ios::binary);
		output.open(targetFile, std::ios::out | std::ios::binary);
		if(input.fail()){
			cout << "Input file cannot be opened at this time,";
			return;
		}
		char c;
		while(input.get(c)){
			output.put(c);
			output.flush();
		}
		input.close();
		output.close();

	}
}
