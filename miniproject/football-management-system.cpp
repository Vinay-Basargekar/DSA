#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

// structure node containing Player's information
struct Node
{
    char player_name[100];
    int jersey_number;
    int goal;
    int got_red_card;
    int got_yellow_card;
    float pass_accuracy;
    Node *link;
};

class Football
{
    Node *match_1; // Head pointer for Linked list for match 1
    Node *match_2; // Head pointer for Linked list for match 2

public:
    // constructor
    Football()
    {
        match_1 = NULL;
        match_2 = NULL;
    }

    void player_info_add(int match);
    void show(int match);
    void search_player(int match);
    void performance();
    void edit(int match);
    void delete_player(int match);
    void sortPlayersByGoals();
    void merge(Node *&head, Node *left, Node *right);
    void mergeSort(Node *&head);
    void combineMatches(Node *match1, Node *match2, Node *&combinedList);
    void displaySortedPlayers(Node *head);
    Node *getMiddle(Node *head);
    void getBest11Players();
};

// Function to add Multiple player's information
void Football::player_info_add(int match)
{
    Node *nn;
    nn = new Node;

    cout << endl;
    cout << "\tEnter Player Name: ";
    cin >> nn->player_name;

    cout << "\tEnter Jersey Number: ";
    cin >> nn->jersey_number;

    cout << "\tEnter Goal Figure: ";
    cin >> nn->goal;

    cout << "\tEnter Red Card Figure: ";
    cin >> nn->got_red_card;

    cout << "\tEnter Yellow Card Figure: ";
    cin >> nn->got_yellow_card;

    cout << "\tEnter The Percentage of Pass Accuracy: ";
    cin >> nn->pass_accuracy;

    nn->link = NULL;

    // stack implementation

    if (match == 1)
    {
        nn->link = match_1;
        match_1 = nn;
    }
    else if (match == 2)
    {
        nn->link = match_2;
        match_2 = nn;
    }
    else
    {
        cout << "\tInvalid match number!" << endl;
        delete nn;
    }
}

// Display Function For Specific Match
void Football::show(int match)
{
    Node *temp;

    if (match == 1)
    {
        temp = match_1;
    }
    else
    {
        temp = match_2;
    }

    if (temp == NULL)
    {
        cout << "\t\tNo Info in the match list." << endl;
    }
    else
    {
        cout << "======================== Player Info list for Match-" << match << " ======================== " << endl;
        cout << endl;

        while (temp != NULL)
        {
            cout << "\tPlayer Name: " << temp->player_name << endl;
            cout << "\tJersey Number: " << temp->jersey_number << endl;
            cout << "\tGoal Figure: " << temp->goal << endl;
            cout << "\tRed Card Figure: " << temp->got_red_card << endl;
            cout << "\tYellow Card Figure: " << temp->got_yellow_card << endl;
            cout << "\tPass accuracy: " << temp->pass_accuracy << endl;

            temp = temp->link;
            cout << "\n";
        }

        cout << "\n";
    }
}

// Search Function Using Player Name and Player Jersey Number
void Football::search_player(int match)
{
    char name[100];
    int number;

    cout << "\tEnter Name: ";
    cin >> name;
    cout << endl;

    cout << "\tEnter Jersey Number: ";
    cin >> number;
    cout << endl;

    // Temporary pointer to traverse the specified match list
    Node *temp;

    if (match == 1)
    {
        temp = match_1;
    }
    else
    {
        temp = match_2;
    }

    if (temp == NULL)
    {
        cout << "\tNo Info available in Match-" << match << endl;
    }
    else
    {
        // Traverse the match list using Temporary pointer
        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                cout << "\n>>>>>>>>>>>>>> Match-" << match << " <<<<<<<<<<<<<<" << endl;
                cout << "\nPlayer Name: " << temp->player_name << endl;
                cout << "\tJersey Number: " << temp->jersey_number << endl;
                cout << "\tGoal Figure: " << temp->goal << endl;
                cout << "\tRed Card Figure: " << temp->got_red_card << endl;
                cout << "\tYellow Card Figure: " << temp->got_yellow_card << endl;
                cout << "\tPass accuracy: " << temp->pass_accuracy << endl;

                break;
            }

            temp = temp->link;
        }
    }
}

// Update Player Info
void Football::edit(int match)
{
    char name[100];
    int number;

    cout << "\tEnter Player Name: ";
    cin >> name;
    cout << endl;

    cout << "\tEnter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp;

    if (match == 1)
    {
        temp = match_1;
    }
    else
    {
        temp = match_2;
    }

    if (temp == NULL)
    {
        cout << "\tThere is nothing to Edit" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                cout << "\tEnter Update Player Name: ";
                cin >> temp->player_name;
                cout << endl;

                cout << "\tEnter Update Jersey Number: ";
                cin >> temp->jersey_number;
                cout << endl;

                cout << "\tEnter Update Goal Figure: ";
                cin >> temp->goal;
                cout << endl;

                cout << "\tEnter Update Red Card Figure: ";
                cin >> temp->got_red_card;
                cout << endl;

                cout << "\tEnter Update Yellow Card Figure: ";
                cin >> temp->got_yellow_card;
                cout << endl;

                cout << "\tEnter The Update Percentage of Pass Accuracy: ";
                cin >> temp->pass_accuracy;
                cout << endl;

                break;
            }

            temp = temp->link;
        }
    }
}

