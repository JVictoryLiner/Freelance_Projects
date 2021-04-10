#include <iostream>
#include <string>
using namespace std;

bool didGuitar = false;
bool didBook = false;
bool didAccess = false;
const int quota = 10;
const int accessoryMax = 20;
const int access = 9;
int customerData = 0;
int bookData = 0;
int itemData = 0;
int currQuan = 0;
string gChoice, bChoice, aChoice;
// Customers Arrays
string customerCollection[quota];
string addressCollection[quota];
string phoneCollection[quota];
string noteCollection[quota];
// Guitars Arrays
string typeData[quota];
string makeData[quota];
string modelData[quota];
string stringsData[quota];
string guitarNotesData[quota];
double guitarPrice = 0;
// Bookings Arrays
string bookInstrument[quota];
string bookCustomer[quota];
string bookLesson[quota];
string bookDate[quota];
string bookTime[quota];
string bookBlock[quota];
double bookPrice[quota];
// Accessories Arrays
string allItems[quota][accessoryMax];
double allPrices[quota][accessoryMax];
double accFinal = 0;

class Accessories{
private:
    string musicAccs[access] = {"Picks (Pack Of 5)", "Guitar Strings",
                                "Guitar Case", "Guitar Capo",
                                "Ukelele String", "Ukelele Case",
                                "Ukelele Capo", "Drum Sticks",
                                "Piano Stand"};
    double accsPrices[access] = {5.15, 7.5, 30.00, 10.25, 9.15,
                                 25.00, 15.50, 12.77, 61.50};
    int accsQuantity[access] = {15, 20, 5, 10, 20, 5, 7, 12, 4};
public:

    void printAccessory() {
        for(int i = 0; i < access; i++){
            cout << "           " << (i + 1) << ". " << musicAccs[i] << endl;
        }
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    // Accessory Data Input
    void addAccessoryData() {
        cout << endl;
        cout << "~~~~~Elevazo's Accessories Inventory~~~~~" << endl << endl;
        printAccessory();
        int j;
        cout << "    Choose An Accessory Number To Buy " << endl;
        while (j != 10) {
            cout << "    Choose Numbers 1 - 9 | 10 - Quit:   ";
            cin >> j;
            cout << endl;
            if (j >= 1 && j <= 9) {
                printDetailsForSelling(j);
            }else {
                continue;
            }
        }
    }
    void printDetailsForSelling(int index) {
        if((accsQuantity[index - 1] -1 ) > -1) {
            cout << "Item Bought: " << musicAccs[index - 1] << endl;
            allItems[customerData][itemData] += musicAccs[index - 1];
            cout << "Item Price: " << accsPrices[index - 1] << endl;
            allPrices[customerData][itemData] += accsPrices[index - 1];
            currQuan = accsQuantity[index - 1] - 1;
            cout << "Item Quantity: " << currQuan << endl;
            accsQuantity[index - 1] = currQuan;
            itemData++;
        }else {
            cout << "Item: " << musicAccs[index - 1] << " insufficient stocks." << endl;
        }
        cout << endl;
    }
    // Accessory Data Input

    // Accessory Display
    void chooseAccessory() {
        cout << "~~~~~Elevazo's Accessories Inventory~~~~~" << endl << endl;
        printAccessory();
        int j;
        cout << "  Choose Accs. # To See Price and Stocks" << endl;
        while (j != 10) {
            cout << "    Choose Numbers 1 - 9 | 10 - Quit:   ";
            cin >> j;
            cout << endl;
            if (j >= 1 && j <= 9) {
                printDetailsForDisplay(j);
            }else {
                continue;
            }
        }
    }
    void printDetailsForDisplay(int index) {
        cout << "Item: " << musicAccs[index - 1] << endl;
        cout << "Price: $" << accsPrices[index - 1] << endl;
        cout << "Quantity: " << accsQuantity[index - 1] << " pcs." << endl;
        cout << endl;
    }
    // Accessory Display
};

class Guitars{
private:
    string guitarType;
    string guitarMake;
    string guitarModel;
    string guitarNotes;
    string guitarStrings;
public:

