#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<long long int> mdc(long long int a,long long int  b) {
	long long int M, alpha, beta;
	
	vector<long long int> answer;
	vector<long long int> r;
	vector<long long int> q;
	vector<long long int> x;
	vector<long long int> y;
	int last_it;

	x.push_back(1);
	x.push_back(0);
	y.push_back(0);
	y.push_back(1);
	
	q.push_back((long long int) NULL);
	q.push_back((long long int) NULL);	
	
	if (a >= b) {
		r.push_back(a);
		r.push_back(b);
	}
	else {
		r.push_back(b);
		r.push_back(a);
	}
	
	for (int i = 2 ; r[i - 1] > 0 ; i++) {
		lldiv_t divresult = lldiv( r[i-2] , r[i-1] );
		cout << "quo: " << divresult.quot << endl;
		cout << "re: " << divresult.rem << endl;

		if (divresult.rem == 0) {
			cout << "last_it: " << endl;
			break;
		}
		
		r.push_back(divresult.rem);
		q.push_back(divresult.quot);
		x.push_back( x[i-2] - (q[i] * x[i-1]) );
		y.push_back( y[i-2] - (q[i] * y[i-1]) );

		last_it = i;
	}
	
	answer.push_back(r[last_it]);
	answer.push_back(x[last_it]);
	answer.push_back(y[last_it]);

	return answer;
}

int main() {
	long long int a,b;
	
	vector<long long int> answer;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	

	answer = mdc(a, b);
	cout << answer[0] << " " << answer[1] << " " << answer[2] << endl;
	
	return 0;
}
