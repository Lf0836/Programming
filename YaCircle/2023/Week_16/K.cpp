#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define INF 1e18
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>

using namespace std;

ll cnt, flct, src, dest, c1, c2, c;

int main() {
    cin >> cnt >> flct;
    vector<vector<pii>> graph(cnt + 1);
    vector<ll> a(cnt + 1, INF);
    vector<ll> papa(cnt + 1, -1);
    vector<int> lime, xdra;
    for (int i = 1; i <= cnt; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            lime.pb(i);
        } else if (a == 2) {
            xdra.pb(i);
        }
    }
    for (ll i = 0; i < flct; ++i) {
        cin >> c1 >> c2 >> c;
        graph[c1].pb(mp(c2, c));
        graph[c2].pb(mp(c1, c));
    }
    if (lime.size() <= xdra.size()) {
        ll x, y, d = INF;
        for (int i = 0; i < lime.size(); ++i) {
            ll start = lime[i];
            a.resize(cnt + 1, INF);
            a[start] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push(mp(0, start));
            while (!pq.empty()) {
                ll dist = pq.top().first;
                ll city = pq.top().second;
                pq.pop();
                if (a[city] < dist) {
                    continue;
                }
                for (auto [next, weight] : graph[city]) {
                    if (a[city] + weight < a[next]) {
                        papa[next] = city;
                        a[next] = a[city] + weight;
                        pq.push(mp(a[next], next));
                    }
                }
            }
            for (int j = 0; j < xdra.size(); ++j) {
                int f = xdra[j];
                if (a[f] != INF) {
                    if (a[f] < d) {
                        x = lime[i];
                        y = f;
                        d = a[f];
                    }
                }
            }
        }
        if (d == INF) {
            cout << -1 << endl;
            return 0;
        }
        cout << x << " " << y << " " << d << endl;
    } else {
        ll x, y, d = INF;
        for (int i = 0; i < xdra.size(); ++i) {
            ll start = xdra[i];
            a.resize(cnt + 1, INF);
            a[start] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push(mp(0, start));
            while (!pq.empty()) {
                ll dist = pq.top().first;
                ll city = pq.top().second;
                pq.pop();
                if (a[city] < dist) {
                    continue;
                }
                for (auto [next, weight] : graph[city]) {
                    if (a[city] + weight < a[next]) {
                        papa[next] = city;
                        a[next] = a[city] + weight;
                        pq.push(mp(a[next], next));
                    }
                }
            }
            for (int j = 0; j < lime.size(); ++j) {
                int f = lime[j];
                if (a[f] != INF) {
                    if (a[f] < d) {
                        y = xdra[i];
                        x = f;
                        d = a[f];
                    }
                }
            }
        }
        if (d == INF) {
            cout << -1 << endl;
            return 0;
        }
        cout << x << " " << y << " " << d << endl;
    }
}
