#ifndef WINNERS_H
#define WINNERS_H

#include <vector>
#include <string>

using namespace std;

class Winners
{
private:
    vector<string>* winnersList;
    void bubbleSort(std::string names[], int scores[], int count);
public:
    Winners();
    void saveName(const string& name,int score, const string& filename);
    vector<string> loadNames(const string& filename);
    ~Winners();
};


#endif
