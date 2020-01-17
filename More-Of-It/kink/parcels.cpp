// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 355, mod = (int) 0;
int d[N][N];
int q[N * N];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
string s[N];
void bfs(int n, int m) {
	int h = 0, t = 0;
	memset(d, 63, sizeof d);
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y)
			if (s[x][y] == '1')
				d[x][y] = 0, q[t++] = x * m + y;
	while (h != t) {
		int v = q[h++];
		int x = v / m, y = v % m;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (::d[nx][ny] > ::d[x][y] + 1) {
					::d[nx][ny] = ::d[x][y] + 1;	
					q[t++] = nx * m + ny;
				}
			}
		}
	}
}
int sum[4 * N][4 * N];
int check(int lim, int n, int m) {
	for (int x = 0; x < 2 * N; ++x) for (int y = 0; y < 2 * N; ++y) sum[x][y] = 0;
	int cnt = 0;
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y) {
			if (d[x][y] > lim) {
				++cnt;
				int lx = x - lim, rx = x + lim;
				int lnx = lx + y;
				int lny = lx - y + m;
				int rnx = rx + y;
				int rny = rx - y + m;
				lny = max(lny, 0);
				lnx = max(lnx, 0);
				rny = max(rny, 0);
				rnx = max(rnx, 0);
				sum[lnx][lny]++;
				sum[rnx + 1][lny]--;
				sum[lnx][rny + 1]--;
				sum[rnx + 1][rny + 1]++;
			}
		}
	for (int x = 0; x < 2 * N; ++x)
		for (int y = 0; y < 2 * N; ++y) {
			int a = (x + y - m) / 2, b = x - a;
			if (x) sum[x][y] += sum[x - 1][y];
			if (y) sum[x][y] += sum[x][y - 1];
			if (x && y) sum[x][y] -= sum[x - 1][y - 1];
			if ((x & 1) == ((y + m) & 1) && a >= 0 && a < n && b >= 0 && b < m && sum[x][y] == cnt) {
				return 1;
			}
		}
	if (cnt == 0) return 1;
	return 0;
}
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; ++j)
			cin >> s[j];
		bfs(n, m);
		int bl = -1, br = n + m + 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			if (check(bm, n, m)) {
				br = bm;
			} else {
				bl = bm;
			}
		}
		cout << br << '\n';
	}
}

