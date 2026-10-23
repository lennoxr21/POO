#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <limits>

using namespace std;

// CONFIGURACION VISUAL Y COLORES

#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10

// 1. CLASE ABSTRACTA: PRODUCTO TECNOLOGICO
class ProductoTecnologico {
protected:
    string id;
    string marca;
    double precio;
    string gama; // Baja, Media, Alta
    int vendidos; // Unidades vendidas de este producto

public:
    ProductoTecnologico(string _id, string _marca, double _precio, string _gama) {
        id = _id;
        marca = _marca;
        precio = _precio;
        gama = _gama;
        vendidos = 0; // Empieza en 0
    }

    // Suma las unidades vendidas (la llama Venta::agregarDetalle)
    void sumarVenta(int cant) { vendidos += cant; }

    virtual ~ProductoTecnologico() {}

    // Getters
    string getId() { return id; }
    string getMarca() { return marca; }
    double getPrecio() { return precio; }
    string getGama() { return gama; }

    // Metodos virtuales puros para Polimorfismo
    virtual void mostrar() = 0;
    virtual void guardarEnArchivo(ofstream &archivo) = 0;
};


// 2. RAMA 1: ACCESORIOS (Herencia)
class Accesorio : public ProductoTecnologico {
protected:
    string conexion; // Alambrico / Inalambrico

public:
    Accesorio(string _id, string _marca, double _precio, string _gama, string _con)
        : ProductoTecnologico(_id, _marca, _precio, _gama) {
        conexion = _con;
    }
};

class Mouse : public Accesorio {
private:
    bool tieneRgb;

public:
    Mouse(string _id, string _marca, double _precio, string _gama, string _con, bool _rgb)
        : Accesorio(_id, _marca, _precio, _gama, _con) {
        tieneRgb = _rgb;
    }

    void mostrar() override {
        cout << "[ACCESORIO - MOUSE] ID: " << id << " | Marca: " << marca
             << " | Precio: $" << precio << " | Conexion: " << conexion
             << " | RGB: " << (tieneRgb ? "Si" : "No") << "\n";
    }

    void guardarEnArchivo(ofstream &archivo) override {
        archivo << "MOUSE | " << id << " | " << marca << " | " << precio << " | " << gama << " | " << conexion << " | Vendidos: " << vendidos << "\n";
    }
};

class Teclado : public Accesorio {
private:
    bool tieneRgb;

public:
    Teclado(string _id, string _marca, double _precio, string _gama, string _con, bool _rgb)
        : Accesorio(_id, _marca, _precio, _gama, _con) {
        tieneRgb = _rgb;
    }

    void mostrar() override {
        cout << "[ACCESORIO - TECLADO] ID: " << id << " | Marca: " << marca
             << " | Precio: $" << precio << " | Conexion: " << conexion
             << " | RGB: " << (tieneRgb ? "Si" : "No") << "\n";
    }

    void guardarEnArchivo(ofstream &archivo) override {
        archivo << "TECLADO | " << id << " | " << marca << " | " << precio << " | " << gama << " | " << conexion << " | Vendidos: " << vendidos << "\n";
    }
};

// 3. RAMA 2: COMPUTADORAS (Herencia)

class Computadora : public ProductoTecnologico {
protected:
    string procesador;
    int ramGb;

public:
    Computadora(string _id, string _marca, double _precio, string _gama, string _proc, int _ram)
        : ProductoTecnologico(_id, _marca, _precio, _gama) {
        procesador = _proc;
        ramGb = _ram;
    }
};

class Laptop : public Computadora {
private:
    int almacenamientoGb;

public:
    Laptop(string _id, string _marca, double _precio, string _gama, string _proc, int _ram, int _alm)
        : Computadora(_id, _marca, _precio, _gama, _proc, _ram) {
        almacenamientoGb = _alm;
    }

    void mostrar() override {
        cout << "[COMPUTADORA - LAPTOP] ID: " << id << " | Marca: " << marca
             << " | Precio: $" << precio << " | Proc: " << procesador
             << " | RAM: " << ramGb << "GB | SSD: " << almacenamientoGb << "GB\n";
    }

