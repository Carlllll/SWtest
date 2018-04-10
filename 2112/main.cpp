#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T, ans;
int D, W, K;
int film[14][21];

bool checkLayer(int layer, int v){
    for(int i = 1; i <= W; i++){
        if(film[layer][i] == v) continue;
        else return false;
    }
    return true;
}

bool checkFilm(){
    int prev, check;
    for(int j = 1; j <= W; j++){
        //set prev
        prev = film[1][j]; check = 1;
        for(int i = 2; i <= D; i++){
            if(check == K) continue;
            if(prev != film[i][j]) {
                prev = film[i][j];
                check = 1;
            } else{
                check++;
            }
        }
        if(check < K) return false;
    }
    return true;
}

void solve(int layer, int value, int cnt){
    //answer
    if(checkFilm()){
        ans = min(ans, cnt);
        return;
    }

    //no more
    if(layer > D || cnt >= ans) return;

    //next
    int tmp[21];
    if(value != -1) {
        for (int i = 1; i <= W; i++) {
            tmp[i] = film[layer][i];
            film[layer][i] = value;
        }
    }

    solve(layer+1, -1, cnt);
    solve(layer+1, 0, cnt+1);
    solve(layer+1, 1, cnt+1);

    if(value != -1) {
        for (int i = 1; i <= W; i++) {
            film[layer][i] = tmp[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        ans = INT_MAX;
        cin >> D >> W >> K;

        for(int i = 1; i <= D; i++){
            for(int j = 1; j <= W; j++){
                cin >> film[i][j];
            }
        }

        solve(0, -1, 0);
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
