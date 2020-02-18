#include <iostream>
#include <fstream>
#include <cstdlib>
#include "math.h"
using namespace std;

int main() {
	//constraint, number of types
	int M, N; 

	ifstream ifile;
	ifile.open("in\\c_medium.in");
	ifile >> M >> N;

	//number of slices of each types
	int *s = new int[N]; 
	for (int i = 0; i < N; i++)
		ifile >> s[i];

	//indicates whether a type is chosen
	int *c = new int[N];
	for (int i = 0; i < N; i++)
		c[i] = 0;

	//f[n][m] stores the max sum with the first n types under constraint m
	int** f = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		f[i] = new int[M + 1];
	for (int j = 0; j <= M; j++)
		f[0][j] = 0;

	//g[n][m]=1 indicates that under constraint m the nth type should be chosen
	int** g = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		g[i] = new int[M + 1];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			g[i][j] = 0;

	//dynamic programming
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (j < s[i - 1])
				f[i][j] = f[i - 1][j];
			else if (f[i - 1][j - s[i - 1]] + s[i - 1] > f[i - 1][j]) {
				f[i][j] = f[i - 1][j - s[i - 1]] + s[i - 1];
				g[i][j] = 1;
			}
			else f[i][j] = f[i - 1][j];
		}

	//retrieve chosen types from g
	for (int i = N, j = M; i >= 1; i--)
		if (g[i][j]) {
			c[i - 1] = 1;
			j -= s[i - 1];
		}

	ofstream ofile;
	ofile.open("out\\c_medium.out");
	ofile << f[N][M] << '\n';
	for (int i = 0; i < N; i++)
		if (c[i]) ofile << s[i] << ' ';

	return 0;
}


