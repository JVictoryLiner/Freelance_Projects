#include <string>     //Allows us to use string throughout coding
#include <iostream>   //inputs and outputs data
#include <algorithm>  //Provides instant sorting, counting, searching and manipulting.
#include <sstream>    //String stream for header (Used here for casting)
#include <math.h>     //Gives us the ability to use math function (e.g. pow)
using namespace std;  //Doesnt have to use 'std::' on every data/line

// Binary to Hex algorithm
void hex(int num) {
    int i, j = 0, h[20], k;
    for (i = 0; num > 0; i++) {
        for (int y = 0; y < 4; y++) {
            k = num % 10;
            num /= 10;
            j += k * pow(2, y);
        }
        h[i] = j;
        j = 0;
    }
    while (i > 0) {
        i--;
        if (h[i] > 9)
            cout << char(55 + h[i]);
        else
            cout << h[i];
    }
}

// OpCode ADD and MOVE shared function.
void addMoveFunction(string binaryValue, string secondValReversed, string secondVal) {
    stringstream convert(binaryValue);  // Casting String to Int
    int cast = 0;                       // Casting String to Int
    convert >> cast;                    // Casting String to Int
    secondValReversed = string(secondVal.rbegin(), secondVal.rend());   // Reverse String
    swap(secondValReversed[0], secondValReversed[1]); // Swap FIRST and SECOND char
    swap(secondValReversed[2], secondValReversed[3]); // Swap THIRD and FOURTH char

    cout << "\bBinary Value is : " << binaryValue << endl;  // Print out
    cout << "Result is : ";                                 // Print out
    hex(cast);                                              // Print out
    cout << " hex";                                         // Print out
}

// OpCode LOAD function
void loadFunction(string binaryValue, string secondValReversed, string secondVal, string noCommaFirstVal) {
    stringstream convert(binaryValue);  // Casting String to Int
    int cast = 0;                       // Casting String to Int
    convert >> cast;                    // Casting String to Int
    secondValReversed = string(secondVal.rbegin(), secondVal.rend());   // Reverse String
    swap(secondValReversed[0], secondValReversed[1]); // Swap FIRST and SECOND char
    swap(secondValReversed[2], secondValReversed[3]); // Swap THIRD and FOURTH

    cout << "\bBinary Value is : " << binaryValue << endl;  // Print out
    cout << "Little endian result is : ";                   // Print out
    hex(cast);                                              // Print out
    cout << secondValReversed << " hex";                    // Print out
}

// OpCode STORE function
void storeFunction(string binaryValue, string noCommaFirstVal, string firstValReversed) {
    stringstream convert(binaryValue);  // Casting String to Int
    int cast = 0;                       // Casting String to Int
    convert >> cast;                    // Casting String to Int
    firstValReversed = string(noCommaFirstVal.rbegin(), noCommaFirstVal.rend());    // Reverse String
    swap(firstValReversed[0], firstValReversed[1]); // Swap FIRST and SECOND char
    swap(firstValReversed[2], firstValReversed[3]); // Swap THIRD and FOURTH char

    cout << "\bBinary Value is : " << binaryValue << endl;  // Print out
    cout << "Little endian result is : ";                   // Print out
    hex(cast);                                              // Print out
    cout << firstValReversed << " hex";                     // Print out
}

// OpCode JMP / JPZ / JPP / JPN functions
void jFunction(string binaryValue, string firstValReversed, string firstVal) {
    stringstream convert(binaryValue);  // Casting String to Int
    int cast = 0;                       // Casting String to Int
    convert >> cast;                    // Casting String to Int
    firstValReversed = string(firstVal.rbegin(), firstVal.rend()); // Reverse String
    swap(firstValReversed[0], firstValReversed[1]); // Swap FIRST and SECOND char
    swap(firstValReversed[2], firstValReversed[3]); // Swap THIRD and FOURTH char

    cout << "\bBinary Value is : " << binaryValue << endl;  // Print out
    cout << "Little endian result is : ";                   // Print out
    hex(cast);                                              // Print out
    cout << firstValReversed << " hex";                     // Print out
}

