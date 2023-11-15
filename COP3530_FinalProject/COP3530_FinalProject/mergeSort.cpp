//
// Created by Chris Tyler on 4/26/23.
//
#include "mergeSort.h"
#include <string>
#include <vector>
#include <iostream>
#include <array>
using namespace std;

void mergeSort :: insertGame(std::string console, std::string genre, bool multiplayer, std::string name, int year,
                            float price, float reviews, float length, std::string rating) {
    float score = reviews/price;
    vertex add = vertex(console, genre, multiplayer, name, year, price, reviews, length, rating, score);
    bool match = false;
    //sortItem matchedItem = *new sortItem;
    sortItem matchedItem;
    //look through the list of games and search for a matching score
    for(int i = 0 ; i < itemList.size() ; i++){
        if(itemList[i].score == score){
            match = true;
            matchedItem = itemList[i];
            break;
        }
    }
    //add to existing "sortitem" vector
    if(match){
        matchedItem.games.push_back(add);
    }
    //create new sort item
    else{
        itemList.push_back(sortItem(add,score));
    }
}



//since merge sort is called with the vector belonging to the
//merge sort class, a seperate function -sort initialize-
//is required to pass in this vector as a parameter and not
//affect the original
void mergeSort :: sortInit() {
    mergeSortList(this->itemList);
}
/*
vector<typename mergeSort :: sortItem> mergeSort ::mergeSortList(vector<mergeSort::sortItem> a) {
    int n = a.size();
    if(n <= 1){
        return a;
    }
    vector<sortItem> vectorOne;
    vector<sortItem> vectorTwo;
    for(int i = 0 ; i < n/2 ; i++){
        vectorOne.push_back(a.at(i));
    }
    for(int i = n/2+1 ; i < n ; i++){
        vectorTwo.push_back(a.at(i));
    }

    vectorOne = mergeSortList(vectorOne);
    vectorTwo = mergeSortList(vectorTwo);
    return merge(vectorOne, vectorTwo);
}
vector<typename mergeSort :: sortItem> mergeSort ::merge(vector<mergeSort::sortItem> a, vector<mergeSort::sortItem> b) {

    vector<sortItem> c;
    while(!(a.empty()) && !(b.empty())){
        if(a.at(0).score > b.at(0).score){
            c.push_back(b.at(0));
            b.erase(b.begin());
        }
        else{
            c.push_back(a.at(0));
            a.erase(a.begin());
        }
    }
    while(!(a.empty())){
        c.push_back(a.at(0));
        a.erase(a.begin());
    }
    while(!(b.empty())){
        c.push_back(b.at(0));
        b.erase(b.begin());
    }
    return c;
}
 */

void mergeSort :: mergeSortList(vector<mergeSort::sortItem> a) {
    int n = a.size();
    if(n <= 1){
        return;
    }
    vector<sortItem> vectorOne;
    vector<sortItem> vectorTwo;
    for(int i = 0 ; i < n/2 ; i++){
        vectorOne.push_back(a.at(i));
    }
    for(int i = n/2+1 ; i < n ; i++){
        vectorTwo.push_back(a.at(i));
    }

    mergeSortList(vectorOne);
    mergeSortList(vectorTwo);
    merge(vectorOne, vectorTwo, a);
}

void mergeSort :: merge(vector<mergeSort::sortItem> a, vector<mergeSort::sortItem> b, vector<mergeSort::sortItem>c) {
    while(!(a.empty()) && !(b.empty())){
        if(a.at(0).score < b.at(0).score){
            c.push_back(b.at(0));
            b.erase(b.begin());
        }
        else{
            c.push_back(a.at(0));
            a.erase(a.begin());
        }
    }
    while(!(a.empty())){
        c.push_back(a.at(0));
        a.erase(a.begin());
    }
    while(!(b.empty())){
        c.push_back(b.at(0));
        b.erase(b.begin());
    }
}

void mergeSort :: printBestGame(std::string console, std::string genre, bool multiplayer, std::string rating,
                               float length) {
    /*
    cout << "testing: " << endl;
    for(int i = 0 ; i < itemList.size() ; i++){
        for(int j = 0 ; j < itemList[i].games.size() ; j++){
            cout << itemList[i].games[j].name << " " << itemList[i].games[j].score << endl;
        }
    }
     */
    int gamesFound =0;
    if(itemList.size() != 0) {
        for(int j = 0 ; j < itemList[0].games.size() ; j++){
            if(itemList[0].games[j].console == console && itemList[0].games[j].genre == genre && itemList[0].games[j].multiplayer == multiplayer){
                cout << itemList[0].games[j].name << endl;
                gamesFound++;
            }
        }
        if(gamesFound == 0){
            cout << "No games found, try different search parameters" << endl;

        }
    }
    else{
        cout << "No games found, try different search parameters" << endl;
    }

}