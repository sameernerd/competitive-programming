#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;


class KidsGame {
public:
	int kthKid(int n, int m, int k);
};

const int maxn = 500000;

int segT[maxn * 4];
int n;

int query(int x, int idx = 1, int l = 0, int r = n - 1){
	if (l == r)return r;
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (segT[lidx] >= x) return query(x, lidx, l, mid);
	return query(x - segT[lidx], ridx, mid + 1, r);
}

void update(int x, int y, int idx = 1, int l = 0, int r = n - 1){
	if (l == r){
		segT[idx] += y;
		return;
	}
	int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
	if (x <= mid) update(x, y, lidx, l, mid);
	else update(x, y, ridx, mid + 1, r);
	segT[idx] = segT[lidx] + segT[ridx];
}

int KidsGame::kthKid(int _n, int m, int k) {
	memset(segT, 0, sizeof(segT));
	n = _n;
	for (int i = 0; i < n; i++) update(i, 1);
	int po = (m - 1) % n;
	for (int st = 0; st < n; st++){
		int idx = query(po + 1);
		if (idx + 1 == k) return st + 1;
		update(idx, -1);
		po = (po + m - 1) % (n - st - 1);
	}
	return -1;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	KidsGame *obj;
	int answer;
	obj = new KidsGame();
	clock_t startTime = clock();
	answer = obj->kthKid(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer) {
		cout << "Match :-)" << endl;
	}
	else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;
	int p3;

	{
		// ----- test 0 -----
		p0 = 5;
		p1 = 2;
		p2 = 3;
		p3 = 5;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 1;
		p1 = 10;
		p2 = 1;
		p3 = 1;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 99;
		p1 = 100;
		p2 = 99;
		p3 = 94;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 19999;
		p1 = 7;
		p2 = 5;
		p3 = 18019;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = 99999;
		p1 = 11111;
		p2 = 3;
		p3 = 69557;
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
