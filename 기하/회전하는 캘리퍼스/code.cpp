// 먼저 볼록껍질 찾기

ll func() {
	S = conv.size();
	ll ret = 0;
	int idx = 1;

	for (int i = 1; i < S; i++) {
		ll t1 = cp(vec(conv[i - 1], conv[i]), vec(conv[i], conv[idx]));
		ret = max(ret, dist(conv[i - 1], conv[idx]));
		ret = max(ret, dist(conv[i], conv[idx]));

		while (1) {
			int idx2 = (idx + 1) % S;
			ll t2 = cp(vec(conv[i - 1], conv[i]), vec(conv[i], conv[idx2]));

			if (t1 > t2) {
				t1 = t2;
				idx = idx2;

				ret = max(ret, dist(conv[i - 1], conv[idx]));
				ret = max(ret, dist(conv[i], conv[idx]));
			}
			else break;
		}
	}
	return ret;
}
