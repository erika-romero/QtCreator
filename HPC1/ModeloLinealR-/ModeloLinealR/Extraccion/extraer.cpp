/*************************************************

    * Fecha: 28-02-2022
    * Autor:  Miguel Thomas
    * Materia: HPC-1
    * Tema: Implementacion del algoritmo de Regresion Lineal
    * Objetivo: Implementacion de la clase extraer
    * 1.Clase para la extraccion, manipulacion de datos

**************************************************/

#include "extraer.h"
#include <iostream>
#include <fstream> //Para el tratamiento de ficheros (csv)
#include <vector>
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>


/* Primer función miembro "ReadCSV": lectura de fichero csv. Se presenta como un vector
 * de vectores de tipo string.
 * La idea es leer linea por linea y almacenar cada una en un vector de vectores
 * de tipo string. */

std::vector<std::vector<std::string>> Extraer::ReadCSV(){ //ReadCSV es el nombre de la clase
    /*Abrir el fichero para lectura SOLAMENTE*/
    std::fstream Fichero(setDatos);
    /*Vector de vectores tipo string a entregar por partede la función */
    std::vector<std::vector<std::string>> datosString;
    /*Se itera a traves de cada linea y se divide el contenido dado por el separador provisto por el constructor*/
    // Almacenar cada linea
    std::string linea = "";
    while(getline(Fichero, linea)){
        /* se crea un vector para almacenar la fila */
        std::vector<std::string> vectorFila;
        /* Se separa segun el delimitador */
        boost::algorithm::split(vectorFila, linea, boost::is_any_of(delimitador));
        datosString.push_back(vectorFila); //inserta el vector en el vector de vectores
    }
    /*se cierra el fichero .csv */
    Fichero.close();
    /*se retorna el vector de vectores de tipo string*/
    return datosString;
}

/* se implementa la segunda función miembro, la cual tiene como mision
 * trasnformar el vector de vectores del tipo String, en una matrix Eigen.
 * La idea es simular un objeto DATAFRAME de pandas, para poder manipular los datos. */

Eigen::MatrixXd Extraer::CSVtoEigen(std::vector<std::vector<std::string>> SETdatos, int filas, int columnas){

    /*Se hace la pregunta si tiene cabecera o no el vector de vectores del tipo string.
     *Si tiene cabecera, de debe eliminar */

    if(header){
        filas = filas -1;
    }

    /* Se itera sobre cada registro del fichero (dataSet), a la vez que se almacena en una matrixXd de dimensión
     * filas por columnas. Principalmente, almacenará strings (porque llega un vector de vectores del tipo string).
     * La idea es hacer un casting de string a float (Es decir
     * cambiar el tipo de dato). */

    Eigen::MatrixXd MatrizDF(columnas, filas);

    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            MatrizDF(j,i) = atof(SETdatos[i][j].c_str());
        }
    }

    /* Se transpone la matriz dato que viene por columnas por filas, para retornarla */

    return MatrizDF.transpose();
}
