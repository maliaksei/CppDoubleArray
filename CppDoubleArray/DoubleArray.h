class DoubleArray
{
private: double * mass;
		 int count;

public:
	DoubleArray(double min, double max, int n);
	DoubleArray(int n);
	~DoubleArray();
	double GetArithmeticMean();
	void PrintMass();
	void PrintMaxElement();
	void PrintMinElement();
	void ChangeElementByIndex(double value, int index);
	void RemoveElementByIndex(int index);
};