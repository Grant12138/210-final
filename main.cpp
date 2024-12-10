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

    public:
        Queue()
};

int main()
{


    return 0;
}