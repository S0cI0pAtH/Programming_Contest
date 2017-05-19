
//all are 1 indexed Graph

const int MX = 10005;
vector < int > adj[MX],Radj[MX],order,Comp;
bool used[MX];
int newCompId[MX];
int N , M;

void dfs1(int u) {
    used[u] = true ;
    for( auto it: adj[u] ) if( !used[ it ] ) dfs1( it );
    order.pb(u);
}

void dfs2(int u , int scc ){
    newCompId[u] = scc ;
    used[u] =  true ;
    Comp.pb(u);
    for( auto it: Radj[u] ) if( !used[it ] ) dfs2( it , scc );
}

void Reset(){
    for( int i = 0; i <= N; i++ ){
        adj[i].clear();
        Radj[i].clear();
    }

    memset( newCompId, 0 , sizeof( newCompId ) );
    memset( used, false,sizeof( used ) );
    order.clear();
}

void Zip(){
    reverse(order.begin(), order.end() );
    int scc = 0 ;
    for( auto it: order ){
        int v = it ;
        if( !used[ v ] ){
            scc++;
            Comp.clear();
            dfs2(v,scc);
            printf("No.%d SCC components are ->  ",scc);
            for(auto u:Comp ) cout << u << " ";
            cout << "\n";

        }
    }
}

void Kosaraju(){
    for( int i = 1; i <= N; i++ ) if( !used[i] ) dfs1(i);
    memset( used, false, sizeof( used ) );
    Zip();
}

int main(){

    cin >> N >> M ;
    for( int i = 0; i < M; i++ ){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        Radj[v].pb(u);
    }
    Kosaraju();
    Reset();
}


