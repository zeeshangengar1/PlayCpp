#include <bits/stdc++.h>
#define int long long int
#define f(n) for (int i = 0; i < n; i++)
#define loop(x, n) for (int x = 0; x < n; x++)
using namespace std;
int md = 1000000007;

void solve2() {
    int x = 8;
    f(78) {
        x+=i+1;
    }
}

void solve() {
    int x = 9;
    solve2();
    f(78) {
        x+=i+1;
    }
}

int32_t main() {
    int test;
    cin >> test;

    int stor[200001] = {0};
    for(int i=1; i<=200000; i++) {
        int temp=i;
    	while(temp%2==0){
    		temp/=2;
    		stor[i]++;
    	}
    }
    solve();
    while (test--) {
        int n;
        cin>>n;

        int arr[n];
        int prod = 1;
        int pow2=0;
        f(n) {
            cin>>arr[i];
            int t = arr[i];
            while(t%2==0) {
                pow2++;
                t/=2;
            }
        }

        if(pow2 >= n)
            cout<<0<<endl;
        else {
            solve();
            int rem=n-pow2;
            vector<int> ntem;
            for(int i=1;i<=n;i++){
                if(stor[i]>0) ntem.push_back(stor[i]);
            }
            sort(ntem.begin(), ntem.end(), greater<int>());
            int fines=0;
            for(auto i:ntem){
                if(rem>=i){
                    rem-=i;
                    fines++;
                }
            }
            if(rem==0) cout<<fines<<endl;
            else cout<<-1<<endl;
        }
    }

    return 0;
}