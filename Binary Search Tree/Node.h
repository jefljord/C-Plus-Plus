#include <string>

class Node {
public:
	Node* left, * right;
	std::string title;
	double price;
	int year;

	Node(std::string title, double price, int year);
};