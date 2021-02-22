// You need to complete this program for a part of your first project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using std::endl;

// 'BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"

bool isPrime(BigUnsigned num, BigUnsigned a);
int main(){
	/* The library throws 'const char *' error messages when things go
	 * wrong.  It's a good idea to catch them using a 'try' block like this
	 * one.  Your C++ compiler might need a command-line option to compile
	 * code that uses exceptions. */
	try {
        //std::cout << "a couple of test cases for 3460:435/535 Algorithms!!!\n";
        BigUnsigned p = BigUnsigned(1);
        for (int i=0;i<155;i++) {
            p = p*10 +rand();
        }
        p = p *2 + 1;
        //This line ensures the number will be odd, this way later in the code
        //we can decrement by 2 to save time.
        bool first, second;
        while(true){
            //this loop continues untill both first and second are true. If
            //first is false, continue will restart the loop, and subtract 2 from p.
            first = isPrime(p, 2);
            if(!first) {
                p-=2;
                continue;
            }
            second = isPrime(p,3);
            if(second) break;
            p -= 2;
        }
        std::ofstream prime;
        prime.open("p_q.txt");
        prime << p << endl;
        BigUnsigned q = BigUnsigned(1);
        for (int i=0;i<155;i++) {
            q = q*10 +rand();
        }
        q = q *2 + 1;
        while(true){
            first = isPrime(q, 2);
            if(!first) {
                q-=2;
                continue;
            }
            second = isPrime(q,3);
            if(second) break;
            q -= 2;
        }
        prime << q;
        prime.close();
        std::cout << "p_q.txt Generated\n";
        //  e is coprime prime to (p-1)*(q-1)
        BigUnsigned n = p*q;
        BigUnsigned phiN = (p-1)*(q-1);
        BigUnsigned e = p*2-1;
        while(true){
            if(gcd(e,phiN) == 1) break;
            e=-2;
        }
        BigUnsigned d = modinv(e,phiN);
        std::ofstream e_n;
        std::ofstream d_n;
        e_n.open("e_n.txt");
        d_n.open("d_n.txt");
        e_n << e << endl << n;
        std::cout << "e_n.txt Generated\n";
        d_n << d << endl << n;
        std::cout << "d_n.txt Generated\n";
        e_n.close();
        d_n.close();






	} catch(char const* err) {
		std::cout << "The library threw an exception:\n"
			<< err << std::endl;
	}

	return 0;
}

bool isPrime(BigUnsigned n, BigUnsigned a){

    if (gcd(n, a) != 1)
        return false;
    if (modexp(a, n-1, n) != 1)
        return false;
    return true;
}
