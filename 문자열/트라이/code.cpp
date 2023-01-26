#include <iostream>
using namespace std;

int trie[100000][26], cnt[100000];

int main() {
	int N; cin >> N;
	int last = 0;

	for (int i = 0; i < N; i++) {
		string st; cin >> st;
		int now = 0;

		for (char ch : st) {
			int t = ch - 'a';
			if (trie[now][t] == 0) trie[now][t] = ++last;
			now = trie[now][t];
		}
    	cnt[now]++;
	}
}
