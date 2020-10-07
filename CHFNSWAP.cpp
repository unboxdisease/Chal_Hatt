// Answer to Chefina and Swaps on Codechef by DarthSid1603


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define mk make_pair
#define pb push_back

typedef long long lld;
typedef pair<lld,lld> pr;
typedef priority_queue <lld> max_heap;
typedef priority_queue <lld, vector<lld>, greater<lld> > min_heap;
lld const mod = 1e9+7;
lld const N = 1e5+5;
#define ordered_set tree<lld, null_type,less<lld>, rb_tree_tag,tree_order_statistics_node_update>

lld fact[N], ifact[N];

lld power(lld x, lld y)
{
    lld res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

lld power_mod(lld base, lld y)
{
    lld t = 1;
    while (y > 0)
    {

        if (y % 2 != 0)
            t = (t * base) % mod;
        base = (base * base) % mod;
        y /= 2;
    }
    return t % mod;
}

void findFact() {
    fact[0] = 1;
    for(lld i = 1; i <= N; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    ifact[N] = power_mod(fact[N], mod - 2);
    for(lld i = N - 1; i >= 0; i--)
        ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
}

lld comb(lld n, lld r) {
    return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}


lld gcd(lld a, lld b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  lld t;
  cin>>t;
  while(t--)
  {
    lld n;
    cin>>n;
    lld sum = n*(n+1)/2;

    if(sum%2!=0)
    {
      cout<<0<<endl;
      continue;
    }
    else
    {
      lld a,b;
      a = (-1 + sqrt(1+2*n*(n+1)))/2;
      b = a+1;
      if(b*(b+1)/2 <= n*(n+1)/4)
      {
        a++;
      }
      lld diff = n*(n+1)/4 - a*(a+1)/2;
      lld cnt = n-a;
      // cout<<a<<endl;
      // cout<<"diff = "<<diff<<endl;
      if(diff==0)
      {
        cnt += a*(a-1)/2 + (n-a)*(n-a-1)/2;
      }
      cout<<cnt<<endl;


    }



  }

}
