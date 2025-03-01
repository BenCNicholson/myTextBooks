#include <iostream>
using namespace std;

struct Vector {
	int sz;
	double* elem;
};

void vector_init(Vector &v, int s){
	v.elem = new double[s];
	v.sz=s;
}

//Function reads s integers and returns the sum
double v_read_sum(int s){
	Vector v;
	vector_init(v,s);
	for(int i=0;i!= s;i++){
		cin>>v.elem[i];
	}
	double sum = 0;
	for(int i=0; i <v.sz; i++){
		sum += v.elem[i];
	}
	return sum;
}


int main(){
	cout << "Hello World";
	struct Vector v;
	vector_init(v,10);
	cout << ("%d",v_read_sum(5));
}

