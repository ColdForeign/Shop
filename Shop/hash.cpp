#include "hash.h"

Hash::Hash()
{
	this->hashCode = hashNew("");
}

Hash::Hash(string value)
{
	this->hashCode = this->hashNew(value);
}

void Hash::setHash(string value)
{
	this->hashCode = this->hashNew(value);
}

size_t Hash::getHash() const
{
	return this->hashCode;
}

bool Hash::operator!=(const Hash& hash)
{
	return (this->hashCode != hash.hashCode);
}

bool Hash::operator==(const Hash& hash)
{
	return (this->hashCode == hash.hashCode);
}

bool Hash::operator>(const Hash& hash)
{
	return (this->hashCode > hash.hashCode);
}

bool Hash::operator<(const Hash& hash)
{
	return (this->hashCode < hash.hashCode);
}

bool Hash::operator>=(const Hash& hash)
{
	return (this->hashCode >= hash.hashCode);
}

bool Hash::operator<=(const Hash& hash)
{
	return (this->hashCode <= hash.hashCode);
}

void Hash::operator=(const Hash& hash)
{
	this->hashCode = hash.hashCode;
}

void Hash::operator=(const size_t& hashCode)
{
	this->hashCode = hashCode;
}

ostream& operator<<(ostream& output, const Hash& hash)
{
	output << hash.getHash();
	return output;
}

Hash::~Hash()
{
	this->hashCode = 0;
}

