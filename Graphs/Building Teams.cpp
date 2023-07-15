/*
    Sourav Kumar Dubey
*/
 
#include <bits/stdc++.h>
using namespace std;

#define lli               long long int
#define forn(i,x,n)       for (i = x; i <= n; i++)
#define rev(n,i)          for(i=N-1;i>=0;i--)
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define out(x)            cout << x
#define fr                first
#define sc                second
#define pb                push_back
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define google           cout << "Case #" << test << ": ";
 
const long long INF=1e18;
const long long int mod=1e9+7;
const int32_t MM=998244353;
const long long inf = 1e18;

lli power(lli x, lli n) {
    lli res = 1;
    
    while (n > 0) {
        
        if (n & 1) res = (res * x) % mod ;
        x = (x * x) % mod;
        n >>= 1;
 
    }
    
    return res;
}

lli mod_inverse(lli x) {

    return power(x, mod - 2);

}

lli lengthOfLIS(vector<lli>& nums) {
    int n = nums.size();
    set<int> se;
    int flag = 0;
    for(int i = 0; i<n; ++i){
        if(se.lower_bound(nums[i]) != se.end()){
            se.erase(se.lower_bound(nums[i]));
        }
        se.insert(nums[i]);
    }
    return se.size() ;
}

lli getGCD(lli a, lli b) {

    if ( b == 0 ) return a;

    return getGCD(b, a % b);

}

lli getLCM(lli a, lli b) {

    return (a / getGCD(a, b)) * b;

}

bool isCoPrime(lli a, lli b) {

    if ( getGCD(a, b) == 1 ) return true;
    else return false;

}

bool isPerfectSquare(lli num)
{
    int64_t n = num;
    int64_t lo = 1;
    int64_t hi = num;
    while (hi - lo > 1) {
        int64_t mid = (hi + lo) / 2;
        if (num == 1) {
            return true;
        }
        else if (mid * mid == num) {
            return true;
        }
        else if (mid * mid > num) {
            hi = mid - 1;
        }
        else if (mid * mid < num) {
            lo = mid + 1;
        }
    }
    if (lo * lo == num || hi * hi == num) {
        return true;
    }
    return false;
}

lli digitSum(lli n) {

    lli sum = 0;

    while (n > 0) {

        sum += n % 10;
        n /= 10;

    }

    return sum;

}
 
lli getCubeRoot(lli n) { return ceil(cbrt(n)); }

//------------------------------------------------------------------------------
 
void insert (vector < lli > &vec, lli n) { for (int i = 0; i < n; i++) cin >> vec[i]; }

void print (vector < lli > &vec , lli n) {
    
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << "\n";
    
}

bool isPrime(lli n) {
    
    for (int i = 2; i <= sqrt(n); i++) {
        
        if ( n % i ) continue;
        return false;
        
    }
    
    return true;
    
}

bool isSubsequence(string s, string t) {
    
    int i = 0;
    
    for (auto j : t) {
        
        if (s[i] == j) i += 1;
        if (i == s.size()) return true;
        
    }
    
    return (i == s.size());
    
}

bool isPowerOfTwo (lli n) { return ppc(n) == 1; }

lli getMEX(vector < lli > vec) {
    
    sort(all(vec));
    int mex = 0;
    
    for (auto& e: vec) {
        
        if (e == mex) mex += 1;
        
    }
    
    return mex;
    
}

bool isPalin (string n) {
    
    string s = n;
    string s2 = s;
    reverse(all(s2));
    return s == s2;
    
}
            
bool isVowel(char ch) { return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); }

vector < vector < lli > > adj;
vector < bool > vis;
vector < lli > team;
lli n, m;
bool isPossible;

void dfs(int parent) {

    vis[parent] = true;

    for (auto child: adj[parent]) {

        if (!vis[child]) {

            vis[child] = true;
            team[child] = !team[parent];
            dfs(child);

        } else {

            if (team[child] == team[parent]) {
                
                isPossible = false; 
                return;

            }

        }

    }

}

void test_case() {

    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {

        lli u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vis.resize(n + 5);
    team.resize(n + 5);
    
    isPossible = true;
    for (int i = 0; i < n; i++) {

        if (!vis[i]) {

            vis[i] = true;
            dfs(i);

        }

    }

    if (!isPossible) cout << "IMPOSSIBLE\n";
    else {

        for (int i = 1; i <= n; i++) cout << team[i] + 1 << " ";
        cout << "\n";

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t = 1;  
    // cin >> t;
    
    for ( int test = 1 ; test <= t ; test += 1 ) {
        
        // google;
        test_case();
      
    }
    return 0;
}