/**~*~*~*
Stack template
===========================================
Name:
IDE:
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <typename T>
class Stack {
private:
    // Structure for the stack nodes
    struct StackNode {
        T value;         // Value in the node
        StackNode *next; // Pointer to next node
    };

    StackNode *top; // Pointer to the stack top
    int length;

public:
    // Constructor
    Stack() {
        top = nullptr;
        length = 0;
    }

    // Destructor
    ~Stack() {
        StackNode *curr = top;
        while (curr != nullptr)
        {
            StackNode *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Stack operations:
    // push()
    void push(T item) {
        StackNode *newNode = new StackNode;
        newNode->value = item;
        newNode->next = top;
        top = newNode;
        length++;
    }

    // pop()
    T pop() {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty!");
        }
        T item = top->value;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        length--;
        return item;
    }

    // peek()
    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        return top->value;
    }
    
    // isEmpty()
    bool isEmpty() const {
        return length == 0;
      }

    // getLength()
    int getLength() const {
        return length;
     }
};

#endif