    // Guitar Form Input
    void addGuitarData() {
        cout << "~~~~~~~~~~~~Guitar Order Form~~~~~~~~~~~~" << endl;
        cout << endl;
        guitarType = inputType();
        guitarMake = inputMake();
        guitarModel = inputModel();
        guitarStrings = inputStrings();
        guitarNotes = inputGuitarNotes();
        if(guitarType == "Electric" || guitarType == "electric" || guitarType == "ELECTRIC") {
            guitarPrice = 60;
        }else if(guitarType == "Acoustic" || guitarType == "acoustic" || guitarType == "ACOUSTIC") {
            guitarPrice = 50;
        }else if(guitarType == "Bass" || guitarType == "bass" || guitarType == "BASS") {
            guitarPrice = 35;
        }else {
            guitarPrice = 40;
        }
        cout << endl;
        typeData[customerData] = guitarType;
        makeData[customerData] = guitarMake;
        modelData[customerData] = guitarModel;
        stringsData[customerData] = guitarStrings;
        guitarNotesData[customerData] = guitarNotes;
    }
    string inputType() {
        cout << " Guitar Type:";
        cin.ignore();
        getline(cin, guitarType);
        return guitarType;
    }
    string inputMake() {
        cout << " Guitar Make:";
        getline(cin, guitarMake);
        return guitarMake;
    }
    string inputModel() {
        cout << " Guitar Model:";
        getline(cin, guitarModel);
        return guitarModel;
    }
    string inputStrings() {
        cout << " Number Of Strings:";
        getline(cin, guitarStrings);
        return guitarStrings;
    }
    string inputGuitarNotes() {
        cout << " Guitar Notes: ";
        getline(cin, guitarNotes);
        return guitarNotes;
    }
    // Guitar Form Input
};

class Bookings{
private:
    string bookingInstrument;
    string bookingCustomer;
    string bookingLesson;
    string bookingDate;
    string bookingTime;
    string bookingBlock;
    double bookingPrice;
public:

    static void printLessons() {
        cout << "~~~~~~~~~~~~~Lesson Bookings~~~~~~~~~~~~~" << endl << endl;
        for(int i = 0; i < bookData; i++) {
            cout << "LESSON BOOKING #" << (i + 1) << endl << endl;
            cout << "Customer: " << bookCustomer[i] << endl;
            cout << "Lesson: " << bookLesson[i] << "\tInstrument: " << bookInstrument[i] << endl;
            cout << "Date: " << bookDate[i] << "\tTime: " << bookTime[i] << endl;
            cout << "Block: " << bookBlock[i] << endl;
            cout << "Booking Price: $" << bookPrice[i];
            cout << endl << endl;
        }
    }

    // Bookings Data Input
    void addBookingData() {
        cout << "~~~~~~~~Lesson Booking Order Form~~~~~~~~" << endl;
        cout << endl;
        bookingInstrument = inputInstrument();
        bookingCustomer = inputCustomer();
        bookingLesson = inputLesson();
        bookingDate = inputDate();
        bookingTime = inputTime();
        bookingBlock = inputBlock();
        bookingPrice = inputPrice();
        cout << endl;
        bookInstrument[customerData] = bookingInstrument;
        bookCustomer[customerData] = bookingCustomer;
        bookLesson[customerData] = bookingLesson;
        bookDate[customerData] = bookingDate;
        bookTime[customerData] = bookingTime;
        bookBlock[customerData] = bookingBlock;
        bookPrice[customerData] = bookingPrice;
        bookData++;
    }
    string inputInstrument() {
        cout << " Instrument: ";
        cin.ignore();
        getline(cin, bookingInstrument);
        return bookingInstrument;
    }
    string inputCustomer() {
        cout << "Customer: ";
        getline(cin, bookingCustomer);
        return bookingCustomer;
    }
    string inputLesson() {
        cout << "Lesson: ";
        getline(cin, bookingLesson);
        return bookingLesson;
    }
    string inputDate() {
        cout << "Date: ";
        getline(cin, bookingDate);
        return bookingDate;
    }
    string inputTime() {
        cout << "Time: ";
        getline(cin, bookingTime);
        return bookingTime;
    }
    string inputBlock() {
        cout << "Block: ";
        getline(cin, bookingBlock);
        return bookingBlock;
    }
    int inputPrice() {
        cout << "Price: ";
        cin >> bookingPrice;
        return bookingPrice;
    }
    // Bookings Data Input
};

class Customers{
private:
    string customerName;
    string customerAddress;
    string customerNumber;
    string customerNotes;
public:
    Guitars callGuitars;
    Bookings callBookings;
    Accessories callAccessories;

