/*************************************************

    * Fecha: 28-02-2022
    * Autor:  Miguel Thomas
    * Materia: HPC-1
    * Tema:
    * Objetivo:


**************************************************/

#ifndef EXTRAER_H
#define EXTRAER_H

#include <iostream>
#include <fstream> //Para el tratamiento de ficheros (csv)
#include <vector>
#include<eigen3/Eigen/Dense>

class Extraer
{
    /* Se presenta el constructor de los argumentos de entrada a la clase Extraer */
    /*Requerimientos
     * 1. Nombre del data set */
    std::string setDatos;
    /*2. Separador de columnas*/
    std::string delimitador; //Por cual estan separados por coma , csv (separado por comas) o por otros
    /*3. Si tiene cabecera o no, el dataset */
    bool header;
public:
    Extraer(std::string datos, std::string separador, bool head):
        setDatos(datos),
        delimitador(separador),
        header(head){}

    std::vector<std::vector<std::string>> ReadCSV();
    Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> SETdatos, int filas, int columnas);
};

#endif // EXTRAER_H
