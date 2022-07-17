#ifndef TTOBSI_VECMATH
#define TTOBSI_VECMATH

#include "ttobsi.h"

class TTOBSI_Matrix33n;
class TTOBSI_Matrix22n;
class TTOBSI_Vector3n;
class TTOBSI_Vector2n;

class TTOBSI_Matrix33n {
  public:
    // doesn't initialize by default: use getIdentity instead!
    TTOBSI_Matrix33n();
    //     / 0,0 0,1 0,2 \
    // m = | 1,0 1,1 1,2 |
    //     \ 2,0 2,1 2,2 /
    TTOBSI_Matrix33n(TTOBSI_Num src[3][3]);
    //     / a1 b1 c1 \
    // m = | a2 b2 c2 |
    //     \ a3 b3 c3 /
    // _a, _b, _c act as three base vector
    TTOBSI_Matrix33n(TTOBSI_Vector3n _a, TTOBSI_Vector3n _b,
                     TTOBSI_Vector3n _c);


    TTOBSI_Matrix33n getTranspose();

    // for most transform, there's probably a better method
    TTOBSI_Num getDeterminant();
    TTOBSI_Matrix33n getInverse();

    static TTOBSI_Matrix33n getIdentity();

    // operator overloads
    friend TTOBSI_Matrix33n operator-(const TTOBSI_Matrix33n &mA);

    friend TTOBSI_Matrix33n operator+(const TTOBSI_Matrix33n &mA,
                                      const TTOBSI_Matrix33n &mB);
    friend TTOBSI_Matrix33n operator-(const TTOBSI_Matrix33n &mA,
                                      const TTOBSI_Matrix33n &mB);
    friend TTOBSI_Matrix33n operator*(const TTOBSI_Matrix33n &mB,
                                      const TTOBSI_Matrix33n &mA);

    friend TTOBSI_Matrix33n operator*(const TTOBSI_Matrix33n &mB, TTOBSI_Num a);

    friend TTOBSI_Matrix33n operator*(const TTOBSI_Vector3n &vB,
                                      const TTOBSI_Matrix33n &mA);

    // these comparison compare EACH ELEMENT DIRECTLY, not their determinant,
    // thus there's no greater than or less than
    friend bool operator==(const TTOBSI_Matrix33n &mA,
                           const TTOBSI_Matrix33n &mB);
    friend bool operator!=(const TTOBSI_Matrix33n &mA,
                           const TTOBSI_Matrix33n &mB);

    // debugging utilities
    void debug_print();

  private:
    //     / 0,0 0,1 0,2 \
    // m = | 1,0 1,1 1,2 |
    //     \ 2,0 2,1 2,2 /
    TTOBSI_Num m[3][3];
};

class TTOBSI_Matrix22n {
  public:
    // doesn't initialize by default: use getIdentity instead!
    TTOBSI_Matrix22n();
    TTOBSI_Matrix22n(TTOBSI_Num m[2][2]);
    //     / a1 b1 \
    // m = \ a2 b2 /
    TTOBSI_Matrix22n(TTOBSI_Vector2n _a, TTOBSI_Vector2n _b);
    //     / a1 a2 \
    // m = \ b1 b2 /
    TTOBSI_Matrix22n(TTOBSI_Num a1, TTOBSI_Num a2, TTOBSI_Num b1,
                     TTOBSI_Num b2);

    TTOBSI_Matrix33n getTranspose();
    
    // for most transform, there's probably a better method
    TTOBSI_Num getDeterminant();
    TTOBSI_Matrix22n getInverse();
    

    static TTOBSI_Matrix22n getIdentity();

    // operator overloads
    friend TTOBSI_Matrix22n operator-(const TTOBSI_Matrix22n &mA);

    friend TTOBSI_Matrix22n operator+(const TTOBSI_Matrix22n &mA,
                                      const TTOBSI_Matrix22n &mB);
    friend TTOBSI_Matrix22n operator-(const TTOBSI_Matrix22n &mA,
                                      const TTOBSI_Matrix22n &mB);
    friend TTOBSI_Matrix22n operator*(const TTOBSI_Matrix22n &mB,
                                      const TTOBSI_Matrix22n &mA);

