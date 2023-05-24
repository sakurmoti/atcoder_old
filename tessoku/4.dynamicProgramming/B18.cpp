#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    //dp[i][j]をカードiまでを選んで合計をjにできるかどうか
    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    dp[0][0] = true; //0枚選ぶと合計0にできる

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= S; j++){
            if(j==0) dp[i][j] = true;

            //i番目のカードを選ぶ場合
            if(i > 0 && j-A[i] >= 0 && dp[i-1][j-A[i]] == true) dp[i][j] = true;

            //i番目のカードを選ばない場合
            if(i > 0 && dp[i-1][j] == true) dp[i][j] = true;
        }
    }

    //ここまでA18と全く同じ

    if(dp[N][S] == true){
        //dpの復元
        vector<int> ans;
        int j = S;
        for(int i = N; i > 0; i--){
            if(dp[i-1][j] == true){
                //カードiを選んでいない
                continue;
            
            }else{
                //カードiを選んでいる
                j = j-A[i];
                ans.push_back(i);
            }
        }

        reverse(ans.begin(), ans.end());
        
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans.at(i) << " ";
        }

    }else{
        cout << "-1" << endl;

    }
    return 0;
}