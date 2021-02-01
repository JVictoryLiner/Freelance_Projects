#include <iostream>
#include <string>
using namespace std;

// Hex to Binary function
string iterate(char digit) {
    string binaryOutput = "";
    switch (digit) {
        case '0':
            binaryOutput += "0000";
            break;
        case '1':
            binaryOutput += "0001";
            break;
        case '2':
            binaryOutput += "0010";
            break;
        case '3':
            binaryOutput += "0011";
            break;
        case '4':
            binaryOutput += "0100";
            break;
        case '5':
            binaryOutput += "0101";
            break;
        case '6':
            binaryOutput += "0110";
            break;
        case '7':
            binaryOutput += "0111";
            break;
        case '8':
            binaryOutput += "1000";
            break;
        case '9':
            binaryOutput += "1001";
            break;
        case 'A':
            binaryOutput += "1010";
            break;
        case 'B':
            binaryOutput += "1011";
            break;
        case 'C':
            binaryOutput += "1100";
            break;
        case 'D':
            binaryOutput += "1101";
            break;
        case 'E':
            binaryOutput += "1110";
            break;
        case 'F':
            binaryOutput += "1111";
            break;
    }
    return binaryOutput;    // Returns the value to be stored in a variable
}

// Binary to OpCode function (If applies)
void opCode(string finalBinary, string input, string firstValue, string reversed) {

    // Check if the input has 6 digits (2 for hex | 4 for address)
    if (input.length() == 6) {
        firstValue = input.substr(2, 7);    // Takes the substring of input
        reversed = string(firstValue.rbegin(), firstValue.rend()); // Reverses string
        swap(reversed[0], reversed[1]); // Swaps FIRST and SECOND char
        swap(reversed[2], reversed[3]); // Swaps THIRD and FOURTH char

        // JFunctions
        if (finalBinary == "10000000") {
            cout << "OpCode : JMP " << reversed;    // Prints if JMP + Reversed Address
        } else if (finalBinary == "10000001") {
            cout << "OpCode : JPZ " << reversed;    // Prints if JPZ + Reversed Address
        } else if (finalBinary == "10000010") {
            cout << "OpCode : JPP " << reversed;    // Prints if JPP + Reversed Address
        } else if (finalBinary == "10000011") {
            cout << "OpCode : JPN " << reversed;    // Prints if JPN + Reversed Address
        }

        // LOAD and STORE
        if(finalBinary.substr(0,2) == "01"){ //First Two Digits Default Value (LOAD and STORE)
            if (finalBinary.substr(5, 8) == "110") { // Last Three Digits Default Value (LOAD)
                if (finalBinary.substr(2, 3) == "000") {    // Checks if A
                    cout << "OpCode : LOAD A, " << reversed;// Prints LOAD + Reversed Address
                } else if (finalBinary.substr(2, 3) == "001") { // Checks if B
                    cout << "OpCode : LOAD B, " << reversed;// Prints LOAD + Reversed Address
                } else if (finalBinary.substr(2, 3) == "010") { // Checks if C
                    cout << "OpCode : LOAD C, " << reversed;// Prints LOAD + Reversed Address
                } else if (finalBinary.substr(2, 3) == "011") { // Checks if D
                    cout << "OpCode : LOAD C, " << reversed;// Prints LOAD + Reversed Address
                } else if (finalBinary.substr(2, 3) == "100") { // Checks if E
                    cout << "OpCode : LOAD C, " << reversed;// Prints LOAD + Reversed Address
                }
            }
            else if (finalBinary.substr(2, 3) == "110") { //Middle Three Digits Default value (STORE)
                if (finalBinary.substr(5, 8) == "000") {        // Checks if A
                    cout << "OpCode : STORE " << reversed << ", A"; // Prints STORE + Reversed Address
                } else if (finalBinary.substr(5, 8) == "001") { // Checks if B
                    cout << "OpCode : STORE " << reversed << ", B"; // Prints STORE + Reversed Address
                } else if (finalBinary.substr(5, 8) == "010") { // Checks if C
                    cout << "OpCode : STORE " << reversed << ", C"; // Prints STORE + Reversed Address
                } else if (finalBinary.substr(5, 8) == "011") { // Checks if D
                    cout << "OpCode : STORE " << reversed << ", D"; // Prints STORE + Reversed Address
                } else if (finalBinary.substr(5, 8) == "100") { // Checks if E
                    cout << "OpCode : STORE " << reversed << ", E"; // Prints STORE + Reversed Address
                }
            }
        }

    } else { // 2 Digit Binary Value (ADD and MOVE) w/o Address


        if (finalBinary.substr(0, 2) == "01") { // MOVE Default Starting First Two Digits
            if (finalBinary.substr(2, 3) == "000") { // A - 000 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : MOVE A, A";                   // Print MOVE A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : MOVE A, B";                   // Print MOVE A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : MOVE A, C";                   // Print MOVE A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : MOVE A, D";                   // Print MOVE A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : MOVE A, E";                   // Print MOVE A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : MOVE A, " << "Custom Value";        // Print MOVE A, Others
                }
            } else if (finalBinary.substr(2, 3) == "001") { // B - 001 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : MOVE B, A";                   // Print MOVE A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : MOVE B, B";                   // Print MOVE A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : MOVE B, C";                   // Print MOVE A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : MOVE B, D";                   // Print MOVE A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : MOVE B, E";                   // Print MOVE A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : MOVE B, " << "Custom Value";        // Print MOVE A, Others
                }
            } else if (finalBinary.substr(2, 3) == "010") { // C - 010 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : MOVE C, A";                   // Print MOVE A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : MOVE C, B";                   // Print MOVE A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : MOVE C, C";                   // Print MOVE A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : MOVE C, D";                   // Print MOVE A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : MOVE C, E";                   // Print MOVE A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : MOVE C, " << "Custom Value";        // Print MOVE A, Others
                }
            } else if (finalBinary.substr(2, 3) == "011") { // D - 011 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : MOVE D, A";                   // Print MOVE A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : MOVE D, B";                   // Print MOVE A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : MOVE D, C";                   // Print MOVE A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : MOVE D, D";                   // Print MOVE A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : MOVE D, E";                   // Print MOVE A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : MOVE D, " << "Custom Value";        // Print MOVE A, Others
                }
            } else if (finalBinary.substr(2, 3) == "100") { // E - 100 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : MOVE E, A";                   // Print MOVE A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : MOVE E, B";                   // Print MOVE A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : MOVE E, C";                   // Print MOVE A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : MOVE E, D";                   // Print MOVE A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : MOVE E, E";                   // Print MOVE A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : MOVE E, " << "Custom Value";       // Print MOVE A, Others
                }
            }
            // ADD Default Starting First Two Digits
        }else if (finalBinary.substr(0, 2) == "00") {
            if (finalBinary.substr(2, 3) == "000") { // A - 000 Binary Value
                if (finalBinary.substr(5, 8) == "000" && finalBinary != "00001000") {    //A - 000 Binary Value
                    cout << "OpCode : ADD A, A";                   // Print ADD A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : ADD A, B";                   // Print ADD A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : ADD A, C";                   // Print ADD A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : ADD A, D";                   // Print ADD A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : ADD A, E";                   // Print ADD A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : ADD E, " << "Custom Value";        // Print ADD A, Others
                }
            } else if (finalBinary.substr(2, 3) == "001") { // B - 001 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : ADD B, A";                   // Print ADD A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : ADD B, B";                   // Print ADD A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : ADD B, C";                   // Print ADD A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : ADD B, D";                   // Print ADD A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : ADD B, E";                   // Print ADD A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : ADD B, " << "Custom Value";        // Print ADD A, Others
                }
            } else if (finalBinary.substr(2, 3) == "010") { // C - 010 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : ADD C, A";                   // Print ADD A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : ADD C, B";                   // Print ADD A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : ADD C, C";                   // Print ADD A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : ADD C, D";                   // Print ADD A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : ADD C, E";                   // Print ADD A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : ADD C, " << "Custom Value";        // Print ADD A, Others
                }
            } else if (finalBinary.substr(2, 3) == "011") { // D - 011 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : ADD D, A";                   // Print ADD A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : ADD D, B";                   // Print ADD A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : ADD D, C";                   // Print ADD A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : ADD D, D";                   // Print ADD A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : ADD D, E";                   // Print ADD A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : ADD D, " << "Custom Value";        // Print ADD A, Others
                }
            } else if (finalBinary.substr(2, 3) == "100") { // E - 100 Binary Value
                if (finalBinary.substr(5, 8) == "000") {    //A - 000 Binary Value
                    cout << "OpCode : ADD E, A";                   // Print ADD A, A
                } else if (finalBinary.substr(5, 8) == "001") { //B - 001 Binary Value
                    cout << "OpCode : ADD E, B";                   // Print ADD A, B
                } else if (finalBinary.substr(5, 8) == "010") { //C - 010 Binary Value
                    cout << "OpCode : ADD E, C";                   // Print ADD A, C
                } else if (finalBinary.substr(5, 8) == "011") { //D - 011 Binary Value
                    cout << "OpCode : ADD E, D";                   // Print ADD A, D
                } else if (finalBinary.substr(5, 8) == "100") { //E - 100 Binary Value
                    cout << "OpCode : ADD E, E";                   // Print ADD A, E
                } else if (finalBinary.substr(5, 8) == "101"){ //Others - 101 Binary Value
                    cout << "OpCode : ADD E, " << "Custom Value";        // Print ADD A, Others
                }
            }
        }
    }
}

