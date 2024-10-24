// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/10/2024 
// Archivo: main.cc 
// Descripción: Archivo principal que gestiona la ejecución del simulador de autómatas finitos, leyendo los archivos de entrada y ejecutando las simulaciones.

#include <iostream>
#include "automata.h"
#include "utils.h"

void mostrarAyuda() {
    std::cout << "Uso: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "El programa simula un autómata finito (NFA o DFA) con las especificaciones provistas en el archivo 'input.fa'." << std::endl;
    std::cout << "Luego evalúa una serie de cadenas, una por línea, contenidas en 'input.txt', para verificar si son aceptadas por el autómata." << std::endl;
    std::cout << "Formato del archivo 'input.fa':" << std::endl;
    std::cout << "  - Línea 1: Símbolos del alfabeto separados por espacios." << std::endl;
    std::cout << "  - Línea 2: Número total de estados." << std::endl;
    std::cout << "  - Línea 3: Estado inicial." << std::endl;
    std::cout << "  - Siguientes líneas: Especificaciones de los estados y transiciones." << std::endl;
    std::cout << std::endl;
    std::cout << "Opciones:" << std::endl;
    std::cout << "  --help    Muestra esta ayuda y finaliza." << std::endl;
}

int main(int argc, char *argv[]) {
    // Verificamos si el usuario ha solicitado la opción '--help'
    if (argc == 2 && std::string(argv[1]) == "--help") {
        mostrarAyuda();
        return 0;
    }

    // Verificamos que se proporcionen los argumentos correctos (input.fa y input.txt)
    if (argc != 3) {
        std::cerr << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl;
        std::cerr << "Pruebe './p06_automata_simulator --help' para más información." << std::endl;
        return 1;
    }

    // Creamos el autómata
    Automata automata;
    
    // Cargamos el autómata desde el archivo .fa
    if (!automata.cargarDesdeArchivo(argv[1])) {
        return 1; // Si hay un error, terminamos la ejecución
    }

    // Leemos las cadenas desde el archivo .txt
    std::vector<std::string> cadenas = leerCadenasDesdeArchivo(argv[2]);
    
    // Procesamos cada cadena de entrada y mostramos si es aceptada o rechazada
    for (const auto &cadena : cadenas) {
        if (automata.procesarCadena(cadena)) {
            std::cout << cadena << " --- Accepted" << std::endl;
        } else {
            std::cout << cadena << " --- Rejected" << std::endl;
        }
    }

    return 0;
}