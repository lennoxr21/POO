#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// 1. CLASE FECHA
class Fecha {
private:
    int dia;
    int mes;
    int ano;

public:
    Fecha() {
        dia = 1;
        mes = 1;
        ano = 2000;
    }

    Fecha(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    void imprimir() {
        cout << dia << "/" << mes << "/" << ano;
    }
};
// 2. CLASE CONTACTO
class Contacto {
protected: // atributos protegidos para que las clases hijas puedan acceder
    string nombre;
    string numero;
    string correo;
    string direccion;
    bool estaBloqueado;
    bool eliminado;
    Fecha fechaNacimiento;

public:
    Contacto(string nom, string num, string cor, string dir, Fecha fecha) {
        nombre = nom;
        numero = num;
        correo = cor;
        direccion = dir;
        fechaNacimiento = fecha;
        estaBloqueado = false;
        eliminado = false;
    }

    // Destructor virtual
    virtual ~Contacto() {}

    string getNombre() { return nombre; }
    string getNumero() { return numero; }
    bool getEstaBloqueado() { return estaBloqueado; }
    bool getEliminado() { return eliminado; }
    Fecha getFechaNacimiento() { return fechaNacimiento; }

    void setNumero(string num) { numero = num; }
    void setCorreo(string cor) { correo = cor; }

    void bloquear() { estaBloqueado = true; }
    void desbloquear() { estaBloqueado = false; }
    void eliminar() { eliminado = true; }

    int calcularEdad(int anoActual) {
        return anoActual - fechaNacimiento.getAno();
    }

    //Está parte hace que la clase sea abstracta y permite POLIMORFISMO
    virtual void mostrar(int anoActual) = 0;
};

// 3. CLASE HIJA 1 (ESTUDIANTE)
class ContactoEstudiante : public Contacto {
private:
    string carrera;
    string codigoEstudiante;

public:
    ContactoEstudiante(string nom, string num, string cor, string dir, Fecha fecha, string car, string cod)
        : Contacto(nom, num, cor, dir, fecha) {
        carrera = car;
        codigoEstudiante = cod;
    }

    // Aplicación de POLIMORFISMO:
    void mostrar(int anoActual) override {
        cout << "Tipo: ESTUDIANTE UNIVERSITARIO\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Codigo: " << codigoEstudiante << " | Carrera: " << carrera << endl;
        cout << "Telefono: " << numero << " | Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Estado: " << (estaBloqueado ? "Bloqueado" : "Activo") << endl;
        cout << "Fecha Nacimiento: ";
        fechaNacimiento.imprimir();
        cout << " (Edad: " << calcularEdad(anoActual) << " anos)\n";
    }
};

// 4. CLASE HIJA 2 (PROFESOR)
class ContactoProfesor : public Contacto {
private:
    string curso;
    string departamento;

public:
    ContactoProfesor(string nom, string num, string cor, string dir, Fecha fecha, string cur, string dep)
        : Contacto(nom, num, cor, dir, fecha) {
        curso = cur;
        departamento = dep;
    }

