#include<iostream>
using namespace std;

class pokemons{
    int power;
    string pokamon;

    public:
    pokemons(){
        cout << "default constructor!";
    }
    pokemons(int p){
        power = p;
    }
    int powers(int p){
        return p;
    }
};

int main(){
    pokemons ash;
    cout << ash.powers(10);
    // pokemons misty(78);
}