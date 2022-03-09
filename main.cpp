#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "cdCollection.h"

using namespace std;

int main() {
  int userChoice;
  string userFileName;
  double userPrice;
  int userYear;
  char yesNo;

  cdCollection test;

  for(;;){

  cout << "Welcome to the CD list!  You may select one of the following options: "<< endl << endl;
  cout << "1 Read a CD collection from a file..." << endl;
  cout<< "2 Write the CD list to a file..." << endl;
  cout << "3 Print the CD collection from the list..." << endl;
  cout << "4 Search for a CD with its name..." << endl;
  cout << "5 Add a CD at front..." << endl;
  cout << "6 Add a CD at back..." << endl;
  cout << "7 Delete a CD..." << endl;
  cout <<"8 Exit this program..." << endl;

  cin >> userChoice;
  

    if(userChoice == 1){
      cout << "Please enter a file name to use" << endl;
      cin >> userFileName;

      test.read_from_file(userFileName);
    }
    if(userChoice == 2){
      cout << "Please enter a file name to use" << endl;
      cin >> userFileName;

      test.write_to_file(userFileName);
    }
    if(userChoice == 3){
      test.print();
    }
    if(userChoice == 4){
      cout << "Please insert the item you want to find..." << endl;
      cin.ignore();
      getline(cin,userFileName);

      test.lookup(userFileName);
    }
    if(userChoice == 5){
      cout << "Please insert the name of the album..." << endl;
      cin.ignore();
      getline(cin,userFileName);

      cout << "Please insert the year of the album" << endl;
      cin >> userYear;

      cout << "Please insert the price of the album" << endl;
      cin >> userPrice;

      test.push_front(userFileName,userYear,userPrice);
    }
    if(userChoice == 6){
      cout << "Please insert the name of the album..." << endl;
      cin.ignore();
      getline(cin,userFileName);

      cout << "Please insert the year of the album" << endl;
      cin >> userYear;

      cout << "Please insert the price of the album" << endl;
      cin >> userPrice;

      test.push_back(userFileName,userYear,userPrice);
    }
    if(userChoice == 7){
      cout << "Enter the name of the album you want to delete..." << endl;
      cin.ignore();
      getline(cin,userFileName);

      test.delete_item(userFileName);
    }
    if(userChoice == 8){
      cout << "The program will now exit." << endl;
      return 0;
    }
    else{
      cout << "Error! Please enter a valid choice!" << endl;
    }
  }
  return 0;
}