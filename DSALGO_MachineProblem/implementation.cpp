#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include "data.h"
#include <iostream>
using namespace std;

string displayMenu() {
    cout << "Welcome To **** Video Rental!" << endl << endl;
    cout << "Menu:" << endl;
    cout << "[1] New Video" << endl;
    cout << "[2] Rent a Video" << endl;
    cout << "[3] Return a Video" << endl;
    cout << "[4] Show Video Details" << endl;
    cout << "[5] Display all Videos" << endl;
    cout << "[6] Check Video Availability" << endl;
    cout << "[7] Customer Maintenance" << endl;
    cout << "\t [1] Add New Customer" << endl;
    cout << "\t [2] Show Customer Details" << endl;
    cout << "\t [3] List of Videos Rented by a Customer" << endl;
    cout << "[8] Exit Program" << endl << endl;
    cout << "Input Section Number:";
    string choice;
    cin >> choice;
    cout << endl;
    return choice;
}

void newVideo(list<vector<string>> &videoList, vector<vector<string>> &videoVector, int videoNumber) {
    // Declare Temp Variables
    string movieTitle, movieGenre, movieProduction, movieCopies, movieFilename;

    // Input Variables
    cout << "[1] New Video" << endl << endl;
    cout << "Video ID: " << videoNumber << endl;
    string movieID = to_string(videoNumber);
    cout << "Movie Title:";
    cin.ignore();
    getline(cin, movieTitle);
    cout << "Genre:";
    getline(cin, movieGenre);
    cout << "Production:";
    getline(cin, movieProduction);
    cout << "Number of Copies:";
    getline(cin, movieCopies);
    cout << "Movie Image Filename:";
    getline(cin, movieFilename);

    // Push To Temp Vector
    vector<string> tempVideoData{movieTitle, movieGenre, movieProduction, movieCopies, movieFilename};

    // Push Temp Vector To Movie Vector
    videoVector.push_back(tempVideoData);

    // Push Movie Vector To Video List
    videoList.push_back(tempVideoData);
}

void rentVideo(stack<vector<string>> &rentStack, vector<vector<string>> &rentVector, vector<vector<string>> customerVector,
               vector<vector<string>> &videoVector) {
    int custID;
    vector<string> tempRentData;
    cout << "[2] Rent A Video" << endl << endl;
    cout << "Customer ID:";
    cin >> custID;
    cout << "Name:" << customerVector.at(custID - 1).at(0) << endl;
    cout << "Address:" << customerVector.at(custID - 1).at(1) << endl << endl;
    cout << "Videos to Rent..." << endl << endl;

    tempRentData.push_back(customerVector.at(custID - 1).at(0));
    tempRentData.push_back(customerVector.at(custID - 1).at(1));
    bool flagTwo = true;
    while (flagTwo) {
        try {
            int videoID;
            cout << "Video ID:";
            cin >> videoID;
            cout << "Movie Title:" << videoVector.at(videoID - 1).at(0) << endl;
            int currCopy = stoi(videoVector.at(videoID - 1).at(3));

            if (currCopy == 0) {
                cout << "Movie Out Of Stock" << endl << endl;
                flagTwo = false;
            } else {
                currCopy--;
                string newCopy = to_string(currCopy);
                videoVector.at(videoID - 1).at(3) = newCopy;
                cout << "Number of Copies:" << videoVector.at(videoID - 1).at(3) << endl << endl;
                bool flagThree = true;
                while (flagThree) {
                    string yesNo;
                    cout << "Rent another video? (Y / N):";
                    cin >> yesNo;
                    cout << endl;
                    if (yesNo == "Y" || yesNo == "y") {
                        string currVidID = to_string(videoID);
                        tempRentData.push_back(currVidID);
                        flagThree = false;
                    } else if (yesNo == "N" || yesNo == "n") {
                        string currVidID = to_string(videoID);
                        tempRentData.push_back(currVidID);
                        rentVector.push_back(tempRentData);
                        rentStack.push(tempRentData);
                        flagTwo = false;
                        flagThree = false;
                    } else {
                        continue;
                    }
                }
            }
        } catch (exception) {
            cout << "Video ID Unavailable" << endl << endl;
            continue;
        }
    }
}

