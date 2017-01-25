

typedef long long ll;
const ll mod = 1e9 + 7;

ll BM( ll b, ll p, ll m )
{
    if (p == 0)
        return 1;

    ll temp = BM( b, p/2, m ) % m;

    if ( p % 2 == 0 )
    {
        return ( temp * temp )%m;
    }
    else
    {
        return ( ( b % m) * ( temp * temp ) % m ) ;
    }
}

// big mod iterative form

ll  BM(ll  B,ll  P,ll  M)
{
    ll  R=1;
    while(P>0)  {
        if(P&1){
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (ll )R;
}

