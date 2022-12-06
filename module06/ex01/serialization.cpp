#include "serialization.hpp"

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
