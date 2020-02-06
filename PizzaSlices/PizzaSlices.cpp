#include <iostream>
#include <fstream> 
#include "math.h"
using namespace std;

const int MAXN = 1005;
int w[MAXN];   
int v[MAXN];
int f[MAXN][MAXN]; 
int res=0;
int main() {
	int M, N;

	ifstream ifile;
	ifile.open("in\\d_quite_big.in");
	ifile >> M >> N;

	int* s = new int[N];
	for (int i = 0; i < N; i++)
		ifile >> s[i];

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += s[i];

	cout << sum - M;
	system("pause");

	int** f = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		f[i] = new int[sum - M];
	cout << "possible";
	system("pause");

	for (int j = 0; j <= M; j++)
		f[0][j] = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (j < s[i - 1])
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = (f[i - 1][j] > f[i - 1][j - s[i - 1]] + s[i - 1]) ? f[i - 1][j] : (f[i - 1][j - s[i - 1]] + s[i - 1]);
		}

	ofstream ofile;
	ofile.open("out\\c_medium.out");
	ofile << f[N][M];

	return 0;
}


