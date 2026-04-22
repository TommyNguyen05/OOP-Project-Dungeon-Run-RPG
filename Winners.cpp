#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Winners.h"

using namespace std;

void Winners::bubbleSort(string names[], int scores[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                // Swap scores
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;

                // Swap names
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}

// Constructor
Winners::Winners() {
    winnersList = new vector<string>();
}

// Destructor: clean up by deleting the vector
Winners::~Winners() {
    if (winnersList) {
        winnersList->clear();
        delete winnersList;
    }
}

// Save name and score to the file
void Winners::saveName(const string& name, int score, const string& filename) {
    ofstream outFile(filename, ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << name << " " << score << endl; // Append name and score
        outFile.close();
    } else {
        cerr << "Error opening file for writing!" << endl;
    }
}

// Function to load names and scores from a file and sort them
vector<string> Winners::loadNames(const string& filename) {
    vector<string> names;
    vector<int> scores;

    ifstream inFile(filename); // Open the file for reading
    if (inFile.is_open()) {
        string name;
        int score;

        // Reading names and scores from the file
        while (inFile >> name >> score) {
            names.push_back(name);
            scores.push_back(score);
        }

        inFile.close();

        // If there are any entries, proceed with sorting
        int count = names.size();
        if (count > 0) {
            // Convert vectors to arrays for sorting
            string* namesArr = new string[count];
            int* scoresArr = new int[count];

            for (int i = 0; i < count; i++) {
                namesArr[i] = names[i];
                scoresArr[i] = scores[i];
            }

            // Sort arrays using bubbleSort
            bubbleSort(namesArr, scoresArr, count);

            // Clear original vector and push back sorted names
            names.clear();
            for (int i = 0; i < count; i++) {
                names.push_back(namesArr[i]);
            }

            // Clean up dynamically allocated arrays
            delete[] namesArr;
            delete[] scoresArr;
        }
    } else {
        cerr << "Error opening file for reading!" << endl;
    }

    return names; // Return sorted names
}