    // Aplicación de POLIMORFISMO:
    void mostrar(int anoActual) override {
        cout << "Tipo: PROFESOR UNIVERSITARIO\n";
        cout << "Nombre: Prof. " << nombre << endl;
        cout << "Curso que dicta: " << curso << " | Depto: " << departamento << endl;
        cout << "Telefono: " << numero << " | Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Estado: " << (estaBloqueado ? "Bloqueado" : "Activo") << endl;
        cout << "Fecha Nacimiento: ";
        fechaNacimiento.imprimir();
        cout << " (Edad: " << calcularEdad(anoActual) << " anos)\n";
    }
};

// 5. PROGRAMA PRINCIPAL (AGENDA)
int main() {
    system("color 02"); // Color de consola
    vector<Contacto*> agenda; // En está parte se guarda los punteros a Contacto para habilitar Polimorfismo
    int opcion = -1; //El ciclo del menú empieza con -1 para que entre al menos una vez y termina cuando el usuario elige 0.
    int anoActual = 2026;

    while (opcion != 0) {
        system("cls");

        cout << "========== AGENDA UNIVERSITARIA ==========\n";
        cout << "1) Registrar nuevo contacto\n";
        cout << "2) Editar contacto\n";
        cout << "3) Listar contactos\n";
        cout << "4) Eliminar contacto\n";
        cout << "5) Bloquear/Desbloquear contacto\n";
        cout << "6) Buscar contacto\n";
        cout << "7) Cumpleanos de hoy\n";
        cout << "0) Salir\n";
        cout << "==========================================\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "\n-> Error: Ingrese un numero valido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            system("pause");
            continue;
        }

        system("cls");

        if (opcion == 1) {
            int tipoContacto;
            cout << "--- TIPO DE CONTACTO ---\n";
            cout << "1) Estudiante Universitario\n";
            cout << "2) Profesor Universitario\n";
            cout << "Seleccione una opcion: ";
            cin >> tipoContacto;

            string nom, num, cor, dir;
            int d, m, a;

            cin.ignore(1000, '\n');

            cout << "\n--- REGISTRAR CONTACTO ---\n";
            cout << "Nombre: ";
            getline(cin, nom);
            cout << "Telefono: ";
            getline(cin, num);
            cout << "Correo: ";
            getline(cin, cor);
            cout << "Direccion: ";
            getline(cin, dir);

            cout << "Fecha de nacimiento (Dia Mes Ano separados por espacio): ";
            cin >> d >> m >> a;
            cin.ignore(1000, '\n');

            Fecha fecha(d, m, a);

            if (tipoContacto == 1) {
                string carrera, codigo;
                cout << "Carrera universitaria: ";
                getline(cin, carrera);
                cout << "Codigo de estudiante: ";
                getline(cin, codigo);

                // Polimorfismo: Se guarda un Estudiante como Contacto*
                agenda.push_back(new ContactoEstudiante(nom, num, cor, dir, fecha, carrera, codigo));
            } else {
                string curso, depto;
                cout << "Curso que dicta: ";
                getline(cin, curso);
                cout << "Departamento academico: ";
                getline(cin, depto);

                // Polimorfismo: Se guarda un Profesor como Contacto*
                agenda.push_back(new ContactoProfesor(nom, num, cor, dir, fecha, curso, depto));
            }

            cout << "\n-> Contacto registrado con exito!\n\n";
            system("pause");

        } else if (opcion == 2) {
            string nomBusqueda;
            cin.ignore(1000, '\n');
            cout << "--- EDITAR CONTACTO ---\n";
            cout << "Ingrese el nombre del contacto a editar: ";
            getline(cin, nomBusqueda);

            bool encontrado = false;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (agenda[i]->getNombre() == nomBusqueda && !agenda[i]->getEliminado()) {
                    string nuevoNum, nuevoCor;
                    cout << "Nuevo telefono: ";
                    getline(cin, nuevoNum);
                    cout << "Nuevo correo: ";
                    getline(cin, nuevoCor);

                    agenda[i]->setNumero(nuevoNum);
                    agenda[i]->setCorreo(nuevoCor);
                    cout << "\n-> Contacto actualizado con exito!\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "\n-> Contacto no encontrado.\n";
            cout << endl;
            system("pause");

        } else if (opcion == 3) {
            cout << "==========================================\n";
            cout << "            LISTA DE CONTACTOS            \n";
            cout << "==========================================\n";
            int cont = 0;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (!agenda[i]->getEliminado()) {
                    cont++;
                    cout << "\n------------------------------------------\n";
                    cout << "               CONTACTO " << cont << "               \n";
                    cout << "------------------------------------------\n";
                    // Esta parte ejecuta el mostrar() de Estudiante o Profesor automáticamente.
                    agenda[i]->mostrar(anoActual);
                }
            }
            if (cont == 0) cout << "\nNo hay contactos guardados o activos.\n";
            cout << "\n==========================================\n";
            system("pause");

        } else if (opcion == 4) {
            string nomBusqueda;
            cin.ignore(1000, '\n');
            cout << "--- ELIMINAR CONTACTO ---\n";
            cout << "Ingrese el nombre del contacto a eliminar: ";
            getline(cin, nomBusqueda);

            bool encontrado = false;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (agenda[i]->getNombre() == nomBusqueda && !agenda[i]->getEliminado()) {
                    agenda[i]->eliminar();
                    cout << "\n-> Contacto eliminado correctamente!\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "\n-> Contacto no encontrado.\n";
            cout << endl;
            system("pause");

        } else if (opcion == 5) {
            string nomBusqueda;
            cin.ignore(1000, '\n');
            cout << "--- BLOQUEAR / DESBLOQUEAR ---\n";
            cout << "Ingrese el nombre del contacto: ";
            getline(cin, nomBusqueda);

            bool encontrado = false;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (agenda[i]->getNombre() == nomBusqueda && !agenda[i]->getEliminado()) {
                    if (agenda[i]->getEstaBloqueado()) {
                        agenda[i]->desbloquear();
                        cout << "\n-> El contacto ha sido DESBLOQUEADO.\n";
                    } else {
                        agenda[i]->bloquear();
                        cout << "\n-> El contacto ha sido BLOQUEADO.\n";
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "\n-> Contacto no encontrado.\n";
            cout << endl;
            system("pause");

        } else if (opcion == 6) {
            string nomBusqueda;
            cin.ignore(1000, '\n');
            cout << "--- BUSCAR CONTACTO ---\n";
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nomBusqueda);

            bool encontrado = false;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (agenda[i]->getNombre() == nomBusqueda && !agenda[i]->getEliminado()) {
                    cout << "\n--- INFORMACION ENCONTRADA ---\n";
                    agenda[i]->mostrar(anoActual);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "\n-> Contacto no encontrado.\n";
            cout << endl;
            system("pause");

        } else if (opcion == 7) {
            int dHoy, mHoy;
            cout << "--- CUMPLEANOS DE HOY ---\n";
            cout << "Ingrese el dia de hoy (numero): ";
            cin >> dHoy;
            cout << "Ingrese el mes actual (numero): ";
            cin >> mHoy;

            cout << "\nContactos que cumplen anos hoy:\n";
            int cont = 0;
            for (size_t i = 0; i < agenda.size(); i++) {
                if (!agenda[i]->getEliminado()) {
                    Fecha f = agenda[i]->getFechaNacimiento();
                    if (f.getDia() == dHoy && f.getMes() == mHoy) {
                        cout << "- " << agenda[i]->getNombre()
                             << " (Telefono: " << agenda[i]->getNumero()
                             << ", Edad hoy: " << agenda[i]->calcularEdad(anoActual) << " anos)\n";
                        cont++;
                    }
                }
            }
            if (cont == 0) cout << "Nadie cumple anos hoy.\n";
            cout << endl;
            system("pause");

        } else if (opcion == 0) {
            cout << "Saliendo de la agenda... ¡Hasta luego!\n";
        } else {
            cout << "Opcion no valida. Intente de nuevo.\n\n";
            system("pause");
        }
    }

    // Esta parte libera la menoria
    for (size_t i = 0; i < agenda.size(); i++) {
        delete agenda[i];
    }

    return 0;
}
