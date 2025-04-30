/**~*~*~* 
Stack of strings: Implementing and testing 
 - getLEngth()
 - isEmpty()
 - peek()
===========================================
Name: Dylan Lam
IDE: VS code
*~*/
#include <iostream>
#include <string>
using namespace std;

class Stack_str
{
private:
   // Structure for the stack nodes
   struct StackNode {
       string value;        // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;              // number of nodes in the stack

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   //~Stack_str();                           // Destructor

   // Stack operations

   // Checks to see if there are nodes in the stack
   bool isEmpty() {
      return length == 0;
    }

   bool push(string);
   // string pop();

   // Checks to see if the node is empty and returns the value at the top of the stack
   string peek() {
      if( !isEmpty() ) {
         return top->value;
      }
      else {
         return "Empty Stack!";
      }
   }

   // Counts the number of nodes in the stack until it reaches the null pointer
   int getLength() {
      int count = 0;
      StackNode* curr = top;

      while( curr != nullptr ) {
         count += 1;
         curr = curr->next;
      }

      return count;
   }
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store item there.
   newNode = new StackNode;
   if (!newNode)
       return false;   // Allocation of memory fails
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}


int main() {

     Stack_str s;
     string item;

     // Adding strings into a stack until the user enters 0
     while( true ) { // While loop is true until 0 is entered
         getline(cin, item); // getline ignores spaces
         if( item == "0") {
            break;
         }
         s.push(item);
     }

     cout << s.getLength() << endl;
     cout << s.peek() << endl;
     cout << s.getLength() << endl;


   
     
     return 0;
}