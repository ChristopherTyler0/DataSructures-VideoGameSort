//
// Created by Chris Tyler on 4/24/23.
//

#ifndef COP3530_FINALPROJECT_MAPSTORE_H
#define COP3530_FINALPROJECT_MAPSTORE_H
#include <string>
#endif //COP3530_FINALPROJECT_MAPSTORE_H
#include <unordered_map>
#include <vector>
using namespace std;
class mapStore{
private:
    struct vertex{
        string name,rating;
        int year;
        float reviews,price,length;
        vertex(){
            this->year = 0;
            this-> reviews = price = length = 0.0;
            this->name = "";
            this->rating = "";
        }
        //these input values are the properties of a game not represented already by the type of
        //graph they end up in
        vertex(string name, int year, float price, float reviews, float length, string rating){
            this->name = name;
            this-> year = year;
            this-> price = price;
            this-> reviews = reviews;
            this->length = length;
            this->rating = rating;
        }
    };
    //order of keys- console, genre, multiplayer, last value is the vertex or game, but we're still not done evaluating
    unordered_map<string, unordered_map<string, unordered_map<bool,vector<vertex>>>> m;

public:
    //the input arguments are all the values of a single game
    void insertGame(string console, string genre, bool multiplayer, string name, int year, float price, float reviews, float length, string rating);
    //these are all the values the user is prompted with
    void searchAndPrintBestGame(string console, string genre, bool multiplayer, string rating, float length);
};