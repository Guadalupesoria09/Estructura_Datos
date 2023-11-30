#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

struct AtletaNode;

struct Atleta {
    std::string nombre;
    int puntos;
    AtletaNode* bstNode;

    Atleta(const std::string& nombre, int puntos) : nombre(nombre), puntos(puntos), bstNode(nullptr) {}
};

struct AtletaNode {
    Atleta atleta;
    AtletaNode* left;
    AtletaNode* right;

    AtletaNode(const Atleta& atleta) : atleta(atleta), left(nullptr), right(nullptr) {}
};

class AtletaBST {
private:
    AtletaNode* root;

    AtletaNode* insert(AtletaNode* node, const Atleta& atleta) {
        if (node == nullptr) {
            return new AtletaNode(atleta);
        }

        if (atleta.nombre < node->atleta.nombre) {
            node->left = insert(node->left, atleta);
        } else if (atleta.nombre > node->atleta.nombre) {
            node->right = insert(node->right, atleta);
        }

        return node;
    }

    AtletaNode* search(AtletaNode* node, const std::string& nombre) const {
        if (node == nullptr || node->atleta.nombre == nombre) {
            return node;
        }

        if (nombre < node->atleta.nombre) {
            return search(node->left, nombre);
        }

        return search(node->right, nombre);
    }

public:
    AtletaBST() : root(nullptr) {}

    void insert(const Atleta& atleta) {
        root = insert(root, atleta);
    }

    AtletaNode* search(const std::string& nombre) const {
        return search(root, nombre);
    }

    void asignarBstNode(const Atleta& atleta, AtletaNode* bstNode) {
        AtletaNode* node = search(atleta.nombre);
        if (node != nullptr) {
            node->atleta.bstNode = bstNode;
        }
    }
};

int particion(std::vector<Atleta>& atletas, int low, int high) {
    int pivot = atletas[high].puntos;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (atletas[j].puntos > pivot) {
            i++;
            std::swap(atletas[i], atletas[j]);
        }
    }

    std::swap(atletas[i + 1], atletas[high]);
    return (i + 1);
}

void quickSort(std::vector<Atleta>& atletas, int low, int high) {
    std::stack<int> pila;
    pila.push(low);
    pila.push(high);

    while (!pila.empty()) {
        high = pila.top();
        pila.pop();
        low = pila.top();
        pila.pop();

        int pivot = particion(atletas, low, high);

        if (pivot - 1 > low) {
            pila.push(low);
            pila.push(pivot - 1);
        }

        if (pivot + 1 < high) {
            pila.push(pivot + 1);
            pila.push(high);
        }
    }
}

void mostrarTodosLosAtletas(const std::vector<Atleta>& atletas) {
    std::cout << "Lista de todos los atletas:\n";
    for (const auto& atleta : atletas) {
        std::cout << "Nombre: " << atleta.nombre << " - Puntos: " << atleta.puntos << std::endl;
    }
}

void buscarAtletaPorNombre(const AtletaBST& atletaBST, const std::string& nombre) {
    AtletaNode* encontrado = atletaBST.search(nombre);

    if (encontrado != nullptr) {
        std::cout << "Atleta encontrado:\n";
        std::cout << "Nombre: " << encontrado->atleta.nombre << " - Puntos: " << encontrado->atleta.puntos << std::endl;
    } else {
        std::cout << "Atleta no encontrado." << std::endl;
    }
}

void mostrarPodio(const std::vector<Atleta>& atletas, int numMostrar) {
    std::cout << "Podium:\n";
    for (int i = 0; i < std::min(numMostrar, static_cast<int>(atletas.size())); i++) {
        std::cout << "Rank " << (i + 1) << ": " << atletas[i].nombre << " - Puntos: " << atletas[i].puntos << std::endl;
    }
}

void verListaFemenil() {
    std::ifstream archivoListaF("ListaF.txt");

    if (!archivoListaF.is_open()) {
        std::cerr << "No se pudo abrir el archivo ListaF.txt" << std::endl;
        return;
    }

    std::cout << "Lista Femenil:\n";
    std::string nombre;

    while (std::getline(archivoListaF, nombre)) {
        std::cout << nombre << std::endl;
    }

    archivoListaF.close();
}

