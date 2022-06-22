#ifndef TTOBSI_VECMATH
#define TTOBSI_VECMATH

#include "ttobsi.h"
#include <initializer_list>
#include <type_traits>

class TTOBSI_Matrix33n;
class TTOBSI_Matrix22n;
class TTOBSI_Vector3n;
class TTOBSI_Vector2n;

class TTOBSI_Matrix33n {
  public:
    TTOBSI_Matrix33n();
    TTOBSI_Matrix33n(TTOBSI_Num src[3][3]);
    TTOBSI_Matrix33n(TTOBSI_Vector3n _x, TTOBSI_Vector3n _y,
                     TTOBSI_Vector3n _z);

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

    // debugging utilitys
    void debug_print();

  private:
    TTOBSI_Num m[3][3];
};

class TTOBSI_Matrix22n {
  public:
    TTOBSI_Matrix22n();
    TTOBSI_Matrix22n(TTOBSI_Num m[2][2]);
    TTOBSI_Matrix22n(TTOBSI_Vector2n _x, TTOBSI_Vector2n _y);
    TTOBSI_Matrix22n(TTOBSI_Num a1, TTOBSI_Num a2, TTOBSI_Num b1,
                     TTOBSI_Num b2);

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

    // debugging utilitys
    void debug_print();

  private:
    TTOBSI_Num m[2][2];
};

class TTOBSI_Vector3n {
  public:
    TTOBSI_Vector3n();
    TTOBSI_Vector3n(TTOBSI_Num a[3]);
    TTOBSI_Vector3n(TTOBSI_Num x, TTOBSI_Num y, TTOBSI_Num z);

    TTOBSI_Num getSquaredLength();
    TTOBSI_Num getLength();

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
    TTOBSI_Vector2n();
    TTOBSI_Vector2n(TTOBSI_Num a[2]);
    TTOBSI_Vector2n(TTOBSI_Num x, TTOBSI_Num y);

    TTOBSI_Num getSquaredLength();
    TTOBSI_Num getLength();

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