/*
Given a set of n integers where n <= 40.
Each of them is at most <= 10^12, determine
the maximum sum subset
having sum less than or equal S where s <= 10 ^ 18
*/


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

ll arr[100], n;
ll comb1[20000005], comb2[20000005];

void calc(  ){ // generate all possible combination sum of n numbers


    int ed = n / 2;
    for (int i = 0; i < ( 1 << ed ); i++ ){
        ll sum = 0;
        for (int j = 0; j < ed; j++ ){
            if ( i  & ( 1 << j ) ){
                sum += arr[j];
            }
        }
        comb1[i] = sum;
    }

    int up = n / 2;
    ed = n - n / 2;

    for (int i = 0; i < ( 1 << ed ); i++ ){
        ll sum = 0;
        for (int j = 0; j < ed; j++ ){
            if ( i  & ( 1 << j ) ){
                sum += arr[j+ up];
            }
        }
      comb2[i] = sum;
    }
}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int t;
    cin >> t;
    for( int ks = 1; ks <= t; ks++ ){
        ll  m , k, ans = 0;
        cin >> n >> m >> k;

        for( int i = 0; i < n; i++ ){
            cin >> arr[i];
        }

        calc();

        int sz1 = ( 1 << n / 2 );
        int sz2 = ( 1 << (n - n / 2 ) );

        sort( comb2, comb2 + sz2 );

        for( int i = 0; i < sz1; i++ ){
            ll x = comb1[i];
            if( x > m ) continue;
            ll need = m - x;

            int id = ( lower_bound( comb2, comb2 + sz2, need ) - comb2) ;

            if( id == sz2 || comb2[id] != need ) id--;

            ans = max( ans, x + comb2[id] );
        }

        cout << ans << "\n";


    }


    return 0;
}

