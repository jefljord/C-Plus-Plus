#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "cdCollection.h"

using namespace std;

cdCollection::cdCollection(){
  cout << "Constructor activated..." << endl;
  head = NULL;
  tail = NULL;
}

cdCollection::~cdCollection(){
  cout << "Destructor has been called..." << endl;
  Entry *temp = new Entry;
  Entry *eraser = new Entry;

  while(head != NULL){

  }
}

void cdCollection::push_front(string tempName, int tempYear, double tempPrice){
  Entry *insert = new Entry;
  insert -> next = NULL;

  insert -> name = tempName;
  insert -> year = tempYear;
  insert -> price = tempPrice;

  insert -> next = head;
  head = insert;
}

void cdCollection::push_back(string tempName, int tempYear, double tempPrice){
  Entry *insert = new Entry;

  insert -> name = tempName;
  insert -> price = tempPrice;
  insert -> year = tempYear;

  insert -> next = NULL;

  if(head == NULL){
    head = insert;
  }
  else{
    Entry *tail = head;

    while(tail -> next != NULL){
      tail = tail -> next;
    }
    tail -> next = insert;
  }
}


void cdCollection::read_from_file(string fileName){
  ifstream inputFile;
  string tempName;
  int tempYear;
  double tempPrice; 

  inputFile.open(fileName);
  
  if(inputFile.is_open()){
    while(inputFile){
      getline(inputFile,tempName);


      inputFile >> tempPrice;

      inputFile >> tempYear;
      inputFile.get();

      push_front(tempName,tempYear,tempPrice);
    }
  }
  else{
    cout << "ERROR! Opening read file!" << endl;
  }
  inputFile.close();
}

void cdCollection::write_to_file(string fileName){
  ofstream outputFile;

  outputFile.open(fileName);
  if(outputFile.is_open()){
    Entry *writer;
    writer = head;

    while(writer != NULL){
      outputFile << writer -> name << endl;
      outputFile << writer -> price << " " << writer -> year <<endl;
      writer = writer -> next;
    }
  }
  else{
    cout << "ERROR! Opening write file!" << endl;
  }
  outputFile.close();
}

void cdCollection::lookup(string s){
  Entry *lookup;
  lookup = head;
  
  while(lookup != NULL){
    if(lookup -> name == s){
      cout << "Album Price: " << lookup -> price << " Album Year: " << lookup -> year << endl;
    }
    else{
      lookup = lookup -> next;
    }
  }
}

void cdCollection::print(){
  Entry *printer;
  printer = head;

  while(printer != NULL){
    cout << "Album name: " << printer -> name << " " << "Album price: $" << printer -> price << "Album year: " << printer -> year << endl;

    printer = printer -> next;
  }
}

void cdCollection::delete_item(string s){
  Entry *temp, *eraser;

  if(head == NULL){
    return; //list is empty so we return.
  }
  else if(head -> name == s){ //the head of the list is the item so we just delete head
    eraser = head;
    head = head -> next;
    delete eraser;
  }
  else{
    temp = head;

    while(temp -> next != NULL && temp -> next -> name != s){
      temp = temp -> next; //if the next node is not NULL or the name of the album we move on
    }
    if(temp -> next != NULL){
      eraser = temp -> next;
      temp -> next = eraser -> next;
      delete eraser;
    }
  }
}