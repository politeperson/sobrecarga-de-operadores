#include "matriz.h"

int main()
{
    Matrix<int> A(4,4,7);
    Matrix<int> B(4,4,1);
    Matrix<int> C(4,4,0);


    A.show("A:");
    B.show("B:");

    C = A + B;
    C.show("A + B:");

    C = A - B;
    C.show("A - B");

    C = A > B;
    C.show("MAX(A , B) : ");

    C = A < B;
    C.show("MIN(A , B) : ");

    C = A % B;//PROMEDIO
    C.show("PROMEDIO(A , B) : ");

    //MULTIPLICAIÓN
    A.resize(3 , 2);
    B.resize(2 , 3);
    C.resize(3 , 3);
    A.build_static(1);
    A.show("new A: ");
    B.build_static(5);
    B.show("new B: ");
    
    C.build_static(0);
    C = A * B;
    C.show("A * B : ");

    C.build_dinamic();
    C.show("C sin ordenar: ");
    C.ordenar('<');
    C.show("C ordenado descendentemente: ");
    C.ordenar('>');
    C.show("C ordenado ascendentemente: ");
    
    return 0;
}