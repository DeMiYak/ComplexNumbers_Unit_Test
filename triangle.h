#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include <iostream>
#include <cmath>

enum triangle_error {NEG, UNEQ};

class triangle
{
public:
    triangle ();
    triangle (double _a, double _b, double _c);
    ~triangle () {}

    void set_a (double _a);
    void set_b (double _b);
    void set_c (double _c);

    const double& get_a () const {return a; };
    const double& get_b () const {return b; };
    const double& get_c () const {return c; };

    double perimeter () const {return a + b + c; };
    double area () const {return 0.0; };

    static bool validate (double a, double b, double c);

private:
    double a, b, c;
};


class complex
{
public:
    complex (double _re = 0, double _im = 0);

    // Functions
    double Re () const {return re; }
    double Im () const {return im; }

    const double& get_Re() const {return re;}
    const double& get_Im() const {return im;}

    /**
    * @brief MultIm
    * @param
    * @return
    */
    complex MultIm (double d) const {return {-im*d, re*d};}
    complex DivIm (double d) const {if(d) return {im/d, -re/d}; else return {0, 0};}
    complex AddIm (double d) const {return {re, im + d};}
    complex SubIm (double d) const {return {re, im - d};}
    complex& PAddIm (double d) {im += d; return *this;}
    complex& PSubIm (double d) {im -= d; return *this;}

    // Methods
    double Mo() const {return sqrt(re*re + im*im);} // Module function
    complex Co() const {return {re,-im};}
    complex Swap() const {return {im, re};}
    //
    // Arithmetical attributions

    complex& operator = (const complex& a)
    {
        re = a.re;
        im = a.im;
        return *this;
    }

    complex operator + (double d) const                             // Add
    {
        return complex (re + d, im);
    }

    complex& operator += (double d)                                 // Add to the complex pair
    {
        re += d;
        return *this;
    }

    complex& operator -= (double d)
    {
        re -= d;
        return *this;
    }

    complex operator - (double d) const
    {
        return complex (re - d, im);
    }

    friend complex operator - (double d, complex a)
    {
        return complex(d - a.re, -a.im);
    }

    friend complex operator * (double d, complex a)
    {
        return complex (a.re*d, a.im*d);
    }

    complex operator * (double d) const
    {
        return complex (re*d, im*d);
    }
    complex& operator *= (double d)
    {
        re *= d;
        im *= d;
        return *this;
    }

    complex& operator *= (const complex& c)
    {
        double temp = re;
        re = re*c.re - im*c.im;
        im = temp*c.im + im*c.re;
        return *this;
    }

    complex operator / (double d) const
    {
        if(d) return complex(re/d, im/d);
        else return complex(re/0.0, im/0.0);
    }

    complex& operator /= (double d)
    {
        if(d)
        {
            re /= d;
            im /= d;
            return *this;
        }
        else
        {
            re = re/0.0; im = im/0.0;
            return *this;
        }
    }

    complex& operator /= (complex& c)
    {
        complex tempNum = (*this)*c.Co();
        std::cout << tempNum;
        const double reTemp = c.Mo()*c.Mo();
        re = tempNum.Re()/reTemp;
        im = tempNum.Im()/reTemp;
        return *this;
    }
    //

    // Arithmetical Operations with Complexes
    complex operator * (complex c)                                                     // Multiplication
    {
        return complex (c.re*this->re - this->im*c.im, c.re*this->im + this->re*c.im);
    }

    friend complex operator + (double d, complex c)                                     // Adding
    {
        return complex (d + c.re, c.im);
    }

    friend std::ostream& operator << (std::ostream &stream, complex c)                  // Output
    {
        stream << "(" << c.re << ", " << c.im << ")";
        return stream;
    }

    friend std::istream& operator >> (std::istream &stream, complex& c)                 // Input
    {
        stream >> c.re >> c.im;
        // std::cout << c.re <<' '<< c.im;
        return stream;
    }

    complex operator - (complex c) const                                               // Subtract
    {
        return complex(this->re - c.re, this->im - c.im);
    }

    bool operator == (complex& c)                                                       // Equivalence
    {
        if(c.re == this->re && c.im == this->im) return true;
        return false;
    }

    bool operator != (complex& c)                                                       // Inequivalence
    {
        if(c.re != this->re || c.im != this->im) return true;
        return false;
    }

    complex operator / (complex& c) const
    {
        double sq = c.Mo()*c.Mo();
        if(c.Mo() != 0)
            return {(this->re*c.re + this->im*c.im)/sq, (this->im*c.re - this->re*c.im)/sq};
        return complex(0, 0);
    }

    complex& operator += (const complex& c)                         // Plus one complex pair to the other
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    complex& operator -= (const complex& c)
    {
        re -= c.re;
        im -= c.im;
        return *this;
    }

    complex operator + (const complex& c) const                     // Plus two complex pairs
    {
        return complex (re + c.re, im + c.im);
    }

    // Unary operators
    complex& operator + ()
    {
        return *this;
    }

    complex& operator - ()
    {
        re = -re;
        im = -im;
        return *this;
    }
private:
    double re, im;
};



#endif // TRIANGLE_H_INCLUDED
