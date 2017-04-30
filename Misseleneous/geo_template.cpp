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

ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

inline const int EQ( double tmp ){
    if( fabs( tmp ) < eps ) return 0;
    return tmp > eps ? 1 : -1;
}

//******************************GEO TEMPAETE**************************************\\


struct point{
    double x, y;
    point(){}
    point( double _x, double _y ):
        x(_x),y(_y) {};
    static bool input( point &p ){
        return scanf("%lf %lf", &p.x, &p.y ) == 2;
    }
    const point operator + ( const point &temp ) const{
        return point( x + temp.x , y + temp.y );
    }
    const point operator - ( const point &temp ) const{
        return point( x - temp.x , y - temp.y );
    }

    const bool operator == ( const point &temp )const{
        return ( !EQ( temp.x - x ) &&  !EQ( temp.y - y ) ) ;
    }
    const bool operator < ( point &temp ) const{
        return EQ( temp.x - x ) == 0 ? EQ( temp.y - y ) < 0 : x < temp.x;
    }

    double dis_root( point &temp ){
        return sqrt(( ( x - temp.x ) * ( x - temp.x )  + ( y - temp.y ) * ( y - temp.y ) ));
    }
    double dis( point &temp ){
        return ( ( x - temp.x ) * ( x - temp.x )  + ( y - temp.y ) * ( y - temp.y ) );
    }
    double radius( point &temp ){
        return sqrt( ( x - temp.x ) * ( x - temp.x )  + ( y - temp.y ) * ( y - temp.y ) );
    }

};

struct line{ // line equation ax + by + c = 0
    double a, b , c;
    point start, finish;
    line(){}
    line( point p1, point p2 ){
        a = p2.y - p1.y;
        b = p2.x - p1.y;
        c = a * p1.x + b * p1.y;
        start = p1;
        finish = p2;
    }
};

struct myvector{
    point start, finish;
    double x, y;
    //mevector(){}
    myvector( double _x, double _y ){
        x = _x; y = _y;
    }
    myvector( point given_start, point  given_end ){

        start = given_start;
        finish = given_end;

        x = finish.x - start.x;
        y = finish.y - start.y;
    }

    double magnitude(){
        return sqrt( x * x + y * y );
    }
    double magnitudeSQ( ){
        return ( x * x + y * y );
    }
    point ADD( point &temp ){
        return point( x + temp.x , y + temp.y );
    }

    myvector scaling( double temp  ){
        return myvector( x * temp, y * temp );
    }

    double dot_product( myvector &temp ){
        return ( x * temp.x + y * temp.y );
    }

    double projection( myvector &temp ){
        return myvector::dot_product( temp ) /  myvector::magnitudeSQ() ;
    }

    point intersecting_point( myvector &temp ){
        double div = temp.y * x - temp.x*y;
        if( div == 0 )return point( inf, inf );
        double lamda = ( x * ( start.y - temp.start.y ) + y * ( temp.start.x - start.x ) ) / div;
        double xx = temp.start.x + lamda * temp.x;
        double yy = temp.start.y + lamda * temp.y;
        return point( xx, yy );
    }

};


struct circle{
    point A, B, C, center;
    double r, e ;
    circle(point p1, point p2, point p3 ){

        A = p1, B = p2, C = p3;

        point D = ( B - A ) ; D.x = D.x / 2; D.y = D.y / 2; D = A + D; // mid AB
        point E = ( C - A ) ; E.x = E.x / 2; E.y = E.y / 2; E = A + E; // mid AC
        myvector AB = myvector( A, B );
        point pp1 = point( -AB.y, AB.x ) + D;
        myvector DR = myvector( D, pp1 );

        myvector AC = myvector( A, C );
        point pp2 = point( -AC.y, AC.x ) + E;
        myvector ER = myvector( E, pp2 );

        center = DR.intersecting_point(ER);
        r = A.radius(center);
        e = ( center.x * center.x ) + ( center.y * center.y ) - ( r * r );
    }
};

double orientation( point a, point b , point p ){
    double temp = ( b.y - a.y ) * ( p.x - b.x ) -  ( b.x - a.x ) * ( p.y - b.y );
    if( temp == 0 ) return 0; // colinear
    return ( temp > 0 ) ? 1 :  2; // 1 -> clock , 2 -> anticlock
}

bool isLineIntersect( line l1, line l2  ){
    point a = l1.start, b = l1.finish;
    point c = l2.start, d = l2.finish;

    int or1 = orientation( a, b , c );
    int or2 = orientation( a, b , d );
    int or3 = orientation( c, d, a );
    int or4 = orientation( c, d, b );
    if( or1 != or2 && or3 != or4 ) return true;
    return false;
}

double distFromPointToLineSegment( point a, point b , point p , point &ans ){
    myvector AB = myvector( a, b );
    myvector AP = myvector( a, p );
    double get_projection = AB.projection(AP);

    if( get_projection > 1 ){
        ans = b;
    }else if( get_projection < 0 ){
        ans = a;
    }else{ // somewhere in the  middle
        ans = AB.scaling( get_projection ).ADD( a );
    }

    return ans.dis_root( p );
}


//******************************END OF TEMPAETE**************************************\\



int main ( ){

     #ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // swapnil


    return 0;

}

