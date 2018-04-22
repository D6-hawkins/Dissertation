//vector <float, 3> vec;
struct  TRIANGLE{
	vector <float, 3> XYZ;
};
struct GRIDCELL {
	vector <float, 3> XYZ;
	double val[8];
};
struct ComputeShaderInput
{
	
};
[numthreads(1, 1, 1)]
void main()
{

}