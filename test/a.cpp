#include <bits/stdc++.h>
using namespace std;
int n, m, p, minidade;

int vis[520], idades[520];

int dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < patroes[u].size(); i++)
	{
		int k = patroes[u][i];

		if (!vis[k])
		{
			minidade = min(minidade, idades[k]);
			dfs(k);
		}
	}
	return 0;
}


vector<vector<int>> patroes;


int main() {
	memset(vis, 0, sizeof vis);
	while (~scanf("%d %d %d", &n, &m, &p)) {
		patroes.assign(n + 1, vector<int>());

		for (int i = 1; i <= n; i++) {
			scanf("%d", &idades[i]);
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			patroes[b].push_back(a);
		}

		for (int i = 0; i < p; i++) {
			char c;
			scanf(" %c", &c);
			if (c == 'P')
			{
				int x;
				scanf("%d", &x);
				memset(vis, 0, sizeof vis);

				minidade = 1000;
				// printf("%d fonfonfonf\n",minidade);
				dfs(x);
				if (minidade == 1000)
					printf("*\n");
				else
					printf("%d\n", minidade);
			}
			else if (c == 'T')
			{
				int a, b;
				scanf("%d %d", &a, &b);
				swap(patroes[a], patroes[b]);
				for (int i = 1; i <= n; i++)
				{
					for (int l = 0; l < patroes[i].size(); l++)
					{
						if (patroes[i][l] == a)
							patroes[i][l] = b;
						else if (patroes[i][l] == b)
							patroes[i][l] = a;
					}
				}
			}
		}
	}

	return 0;
}