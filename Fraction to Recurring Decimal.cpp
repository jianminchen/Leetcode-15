class Solution {
	typedef long long int64;
public:
	string toString(int64 n)
	{
		stringstream s;
		s << n;
		return s.str();
	}
	string foo(int64 numerator, int64 denominator)
	{
		map< pair<int64, int64>, int > rep;
		string ans;
		int len = 0;
		while (numerator % denominator != 0)
		{
			pair<int64, int64> pr = make_pair(numerator, denominator);
			if (rep.count(pr))
			{
				len = rep[pr];
				break;
			}
			rep[make_pair(numerator, denominator)] = len;
			rep[pr] = len;
			ans += ('0' + numerator * 10 / denominator);
			numerator =  numerator * 10 % denominator;
			len++;
		}
		if (numerator % denominator != 0)
			return ans.substr(0, len) + "(" + ans.substr(len, ans.length()) + ")";
		else
			return ans;
	}
	int sign(int n)
	{
		if (n == 0)
			return 0;
		return n < 0 ? -1 : 1;
	}
	string fractionToDecimal(int numerator, int denominator) {
		int sg = sign(numerator) * sign(denominator);
		int64 numeratorLL = abs(1LL * numerator);
		int64 denominatorLL = abs(1LL * denominator);
		string ans = toString(numeratorLL / denominatorLL);
		if (sg < 0)
			ans = "-" + ans;
		if (numeratorLL % denominatorLL == 0)
			return ans;
		ans += '.';
		return ans + foo(numeratorLL % denominatorLL, denominatorLL);
	}
};
