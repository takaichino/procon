int n, m, a, b;
int t[MAX_N];
int d[MAX_N][MAX_N];
// dp[S][v] := 残り乗車券S、現在位置vという状態に至る最小コスト
double dp[1 << MAX_N][MAX_M];
void solve(){
	for(int i = 0; i < 1 << n; i++){
		fill(dp[i], dp[i] + m, INF);
	}
	dp[(1 << n) ? 1][a - 1] = 0;
	double res = INF;
}

for(int S = (1 << n) ? 1; S >= 0; S--){ // 乗車券がなくなるまで
	res = min(res, dp[S][b ? 1]);
	for(int v = 0; v < m; v++){ // 位置v
		for(int i = 0; i < n; i++)
			 if(S >> i & 1){ // i番目の乗車券がある
				for(int u = 0; u < m; u++){
					if(d[v][u] >= 0){ // vからuへ行ける!
						dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[u][v]/t[i]);
					}
				}
			}
		}
	}
}

