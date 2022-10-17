// Two methods to remove collision: Separate chaining and Open addressing
// Implements separate chaining
#include<iostream>
#include<cstring>
#include<list>
using namespace std;

class HashTable {
		static const int HashGroups = 10;
		list<pair<int, string>> table[HashGroups];

	public:
		bool isEmpty();
		int hashFunction(int key);
		void insertItem(int key, string value);
		void removeItem(int key);
		string searchTable(int key);
		void printTable();
};

bool HashTable::isEmpty()
{
	int sum = 0;
	for(int i = 0; i<HashGroups; i++) {
		sum += table[i].size();
	}
	if(!sum) return true;
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % HashGroups;
}

void HashTable::insertItem(int key, string value)
{
	int hashVal = hashFunction(key);
	auto &cell = table[hashVal];
	auto Itr = begin(cell);
	bool keyExists = false;
	for(; Itr!=end(cell); Itr++) {
		if(Itr->first == key) {
			keyExists = true;
			Itr->second = value;
			cout<<"[WARNING] Key exists! Item replaced!\n";
			break;
		}
	}
	if(!keyExists) {
		cell.emplace_back(key, value);
	}
	return;
}

void HashTable::removeItem(int key)
{
	int hashVal = hashFunction(key);
	auto &cell = table[hashVal];
	auto Itr = begin(cell);
	bool keyExists = false;
	for(; Itr!=end(cell); Itr++) {
		if(Itr->first == key) {
			keyExists = true;
			Itr = cell.erase(Itr);
			cout << "[INFO] Item removed!\n";
			break;
		}
	}

	if(!keyExists) {
		cout << "[WARNING] Item Not Found!\n";
	}

	return;
}

string HashTable::searchTable(int key)
{
	string ans = "";
	int hashVal = hashFunction(key);
	auto &cell = table[hashVal];
	auto Itr = begin(cell);
	bool keyExists = false;
	for(; Itr!=end(cell); Itr++) {
		if(Itr->first == key) {
			keyExists = true;
			ans = Itr->second;
			cout << "[INFO] Found! "<< key <<" --> ";
			break;
		}
	}

	if(!keyExists) {
		cout << "[WARNING] Item Not Found!\n";
	}

	return ans;
}

void HashTable::printTable()
{
	for(int i = 0; i<HashGroups; i++) {
		if(table[i].size() == 0) continue;

		auto Itr = table[i].begin();
		for(; Itr != table[i].end(); Itr++) {
			cout << "[INFO] Key: "<<Itr->first<<" Value: "<<Itr->second<<endl;
		}
	}

	return;
}

int main()
{
	cout.setf(ios::boolalpha);
	HashTable Ht;
	cout<<"IS_EMPTY: "<<Ht.isEmpty()<<endl;

	Ht.insertItem(105, "Tim");
	Ht.insertItem(528, "Tom");
	Ht.insertItem(401, "Hank");
	Ht.insertItem(103, "Harry");
	Ht.insertItem(386, "Pym");
	Ht.insertItem(202, "Jim");
	Ht.insertItem(507, "James");
	Ht.insertItem(454, "Hook");
	Ht.insertItem(109, "Rob");
	Ht.insertItem(109, "Bob");
	cout<<endl;

	Ht.removeItem(103);
	Ht.removeItem(100);

	cout<<"IS_EMPTY: "<<Ht.isEmpty()<<endl;
	
	cout << Ht.searchTable(105);

	cin.get();
}
