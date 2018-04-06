#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int T, ans;
int N, M, K, A, B;
int ai[11], bi[11], timeA[11], timeB[11];
int current, passedA, passedB;
pair<int, int> k[1001];
queue<int> q;
queue<pair<int, int>> kq;

int available(int tmp[], int size){
    for(int i = 1; i <= size; i++)
        if(tmp[i] == 0) return i;
    return -1;
}

bool isempty(int tmp[], int size){
    for(int i = 1; i <= size; i++)
        if(tmp[i] != 0) return false;
    return true;
}

void solution(){
    current = 1;
    passedA = 0;
    passedB = 0;
    sort(k, k+K);
    for(int t = 0; ; t++){
        //no more
        if(current > K && q.empty() && isempty(timeA, N) && isempty(timeB, M)) break;

        //bi[] -> done
        for(int i = 1; i <= M; i++)
            if(timeB[i] > 0) timeB[i]--;

        //ai[] -> bi[]
        for(int i = 1; i <= N; i++){
            if(timeA[i] > 0){
                timeA[i]--;
                if(timeA[i] == 0){
                    if(i == A) q.push(passedA);
                    else q.push(0);
                }
            }
        }

        //queue -> bi[]
        while(!q.empty()){
            int tmp = available(timeB, M);
            if(tmp != -1){
                if(q.front() != 0 && tmp == B){
                    passedB += q.front();
//                    cout << "added : " << q.front() << endl;
                }
                timeB[tmp] = bi[tmp];
                q.pop();
            } else break;
        }

        //k[] -> kq
        for(int i = 1; i <= K; i++)
            if(t == k[i].first) kq.push(k[i]);

        //k[] -> ai[]
        while(!kq.empty()){
            int tmp = available(timeA, N);
            if(tmp != -1){
                if(tmp == A){
                    passedA = kq.front().second;
//                    cout << "added : " << q.front() << endl;
                }
                timeA[tmp] = ai[tmp];
                kq.pop();
                current++;
            } else break;
        }

//        for(int i = current; i <= K; i++){
//            if(k[i].first > t) break;
//            int tmp = available(timeA, N);
//            if(tmp != -1){
//                if(tmp == A) passedA = current;
//                timeA[tmp] = ai[tmp];
//                current++;
//            }
//        }
//        cout << "t:" << t << " // " << "current:" << current << " ";
//        for(int i = 1; i <= N; i++) cout << "A:" << timeA[i] << " ";
//        cout << " / ";
//        for(int i = 1; i <= M; i++) cout << "B:" << timeB[i] << " ";
//        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= 10; test_case++) {
        ans = -1;
        cin >> N >> M >> K >> A >> B;
        for(int i = 1; i <= N; i++) cin >> ai[i];
        for(int i = 1; i <= M; i++) cin >> bi[i];
        for(int i = 1; i <= K; i++) {
            cin >> k[i].first;
            k[i].second = i;
        }
        solution();
        ans = (passedB == 0) ? -1 : passedB;
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}