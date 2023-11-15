#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "mapStore.h"
#include "mergeSort.h"
#include <chrono>
using namespace std;

//gets rid of quotation marks around a string
string trimString(string toTrim){
    toTrim.erase(0,1);
    toTrim.erase(toTrim.length()-1, 1);
    return toTrim;
}

int main() {
    mergeSort merger;
    mapStore map;
    //parsing data from file
    ifstream inFile("video_games.csv");
    if(inFile.is_open()){
        string fileLine;
        getline(inFile,fileLine);

        //all the data used, initially stored as a string
        string title, console, rating, yearS, multiplayer, usedpriceS, lengthS, genre, reviewS, skip;

        //will be converted from string values
        bool multiplayerTF;
        int year;
        float review, usedprice, length;
        while(getline(inFile,fileLine)){
            istringstream stream(fileLine);

            //there can be a comma in the title, so it must be read differently
            getline(stream, skip, '"');
            getline(stream, title, '"');
            getline(stream, skip, ',');
            getline(stream, skip, ',');

            getline(stream, multiplayer, ',');
            getline(stream, skip, ',');
            getline(stream, skip, ',');
            getline(stream, skip, '"');
            //there can be subgenres, but for this program, we'll only consider
            //the main genre
            getline(stream, skip, '"');
            stringstream temp(skip);
            getline(temp,genre, ',');
            //cout << genre << endl;

            getline(stream, skip, ',');
            getline(stream, skip, ',');

            //there can also be multiple publishers, for some reason seperated by a comma
            getline(stream, skip, '"');
            getline(stream, skip, '"');
            getline(stream, skip, ',');
            getline(stream, skip, ',');

            getline(stream, reviewS, ',');
            reviewS = trimString(reviewS);
            review = stof(reviewS);

            getline(stream, skip, ',');
            getline(stream, usedpriceS, ',');
            usedpriceS = trimString(usedpriceS);
            usedprice = stof(usedpriceS);

            getline(stream, console, ',');
            console = trimString(console);
            //cout << console << endl;
            getline(stream, rating, ',');
            getline(stream, skip, ',');
            getline(stream, yearS, ',');
            yearS = trimString(yearS);
            year = stoi(yearS);

            getline(stream, skip, ',');
            getline(stream, skip, ',');
            getline(stream, lengthS, ',');
            lengthS = trimString(lengthS);
            length = stof(lengthS);


            multiplayer = trimString(multiplayer);
            if(stoi(multiplayer) > 1){
                multiplayerTF = true;
            }
            else{
                multiplayerTF = false;
            }


            //insert data/ nodes
            //all the commented out code can be used to compare insertion times
            //but it prints out hundreds of statements every time, so its
            //not practical to run it every time


            //auto start = chrono::high_resolution_clock ::now();
            map.insertGame(console, genre,multiplayerTF, title, year, usedprice, review, length, rating);
            //auto stop = chrono::high_resolution_clock ::now();
            //auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
            //cout << "Insertion time (3D map) = " << duration.count() << "micro s" << endl;

            //start = chrono::high_resolution_clock ::now();
            merger.insertGame(console, genre,multiplayerTF, title, year, usedprice, review, length, rating);
            // stop = chrono::high_resolution_clock ::now();
            //duration = chrono::duration_cast<chrono::microseconds>(stop-start);
            //cout << "Insertion time (Merge Sort) = " << duration.count() << "micro s" << endl;
        }
    }

    //Gather data about user
    //these are the parameters that are used to search, the other data points will be used for deciding which is the best option out of all the games
    //that meet these conditions, then the name and year will simply be displayed.
    string console;
    string rating;
    string genre;
    bool multiplayer;
    float length;

    //merger.sortInit();
    cout << "Hello, this program will help you search for a 2000's era video game based on your preferences and needs" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "First, what type of console are you playing on?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. Nintendo DS" << endl;
    cout << "   2. Nintendo Wii" << endl;
    cout << "   3. X-Box 360" <<endl;
    cout << "   4. PlayStation 3" <<endl;
    cout << "   5. Sony PSP" << endl;
    int consolenum;
    cin >> consolenum;
    switch(consolenum){
        case 1:
            console = "Nintendo DS";
            break;
        case 2:
            console = "Nintendo Wii";
            break;
        case 3:
            console = "X360";
            break;
        case 4:
            console = "PlayStation 3";
            break;
        case 5:
            console = "Sony PSP";
            break;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Do you need the game to be a certain rating?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. E only (Everyone)" << endl;
    cout << "   2. T and under (Teen & Everyone)" << endl;
    cout << "   3. Any rating (including Mature)" <<endl;
    int ratingNum;
    cin >> ratingNum;
    switch(ratingNum){
        case 1:
            rating = "E";
            break;
        case 2:
            rating = "T";
        case 3:
            rating = "M";
    }

    cout << "---------------------------------------------------" << endl;
    cout << "Next, what type of genre do you prefer?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. Action" << endl;
    cout << "   2. Strategy" << endl;
    cout << "   3. RPG" <<endl;
    cout << "   4. Sports" <<endl;
    cout << "   5. Racing" << endl;
    cout << "   6. Simulation" << endl;
    int genreNum;
    cin >> genreNum;
    switch(genreNum){
        case 1:
            genre = "Action";
            break;
        case 2:
            genre = "Strategy";
            break;
        case 3:
            genre = "Role-Playing (RPG)";
            break;
        case 4:
            genre = "Sports";
            break;
        case 5:
            genre = "Racing / Driving";
            break;
        case 6:
            genre = "Simulation";
            break;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Do you want a singleplayer game, or one with multiplayer options?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. Singleplayer only" << endl;
    cout << "   2. Multiplayer option" << endl;
    int multiNum;
    cin >> multiNum;
    switch(multiNum){
        case 1:
            multiplayer = false;
            break;
        case 2:
            multiplayer = true;
            break;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Lastly, how long do you want the game to be? (hours)" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. 0-20 (short)" << endl;
    cout << "   2. 21-40 (short)" << endl;
    cout << "   3. 41+ (long)" <<endl;


    int hourNum;
    cin >> hourNum;
    switch (hourNum) {
        case 1:
            length = 20;
            break;
        case 2:
            length = 40;
            break;
        case 3:
            length = 41;
            break;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Using map based algorithm" << endl;
    auto start = chrono::high_resolution_clock :: now();
    map.searchAndPrintBestGame(console, genre, multiplayer, rating, length);
    auto stop = chrono::high_resolution_clock ::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << "Execution time (3D map search) = " << duration.count() << "micro s" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Using merge sort algorithm" << endl;
    start = chrono::high_resolution_clock :: now();
    merger.sortInit();
    merger.printBestGame(console, genre, multiplayer, rating, length);
    stop = chrono::high_resolution_clock ::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << "Execution time (merge sort) = " << duration.count() << "micro s" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "These execution times do not factor in the insertion time" << endl;
    return 0;
}
