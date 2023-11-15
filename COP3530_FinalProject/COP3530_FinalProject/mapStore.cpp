//
// Created by Chris Tyler on 4/24/23.
//
#include "mapStore.h"
#include<map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
void mapStore ::insertGame(std::string console, std::string genre, bool multiplayer, std::string name, int year,
                           float price, float reviews, float length, std::string rating) {
    vertex add = vertex(name, year, price, reviews, length, rating);
    m[console][genre][multiplayer].push_back(add);
}

void mapStore ::searchAndPrintBestGame(std::string console, std::string genre, bool multiplayer, std::string rating,
                                       float length) {
    vector<vertex> possibleOutputs;
    if(!(m[console][genre][multiplayer].empty())){
        //cout << m[console][genre][multiplayer].size() << " games found" << endl;
        //we can only return games with e rating
        if(rating == "E"){
            for(int i = 0 ; i < m[console][genre][multiplayer].size() ; i++){
                if(m[console][genre][multiplayer].at(i).rating == "E"){
                    if(length == 41){
                        if (m[console][genre][multiplayer].at(i).length >= 41){
                            possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                        }
                    }
                    else if(m[console][genre][multiplayer].at(i).length > length-20 && m[console][genre][multiplayer].at(i).length < length){
                        possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                    }
                }
            }
        }
        //we can only return games with Teen or lower rating
        if(rating == "T"){
            for(int i = 0 ; i < m[console][genre][multiplayer].size() ; i++){
                if(m[console][genre][multiplayer].at(i).rating != "M"){
                    if(length == 41){
                        if (m[console][genre][multiplayer].at(i).length >= 41){
                            possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                        }
                    }
                    else if(m[console][genre][multiplayer].at(i).length > length-20 && m[console][genre][multiplayer].at(i).length < length){
                        possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                    }
                }
            }
        }
        //rating doesn't matter
        if(rating == "M"){
            for(int i = 0 ; i < m[console][genre][multiplayer].size() ; i++){
                if(length == 41){
                    if (m[console][genre][multiplayer].at(i).length >= 41){
                        possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                    }
                }
                else if(m[console][genre][multiplayer].at(i).length > length-20 && m[console][genre][multiplayer].at(i).length < length){
                    possibleOutputs.push_back(m[console][genre][multiplayer].at(i));
                }
            }
        }
        if(possibleOutputs.size() == 0){
            cout << "No games found, try different search parameters" << endl;
        }
        else{
            cout << possibleOutputs.size() << " games found" << endl;
            //optional-print all games found
        }

        //now, weigh possible options
        vector<float> scores;
        for(int i = 0 ; i < possibleOutputs.size() ; i++){
            //review score over price
            scores.push_back(m[console][genre][multiplayer].at(i).reviews / m[console][genre][multiplayer].at(i).price);
        }
        //grab index
        int highScoreIndex = *max_element(scores.begin(), scores.end());

        //print
        cout << "The best game based on your responses, review score, and price, is: "<< m[console][genre][multiplayer].at(highScoreIndex).name << " " << m[console][genre][multiplayer].at(highScoreIndex).year << endl;
    }
    else{
        cout << "No games found, try different search parameters" << endl;
    }
}