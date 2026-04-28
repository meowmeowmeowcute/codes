#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    auto it = lower_bound(v.begin(), v.end(), 30);
    
    cout << it-v.begin();
    cout << "         " << *it; 

    return 0;
}