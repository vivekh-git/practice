#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	unordered_map<string,int> months;
	months["january"] = 31;
	months["feb"] = 28;

	cout << "jan:" << months.at("january") << endl;
	
	cout << "feb:" << months["feb"] << endl;
	
	
	return 0;
}