void registrarAtletaFemenil() {
    std::ofstream archivoListaF("ListaF.txt", std::ios::app); 
    if (!archivoListaF.is_open()) {
        std::cerr << "No se pudo abrir el archivo ListaF.txt" << std::endl;
        return;
    }

    std::string nombre;

    std::cout << "Ingrese el nombre del nuevo atleta femenil: ";
    std::getline(std::cin, nombre);

    archivoListaF << nombre << std::endl;

    std::cout << "Atleta femenil registrado exitosamente." << std::endl;

    archivoListaF.close();
}

void verListaVaronil() {
    std::ifstream archivoListaV("ListaV.txt");

    if (!archivoListaV.is_open()) {
        std::cerr << "No se pudo abrir el archivo ListaV.txt" << std::endl;
        return;
    }

    std::cout << "Lista Varonil:\n";
    std::string nombre;

    while (std::getline(archivoListaV, nombre)) {
        std::cout << nombre << std::endl;
    }

    archivoListaV.close();
}

void registrarAtletaVaronil() {
    std::ofstream archivoListaV("ListaV.txt", std::ios::app); 
    if (!archivoListaV.is_open()) {
        std::cerr << "No se pudo abrir el archivo ListaV.txt" << std::endl;
        return;
    }

    std::string nombre;

    std::cout << "Ingrese el nombre del nuevo atleta varonil: ";
    std::getline(std::cin, nombre);

    archivoListaV << nombre << std::endl;

    std::cout << "Atleta varonil registrado exitosamente." << std::endl;

    archivoListaV.close();
}

void mostrarMenu() {
    std::cout << "\n*** Menú ***\n";
    std::cout << "1. Mostrar todos los atletas\n";
    std::cout << "2. Buscar atleta por nombre\n";
    std::cout << "3. Mostrar Podium\n";
    std::cout << "4. Registrar atleta Femenil\n"; 
    std::cout << "5. Registrar atleta Varonil\n"; 
    std::cout << "6. Ver Lista Femenil\n";
    std::cout << "7. Ver Lista Varonil\n";  
    std::cout << "8. Salir\n"; 
}

int main() {
    std::vector<Atleta> atletas;
    AtletaBST atletaBST;

    std::ofstream archivoPuntajes("puntajes.txt");

    if (!archivoPuntajes.is_open()) {
        std::cerr << "No se pudo abrir el archivo puntajes.txt" << std::endl;
        return 1;
    }

    int numAtletas;

    std::cout << "Ingrese el número de atletas: ";
    std::cin >> numAtletas;
    std::cin.ignore();

    for (int i = 0; i < numAtletas; i++) {
        std::string nombre;
        int puntos;

        std::cout << "Nombre del atleta " << (i + 1) << ": ";
        std::getline(std::cin, nombre);
        std::cout << "Puntos del atleta " << (i + 1) << ": ";
        std::cin >> puntos;
        std::cin.ignore();

        Atleta atleta(nombre, puntos);
        atletaBST.insert(atleta);
        atletaBST.asignarBstNode(atleta, atleta.bstNode); 
        atletas.push_back(atleta);

        archivoPuntajes << nombre << " " << puntos << std::endl;
    }

    archivoPuntajes.close();

    quickSort(atletas, 0, numAtletas - 1);

    std::cout << "Ranking de los 12 mejores atletas:\n";
    for (int i = 0; i < std::min(12, numAtletas); i++) {
        std::cout << "Rank " << (i + 1) << ": " << atletas[i].nombre << " - Puntos: " << atletas[i].puntos << std::endl;
    }

   int opcion;
       do {
               mostrarMenu();
               std::cout << "Seleccione una opción (1-8): ";  
               std::cin >> opcion;
               std::cin.ignore();

               switch (opcion) {
                   case 1:
                       mostrarTodosLosAtletas(atletas);
                       break;
                   case 2: {
                       std::string nombreBusqueda;
                       std::cout << "Ingrese el nombre del atleta a buscar: ";
                       std::getline(std::cin, nombreBusqueda);
                       buscarAtletaPorNombre(atletaBST, nombreBusqueda);
                       break;
                   }
                   case 3: {
                       int numMostrar = 4;
                       mostrarPodio(atletas, numMostrar);
                       break;
                   }
                   case 4:
                       registrarAtletaFemenil();  
                       break;
                   case 5:
                       registrarAtletaVaronil();  
                       break;
                   case 6:
                       verListaFemenil();
                       break;
                   case 7:
                       verListaVaronil();  
                       break;
                   case 8:
                       std::cout << "¡Hasta luego!\n";
                       break;
                   default:
                       std::cout << "Opción no válida. Inténtelo de nuevo.\n";
               }
           } while (opcion != 8);

           return 0;
} 

