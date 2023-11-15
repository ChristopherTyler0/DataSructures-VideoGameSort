//
// Created by Chris Tyler on 4/26/23.
//

#ifndef COP3530_FINALPROJECT_MERGESORT_H
#define COP3530_FINALPROJECT_MERGESORT_H

#endif //COP3530_FINALPROJECT_MERGESORT_H
#include <array>
#include <string>
#include <vector>
using namespace std;
class mergeSort{
private:
    struct vertex{
        string name,rating, console, genre;
        bool multiplayer;
        int year;
        float reviews,price,length, score;
        vertex(){
            this->year = 0;
            this-> reviews = price = length = score = 0.0;
            this->name = "";
            this->rating = "";
            this->multiplayer = false;
            this->console = "";
            this->name = "";
        }
        //these input values are the properties of a game not represented already by the type of
        //graph they end up in
        vertex(string console, string genre, bool multiplayer, string name, int year, float price, float reviews, float length, string rating, float score){
            this->name = name;
            this-> year = year;
            this-> price = price;
            this-> reviews = reviews;
            this->length = length;
            this->rating = rating;
            this->console = console;
            this->genre = genre;
            this->multiplayer = multiplayer;
            this->score = score;
        }
    };
    //this is neccesary due to the existence of duplicate score values (review score/price can be the same for different games)
    struct sortItem{
        float score;
        vector<vertex> games;
        sortItem(){
            this->score = 0.0;
            games = {};
        };
        sortItem(vertex insert, float score){
            games.push_back(insert);
            this->score = score;
        };
    };
    vector<sortItem> itemList;
public:
    void insertGame(string console, string genre, bool multiplayer, string name, int year, float price, float reviews, float length, string rating);

    void sortInit();
    /*
    vector<sortItem> mergeSortList(vector<sortItem> a);
    vector<sortItem> merge(vector<sortItem> a, vector<sortItem> b);
     */
    void mergeSortList(vector<sortItem> a);
    void merge(vector<sortItem> a, vector<sortItem> b, vector<sortItem> c);

    void printBestGame(string console, string genre, bool multiplayer, string rating, float length);
};