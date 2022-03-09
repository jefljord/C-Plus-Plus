#include <iostream>
#include <fstream>

#include "Vector.h"

using namespace std;

Vector::Vector(){
  ptr = NULL;

  size = 0;
  capacity = 0;
}

Vector::Vector(const Vector &other){
  size = other.size;
  capacity = other.capacity;
  
  for(int i = 0; i < size; i++){
    ptr[i] = other.ptr[i];
  }
}

Vector::~Vector(){
  cout << "Deleting the Vector..." << endl;
  
  delete[] ptr;
}

Vector& Vector::operator=(const Vector &other){
  double *Equal = new double[other.size];

  size = other.size;
  capacity = other.capacity;

  for (int i = 0; i < size; i++){
    Equal[i] = other.ptr[i];
  }
  return *this;
}

int Vector::getSize(){
  //unsure how to even test this
  return size;
}

int Vector::getCapacity(){
  //unsure how to even test this
  return capacity;
}

bool Vector::push(double element, unsigned int index){
  //puts in a user defined element in a user defined index. I had some simple catches for out of bounds
  if(index >= 0){
    if(index < size){
      ptr[index] = element;
      return true;
    }
  }
}

double Vector::pop_front(){
  //kills the first index and moves everything over 1 index.
  double x = ptr[0];

  for(int i = 1; i < size; i++){
    ptr[i-1] = i;
  }
  size--;
  return x;
}

void Vector::resize(){
  //this just doubles the cap it says the indexes can not be touched so I am unsure where we would begin testing.
  if(capacity != 0){
    capacity = capacity * 2;
  }
  else{
    capacity = 1;
  }

}

double& Vector::operator[](unsigned int index){
  return ptr[index]; //just returns the index the user gives. Will most likely need if statements to catch out of bounds 
}
