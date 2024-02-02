vector<int> link[201];
int A[201], B[201];
bool visit[201];

bool match(int a) {
	visit[a] = 1;

	for (int b : link[a]) {
		if (B[b] == 0) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
		else if (!visit[B[b]] && match(B[b])) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
	}
	return 0;
}

int main() {
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		fill_n(visit, N + 1, 0);
		if (match(i)) cnt++;
	}
}
