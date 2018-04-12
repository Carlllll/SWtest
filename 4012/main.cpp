#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>

using namespace std;

int T, ans;
int N, map[17][17];
bool visited[17];

void solution(int num, int cnt){
    //done
    if(num == N){
        int A = 0, B = 0;
        for(int i = 1; i<= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue;
                if(visited[i] && visited[j]) A += map[i][j];
                if(!visited[i] && !visited[j]) B += map[i][j];
            }
        }
        ans = min(ans, abs(A - B));
        return;
    }
    //add A
    if(cnt > 0) {
        visited[num + 1] = true;
        solution(num + 1, cnt - 1);
        visited[num + 1] = false;
    }
    //add B
    solution(num+1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        ans = INT_MAX;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cin >> map[i][j];
        solution(1, N/2);
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}