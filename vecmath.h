#ifndef TTOBSI_VECMATH
#define TTOBSI_VECMATH

// debug use only
#include <iostream>

#include "ttobsi.h"
#include <type_traits>

template <int N, typename ElementType>
class TTOBSI_SquareMatrix {
    static_assert(N > 0, "Order of a Square Matrix must be greater than zero!");
    static_assert(std::is_arithmetic<ElementType>::value,
                  "Element type of a matrix must be a arithmetic type");

  public:
    // default constructor, identity matrix
    TTOBSI_SquareMatrix() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = (i == j); // nice implicit conversion
    }

    // construct with given array
    TTOBSI_SquareMatrix(ElementType src[N][N]) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = src[i][j];
    }

    // operator overload
    TTOBSI_SquareMatrix operator+(const TTOBSI_SquareMatrix &mB) const & {
        TTOBSI_SquareMatrix<N, ElementType> mC;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mC.m[i][j] = this->m[i][j] + mB.m[i][j];
        return mC;
    }

    TTOBSI_SquareMatrix operator-(const TTOBSI_SquareMatrix &mB) const & {
        TTOBSI_SquareMatrix<N, ElementType> mC;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mC.m[i][j] = this->m[i][j] - mB.m[i][j];
        return mC;
    }

    /* IMPORTANT: The order of multiplication is REVERSED
     * normal annotation you'll meet in math class
     *   mA mB v = v'
     * which is multiplying for right to left
     * however this isn't the case for c++
     *
     * thus, we do v mB mA = (v mB) mA = (v') mA
     * so mB mA in program is actualy mA mB in the normal mathematical form
     */
    TTOBSI_SquareMatrix operator*(const TTOBSI_SquareMatrix &mB) const & {
        TTOBSI_SquareMatrix<N, ElementType> mC;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                mC.m[i][j] = 0;
                for (int k = 0; k < N; k++)
                    mC.m[i][j] += mB.m[i][k] * (this->m[k][j]);
            }
        return mC;
    }

    TTOBSI_SquareMatrix operator*(ElementType a) const & {
        TTOBSI_SquareMatrix<N, ElementType> mB;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mB.m[i][j] = this->m[i][j] * a;
        return mB;
    }

    /*friend TTOBSI_SquareMatrix operator-(const TTOBSI_SquareMatrix &mA,
                                         const TTOBSI_SquareMatrix &mB);
    friend TTOBSI_SquareMatrix operator*(const TTOBSI_SquareMatrix &mA,
                                         const TTOBSI_SquareMatrix &mB);*/

    /*friend TTOBSI_Vector<N, ElementType>
    TOBSI_Vector<N, ElementType>::operator*(
        const TTOBSI_SquareMatrix<N, ElementType> &);*/

    //#ifdef TTOBSI_DEBUG
    // debug print
    void debug_print() {
        printf("TTOBSI_SquareMatrix size %d*%d , located at %p\n", N, N, this);
        printf("this->m at %p\n", this->m);
        printf("dumping this->m ...\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                std::cout << m[i][j] << ' ';
            puts("");
        }
    }
    //#endif

    //  private:
    ElementType m[N][N];
};

template <int N, typename ElementType>
class TTOBSI_Vector {
    static_assert(N > 0, "Order of a vector must be greater than zero!");
    static_assert(std::is_arithmetic<ElementType>::value,
                  "Element type of a vector must be a arithmetic type");

  public:
    TTOBSI_Vector() {
        for (int i = 0; i < N; i++)
            v[i] = 0;
    }

    TTOBSI_Vector(ElementType src[N]) {
        for (int i = 0; i < N; i++)
            v[i] = src[i];
    }

    TTOBSI_Vector(std::initializer_list<ElementType> src) {
        int i = 0;
        for (auto e: src) {
            v[i] = e; 
            i++;
        }
    }

    TTOBSI_Vector operator+(const TTOBSI_Vector &vB) const & {
        TTOBSI_Vector<N, ElementType> vC;
        for (int i = 0; i < N; i++)
            vC.v[i] = this->v[i] + vB.v[i];
        return vC;
    }

    TTOBSI_Vector operator-(const TTOBSI_Vector &vB) const & {
        TTOBSI_Vector<N, ElementType> vC;
        for (int i = 0; i < N; i++)
            vC.v[i] = this->v[i] - vB.v[i];
        return vC;
    }

    TTOBSI_Vector operator*(ElementType a) const & {
        TTOBSI_Vector<N, ElementType> vB;
        for (int i = 0; i < N; i++)
            vB.v[i] = this->v[i] * a;
        return vB;
    }

    /* this is DOT product, not cross product!
     */

    ElementType operator*(const TTOBSI_Vector &vB) const & {
        ElementType product = 0;
        for (int i = 0; i < N; i++)
            product += v[i] * vB.v[i];
        return product;
    }

    /* IMPORTANT: The order of multiplication is REVERSED
     * normal annotation you'll meet in math class
     *   mA mB v = v'
     * which is multiplying for right to left
     * however this isn't the case for c++
     *
     * thus, we do v mB mA = (v mB) mA = (v') mA
     * so mB mA in program is actualy mA mB in the normal mathematical form
     */
    TTOBSI_Vector
    operator*(const TTOBSI_SquareMatrix<N, ElementType> &mB) const & {
        TTOBSI_Vector<N, ElementType> vC;
        for (int i = 0; i < N; i++) {
            vC.v[i] = 0;
            for (int j = 0; j < N; j++) {
                vC.v[i] += v[j] * mB.m[i][j];
            }
        }
        return vC;
    }

    // debug print
    void debug_print() {
        printf("TTOBSI_Vector size %d , located at %p\n", N, this);
        printf("this->v at %p\n", this->v);
        printf("dumping this->v ...\n");
        for (int i = 0; i < N; i++) {
            std::cout << v[i] << ' ';
        }
        puts("");
    }

    //  private:
    ElementType v[N];
};

/*
template <int N, typename ElementType>
TTOBSI_SquareMatrix<N, ElementType>
operator+(const TTOBSI_SquareMatrix<N, ElementType> &mA,
          const TTOBSI_SquareMatrix<N, ElementType> &mB) {}
*/

typedef TTOBSI_SquareMatrix<2, TTOBSI_Num> TTOBSI_Matrix22n;
typedef TTOBSI_SquareMatrix<2, int> TTOBSI_Matrix22i;
typedef TTOBSI_SquareMatrix<3, TTOBSI_Num> TTOBSI_Matrix33n;
typedef TTOBSI_SquareMatrix<3, int> TTOBSI_Matrix33i;

typedef TTOBSI_Vector<2, TTOBSI_Num> TTOBSI_Vector2n;
typedef TTOBSI_Vector<2, int> TTOBSI_Vector2i;
typedef TTOBSI_Vector<3, TTOBSI_Num> TTOBSI_Vector3n;
typedef TTOBSI_Vector<3, int> TTOBSI_Vector3i;

#endif