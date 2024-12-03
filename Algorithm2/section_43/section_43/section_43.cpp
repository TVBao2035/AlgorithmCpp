#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> storeWords;
	int length;
	cout << "Enter Length Of Store Words:" << endl;
	cin >> length;
	for (int i = 0; i < length; i++) {
		string temp; cin >> temp;
		storeWords.push_back(temp);
	}

	map<string, int> mapStringInt;
	int result = 0;
	int maxValue = 0;
	for (int i = 0; i < length; i++) {
		if (mapStringInt.find(storeWords[i]) != mapStringInt.end()) {
			auto temp = mapStringInt.find(storeWords[i]);
			maxValue = i - temp->second;
			if (maxValue > result) result = maxValue;
			maxValue = 0;
		}
		else {
			mapStringInt.insert(make_pair(storeWords[i], i));
		}
	}
	cout << result;
	return 0;
}