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

struct node{
    int val;
    struct node *next;
};

void print(node *cur ){
    while( cur  != NULL ) {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    return;
}

void in( node **hed, int val ){
    struct node *newnode = new node();
    newnode -> val = val;
    newnode -> next = NULL;

    if( *hed == NULL ){
        *hed = newnode;
        return;
    }

    node *cur = *hed;
    while( cur -> next != NULL ){
        cur = cur -> next;
    }
    cur -> next = newnode;
    return;


}


int main ( ){
     #ifdef S0cI0pAtH
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // S0cI0pAtH

    struct node *head = NULL;

    int n;
    cin >> n;
    while( n-- ){
        int x; cin >> x;
        in( &head, x );
    }


    print( head );




    return 0;
}