    friend TTOBSI_Matrix22n operator*(const TTOBSI_Matrix22n &mB, TTOBSI_Num a);

    friend TTOBSI_Matrix22n operator*(const TTOBSI_Vector2n &vB,
                                      const TTOBSI_Matrix22n &mA);

    // these comparison compare EACH ELEMENT DIRECTLY, not their determinant,
    // thus there's no greater than or less than
    friend bool operator==(const TTOBSI_Matrix22n &mA,
                           const TTOBSI_Matrix22n &mB);
    friend bool operator!=(const TTOBSI_Matrix22n &mA,
                           const TTOBSI_Matrix22n &mB);

    // debugging utilities
    void debug_print();

  private:
    //     / 0,0 0,1 \
    // m = \ 1,0 1,1 /
    TTOBSI_Num m[2][2];
};

class TTOBSI_Vector3n {
  public:
    // doesn't initialize by default!
    TTOBSI_Vector3n();
    TTOBSI_Vector3n(TTOBSI_Num a[3]);
    TTOBSI_Vector3n(TTOBSI_Num x, TTOBSI_Num y, TTOBSI_Num z);

    // this is useful for length comparison and is probably faster than getting length
    TTOBSI_Num getSquaredLength();
    TTOBSI_Num getLength();

    friend TTOBSI_Matrix33n::TTOBSI_Matrix33n(TTOBSI_Vector3n _a,
                                              TTOBSI_Vector3n _b,
                                              TTOBSI_Vector3n _c);

    // operator overloads
    friend TTOBSI_Vector3n operator-(const TTOBSI_Vector3n &vA);
    friend TTOBSI_Vector3n operator+(const TTOBSI_Vector3n &vA,
                                     const TTOBSI_Vector3n &vB);
    friend TTOBSI_Vector3n operator-(const TTOBSI_Vector3n &vA,
                                     const TTOBSI_Vector3n &vB);

    // dot product
    friend TTOBSI_Num operator*(const TTOBSI_Vector3n &vA,
                                const TTOBSI_Vector3n &vB);

    friend TTOBSI_Vector3n operator*(const TTOBSI_Vector3n &vB, TTOBSI_Num a);

    friend TTOBSI_Matrix33n operator*(const TTOBSI_Vector3n &vB,
                                      const TTOBSI_Matrix33n &mA);

    // its actually difficult to decide what these comparison operator mean
    friend bool operator==(const TTOBSI_Vector3n &vA,
                           const TTOBSI_Vector3n &vB);

  private:
    TTOBSI_Num v[3];
};

class TTOBSI_Vector2n {
  public:
    // doesn't initialize by default!
    TTOBSI_Vector2n();
    TTOBSI_Vector2n(TTOBSI_Num a[2]);
    TTOBSI_Vector2n(TTOBSI_Num x, TTOBSI_Num y);
    
    // this is useful for length comparison and is probably faster than getting length
    TTOBSI_Num getSquaredLength();

    TTOBSI_Num getLength();

    friend TTOBSI_Matrix22n::TTOBSI_Matrix22n(TTOBSI_Vector2n _a,
                                              TTOBSI_Vector2n _b);

    // operator overloads
    friend TTOBSI_Vector2n operator-(const TTOBSI_Vector2n &vA);
    friend TTOBSI_Vector2n operator+(const TTOBSI_Vector2n &vA,
                                     const TTOBSI_Vector2n &vB);
    friend TTOBSI_Vector2n operator-(const TTOBSI_Vector2n &vA,
                                     const TTOBSI_Vector2n &vB);
    // dot product
    friend TTOBSI_Num operator*(const TTOBSI_Vector2n &vA,
                                const TTOBSI_Vector2n &vB);

    friend TTOBSI_Vector2n operator*(const TTOBSI_Vector2n &vB, TTOBSI_Num a);

    friend TTOBSI_Matrix22n operator*(const TTOBSI_Vector2n &vB,
                                      const TTOBSI_Matrix22n &mA);

    // its actually difficult to decide what these comparison operator mean
    friend bool operator==(const TTOBSI_Vector2n &vA,
                           const TTOBSI_Vector2n &vB);

  private:
    TTOBSI_Num v[2];
};

#endif  