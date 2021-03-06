#include<bits/stdc++.h>
using namespace std;


class MagicalSpheres {
public:
	int divideWork(int spheresCount, int fakeSpheresCount, int gnomesAvailable);
};

typedef long long ll;

int get_powers(ll n, ll p){
	int res = 0;
	for (ll power = p; power <= n; power *= p){
		res += n / power;
		if (power > n / p) break;
	}
	return res;
}

int nckcnt(ll n, ll k, ll p){
	return (get_powers(n, p) - get_powers(k, p) - get_powers(n - k, p));
}



int MagicalSpheres::divideWork(int spheresCount, int fakeSpheresCount, int gnomesAvailable) {
	for (int te = gnomesAvailable;; te--){
		int n = te, cnt = 0;
		bool div = 1;
		for (int i = 2; i*i <= n; i++){
			if (n%i == 0){
				cnt = 0;
				while (n%i == 0){
					n /= i;
					cnt++;
				}
				if (nckcnt(fakeSpheresCount + spheresCount, spheresCount, i) < cnt){
					div = 0;
					break;
				}
			}
		}
		if (n > 1 && nckcnt(fakeSpheresCount + spheresCount, spheresCount, n) < 1) div = 0;
		if (div) return te;
	}
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
	MagicalSpheres *obj;
	int answer;
	obj = new MagicalSpheres();
	clock_t startTime = clock();
	answer = obj->divideWork(p0, p1, p2);
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
		p0 = 3;
		p1 = 1;
		p2 = 3;
		p3 = 2;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 3;
		p1 = 3;
		p2 = 50;
		p3 = 20;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 4;
		p1 = 3;
		p2 = 4;
		p3 = 1;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 15634;
		p1 = 456;
		p2 = 5000;
		p3 = 4990;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
