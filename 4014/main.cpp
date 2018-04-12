#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, ans;
int N, X, map[21][21];

void solution() {
    //vertical
    int path, prev;
    bool ing;
    for (int i = 1; i <= N; i++) {
        path = 1, prev = map[i][1], ing = false;
        for (int j = 2; j <= N; j++) {
            //1이상 차이나면 다음줄로 넘어감
            if(abs(prev - map[i][j]) > 1){
                j = N+1, ing = true;
                continue;
            }
            //같을 때
            if(map[i][j] == prev){
                path++;
                if(path >= X && ing) ing = false, path = 0;
            }
            //1만큼 높아졌을 때
            else if(map[i][j] - prev == 1){
                if(X <= path) ing = false;
                else{
                    ing = true, j = N+1;
                    continue;
                }
                path = 1, prev = map[i][j];
            }
            //1만큼 낮아졌을 때
            else {
                if(ing){
                    j = N+1;
                    continue;
                }
                path = 1, prev = map[i][j], ing = true;
            }
        }
        if(!ing) ans++;
//        cout << "i : " << i << " => " << !ing << endl;
    }
//    cout << endl;

    //horizontal
    for (int j = 1; j <= N; j++) {
        path = 1, prev = map[1][j], ing = false;
        for (int i = 2; i <= N; i++) {
            //1이상 차이나면 다음줄로 넘어감
            if(abs(prev - map[i][j]) > 1){
                i = N+1, ing = true;
                continue;
            }

            //같을 때
            if(map[i][j] == prev){
                path++;
                if(path >= X && ing) ing = false, path = 1;
            }
            //1만큼 높아졌을 때
            else if(map[i][j] - prev == 1){
                if(X <= path) ing = false;
                else{
                    ing = true, i = N+1;
                    continue;
                }
                path = 1, prev = map[i][j];
            }
            //1만큼 낮아졌을 때
            else {
                if(ing){
                    i = N+1;
                    continue;
                }
                path = 1, prev = map[i][j], ing = true;
            }
        }
        if(!ing) ans++;
//        cout << "j : " << j << " => " << !ing << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        ans = 0;
        cin >> N >> X;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cin >> map[i][j];
        solution();
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
