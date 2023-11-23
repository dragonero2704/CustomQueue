#include "macros.h"
#include "CustomQueue.hpp"
#include <queue>
using namespace std;

int main()
{
	CustomQueue<int> q(4);
	info("Size: %ld", q.size());


	return 0;
}