/*

Problem Id Codechef : CHEFDIV

A divisor tree with value at root $N$ is defined as follows. For each node of the tree,
the values at the child nodes will be the proper divisors of $x$ (i.e. divisors except $x$).
The weight of a path in this tree is defined as the sum of degrees of all the nodes in the path.
The weight of a tree will be the maximum score of path starting at root.
You are given two integers $A, B$.
You have to find the sum of weights of all the trees with the values at their root node
being in the range $A$ to $B$, both inclusive.
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
const ll MAX = 1e6 + 5;

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

ll a, b;
vector< ll > primes, divi[100005];
bool check[MAX+20];

void sieve(){
    for( int i = 2; i * i <= MAX; i++ ){
        if( check[i] ) continue;
        for( int j = i * i ; j <= MAX; j += i ){
            check[j] = true;
        }
    }
    for( int i = 2; i <= MAX; i++ ){
        if( !check[i] ) primes.pb( i );
    }
}

void gen_div(){
    for( auto pr : primes ){
        ll first = a / pr;
        if( a % pr ) first++;
        first *= pr;

        for( ll i = first; i <= b; i += pr ){
            ll num = i;
            while( num % pr == 0 ){
                divi[i-a].pb( pr );
                num /= pr;
            }
        }

    }
}

int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil

    sieve();
    ll ans = 0;

    cin >> a >> b;
    if( a == 1 ) a++;
    gen_div();

    int sz = b - a + 1 ;

    for( int i = 0; i < sz; i++ ){
        ll num = a + i;

        map< int, int > mp;
        ll total = 1;

        for( auto val : divi[i] ){
            mp[val]++;
            num /= val;
        }
        if( num > 1 ) mp[num]++;

        priority_queue< int > pq;
        for( auto it : mp ){
            total *= ( it.second + 1 );
            pq.push( it.second + 1 );
        }

        ll tmp = 0;
        while( !pq.empty() ){
            int tp = pq.top(); pq.pop();
            tmp += total;
            total /= tp;
            tp--;
            total *= tp;
            if( tp > 1 ) pq.push( tp );
        }
        ans += tmp;
    }
    cout << ans << "\n";

    return 0;
}
