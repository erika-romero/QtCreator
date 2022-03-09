/*************************************************

    * Fecha: 28-02-2022
    * Autor:  Miguel Thomas
    * Materia: HPC-1
    * Tema: Implementacion del algoritmo de Regresion Lineal
    * Requerimientos:
    * 1.-Crear una clase que permita la manipulacion de los datos
    * (extraccion, normalizacion, entre otros) con eigen.
    * 2.-Crear una clase que permita implementar el modelo de Regresion Lineal, con eigen.

**************************************************/

#include "Extraccion/extraer.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <string.h>

int main(int argc, char *argv[]) {

    /* Se crea un objeto del tipo Extraer
     * para incluir los 3 argumentos que necesita el objeto. */

    Extraer extraerData(argv[1], argv[2], argv[3]);

    /* Se requiere probar la lectura del fichero y luego se requiere observar el dataset como un objeto
     * de matriz tipo dataFrame */

    std::vector<std::vector<std::string>> dataSET = extraerData.ReadCSV();
    int filas = dataSET.size()+1;
    int columnas = dataSET[0].size();
    Eigen::MatrixXd MatrizDATAF = extraerData.CSVtoEigen(dataSET,filas,columnas);

    /*Se imprime la matriz que contiene los datos del dataSET */

    std::cout << MatrizDATAF << std:: endl;

    return 0;
}
