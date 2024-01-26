#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//map for store relationships bettween stations (create the graph)
map<string, vector<string>> metroMap;

// this map include The least number of stations you need for every station 
map<string, int>shortPath;

// insert data to metroMap
void insertData(string firstData, string secondData)
    {
        metroMap[firstData].push_back(secondData);
        metroMap[secondData].push_back(firstData);
    }

// return the least number of stations for your trip
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
