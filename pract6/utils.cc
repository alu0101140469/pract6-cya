// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/10/2024 
// Archivo: utils.cc
// Descripción: Implementación de las funciones auxiliares para la lectura de cadenas desde archivos.

#include "utils.h"
#include <fstream>
#include <iostream>

// Función para leer las cadenas desde un archivo .txt
std::vector<std::string> leerCadenasDesdeArchivo(const std::string &rutaArchivo) {
    std::ifstream archivo(rutaArchivo); // Abrimos el archivo
    std::vector<std::string> cadenas; // Vector para almacenar las cadenas

    if (!archivo.is_open()) {
        // Si no se puede abrir el archivo, mostramos un mensaje de error
        std::cerr << "Error al abrir el archivo " << rutaArchivo << std::endl;
        return cadenas;
    }

    std::string cadena;
    // Leemos cada línea del archivo y la añadimos al vector de cadenas
    while (std::getline(archivo, cadena)) {
        cadenas.push_back(cadena);
    }

    return cadenas; // Devolvemos el vector con todas las cadenas leídas
}
