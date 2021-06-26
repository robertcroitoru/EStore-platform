#include "LRUCache.h"
#include <algorithm>
#include <stack>

using namespace std;

LRUCache::LRUCache(int capacity)
{
    // initializam atat campul, cat si capacitatea lui LRU
	this->capacity = capacity;
	lru.resize(capacity);
	lru.shrink_to_fit();
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
    for(vector<int>::iterator iter = requestsNo.begin(); iter != requestsNo.end(); iter++){

        if(lru.size() == lru.capacity()){ // daca se ajunge la capacitatea maxima, scoatem ultimul element din LRU

            lru.pop_back();
        }

        lru.insert(lru.begin(), (*iter)); // adaugam pe prima pozitie urmatorul element
    }

    return lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru = aux;
}
