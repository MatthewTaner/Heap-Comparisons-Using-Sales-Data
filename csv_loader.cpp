//
// Created by Owner on 11/4/2025.
//

#include "csv_loader.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<Record> load_csv(const std::string& path) {
    vector<Record> inputs;
    string line;
    ifstream inputFile(path);

    //check forfile open
    if (!inputFile.is_open()) {
        cout << "Could not open CSV: " << path << endl;
        return inputs;
    }

    bool firstLine = true;

    while(getline(inputFile,line)) {
        if (line.empty()) continue;

        if (firstLine) {
            firstLine = false;
            continue;
        }

        stringstream fileLines(line);
        string storage;

        //first and second values from the csv, garbage values
        getline(fileLines, storage, ',');
        getline(fileLines, storage, ',');

        //third value, which is the type of item, we'll store this for our Record
        getline(fileLines, storage, ',');
        string itemType = storage;

        //4th - 8th values from the csv, garbage values
        for (int i = 0; i < 5; ++i) {
            getline(fileLines, storage, ',');
        }

        //9th value, which is the number sold, we'll store this for our Record
        getline(fileLines, storage, ',');
        if (storage.empty()) storage = "0";

        int unitsSold;
        try {
            unitsSold = stoi(storage);
        } catch(...) {
            continue;
        }

        //Here, we instantiate a new Record object, which gets pushed back
        Record record = Record(unitsSold, itemType);
        inputs.push_back(record);
    }
    return inputs;
}
