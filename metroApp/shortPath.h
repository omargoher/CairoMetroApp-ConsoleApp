#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//map for store relationships between stations (create the graph)
map<string, vector<string>> metroMap;

//This map includes The least number of stations you need for every station 
map<string, int>shortPath;

// insert data to metroMap
void insertData(string firstData, string secondData)
    {
        metroMap[firstData].push_back(secondData);
        metroMap[secondData].push_back(firstData);
    }

//Return the least number of stations for your trip
int numberOfStations(string start, string end)
    {
        queue<string>level;
        shortPath[start] = 0;
        level.push(start);
        while (!level.empty())
        {
            string front = level.front();
            level.pop();
            for (string child : metroMap[front])
            {
                if (shortPath.count(child) == 0)
                {
                    level.push(child);
                    shortPath[child] = shortPath[front] + 1;
                }
            }
        }
        return shortPath[end];
    }

// Display All Stations in the shortest path
string displayPath(string end) {
    // The Parent of station 
    string parent = shortPath[end].second;
    //If the parent = none, so this is the start station 
    if (shortPath[end].second == "none") {
        return end;
    }
    // insert this station
    string path = displayPath(parent);
    return path + " -> " + end;
}
