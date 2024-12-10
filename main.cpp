#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// Possible names and drinks
string names[] = {"Ella", "Inga", "Zane", "Oleg", "Wade", "Yale", "Tami",
                  "Tara", "Axel", "Ola", "Beth", "Boyd", "Rosa"};
const int NUM_NAMES = 13;
string drinks[] = {"Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
                   "Flat White", "Macchiato", "Tea", "Hot Chocolate", "Iced Coffee"};
const int NUM_DRINKS = 10;
string muffinTypes[] = {"Blueberry", "Chocolate Chip"};

// Coffee Booth
struct CoffeeNode
{
    string name;
    string drink;
    CoffeeNode* next;

    CoffeeNode(const string& customerName, const string& drinkOrder)
        : name(customerName), drink(drinkOrder), next(nullptr) {}
};

class CoffeeQueue
{
    private:
        CoffeeNode* head;
        CoffeeNode* tail;

    public:
        CoffeeQueue() : head(nullptr), tail(nullptr) {}

        ~CoffeeQueue()
        {
            while (head != nullptr)
            {
                CoffeeNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void enqueue(const string& name, const string& drink)
        {
            CoffeeNode* newNode = new CoffeeNode(name, drink);
            if (tail == nullptr)
                head = tail = newNode;
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Coffee Booth: Customer " << name << " with drink " << drink << " joined the queue.\n";
        }

        void displayQueue() const
        {
            cout << "Coffee Booth Queue: ";
            CoffeeNode* current = head;
            while (current != nullptr)
            {
                cout << "[" << current->name << " - " << current->drink << "]";
                current = current->next;
            }
            cout << '\n';
        };
};

// Muffin Booth
struct MuffinCustomer
{
    string name;
    string muffinType;

    MuffinCustomer(const string& customerName, const string& customerMuffin)
        : name(customerName), muffinType(customerMuffin) {}
};

class MuffinQueue
{
    private:
        deque<MuffinCustomer> queue;

    public:
        void enqueue(const string& name, const string& muffinType)
        {
            queue.emplace_back(name, muffinType);
            cout << "Muffin Booth: Customer " << name << " with muffin" << muffinType << " joined the queue.\n";
        }

        void displayQueue() const
        {
            cout << "Muffin Booth Queue: ";
            for (const auto& customer : queue)
                cout << "[" << customer.name << " - " << customer.muffinType << "] ";
            cout << '\n';
        }
};

// Bracelet Booth
struct BraceletCustomer
{
    string name;
    string braceletType;

    BraceletCustomer(const string& customerName, const string& customerBracelet)
        : name(customerName), braceletType(customerBracelet) {}
};

class BraceletQueue
{
    private:
        vector<BraceletCustomer> queue;
    public:
        void enqueue(const string& name, const string& braceletType)
        {
            queue.emplace_back(name, braceletType);
            cout << "Bracelet Booth: Customer " << name << " with bracelet " << braceletType << " joined the queue.\n";
        }

        void displayQueue() const
        {
            cout << "Bracelet Booth Queue: ";
            for (const auto& customer : queue)
                cout << "[" << customer.name << " - " << customer.braceletType << "] ";
            cout << '\n';
        }
};

// Sandwiches Booth
struct SandwichCustomer
{
    string name;
    string sandwichType;
    int priority;

    SandwichCustomer(const string& customerName, const string& customerSandwich, int customerPriority)
        : name(customerName), sandwichType(customerSandwich), priority(customerPriority) {}
};

struct CompareSandwichCustomer
{
    bool operator()(const SandwichCustomer& a, const SandwichCustomer& b)
    {
        return a.priority < b.priority
    }
};

class SandwichQueue
{
    private:
        priority_queue<SandwichCustomer, vector<SandwichCustomer>, CompareSandwichCustomer> queue;
    public:
        void enqueue(const string& name, const string& sandwichType, int priority)
        {
            SandwichCustomer newCustomer(name, sandwichType, priority);
            queue.push(newCustomer);
            cout << "Sandwich Booth: Customer " << name << " with sandwich " << sandwichType << " (Priority: " << priority << ") joined the queue.\n";
        }

        void displayQueue() const
        {
            // Create a copy to prevent modification
            priority_queue<SandwichCustomer, vector<SandwichCustomer>, CompareSandwichCustomer> tempQueue = queue;
            cout << "Sandwich Booth Queue: ";
            while (!tempQueue.empty())
            {
                SandwichCustomer customer = tempQueue.top();
                cout << "[" << customer.name << " - " << customer.sandwichType << " (Priority: " << customer.priority << ")] ";
                tempQueue.pop();
            }
            cout << '\n';
        }
};

int main()
{
    srand(time(0));


    // Initialize Queue with three customers

    return 0;
}