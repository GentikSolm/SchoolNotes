/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment H
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 04.12.2020
   Purpose: Learn maps and map iterators
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using std::map;
using std::cin;
using std::cout;
using std::string;
using std::ifstream;

ifstream revFile();
/* revFile
    Establish a review file.
    req:
        Must be .txt
        1st line must be ammount of review,
        after 1st line, even lines must be movie names
        and odd lines following must be the corosponding rating.
    post:
        returns ifstream to file
*/
void fillRevMap(map<string, double[2]>&, ifstream&);
/* fillRevMap
    Fills map with ratings, and count of ratings.
        req:
            review file established
        post:
            Map contains movie titles as keys, pointing to an array of two doubles.
            first double is summation of ratings, and second is the total number of ratings.
*/
void displayRatings(map<string, double[2]>&);
/* displayRatings

*/
int main(){
    cout << "Please enter a file to input: ";
    ifstream reviews = revFile();
    map<string, double[2]> reviewMap;
    fillRevMap(reviewMap, reviews);
    displayRatings(reviewMap);
    return 0;
}

ifstream revFile(){
    string fileName;
    getline(cin, fileName);
    ifstream reviews;
    reviews.open(fileName);
    while(!reviews.is_open()){
        cout << "Error opening file, please enter file name: ";
        getline(cin, fileName);
        reviews.open(fileName);
    }
    return reviews;
}

void fillRevMap(map<string, double[2]> &reviewMap, ifstream &reviews){
    string movieTitle;
    char temp;
    int reviewScore, totalReviews;
    reviews >> totalReviews;
    reviews.get(temp);
    for(int i = 0; i < totalReviews; i++){
        getline(reviews, movieTitle);
        reviews >> reviewScore;
        reviews.get(temp);
        reviewMap[movieTitle][0] += reviewScore;
        reviewMap[movieTitle][1]++;
    }
    reviews.close();
}

void displayRatings(map<string, double[2]> &reviewMap){
    for(map<string, double[2]>::iterator iter = reviewMap.begin(); iter != reviewMap.end(); iter++){
        cout << iter->first << ": " << (iter->second)[1] << " reviews, average of "
        << (iter->second)[0] / (iter->second)[1] << " / 5"<< std::endl;
    }
}
