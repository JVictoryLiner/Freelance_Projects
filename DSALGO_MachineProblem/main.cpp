#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include "data.h"

using namespace std;

int main() {

    // Videos LinkedList and Vector
    list<vector<string>> videoList;
    vector<vector<string>> videoVector;

    // Customer Queue and Vector
    queue<vector<string>> customerQueue;
    vector<vector<string>> customerVector;

    // Rent Stack and Vector
    stack<vector<string>> rentStack;
    vector<vector<string>> rentVector;

    int currVidNum = videoList.size() + 1;
    // int currVidNum = 1;
    int currCustomerNum = customerVector.size() + 1;
    // int currCustomerNum = 1;
    preLoadValues(videoList, videoVector, customerQueue, customerVector);
    bool flagOne = true;
    while (flagOne) {
        string a = displayMenu();
        try {
            int choiceOne = stoi(a);
            if (choiceOne == 1) {
                newVideo(videoList, videoVector, currVidNum);
                currVidNum++;
            } else if (choiceOne == 2) {
                rentVideo(rentStack, rentVector, customerVector, videoVector);
            } else if (choiceOne == 3) {
                returnVideo(rentVector, videoVector);
            } else if (choiceOne == 4) {
                showIndivVideo(videoVector);
            } else if (choiceOne == 5) {
                showAllVideo(videoVector);
            } else if (choiceOne == 6) {
                availabilityVideo(videoVector);
            } else if (choiceOne == 7) {
                string b = customerMaintenance();
                try {
                    int choiceTwo = stoi(b);
                    if (choiceTwo == 1) {
                        addCustomer(customerQueue, customerVector, currCustomerNum);
                        currCustomerNum++;
                    } else if (choiceTwo == 2) {
                        showCustomer(customerVector);
                    } else if (choiceTwo == 3) {
                        rentedByCustomer(rentVector, videoVector);
                    }
                } catch (invalid_argument) {
                    continue;
                }
            } else if (choiceOne == 8) {
                exportList(videoList);
                exportQueue(customerQueue);
                exportStack(rentStack);
                flagOne = false;
            }
        } catch (invalid_argument) {
            continue;
        }

    }

    return 0;
}


