#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>
#include <fstream>
#include <set>
#include <vector>
using std::set;
using std::vector;
using std::ifstream;
using std::string;
using std::cin;
using std::endl;
using std::cout;

string FILENAME = "Dictionary.txt";
void getWord(string &);
    //Gets word from user, string var must be referenceable.
    //makes sure there is no non letters in input.

bool wordLadder(string start, string last, set<string> dict);
    //start and last must be same length.
    //Dict does not even requre words, will just return false if no linking words are found
    //returns true if a ladder is found.
    //In case of ladder, will print out the ladder.

struct scoredWords{
    int score = 0;
    string word;
};
//Holds a word as well as the words score in relativity to the end target
int main(){
    string start, end;
    cout << "Please enter the starting word: ";
    getWord(start);
    cout << "Please enter the end word: ";
    getWord(end);

    ifstream dictionary;
    set<string> dict;
    string temp;
    int startSize = start.size();

    //makes sure words are same length before loading dict.
    if(start.size()!= end.size()){
        cout << "Words must match in length!";
        return 0;
    }

    //Generates dict with only words of length of start/end
    dictionary.open(FILENAME);
    while(!dictionary.eof()){
        dictionary >> temp;
        if(temp.size() == startSize) dict.insert(temp);
    }
    //ensures end is in dict, doesnt duplicate because of set properties
    dict.insert(end);
    //if wordladder returns true, program exits, else no path was faound.
    if(!wordLadder(start, end, dict)){
        cout << "No path was found!";
    }
    //Placed ontop of close bracket because do{}while()
    return 0;
}

void getWord(string &word){
    bool flag = 0;
    while(!flag){
        cin >> word;
        for(char& c : word){
            //Makes sure string is only letters
            if(!isalpha(c)){
                cout << "Not a valid word, please remove any non letters!\n";
                flag = 0;
                break;
            }
            //forces all letters to lowercase.
            c = tolower(c);
            flag = 1;
        }
    }

}
bool wordLadder(string start,string last, set<string> dict){
    if (last==start){
        //end case
        cout << last << endl;
        return true;
    }else{
        string str = last;
        //we use last instead of start so that the list will print out with the start first.

        vector<scoredWords> level;
        //used to map out current level word possibilites.
        auto iter = level.begin();
        for (int i = 0; i < str.size(); i++){
            str = last;
            for(char j = 'a'; j<='z'; j++){
                str[i]=j;
                if(dict.find(str) != dict.end()){
                    //This nested loop Generates/finds all words that are 1 letter different
                    //than 'last'

                    dict.erase(str); //erases word from dict.
                    iter = level.begin();
                    scoredWords temp;
                    temp.word = str;
                    for(int i = 0; i < start.size(); i++){
                        if(start[i] == str[i]) temp.score++;
                        //finds and scores each word to see how far away it is from target
                    }
                    while(iter != level.end() && iter->score > temp.score) iter++;
                    level.insert(iter, temp);
                    //this while loop inserts the scoredWords element in order of rank.
                }
            }
        }
        for(auto iter = level.begin(); iter!= level.end(); iter++){
            //Transverses the level, if level is empty (no more words or no combinations possible),
            //then the for loop will instantly terminate and the recursion function will return false,
            //climbing back up to the previous level, to which it will move to the next item.
            if(wordLadder(start, iter->word, dict)){
                //if its true, then a ladder was found and it will print the tree.
                cout << last << endl;
                return true;
            }
        }
    }
    return false;
}
