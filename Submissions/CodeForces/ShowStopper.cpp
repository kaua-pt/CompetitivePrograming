#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n,x;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        v2.push_back(x);
    }
    

}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int ans = solve();
        ans == 1 ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}