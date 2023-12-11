#include <datenstrukturen/hashtable.hpp>

namespace Datenstrukturen {

Hashtable::Hashtable() :
    hashfkt(std::hash<std::string>()),
    num_buckets(32)
{
}



}
