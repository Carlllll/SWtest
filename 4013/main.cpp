#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, ans;
int K, w[5][9], rt[21][3];
bool tmp[4], visited[5];

void onerot(int num, int d){
    if(d == 1){
        int tmp = w[num][8];
        for(int i = 7; i >= 1; i--) w[num][i+1] = w[num][i];
        w[num][1] = tmp;
    } else {
        int tmp = w[num][1];
        for(int i = 1; i <= 8; i++) w[num][i] = w[num][i+1];
        w[num][8] = tmp;
    }
}

void allrot(int num, int d){
    //no more
    if(num < 1 || num > 4 || visited[num]) return;
    //next
    onerot(num, d);
    visited[num] = true;

    if(tmp[num]) allrot(num + 1, -(d));
    if(tmp[num-1]) allrot(num - 1, -(d));
}

void solve(){
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= 3; j++) tmp[j] = (w[j][3] != w[j+1][7]);
        for(int j = 1; j <= 4; j++) visited[j] = false;
        allrot(rt[i][1], rt[i][2]);
    }
    ans = w[1][1] + 2*w[2][1] + 4*w[3][1] + 8*w[4][1];
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> K;
        for(int i = 1; i <= 4; i++) for(int j = 1; j <= 8; j++) cin >> w[i][j];
        for(int i = 1; i <= K; i++) cin >> rt[i][1] >> rt[i][2];
        solve();
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
