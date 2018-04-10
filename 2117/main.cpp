#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, ans;
int N, M;
int map[21][21], num, limit;

bool inner(int i, int j){
    return i > 0 && i <= N && j > 0 && j <= N;
}

int manage(int k){
    return k*k + (k-1)*(k-1);
}

void solve(int ci, int cj, int k, int num){
    //not
    if(manage(k) > limit) return;

    //ans
    if(manage(k) <= M*num) ans = max(ans, num);

    //next
    if(inner(ci-k, cj)) num += map[ci-k][cj];
    if(inner(ci+k, cj)) num += map[ci+k][cj];

    for(int i = 1; i <= k; i++){
        if(inner(ci-k+i, cj+i)) num += map[ci-k+i][cj+i];
        if(inner(ci-k+i, cj-i)) num += map[ci-k+i][cj-i];
    }
    for(int i = 1; i < k; i++){
        if(inner(ci+k-i, cj+i)) num += map[ci+k-i][cj+i];
        if(inner(ci+k-i, cj-i)) num += map[ci+k-i][cj-i];
    }
    solve(ci, cj, k + 1, num);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        ans = 0, num = 0;
        cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> map[i][j];
                if(map[i][j] == 1) num++;
            }
        }
        limit = M * num;
        for(int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                solve(i, j, 1, map[i][j]);
            }
        }
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
