#include "Node.h"
#include <fstream>

using namespace std;

class BinarySearchTree {
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(std::string title, double price, int year);
  void print();
  void deleteNode(std::string title);
  bool find(std::string title);
  void saveIntoFile(fstream &file);

private:
  Node *root;
  void insertHelper(Node *current, std::string title, double price, int year);
  void printHelper(Node *current);
  void deleteHelper(Node*& current, std::string title);
  void destructorHelper(Node* current);
  bool findHelper(Node* current, std::string title);
  void saveIntoFileHelper(Node * current, fstream &file);
};
