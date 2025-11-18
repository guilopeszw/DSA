#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> getPairs(const vector<int> nums) {
    vector<int> pairs;

    for (int i = 0; i < nums.size(); i++) {
        
        if (nums[i] % 2 == 0) {
            pairs.push_back(nums[i]);
        }
        else {
            continue;
        }
    }
    return pairs;
}

vector<int> populateVector() {
    vector<int> nums;
    for (int i = 0; i < 15; i++) {
        nums.push_back(rand() % 101);
    }
    return nums;
}

int main() {
    vector<int> nums = populateVector();
    vector<int> pairs = getPairs(nums);

    cout << "Nums: \n";
    for (int n : nums) cout << n << " ";

    cout << "Pares: \n";
    for (int p : pairs) cout << p << " ";
}