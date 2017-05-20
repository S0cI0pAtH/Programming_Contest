#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
/*************NOTES*********************\
XOR operation :  same hoile 0, naile 1
24 = 2^3 * 3 ^ 1 = ( 3 + 1 ) * ( 1 + 1 ) = 8 divisor

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

ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

vector< int > numbers;
int totalNumber = 0;
ll dp[2][2][11][11];



ll hope( bool isStart, bool isSmall, int pos, int value ){
    if( pos == totalNumber ) return value;
    ll &ret = dp[isStart][isSmall][pos][value];
    if( ret != -1 ) return ret;
    ret = 0;

    int lim = 0;
    if( isSmall ) lim = 9;
    else lim = numbers[pos];

    if( isStart ){
        for( int i = 1; i <= lim; i++ ){
            ret += hope( 0, isSmall | i < numbers[pos], pos + 1 , ( i == 0 ) +  value );
        }
        ret += hope( 1, 1, pos + 1 , 0 );
    }else{
        for( int i = 0; i <= lim; i++ ){
            ret += hope( 0, isSmall | i < numbers[pos], pos + 1 ,  ( i == 0 ) + value );
        }

    }

    return ret;
}

ll solve( ll num ){
    memset( dp, - 1, sizeof( dp ) );
    if( num < 0 ) return 0;
    if( num <= 9 ) return 1;
    numbers.clear();
    while( num  ) {
        numbers.pb( num % 10 );
        num /= 10;
    }
    reverse( numbers.begin(), numbers.end() );
    totalNumber = numbers.size();
    return hope( 1, 0 , 0, 0 ) + 1 ;
}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int t;
    cin >> t;
    for( int ks = 1; ks <= t; ks++ ){
        ll n , m;
        cin >> n >> m;
        cout << "Case " << ks << ": " << solve( m ) - solve( n - 1 ) << "\n";
    }


    return 0;
}

