#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

const int patientLimit = 5;
int storedData = 0;
string nameCollection[patientLimit];
string emailCollection[patientLimit];
string numberCollection[patientLimit];
double bmiCollection[patientLimit];

class BMICalculator {
private:

    double BMI = 0;
    double height = 0;
    double weight = 0;

public:

    void inputBMIData() {
        cout << "\tEnter height in (meters): ";
        cin >> height;

        cout << "\tEnter your weight in (kilograms): ";
        cin >> weight;
        cout << endl;
    }

    void editBMIData() {
        cout << "\tEnter height in (meters): ";
        cin >> height;

        cout << "\tEnter your weight in (kilograms): ";
        cin >> weight;
        cout << endl;
    }

    double calculateBMI() {
        BMI = weight / (height * height);
        return BMI;
    }

    void printBMI(double BMI) {
        BMI = calculateBMI();
        if (BMI > 0 && BMI < 18.5) {
            cout << "----------Message: You are Underweight----------" << endl;
            cout << endl;
        }
        else if (BMI >= 18.5 && BMI <= 24.9) {
            cout << "------Message: You are at in Normal Range!------" << endl;
            cout << endl;
        }
        else if (BMI >= 25 && BMI <= 29.9) {
            cout << "----------Message: You are Overweight!----------" << endl;
            cout << endl;
        }
        else if (BMI > 30) {
            cout << "-------------Message: You are Obese-------------" << endl;
            cout << endl;
        }
        else {
            cout << "-------------Message: No Data Input-------------" << endl;
            cout << endl;
        }
    }

    void printBMIMessage2(double BMI) {
        BMI = calculateBMI();
        if (BMI > 0 && BMI < 18.5) {
            cout << "Category: Underweight" << endl;
            cout << endl;
        }
        else if (BMI >= 18.5 && BMI <= 24.9) {
            cout << "Category: Normal" << endl;
            cout << endl;
        }
        else if (BMI >= 25 && BMI <= 29.9) {
            cout << "Category: Overweight" << endl;
            cout << endl;
        }
        else if (BMI > 30) {
            cout << "Category: You are Obese" << endl;
            cout << endl;
        }
        else {
            cout << "Category: No Data Input" << endl;
            cout << endl;
        }
    }
};

class PatientMenu {
private:
    string patientName;
    string patientEmail;
    string patientPhoneNum;
    double patientBMI;
    double temp;
public:
    BMICalculator callCalculator;
    // START MENU 1
    void addPatientData() {
        cout << "-------------Add New Patient Data---------------" << endl;
        cout << endl;
        patientName = inputName();
        patientEmail = inputEmail();
        patientPhoneNum = inputNumber();
        cout << endl;
        nameCollection[storedData] = patientName;
        emailCollection[storedData] = patientEmail;
        numberCollection[storedData] = patientPhoneNum;
        cout << "------New Patients Data Successfully Added------" << endl;
        cout << endl;
        storedData++;
    }
    string inputName() {
        cout << "  Type in Patient's Name:";
        cin.ignore();
        getline(cin, patientName);
        return patientName;
    }
    string inputEmail() {
        cout << "  Type in Patient's Email:";
        cin >> patientEmail;
        return patientEmail;
    }
    string inputNumber() {
        cout << "  Type in Patient's Number:";
        cin >> patientPhoneNum;
        return patientPhoneNum;
    }
    // END MENU 1

    // START MENU 2
    void addBMI(int patientNumber) {
        cout << "---------Add BMI Record for Patient #" << (patientNumber + 1) << "-----------" << endl;
        cout << endl;
        callCalculator.inputBMIData();
        patientBMI = callCalculator.calculateBMI();
        bmiCollection[patientNumber] = patientBMI;
        callCalculator.printBMI(patientBMI);
    }
    // END MENU 2

