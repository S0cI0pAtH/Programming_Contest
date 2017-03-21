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

int n, arr[25];
ll sum[20000005];

void all_possible_sum( ){ // there will be 2 ^ n combination , n must be small

    for( int i = 0; i < ( 1 << n ); i++ ){
        ll tmp = 0;
        for( int j = 0; j < n; j++ ){
            if( i & ( 1 << j ) ) tmp += arr[j];
        }
        sum[i] = tmp;
    }
}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    cin >> n;
    cout << n << "\n";
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }

    all_possible_sum( );
    cout << n << "\n";
    cout << ( 1 << n ) << "\n";

    for( int i = 0; i < (1 << n ); i++ ){
        cout << sum[i] << " ";
    }


    return 0;
}

