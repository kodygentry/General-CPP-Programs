#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


struct Flight{
    string from;
    string to;
    double price;
    int distance;
};

int readFlights(ifstream& in, Flight flight[]){
// read data from .csv
// take in flight[] and file input - return SIZE

    string priceStr, distanceStr; // temporary string variables

    int SIZE = 0; // index
    while(getline(in,flight[SIZE].from,',')){
        getline(in,flight[SIZE].to,',');

        getline(in,priceStr,',');
        flight[SIZE].price = stod(priceStr); // string to double

        getline(in,distanceStr);
        flight[SIZE].distance = stod(distanceStr); // string to double

        SIZE++;
    }

    return SIZE; // return index
}

void printFlights(int SIZE, Flight flight[]){
// take in SIZE and flight[] - print table

    // table header
    cout << left << setw(16) << "From"
         << left << setw(15) << "To"
         << left << setw(6)  << "Price"
         << "Distance" << endl;
    for (int i=0; i<45; i++){
        cout << "-";
    }
    cout << endl;

    // print table
    for(int i=0;i<SIZE;i++){
        cout << left << setw(15) << flight[i].from << " "
             << left << setw(15) << flight[i].to << " "
             << left << setw(4)  << flight[i].price << " "
             << flight[i].distance << endl;
    }
    cout << endl;

}

void printFlightsFrom(int SIZE, Flight flight[]){
// print flights from departure city - take in SIZE and flight[]

    string choice;
    cout << "Please enter the city of departure:\n";
    cin.ignore();
    getline(cin, choice);

    cout << endl;
    for (int i=0; i<SIZE; i++){
        if (choice == flight[i].from){
            cout << flight[i].from << " "
                 << flight[i].to << " "
                 << flight[i].price << " "
                 << flight[i].distance << endl;
        }
    }
    cout << endl;

}

double findHighestDistanceToPriceRatio(int SIZE, Flight flight[]){
// compare distance to price ratio
// take in SIZE and flight[] - return index

    double Ratio[SIZE];

    for (int k=0; k<SIZE; k++){ // constructing ratio array
        Ratio[k] = (flight[k].distance / flight[k].price);
    }

    double high = Ratio[0];
    double index = 0;

    for (int i=1; i<SIZE; i++){ // finding best ratio
        if (Ratio[i] > high){
            high = Ratio[i];
            index = i;
        }
    }

    return index;
}

int main(){

    ifstream in("flights.csv");

    if(!in){
        cout << "File failed to open!";
        return -1;
    }

    Flight flight[100]; // 100 possible flights
    int const SIZE = readFlights(in, flight); // SIZE = index of readFlights()

    bool running = true; // for main do while loop
    int actionChoice = 1; // user menu option

    do{
        cout << "Select the action: \n"
             << "1) Display all flights.\n"
             << "2) Show the flights that depart from a given city.\n"
             << "3) Find a flight with the best distance to price ratio.\n"
             << "4) Exit the program.\n";
        cin  >> actionChoice;

        if(actionChoice==1){
            printFlights(SIZE, flight);
        }

        else if(actionChoice==2){
            printFlightsFrom(SIZE, flight);
        }

        else if(actionChoice==3){

            int index = findHighestDistanceToPriceRatio(SIZE, flight);

            cout << "The best distance to price ratio is "
                 << setprecision(4) << (flight[index].distance / flight[index].price)
                 << " km/$.\n";
            cout << left << setw(15) << flight[index].from << " "
                 << left << setw(15) << flight[index].to << " "
                 << left << setw(4)  << flight[index].price << " "
                 << flight[index].distance << endl << endl;
        }

        else if(actionChoice==4){
            cout << "Exiting program...\n";
            running = false;
        }

        else{
            cout << "**Invalid input, choose action 1, 2, 3 or 4.**\n";
        }

    }while(running);

    in.close();

    return 0;
}
