#include "triangle.h"

bool triangle::validate (double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0) return false;
    //
    return true;
};

triangle::triangle (): a(0.0), b(0.0), c(0.0) {}
triangle::triangle (double _a, double _b, double _c):
                 a(_a), b(_b), c(_c)
                 {
                    if (!validate(a,b,c)) throw NEG;
                 };


void triangle::set_a (double _a)
{
    if (!validate(_a,b,c)) throw NEG;
    a = _a;
};
void triangle::set_b (double _b) {b = _b;};
void triangle::set_c (double _c) {c = _c;};


complex::complex (double _re, double _im): re(_re), im(_im) {}; // member initialization

