#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int tickets[5];
int months[13];
int dp[13];

void solutionIter(){
    dp[1] = min(tickets[1]*months[1], tickets[2]);
    dp[2] = min(dp[1] + tickets[1]*months[2], dp[1] + tickets[2]);
    dp[3] = min(dp[2] + tickets[1]*months[3], min(dp[2] + tickets[2], tickets[3]));

    for(int i = 4; i < 13; i++){
        dp[i] = min(dp[i-1]+tickets[1]*months[i], min(dp[i-1]+tickets[2], dp[i-3]+tickets[3]));
    }
    dp[12] = min(dp[12], tickets[4]);
}

int solutionRecur(int i){
    if(i < 1) return 0;
    if(dp[i] != 0) return dp[i];
    else{
        dp[i] = min(solutionRecur(i - 1) + tickets[1]*months[i],
                    min(solutionRecur(i - 1)+tickets[2], solutionRecur(i - 3)+tickets[3]));
        return dp[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        for(int i = 1; i < 5; i++) cin >> tickets[i];
        for(int i = 1; i < 13; i++) cin >> months[i];
        fill_n(dp, 13, 0);
//        cout << "#" << test_case <<  " " << min(solutionRecur(12), tickets[4]) << endl;
        solutionIter();
        cout << "#" << test_case <<  " " << dp[12] << endl;
    }
    return 0;
}
