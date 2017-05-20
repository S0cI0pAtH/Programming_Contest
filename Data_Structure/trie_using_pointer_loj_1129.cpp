#include<bits/stdc++.h>
using namespace std;
bool ok = true;
struct node
{
    bool endpoint = false;;
    bool visit = false;;
    node *child[11];
    node( ){
        for( int i = 0; i <= 10; i++ ) child[i] = NULL;
    }
};

void add( node *cur, string s )
{
    if( !ok ) return;
    for( int i = 0; i < s.size(); i++ ){
        int num = s[i] - '0';
        cur -> visit = true;
        if( cur -> child[num] == NULL )
            cur -> child[num] = new node();
        cur = cur -> child[num];

        if( cur -> endpoint )
        {
            ok = false;
            return;
        }
    }
    if( cur -> visit ){
        ok = false;
        return;
    }
    cur -> endpoint = true;
}
void del( node *cur )
{
    cur-> endpoint = false;
    for( int i = 0; i <= 10; i++ ){
        if( cur -> child[i] != NULL  )
            del( cur -> child[i] );
    }
    delete( cur );
}
int main(){
    int t;
    cin >> t;
    for( int k = 1; k <= t; k++ )
    {
        node *head = new node();

        ok = true;
        int n;
        cin >> n;

        for( int i =  0; i < n; i++ )
        {
            string s;
            cin >> s;
            add( head, s );
        }
        cout << "Case " << k << ": ";
        if( ok ) cout << "YES\n";
        else cout << "NO\n";
        del( head );
    }
}

