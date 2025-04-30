/**~*~*~* 
Stack of strings: Implementing and testing 
 - pop()
===========================================
Name: Dylan
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
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   // ~Stack_str();                          // Destructor

   // Stack operations
   bool isEmpty() {
        return length == 0;
   }
   bool push(string);
   string pop();
   // string peek();
   // int getLength();
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

/**~*~*~*
  Member function pop pops the value at the top
  of the stack off, and returns it
  Assume stack is not empty
*~**/
/* Define the pop function */
string Stack_str::pop() {
    StackNode *currnode = top;
    if( currnode == nullptr ) {
        return "Empty Stack!";
    }

    StackNode* temp = top;
    string poppedValue = top->value;

    top = top->next;     // Move top to the next node
    delete temp;         // Delete the old top node
    length--;            // Optional: update length if you track it

    return poppedValue;  // Return the value that was popped

}


int main() {

     Stack_str s;
     string item;

     /* Write your code here to test the push and pop functions */
     // Adding strings into a stack until the user enters 0
    while (true)
    {                       // While loop is true until 0 is entered
        getline(cin, item); // getline ignores spaces
        if (item == "0")
        {
            break;
        }
        s.push(item);
    }

    // Always call pop once — it will print "Empty stack!" if stack is empty
    if (s.isEmpty()) {
        cout << s.pop() << endl;
    } else {
        while (!s.isEmpty()) {
            cout << s.pop() << endl;
        }
    }
     
     return 0;
}