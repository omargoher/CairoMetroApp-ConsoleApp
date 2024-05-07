#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "shortestPath.h"
using namespace std;

int main() {
    // metro stations 
    vector<string>
        choseMenu = {
        "Line1", "Line2", "Line3"},
        line1 = {
         "Helwan","Ain Helwan","Helwan University","Wadi Hof","Hadayek Helwan",
         "Elmasraa","Tura El-Esmant","Kozzika","Tora El-Balad","Sakanat El-Maadi",
         "Maadi","Hadayek El-Maadi","Dar El-Salam","El-Zahraa",  "Mar Girgis", "El-Malek El-Saleh",
         "Al-Sayeda Zeinab", "Saad Zaghloul", "Sadat", "Nasser", "Orabi", "Al-Shohadaa", "Ghamra",
         "El-Demerdash", "Manshiet El-Sadr", "Kobri El-Qobba", "Hammamat El-Qobba", "Saray El-Qobba",
         "Hadayeq El-Zaitoun", "Helmeyet El-Zaitoun", "El-Matareyya", "Ain Shams", "Ezbet El-Nakhl", "El Marg", "New Marg"},
        line2 = {
         "El Monib", "Sakiat Mekky", "Omm El-Masryeen", "Giza", "Faisal", "Cairo University",
         "El Bohoth", "Dokki", "Opera", "Sadat", "Mohamed Naguib", "Attaba", "Al-Shohadaa", "Masarra", "Rod El-Farag",
         "St. Teresa", "Khalafawy", "Mezallat", "Koliet El-Zeraa", "Shubra Al Khaimah" },
        line3 = {
         "Adly Mansour","Haykesteb","Omar Ibn El Khattab","Qubaa","Hesham Barakat","El Nozha","El Shams Club",
         "Alf Maskan","Heliopolis","Haroun","Al-Ahram","Koleyet El-Banat","Stadium","Fair Zone","Abbassiya",
         "Abdou Pasha","El-Geish","Bab El Shaarlya","Attaba","Nasser","Maspero","Safaa Hijazy","Kit-Kat" };
    
    string userChoise, startStations, endStations;

    cout << "Hi, in Cairo Metro App\n";
    setColor(1,1);//change color to blue
    cout << "use up and down arrow :)\n";
    setColor(5, 1);//change color to defualt
    cout << "Which line are you starting from?\n";
    userChoise = display(choseMenu);

    cout << "Please enter the start station\n";
    if (userChoise == "Line1") {
        userChoise = display(line1);
    }
    else if (userChoise == "Line2") {
        userChoise = display(line2);
    }
    else if (userChoise == "Line3") {
        userChoise = display(line3);
    }
    startStations = userChoise;

    cout << "Which line will you go to?\n";
    userChoise = display(choseMenu);
    
    cout << "Please enter the end station\n";
    if (userChoise == "Line1") {
        userChoise = display(line1);
    }
    else if (userChoise == "Line2") {
        userChoise = display(line2);
    }
    else if (userChoise == "Line3") {
        userChoise = display(line3);
    }
    endStations = userChoise;
    
    // insert data (create the metro graph)
    for (int i = 0; i < line1.size() - 1; ++i)
    {
        insertData(line1[i], line1[i + 1]);
    }
    for (int i = 0; i < line2.size() - 1; ++i)
    {
        insertData(line2[i], line2[i + 1]);
    }
    for (int i = 0; i < line3.size() - 1; ++i)
    {
        insertData(line3[i], line3[i + 1]);
    }
    
    int numStations = numberOfStations(startStations, endStations);
    setColor(1, 1);// change color to blue
    cout << "The number of stations in your trip is " << numStations << "\n" << "Your The Tiket Price is : ";
    
    // calculate the Ticket price
    if (numStations <= 9) {
        // if number of stations in the trip less than or equal 9 The tiket price equal 6
        cout << 6;
    }
    else if (numStations <= 16) {
        // if number of stations in the trip less than or equal 16 and more than 9 The tiket price equal 8
        cout << 8;
    }
    else if (numStations <= 23){
        // if number of stations in the trip less than or equal 23 and more than 16 The tiket price equal 12
        cout << 12;
    }
    else {
        // if number of stations in the trip more than 23 The tiket price equal 15
        cout << 15;
    }

    setColor(4, 2);

    // Display All stations in the trip
    cout << "\nTrip stations:";
    setColor(1, 1);// change color to blue
    cout << displayPath(endStations) << "\n";
    setColor(1, 2);

    return 0;
}
