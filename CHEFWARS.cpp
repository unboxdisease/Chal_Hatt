// Solution to CHEFWARS on CodeChef by DarthSid1603

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

#define ordered_set tree<lld, null_type,less<lld>, rb_tree_tag,tree_order_statistics_node_update>

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

lld nCrModp(lld n, lld r, lld p)
{
    if (r > n - r)
        r = n - r;
    lld C[r + 1]={0};
    C[0] = 1;

    for (lld i = 1; i <= n; i++)
    {
      for (lld j = min(i, r); j > 0; j--)
      {
        C[j] = (C[j] + C[j - 1]) % p;

      }
    }
    return C[r];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  lld t;
  cin>>t;
  while(t--)
  {
    lld h,p;
    cin>>h>>p;
    while(h>0 && p>0)
    {
      h = h - p;
      p = p/2;
    }
    if(h>0)
      cout<<0<<endl;
    else
      cout<<1<<endl;
  }

}
