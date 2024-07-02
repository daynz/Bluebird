namespace Bluebird {
	__declspec(dllimport) void print();
}

int main()
{
	Bluebird::print();
	return 0;
}