#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, m;
        cin >> n >> m; // Number of states initially and minimum literate people required in each state

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Initial count of literate people in each state
        }

        int max_states = 0; // To store the maximum number of states

        // Calculate the cumulative sum of literate people
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        }

        // Iterate through each state and find the maximum number of states that can be combined
        for (int i = 0; i < n; i++) {
            int required_literate_people = (i > 0) ? prefix_sum[i - 1] : 0;

            // Binary search to find the rightmost state that satisfies the condition
            int low = i, high = n - 1, result = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                int sum = prefix_sum[mid] - required_literate_people;

                if (sum >= m) {
                    result = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Update the maximum number of states
            max_states = max(max_states, result - i + 1);
        }

        cout << max_states << endl;
    }

    return 0;
}
