#include <iostream>
using namespace std;
#define ll long long int
class complex {
    float r;
    float i;
    static int count;
public:
    complex() {}
    complex(int x, int y) {
        this->r = x;
        this->i = y;
        count++;
    }
    void display(void);
    complex operator+(complex);
    static void display_count(void) {
    	cout<<"Number of Objects: "<<count<<endl; 
    }
    friend void operator-(complex &c1);

};
int complex :: count = 0;
void complex :: display(void) {
    cout<<r<<" +  i"<<i<<endl;
}
complex complex:: operator+(complex c) {
	return complex(r+c.r, i+c.i);
}
void operator-(complex &c1) {
	c1.r = -c1.r;
	c1.i = -c1.i;
}

int main() {
	complex c1(2.5, 3.5), c2, c3;
	c2 = complex(1.6, 2.7);
	c3 = c1 + c3;
	c3.display();
	-c3;
	c3.display();
	complex::display_count();
	return 0;
}