    // START MENU 3
    void editPatientData(int patientNumber) {
        cout << "----------Edit Patient #" << (patientNumber + 1) << " Details ------------" << endl;
        cout << endl;
        patientName = editName();
        patientEmail = editEmail();
        patientPhoneNum = editNumber();
        patientBMI = editBMI(patientNumber);
        nameCollection[patientNumber] = patientName;
        emailCollection[patientNumber] = patientEmail;
        numberCollection[patientNumber] = patientPhoneNum;
        bmiCollection[patientNumber] = patientBMI;
        cout << "------New Patients Data Successfully Edited-----" << endl;
        cout << endl;
    }
    string editName() {
        cout << "  Type in New Patient's Name:";
        cin.ignore();
        getline(cin, patientName);
        return patientName;
    }
    string editEmail() {
        cout << "  Type in New Patient's Email:";
        cin >> patientEmail;
        return patientEmail;
    }
    string editNumber() {
        cout << "  Type in New Patient's Number:";
        cin >> patientPhoneNum;
        return patientPhoneNum;
    }
    double editBMI(int patientNumber) {
        cout << "  Input New Patient's BMI:" << endl;
        callCalculator.editBMIData();
        patientBMI = callCalculator.calculateBMI();
        bmiCollection[patientNumber] = patientBMI;
        return patientBMI;
    }
    // END MENU 3

    // START MENU 4
    void displayAll(int patientNumber) {
        cout << "Patient #" << (patientNumber + 1) << " Full Details" << endl;
        cout << "Name of Patient : " << nameCollection[patientNumber] << endl;
        cout << "Email Address : " << emailCollection[patientNumber] << endl;
        cout << "Phone Number : " << numberCollection[patientNumber] << endl;
        cout << "BMI Result : " << bmiCollection[patientNumber] << endl;
        temp = bmiCollection[patientNumber];
        callCalculator.printBMIMessage2(temp);
    }

    void outputDetails() {
        for (int i = 0; i < patientLimit; i++) {
            cout << "Patient #" << (i + 1) << " | Name : " << nameCollection[i] << " | Email : " << emailCollection[i] << endl;
        }
    }
    // Individual Printing || Change in // MENU 4 showPatientDetails()
    void printNames() {
        for (int i = 0; i < patientLimit; i++) {
            cout << "\tPatient #" << (i + 1) << " | " << nameCollection[i] << endl;
        }
    }
    void printEmails() {
        for (int i = 0; i < patientLimit; i++) {
            cout << "\tPatient #" << (i + 1) << " | " << emailCollection[i] << endl;
        }
    }
    void printNumbers() {
        for (int i = 0; i < patientLimit; i++) {
            cout << "\tPatient #" << (i + 1) << " | " << numberCollection[i] << endl;
        }
    }
    void printBMI() {
        for (int i = 0; i < patientLimit; i++) {
            cout << "\tPatient #" << (i + 1) << " | " << bmiCollection[i] << endl;
        }
    }
    // END MENU 4

};

class MainMenu {
private:
    PatientMenu callPatientMenu;
    bool carryOutMenu = true;
    int patientNumber;

    // START MENU 1
    void addPatient() {
        if (storedData >= 5) {
            cout << "\t Information Reached Its Limit!" << endl;
            cout << endl;
        }
        else {
            callPatientMenu.addPatientData();
        }
    }
    // END MENU 1

    // START MENU 2
    void addNewBMI() {
        cout << "--------------Add New BMI Record----------------" << endl;
        cout << endl;
        callPatientMenu.printNames();
        cout << endl;
        cout << "         Choose Patient Number (1 - 5):";
        cin >> patientNumber;
        cout << endl;
        if (patientNumber >= 0 && patientNumber <= 5) {
            callPatientMenu.addBMI(patientNumber - 1);
        }
        else {
            cout << "            !Invalid Patient Number!            " << endl;
            cout << endl;
        }
    }
    // END MENU 2

    // START MENU 3
    void editPatient() {
        cout << endl;
        cout << "---------------Edit Patient Data---------------" << endl;
        cout << endl;
        callPatientMenu.outputDetails();
        cout << endl;
        cout << "         Choose Patient Number (1 - 5):";
        cin >> patientNumber;
        cout << endl;
        if (patientNumber >= 0 && patientNumber <= 5) {
            callPatientMenu.editPatientData(patientNumber - 1);
        }
        else {
            cout << "            !Invalid Patient Number!            " << endl;
            cout << endl;
        }
    }

