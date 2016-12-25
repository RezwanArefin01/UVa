#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

int A, B, N;
bool state[1100][1100];
string move_names[6] = {
	"fill A",
	"fill B",
	"empty A",
	"empty B",
	"pour A B",
	"pour B A",
};

void bfs() {
	vector<int> mo;
	queue<pair<pair<int, int>, vector<int> > > q;
	q.push(make_pair(make_pair(0, 0), mo));
	while(!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		mo = q.front().second;
		q.pop();

		if(b == N) {
			for(int i = 0; i < mo.size(); i++)
				cout << move_names[mo[i]] << endl;
			printf("success\n");
			break;
		}

		int na = 0, nb = 0;
		if(a != A) {
			// fill a
			if(!state[A][b]) {
				state[A][b] = true;
				mo.push_back(0);
				q.push(make_pair(make_pair(A, b), mo));
				mo.pop_back();
			}
			na = a + b;
			nb = 0;
			if(na > A) {
				nb = na - A;
				na = A;
			}
			if(b != 0 && !state[na][nb]) {
				// pour from b to a
				state[na][nb] = true;
				mo.push_back(5);
				q.push(make_pair(make_pair(na, nb), mo));
				mo.pop_back();
			}
		}
		if(b != B) {
			// fill b
			if(!state[a][B]) {
				state[a][B] = true;
				mo.push_back(1);
				q.push(make_pair(make_pair(a, B), mo));
				mo.pop_back();
			}
			na = 0;
			nb = a + b;
			if(nb > B) {
				na = nb - B;
				nb = B;
			}
			if(a != 0 && !state[na][nb]) {
				// pour from a to b
				state[na][nb] = true;
				mo.push_back(4);
				q.push(make_pair(make_pair(na, nb), mo));
				mo.pop_back();
			}
		}
		if(a != 0 && !state[0][b]) {
			// empty a
			state[0][b] = true;
			mo.push_back(2);
			q.push(make_pair(make_pair(0, b), mo));
			mo.pop_back();
		}
		if(b != 0 && !state[a][0]) {
			// empty b
			state[a][0] = true;
			mo.push_back(3);
			q.push(make_pair(make_pair(a, 0), mo));
			mo.pop_back();
		}
	}
}

int main() {
	while(scanf("%d %d %d", &A, &B, &N) == 3) {
		memset(state, false, sizeof state);
		bfs();
	}
}
