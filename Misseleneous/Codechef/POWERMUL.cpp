#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
/*************NOTES*********************\
    string s; int tmp; getline( cin, s ); stringstream ss(s);
      while( ss >> tmp ){
         person[i].pb( tmp );
       }
***************************************/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll MAX = 32000;

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
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//int countbit( int x ){ return __builtin_popcount( x );}
/*------------------------------------------------*/
ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
//ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

vector< ll > primes, factors;
bool check[MAX];
ll n, m;
ll common[100005][20], g[100005];
ll ans[100005];

void sieve(){
    check[0] = check[1] = true;
    primes.pb( 2 );
    for( ll i = 3; i  <= MAX; i+= 2 ){
        if( check[i] ) continue;
        primes.pb( i );
        for( ll j = i * i ; j <= MAX; j += 2 * i ){
            check[j] = true;
        }
    }

}

ll factorise( ll x ){
    factors.clear();
    int psz = primes.size();
    ll tot = n;
    for( int i = 0; i < psz && primes[i] * primes[i] <= x; i++ ){
        if( x % primes[i] == 0 ){
            factors.pb( primes[i] );
            tot -= tot/primes[i];
            while( x % primes[i] == 0 ) x /= primes[i];
        }
    }
    if( x > 1 ){
        factors.pb( x );
        tot -= tot/x;
    }
    return tot;
}
ll ext_gcd ( ll A, ll B, ll *XX, ll *YY ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *XX = x2; *YY = y2;
    return r2;
}
ll mi( ll a, ll m ){
    ll x, y;
    ext_gcd( a, m , &x, &y );
    x %= m;
    while( x < 0 ) x += m;
    return x;

}

void solve(){
    int fsz = factors.size();
    for( int i = 0; i < fsz; i++ ) common[1][i] = 0;
    g[0] = 0;
    g[1] = 1;
    for( int i = 2; i <= n; i++ ){
        ll num = i;
        for( int j = 0; j < fsz; j++ ){
            int cnt = 0;
            while( num % factors[j] == 0 ){
                cnt++;
                num  /= factors[j];
            }
            common[i][j] =  common[i-1][j] +  cnt * (ll)i ;
        }
        g[i] = ( g[i-1] * BM( num , i , m ) ) % m;
    }

}

void pre(){
    int fsz = factors.size();
    for( int i = 1; i <= n/2; i++ ){
        int dif = 0;
        ans[i] = 1;
        ll tmp=(((g[n]*mi(g[i], m))%m)*mi(g[n-i], m))%m;
        for( int j = 0; j < fsz; j++ ){
            ll diff = ( common[n][j] - common[i][j] - common[n-i][j] );
            tmp = ( tmp *  BM( factors[j], diff, m ) ) % m;
        }
        ans[i] = tmp;
    }
    int ck = 1;
    for( int i = n-1; i > n/2; i-- ){
        ans[i] = ans[ck++];
    }
}

int main ( ){

     #ifdef S0cI0pAtH
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // S0cI0pAtH

    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int t;
    cin >> t;
    while( t-- ){
        int q;
        cin >> n >> m >> q;
        ll phi = factorise(m);
        solve();
        pre();

        while( q-- ){
            ll x; cin >> x;

//            ll tmp=(((g[n]*mi(g[x], m))%m)*mi(g[n-x], m))%m;
//
//            for( int j = 0; j < factors.size(); j++ ){
//                ll diff = ( common[n][j] - common[x][j] - common[n-x][j] );
//                tmp = ( tmp *  BM( factors[j], diff, m ) ) % m;
//            }
//            cout << tmp << "\n";
            cout << ans[x] << "\n";
        }
    }





    return 0;

}