    // END MENU 3

    // START MENU 4
    void showPatientDetails() {
        cout << "-----------Show Patient's Information-----------" << endl;
        cout << endl;
        callPatientMenu.outputDetails();
        cout << endl;
        cout << "         Choose Patient Number (1 - 5):";
        cin >> patientNumber;
        cout << endl;
        if (patientNumber >= 0 && patientNumber <= 5) {
            callPatientMenu.displayAll(patientNumber - 1);
        }
        else {
            cout << "            !Invalid Patient Number!            " << endl;
            cout << endl;
        }
    }
    // END MENU 4

    // START MENU 5
    void writeFile() {
        ofstream displayFile;
        displayFile.open("bmipatientdata.txt");
        for (int i = 0; i < patientLimit; i++) {
            displayFile << "Patient #" << (i + 1) << " Full Details" << endl;
            displayFile << "Name :" << nameCollection[i] << endl;
            displayFile << "Email : " << emailCollection[i] << endl;
            displayFile << "Number : " << numberCollection[i] << endl;
            displayFile << "BMI : " << bmiCollection[i] << endl;
            if (bmiCollection[i] > 0 && bmiCollection[i] < 18.5) {
                displayFile << "Category : Underweight" << endl;
            }
            else if (bmiCollection[i] >= 18.5 && bmiCollection[i] <= 24.9) {
                displayFile << "Category : Normal" << endl;
            }
            else if (bmiCollection[i] >= 25 && bmiCollection[i] <= 29.9) {
                displayFile << "Category : Overweight" << endl;
            }
            else if (bmiCollection[i] >= 30) {
                displayFile << "Category : Obese" << endl;
            }
            else {
                displayFile << "Category : No Data Available" << endl;
            }
            displayFile << endl;
        }
        displayFile.close();
        cout << "----All Patients Details Successfully Added!----" << endl;
        cout << endl;
    }
    // END MENU 5

    // START MENU 6
    void loadFile() {
        string line;
        ifstream printFile;
        printFile.open("bmipatientdata.txt");
        if (printFile.is_open()) {
            while (getline(printFile, line)) {
                cout << line << endl;
            }
            printFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }

    }
    // END MENU 6

    // START MENU 7
    void saveAndQuit() {
        writeFile();
        carryOutMenu = false;
        cout << "Thanks for your time" << endl;
    }
    // END MENU 7

public:
    void printMenu() {
        int numChoice;
        while (carryOutMenu) {
            cout << "/----------------------------------------------\\" << endl;
            cout << "|BMI CALCULATOR, PLEASE CHOOSE AN OPTION BELOW:|" << endl;
            cout << "|                                              |" << endl;
            cout << "|      1. ADD new patient                      |" << endl;
            cout << "|      2. ADD / CALCULATE BMI for patient      |" << endl;
            cout << "|      3. EDIT Patient's information           |" << endl;
            cout << "|      4. SHOW Patient's details               |" << endl;
            cout << "|                                              |" << endl;
            cout << "|--------------SAVE | LOAD | EXIT--------------|" << endl;
            cout << "|                                              |" << endl;
            cout << "|      5. SAVE patient's details to a file     |" << endl;
            cout << "|      6. LOAD the patient's details           |" << endl;
            cout << "|      7. EXIT program (save and quit)         |" << endl;
            cout << "|                                              |" << endl;
            cout << "\\----------------------------------------------/" << endl;
            cout << "\t  Input your Option (1 - 7):";
            cin >> numChoice;
            cout << endl;
            switch (numChoice) {
            case 1:
                addPatient();
                break;
            case 2:
                addNewBMI();
                break;
            case 3:
                editPatient();
                break;
            case 4:
                showPatientDetails();
                break;
            case 5:
                writeFile();
                break;
            case 6:
                loadFile();
                break;
            case 7:
                saveAndQuit();
                break;
            default:
                printMenu();
            }
            ;
        }
    }
};

int main() {
    MainMenu callMenu;
    callMenu.printMenu();
}

