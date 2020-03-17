#include<bits/stdc++.h> 
using namespace std; 

class Complex { 
private: 
	int real, imag; 
public: 
	Complex(int r = 0, int i =0) {real = r; imag = i;} 
	
	// This is automatically called when '+' is used with 
	// between two Complex objects 
	Complex operator + (Complex const &obj) { 
		Complex res; 
		res.real = real + obj.real; 
		res.imag = imag + obj.imag; 
		return res; 
	} 
    friend ostream & operator << (ostream &out, const Complex &c) {
        out << c.real; 
        out << "+i" << c.imag << endl; 
        return out; 
    }
};   

class Box {
private:
    int l, b, h;
public:
    Box(int l = 0, int b = 0, int h = 0) {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    bool operator < (const Box &bx) const {
        return (l*b*h < bx.l*bx.b*bx.h);
    }
    friend ostream & operator << (ostream &out, const Box &bx) {
        out << bx.l << " " << bx.b << " " << bx.h << endl; 
        return out; 
    }
};

int main() 
{ 
	Complex c1(10, 5), c2(2, 4); 
	Complex c3 = c1 + c2; // An example call to "operator+" 
	cout << c3 ;

    Box b1(10, 4, 3), b2(12, 5, 1), b3(8, 5, 5);
    cout << (b1 < b3) << endl;

    Box arr[5];
    arr[4] = arr[3] = Box(1, 4, 5);
    arr[2] = b2;
    arr[1] = b1;
    arr[0] = b3;

    sort(arr, arr+5);
    for(auto x: arr)
        cout << x ;
}


