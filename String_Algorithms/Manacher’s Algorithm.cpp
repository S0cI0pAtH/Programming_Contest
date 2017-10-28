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
 /*-----------------------Bitmask------------------*/
 //int Set(int N,int pos){return N=N  (1<<pos);}
 //int reset(int N,int pos){return N= N & ~(1<<pos);}
 //bool check(int N,int pos){return (bool)(N & (1<<pos));}
 /*------------------------------------------------*/
 ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
 ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

int P[100005];

string preprocess(string s ){
    string tmp = "^";
    for( int i = 0; i < s.size(); i++ ){
            tmp += "#";
            tmp += s[i];
    }
    tmp += "#$";
    return tmp;
}

string longestPalindrome( string s ){
    string T = preprocess(s);
    int sz = T.size();
    int C = 0, R = 0;
    for( int i = 1; i < sz - 1; i++ ){
        int mirror = 2*C - i;
        P[i] = ( R > i ) ? min( R-i, P[mirror] ) : 0;

        while( T[i + 1 + P[i]] == T[i - 1 - P[i]] ) P[i]++;
        if( i + P[i] > R ){
            C = i; R = i + P[i];
        }
    }
    int mx = 0, center = 0;
    for( int i = 1; i < sz - 1; i++ ){
        if( P[i] > mx ){
            mx = P[i];
            center = i;
        }
    }
    return s.substr((center - 1- mx ) / 2 , mx );
}

 int main ( ){

      #ifdef swapnil
     freopen("in.txt","r",stdin );
     //freopen("out.txt","w",stdout );
     #endif // swapnil

     string s;
     cin >> s;
     cout << longestPalindrome(s) << "\n";



     return 0;

 }
