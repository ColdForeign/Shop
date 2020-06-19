#pragma once
#include <iostream>
using namespace std;
using std::hash;
using std::ostream;

class Hash
{
public:

	Hash();

	Hash(string value);

	size_t getHash() const;

	void setHash(string value);

	bool operator != (const Hash& hash);
	bool operator == (const Hash& hash);
	bool operator > (const Hash& hash);
	bool operator < (const Hash& hash);
	bool operator <= (const Hash& hash);
	bool operator >= (const Hash& hash);
	void operator = (const Hash& hash);
	void operator=(const size_t& hashCode);
	friend ostream& operator << (ostream& output, const Hash& hash);

	~Hash();

private:
	size_t hashCode;
	hash<string>hashNew;
};
