#ifndef CDCOLLECTION
#define CDCOLLECTION

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct Entry {  
  std::string name;
  double price;
  int year;

  Entry *next;
};

class cdCollection{

public:
  Entry *head, *tail;

  cdCollection();
  /* Description:
   *    Default constructor.  
   *      Sets head and tail to NULL
   *
   *    Parameters:
   *      None
   *
   *    Post-conditions:
   *      Sets head and tail to NULL and announces their construction on the console.
   */
  ~cdCollection();
  /* Description:
   *     Deconstructor.  
   *      Deallocates memory for the linked list.
   *
   *    Parameters:
   *      None
   *
   *    Post-conditions:
   *      Destroys the linked list and announces all items deallocated correctly.
   */
  void push_front(std::string tempName, int tempYear, double tempPrice);
    /* Description:
   *     push_front
   *      Throws a user defined album name, release year, and price to the front of the     *      linked list.
   *
   *    Parameters:
   *      string tempName, int tempYear, double tempPrice
   *        The album name, its release year, and its price.
   *
   *    Post-conditions:
   *      Adds the album to the front of the list.
   */
  void push_back(std::string tempName, int tempYear, double tempPrice);
    /* Description:
   *     push_back
   *      Throws a user defined album name, release year, and price to the back of the     *      linked list.
   *
   *    Parameters:
   *      string tempName, int tempYear, double tempPrice
   *        The album name, its release year, and its price.
   *
   *    Post-conditions:
   *      Adds the album to the back of the list.
   */
  void read_from_file(std::string fileName);
    /* Description:
   *     read_from_file
   *      Reads a user defined file into a linked list.
   *
   *    Parameters:
   *      string fileName
   *        User defined file name.
   *
   *    Post-conditions:
   *      File is read into a linked list using push_front
   */
  void write_to_file(std::string fileName);
    /* Description:
   *     write_to_file
   *      Reads the linked list into a user defined file.
   *
   *    Parameters:
   *      string fileName
   *        User defined file name.
   *
   *    Post-conditions:
   *      Linked list is written to a file.
   */
  void lookup(std::string s);
    /* Description:
   *     lookup
   *      Searches for a album name and returns the price and release year
   *
   *    Parameters:
   *      string s
   *        User defined album name
   *
   *    Post-conditions:
   *      Prints the correct year and price onto the console.
   */
  void print();
    /* Description:
   *     print 
   *      Prints the entire linked list onto the console.
   *
   *    Parameters:
   *      None
   *
   *    Post-conditions:
   *     Prints the entire linked list onto the console.
   */
  void delete_item(std::string s);
    /* Description:
   *     delete_item
   *      Searches for a user defined album name and removes it from the linked list.
   *
   *    Parameters:
   *      string s
   *        A user defined album name. 
   *
   *    Post-conditions:
   *      Removes the correct album from the linked list.
   */
};
#endif