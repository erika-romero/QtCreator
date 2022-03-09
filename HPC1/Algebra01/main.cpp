/**************************************************
 * Fecha: 23-02-2022
 * Autor: Diego Bermúdez
 * Materia: HPC-1
 * Tema: Introducción Algebra Lineal con EIGEN
* **************************************************/

#include <iostream>
#include <eigen3/Eigen/Dense>

/****** Se definen tipos de datos (Matrices y vectores)*/
typedef Eigen::Matrix<float,3,3> MiMatrix33F;//Matrix 3x3 flotante
typedef Eigen::Matrix<float,3,1> MiVector3F;//Vector [3] flotante
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> MiMatrixD;//Matrix generica double

int main()
{
    //Declaraciones
    MiMatrix33F matriz33f;
    MiVector3F  vector3f;
    MiMatrixD   mat(5,5);

    //Inicialización en ceros
    matriz33f = MiMatrix33F::Zero();
    std::cout<<"Matriz 3x3 en ceros \n" <<std::endl<< matriz33f <<std::endl<<std::endl;

    //La matriz 3x3 debe ser identidad
    matriz33f = MiMatrix33F::Identity();
    std::cout<<"Matriz 3x3 identidad \n" <<std::endl<< matriz33f <<std::endl<<std::endl;

    //Se quiere el vector en aleatorio
    vector3f = MiVector3F::Random();
    std::cout<<"Vector 3 aleatorio \n" <<std::endl<< vector3f <<std::endl<<std::endl;

    //Ingrese valores a la matriz de 3x3
    matriz33f <<1,5,-8,0,3,-7,-4,5,6;
    std::cout<<"Matriz con valores \n" <<std::endl<< matriz33f <<std::endl<<std::endl;

    //El valor en la primera posición se debe cambiar a 10
    matriz33f(0,0) =10;
    std::cout<<"Matriz con valores editada\n" <<std::endl<< matriz33f <<std::endl<<std::endl;




    //Convertir un vector a filas
    int data[] = {0,-1,2,3};
    Eigen::Map<Eigen::RowVectorXi> vectorFila(data,4);
    std::cout<<"Vector[0] \n" <<std::endl<< vectorFila <<std::endl<<std::endl;

    //Aritmetica
    Eigen::Matrix2d mA;
    Eigen::Matrix2d mB;
    mA <<4,2,-2,0;
    mB <<0,1,-1,5;

    //Se hacen operaciones por ELEMENTO (elemento-wise)
    //Multiplicacos cada elemento de mA por cada elemento de mB
    Eigen::Matrix2d resultado = mA.array()*mB.array();
    std::cout<<"Producto \n" <<std::endl<< mA;
    std::cout<<"\n  *"<<std::endl;
    std::cout<<mB<<"\n"<<"  ="<<"\n"<<resultado <<std::endl<<std::endl;

    //Se hacen operaciones por ELEMENTO (elemento-wise)
    //Divididos cada elemento de mA por cada elemento de mB
    Eigen::Matrix2d resultado2 = mA.array()/mB.array();
    std::cout<<"Producto \n" <<std::endl<< mA;
    std::cout<<"\n  /"<<std::endl;
    std::cout<<mB<<"\n  ="<<"\n"<<resultado2 <<std::endl<<std::endl;

    std::cout<<"Producto de Matrices\n";
    resultado=mA*mB;
    std::cout<<mA<<" \n /<<  (elemento) \n" << mB <<"\n";

    //Acceso parcial a las Matrices
    Eigen::MatrixXf m = Eigen::MatrixXf::Random(4,4);

    std::cout<<"Matriz aleatoria 4x4 \n"<<m<<std::endl;
    //Se requiere una matriz que tenga el bloque interior
    //de la matriz m
    Eigen::Matrix2f bloque = m.block(1,1,2,2);//Se copia en bloque interno
    std::cout<<"\n Bloque Interno \n"<<bloque<<std::endl;

    //Se requiere cambiar el bloque interno de la matriz
    m.block(1,1,2,2)*=0;
    std::cout<<"Matriz 4*4 con ceros \n"<<m<<std::endl;

    //Se le suma 10 a la fila 1
    m.row(1).array()+=10;
    std::cout<<"Matriz 4*4 fila 1 + 10 \n"<<m<<std::endl;

    //Se quiere sumar 100 a la columna 3
    m.col(3).array()+=100;
    std::cout<<"Matriz 4*4 columna 3 + 100\n"<<m<<std::endl;

    std::cout << "Hello World!" <<std::endl;
    return 0;
}