// Delete Function to Remove a Player Info
void Football::delete_player(int match)
{
    char name[100];
    int number;

    cout << "\tEnter Player Name: ";
    cin >> name;
    cout << endl;

    cout << "\tEnter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp;

    if (match == 1)
    {
        temp = match_1;
    }
    else
    {
        temp = match_2;
    }

    if (temp == NULL)
    {
        cout << "\tNo Info available in Match-" << match << endl;
    }
    else
    {
        Node *previous = NULL;

        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                if (previous == NULL)
                {
                    // Removing the first node
                    if (match == 1)
                    {
                        match_1 = temp->link;
                    }
                    else
                    {
                        match_2 = temp->link;
                    }
                }
                else
                {
                    previous->link = temp->link;
                }

                delete temp;
                cout << "\tPlayer Deleted." << endl;
                return;
            }

            previous = temp;
            temp = temp->link;
        }

        cout << "\tPlayer not found in Match-" << match << endl;
    }
}

// Performance Function
void Football::performance()
{
    char name[100];
    int number;

    cout << "\tEnter Name: ";
    cin >> name;
    cout << endl;

    cout << "\tEnter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp1 = match_1;
    Node *temp2 = match_2;

    Node *playerInfo1 = NULL;
    Node *playerInfo2 = NULL;

    // Search for the player in Match 1
    while (temp1 != NULL)
    {
        if (strcmp(temp1->player_name, name) == 0 && temp1->jersey_number == number)
        {
            playerInfo1 = temp1;
            break;
        }
        temp1 = temp1->link;
    }

    // Search for the player in Match 2
    while (temp2 != NULL)
    {
        if (strcmp(temp2->player_name, name) == 0 && temp2->jersey_number == number)
        {
            playerInfo2 = temp2;
            break;
        }
        temp2 = temp2->link;
    }

    // Display the result
    cout << "-------------------------------------------Result--------------------------------------------------" << endl;
    cout << endl;

    if (playerInfo1 != NULL)
    {
        cout << "\tDetails for Match 1:" << endl;
        cout << "\tPlayer Name: " << playerInfo1->player_name << endl;
        cout << "\tJersey Number: " << playerInfo1->jersey_number << endl;
        cout << "\tGoal Figure: " << playerInfo1->goal << endl;
        cout << "\tRed Card Figure: " << playerInfo1->got_red_card << endl;
        cout << "\tYellow Card Figure: " << playerInfo1->got_yellow_card << endl;
        cout << "\tPass accuracy: " << playerInfo1->pass_accuracy << endl;
        cout << endl;
    }
    else
    {
        cout << "\tPlayer not found in Match 1." << endl;
    }

    if (playerInfo2 != NULL)
    {
        cout << "\tDetails for Match 2:" << endl;
        cout << "\tPlayer Name: " << playerInfo2->player_name << endl;
        cout << "\tJersey Number: " << playerInfo2->jersey_number << endl;
        cout << "\tGoal Figure: " << playerInfo2->goal << endl;
        cout << "\tRed Card Figure: " << playerInfo2->got_red_card << endl;
        cout << "\tYellow Card Figure: " << playerInfo2->got_yellow_card << endl;
        cout << "\tPass accuracy: " << playerInfo2->pass_accuracy << endl;
        cout << endl;
    }
    else
    {
        cout << "\tPlayer not found in Match 2." << endl;
    }
}

// Function to get the middle node of a linked list
Node *Football::getMiddle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head->link;

    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
}

// Function to combine players from both matches into a single list
void Football::combineMatches(Node *match1, Node *match2, Node *&combinedList)
{
    Node *temp = NULL;
    while (match1 != NULL)
    {
        temp = match1->link;
        match1->link = combinedList;
        combinedList = match1;
        match1 = temp;
    }

    while (match2 != NULL)
    {
        temp = match2->link;
        match2->link = combinedList;
        combinedList = match2;
        match2 = temp;
    }
}

// Function to display the sorted list of players
void Football::displaySortedPlayers(Node *head)
{
    cout << "\tPlayers sorted based on highest scorer (total goals):" << endl;

    Node *current = head;
    while (current != NULL)
    {
        cout << "\tPlayer Name: " << current->player_name << endl;
        cout << "\tJersey Number: " << current->jersey_number << endl;
        cout << "\tTotal Goals: " << current->goal << endl;
        cout << "------------------------" << endl;

        current = current->link;
    }
}

void Football::merge(Node *&head, Node *left, Node *right)
{
    Node mergedList;
    Node *current = &mergedList;

    while (left != NULL && right != NULL)
    {
        if (left->goal >= right->goal)
        {
            current->link = left;
            left = left->link;
        }
        else
        {
            current->link = right;
            right = right->link;
        }
        current = current->link;
    }

    if (left != NULL)
    {
        current->link = left;
    }
    else
    {
        current->link = right;
    }

    head = mergedList.link;
}