    // Print Invoice Methods
    static void printInvoice() {
        cout << "~~~~~~~~~~~~~~FINAL INVOICE~~~~~~~~~~~~~~" << endl << endl;
        cout << "CUSTOMER DETAILS" << endl << endl;
        cout << "Full Name: " << customerCollection[customerData] << endl;
        cout << "Full Address: " << addressCollection[customerData] << endl;
        cout << "Contact Number: " << phoneCollection[customerData] << endl;
        cout << "Customer Notes: " << noteCollection[customerData] << endl;
        cout << endl;
        if(didGuitar){
            guitarInvoice();
        }
        if(didBook){
            bookingInvoice();
        }
        if(didAccess){
            accessoryInvoice();
        }
        cout << "FINAL PRICE: $" << guitarPrice + accFinal + bookPrice[customerData] << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }

    static void guitarInvoice() {
        cout << "GUITAR DETAILS" << endl << endl;
        cout << "Type: " << typeData[customerData] << "\tMake: " << makeData[customerData] << endl;
        cout << "Model: " << modelData[customerData] << "\tString #: " << stringsData[customerData] << endl;
        cout << "Guitar Price: $" << guitarPrice << endl;
        cout << "Guitar Notes: " << guitarNotesData[customerData];
        cout << endl << endl;
    }
    static void bookingInvoice() {
        cout << "BOOKING DETAILS" << endl << endl;
        cout << "Customer: " << bookCustomer[customerData] << endl;
        cout << "Lesson: " << bookLesson[customerData] << "\tInstrument: " << bookInstrument[customerData] << endl;
        cout << "Date: " << bookDate[customerData] << "\tTime: " << bookTime[customerData] << endl;
        cout << "Block: " << bookBlock[customerData] << endl;
        cout << "Booking Price: $" << bookPrice[customerData];
        cout << endl << endl;
    }
    static void accessoryInvoice() {
        cout << "ACCESSORIES DETAILS" << endl << endl;
        cout << "List of All Items:" << endl;
        for(int i = customerData; i < customerData + 1; i++) {
            for(int j = 0; j < itemData; j++) {
                cout << allItems[i][j] << " | ";
                if(j != 0 && j % 2 == 0) {
                    cout << endl;
                }
            }
        }
        cout << endl;
        cout << "Total Quantity: " << itemData << endl;
        for(int i = customerData; i < customerData + 1; i++) {
            for(int j = 0; j < itemData; j++) {
                accFinal += allPrices[i][j];
            }
        }
        cout << "Accessories Price: $" << accFinal << endl;
        cout << endl;
    }
    // Print Invoice Methods

