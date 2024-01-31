int fail[100000];

int main() {
	for (int i = 1, j = 0; i < M; i++) {
		while (j != 0 && P[i] != P[j]) j = fail[j - 1];

		if (P[i] == P[j]) {
			fail[i] = ++j;
		}
	}

	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && T[i] != P[j]) j = fail[j - 1];

		if (T[i] == P[j]) {
			if (j == M - 1) {
				idxs.push_back({ i - (M - 1) });
				j = fail[j];
			}
			else j++;
		}
	}
}
