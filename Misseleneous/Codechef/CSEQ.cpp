
/*

Problem Id Codechef:  CSEQ

Number of non-decreasing sequences of size exactly K will be Choose(K + R - L, K).
Where Choose(N, R) is number of ways to choose R elements from N distinct elements.
Summation of Choose(K + R - L, K) for all K between 1 and N (inclusive) will be Choose(N + R - L + 1, N) - 1.
In the question it is given that the answer should be printed mod (10^6+3)
which is a prime number. Choose(N, R) mod P for N > P can be found by using Lucas Theorem.
*/

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

int Set( int n , int pos ) { return n = n | ( 1 << pos ); }
int reSet( int n , int pos ){ return n = n & ~( 1 << pos ) ; }
bool check( int n , int pos ){ return (bool) ( n & ( 1 << pos));}


ll fact[MAX];
void factorial( int md ){
    fact[0] = fact[1] = 1;
    for( int i = 2; i <= md; i++ ){
        fact[i] = ( fact[i-1] * i ) % md;
    }
}

ll lucas_theorm( ll n , ll r, ll p ){
    ll ans = 1;
    while( n || r ){
        if( n % p < r % p ) return 0;
        ans *= ((fact[n%p] % p * BM( fact[r%p], p - 2, p ))%p * BM( fact[n%p - r%p], p -2, p )  ) %p;
        ans %= p;
        n /= p;
        r /= p;
    }
    return ans;
}


int main ( ){
     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    factorial( 1000003 );

    int t;
    cin >> t;
    while( t-- ){
        ll n , l, r;
        cin >> n >> l >> r;
        ll md = 1000000+3;

        ll ans = lucas_theorm( n + r - l + 1, n, md ) -1;
        if( ans < 0 ) ans += md;
        cout << ans << "\n";
    }

    return 0;
}

