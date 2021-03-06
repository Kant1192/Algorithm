#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

int main(){
    int H, N; cin >> H >> N;
    vector<int> a(N), b(N);
    vector<pair<int, int>> vp(N);
    for (int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
        vp[i] = {b[i], a[i]};
    }
    sort(vp.begin(), vp.end());

    int Cost[101000];
    fill(Cost, Cost+10100, MM);
    Cost[0] = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10001; j++){
            if (j < vp[i].second){
                Cost[j] = min(Cost[j], vp[i].first);
            }
            if (j + vp[i].second > 20000){
                break;
            }
            Cost[j+vp[i].second] = min(Cost[j+vp[i].second], Cost[j] + vp[i].first);
        }
    }
    cout << Cost[H] << endl;
}