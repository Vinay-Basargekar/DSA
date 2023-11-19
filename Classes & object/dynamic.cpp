#include <iostream>
using namespace std;

class pokemons{
    string pokemon;
    int power;

public:
    // Function to set the power and return it
    int powers(int p){
        power = p;
        return power;
    }

    // Function to set the Pokemon name and display it
    void pokemoni(string s){
        pokemon = s;
        cout << "Pokemon is " << pokemon;
    }
};

int main()
{
    // STATIC ALLOCATION OF AN OBJECT (memory allocated at compile time)
    pokemons ash;
    ash.pokemoni("pikachu");   // Set the Pokemon name for Ash
    cout << " Of power " << ash.powers(80) << endl;// Set and display Ash's power

    // DYNAMIC ALLOCATION OF AN OBJECT(memory allocated at runtime)
    pokemons *misty = new pokemons;
    (*misty).pokemoni("Togepi"); // Set the Pokemon name for Misty
    cout << " Of power " << (*misty).powers(75) << endl; // Set and display Misty's power

    pokemons *Brook = new pokemons;
    Brook->pokemoni("Golem");   // Set the Pokemon name for Brook
    cout << " Of power " << Brook->powers(85) << endl; // Set and display Brook's power

    delete misty; // Release the memory allocated dynamically for Misty's object
    delete Brook; // Release the memory allocated dynamically for Brook's object

    return 0;
}
