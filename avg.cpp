#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rev(i,a,b) for(long long i=b-1;i>=a;i--)
#define loopi(i,a,b) for(int i=a;i<b;i++)
#define rep(t) int t;cin>>t;while(t--)
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) x.begin(),x.end()
int main()
{
    ll n;
    long double avg= 0.0 ;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        {cin>>arr[i];avg+=arr[i];}
        avg = avg/n;
        cout<<avg<<endl;
    return 0;
}

