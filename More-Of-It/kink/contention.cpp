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

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, q, xl[N], xr[N], mvl[N];
pair<int, int> sr[N];
int check(int k) {
	for (int j = 0; j < q; ++j)
		xl[j] = sr[j].first, xr[j] = -sr[j].second, mvl[j] = xl[j];
	for (int j = 0; j < q; ++j) {
		int l = xl[j], r = xr[j];	
		int st = mvl[j];
		int allowed_after = r;
		int cnt = 0;
		for (int i = j + 1; i < q; ++i) {
			if (xr[i] <= r) {
				if (xl[i] <= st) {
					st = max(st, xr[i]);	
				} else {
					cnt += xl[i] - st;
					st = max(st, xr[i]);
					if (cnt >= k) {
						allowed_after = xl[i] - (cnt - k);
						break;
					}
				}
			}
		}
		if (cnt < k) {
			cnt += r - st;
			if (cnt < k) return 0;
			allowed_after = r - (cnt - k);
		}
		for (int i = j + 1; i < q; ++i) {
			if (xl[i] >= allowed_after) break;
			if (xr[i] > r) {
				mvl[i] = max(mvl[i], r);
			}
		}
	}
	return 1;
}
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		cin >> n >> q;
		for (int j = 0; j < q; ++j) {
			cin >> xl[j] >> xr[j], --xl[j];
			sr[j] = mp(xl[j], -xr[j]);	
		}
		sort(sr, sr + q);
		int bl = 0, br = n + 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			if (check(bm)) {
				bl = bm;
			} else {
				br = bm;
			}
		}
		cout << bl << '\n';

	}
}
