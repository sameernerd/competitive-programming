/*
	frst lets build graph of given array
	straightforward to check cycle using floyd
	if a node is in cycle and have outdegree bigger than 1 it means there's a cycle that can always grow bigger so just return -1
	else notice that we almost make n steps of simulations and after that either number of pigons grow or stays same
	so just simulate for n moves
*/
#include <bits/stdc++.h>
using namespace std;


class MonsterFarm {
public:
	int numMonsters(vector <string> transforms);
};

typedef long long ll;

int d[55][55];
int out[55];
ll adj[55][55];
ll nu[2][55];

const ll mod = 1000000007;

int MonsterFarm::numMonsters(vector <string> transforms) {
	memset(d, 0, sizeof d);
	memset(out, 0, sizeof out);
	memset(adj, 0, sizeof adj);
	memset(nu, 0, sizeof nu);
	int n = transforms.size();
	for (int i = 0; i < n; i++){
		istringstream iss(transforms[i]);
		int t;
		while (iss >> t){
			out[i]++;
			t--;
			d[i][t] = 1;
			adj[i][t]++;
		}
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
	for (int i = 0; i < n; i++)
		if (d[0][i] && out[i] > 1 && d[i][i])
			return -1;
	nu[0][0] = 1;
	for (int s = 0; s < n; s++){
		memset(nu[1], 0, sizeof nu[1]);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			nu[1][j] = (nu[1][j] + 1LL * nu[0][i] * adj[i][j]) % mod;
		for (int i = 0; i < n; i++)
			nu[0][i] = nu[1][i];
	}
	ll ret = 0;
	for (int i = 0; i < n; i++)
		ret = (ret + nu[0][i]) % mod;
	return (int)ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MonsterFarm *obj;
	int answer;
	obj = new MonsterFarm();
	clock_t startTime = clock();
	answer = obj->numMonsters(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <string> p0;
	int p1;

	{
		// ----- test 0 -----
		string t0[] = { "2 3", "5 7", "2 4", "5", "6", "4", "7" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 5;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!