#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>
#include <fstream>
#include <set>
#include <vector>
#include <map>
using std::set;
using std::map;
using std::vector;
using std::ifstream;
using std::string;
using std::cin;
using std::endl;
using std::cout;

string FILENAME = "Dictionary.txt";
void getWord(string &);
bool wordLadder(string, string, set<string> &, map<string,vector<string>> &);
bool output(string&, string, vector<string>&, map<string,vector<string>>&);

int main(){
    map<string,vector<string> > map;
    string start, end;
    bool flag;
    cout << "Please enter the starting word: ";
    getWord(start);
    cout << "Please enter the end word: ";
    getWord(end);
    ifstream dictionary;
    set<string> dict;
    string temp;
    dictionary.open(FILENAME);
    while(!dictionary.eof()){
        dictionary >> temp;
        if(temp.size() == start.size()) dict.insert(temp);
    }

    if(dict.find(end) == dict.end()){
        cout << "Word is not in dictionary!\n";
    }

    else if(start.size()!= end.size()){
        cout << "Words must match in length!";
    }

    flag = wordLadder(start, end, dict, map);
    if(!flag){
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
            if(!isalpha(c)){
                cout << "Not a valid word, please remove any non letters!\n";
                flag = 0;
                break;
            }
            c = tolower(c);
            flag = 1;
        }
    }

}

bool wordLadder(string start, string end, set<string> &dict, map<string,vector<string>> &mp){
    vector<string> path;
    set<string> cur_lev;
    cur_lev.insert(start);
    set<string> next_lev;
    path.push_back(end);

    while (true){
        for (auto it = cur_lev.begin();it!=cur_lev.end();it++){
            dict.erase(*it);
        } //delete previous level words

        for (auto it = cur_lev.begin();it!=cur_lev.end();it++){  //find current level words
            //findDict2(*it,dict,next_lev);
            string str = *it;
            for (int i = 0; i < str.size(); i++){
                str = *it;
                for(char j = 'a'; j<='z'; j++){
                    str[i]=j;
                    if(dict.find(str) != dict.end()){
                        next_lev.insert(str);
                        mp[str].push_back(*it);
                    }
                }
            }
        }
        if (next_lev.empty()){
            return 0;
        }

        if (next_lev.find(end)!=next_lev.end()){ //if find end string
            output(start, end, path, mp);
            return 1;
        }

        cur_lev.clear();
        cur_lev = next_lev;
        next_lev.clear();
    }
    return 0;
}

bool output(string &start,string last, vector<string>& path, map<string, vector<string>>&map){
    if (last==start){
        reverse(path.begin(),path.end());
        for(auto it = path.begin(); it!=path.end(); it++){
            cout <<*it << endl;
        }
        reverse(path.begin(),path.end());
        return true;
    }else{
        for (int i=0;i<map[last].size();i++){
            path.push_back(map[last][i]);
            if(output(start,map[last][i], path, map)) return 1;
            path.pop_back();
        }
    }
    return false;
}
