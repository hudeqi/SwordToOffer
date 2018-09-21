#include<iostream>
#include<string>
#include<vector>
using namespace std;

string solveEquation(string equation) {
	if (equation.length() <= 2)
		return "No solution";
	bool flag = false;
	double CoefficientX = 0.0;
	double Coefficient = 0.0;
	vector<string> tempLeft;
	vector<string> tempRight;
	char* equ = (char*)equation.data();
	const char* seq = "=";
	char* p = strtok(equ, seq);
	string left(p);
	p = strtok(NULL, seq);
	string right(p);
	if (right.length() == 0)
		return "No solution";
	char* leftp = (char*)left.data();
	const char* seqMath = "+";
	char* pl = strtok(leftp, seqMath);
	while (pl)
	{
		string s(pl);
		tempLeft.push_back(s);
		pl = strtok(NULL, seqMath);
	}
	vector<string> l;
	for (int i = 0; i < tempLeft.size(); i++) {
		string s = tempLeft[i];
		char* sc = (char*)s.data();
		const char* seqj = "-";
		char* ps = strtok(sc, seqj);
		int count = 0;
		while (ps)
		{
			count++;
			string pstr(ps);
			if (count == 1) {
				if (s[0] == '-')
					l.push_back("-" + pstr);
				else
				{
					l.push_back(pstr);
				}
			}
			else
			{
				l.push_back("-" + pstr);
			}
			ps = strtok(NULL, seqj);
		}
	}
	char* rightp = (char*)right.data();
	char* pr = strtok(rightp, seqMath);
	while (pr)
	{
		string s(pr);
		tempRight.push_back(s);
		pr = strtok(NULL, seqMath);
	}
	vector<string> r;
	for (int i = 0; i < tempRight.size(); i++) {
		string s = tempRight[i];
		char* sc = (char*)s.data();
		const char* seqj = "-";
		char* ps = strtok(sc, seqj);
		int count = 0;
		while (ps)
		{
			count++;
			string pstr(ps);
			if (count == 1) {
				if (s[0] == '-')
					r.push_back("-" + pstr);
				else
				{
					r.push_back(pstr);
				}
			}
			else
			{
				r.push_back("-" + pstr);
			}
			ps = strtok(NULL, seqj);
		}
	}
	for (int i = 0; i < l.size(); i++) {
		string str = l[i];
		string::size_type idx = str.find("x");
		if (idx == string::npos) {
			Coefficient += (atof(str.c_str()) * (-1));
		}
		else
		{
			if (str.length() == 1) {
				CoefficientX += 1;
			}
			else {
				if (str.length() == 2 && str[0] == '-') {
					CoefficientX += -1;
				}
				else {
					CoefficientX += atof(str.substr(0, str.length() - 1).c_str());
				}
			}
		}
	}
	for (int i = 0; i < r.size(); i++) {
		string str = r[i];
		string::size_type idx = str.find("x");
		if (idx == string::npos) {
			Coefficient += atof(str.c_str());
		}
		else
		{
			if (str.length() == 1) {
				CoefficientX += -1;
			}
			else
			{
				if (str.length() == 2 && str[0] == '-') {
					CoefficientX += 1;
				}
				else
				{
					CoefficientX += (atof(str.substr(0, str.length() - 1).c_str()) * (-1));
				}
			}
		}
	}
	const double EXP = 0.000001;
	if (abs(CoefficientX) <= EXP && abs(Coefficient) <= EXP) {
		return "Infinite solutions";
	}
	else if (abs(CoefficientX) <= EXP && abs(Coefficient) > EXP)
	{
		return "No solution";
	}
	else {
		int result = Coefficient / CoefficientX;
		string res = "x=" + to_string(result);
		return res;
	}
}

int main_SolveTheEqualtion() {
	string s1 = "-x=1";
	cout << solveEquation(s1)<<endl;
	system("pause");
	return 0;
}