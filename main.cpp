#include <iostream>
using namespace std;

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

    // Possible names and drinks
    string names[] = {""};

    return 0;
}