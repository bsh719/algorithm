vector<vector<int>> SCC;
vector<int> link[20000];
bool fin[20000];
int cnt, SN;
int dfsn[20000], sn[20000];
vector<int> S;

int dfs(int a) {
	dfsn[a] = ++cnt;
	S.push_back(a);
	int ret = dfsn[a];

	for (int b : link[a]) {
		if (dfsn[b] == 0) ret = min(ret, dfs(b));
		else if (!fin[b]) ret = min(ret, dfsn[b]);
	}
	if (ret == dfsn[a]) {
		vector<int> tmp;
		while (1) {
			int t = S.back(); S.pop_back();
			fin[t] = 1;
			sn[t] = SN;
			tmp.push_back(t);
			if (t == a) break;
		}
		SN++;
		SCC.push_back(tmp);
	}
	return ret;
}
