
typedef long long ll;
const ll inf = 1e9+20;
const int MAX = 2005;
const int MAX_E = 200005;

struct abc
{
    int x,y,z;
}arr[MAX_E];

int dist[MAX+10], par[MAX+10], n , m;

void init( int start ){
    for( int i = 0; i <= n; i++ ){
        dist[i] = inf;
    }
    dist[start] = 0;
    par[start] = start;
}

void bellmanford(){
    bool update = false, neg_cycle = false;
    for( int i = 0; i <= n - 1; i++ ){
        update = false;
        for( int j = 0; j < m; j++ ){
            int u = arr[j].x, v = arr[j].y, c = arr[j].z;
            if( dist[u] + c < dist[v]){
                dist[v] = dist[u] + c;
                par[v] = u;
                update = true;
            }
        }
        if( i == n - 1 && update ){
            neg_cycle = true;
            break;
        }
        if( !update ) break;
    }
}
