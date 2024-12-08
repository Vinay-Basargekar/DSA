#include <vector>
using namespace std;

class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> result;
        long long fact = 1;
        long long i = 1;
        
        // Generate all factorial numbers less than or equal to n
        while (fact <= n) {
            result.push_back(fact);
            i++;
            fact *= i; // Calculate the next factorial
        }
        
        return result;
    }
};
