/*このようなdpを組み立てるには(kyopro-friendsさんより引用)
・発想１：制約を見る
この問題で考えるべきものは「何番目の品物まで使ったか」「価値はいくらか」「重さはいくらか」の3つなのだ。制約を考えると、状態として持てるのは多くても前の2つだけなのだ。だから
dp[何番目][価値]=(i番目までの品物を、価値に関するなんらかの条件を満たすように選んだときの重さに関するなにか)
という形にするしかないのだ。あとは頑張って考えるのだ！
・発想２：boolのDP
まずはさっき言った「考えるべきもの3つ」を全部状態に持つDPを考えてみるのだ。
dp[i][j][k]=(i番目までの品物を、価値がj、重さがkとなるように選べるか？)
ここで「『はい』か『いいえ』を値に持つようなDPは、添字を1つ選んで「～が『はい』になる〇〇の最小値(最大値)」という形に書き直せることが多い」というテクニックを使うと、思いつけるのだ！
・発想３：添字の入れ替え
「～となる〇〇の最大値」を値に持つDPは、適当な添字と入れ替えて「～となる××の最小値」というDPにできることが多いのだ！
D問題の解法にこれを使えば思いつけるのだ！
これは発想２の考え方「～となる○○の最大値」→「～とできるか？」→「～となる××の最小値」の間を飛ばしたものとも言えるのだ。*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    vector<int> w(N+1),v(N+1); 
    for(int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }

    /*Knapsack1に比べ、Wが大きいのでO(NW)ではTLEする。
    そこでdp[i][j]を品物iまでのうち、価値がj以下で取れる重さの最小値とする
    最後にdp[N][j]をjが大きいところからみてW以下になればそのjが答えとなる
    dp[i+1][j]はi+1を取るときdp[i][j-v[i+1]] + w[i+1]
    取らない時dp[i+1][j] = dp[i][j]
    */
    vector<vector<long long>> dp(N+1, vector<long long>(1e+6,1e+18));//価値の最大はN*viなので10^5
    dp[0][0]=0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 1e5 +1; j++){

            if(j-v.at(i+1) >= 0){
                dp.at(i+1).at(j)
                = min(dp.at(i).at(j), dp.at(i).at(j-v.at(i+1)) + w.at(i+1));

            }else{
                dp.at(i+1).at(j) = dp.at(i).at(j);

            }

        }
    }

    int ans = 1e5;
    while(dp[N][ans] > W) ans--;

    cout << ans << endl;

    return 0;
}