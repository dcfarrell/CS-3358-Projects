//  Serial Number/s: 9
//
//  Author/s: Delaney Farrell
//  Due	Date: 03/04/2020
//  Programming	Assignment Number 3
//
//  Spring 2020 - CS 3358 - 253
//
//  Instructor: Husain Gholoom.
//
// 	Implements Stack and Queue ADTs with Linked Lists to compare the
//  equality of user inputed strings.

#include <iostream>

using namespace std;

//*******************************************************************
// List of files:
//
// Node.h
// Stack.h
// Stack.cpp
// Queue.h
// Queue.cpp
// driver.cpp
//*******************************************************************

//*******************************************************************
// Node.h
//
// Information for a single node of a linked list.
//*******************************************************************
struct Node
{
    string data; // holds a string
    Node *next; // points to next node in list
};

//*******************************************************************
// Stack.h
//
// Declares class Stack
//*******************************************************************
class Stack
{
private:
    Node *top; // points to node at top of list
    int stackSize; // keeps track of the size of the stack

public:
    // Constructor
    Stack();
    // Destructor
    ~Stack();

    // Operations
    void push(string s);
    string pop();
    bool isEmpty() const; // true = empty
    Node* getTop();
    int size();
    void makeEmpty();
    string peek();
};

//*******************************************************************
// Stack.cpp
//
// Implements functions in class Stack
//*******************************************************************

// Stack Default Constructor
Stack::Stack()
{
    top = NULL;
    stackSize = 0;
};

// Stack Destructor
Stack::~Stack()
{
    makeEmpty();
};

//*******************************************************************
// void push(string s)
//
// Parameter(s): string s
// Return: n/a
// Inserts a new node with data string s to the top of the stack
//*******************************************************************
void Stack::push(string s)
{
    Node *newNode;

    newNode = new Node;
    newNode->data = s;

    if(isEmpty())
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }

    top = newNode;
    stackSize++;
};

//*******************************************************************
// string pop()
//
// Parameter(s): n/a
// Return: string
// Returns the top element of the stack and removes it from the stack
//*******************************************************************
string Stack::pop()
{
    if(!isEmpty())
    {
        stackSize--;
        string temp = top->data;
        Node *tempNode = top;
        top = top->next;
        tempNode->next = NULL;
        delete tempNode;
        return temp;
    }
    else
    {
        return "";
    }
};

//*******************************************************************
// bool isEmpty() const
//
// Parameter(s): n/a
// Return: bool
// Returns true if stack is empty, false otherwise
//*******************************************************************
bool Stack::isEmpty() const
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//*******************************************************************
// Node* getTop()
//
// Parameter(s): n/a
// Return: Node*
// Returns a pointer to the stack's top node pointer
//*******************************************************************
Node* Stack::getTop()
{
    return top;
};

//*******************************************************************
// int size()
//
// Parameter(s): n/a
// Return: int
// Returns stackSize
//*******************************************************************
int Stack::size()
{
    return stackSize;
};

