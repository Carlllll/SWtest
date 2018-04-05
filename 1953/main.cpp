#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int T, ans;
int N, M, R, C, L;
int map[51][51];
bool visited[51][51];
int mi[] = {-1, 1, 0, 0};
int mj[] = {0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;

void solve(int r, int c, int l){
    q.push({{r, c}, 1});
    visited[r][c] = true;
    while(!q.empty()){
        pair<pair<int, int>, int> current = q.front();
        q.pop();
        int ci = current.first.first;
        int cj = current.first.second;
        int ct = current.second;
        if(ct >= l) return;
        for(int i = 0; i < 4; i++){
            int ni = ci + mi[i];
            int nj = cj + mj[i];

            if(visited[ni][nj] || map[ni][nj] == 0 || ni < 0 || ni > N-1 || nj < 0 || nj > M-1) continue;

            int cm = map[ci][cj];
            int nm = map[ni][nj];

            //up
            if (i == 0) {
                if(cm == 3 || cm == 5 || cm == 6 || nm == 3 || nm == 4 || nm == 7) continue;
            }
            //down
            else if (i == 1) {
                if(cm == 3 || cm == 4 || cm == 7 || nm == 3 || nm == 5 || nm == 6) continue;
            }
            //left
            else if (i == 2) {
                if(cm == 2 || cm == 4 || cm == 5 || nm == 2 || nm == 6 || nm == 7) continue;
            }
            //right
            else {
                if(cm == 2 || cm == 6 || cm == 7 || nm == 2 || nm == 4 || nm == 5) continue;
            }
            q.push(make_pair(make_pair(ni, nj), ct + 1));
            visited[ni][nj] = true;
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        ans = 1;
        memset(visited, false, sizeof(visited));
        while(!q.empty()) q.pop();
        cin >> N >> M >> R >> C >> L;
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        solve(R, C, L);
        cout << "#" << test_case <<  " " << ans << endl;
    }
    return 0;
}
