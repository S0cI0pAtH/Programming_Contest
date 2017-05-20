// loj 1068
// how many numbers from A to B, that is divisible by k and sum of digits of that number also divisible by k

#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
/*************NOTES*********************\

***************************************/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll MAX = 1e7 + 20;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

inline const int EQ( double tmp ){ if( fabs( tmp ) < eps ) return 0; return tmp > eps ? 1 : -1;}
ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

vector< int > num;
bool vis[12][2][90][90];
ll dp[12][2][90][90];
ll k;
int sz;

ll hope( int pos, bool isSmall, int sum, int dsum ){
    if( pos == sz ){
        if( sum == 0 && dsum % k == 0 ) return 1;
        return 0;
    }
    if( vis[pos][isSmall][sum][dsum] ) return dp[pos][isSmall][sum][dsum];
    vis[pos][isSmall][sum][dsum] = true;
    ll &ret = dp[pos][isSmall][sum][dsum];
    ret = 0;

    int ed ;
    if( isSmall ) ed = 9;
    else ed = num[pos];

    for( int i = 0; i <= ed; i++ ){
        ret += hope( pos + 1, isSmall | ( i < num[pos] ), ( sum * 10 + i ) % k, dsum + i  );
    }
    return ret;
}

ll solve( ll n ){

    num.clear();
    memset( vis, false, sizeof( vis ) );
    while( n > 0 ){
        num.pb( n % 10 );
        n /= 10;
    }
    reverse( num.begin(), num.end() );
    sz =num.size();
    return hope( 0, false, 0, 0 );
}

int main ( ){
     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int t;
    cin >> t;
    for( int ks = 1; ks <= t; ks++ ){
        ll a, b ;
        cin >> a >> b >> k;
        cout << "Case " << ks << ": ";
        if( k > 90 ){
            cout << 0 << "\n";
        }
        else cout << solve( b ) - solve( a - 1 ) << "\n";
    }
    return 0;
}
