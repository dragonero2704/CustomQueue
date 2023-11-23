#include "macros.h"
#include "CustomQueue.hpp"

using namespace std;

int main()
{
	CustomQueue<int> q(4);
	info("Size: %ld", q.size());



	return 0;
}