void returnVideo(vector<vector<string>> rentVector, vector<vector<string>> &videoVector) {
    int custID;
    cout << "[3] Return A Video" << endl << endl;
    cout << "Customer ID:";
    cin >> custID;
    cout << "Videos Rented..." << endl << endl;
    for (int i = 2; i < rentVector.at(custID - 1).size(); i++) {
        cout << "Video ID:" << rentVector.at(custID - 1).at(i) << endl << endl;
        int currCopy = stoi(rentVector.at(custID - 1).at(i));
        currCopy++;
        string newCopy = to_string(currCopy);
        videoVector.at(stoi(rentVector.at(custID - 1).at(i)) - 1).at(3) = newCopy;
    }
    cout << "Videos successfully returned!" << endl << endl;
}

void showIndivVideo(vector<vector<string>> &videoVector) {
    int videoID;
    cout << "[4] Show Video Details" << endl << endl;
    cout << "Video ID:";
    cin >> videoID;
    cout << "Movie Title:" << videoVector.at(videoID - 1).at(0) << endl;
    cout << "Genre:" << videoVector.at(videoID - 1).at(1) << endl;
    cout << "Production:" << videoVector.at(videoID - 1).at(2) << endl;
    cout << "Number of Copies:" << videoVector.at(videoID - 1).at(3) << endl;
    cout << "Movie Image:" << videoVector.at(videoID - 1).at(4) << endl << endl;
}

void showAllVideo(vector<vector<string>> &videoVector) {
    cout << "[5] Show All Videos" << endl << endl;
    for (int i = 0; i < videoVector.size(); i++) {
        cout << "Video ID: " << (i + 1) << endl;
        cout << "Movie Title:" << videoVector.at(i).at(0) << endl;
        cout << "Genre:" << videoVector.at(i).at(1) << endl;
        cout << "Production:" << videoVector.at(i).at(2) << endl;
        cout << "Movie Image:" << videoVector.at(i).at(4) << endl << endl;
    }
}

void availabilityVideo(vector<vector<string>> &videoVector) {
    int videoID;
    cout << "[6] Check Video Availability" << endl << endl;
    cout << "Video ID:";
    cin >> videoID;
    cout << "Movie Title:" << videoVector.at(videoID - 1).at(0) << endl;
    cout << "Genre:" << videoVector.at(videoID - 1).at(1) << endl;
    cout << "Production:" << videoVector.at(videoID - 1).at(2) << endl;
    cout << "Number of Copies:" << videoVector.at(videoID - 1).at(3) << endl;
    int numCopies = stoi(videoVector.at(videoID - 1).at(3));
    if (numCopies >= 1) {
        cout << "Availability:Available" << endl << endl;
    } else {
        cout << "Availability:Unavailable" << endl << endl;
    }
}

string customerMaintenance() {
    cout << "Customer Maintenance" << endl << endl;
    cout << "[1] Add New Customer" << endl;
    cout << "[2] Show Customer Details" << endl;
    cout << "[3] List of Videos Rented by a Customer" << endl;
    cout << "Input Section Number:";
    string choice;
    cin >> choice;
    cout << endl;
    return choice;
}

void addCustomer(queue<vector<string>> &customerQueue, vector<vector<string>> &customerVector, int currCustomerNum) {
    string customerName, customerAddress;
    cout << "[7-1] Add New Customer" << endl << endl;
    cin.ignore();
    cout << "Customer ID:" << currCustomerNum << endl;
    string custID = to_string(currCustomerNum);
    cout << "Name:";
    getline(cin, customerName);
    cout << "Address:";
    getline(cin, customerAddress);

    // Push To Temp Vector
    vector<string> tempCustData{customerName, customerAddress};

    // Push Temp Vector To Customer Vector
    customerVector.push_back(tempCustData);

    // Push Customer Vector To Queue
    customerQueue.push(tempCustData);

}

