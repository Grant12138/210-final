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
std::string muffinTypes[] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Bran", "Cranberry",
                             "Apple Cinnamon", "Double Chocolate", "Lemon Poppyseed", "Raspberry", "Pumpkin"};
const int NUM_MUFFINS = 10;
std::string braceletTypes[] = {"Friendship Knot", "Beaded", "Charm", "Braided", "Wrap", "Cuff",
                               "Leather", "Friendship", "Infinity", "Adjustable"};
const int NUM_BRACELETS = 10;
std::string sandwichTypes[] = {"Turkey Club", "Ham & Cheese", "BLT", "Veggie Delight",
                               "Chicken Salad", "Tuna Melt", "Roast Beef", "Grilled Cheese", "Egg Salad", "Caprese"};
const int NUM_SANDWICHES = 10;

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

        bool dequeue(string& servedName, string& servedDrink)
        {
            if (head == nullptr)
                return false;
            CoffeeNode* temp = head;
            servedName = head->name;
            servedDrink = head->drink;
            head = head->next;
            if (head == nullptr)
                tail = nullptr;
            delete temp;

            return true;
        }
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

        bool dequeue(string& servedName, string& servedMuffin)
        {
            if (queue.empty())
                return false;
            MuffinCustomer servedCustomer = queue.front();
            servedName = servedCustomer.name;
            servedMuffin = servedCustomer.muffinType;
            queue.pop_front();
            return true;
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

        bool dequeue(string& servedName, string& servedBracelet)
        {
            if (queue.empty())
                return false;
            BraceletCustomer servedCustomer = queue.front();
            servedName = servedCustomer.name;
            servedBracelet = servedCustomer.braceletType;
            queue.erase(queue.begin());
            return true;
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
        return a.priority < b.priority;
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

        void dequeue(string& servedName, string& servedSandwich, int& servedPriority)
        {
            if (queue.empty())
                return false;
            SandwichCustomer servedCustomer = queue.top();
            servedName = servedCustomer.name;
            servedSandwich = servedCustomer.sandwichType;
            servedPriority = servedCustomer.priority;
            queue.pop();
            return true;
        }
};

int main()
{
    srand(time(0));

    CoffeeQueue coffeeQueue;
    MuffinQueue muffinQueue;
    BraceletQueue braceletQueue;
    SandwichQueue sandwichQueue;

    cout << "Initializing Coffee Booth Queue:\n";
    for (int i = 0; i < 3; i++)
    {
        string randomName = names[ rand() % NUM_NAMES ];
        string randomDrink = drinks[ rand() % NUM_NAMES ];
        coffeeQueue.enqueue(randomName, randomDrink);
    }
    coffeeQueue.displayQueue();
    cout << "--------------------------------------------\n";

    std::cout << "Initializing Muffin Booth Queue:\n";
    for (int i = 0; i < 3; i++)
    {
        std::string randomName = names[ rand() % NUM_NAMES ];
        std::string randomMuffin = muffinTypes[ rand() % NUM_MUFFINS];
        muffinQueue.enqueue(randomName, randomMuffin);
    }
    muffinQueue.displayQueue();
    cout << "----------------------------------------\n";

    std::cout << "Initializing Bracelet Booth Queue:\n";
    for (int i = 0; i < 3; i++)
    {
        std::string randomName = names[ rand() % NUM_NAMES ];
        std::string randomBracelet = braceletTypes[ rand() % NUM_BRACELETS ];
        braceletQueue.enqueue(randomName, randomBracelet);
    }
    braceletQueue.displayQueue();
    cout << "----------------------------------------\n";

    std::cout << "Initializing Sandwich Booth Queue:\n";
    for (int i = 0; i < 3; i++)
    {
        std::string randomName = names[ rand() % NUM_NAMES ];
        std::string randomSandwich = sandwichTypes[ rand() % NUM_SANDWICHES ];
        int randomPriority = ( rand() % 5) + 1; // Priority between 1 and 5
        sandwichQueue.enqueue(randomName, randomSandwich, randomPriority);
    }
    sandwichQueue.displayQueue();
    cout << "----------------------------------------\n";

    // Simulate for 10 times
    const int TOTAL_ROUNDS = 10;
    for (int round = 1; round <= TOTAL_ROUNDS; round++)
    {
        cout << "Round " << round << '\n';

        // Coffee Booth
        string servedCoffeeName, servedCoffeeDrink;
        if (coffeeQueue.dequeue(servedCoffeeName, servedCoffeeDrink))
            cout << "Coffee Booth: Served " << servedCoffeeName << " their " << servedCoffeeDrink << ".\n";
        else
            cout << "Coffee Booth: No customer served this round.\n";

        // Muffin Booth
        string servedMuffinName, servedMuffinType;
        if (muffinQueue.dequeue(servedMuffinName, servedMuffinType))
            cout << "Muffin Booth: Served " << servedMuffinName << " their " << servedMuffinType << " muffin.\n";
        else
            cout << "Muffin Booth: No customer served this round.\n";

        // Bracelet Booth
        string servedBraceletName, servedBraceletType;
        if (braceletQueue.dequeue(servedBraceletName, servedBraceletType))
            cout << "Bracelet Booth: Served " << servedBraceletName << " their " << servedBraceletType << " bracelet.\n";
        else
            cout << "Bracelet Booth: No customer served this round.\n";

        // Sandwiches Booth
        string servedSandwichName, servedSandwichType;
        int servedSandwichPriority;
        if (sandwichQueue.dequeue(servedSandwichName, servedSandwichType, servedSandwichPriority))
            cout << "Sandwich Booth: Served " << servedSandwichName << " their " << servedSandwichType << " sandwich (Priority: " << servedSandwichPriority << ").\n";
        else
            cout << "Sandwich Booth: No customer served this round.\n";

        // Add Coffee Customer
        int addCoffeeCustomer = rand() % 2;
        if (addCoffeeCustomer == 0)
        {
            string newCoffeeName = names[ rand() % NUM_NAMES ];
            string newCoffeeDrink = drinks[ rand() % NUM_DRINKS ];
            coffeeQueue.enqueue(newCoffeeName, newCoffeeDrink);
        }

        int addMuffinCustomer = rand() % 2;
        if (addMuffinCustomer == 0)
        {
            string newMuffinName = names[ rand() % NUM_NAMES ];
            string newMuffinType = muffinTypes[ rand() % NUM_MUFFINS ];
            muffinQueue.enqueue(newMuffinName, newMuffinType);
        }

        int addBraceletCustomer = rand() % 2;
        if (addBraceletCustomer == 0)
        {
            string newBraceletName = names[ rand() % NUM_NAMES ];
            string newBraceletType = braceletTypes[ rand() % NUM_BRACELETS ];
            braceletQueue.enqueue(newBraceletName, newBraceletType);
        }

        int addSandwichCustomer = rand() % 2;
        if (addSandwichCustomer == 0)
        {
            string newSandwichName = names[ rand() % NUM_NAMES];
            string newSandwichType = sandwichTypes[ rand() % NUM_SANDWICHES ];
            int newSandwichPriority = 1 + (rand() % 5);
            sandwichQueue.enqueue(newSandwichName, newSandwichType, newSandwichPriority);
        }
    }


    return 0;
}