#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>

using namespace std;

int T, ans;
int N, num[13];
vector<int> op;
int maximum, minimum;

void solve() {
    sort(op.begin(), op.end());
    do {
        int result = num[1];
        for (int i = 2; i <= N; i++) {
            if (op[i - 2] == 1) result += num[i];
            else if (op[i - 2] == 2) result -= num[i];
            else if (op[i - 2] == 3) result *= num[i];
            else if (op[i - 2] == 4) result /= num[i];
        }
        maximum = max(maximum, result);
        minimum = min(minimum, result);
    } while (next_permutation(op.begin(), op.end()));
    ans = maximum - minimum;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        ans = 0, maximum = INT_MIN, minimum = INT_MAX, op.clear();
        int tmp;
        for (int i = 1; i <= 4; i++) {
            cin >> tmp;
            for (int j = 0; j < tmp; j++) op.push_back(i);
        }
        for (int i = 1; i <= N; i++) cin >> num[i];
        solve();
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
