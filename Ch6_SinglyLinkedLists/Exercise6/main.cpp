/**~*~*~* 
 Project: Singly-Linked List - insertSorted()
 
 This program builds and displays a sorted list.
 The list is sorted in ascending order by name.
 
 Requirements:
   1. Change the insertSorted() function to sort the list in descending order by gpa.
   2. Debug the destructor
 
===========================================
Name:
IDE:
*~*/

#include <iostream>
#include <sstream>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;
    
    buildList(list);       
    list.displayList();

    return 0;
}
/*  
This function builds a sorted linked list with data from the keyboard.
The list is sorted in ascending order by the students' names.
It calls the insertSorted() function that inserts the new data at the right location in the linked list.
An input line contains the gpa of a student follow by the student's name (assume it is a single word name)
To stop reading enter "#"
*/
void buildList(StudentList &list)
{
   string line;
   getline(cin, line);
   while (line != "#")
   {
      stringstream temp(line); // create a stringstream named temp with data from line
      Student newStu;
      temp >> newStu.gpa;      // read gpa from temp
      temp >> newStu.name;     // read name from temp
      list.insertSorted(newStu);
      getline(cin, line);
   }
    
}