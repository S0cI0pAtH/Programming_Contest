typedef long long ll;
const int MAX = (int) 1e6 + 20;

int phi [MAX + 7];
bool check [MAX + 7];

void sieve_phi () {
    for (ll i = 2; i <= MAX; i++) {
        if (check [i]) continue;
        phi [i] = i - 1;
        for (ll j = 2 * i; j <= MAX; j += i) {
            if (!check [j]) {check [j] = true; phi [j] = j;}
            phi [j] -= phi [j] / i;
        }
    }
}