//*******************************************************************
// void makeEmpty()
//
// Parameter(s): n/a
// Return: n/a
// Clears the stack
//*******************************************************************
void Stack::makeEmpty()
{
    Node *nodePtr = top;
    Node *nextNode;
    while(nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    stackSize = 0;
};

//*******************************************************************
// string peek()
//
// Parameter(s): n/a
// Return: string
// Peeks at the first element in the stack without removing it
//*******************************************************************
string Stack::peek()
{
    return top->data;
};

//*******************************************************************
// Queue.h
//
// Declares class Queue
//*******************************************************************
class Queue
{
private:
    Node *front; // points to front of queue
    Node *rear; // points to end of queue
    int numElements; // number of elements in queue

public:
    // Constructor
    Queue();
    // Destructor
    ~Queue();

    // Operations
    void enqueue(string);
    string dequeue();
    bool isEmpty() const; // true = empty
    void makeEmpty();
    int size();
    string peek();

};

//*******************************************************************
// Queue.cpp
//
// Implements functions in class Queue
//*******************************************************************

// Default Constructor
Queue::Queue()
{
    front = NULL;
    rear = NULL;
    numElements = 0;
};

// Destructor
Queue::~Queue()
{
    makeEmpty();
};

//*******************************************************************
// void enqueue(string s)
//
// Parameter(s): string s
// Return: n/a
// Inserts a new node with data string s to the end of the queue
//*******************************************************************
void Queue::enqueue(string s)
{
    Node *newNode;

    newNode = new Node;
    newNode->data = s;

    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    numElements++;
};

//*******************************************************************
// string dequeue()
//
// Parameter(s): n/a
// Return: string
// Returns front element of queue and removes it from queue
//*******************************************************************
string Queue::dequeue()
{
    if(!isEmpty())
    {
        string temp = front->data;
        Node *nodePtr = front;
        front = front->next;
        delete nodePtr;
        if(isEmpty())
        {
            rear = NULL;
        }
        numElements--;
        return temp;
    }
    else
    {
        return "";
    }
};

//*******************************************************************
// bool isEmpty() const
//
// Parameter(s): n/a
// Return: bool
// Returns true if queue is empty, false otherwise
//*******************************************************************
bool Queue::isEmpty() const
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//*******************************************************************
// void makeEmpty()
//
// Parameter(s): n/a
// Return: n/a
// Clears the queue
//*******************************************************************
void Queue::makeEmpty()
{
    Node *nodePtr = front;
    Node *nextNode;
    while(nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    front = NULL;
    rear = NULL;
    numElements = 0;
};

//*******************************************************************
// int size()
//
// Parameter(s): n/a
// Return: int
// Returns numElements
//*******************************************************************
int Queue::size()
{
    return numElements;
};

//*******************************************************************
// string peek()
//
// Parameter(s): n/a
// Return: string
// Peeks at the first element in the queue without removing it
//*******************************************************************
string Queue::peek()
{
    return front->data;
};

//*******************************************************************
// driver.cpp
//
// Uses Stack and Queue to compare user inputted strings
//*******************************************************************
int main()
{
    int select = 0; // user selection 1, 2, or 9
    string input; // string inputted by user
    string hashSym = "#"; // holds # symbol for comparison
    bool foundHash = false; // false = hash not found in string
    bool areMatch = true; // true = matching queue or stack

    // Header Message
    cout << "*** Welcome to My stack / Queue Program ***\n\n"
         "The function of this program is to :\n\n"
         "\t1. Use stack to determine whether or not\n"
         "\t   two strings are the same.\n\n"
         "\t2. Use queue to determine whether or not\n"
         "\t   STRING2 is the reversed of STRING1.\n" << endl;

    // Begin main program loop
    do
    {
        // Menu
        cout << "Select from the following menu\n"
             "\t1. Enter Stack Values.\n"
             "\t2. Enter Queue Values.\n"
             "\t9. Terminate the program.\t";
        cin >> select;
        cout << "\n\n";

        if(!cin) // user enters non-integer
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid Option\n\n" << endl;
        }
        else if(select == 1)   // Option 1 -> Compare Stacks
        {
            // declaring stacks for comparing
            Stack stack1;
            Stack stack2;

            // user input
            cout << "Enter Stack Values :\t";
            cin >> input;
            cout << "\n\n";

            // fill up the two stacks
            for(unsigned int i = 0; i < input.length(); i++)
            {
                if(input.compare(i, 1, hashSym) == 0)
                {
                    foundHash = true;
                }
                else if(!foundHash)
                {
                    stack1.push(input.substr(i,1));
                }
                else
                {
                    stack2.push(input.substr(i,1));
                }
            }

            // while the stacks are not empty and still match check the top elements
            while(!stack1.isEmpty() && !stack2.isEmpty() && areMatch)
            {
                if(stack1.pop() != stack2.pop())
                {
                    areMatch = false;
                }
            }

            // make sure one of the stacks doesn't have more elements than the other
            if((!stack1.isEmpty() && stack2.isEmpty()) || (stack1.isEmpty() && !stack2.isEmpty()))
            {
                areMatch = false;
            }

            // output result
            if(areMatch)
            {
                cout << "Strings are identical\n\n" << endl;
            }
            else
            {
                cout << "Strings are not identical\n\n" << endl;
            }

            // clears stacks
            stack1.makeEmpty();
            stack2.makeEmpty();
        }
        else if(select == 2) // Option 2 -> Compare Queues
        {
            // declaring queues to compare
            Queue queue1;
            Queue queue2;

            // user input
            cout << "Enter Queue Values :\t";
            cin >> input;
            cout << "\n\n";

            // traversing index
            unsigned int i = 0;

            // fill up the first queue
            while(!foundHash && i < input.length())
            {
                if(input.compare(i, 1, hashSym) == 0)
                {
                    foundHash = true;
                }
                else if(!foundHash)
                {
                    queue1.enqueue(input.substr(i,1));
                    i++;
                }
            }

            // fill up the second queue
            if(foundHash && i < input.length())
            {
                i = input.length()-1;
                foundHash = false;
                while(i >= 0 && !foundHash)
                {
                    if(input.compare(i, 1, hashSym) == 0)
                    {
                        foundHash = true;
                    }
                    else if(!foundHash)
                    {
                        queue2.enqueue(input.substr(i,1));
                    }
                    i--;
                }
            }

            // while the queues are not empty and still match check the top elements
            while(!queue1.isEmpty() && !queue2.isEmpty() && areMatch)
            {
                if(queue1.dequeue() != queue2.dequeue())
                {
                    areMatch = false;
                }
            }

            // make sure one of the queues doesn't have more elements than the other
            if(areMatch && ((!queue1.isEmpty() && queue2.isEmpty()) || (queue1.isEmpty() && !queue2.isEmpty())))
            {
                areMatch = false;
            }

            // output result
            if(areMatch)
            {
                cout << "STRING2 is reversed of STRING1\n\n" << endl;
            }
            else
            {
                cout << "STRING2 is not reversed of STRING1\n\n" << endl;
            }

            // clears queues
            queue1.makeEmpty();
            queue2.makeEmpty();
        }
        else if(select != 9) // Invalid input
        {
            cout << "Invalid Option\n\n" << endl;
        }

        // reset values
        foundHash = false;
        input = "";
        areMatch = true;

    }
    while(select != 9); // exits loop when user enters 9

    // Footer Message
    cout << "\n\n*** End of the program. ***\n"
         "*** Written by Delaney Farrell ***\n"
         "*** March - 2020 ***\n" << endl;


    return 0;
}
