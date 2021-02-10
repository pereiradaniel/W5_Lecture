#include <iostream>

using namespace std;

unsigned int fib(unsigned int n)
{
	if (n == 0)
		throw "Index 0 is not a valid index.";
	if (n > 47)
		throw 10.3;

	unsigned int val1 = 0, val2 = 1;
	for (auto i = 0u; i < n; ++i)
	{
		auto tmp = val1 + val2;
		val2 = val1;
		val1 = tmp;
	}

	return val1;
}

int main()
{
	for (auto i = 1; i < 50; ++i)
	{
		try {
			cout << i << ". " << fib(i) << endl;
		}
		// Order is important!
		catch (...)
		{
			cout << "Catastrophic error!" << endl;
		}
		catch (const char* error) // Catch the string thrown by fib
		{
			cout << error << endl;
		}
		catch (double error)
		{
			cout << "The index was too big." << endl;
		}
	}
}
