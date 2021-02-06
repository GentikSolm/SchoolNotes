#include <iostream>
using namespace std;

char* getWord();

int main(){
    char* word2 = getWord();
    cout << word2;'
    delete word2;
}

char* getWord(){
    char *word = new char[11];
    cin >> word;
    return word;
}
