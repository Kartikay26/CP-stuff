#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()

int main(){
	
// vector
	vector<int> v (10, 42);
	for (int i = 0; i < 10; ++i)
	{
		v[i] = 5*i - i*i/2;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for(auto x : v){
		cout << x << " ";
	}
	cout << endl;
	auto mm = max_element(all(v));
	cout << "max element is: " << *mm << " at v[" << mm-v.begin() <<"]\n";

// map
	map<int, string> m;
	m = {{1,"kartik"},{2,"lakshay"}};
	for(auto x : m){
		cout << x.first << ": " << x.second << endl;
	}

// set
	set<int> s;
	s.insert(all(v));
	for(auto i : s){
		cout << i << " ";
	}
	cout << endl;

// lexicographically ordered permutations
	vector<int> vc = {1,2,3};
	do
	{
		for(auto i : vc){
			cout << i << " ";
		}
		cout << endl;
	} while (next_permutation(vc.begin(), vc.end()));

// accumulate
// copy // inner_product
// for_each
}