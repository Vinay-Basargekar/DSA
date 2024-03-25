#include <iostream>
#include <utility>

using namespace std;

int main() {
    pair<int,int> p(1,2);
    cout << p.first << " " << p.second << endl;

    pair<int,pair<int,int> > pp(1, make_pair(2,3));
    cout << pp.first << " " << pp.second.second << endl;
    return 0;
}
