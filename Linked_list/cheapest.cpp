#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int price;
    node *link;
};

class PriceList
{
    node *head;

public:
    PriceList() { head = NULL; }

    void create(int n)
    {
        node *nn, *prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter price for item " << i + 1 << ": ";
            cin >> nn->price;
            nn->link = NULL;
            if (i == 0)
            {
                head = nn;
                prev = nn;
                continue;
            }
            prev->link = nn;
            prev = nn;
        }
    }

    void displayCheapest()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        int minPrice = INT_MAX;

        while (temp != NULL)
        {
            if (temp->price < minPrice)
            {
                minPrice = temp->price;
            }
            temp = temp->link;
        }

        cout << "The price of the cheapest item is: " << minPrice << endl;
    }
};

int main()
{
    PriceList priceList;
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    priceList.create(n);
    priceList.displayCheapest();
    return 0;
}
