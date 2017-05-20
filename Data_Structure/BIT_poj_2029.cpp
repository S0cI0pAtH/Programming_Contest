
//poj 2029
// onek gula point er cordinate dea thakbe, then query te rectangle er up,down dile bolte hbe kotogula point ase oitar modhe :p

#include<iostream>
#include<cstdio>
#include<cstring>
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

int W, H, tree[101][101];
int query( int x, int y ){
    int sum = 0, tmp = y;
    while( x > 0  ){
        y = tmp;
        while( y > 0 ){
            sum += tree[x][y];
            y -= y & -y;
        }
        x -= x & -x;
    }
    return sum;
}
void update( int x, int y , int val ){
    int tmp = y;
    while( x <= 100  ){
        y = tmp;
        while( y <= 100 ){
            tree[x][y] += val;
            y += y & -y;
        }
        x += x & -x;
    }
}


int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    int n;
    while( scanf("%d", & n ) && n  ){
        memset( tree, 0 , sizeof( tree ) );
        scanf("%d %d", &W, &H );
        for( int i = 0; i < n; i++ ){
            int x, y;
            scanf("%d %d", &x, &y );
            update( x, y , 1 );
        }
        int myW, myH, ans = 0;
        scanf("%d %d", &myW, &myH );
        for( int i = myW; i <= W; i++ ){
            for( int j = myH; j <= H; j++ ){
                ans = max( ans, ( query( i, j ) - query( i - myW, j ) - query( i, j - myH ) + query( i - myW, j - myH ) ) );
            }
        }
        printf("%d\n", ans );
    }




    return 0;
}

