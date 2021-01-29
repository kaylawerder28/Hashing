#include<iostream>
#include<string>
using namespace std;

class HashNode {
public:
	int key;
	string data;
	HashNode() {}
	HashNode(int k, string x) {
		key = k;
		data = x;
	}
};


class HashTable {
public:
	HashNode** table;
	int size = 0;
	HashTable(int n) {
		size = n;
		table = new HashNode*[n];
		for (int i = 0; i < n; i++) {
			table[i] = nullptr;
		}
	}
	int CalulateHash(int key) {
		int hash = key % size;

		//Linear Probing
		//int i = 1;
		//while (table[hash] !=nullptr && table[hash]->key != key) { 
		//	hash = (key + i) % size; 
		// i++;
		//}

		//Quadretic Probing
		//int i = 1;
		//while (table[hash] != nullptr && table[hash]->key != key) {
		//	hash = (key + i*i) % size;
		//  i++;
		//}

		//Double Hashing
		while (table[hash] != nullptr && table[hash]->key != key) {
			int hash2 = 7 - key % 7;
			hash = (hash + hash2) % size;
		}

		return hash;
	}


	void Insert(int key, string val) {
		HashNode* node = new HashNode(key, val);
		int hash = CalulateHash(key);
		table[hash] = node;
	}

	void Print() {
		cout << "--------PRINT-------" << endl;
		for (int i = 0; i < size; i++) {
			if (table[i] != nullptr)
				cout << i << "  " << table[i]->data << endl;
		}
		//cout <<"-----------------"<< endl;
	}

	void Search(int key) {

		int hash = CalulateHash(key);

		cout << "--------SEARCH-------" << endl;
		if (table[hash] == nullptr) {
			cout << "Element not found for key: " << key << endl;
		}
		else {
			cout << "Key: " << key << " | Data: " << table[hash]->data << endl;
		}

	}
	void Delete(int key) {
		int hash = CalulateHash(key);

		cout << "--------DELETE-------" << endl;
		if (table[hash] == nullptr) {
			cout << "No element to delete for key: " << key << endl;
		}
		else {
			cout << "Deleting...Key: " << key << " :Data: " << table[hash]->data << endl;
			delete table[hash];
			table[hash] = nullptr;
		}
	}
};


int main() {

	HashTable* ht = new HashTable(10);

	ht->Insert(20, "Thomas");	ht->Print();
	ht->Insert(30, "Bill");		ht->Print();
	ht->Insert(40, "Chris");	ht->Print();
	ht->Insert(24, "Emily");	ht->Print();
	ht->Insert(34, "Megan");	ht->Print();


	ht->Search(20);
	ht->Search(29);
	ht->Search(23);

	ht->Delete(24);				ht->Print();
	getchar();
}