void showCustomer(vector<vector<string>> customerVector) {
    int custID;
    cout << "[7-2] Show Customer Details" << endl << endl;
    cout << "Customer ID:";
    cin >> custID;
    cout << "Name:" << customerVector.at(custID - 1).at(0) << endl;
    cout << "Address:" << customerVector.at(custID - 1).at(1) << endl << endl;
}

void rentedByCustomer(vector<vector<string>> rentVector, vector<vector<string>> videoVector) {
    int custID;
    cout << "[7-3] List All Videos Rented By A Customer" << endl << endl;
    cout << "Customer ID:";
    cin >> custID;
    cout << "Name:" << rentVector.at(custID - 1).at(0) << endl;
    cout << "Address:" << rentVector.at(custID - 1).at(1) << endl << endl;
    cout << "List of Videos Rented..." << endl << endl;
    for (int i = 2; i < rentVector.at(custID - 1).size(); i++) {
        cout << "Video ID:" << rentVector.at(custID - 1).at(i) << "\tMovie Title:" << videoVector.at(i - 2).at(0)
             << endl << endl;
    }

}

void exportList(list<vector<string>> videoList) {
    ofstream videoFile;
    videoFile.open("videoLinkedList.txt");
    int currVidNum = 1;
    list<vector<string>>::iterator it;
    for (it = videoList.begin(); it != videoList.end(); ++it) {
        videoFile << "Video_ID" << currVidNum << endl;
        videoFile << "Movie Title:" << it->at(0) << endl;
        videoFile << "Genre:" << it->at(1) << endl;
        videoFile << "Production:" << it->at(2) << endl;
        videoFile << "Number of Copies:" << it->at(3) << endl << endl;
        currVidNum++;
    }
    videoFile.close();
    cout << "All Video Details Successfully Written!" << endl;
}

void exportQueue(queue<vector<string>> customerQueue) {
    ofstream customerFile;
    customerFile.open("customerQueue.txt");
    int currCustomerNum = 1;
    while (!customerQueue.empty()) {
        customerFile << "Customer_ID:" << currCustomerNum << endl;
        customerFile << "Name:" << customerQueue.front()[0] << endl;
        customerFile << "Address:" << customerQueue.front()[1] << endl << endl;
        customerQueue.pop();
        currCustomerNum++;
    }
    customerFile.close();
    cout << "All Customer Details Successfully Written!" << endl;
}

void exportStack(stack<vector<string>> rentStack) {
    ofstream rentFile;
    rentFile.open("rentStack.txt");
    int currRentNum = 1;
    while (!rentStack.empty()) {
        rentFile << "Customer_ID:" << rentStack.top()[0] << endl;
        rentFile << "Name:" << rentStack.top()[1] << endl;
        for (int i = 2; i < rentStack.top().size(); i++) {
            rentFile << "Video_ID:" << i - 1 << endl;
        }
        rentStack.pop();
        currRentNum++;
    }
    rentFile.close();
    cout << "All Rent Details Successfully Written!" << endl;
}

