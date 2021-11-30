#ifndef MACHPROB_DATA_H
#define MACHPROB_DATA_H

#endif //MACHPROB_DATA_H
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
using namespace std;

string displayMenu();
void newVideo(list<vector<string>> &videoList, vector<vector<string>> &videoVector, int videoNumber);
void rentVideo(stack<vector<string>> &rentStack, vector<vector<string>> &rentVector, vector<vector<string>> customerVector,
               vector<vector<string>> &videoVector);
void returnVideo(vector<vector<string>> rentVector, vector<vector<string>> &videoVector);
void showIndivVideo(vector<vector<string>> &videoVector);
void showAllVideo(vector<vector<string>> &videoVector);
void availabilityVideo(vector<vector<string>> &videoVector);
string customerMaintenance();
void addCustomer(queue<vector<string>> &customerQueue, vector<vector<string>> &customerVector, int currCustomerNum);
void showCustomer(vector<vector<string>> customerVector);
void rentedByCustomer(vector<vector<string>> rentVector, vector<vector<string>> videoVector);
void exportList(list<vector<string>> videoList);
void exportQueue(queue<vector<string>> customerQueue);
void exportStack(stack<vector<string>> rentStack);
void preLoadValues(list<vector<string>> &videoList, vector<vector<string>> &videoVector,
                   queue<vector<string>> &customerQueue, vector<vector<string>> &customerVector);