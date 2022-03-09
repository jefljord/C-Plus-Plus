#include <iostream>
#include "binary_search_tree.h"
#include <fstream>

using namespace std;

BinarySearchTree::BinarySearchTree() {
  root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
  destructorHelper(root);
}

void BinarySearchTree::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}

bool BinarySearchTree::findHelper(Node* current, std::string title)
{
	if (current->title.compare(title) == 0)
		return 1;
	
	if (current->title.compare(title) < 0)
		findHelper(current->left, title);
	else
		findHelper(current->right, title);

	return 0;
}

void BinarySearchTree::saveIntoFileHelper(Node* current, fstream& file)
{
	if (current == NULL)
		return;

	file << current->title << "\n" << current->price << " " << current->year << "\n";

	saveIntoFileHelper(current->left, file);
	saveIntoFileHelper(current->right, file);
}

void BinarySearchTree::insert(std::string title, double price, int year) {
  if(root == NULL)
    root = new Node(title,price,year);
  else
    insertHelper(root, title, price, year);
}

void BinarySearchTree::insertHelper(Node *current, std::string title, double price, int year) {
  
	if (current->title.compare(title) == 0)
	{
		current->price = price;
		current->title = title;
		current->year = year;
		return;
	}
	
  if(title.compare(current->title) < 0) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Node(title, price, year);
    else
      insertHelper(current->left, title, price, year);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Node(title, price, year);
    else
      insertHelper(current->right, title, price, year);
  }

}

void BinarySearchTree::print() {
  printHelper(root);
  cout << endl;
}

void BinarySearchTree::printHelper(Node *current) {
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
	cout << current->title << " " << current->year << " " << current->price << "\n";
    printHelper(current->right);
  }
}

void BinarySearchTree::deleteNode(std::string title) {
  deleteHelper(root, title);
}

void BinarySearchTree::deleteHelper(Node* &current, std::string title) {
  //Node doesn't exist
  if(current == NULL)
    return;
  //Go left
  else if (title.compare(current->title) < 0)
    deleteHelper(current->left, title);
  //Go right
  else if (title.compare(current->title) > 0)
    deleteHelper(current->right, title);
  //Delete current node
  else {
    Node *temp;

    if(current->left == NULL) {
      temp = current->right;
      delete current;
      current = temp;
    }
    else if(current->right == NULL) {
      temp = current->left;
      delete current;
      current = temp;
    }
    //2 children
    else {
      temp = current->right;
      Node *parent = NULL;
      
      while(temp->left != NULL) {
	parent = temp;
	temp = temp->left;
      }

      current->title = temp->title;
	  current->price = temp->price;
	  current->year = temp->year;

      if(parent != NULL)
	deleteHelper(parent->left, parent->left->title);
      else
	deleteHelper(current->right, current->right->title);

    }//else
  }//else
}

bool BinarySearchTree::find(std::string title)
{
	if (root == NULL)
		return 0;

	return findHelper(root,title);
}

void BinarySearchTree::saveIntoFile(fstream &file)
{
	if (root == NULL)
		return;

	saveIntoFileHelper(root, file);
}