    // Customer Data Input
    void addCustomerData() {
        cout << " ~~~~~~~~~~~Customer Order Form~~~~~~~~~~~" << endl;
        cout << endl;
        customerName = inputName();
        customerAddress = inputAddress();
        customerNumber = inputNumber();
        customerNotes = inputNotes();
        cout << endl;
        customerCollection[customerData] = customerName;
        addressCollection[customerData] = customerAddress;
        phoneCollection[customerData] = customerNumber;
        noteCollection[customerData] = customerNotes;
    }
    string inputName() {
        cout << " Customer Name:";
        cin.ignore();
        getline(cin, customerName);
        return customerName;
    }
    string inputAddress() {
        cout << " Customer Address:";
        getline(cin, customerAddress);
        return customerAddress;
    }
    string inputNumber() {
        cout << " Customer Contact#:";
        getline(cin, customerNumber);
        return customerNumber;
    }
    string inputNotes() {
        cout << " Notes:";
        getline(cin, customerNotes);
        return customerNotes;
    }
    // Customer Data Input

    // Call Purchase Methods
    void purchaseGuitar() {
        callGuitars.addGuitarData();
    }
    void purchaseBooking() {
        callBookings.addBookingData();
    }
    void purchaseAccessory() {
        callAccessories.addAccessoryData();
    }
    // Call Purchase Methods
};

class MainMenu{
private:
    Customers callCustomers;
    Accessories callAccessories;
    Bookings callBookings;
    bool carryOutMenu = true;

    void createOrder() {
        callCustomers.addCustomerData();

        while(gChoice != "No" || gChoice != "no" || gChoice != "NO") {
            cout << " Purchase a guitar? (Yes / No):";
            cin >> gChoice;
            if(gChoice == "Yes" || gChoice == "yes" || gChoice == "YES") {
                callCustomers.purchaseGuitar();
                didGuitar = true;
                break;
            }else if(gChoice == "No" || gChoice == "no" || gChoice == "NO") {
                cout << endl;
                break;
            }else {
                cout << " Input (Yes / No) Only" << endl;
            }
        }
        while(bChoice != "No" || bChoice != "no" || bChoice != "NO") {
            cout << " Purchase a booking? (Yes / No):";
            cin >> bChoice;
            if(bChoice == "Yes" || bChoice == "yes" || bChoice == "YES") {
                callCustomers.purchaseBooking();
                didBook = true;
                break;
            }else if(bChoice == "No" || bChoice == "no" || bChoice == "NO"){
                cout << endl;
                break;
            }else {
                cout << " Input (Yes / No) Only" << endl;
            }
        }
        while(aChoice != "No" || aChoice != "no" || aChoice != "NO") {
            cout << " Purchase an accessory? (Yes / No):";
            cin >> aChoice;
            if(aChoice == "Yes" || aChoice == "yes" || aChoice == "YES") {
                callCustomers.purchaseAccessory();
                didAccess = true;
                break;
            }else if(aChoice == "No" || aChoice == "no" || aChoice == "NO") {
                cout << endl;
                break;
            }else {
                cout << " Input (Yes / No) Only" << endl;
            }
        }
        cout << endl;
        callCustomers.printInvoice();
        customerData++;
    }
    void printBookings() {
        callBookings.printLessons();
    }
    void printAccessories() {
        callAccessories.chooseAccessory();
    }

public:

    void printMenu (){
        int numChoice;
        while (carryOutMenu) {
            cout << "~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~" << endl;
            cout << "|  Elevazo's Lumanog (Guitar and Acs.)  |" << endl;
            cout << "|                                       |" << endl;
            cout << "| 1.Create An Order (Purchase/Booking)  |" << endl;
            cout << "| 2.Display List Of Bookings            |" << endl;
            cout << "| 3.Search For An Accessory             |" << endl;
            cout << "|                                       |" << endl;
            cout << "~~~~~~~~~~~~~~~END OF MENU~~~~~~~~~~~~~~~" << endl;
            cout << "\tChoose A Menu (1/2/3) :";
            cin >> numChoice;
            cout << endl;
            switch (numChoice) {
                case 1:
                    createOrder();
                    break;
                case 2:
                    printBookings();
                    break;
                case 3:
                    printAccessories();
                    break;
                default:
                    printMenu();
            }
        }
    }
};

int main() {
    MainMenu callMenu;
    callMenu.printMenu();
}
