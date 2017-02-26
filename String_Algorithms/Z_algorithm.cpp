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

int Z[1000005], len;
string s , str, pat ;

void build(){
    int L, R, K;
    L = R = 0;
    for( int i = 1; i < len; i++){
        if( i > R ){
            L = R = i;
            while( R < len && s[R - L] == s[R] ){
                R++;
            }
            Z[i] = R - L;
            R--;
        }else{
            K = i - L;
            if( Z[K] + i <= R ){
                Z[i] = Z[K];
            }else{
                L = i;
                while( R < len && s[R-L] == s[R] ){
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
}

int Z_algo(){
    s = pat + "$" + str; // patteren + $ + original string
    len = s.size();
    build();
    int occurance = 0;

    for( int i = pat.size() + 1; i < len; i++ )
    {
        if( Z[i] == pat.size() ) occurance++;      //  if Z[i] == length  of the patteren then
                                                                    // it's a starting point of the patteren
    }

    return occurance ;
}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    getline( cin ,str );
    getline( cin, pat );

    int repeat = Z_algo();
    cout << repeat << "\n";


    return 0;
}
