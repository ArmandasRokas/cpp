#include <iostream>
#include "ex03-library.h"
#include <algorithm>
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    for(auto song: this->songs){
        cout << "title=" << song << "; url=" << songsInfo[song].url;
        cout << "; score=" << songsInfo[song].score << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    if(find(songs.begin(), songs.end(), title) != songs.end()){
        return false;
    }
    if(score>10){
        return false;
    }
    songs.push_back(title);
    Info info;
    info.url = url;
    info.score = score;
    songsInfo[title] = info;
    return true;
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    int lower_limit = -1;
    int upper_limit = -1;


    if(howGood == "abysmal"){
        lower_limit = 0;
        upper_limit = 3;
    } else if(howGood== "lousy" ){
        lower_limit = 3;
        upper_limit = 5;
    } else if(howGood== "meh" ){
        lower_limit = 5;
        upper_limit = 7;
    } else if(howGood== "cool"){
        lower_limit = 7;
        upper_limit = 9;
    } else if(howGood== "OMG"){
        lower_limit = 9;
        upper_limit = 9999;
    }

    for(auto song: songs){
        if(songsInfo[song].score >=lower_limit && songsInfo[song].score < upper_limit ){
            cout << "title=" << song << "; url=" << songsInfo[song].url;
            cout << "; score=" << songsInfo[song].score << endl;
        }
    }

}