void Football::mergeSort(Node *&head)
{
    if (head == NULL || head->link == NULL)
    {
        return;
    }

    Node *middle = getMiddle(head);
    Node *nextToMiddle = middle->link;

    middle->link = NULL;

    mergeSort(head);
    mergeSort(nextToMiddle);

    merge(head, head, nextToMiddle);
}

void Football::sortPlayersByGoals()
{
    Node *combinedList = NULL;

    // Combine players from both matches into a single list
    combineMatches(match_1, match_2, combinedList);

    // Apply merge sort to sort the list by total goals in descending order
    mergeSort(combinedList);

    // Display the sorted list
    displaySortedPlayers(combinedList);
}

void Football::getBest11Players()
{
    Node *combinedList = NULL;
    combineMatches(match_1, match_2, combinedList);

    // Apply merge sort to sort the list by total goals in descending order
    mergeSort(combinedList);

    // Display the best 11 players
    Node *current = combinedList;
    int count = 0;

    cout << "========================= Best 11 Players =========================" << endl;
    while (current != NULL && count < 11)
    {
        cout << "\tPlayer Name: " << current->player_name << endl;
        cout << "\tJersey Number: " << current->jersey_number << endl;
        cout << "\tTotal Goals: " << current->goal << endl;
        cout << "------------------------" << endl;

        current = current->link;
        count++;
    }
}

bool isIntegerNumber(string &str)
{
    std::string::const_iterator it = str.begin();
    int minSize = 0;
    if (str.size() > 0 && (str[0] == '-' || str[0] == '+'))
    {
        it++;
        minSize++;
    }
    while (it != str.end() && std::isdigit(*it))
        ++it;
    return str.size() > minSize && it == str.end();
}

int main()
{
    Football match;

    int choice = 0;
    cout << "\t\t-------------------------------------------" << endl;
    cout << "\t\t|         Football Players System         |" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    while (choice != 10)
    {

        cout << endl;
        cout << "\t\t\t    ---------------------" << endl;
        cout << "\t\t\t    |     Main Menu     |" << endl;
        cout << "\t\t\t    ---------------------" << endl;
        cout << endl;
        cout << "\t1. Add Player Info." << endl;
        cout << "\t2. Display Match 1 Info." << endl;
        cout << "\t3. Display Match 2 Info." << endl;
        cout << "\t4. Search Specific Player Info." << endl;
        cout << "\t5. Performance of Specific Player." << endl;
        cout << "\t6. Edit Specific Player Info." << endl;
        cout << "\t7. Highest Scorer." << endl;
        cout << "\t9. Select Best 11 Players" << endl;
        cout << "\t8. Delete Specific Player Info." << endl;
        cout << "\t10. Exit" << endl;
        cout << endl;
        cout << "\tEnter your choice: ";
        string input;
        cin >> input;
        cout << endl;

        if (isIntegerNumber(input))
        {
            // Convert the input to an integer
            choice = stoi(input);

            switch (choice)
            {
            case 1:
            {
                int matchNumber;
                cout << "\tEnter Match Number (1 or 2): ";
                cin >> matchNumber;

                if (matchNumber != 1 && matchNumber != 2)
                {
                    cout << "\tInvalid match number. Please enter either 1 or 2." << endl;
                    break;
                }

                match.player_info_add(matchNumber);
                break;
            }
            case 2:
                match.show(1);
                break;
            case 3:
                match.show(2);
                break;
            case 4:
            {
                int matchNumber;
                cout << "\tEnter Match Number (1 or 2): ";
                cin >> matchNumber;

                if (matchNumber != 1 && matchNumber != 2)
                {
                    cout << "\tInvalid match number. Please enter either 1 or 2." << endl;
                    break;
                }

                match.search_player(matchNumber);
                break;
            }
            case 5:
                match.performance();
                break;
            case 6:
            {
                int matchNumber;
                cout << "\tEnter Match Number (1 or 2): ";
                cin >> matchNumber;

                if (matchNumber != 1 && matchNumber != 2)
                {
                    cout << "\tInvalid match number. Please enter either 1 or 2." << endl;
                    break;
                }

                match.edit(matchNumber);
                break;
            }
            case 7:
                match.sortPlayersByGoals();
                break;
            case 8:
            {
                int matchNumber;
                cout << "\tEnter Match Number (1 or 2): ";
                cin >> matchNumber;

                if (matchNumber != 1 && matchNumber != 2)
                {
                    cout << "\tInvalid match number. Please enter either 1 or 2." << endl;
                    break;
                }

                match.delete_player(matchNumber);
                break;
            }
            case 9:
                match.getBest11Players();
                break;
            case 10:
                cout << "********************* Exit Completed ******************" << endl;
                break;
            default:
                cout << "\tPlease Enter a valid choice." << endl;
                break;
            }
        }
        else
        {
            cout << "\tInvalid input. Please enter a valid integer." << endl;
            // Clear the input buffer to prevent an infinite loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
