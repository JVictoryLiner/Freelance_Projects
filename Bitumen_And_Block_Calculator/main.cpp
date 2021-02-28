#include<iostream>
#include<iomanip>
using namespace std;

char menu() {
    char choice;
    cout << "Civil Engineering Calculator" << endl;
    cout << "[a] Bitumen Density Calculator" << endl;
    cout << "[b] Concrete Block Calculator" << endl;
    cout << "Enter option:";
    cin >> choice;
    cout << endl;
    choice = tolower(choice);
    return choice;
}
void bitumenGetData(int &w1, int &w2, int &w3, int &w4, char &unit) {
    cout << "[a] Bitumen Density Calculator" << endl;
    cout << endl;
    cout << "ENTER Unit of Weight" << endl;
    cout << "[a] mg" << endl;
    cout << "[b] g" << endl;
    cout << "[c] kg" << endl;
    cout << "[d] oz" << endl;
    cout << "[e] lb" << endl;
    cout << "[f] dr" << endl;
    cout << "[g] gr" << endl;
    cout << "Enter option:";
    cin >> unit;
    unit = tolower(unit);
    cout << endl;
    cout << "ENTER Weight of Empty and Dry Pycnometer, w1:";
    cin >> w1;
    cout << "ENTER Weight of Pycnometer with Bitumen, w2:";
    cin >> w2;
    cout << "ENTER Weight of Pycnometer with Full of Water at Temperature 25 degree Celcius, w3:";
    cin >> w3;
    cout << "ENTER Weight of Pycnometer with Distilled Water and Bitumen, w4:";
    cin >> w4;
    cout << endl;
}
void bitumenCalc(int w1, int w2, int w3, int w4, double &density) {
    double dividend;
    dividend = (w3 - w1) - (w4 - w2);
    density = (w2 - w1) / dividend;
}
void bitumenPrint(int w1, int w2, int w3, int w4, double density, char unit) {
    string unitMeasure;
    if (unit == 'b'){ // Grams = SI UNIT
        density = density;
        unitMeasure = "g";
    } else if (unit == 'a'){
        unitMeasure = "mg";
    } else if (unit == 'c'){
        unitMeasure = "kg";
    } else if (unit == 'd'){
        unitMeasure = "oz";
    } else if (unit == 'e'){
        unitMeasure = "lb";
    } else if (unit == 'f'){
        unitMeasure = "dr";
    } else if (unit == 'g'){
        unitMeasure = "gr";
    }
    cout << "Weight of Empty and Dry Pycnometer, w1: " << w1 << " " << unitMeasure << endl;
    cout << "Weight of Pycnometer with Bitumen, w2: " << w2 << " " << unitMeasure << endl;
    cout << "Weight of Pycnometer with Full of Water at Temperature 25 degree Celcius, w3: " << w3 << " " << unitMeasure << endl;
    cout << "Weight of Pycnometer with Distilled Water and Bitumen, w4: " << w4 << " " << unitMeasure << endl;
    cout << endl;
    cout << "Density of Bitumen / Asphalt = " << setprecision(4) << density << endl;
}
void blockGetData(int &length, int &width, char &blockSize, char &unit) {
    cout << "[b] Concrete Block Calculator" << endl;
    cout << endl;
    cout << "ENTER Block Size" << endl;
    cout << "[a] 8  inch x 8 inch" << endl;
    cout << "[b] 12 inch x 8 inch" << endl;
    cout << "[c] 16 inch x 8 inch" << endl;
    cout << "[d] 8  inch x 4 inch" << endl;
    cout << "[e] 12 inch x 4 inch" << endl;
    cout << "[f] 16 inch x 4 inch" << endl;
    cout << "Enter option:";
    cin >> blockSize;
    blockSize = tolower(blockSize);
    cout << endl;
    cout << "ENTER Unit of length and width" << endl;
    cout << "[a] mm" << endl;
    cout << "[b] cm" << endl;
    cout << "[c] dm" << endl;
    cout << "[d] m" << endl;
    cout << "Enter option:";
    cin >> unit;
    unit = tolower(unit);
    cout << endl;
    cout << "Enter project length:";
    cin >> length;

    cout << "Enter project width:";
    cin >> width;
    cout << endl;
}
void blockCalc(int length, int width, char blockSize, char unit, double &noOfBlocks) {
    int blockOne, blockTwo;
    float lengthFinal, widthFinal;
    if (blockSize == 'a') {
        blockOne = 8;
        blockTwo = 8;
    } else if (blockSize == 'b') {
        blockOne = 12;
        blockTwo = 8;
    } else if (blockSize == 'c') {
        blockOne = 16;
        blockTwo = 8;
    } else if (blockSize == 'd') {
        blockOne = 8;
        blockTwo = 4;
    } else if (blockSize == 'e') {
        blockOne = 12;
        blockTwo = 4;
    } else if (blockSize == 'f') {
        blockOne = 16;
        blockTwo = 4;
    }
    if (unit == 'd') {
        lengthFinal = (float) length * 39.3701;
        widthFinal = (float) width * 39.3701;
    } else if (unit == 'a') {
        lengthFinal = (float) length * 0.0393701;
        widthFinal = (float) width * 0.0393701;
    } else if (unit == 'b') {
        lengthFinal = (float) length * 0.393701;
        widthFinal = (float) width * 0.393701;
    } else if (unit == 'c') {
        lengthFinal = (float) length * 3.93701;
        widthFinal = (float) width * 3.93701;
    }
    noOfBlocks = (lengthFinal * widthFinal) / (blockOne * blockTwo);
}
void blockPrint(int length, int width, char blockSize, char unit, double noOfBlocks) {
    string blockName, unitName;
    if (unit == 'd') {
        unitName = "m";
    } else if (unit == 'a') {
        unitName = "mm";
    } else if (unit == 'b') {
        unitName = "cm";
    } else if (unit == 'c') {
        unitName = "dm";
    }
    cout << "Project length:" << length << " " << unitName << endl;
    cout << "Project width:" << width << " " << unitName << endl;
    if (blockSize == 'a') {
        blockName = "[a] 8  inch x 8 inch";
    } else if (blockSize == 'b') {
        blockName = "[b] 12 inch x 8 inch";
    } else if (blockSize == 'c') {
        blockName = "[c] 16 inch x 8 inch";
    } else if (blockSize == 'd') {
        blockName = "[d] 8  inch x 4 inch";
    } else if (blockSize == 'e') {
        blockName = "[e] 12 inch x 4 inch";
    } else if (blockSize == 'f') {
        blockName = "[f] 16 inch x 4 inch";
    }
    cout << blockName << endl;
    cout << "Number of blocks " << noOfBlocks << " blocks" << endl;
}

int main() {
    char option, unit, blockSize;
    int w1, w2, w3, w4, length, width;
    double density, noOfBlocks;
    cout << fixed << setprecision(4);
    option = menu();
    if(option == 'a')
    {
        bitumenGetData(w1, w2, w3, w4, unit);
        bitumenCalc(w1, w2, w3, w4, density);
        bitumenPrint(w1, w2, w3, w4, density, unit);
    }
    if(option == 'b')
    {
        blockGetData(length, width, blockSize, unit);
        blockCalc(length, width, blockSize, unit, noOfBlocks);
        blockPrint(length, width, blockSize, unit, noOfBlocks);
    }
    cout << "\nEND OF PROGRAM!!!" << endl << endl;
    system("pause");
    return 0;
}


