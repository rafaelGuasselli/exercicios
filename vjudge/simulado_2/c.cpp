#include<bits/stdc++.h>

using namespace std;


int main() {
	int L, W, H; cin>>L>>W>>H;
	int l, w, h; cin>>l>>w>>h;

	int total1 = (L/l)*(W/w)*(H/h);
	int total4 = (L/l)*(W/h)*(H/w);
	
	int total2 = (L/h)*(W/l)*(H/w);
	int total5 = (L/h)*(W/w)*(H/l);
	
	int total3 = (L/w)*(W/h)*(H/l);
	int total6 = (L/w)*(W/l)*(H/h);

	cout<<max({total1, total2, total3, total4, total5, total6})<<endl;
	return 0;
}