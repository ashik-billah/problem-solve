
#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
         int m = a.size();
    int minNew = 0;

    for (int i = 0; i < m; ++i) {
        if (a[i] > b[i]) {
            int d = a[i] - b[i];
            minNew = max(minNew, d);
            a[i] -= d;
        }
    }

        int result = minNew;
        cout << minNew << endl;
    }

    return 0;
}
