#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s="1234"; 
    int n = s.length();
    int cnt = 0;
    vector<string>ans;

    for (int i = 0; i < (1 << n); i++) { 
        string sub = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { 
                sub += s[j]; 
            }
        }
        if (sub.length() > 0) {
			ans.push_back(sub);
		}
    }
        for (auto num : ans) {
            int number = stoi(num);
            if(number % 2 == 0){
                cout << number << "";
                cout << endl;
            }
        }
}