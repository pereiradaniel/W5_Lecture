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

unsigned int fibR(unsigned int n)
{
	if (n <= 2)
		return 1;
	return fibR(n - 1) + fibR(n - 2);
}

int main()
{
	for (auto i = 1; i < 10; ++i)
	{
		try {
			cout << i << ". " << fibR(i) << endl;
		}
		catch (const char* error) // Catch the string thrown by fib
		{
			cout << error << endl;
		}
		catch (double error)
		{
			cout << "The index was too big." << endl;
		}
		// Order is important!
		// This must come at the end to catch all exceptions that
		// have not already been caught.
		catch (...)
		{
			cout << "Catastrophic error!" << endl;
		}
	}
}
