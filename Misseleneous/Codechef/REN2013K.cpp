/*
given a range of terms [X...Y] you must calculate the sum of pairwise GCD(greatest common divisor) of the entire range (inclusive of X and Y ).

For example, if range contains the numbers A,B,C,D then the result of the query on this range will be
GCD(A,B)+GCD(A,C)+GCD(A,D)+GCD(B,C)+GCD(B,D)+GCD(C,D).

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


int main ( ){
     #ifdef swapnil
    //freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int t;
    cin >> t;
    while( t-- ){
        ll a, b, tmp;
        cin >> a >> b;
        tmp = b - a + 1;
        cout << ( tmp * (tmp -1 ) ) / 2 << "\n";
    }


    return 0;
}

