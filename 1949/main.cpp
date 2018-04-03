#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, ans, n, k;
int top;
int topX[6], topY[6];
int map[9][9];
int mi[] = {0, 0, 0, -1, 1};
int mj[] = {0, 1, -1, 0, 0,};

void solution(){
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n >> k;
        top = 0;
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
                if(top < map[i][j]){
                    top = map[i][j];
                }
            }
        }
        cout << "#" << test_case <<  " " << ans << endl;
    }
    return 0;
}
