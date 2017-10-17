#include "Changelog.h"
using namespace std;
void getChangeLog()
{
	ifstream changelog;
	string log;
	string fullLog;
	changelog.open("changelog.txt");

	while (!changelog.eof())
	{
		getline(changelog, fullLog);
		cout << fullLog << "\n";
	}
}
