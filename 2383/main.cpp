#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int T, ans;
int N, map[11][11];
pair<int, int> A, B;
int tim[2];
int path[3][11];
int t[11];

void getBinary(int current, int num) {
    int curr = current-1;
    while(num > 0) {
        t[curr--] = num % 2;
        num /= 2;
    }
}

int getSum(int current){
    int sum = 0;
    vector<int> tmp[2];
    queue<int> s[2];
    for(int i = 1; i < current; i++) {
        if (t[i] == 0) tmp[0].push_back(path[t[i] + 1][i]);
        else tmp[1].push_back(path[t[i] + 1][i]);
    }

    for(int num = 0; num < 2; num++) {
        int tsum = 0;
        int i;
        sort(tmp[num].begin(), tmp[num].end());
        if (tmp[num].size() == 0) continue;
        if (tmp[num].size() > 3) {
            for (i = 1;; i++) {
                for (int j = 0; j < tmp[num].size(); j++) {
                    if (tmp[num][j] > 0) {
                        tmp[num][j]--;
                        if (tmp[num][j] == 0){
                            if(s[num].size() != 3) s[num].push(tim[num] + i - 1);
                            else tmp[num][j]++;
                        }
                    }
                }
                while(s[num].size() > 0 && i == s[num].front()) s[num].pop();
                if (tmp[num][tmp[num].size() - 1] == 0) break;
            }
            tsum = i + tim[num] + 1;
        } else tsum = tmp[num][tmp[num].size() - 1] + tim[num] + 1;
        while(s[num].size() > 1) s[num].pop();
        sum = max(sum, tsum);
    }
    return sum;
}

void solution(){
    int current = 1;
    int total = INT_MAX;;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 1){
                path[1][current] = abs(i-A.first) + abs(j - A.second);
                path[2][current] = abs(i-B.first) + abs(j - B.second);
                current++;
            }
        }
    }
    for(int i = 0; i < pow(2,current-1); i++) {
        memset(t, 0, sizeof(t));
        getBinary(current, i);
        total = min(total, getSum(current));
    }
    ans = total;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= 10; test_case++) {
        cin >> N;
        A.first = 0;
        ans = numeric_limits<int>::max();
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cin >> map[i][j];
                if(map[i][j] >= 2){
                    if(A.first == 0){
                        A = {i, j};
                        tim[0] = map[i][j];
                    }
                    else{
                        B = {i, j};
                        tim[1] = map[i][j];
                    }
                }
            }
        }
        solution();
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
