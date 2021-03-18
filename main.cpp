//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  private:
  double re;

  public:
  Real(double a) : re{a}{}
  double GetReal()const {return re;}
  Real operator *(double n)const {
      Real r(re*n);
      return r;
  }
};

class Complex : public Real{
  private:
  double im;
 
  public:
  Complex(double x, double y) : Real(x),im{y}{}
  double GetImaginary()const {return im;}
  Complex operator* (double n)const {
     Complex r(GetReal()*n,GetImaginary()*n);
      return r;
  }
};

class Surreal : public Complex{
  private:
  double sur;
  
  public:
  Surreal(double x, double y, double z) : Complex(x,y),sur{z}{}
  double GetSurreal()const {return sur;}
  Surreal operator* (double n){
      Surreal r(GetReal()*n,GetImaginary()*n,GetSurreal()*n);
      return r;
    
  }
};
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
