// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/10/2024 
// Archivo: automata.h 
// Descripción: Definición de la clase Automata que modela un autómata finito, ya sea determinista (DFA) o no determinista (NFA).

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <set>
#include <map>
#include <string>
#include <vector>

// Clase Automata para simular el comportamiento de DFAs y NFAs
class Automata {
public:
    Automata(); // Constructor por defecto
    bool cargarDesdeArchivo(const std::string &rutaArchivo); // Cargar la configuración del autómata desde un archivo .fa
    bool procesarCadena(const std::string &cadena); // Procesar una cadena de entrada y determinar si es aceptada
    void mostrarResultados(); // Mostrar los resultados de aceptación/rechazo de las cadenas procesadas

private:
    std::set<char> alfabeto; // Conjunto de símbolos de entrada del autómata
    std::set<int> estados; // Conjunto de estados del autómata
    int estadoInicial; // Estado inicial del autómata
    std::set<int> estadosFinales; // Conjunto de estados de aceptación
    std::map<std::pair<int, char>, std::set<int>> transiciones; // Mapa de transiciones (pares de estado y símbolo de entrada)

    bool esDeterminista; // Bandera para determinar si es un DFA o un NFA
    bool esCadenaAceptada(const std::string &cadena); // Simulación para comprobar si una cadena es aceptada por el autómata
};

#endif
