#include <iostream>
#include <string>
using namespace std;

// Space optimized function to find length of Longest Common Subsequence
// of substring X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y)
{
	int m = X.length(), n = Y.length();

	// allocate storage for one-dimensional arrays curr and prev
	int curr[n + 1], prev[n + 1];

	// fill the lookup table in bottom-up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				curr[j] = 0;
			else
			{
				// if current character of X and Y matches
				if (X[i - 1] == Y[j - 1])
					curr[j] = prev[j - 1] + 1;

				// else if current character of X and Y don't match
				else
					curr[j] = max(prev[j], curr[j - 1]);
			}
		}

		// replace contents of previous array with current array
		for (int i = 0; i <= n; i++)
			prev[i] = curr[i];
	}

	// LCS will be last entry in the lookup table
	return curr[n];
}

// Longest Common Subsequence problem space optimized solution
int main()
{
	string X = "XMJYAUZ", Y = "MZJAWXU";

	cout << "The length of LCS is " << LCSLength(X, Y);

	return 0;
}
