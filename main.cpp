#include <iostream>;
#include <cmath>;
#include <fstream>;

float recurrence_f(int n)
{
	// calculates nth term in the recurrence relation with floats
	float p1 = 1.0f / 3, p0 = 1.0f, pn = 0.0f;
	if (n == 0)
	{
		return p0;
	}
	else if (n == 1)
	{
		return p1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			pn = 19.0f / 3 * p1 - 2.0f * p0;
			p0 = p1;
			p1 = pn;
		}
		return pn;
	}

}


double recurrence_d(int n)
{
	// calculates nth term in the recurrence relation with doubles
	double p1 = 1.0 / 3, p0 = 1.0, pn;
	if (n == 0)
	{
		return p0;
	}
	else if (n == 1)
	{
		return p1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			pn = 19.0 / 3 * p1 - 2.0 * p0;
			p0 = p1;
			p1 = pn;
		}
		return pn;
	}

}

float analytical(int n)
{
	// gives analytical solution of reccurence relation
	float ans = pow((1.0f / 3), n);
	return ans;
}

int main()
{
	// declare object 'File'
	std::ofstream File;

	// try to open File
	File.open("data1.txt");

	// if opening fails , exit main
	if (!File) return 1;

	// labelling data columns
	File.width(20); File << "n";
	File.width(20); File << "analytical";
	File.width(20); File << "reccurence";
	File.width(20); File << "relative error";
	File.width(20); File << "abs error" << std::endl;

	// importing data to File
	for (int i = 0; i <= 20; i++)
	{
		// abs error |x-x'|, relative error |(x-x')|/|x|
		File.width(20); File << i;
		File.width(20); File << analytical(i);
		File.width(20); File << recurrence_d(i);
		File.width(20); File << abs(analytical(i) - recurrence_d(i)) / abs(analytical(i));
		File.width(20); File << abs(analytical(i) - recurrence_d(i)) << std::endl;
	}
	File.close();

	// same for float data

	// declare object 'File2'
	std::ofstream File2;

	// try to open File2
	File2.open("data2.txt");

	//if opening fails , exit main
	if (!File2) return 1;

	// labelling data columns
	File2.width(20); File2 << "n";
	File2.width(20); File2 << "analytical";
	File2.width(20); File2 << "reccurence";
	File2.width(20); File2 << "relative error";
	File2.width(20); File2 << "abs error" << std::endl;

	for (int i = 0; i <=20; i++)
	{
		// abs error |x-x'|, relative error |(x-x')|/|x|
		File2.width(20); File2 << i;
		File2.width(20); File2 << analytical(i);
		File2.width(20); File2 << recurrence_f(i);
		File2.width(20); File2 << abs(analytical(i) - recurrence_f(i)) / abs(analytical(i));
		File2.width(20); File2 << abs(analytical(i) - recurrence_f(i)) << std::endl;
	}
	File2.close();
	return 0;
}