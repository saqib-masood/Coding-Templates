#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> O(N);
    for (int i = 0; i < N; i++) {
        cin >> O[i];
    }

    int T;
    cin >> T;

    vector<int> prefixAnd(N);
    prefixAnd[0] = O[0];
    for (int i = 1; i < N; i++) {
        prefixAnd[i] = prefixAnd[i - 1] & O[i];
    }

    stack<int> s;
    int minDiff = INT_MAX;
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && O[s.top()] < O[i]) {
            s.pop();
        }
        while (!s.empty() && (prefixAnd[i] & O[s.top()]) < T) {
            minDiff = min(minDiff, abs(prefixAnd[i] - (prefixAnd[s.top()]))); // Difference between current prefix AND value and prefix AND value at nearest greater element
            s.pop();
        }
        s.push(i);
    }

    cout << minDiff << endl;
    return 0;
}
