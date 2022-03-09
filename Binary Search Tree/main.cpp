#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "binary_search_tree.h"

using namespace std;

int main() {
  BinarySearchTree tree;
  int choice;

  string s;
	int year;
	double price;

  do {
	  cout << "\n";
	  cout << "1). Instert Node" << endl;
	  cout << "2). Print Tree"<< endl;
	  cout << "3). Read from file"<< endl;
	  cout << "4). Find CD in Tree"<< endl;
	  cout << "5). Delete CD in Tree" << endl;
	  cout << "6). Save in file" << endl;
	  cout << "0). Exit" << endl <<endl;

	  cout << "Enter Choice: ";

	  cin >> choice;

	  switch (choice)
	  {
	  case 1:{

		  cin.ignore();

		  cout << "Enter Title: " << endl;
		  getline(cin, s);
		  cout << "Enter Year: "<< endl; 
		  cin >> year;
		  cout << "Enter Price: "<< endl;
		  cin >> price;

		  tree.insert(s, price, year);

		  break;
	  }
	  case 2:
	  {
		  tree.print();
		  break;
	  }
	  case 3:
	  {
		  string s;
		  cin.ignore();
		  cout << "Enter Filename: ";
		  getline(cin, s);

		  cout << endl;

		  fstream fin;
		  fin.open(s, ios::in);

		  int year;
		  double price;

		  if (fin.is_open())
		  {
			  while (getline(fin, s))
			  {
				  fin >> price >> year;
				  tree.insert(s, price, year);

				  fin.ignore();

			  }
			  fin.close();
		  }

		  else 
			  cout << "Unable to open file" << endl;
		  break;
	  }
	  case 4:
	  {
		  string s;

		  cout << "Enter Title: " << endl;
      
		  cin.ignore();
		  getline(cin, s);

		  if (tree.find(s))
			  cout << "Element found." << endl;
		  else
			  cout << "Element not found." << endl;

		  break;
	  }
	  case 5:
	  {
		  string s;
		  
		  cout << "Enter Title: " << endl ;

      cin.ignore();
		  getline(cin, s);

		  tree.deleteNode(s);

		  break;
	  }
	  case 6:
	  {
		  cin.ignore();
		  string s;
		  cout << "Enter Filename: ";
		  getline(cin, s);

		  fstream fout;
		  fout.open(s, ios::out | ios::trunc);

		  tree.saveIntoFile(fout);
		  cout << "Done.";

		  break;
	  }
	  case 0:
	  {
		  cout << "Program will not exit...";
		  break;
	  }
	  };


  } while (choice != 0);
  
  return 0;
}
