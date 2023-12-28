#include <iostream>
using namespace std;
#define MAXSIZE 5
int Stack[MAXSIZE], TOP = 0, ITEM;

void push()
{
    if (TOP == MAXSIZE)
    {
        cout << "Stack is full. Overflow";
    }
    else
    {
        cout << "\n Enter the value to be pushed in stack:\t";
        cin >> ITEM;
        cout << "\n Position: " << TOP << ", Pushed Value: " << ITEM;
        Stack[TOP++] = ITEM;
    }
}

void pop()
{
    if (TOP == -1)
    {
        cout << "Stack is empty. Underflow";
    }
    else
    {
        TOP--;
        cout << "\n Position: " << TOP << ", Popped Value: " << Stack[TOP];
    }
}

void display()
{
    if (TOP == -1)
        cout << "Stack is empty";
    else
    {
        for (int i = TOP - 1; i >= 0; i--)
            cout << "\n Position: " << i << ", Value: " << Stack[i];
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "\n\n**STACK Main Menu**";
        cout << "\n1 PUSH\n2 POP\n3 Display\n4 Exit";
        cout << "\nEnter you choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Wrong choice!!Try Again";
        }
    }
    return 0;
}