int main() {

    // Initialize Variables
    string input;
    string firstIteration, secondIteration;
    char a, b;
    string firstValue;
    string reversed;
    string finalBinary;

    //Print program guide
    cout << "Hexadecimal to Binary Converter" << endl;
    cout << endl;
    cout << "Input hexadecimal (Either 2 digits or 6 digits)" << endl;
    cout << "(2 Digits - e.g. 01 | 0F) | (6 Digits - e.g. FF10CD | 74FFEE)" << endl;
    cout << "Note : Some 2 digit hex can show you the OpCode along side the Addr" << endl;
    cout << endl;

    // Input hexadecimal
    cout << "Enter a hexadecimal : ";
    cin >> input;

    // Verifies the length of a valid hexadecimal
    if (input.length() == 2 || input.length() == 6) { // Valid hex
        a = input[0];   // Gets the 1st char in the input
        b = input[1];   // Gets the 2nd char in the input
        firstIteration = iterate(a);    // Calls iterate function
        secondIteration = iterate(b);   // Calls iterate function
    } else {
        cout << "Invalid Hexadecimal Code" << endl; // Invalid hex
    }

    // Merges the two iteration
    finalBinary = firstIteration + secondIteration;
    cout << endl;

    //Prints out converted hex to binary
    cout << "\bBinary : " << finalBinary << endl;

    //Calls and prints out the OpCode if applies
    opCode(finalBinary, input, firstValue, reversed);


}
