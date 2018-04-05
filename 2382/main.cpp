#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T, ans;
int N, K, M;
int mi[5] = {0, -1, 1, 0, 0};
int mj[5] = {0, 0, 0, -1, 1};
int map[1001][1001];
int maxmap[1001][1001];
vector<pair<pair<int,int>, pair<int,int>>> v;
//v.first.first = i
//v.first.second = j
//v.second.first = 미생물 수
//v.second.second = 방향


void solution(){
    for(int t = 1; t <= M; t++) {
        memset(map, 0, sizeof(map));
        memset(maxmap, 0, sizeof(maxmap));
        //move
        for (int i = 1; i < v.size(); i++) {
            int mm = v[i].second.second;
            v[i].first.first += mi[mm];
            v[i].first.second += mj[mm];
            int ii = v[i].first.first;
            int jj = v[i].first.second;
            int kk = v[i].second.first;

            //빨간 영역 도달
            if(ii == 0 || jj == 0 || ii == N-1 || jj == N-1) {
                //방향 변경
                if(mm % 2 == 0) v[i].second.second--;
                else v[i].second.second++;
                //미생물 반으로 감소
                v[i].second.first /= 2;
                //반 죽었는데 0이면 없어짐
                if(v[i].second.first == 0){
                    v.erase(v.begin()+i, v.begin()+i+1);
                    i--;
                }
                map[ii][jj] = i;
            }
                //안전지역 도달
            else {
                //겹친다면 미생물 수 큰거로 바꾸고 방향도 바꿈
                if (maxmap[ii][jj] > 0) {
                    //원래거가 클때
                    if (maxmap[ii][jj] > kk) {
                        v[map[ii][jj]].second.first += kk;
                        v.erase(v.begin() + i, v.begin() + i + 1);
                    } else { //새로운 게 클때
                        v[i].second.first += v[map[ii][jj]].second.first;
                        v.erase(v.begin() + map[ii][jj], v.begin() + map[ii][jj] + 1);
                        map[ii][jj] = i-1;
                        maxmap[ii][jj] = kk;
                    }
                    i--;
                }
                //안 겹칠 때
                else{
                    map[ii][jj] = i;
                    maxmap[ii][jj] = kk;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= 10; test_case++) {
        int tmp[4];
        ans = 0;
        v.clear();
        v.push_back({{0, 0},{0, 0}});
        cin >> N >> M >> K;
        for(int i = 1; i <= K; i++){
            cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
            v.push_back({{tmp[0], tmp[1]}, {tmp[2], tmp[3]}});
        }
        solution();
        for (int i = 1; i < v.size(); i++) ans += v[i].second.first;
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
