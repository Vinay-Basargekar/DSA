#include<iostream>
using namespace std;

class pokemons{
    
    string pokemon;
    int power;

    public:
    // int getpower(){
    //     return power;
    // }
    int Powers(int p){
        power = p;
        return power;
    }
};

int main(){
    pokemons ash;
    // ash.setpower(80);
    // ash.pokemon = "Pikachu";
    cout << "Power of ash is: " << ash.Powers(80) <<endl;
    // cout << "ash Pokemon is: " << ash.pokemon;
}