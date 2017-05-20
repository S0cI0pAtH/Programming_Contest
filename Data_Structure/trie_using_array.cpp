
// search word like dictionary
//poj-3630
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
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

//inline const int EQ( double tmp ){ if( fabs( tmp ) < eps ) return 0; return tmp > eps ? 1 : -1;}
ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

int tree[11][100010];
int End[100010];
int node = 0;
void add( string s ){
    int  root = 0;
    for( int i = 0; i < s.size(); i++ ){
        int id = s[i] - '0';
        if( tree[id][root] == -1 ){
            tree[id][root] = ++node;
        }
        root = tree[id][root];
    }
    End[root] = 1;
}

int main ( ){
     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while( t-- ){
        memset( tree, -1, sizeof( tree ) );
        memset( End, 0, sizeof( End ) );
        node = 0;
        int n;
        bool ok = true;
        cin >> n;
        for( int i = 0; i < n; i++ ){
            string s;
            cin >> s;
            add( s );
        }
        for( int i = 1; i <= node; i++ ){
            if( End[i] ){
                for( int j = 0; j < 10; j++ ){
                    if( tree[j][i] != -1 ){
                        ok = false;
                        break;
                    }
                }
                if( !ok ) break;
            }
        }
        if( ok ){
            cout << "YES\n";
        }else cout << "NO\n";
    }


    return 0;
}

