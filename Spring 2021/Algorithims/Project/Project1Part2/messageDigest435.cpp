/***
   prepared for CS435 Project 1 part 2
**/

#include <string.h>
#include <iostream>
#include <fstream>
#include "sha256.h"
#include "BigIntegerLibrary.hh"
using std::cout;


int main(int argc, char *argv[])
{
   // //demonstrating how sha256 works
   // std::string input = "testing";
   // std::string output1 = sha256(input);
   // std::cout << "sha256('"<< input << "'):" << output1 << "\n";
   //
   // //demo bigInt works here
   // BigUnsigned a = stringToBigUnsigned("124338907642982722929222542626327282");
   // BigUnsigned b = stringToBigUnsigned("124338907642977775546469426263278643");
   // std::cout << "big a = " <<a<<"\n";
   // std::cout << "big b = " <<b<<"\n";
   // std::cout << "big a*b = " <<a*b<<"\n";

   //Second part of your project starts here


   // if v, then argc will be 4...?
    // deleted "argc !=3 || ... "
    if (argv[1][0]!='s' && argv[1][0]!='v'){
        std::cout << "wrong format! should be \"a.exe s filename\"\n";

    }
    else {
        std::string filename;
        if(argv[1][0] == 's')
        // the last file is the one used for sha256
             filename = argv[2];
        else{
            filename = argv[3];
        }

      //read the file
        std::streampos begin,end;
        std::ifstream myfile (filename.c_str(), std::ios::binary);
        begin = myfile.tellg();
        myfile.seekg (0, std::ios::end);
        end = myfile.tellg();
        std::streampos size = end-begin;
        //std::cout << "size of the file: " << size << " bytes.\n"; //size of the file

        myfile.seekg (0, std::ios::beg);
        char * memblock = new char[size];
        myfile.read (memblock, size); //read file; it's saved in the char array memblock
        myfile.close();

        std::string copyOFfile = filename+".Copy";
        std::ofstream myfile2 (copyOFfile.c_str(), std::ios::binary);
        myfile2.write (memblock, size); //write to a file
        myfile2.close();

        //Does sha256 outside of if's since both use it.
        std::string shaHash = sha256(memblock);
        BigUnsignedInABase signatureString(shaHash, 16);
        BigUnsigned signature = signatureString;

    if (argv[1][0]=='s') {
        std::cout << "\n"<<"Need to sign the doc.\n";
        //Most of this mess is just getting the keys
        std::ifstream privateKey;
        privateKey.open("d_n.txt");
        BigUnsigned d, n;
        std::string temp1, temp2;
        privateKey >> temp1 >> temp2;
        BigUnsignedInABase strD(temp1,10);
        BigUnsignedInABase strN(temp2, 10);
        d = strD;
        n = strN;
        privateKey.close();
        //  Keys collected

        signature = modexp(signature, d, n);

        std::ofstream signedFile;
        signedFile.open("file.txt.signature");
        signedFile << signature;
        signedFile.close();

    }
    else {
        std::cout << "\n"<<"Need to verify the doc.\n";
        //ditto
        std::ifstream publicKey;
        std::string temp1, temp2;
        publicKey.open("e_n.txt");
        BigUnsigned e, n;
        publicKey >> temp1 >> temp2;
        BigUnsignedInABase strE(temp1, 10);
        BigUnsignedInABase strN(temp2, 10);
        e = strE;
        n = strN;
        publicKey.close();

        std::ifstream signedFile;
        signedFile.open(argv[2]);
        BigUnsigned decryptSig;
        signedFile >> temp1;
        BigUnsignedInABase strDec(temp1, 10);
        decryptSig = strDec;
        signedFile.close();
        decryptSig = modexp(decryptSig, e, n);
        if(signature == decryptSig){
            cout << "The document is authentic!\n";
        }
        else{
            cout << "The document has been modified!\n";
        }

        }
        delete[] memblock;
    }
    return 0;
}
