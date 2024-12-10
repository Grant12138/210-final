#include <iostream>
using namespace std;

// Possible names and drinks
string names[] = {"Ella", "Inga", "Zane", "Oleg", "Wade", "Yale", "Tami",
                  "Tara", "Axel", "Ola", "Beth", "Boyd", "Rosa"};
const int NUM_NAMES = 13;
string drinks[] = {"Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
                   "Flat White", "Macchiato", "Tea", "Hot Chocolate", "Iced Coffee"};
const int NUM_DRINKS = 10;

struct Node
{
    string name;
    string drink;
    Node* next;

    Node(const string& customerName, const string& drinkOrder) :
    name(customerName), drink(drinkOrder), next(nullptr) {}
};

class Queue
{
    private:
        Node* head;
        Node* tail;

    public:
        Queue() : head(nullptr), tail(nullptr) {}

        ~Queue()
        {
            while (head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void enqueue(const string& name, const string& drink)
        {
            Node* newNode = new Node(name, drink);
            if (tail == nullptr)
                head = tail = newNode;
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void displayQueue() const
        {
            cout << "Current Queue: ";
            Node* current = head;
            while (current != nullptr)
            {
                cout << "[" << current->name << " - " << current->drink << "]";
                current = current->next;
            }
            cout << '\n';
        };
};




int main()
{
    srand(time(0));

    Queue coffeeQueue;

    // Initialize Queue with three customers
    for (int i = 0; i < 3; i++)
    {
        string randomName = names[ rand() % NUM_NAMES ];
        string randomDrink = drinks[ rand() % NUM_DRINKS ];
        coffeeQueue.enqueue(randomName, randomDrink);
    }

    return 0;
}