int main() {

    // Initialize Variables
    string firstVal, secondVal, opCode, userInput, userChoice;
    string binaryValue = "";
    string firstValReversed;
    string secondValReversed;

    // Print Out Program Guide
    cout << "  Choose an OpCode section : " << endl;
    // OpCode Selection
    cout << "(A - ADD / MOVE / STORE / LOAD)" << endl;
    cout << "  (B - JMP / JPZ / JPP / JPN)" << endl;
    cout << endl;
    cout << "    Enter OpCode Section : ";
    // Input OpCode Section
    cin >> userChoice;
    cout << " " << endl;
    // Input A/a or B/b or Other = Invalid Choice
    if (userChoice == "A" || userChoice == "a") {
        cout << "\bEnter OpCode_DestReg,_Addr (Separate by space) : ";
        cin >> opCode >> firstVal >> secondVal;

    } else if (userChoice == "B" || userChoice == "b") {
        cout << "\bEnter OpCode : ";
        cin >> opCode >> firstVal;
    } else {
        cout << "\bInvalid Choice." << endl;
    }

    // Removes comma for value (DestReg / Addr) after OpCode
    string noCommaFirstVal = firstVal.substr(0, firstVal.size() - 1);

    firstValReversed = noCommaFirstVal; // Make a copy of a string
    secondValReversed = secondVal;      // Make a copy of a string

    // OpCode Section A
    if (opCode == "ADD") {                    // Checks if ADD
        binaryValue += "00";                        // Default Move Binary Value

        if (noCommaFirstVal == "A") {               // A - 000 Binary Value
            binaryValue += "000";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "B") {        // B - 001 Binary Value
            binaryValue += "001";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";

                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";

                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";

                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";

                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";

                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "C") {        // C - 001 Binary Value
            binaryValue += "010";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";

                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";

                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "D") {        // D - 011 Binary Value
            binaryValue += "011";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "E") {        // E - 100 Binary Value
            binaryValue += "100";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }
        } else {
            cout << "\bInvalid DestReg Value" << endl;
        }
    }

    else if (opCode == "MOVE") {                    // Checks if MOVE
        binaryValue += "01";                        // Default Move Binary Value

        if (noCommaFirstVal == "A") {               // A - 000 Binary Value
            binaryValue += "000";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "B") {        // B - 001 Binary Value
            binaryValue += "001";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "C") {        // C - 001 Binary Value
            binaryValue += "010";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "D") {        // D - 011 Binary Value
            binaryValue += "011";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }

        } else if (noCommaFirstVal == "E") {        // E - 100 Binary Value
            binaryValue += "100";

            if (secondVal.length() == 1) {
                if (secondVal == "A") {             // A - 000 Binary Value
                    binaryValue += "000";
                } else if (secondVal == "B") {      // B - 001 Binary Value
                    binaryValue += "001";
                } else if (secondVal == "C") {      // C - 010 Binary Value
                    binaryValue += "010";
                } else if (secondVal == "D") {      // D - 011 Binary Value
                    binaryValue += "011";
                } else if (secondVal == "E") {      // E - 100 Binary Value
                    binaryValue += "100";
                } else {
                    binaryValue += "101";           // Others - 101 Binary Value
                }
                addMoveFunction(binaryValue, secondValReversed, secondVal);
            }
        } else {
            cout << "\bInvalid DestReg Value" << endl;
        }
    }

    else if (opCode == "LOAD") {                // Checks if LOAD
        binaryValue += "01";                    // Load OpCode Binary Value

        if (noCommaFirstVal == "A") {           // A - 000 Binary Value
            binaryValue += "000";

            if (secondVal.length() < 4) {       // Checks if Addr has 4 characters
                cout << "\bInvalid Addr" << endl;
            } else {
                binaryValue += "110";           // Default Addr Binary Value
                loadFunction(binaryValue, secondValReversed, secondVal, noCommaFirstVal);
                // Calls load function
            }

        } else if (noCommaFirstVal == "B") {    // B - 001 Binary Value
            binaryValue += "001";

            if (secondVal.length() < 4) {       // Checks if Addr has 4 characters
                cout << "\bInvalid Addr" << endl;
            } else {
                binaryValue += "110";           // Default Addr Binary Value
                loadFunction(binaryValue, secondValReversed, secondVal, noCommaFirstVal);
                // Calls load function
            }
        } else if (noCommaFirstVal == "C") {    // C - 010 Binary Value
            binaryValue += "010";

            if (secondVal.length() < 4) {       // Checks if Addr has 4 characters
                cout << "\bInvalid Addr" << endl;
            } else {
                binaryValue += "110";           // Default Addr Binary Value
                loadFunction(binaryValue, secondValReversed, secondVal, noCommaFirstVal);
                // Calls load function
            }
        } else if (noCommaFirstVal == "D") {    // D - 011 Binary Value
            binaryValue += "011";

            if (secondVal.length() < 4) {       // Checks if Addr has 4 characters
                cout << "\bInvalid Addr" << endl;
            } else {
                binaryValue += "110";           // Default Addr Binary Value
                loadFunction(binaryValue, secondValReversed, secondVal, noCommaFirstVal);
                // Calls load function
            }
        } else if (noCommaFirstVal == "E") {    // D - 011 Binary Value
            binaryValue += "100";

            if (secondVal.length() < 4) {       // Checks if Addr has 4 characters
                cout << "\bInvalid Addr" << endl;
            } else {
                binaryValue += "110";           // Default Addr Binary Value
                loadFunction(binaryValue, secondValReversed, secondVal, noCommaFirstVal);
                // Calls load function
            }
        } else {
            cout << "\bInvalid DestReg Value" << endl; // Invalid DestReg Value
        }
    }

    else if (opCode == "STORE") {                           // Checks if STORE
        binaryValue += "01";                    // Store OpCode Binary Value
        if (noCommaFirstVal.length() < 4) { // Checks if Addr has 4 characters
            cout << "\bInvalid Addr value" << endl;
        }
        else {
            binaryValue += "110";               // Default Addr Binary Value

            if (secondVal == "A") {             // A - 000 Binary Value
                binaryValue += "000";
            } else if (secondVal == "B") {      // B - 000 Binary Value
                binaryValue += "001";
            } else if (secondVal == "C") {      // C - 000 Binary Value
                binaryValue += "010";
            } else if (secondVal == "D") {      // D - 000 Binary Value
                binaryValue += "011";
            } else if (secondVal == "E") {      // E - 000 Binary Value
                binaryValue += "100";
            } else {                            // Invalid SrcReg Value
                cout << "\bInvalid SrcReg" << endl;
            }
            storeFunction(binaryValue, noCommaFirstVal, firstValReversed); // Calls Store Function
        }
    }
// OpCode Section B

    else if (opCode == "JMP") {                             // Checks if JMP
        binaryValue += "10000000";                          // JMP Binary Code
        jFunction(binaryValue, firstValReversed, firstVal); // Calls JFunction
    }
    else if (opCode == "JPZ") {                             // Checks if JPZ
        binaryValue += "10000001";                          // JPZ Binary Code
        jFunction(binaryValue, firstValReversed, firstVal); // Calls JFunction
    }
    else if (opCode == "JPP") {                             // Checks if JPP
        binaryValue += "10000010";                          // JPP Binary Code
        jFunction(binaryValue, firstValReversed, firstVal); // Calls JFunction
    }
    else if (opCode == "JPN") {                             // Checks if JPN
        binaryValue += "10000011";                          // JPN Binary Code
        jFunction(binaryValue, firstValReversed, firstVal); // Calls JFunction

    }
    else {                  // Executes if not a valid OpCode has been entered
        cout << "Out Of Scope Operation Code.";
    }
}