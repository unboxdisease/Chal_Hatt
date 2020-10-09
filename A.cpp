#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,k;
        cin>>x>>y>>k;
        long long int ans = k*y + k - 1;
        int mod=0;
        if(ans%(x-1))
        {
            mod=1;
        }
        ans=ans/(x-1);
        ans=ans+mod;
        cout<<ans + k<< " "<<endl;
    }
    return 0;
}