    void guardarEnArchivo(ofstream &archivo) override {
        archivo << "LAPTOP | " << id << " | " << marca << " | " << precio << " | " << gama << " | " << ramGb << " | Vendidos: " << vendidos << "\n";
    }
};

class PcEscritorio : public Computadora {
private:
    string tipoTorre; // Media Torre / Torre Completa

public:
    PcEscritorio(string _id, string _marca, double _precio, string _gama, string _proc, int _ram, string _torre)
        : Computadora(_id, _marca, _precio, _gama, _proc, _ram) {
        tipoTorre = _torre;
    }

    void mostrar() override {
        cout << "[COMPUTADORA - PC] ID: " << id << " | Marca: " << marca
             << " | Precio: $" << precio << " | Proc: " << procesador
             << " | RAM: " << ramGb << "GB | Torre: " << tipoTorre << "\n";
    }

    void guardarEnArchivo(ofstream &archivo) override {
        archivo << "PC | " << id << " | " << marca << " | " << precio << " | " << gama << " | " << tipoTorre << " | Vendidos: " << vendidos << "\n";
    }
};

// 4. PERSONAS (Cliente y Vendedor)
class Persona {
protected:
    string nombre;
    int edad;
    string celular;

public:
    Persona(string _nombre, int _edad, string _celular) {
        nombre = _nombre;
        edad = _edad;
        celular = _celular;
    }
    virtual ~Persona() {}
    string getNombre() { return nombre; }
    virtual void mostrarDatos() = 0;
};

class Cliente : public Persona {
private:
    string codigoCliente;
public:
    Cliente(string _nombre, int _edad, string _celular, string _cod)
        : Persona(_nombre, _edad, _celular), codigoCliente(_cod) {}

    string getCodigo() { return codigoCliente; }

    void mostrarDatos() override {
        cout << "[CLIENTE] Cod: " << codigoCliente << " | Nombre: " << nombre
             << " | Edad: " << edad << " | Cel: " << celular << "\n";
    }
};

class Vendedor : public Persona {
private:
    double sueldo;
public:
    Vendedor(string _nombre, int _edad, string _celular, double _sueldo)
        : Persona(_nombre, _edad, _celular), sueldo(_sueldo) {}

    void mostrarDatos() override {
        cout << "[VENDEDOR] Nombre: " << nombre << " | Edad: " << edad
             << " | Cel: " << celular << " | Sueldo: $" << sueldo << "\n";
    }
};

