#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//map for store relationships bettween stations (create the graph)
map<string, vector<string>> metroMap;
//
//
//= {
//                            {"Helwan",{"Ain Helwan"}}, 
//                            {"Ain Helwan",{"Helwan","Helwan University"}},
//                            {"Helwan University",{"Ain Helwan","Wadi Hof"}},
//                            {"Wadi Hof",{"Helwan University","Hadayek Helwan"}},
//                            {"Hadayek Helwan",{"Wadi Hof","Elmasraa"}},
//                            {"Elmasraa",{"Tura El-Esmant","Hadayek Helwan"}},
//                            {"Tura El-Esmant",{"Elmasraan","Kozzika"}},
//                            {"Kozzika",{"Tura El-Esmant","Tora El-Balad"}},
//                            {"Tora El-Balad",{"Kozzika","Sakanat El-Maadi"}},
//                            {"Sakanat El-Maadi",{"Tora El-Balad","Maadi"}},
//                            {"Maadi",{"Sakanat El-Maadi","Hadayek El-Maadi"}},
//                            {"Hadayek El-Maadi",{"Maadi","Dar El-Salam"}},
//                            {"Dar El-Salam",{"Hadayek El-Maadi","El-Zahraa"}},
//                            {"El-Zahraa",{"Dar El-Salam","Mar Girgis"}},
//                            {"Mar Girgis",{"El-Zahraa","El-Malek El-Saleh"}},
//                            {"El-Malek El-Saleh",{"Mar Girgis","Al-Sayeda Zeinab"}},
//                            {"Al-Sayeda Zeinab",{"El-Malek El-Saleh",""}},
//                            {"Saad Zaghloul",{"Al-Sayeda Zeinab",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//                            {"",{"",""}},
//"Saad Zaghloul", "Sadat", "Nasser", "Orabi", "Al-Shohadaa", "Ghamra",
//"El-Demerdash", "Manshiet El-Sadr", "Kobri El-Qobba", "Hammamat El-Qobba", "Saray El-Qobba",
//"Hadayeq El-Zaitoun", "Helmeyet El-Zaitoun", "El-Matareyya", "Ain Shams", "Ezbet El-Nakhl"
//};

//
//1 2  3 4 5 6 7 8 9
//
//metroMap[3].push_back(4);
//metroMap[4].push_back(3);
//
//1 -> 2
//2 -> 1 3
//3 -> 2 4
//4 -> 3 5
//5 -> 4 6
//6 -> 5 7
//7 -> 6 8
//8 -> 7 9
//9 -> 8 

// this map include The least number of stations you need for every station 
map<string,pair<int,string>>shortPath;

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
        shortPath[start].first = 0;
        shortPath[start].second = "none";
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
                    shortPath[child].first = shortPath[front].first + 1;
                    shortPath[child].second = front;
                }
            }
        }
        return shortPath[end].first;
}


string displayPath(string end) {
    // The Parent of station 
    string parent = shortPath[end].second;
    // if the parent = none , so this is the start station 
    if (shortPath[end].second == "none") {
        return end;
    }
    // insert this station
    string path = displayPath(parent);
    return path + " -> " + end;
}
