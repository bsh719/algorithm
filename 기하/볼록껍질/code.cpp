typedef pair<int, int> pi;

pi vec(pi& p1, pi& p2) {
	return { p2.first - p1.first , p2.second - p1.second };
}
int cp(pi v1, pi v2) {
	return v1.first * v2.second - v1.second * v2.first;
}

vector<pi> pnts, conv;

int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pnts.push_back({ x, y });
	}
	sort(pnts.begin(), pnts.end());

	for (int i = 0; i < N; i++) {
		while (conv.size() >= 2) {
			int b = conv.size() - 1;
			int a = b - 1;

			if (cp(vec(conv[a], conv[b]), vec(conv[b], pnts[i])) >= 0)
				conv.pop_back();
			else break;
		}
		conv.push_back(pnts[i]);
	}
	int S = conv.size();

	for (int i = N - 2; i >= 0; i--) {
		while (conv.size() > S) {
			int b = conv.size() - 1;
			int a = b - 1;

			if (cp(vec(conv[a], conv[b]), vec(conv[b], pnts[i])) >= 0)
				conv.pop_back();
			else break;
		}
		conv.push_back(pnts[i]);
	}
	int Area = 0;
	S = conv.size();
}
