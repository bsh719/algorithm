#include <iostream>
using namespace std;

int trie[100000][27];
int fail[100000];
int cnt[100000];

int main() {
	int N; cin >> N;

	// 트라이
	int last = 0;

	for (int i = 0; i < N; i++) {
		string st; cin >> st;
		int now = 0;

		for (char ch : st) {
			int t = ch - 'a';
			if (trie[now][t] == 0) trie[now][t] = ++last_idx;
			now = trie[now][t];
		}
		cnt[now]++;
	}
	// 실패함수
	queue<int> q; q.push(0);

	while (!q.empty()) {
		int a = q.front(); q.pop();

		for (int i = 0; i < 26; i++) {
			if (trie[a][i] == 0) continue;
			int b = trie[a][i];

			int t = fail[a];
			if (a == 0) fail[b] = 0;
			else {
				int t = fail[a];
				while (t != 0 && trie[t][i] == 0) t = fail[t];
				fail[b] = trie[t][i];
			}
			cnt[b] += cnt[fail[b]];
			q.push(b);
		}
	}
	// 답
	int ans = 0;
	int now = 0;
	string st; cin >> st;
	int S = st.size();

	for (int i = 0; i < S; i++) {
		int t = st[i] - 'a';
		
		while (now != 0 && trie[now][t] == 0) now = fail[now];
		now = trie[now][t];
		
		ans += cnt[now];
	}
	cout << ans;
}