void preLoadValues(list<vector<string>> &videoList, vector<vector<string>> &videoVector,
                   queue<vector<string>> &customerQueue, vector<vector<string>> &customerVector) {
    string initialVideos[20][5] = {{"The Conjuring",         "Horror",   "New Line Cinema The Safran Company Evergreen Media Group", "3", "c:/conjuring.jpg"},
                                   {"The Exorcist",          "Horror",   "Hoya Productions", "8", "c:/exorcist.jpg"},
                                   {"The Shining",           "Horror",   "EMI Elstree Studios Number of Copies", "5", "c:/shining.jpg"},
                                   {"Paranormal Activity",   "Horror",   "Blumhouse Production", "1", "c:/paranormal.jpg"},
                                   {"The Descent",           "Horror",   "Celador Films Northmen Productions", "3", "c:/descent.jpg"},

                                   {"All the Bright Places", "Romantic", "Echo Lake Entertainment Mazur/Kaplan Company Demarest Media", "4", "c:/brightplaces.jpg"},
                                   {"365 Days",              "Romantic", "Future Space", "1", "c:/365.jpg"},
                                   {"After We Fell",         "Romantic", "Voltage Pictures CalMaple Media Ethea Entertainment Wattpad", "4", "c:/afterfall.jpg"},
                                   {"After We Collided",     "Romantic", "Voltage Pictures CalMaple Media Ethea Entertainment Wattpad", "2", "c:/aftercollided.jpg"},
                                   {"Be With You",           "Romantic", "Movie Rock", "4", "c:/bewithyou.jpg"},

                                   {"Oxygen",                "Sci - Fi", "Gateway Films Wild Bunch Echo Lake Entertainment", "4", "c:/oxygen.jpg"},
                                   {"Arrival",               "Sci - Fi", "FilmNation Entertainment Lava Bear Films 21 Laps Entertainment", "4", "c:/arrival.jpg"},
                                   {"Looper",                "Sci - Fi", "TriStar Pictures FilmDistrict Endgame Entertainment DMG Entertainment Ram Bergman Productions", "4", "c:/looper.jpg"},
                                   {"Inception",             "Sci - Fi", "VWarner Bros. Pictures", "4", "c:/inception.jpg"},
                                   {"Snowpiercer",           "Sci - Fi", "Moho Film Opus Pictures Union Investment Partners Stillking Films", "4", "c:/snowpiercer.jpg"},

                                   {"Onward",                "Comedy",   "Walt Disney Pictures Pixar Animation Studios", "6", "c:/onward.jpg"},
                                   {"The Spy",               "Comedy",   "Legende Films ", "1", "c:/spy.jpg"},
                                   {"The Climb",             "Comedy",   "Topic Studios Watch this Ready", "22", "c:/climb.jpg"},
                                   {"Bad Boys for Life",     "Comedy",   "Columbia Pictures 2.0 Entertainment Don Simpson/Jerry Bruckheimer Films Overbrook Entertainment", "3", "c:/badboys.jpg"},
                                   {"Come As You Are",       "Comedy",   "Chicago Media Angels Florida Hill Entertainment The Black List", "1", "c:/comeasyouare.jpg"},
    };
    string initialCustomers[20][4] = {{"Nuriel Aguilar",     "San Juan City"},
                                      {"Kirt Tejada",        "Davao City"},
                                      {"Lynch Fabroa",       "Bataan City"},
                                      {"Angela Dela Cruz",   "Manila City"},
                                      {"Kurl Gabin",         "San Juan City"},

                                      {"Johannes Gregorio",  "Manila City"},
                                      {"Deo Buenavista",     "Manila City"},
                                      {"Jonas Garcia",       "Batangas City"},
                                      {"Ron Artest",         "Palawan City"},
                                      {"Maria Bartolome",    "Mandaluyong City"},

                                      {"Kyla Sarmiento",     "Mandaluyong City"},
                                      {"Rey Edubas",         "Quezon City"},
                                      {"Pardeep Singh",      "San Juan City"},
                                      {"Nemuel Aguilar",     "San Juan City"},
                                      {"Isaac Betic",        "Tondo Manila"},

                                      {"Dieter De San Jose", "Laguna City"},
                                      {"Samantha Cruz",      "Cebu City"},
                                      {"Albert Cansino",     "Cavite City"},
                                      {"Darren Coprado",     "San Juan City"},
                                      {"Adrian Fria",        "Sampaloc Manila"},
    };
    for (int i = 0; i < 20; i++) {
        vector<string> tempVideoData{initialVideos[i][0], initialVideos[i][1], initialVideos[i][2],
                                     initialVideos[i][3], initialVideos[i][4]};
        vector<string> tempCustData{initialCustomers[i][0], initialCustomers[i][1]};
        videoVector.push_back(tempVideoData);
        videoList.push_back(tempVideoData);
        customerVector.push_back(tempCustData);
        customerQueue.push(tempCustData);
    }
}