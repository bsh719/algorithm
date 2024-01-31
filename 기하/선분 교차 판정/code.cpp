typedef long long ll;
typedef pair<ll, ll> pl;

pl vec(pl& p1, pl& p2) {
	return { p2.first - p1.first, p2.second - p1.second };
}
ll crp(pl p1, pl p2) {
	return p1.first * p2.second - p1.second * p2.first;
}
ll inp(pl p1, pl p2) {
	return p1.first * p2.first + p1.second * p2.second;
}

bool meet(pl& p1, pl& p2, pl& p3, pl& p4) {
	ll n1 = crp(vec(p1, p2), vec(p2, p3));
	ll n2 = crp(vec(p1, p2), vec(p2, p4));

	if (n1 < 0 && n2 < 0) return 0;
	if (n1 > 0 && n2 > 0) return 0;
	if (n1 == 0) {
		ll t = inp(vec(p1, p2), vec(p1, p3));
		ll t2 = inp(vec(p1, p2), vec(p1, p2));

		if (t >= 0 && t <= t2) return 1;
	}
	if (n2 == 0) {
		ll t = inp(vec(p1, p2), vec(p1, p4));
		ll t2 = inp(vec(p1, p2), vec(p1, p2));

		if (t >= 0 && t <= t2) return 1;
	}
	if (n1 == 0 && n2 == 0) {
		ll t = inp(vec(p1, p4), vec(p1, p3));
		if (t < 0) return 1;
		else return 0;
	}
	if (n1 == 0 || n2 == 0) return 0;

	n1 = crp(vec(p3, p4), vec(p4, p1));
	n2 = crp(vec(p3, p4), vec(p4, p2));

	if (n1 < 0 && n2 < 0) return 0;
	if (n1 > 0 && n2 > 0) return 0;
	return 1;
}