// PARA LA FACTURA
void setColor(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string centrarTexto(const string& t, int ancho) {
    int total = ancho - (int)t.size();
    if (total < 0) return t.substr(0, ancho);
    int izq = total / 2;
    return string(izq, ' ') + t + string(total - izq, ' ');
}

string cortar(const string& t, int ancho) {
    return (int)t.size() > ancho ? t.substr(0, ancho - 1) + "." : t;
}

const int ANCHO_FACTURA = 66;

void lineaFactura(char borde, char relleno) {
    setColor(8);
    cout << "    " << borde << string(ANCHO_FACTURA, relleno) << borde << "\n";
}

void textoFactura(const string& texto, int color) {
    setColor(8);     cout << "    |";
    setColor(color); cout << centrarTexto(texto, ANCHO_FACTURA);
    setColor(8);     cout << "|\n";
}

void filaTotal(const string& etiqueta, double monto, int color) {
    setColor(8);     cout << "    |";
    setColor(color);
    cout << string(30, ' ') << left << setw(24) << etiqueta
         << right << setw(1) << "$" << setw(10) << fixed << setprecision(2) << monto << " ";
    setColor(8);     cout << "|\n";
}

// 5. CLASES DE VENTAS Y TRANSACCIONES

class DetalleVenta {
private:
    ProductoTecnologico* producto;
    int cantidad;
    double subtotal;

public:
    DetalleVenta(ProductoTecnologico* _prod, int _cant) {
        producto = _prod;
        cantidad = _cant;
        subtotal = producto->getPrecio() * cantidad;
    }

    void mostrarDetalle() {
        string desc = cortar(producto->getMarca() + " (" + producto->getGama() + ")", 29);

        setColor(8);  cout << "    |";
        setColor(15);
        cout << " " << left << setw(29) << desc
             << left << setw(8) << producto->getId()
             << right << setw(6) << cantidad
             << right << setw(10) << fixed << setprecision(2) << producto->getPrecio()
             << right << setw(11) << subtotal << " ";
        setColor(8);  cout << "|\n";
    }

};

class Venta {
private:
    int idVenta;
    string fecha;
    Cliente* cliente;
    Vendedor* vendedor;
    vector<DetalleVenta*> detalles;
    double totalGeneral;

public:
    Venta(int _id, string _fecha, Cliente* _cli, Vendedor* _vend) {
        idVenta = _id;
        fecha = _fecha;
        cliente = _cli;
        vendedor = _vend;
        totalGeneral = 0;
    }

    ~Venta() {
        for (size_t i = 0; i < detalles.size(); i++) delete detalles[i];
    }

    void agregarDetalle(ProductoTecnologico* prod, int cant) {
        DetalleVenta* detalle = new DetalleVenta(prod, cant);
        detalles.push_back(detalle);
        prod->sumarVenta(cant); // Cuenta las unidades vendidas
        totalGeneral += (prod->getPrecio() * cant);
    }

    void mostrarVenta(bool animado = false) {
        int pausa = animado ? 250 : 0;

        lineaFactura('+', '=');
        textoFactura("", 7);
        textoFactura("D O N    G I L E S    T E C H N O L O G Y", 11);
        textoFactura("RUC: 20123456789  -  Puno, Peru", 8);
        textoFactura("", 7);
        textoFactura("BOLETA DE VENTA ELECTRONICA", 14);
        textoFactura("N. B001-" + to_string(idVenta), 14);
        lineaFactura('+', '=');
        Sleep(pausa);

        string cli = cliente ? cliente->getNombre() + " (" + cliente->getCodigo() + ")" : "---";
        string ven = vendedor ? vendedor->getNombre() : "---";

        setColor(8);  cout << "    |";
        setColor(10); cout << " Fecha    : "; setColor(15);
        cout << left << setw(ANCHO_FACTURA - 12) << fecha;
        setColor(8);  cout << "|\n";

        setColor(8);  cout << "    |";
        setColor(10); cout << " Cliente  : "; setColor(15);
        cout << left << setw(ANCHO_FACTURA - 12) << cortar(cli, ANCHO_FACTURA - 13);
        setColor(8);  cout << "|\n";

        setColor(8);  cout << "    |";
        setColor(10); cout << " Vendedor : "; setColor(15);
        cout << left << setw(ANCHO_FACTURA - 12) << cortar(ven, ANCHO_FACTURA - 13);
        setColor(8);  cout << "|\n";
        lineaFactura('+', '-');
        Sleep(pausa);

        setColor(8);  cout << "    |";
        setColor(14);
        cout << " " << left << setw(29) << "DESCRIPCION"
             << left << setw(8) << "COD"
             << right << setw(6) << "CANT"
             << right << setw(10) << "P.UNIT"
             << right << setw(11) << "IMPORTE" << " ";
        setColor(8);  cout << "|\n";
        lineaFactura('+', '-');

        for (size_t i = 0; i < detalles.size(); i++) {
            detalles[i]->mostrarDetalle();
            Sleep(pausa);
        }
        lineaFactura('+', '-');

        double baseImponible = totalGeneral / 1.18;
        double igv = totalGeneral - baseImponible;
        filaTotal("OP. GRAVADA:", baseImponible, 15);
        filaTotal("IGV (18%):", igv, 15);
        lineaFactura('+', '-');
        filaTotal("TOTAL A PAGAR:", totalGeneral, 10);
        lineaFactura('+', '=');
        Sleep(pausa);

        textoFactura("", 7);
        textoFactura("||| || ||||| | |||| || ||| |||| | |||", 7);
        textoFactura("Gracias por su compra - Vuelva pronto", 11);
        textoFactura("", 7);
        lineaFactura('+', '=');
        setColor(Color_Def);
    }
};

// 6. INTERFAZ VISUAL
void titulo(void) {
    const int ANCHO = 100;
    auto color = [](int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); };
    auto centrar = [](const string& t, int ancho) {
        int total = ancho - (int)t.size();
        if (total < 0) return t.substr(0, ancho);
        int izq = total / 2;
        return string(izq, ' ') + t + string(total - izq, ' ');
    };
    auto fila = [&](const string& texto, int c) {
        color(8); cout << "    |";
        color(c); cout << centrar(texto, ANCHO);
        color(8); cout << "|" << endl;
    };
    auto caja = [&](const string l[7], int interior, string r[9]) {
        r[0] = "+" + string(interior, '-') + "+";
        for (int i = 0; i < 7; i++) r[i + 1] = "|" + centrar(l[i], interior) + "|";
        r[8] = "+" + string(interior, '-') + "+";
    };

    color(8);
    cout << "    +" << string(ANCHO, '=') << "+" << endl;
    fila("", 7);
    fila("D O N    G I L E S    T E C H N O L O G Y", 11);
    fila(string(44, '_'), 11);
    fila("", 7);
    fila("VENTA DE:    ACCESORIOS    *    LAPTOPS    *    COMPUTADORAS", 10);
    fila("", 7);
    color(8);
    cout << "    +" << string(ANCHO, '-') << "+" << endl;
    fila("", 7);

    string vid[7] = { "", "", "", "", "", "", "" };
    string pue[7] = { "ABIERTO", "+-----++-----+", "|     ||     |", "|    o||o    |", "|     ||     |", "|     ||     |", "|_____||_____|" };

    string v1[9], v2[9], dr[9];
    caja(vid, 30, v1);
    caja(vid, 30, v2);
    caja(pue, 14, dr);

    string sep(5, ' ');
    for (int i = 0; i < 9; i++) {
        color(8);  cout << "    |" << sep;
        color(11); cout << v1[i];
        color(8);  cout << sep;
        color(14); cout << dr[i];
        color(8);  cout << sep;
        color(11); cout << v2[i];
        color(8);  cout << sep << "|" << endl;
    }

    fila("", 7);
    color(8);
    cout << "    +" << string(ANCHO, '=') << "+" << endl;
    cout << "    " << string(ANCHO + 2, '_') << endl;

    color(7);
}

