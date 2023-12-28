#include <iostream>
using namespace std;
#define MAXSIZE 5
int Queue[MAXSIZE], Front = -1, Rear = -1, ITEM;

void enQueue()
{
  if (Rear == MAXSIZE - 1)
    cout << "\nQ is full!! OVERFLOW";
  else
  {
    if (Front == -1)
      Front = 0;
    Rear++;
    cout << "Enter the ITEM to be Insert: ";
    cin >> ITEM;
    Queue[Rear] = ITEM;
    cout << "\n#Position: " << Rear << ", ITEM Inserted: " << ITEM;
  }
}
void deQueue()
{
  if (Front == -1 || Front > Rear)
    cout << "\nQ is Empty!! UNDERFLOW";
  else
  {
    cout << "\n#Position: " << Front << ", Item deleted: " << Queue[Front];
    Front++;
  }
}
void Display()
{
  if (Front == -1 || Front > Rear)
    cout << "\nQ is Empty";
  else
  {
    cout << "\nQueue elements are: ";
    for (int i = Front; i <= Rear; i++)
      cout << Queue[i] << " ";
  }
}

int main()
{
  int choice;
  while (1)
  {
    cout << "\n\n**Queue Main Menu**";
    cout << "\n1 enQueue\n2 deQueue\n3 Display\n4 Exit";
    cout << "\nEnter you choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      enQueue();
      break;
    case 2:
      deQueue();
      break;
    case 3:
      Display();
      break;
    case 4:
      exit(0);
      break;
    default:
      cout << "Wrong choice!!Try Again";
    }
  }
}
