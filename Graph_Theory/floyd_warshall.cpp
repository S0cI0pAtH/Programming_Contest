
typedef long long ll;
const ll inf = 1e9+20;
const int MAX = 200;

ll cost[MAX][MAX];

void init(int n ){
    for( int i = 0; i <= n; i++ ){
        for( int j = 0; j <= n; j++ ){
            if( i == j ) cost[i][j] = 0;
            else cost[i][j] = inf;
        }
    }
}

void floydWarshall (int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost [i][j] = min(cost [i][j], cost [i][k] + cost [k][j]);
            }
        }
    }
}