void menuPrincipal(void) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout << "\n      ---------------------------------------------------------------------\n";
    cout << "             <<<<<<<<         MENU PRINCIPAL         >>>>>>>>";
    cout << "\n      ---------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout << "      (1) GESTION DE INVENTARIO (Accesorios y Computadoras)\n";
    cout << "      (2) GESTION DE PERSONAS (Clientes y Vendedores)\n";
    cout << "      (3) REALIZAR UNA VENTA\n";
    cout << "      (4) VER VENTAS Y ARCHIVO LOCAL\n";
    cout << "      (5) SALIR\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout << "\n                                             PROYECTO - POO C++ \n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout << "      Ingrese el numero de la opcion : ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

// GUARDAR EL INVENTARIO EN EL ARCHIVO
// Se llama cada vez que cambia algo (registrar producto o hacer una venta)
void guardarInventario(vector<ProductoTecnologico*> &inventario) {
    ofstream archivoOut("inventario.txt");
    for (size_t i = 0; i < inventario.size(); i++) {
        inventario[i]->guardarEnArchivo(archivoOut);
    }
    archivoOut.close();
}

// 7. PROGRAMA PRINCIPAL
int main() {
    SetConsoleTitle("SISTEMA DE VENTAS - TIENDA DON GILES TECHNOLOGY");

    vector<ProductoTecnologico*> inventario;
    vector<Cliente*> clientes;       // Vector exclusivo para Clientes
    vector<Vendedor*> vendedores;    // Vector exclusivo para Vendedores
    vector<Venta*> ventasRealizadas;

    int opcion = 0;
    int contadorVentas = 100;

    // Datos iniciales de prueba
    inventario.push_back(new Mouse("M01", "Logitech", 35.0, "Media", "Inalambrico", true));
    inventario.push_back(new Teclado("T01", "Razer", 85.0, "Alta", "Alambrico", true));
    inventario.push_back(new Laptop("L01", "Asus", 1200.0, "Alta", "Intel i7", 16, 512));
    inventario.push_back(new PcEscritorio("PC01", "HP", 950.0, "Media", "Ryzen 5", 8, "Media Torre"));

    clientes.push_back(new Cliente("Pedro Picapiedra", 30, "999111222", "CLI01"));
    vendedores.push_back(new Vendedor("Don Gil", 55, "912345678", 1500.0));

    do {
        system("cls");
        titulo();
        menuPrincipal();

        // VALIDACIÓN PARA EVITAR BUCLES CON LETRAS
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1: { // GESTION DE INVENTARIO
                int opInv = 0;
                do {
                    system("cls");
                    titulo();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
                    cout << "\n--- SUBMENU: GESTION DE INVENTARIO ---\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
                    cout << "1) Ver todo el Inventario\n";
                    cout << "2) Registrar Accesorio (Mouse / Teclado)\n";
                    cout << "3) Registrar Computadora (Laptop / PC)\n";
                    cout << "4) Volver al Menu Principal\n";
                    cout << "Seleccione una opcion: ";

                    if (!(cin >> opInv)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        opInv = 0;
                        continue;
                    }

                    if (opInv == 1) {
                        system("cls");
                        titulo();
                        cout << "\n==========================================\n";
                        cout << "         LISTA DEL INVENTARIO             \n";
                        cout << "==========================================\n";
                        if (inventario.empty()) {
                            cout << "Inventario vacio.\n";
                        } else {
                            for (size_t i = 0; i < inventario.size(); i++) {
                                cout << i + 1 << ". ";
                                inventario[i]->mostrar();
                            }
                        }
                        cout << "\n==========================================\n";
                        system("pause");
                    }
                    else if (opInv == 2) { // Registrar Accesorio
                        int tipoAcc;
                        cout << "\nQue accesorio desea registrar?\n1) Mouse\n2) Teclado\nOpcion: ";
                        if (!(cin >> tipoAcc)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            tipoAcc = 0;
                        }

                        string id, marca, gama, conexion;
                        double precio;
                        int rgb;

                        cin.ignore(1000, '\n');
                        cout << "ID: "; getline(cin, id);
                        cout << "Marca: "; getline(cin, marca);
                        cout << "Precio ($): "; cin >> precio;
                        cin.ignore(1000, '\n');
                        cout << "Gama (Baja/Media/Alta): "; getline(cin, gama);
                        cout << "Conexion (Alambrico/Inalambrico): "; getline(cin, conexion);
                        cout << "Tiene RGB? (1: Si / 0: No): "; cin >> rgb;

                        if (tipoAcc == 1) {
                            inventario.push_back(new Mouse(id, marca, precio, gama, conexion, (rgb == 1)));
                        } else {
                            inventario.push_back(new Teclado(id, marca, precio, gama, conexion, (rgb == 1)));
                        }
                        cout << "\n-> Accesorio registrado con exito!\n";
                        guardarInventario(inventario); // guarda al instante
                        system("pause");
                    }
                    else if (opInv == 3) { // Registrar Computadora
                        int tipoComp;
                        cout << "\nQue computadora desea registrar?\n1) Laptop\n2) PC de Escritorio\nOpcion: ";
                        if (!(cin >> tipoComp)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            tipoComp = 0;
                        }

                        string id, marca, gama, proc;
                        double precio;
                        int ram;

                        cin.ignore(1000, '\n');
                        cout << "ID: "; getline(cin, id);
                        cout << "Marca: "; getline(cin, marca);
                        cout << "Precio ($): "; cin >> precio;
                        cin.ignore(1000, '\n');
                        cout << "Gama (Baja/Media/Alta): "; getline(cin, gama);
                        cout << "Procesador: "; getline(cin, proc);
                        cout << "Memoria RAM (GB): "; cin >> ram;

                        if (tipoComp == 1) {
                            int alm;
                            cout << "Almacenamiento SSD (GB): "; cin >> alm;
                            inventario.push_back(new Laptop(id, marca, precio, gama, proc, ram, alm));
                        } else {
                            string torre;
                            cin.ignore(1000, '\n');
                            cout << "Tipo de Torre (Media Torre / Torre Completa): "; getline(cin, torre);
                            inventario.push_back(new PcEscritorio(id, marca, precio, gama, proc, ram, torre));
                        }
                        cout << "\n-> Computadora registrada con exito!\n";
                        guardarInventario(inventario); // guarda al instante
                        system("pause");
                    }
                } while (opInv != 4);

                guardarInventario(inventario);
                break;
            }

            case 2: { // GESTION DE PERSONAS
                int opPers = 0;
                do {
                    system("cls");
                    titulo();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
                    cout << "\n--- SUBMENU: GESTION DE PERSONAS ---\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
                    cout << "1) Ver Lista de Personas (Clientes y Vendedores)\n";
                    cout << "2) Registrar Nuevo Cliente\n";
                    cout << "3) Registrar Nuevo Vendedor\n";
                    cout << "4) Volver al Menu Principal\n";
                    cout << "Seleccione una opcion: ";

                    if (!(cin >> opPers)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        opPers = 0;
                        continue;
                    }

                    if (opPers == 1) {
                        system("cls");
                        titulo();
                        cout << "\n==========================================\n";
                        cout << "       LISTA DE PERSONAS REGISTRADAS      \n";
                        cout << "==========================================\n";
                        if (clientes.empty() && vendedores.empty()) {
                            cout << "No hay personas registradas.\n";
                        } else {
                            cout << "--- CLIENTES ---\n";
                            if (clientes.empty()) cout << "(No hay clientes)\n";
                            for (size_t i = 0; i < clientes.size(); i++) {
                                clientes[i]->mostrarDatos();
                            }

                            cout << "\n--- VENDEDORES ---\n";
                            if (vendedores.empty()) cout << "(No hay vendedores)\n";
                            for (size_t i = 0; i < vendedores.size(); i++) {
                                vendedores[i]->mostrarDatos();
                            }
                        }
                        cout << "==========================================\n";
                        system("pause");
                    }
                    else if (opPers == 2) { // Registrar Cliente
                        string nom, cel, cod;
                        int edad;

                        cin.ignore(1000, '\n');
                        cout << "\nNombre del Cliente: "; getline(cin, nom);
                        cout << "Edad: "; cin >> edad;
                        cin.ignore(1000, '\n');
                        cout << "Celular: "; getline(cin, cel);
                        cout << "Codigo de Cliente (ej. CLI02): "; getline(cin, cod);

                        clientes.push_back(new Cliente(nom, edad, cel, cod));
                        cout << "\n-> Cliente registrado con exito!\n";
                        system("pause");
                    }
                    else if (opPers == 3) { // Registrar Vendedor
                        string nom, cel;
                        int edad;
                        double sueldo;

                        cin.ignore(1000, '\n');
                        cout << "\nNombre del Vendedor: "; getline(cin, nom);
                        cout << "Edad: "; cin >> edad;
                        cin.ignore(1000, '\n');
                        cout << "Celular: "; getline(cin, cel);
                        cout << "Sueldo ($): "; cin >> sueldo;

                        vendedores.push_back(new Vendedor(nom, edad, cel, sueldo));
                        cout << "\n-> Vendedor registrado con exito!\n";
                        system("pause");
                    }
                } while (opPers != 4);
                break;
            }

            case 3: { // REALIZAR VENTA
                system("cls");
                titulo();
                if (inventario.empty() || clientes.empty() || vendedores.empty()) {
                    cout << "\nError: Se necesitan productos, clientes y vendedores para poder vender.\n";
                    system("pause");
                    break;
                }

                string fecha;
                cin.ignore(1000, '\n');
                cout << "\nIngrese fecha de venta (Ej: 20/10/2026): "; getline(cin, fecha);

                // Seleccionar cliente de forma directa
                cout << "\nSeleccione un Cliente:\n";
                for (size_t i = 0; i < clientes.size(); i++) {
                    cout << i << ") " << clientes[i]->getNombre() << " (Cod: " << clientes[i]->getCodigo() << ")\n";
                }
                int indiceCliente;
                cout << "Indice: ";
                cin >> indiceCliente;

                Cliente* cliSel = nullptr;
                if (indiceCliente >= 0 && indiceCliente < (int)clientes.size()) {
                    cliSel = clientes[indiceCliente];
                }

                // Seleccionar vendedor de forma directa
                cout << "\nSeleccione un Vendedor:\n";
                for (size_t i = 0; i < vendedores.size(); i++) {
                    cout << i << ") " << vendedores[i]->getNombre() << "\n";
                }
                int indiceVendedor;
                cout << "Indice: ";
                cin >> indiceVendedor;

                Vendedor* vendSel = nullptr;
                if (indiceVendedor >= 0 && indiceVendedor < (int)vendedores.size()) {
                    vendSel = vendedores[indiceVendedor];
                }

                if (cliSel == nullptr || vendSel == nullptr) {
                    cout << "\nError: Seleccion de cliente o vendedor invalida.\n";
                    system("pause");
                    break;
                }

                Venta* nuevaVenta = new Venta(contadorVentas++, fecha, cliSel, vendSel);

                string resp = "si";
                while (resp == "si" || resp == "SI" || resp == "Si") {
                    cout << "\nProductos disponibles:\n";
                    for (size_t i = 0; i < inventario.size(); i++) {
                        cout << i << ") "; inventario[i]->mostrar();
                    }
                    int indiceProducto, cant;
                    cout << "Elija el indice del producto: "; cin >> indiceProducto;
                    cout << "Cantidad: "; cin >> cant;

                    if (indiceProducto >= 0 && indiceProducto < (int)inventario.size()) {
                        nuevaVenta->agregarDetalle(inventario[indiceProducto], cant);
                        cout << "-> Producto agregado a la venta.\n";
                    } else {
                        cout << "-> Indice de producto invalido.\n";
                    }
                    cout << "Desea agregar otro producto? (si/no): "; cin >> resp;
                }

                ventasRealizadas.push_back(nuevaVenta);
                guardarInventario(inventario);
                system("cls");
                titulo();
                cout << "\nVENTA REGISTRADA CON EXITO!\n\n";
                nuevaVenta->mostrarVenta(true); // Boleta
                cout << "\n";
                system("pause");
                break;
            }

            case 4: { // VER VENTAS Y ARCHIVOS
                system("cls");
                titulo();
                cout << "\n--- HISTORIAL DE VENTAS ---\n\n";
                if (ventasRealizadas.empty()) {
                    cout << "No hay ventas registradas.\n";
                } else {
                    for (size_t i = 0; i < ventasRealizadas.size(); i++) {
                        ventasRealizadas[i]->mostrarVenta();
                        cout << endl;
                    }
                }

                setColor(Color_Def);
                cout << "\n--- LEYENDO DESDE 'inventario.txt' (ARCHIVOS) ---\n";
                ifstream archivoIn("inventario.txt");
                string linea;
                while (getline(archivoIn, linea)) {
                    cout << linea << endl;
                }
                archivoIn.close();
                system("pause");
                break;
            }

            case 5:
                cout << "\nSaliendo del sistema de la Tienda... Hasta luego!\n";
                break;

            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                system("pause");
                break;
        }

    } while (opcion != 5);

    // Liberar memoria
    for (size_t i = 0; i < inventario.size(); i++) delete inventario[i];
    for (size_t i = 0; i < clientes.size(); i++) delete clientes[i];
    for (size_t i = 0; i < vendedores.size(); i++) delete vendedores[i];
    for (size_t i = 0; i < ventasRealizadas.size(); i++) delete ventasRealizadas[i];

    return 0;
}
