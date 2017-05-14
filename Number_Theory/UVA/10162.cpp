/* number theory
patteren
<uva 10162>
Give you a integer number N,  1 <= N <= 10 ^ 100. Compute
S = 1^1 + 2^2 + 3^3 + . . . + N^N
find the last digit of S
result repete after 100 iteration

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
int digit[105];

int main ( ){
     #ifdef swapnil
    freopen("in.txt","r",stdin );
    freopen("out.txt","w",stdout );
    #endif // swapnil

    for( int i = 1; i <= 100; i++ ){
        digit[i] = digit[i-1] + BM( i, i, 10 );
    }

    string s;
    while( cin >> s ){
        if( s == "0" ) break;
        int n = 0;
        if( s.size() < 4 ){
            for( int i = 0; i < s.size(); i++ ){
                n = n * 10 + s[i] - '0';
            }
        }else{
            for( int i = s.size() - 4; i < s.size(); i++ ){
                n = n * 10 + s[i] - '0';
            }
        }

        cout << digit[n%100] % 10 << "\n";
    }



    return 0;
}

