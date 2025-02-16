//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include <functional>

using namespace std;

// Ejemplos de funciones para ilustrar los punteros a función
void func1(void){ cout << "Hola desde func1" << endl; }
void func2(int a){ cout << "2*a: " << 2*a << endl; }
float func3(float a){ return 3*a; }
double func4(double a, double b){ return a*b; }

// Functor
class Suma
{
	public:
		int operator()(int a, int b) const { return a + b; }
};

void test1();
void test2();
void test3();

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}

void test3()
{
	// Puntero a función lambda
	std::function<int(int, int)> pFunc1 = [](int a, int b)
	{
		return a * b;
	};
    int res1 = pFunc1(5, 6);
    cout << "Producto: " << res1 << endl;

    // Puntero a functor
    std::function<int(int, int)> pFunc2 = Suma();

    int res2 = pFunc2(15, 13);
    cout << "Suma: " << res2 << endl;
}

void test2()
{
	std::function<void(void)> pFunc1 = func1;
	std::function<void(int)> pFunc2 = func2;
	std::function<float(float)> pFunc3 = func3;
	std::function<double(double, double)> pFunc4 = func4;

	pFunc1();
	pFunc2(5);
	cout << pFunc3(1.5) << endl;
	cout << pFunc4(3.5, 2.5) << endl;
}

void test1()
{
	void (*pFunc1)(void) = func1;
	void (*pFunc2)(int) = func2;
	float (*pFunc3)(float) = func3;
	double (*pFunc4)(double, double) = func4;

	pFunc1();
	pFunc2(5);
	cout << pFunc3(1.5) << endl;
	cout << pFunc4(3.5, 2.5) << endl;
}
