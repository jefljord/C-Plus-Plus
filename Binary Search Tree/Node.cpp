#include "Node.h"

Node::Node(std::string title, double price, int year) {
  left=NULL;
  right=NULL;
  this->title = title;
  this->price = price;
  this->year = year;
}
