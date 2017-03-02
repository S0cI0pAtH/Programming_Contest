// codeforces
// 86D - Powerful array


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

ll block = 0, arr[2000005], occur[2000005] , ans[2000005] , cnt = 0;
int curL = -1, curR = -1 ;

struct query{
    int lt, rt, id;
    query(){}
    query(int a, int b , int c ){
        lt = a; rt = b; id = c;
    }
}Q[2000005];

bool cmp( query a, query b ){
    if( a.lt / block == b.lt / block ) return a.rt < b.rt;
    return a.lt / block < b.lt / block;
}

void Add( int idx ){
    cnt += arr[idx] * ( 2 * occur[arr[idx]] + 1 ); // a( x + 1 ) ^ 2 - ax ^ 2 = a ( 2x + 1 )
    occur[arr[idx]]++;
}
void Remove( int idx ){
    cnt -= arr[idx] * ( 2 * occur[arr[idx]] - 1 );
    occur[arr[idx]]--;
}

void MO( int id ){

    int left = Q[id].lt;
    int right = Q[id].rt;

    while( curL < left ) Remove( curL++ );
    while( curL > left ) Add( --curL );
    while( curR > right ) Remove( curR-- );
    while( curR < right ) Add( ++curR );

    ans[Q[id].id] = cnt;

}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    ios_base:: sync_with_stdio( false );
    cin.tie(0);

    int n, q;
    curL = -1, curR = -1;
    cin >> n >> q;
    block = sqrt( n ) + eps;
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }
    for( int i = 0; i < q; i++ ){
        int a, b;
        cin >> a >> b;
        a--; b--;
        Q[i] = query( a, b, i );
    }

    sort( Q, Q + q, cmp );

    for( int i = 0; i < q; i++ ){
        MO( i );
    }
    for( int i = 0; i < q; i++ ){
        cout << ans[i] << "\n";
    }

    return 0;
}

