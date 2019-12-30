#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	std::string s = "-12456--789";
	std::regex number("(-?\\d*)(\\D)(-?\\d*)");

	std::sregex_iterator it(s.begin(), s.end(), number);
	std::sregex_iterator end;

	while(it != end)
	{
		std::smatch m = *it;
        string a =  m.str(1).c_str();
        cout << a;
		printf("%s\n%s\n%s\n",  m.str(1).c_str(), m.str(2).c_str(), m.str(3).c_str());

		++it;
	}

	return 0;
}