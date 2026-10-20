#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//                 FIGURAS 2D

// CUADRADO
class Cuadrado
{
    public:
    // atributos
        int lado;
    // metodos
    // Calcular area
    int area()
    {
        int resultado = 0;

        resultado = lado * lado;

        return resultado;
    }
    // Calcular perimetro
    int perimetro()
    {
        int resultado = 0;

        resultado = 4 * lado;

        return resultado;
    }
    // Dibujar cuadrado
    void dibujar()
    {
        cout<<endl;
        cout<<"CUADRADO"<<endl;
        for(int i = 0; i < lado; i++)
        {
            for(int j = 0; j < lado; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

// RECTANGULO
class Rectangulo
{
    public:
    // atributos
        int base;
        int altura;
    // metodos
    int area()
    {
        int resultado = 0;

        resultado = base * altura;

        return resultado;
    }
    int perimetro()
    {
        int resultado = 0;
        resultado = 2 * (base + altura);
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"RECTANGULO"<<endl;

        for(int i = 0; i < altura; i++)
        {
            for(int j = 0; j < base; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

// CLASE TRIANGULO
class Triangulo
{
    public:
    // atributos
        int base;
        int altura;
        int lado;
    // metodos
    int area()
    {
        int resultado = 0;
        resultado = (base * altura) / 2;
        return resultado;
    }
    int perimetro()
    {
        int resultado = 0;
        resultado = base + lado + lado;
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"TRIANGULO"<<endl;
        for(int i = 1; i <= altura; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

// CLASE CIRCULO
class Circulo
{
    public:
    // atributos
        double radio;
    // metodos
    double area()
    {
        double resultado = 0;
        resultado = 3.1416 * radio * radio;
        return resultado;
    }
    double perimetro()
    {
        double resultado = 0;
        resultado = 2 * 3.1416 * radio;
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"CIRCULO"<<endl;
        for(int i = -radio; i <= radio; i++)
        {
            for(int j = -radio; j <= radio; j++)
            {
                if(i*i + j*j <= radio*radio)
                {
                    cout<<"* ";
                }
                else
                {
                    cout<<"  ";
                }
            }

            cout<<endl;
        }
    }
};


// CLASE ROMBO
class Rombo
{
    public:
    // atributos
        int diagonal_mayor;
        int diagonal_menor;
        int lado;
    // metodos
    double area()
    {
        double resultado = 0;
        resultado = (diagonal_mayor * diagonal_menor) / 2.0;
        return resultado;
    }
    int perimetro()
    {
        int resultado = 0;
        resultado = 4 * lado;
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"ROMBO"<<endl;
        for(int i = 1; i <= diagonal_menor; i++)
        {
            for(int j = diagonal_menor; j > i; j--)
            {
                cout<<" ";
            }

            for(int j = 1; j <= 2*i-1; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        for(int i = diagonal_menor-1; i >= 1; i--)
        {
            for(int j = diagonal_menor; j > i; j--)
            {
                cout<<" ";
            }
            for(int j = 1; j <= 2*i-1; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }
};


// PARALELOGRAMO

class Paralelogramo
{
    public:

    // atributos
        int base;
        int altura;
        int lado;
    // metodos
    int area()
    {
        int resultado = 0;
        resultado = base * altura;
        return resultado;
    }
    int perimetro()
    {
        int resultado = 0;
        resultado = 2 * (base + lado);
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"PARALELOGRAMO"<<endl;
        for(int i = 0; i < altura; i++)
        {
            for(int j = 0; j < altura-i; j++)
            {
                cout<<" ";
            }
            for(int j = 0; j < base; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};


// TRAPECIO
class Trapecio
{
    public:
    // atributos
        int base_mayor;
        int base_menor;
        int altura;
        int lado1;
        int lado2;
    // metodos
    double area()
    {
        double resultado = 0;
        resultado = ((base_mayor + base_menor) * altura) / 2.0;
        return resultado;
    }
    int perimetro()
    {
        int resultado = 0;
        resultado = base_mayor + base_menor + lado1 + lado2;
        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"TRAPECIO"<<endl;
        for(int i = 0; i < altura; i++)
        {
            for(int j = 0; j < altura-i; j++)
            {
                cout<<" ";
            }
            for(int j = 0; j < base_menor+i; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};


// CLASE PENTAGONO
class Pentagono
{
    public:
    // atributos
        double lado;
        double apotema;

    // metodos
    double area()
    {
        double resultado = 0;
        resultado = (5 * lado * apotema) / 2;
        return resultado;
    }
    double perimetro()
    {
        double resultado = 0;
        resultado = 5 * lado;
        return resultado;
    }
    void dibujar()
    {
        cout<<endl;
        cout<<"PENTAGONO"<<endl;

        cout<<"    *    "<<endl;
        cout<<"   * *   "<<endl;
        cout<<"  *   *  "<<endl;
        cout<<" *     * "<<endl;
        cout<<"*********"<<endl;
    }
};

// CLASE HEXAGONO
class Hexagono
{
    public:

    // atributos
        double lado;
        double apotema;
    // metodos

    double area()
    {
        double resultado = 0;
        resultado = (6 * lado * apotema) / 2;
        return resultado;
    }

    double perimetro()
    {
        double resultado = 0;
        resultado = 6 * lado;
        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"HEXAGONO"<<endl;

        cout<<"  ****  "<<endl;
        cout<<" *    * "<<endl;
        cout<<"*      *"<<endl;
        cout<<"*      *"<<endl;
        cout<<" *    * "<<endl;
        cout<<"  ****  "<<endl;
    }
};

// CLASE ELIPSE
class Elipse
{
    public:
    // atributos
        double radio_mayor;
        double radio_menor;
    // metodos
    double area()
    {
        double resultado = 0;
        resultado = 3.1416 * radio_mayor * radio_menor;
        return resultado;
    }

    double perimetro()
    {
        double resultado = 0;
        resultado = 2 * 3.1416 *
                    sqrt((radio_mayor*radio_mayor +
                    radio_menor*radio_menor) / 2);
        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"ELIPSE"<<endl;

        cout<<"   ******   "<<endl;
        cout<<" **      ** "<<endl;
        cout<<"*          *"<<endl;
        cout<<" **      ** "<<endl;
        cout<<"   ******   "<<endl;
    }
};



//                 FIGURAS 3D
// CLASE CUBO
class Cubo
{
    public:

    // atributos
        double lado;
    // metodos

    double area()
    {
        double resultado = 0;
        resultado = 6 * lado * lado;
        return resultado;
    }

    double volumen()
    {
        double resultado = 0;
        resultado = lado * lado * lado;
        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"CUBO"<<endl;

        cout<<"   ******"<<endl;
        cout<<"  *    **"<<endl;
        cout<<" *    * *"<<endl;
        cout<<"******  *"<<endl;
        cout<<"*    *  *"<<endl;
        cout<<"*    * **"<<endl;
        cout<<"******"<<endl;
    }
};


// CLASE ORTOEDRO

class Ortoedro
{
    public:

    // atributos
        double largo;
        double ancho;
        double alto;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 2 * (largo*ancho +
                         largo*alto +
                         ancho*alto);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = largo * ancho * alto;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"ORTOEDRO"<<endl;

        cout<<"**********"<<endl;
        cout<<"*        **"<<endl;
        cout<<"*        * *"<<endl;
        cout<<"**********  *"<<endl;
        cout<<" *        * *"<<endl;
        cout<<"  **********"<<endl;
    }
};


// CLASE CILINDRO
class Cilindro
{
    public:

    // atributos
        double radio;
        double altura;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 2 * 3.1416 * radio *
                    (radio + altura);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = 3.1416 * radio * radio * altura;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"CILINDRO"<<endl;

        cout<<"   *****   "<<endl;
        cout<<" *       * "<<endl;
        cout<<"*         *"<<endl;
        cout<<"*         *"<<endl;
        cout<<"*         *"<<endl;
        cout<<" *       * "<<endl;
        cout<<"   *****   "<<endl;
    }
};


// CLASE ESFERA
class Esfera
{
    public:

    // atributos
        double radio;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 4 * 3.1416 * radio * radio;

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = (4 * 3.1416 * radio * radio * radio) / 3;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"ESFERA"<<endl;

        cout<<"   *****   "<<endl;
        cout<<" **     ** "<<endl;
        cout<<"*         *"<<endl;
        cout<<"*         *"<<endl;
        cout<<" **     ** "<<endl;
        cout<<"   *****   "<<endl;
    }
};


// CLASE CONO
class Cono
{
    public:

    // atributos
        double radio;
        double altura;
        double generatriz;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 3.1416 * radio *
                    (radio + generatriz);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = (3.1416 * radio * radio * altura) / 3;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"CONO"<<endl;

        cout<<"     *     "<<endl;
        cout<<"    * *    "<<endl;
        cout<<"   *   *   "<<endl;
        cout<<"  *     *  "<<endl;
        cout<<" ********* "<<endl;
    }
};


// CLASE PIRAMIDE
class Piramide
{
    public:

    // atributos
        double lado;
        double altura;
        double apotema;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = (lado*lado) +
                    (2*lado*apotema);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = (lado*lado*altura) / 3;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"PIRAMIDE"<<endl;

        cout<<"     *     "<<endl;
        cout<<"    * *    "<<endl;
        cout<<"   *   *   "<<endl;
        cout<<"  *     *  "<<endl;
        cout<<" ********* "<<endl;
    }
};


// CLASE PRISMA TRIANGULAR

class PrismaTriangular
{
    public:

    // atributos
        double base;
        double altura;
        double lado;
        double longitud;

    // metodos

    double area()
    {
        double resultado = 0;

        double area_base = (base * altura) / 2;

        resultado = 2 * area_base +
                    (3 * lado * longitud);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = ((base * altura) / 2) * longitud;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"PRISMA TRIANGULAR"<<endl;

        cout<<"   *     "<<endl;
        cout<<"  * *    "<<endl;
        cout<<" *****   "<<endl;
        cout<<"   ****  "<<endl;
        cout<<"  *  * * "<<endl;
        cout<<" *****   "<<endl;
    }
};


// CLASE PRISMA RECTANGULAR

class PrismaRectangular
{
    public:

    // atributos
        double largo;
        double ancho;
        double altura;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 2 * (largo*ancho +
                         largo*altura +
                         ancho*altura);

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = largo * ancho * altura;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"PRISMA RECTANGULAR"<<endl;

        cout<<"********"<<endl;
        cout<<"*      **"<<endl;
        cout<<"*      * *"<<endl;
        cout<<"********  *"<<endl;
        cout<<" *      * *"<<endl;
        cout<<"  ********"<<endl;
    }
};


// CLASE TETRAEDRO
class Tetraedro
{
    public:

    // atributos
        double lado;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = sqrt(3) * lado * lado;

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = (lado*lado*lado) /
                    (6 * sqrt(2));

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"TETRAEDRO"<<endl;

        cout<<"    *    "<<endl;
        cout<<"   * *   "<<endl;
        cout<<"  *   *  "<<endl;
        cout<<" * * * * "<<endl;
    }
};

--
// CLASE OCTAEDRO

class Octaedro
{
    public:

    // atributos
        double lado;

    // metodos

    double area()
    {
        double resultado = 0;

        resultado = 2 * sqrt(3) * lado * lado;

        return resultado;
    }

    double volumen()
    {
        double resultado = 0;

        resultado = (sqrt(2) * lado * lado * lado) / 3;

        return resultado;
    }

    void dibujar()
    {
        cout<<endl;
        cout<<"OCTAEDRO"<<endl;

        cout<<"    *    "<<endl;
        cout<<"   * *   "<<endl;
        cout<<"  *   *  "<<endl;
        cout<<" *     * "<<endl;
        cout<<"  *   *  "<<endl;
        cout<<"   * *   "<<endl;
        cout<<"    *    "<<endl;
    }
};


//                    MENU 2D

void menu2D()
{
    int opcion;

    do
    {
        cout<<endl;
        cout<<"======================================"<<endl;
        cout<<"             FIGURAS 2D"<<endl;
        cout<<"======================================"<<endl;
        cout<<"1. Cuadrado"<<endl;
        cout<<"2. Rectangulo"<<endl;
        cout<<"3. Triangulo"<<endl;
        cout<<"4. Circulo"<<endl;
        cout<<"5. Rombo"<<endl;
        cout<<"6. Paralelogramo"<<endl;
        cout<<"7. Trapecio"<<endl;
        cout<<"8. Pentagono"<<endl;
        cout<<"9. Hexagono"<<endl;
        cout<<"10. Elipse"<<endl;
        cout<<"11. Regresar"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion == 1)
        {
            Cuadrado figura;
            int menu;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 2)
        {
            Rectangulo figura;
            int menu;
            cout<<"Ingrese la base: ";
            cin>>figura.base;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 3)
        {
            Triangulo figura;
            int menu;
            cout<<"Ingrese la base: ";
            cin>>figura.base;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 4)
        {
            Circulo figura;
            int menu;
            cout<<"Ingrese el radio: ";
            cin>>figura.radio;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 5)
        {
            Rombo figura;
            int menu;
            cout<<"Ingrese la diagonal mayor: ";
            cin>>figura.diagonal_mayor;
            cout<<"Ingrese la diagonal menor: ";
            cin>>figura.diagonal_menor;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 6)
        {
            Paralelogramo figura;
            int menu;
            cout<<"Ingrese la base: ";
            cin>>figura.base;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 7)
        {
            Trapecio figura;
            int menu;
            cout<<"Ingrese la base mayor: ";
            cin>>figura.base_mayor;
            cout<<"Ingrese la base menor: ";
            cin>>figura.base_menor;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;
            cout<<"Ingrese el lado 1: ";
            cin>>figura.lado1;
            cout<<"Ingrese el lado 2: ";
            cin>>figura.lado2;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 8)
        {
            Pentagono figura;
            int menu;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;
            cout<<"Ingrese la apotema: ";
            cin>>figura.apotema;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 9)
        {
            Hexagono figura;
            int menu;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;
            cout<<"Ingrese la apotema: ";
            cin>>figura.apotema;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }
        else if(opcion == 10)
        {
            Elipse figura;
            int menu;
            cout<<"Ingrese el radio mayor: ";
            cin>>figura.radio_mayor;
            cout<<"Ingrese el radio menor: ";
            cin>>figura.radio_menor;

            do
            {
                cout<<endl<<"1. Mostrar area"<<endl;
                cout<<"2. Mostrar perimetro"<<endl;
                cout<<"3. Mostrar figura"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"5. Ver todos los resultados"<<endl;                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Perimetro aproximado: "<<figura.perimetro()<<endl;
                else if(menu==3) figura.dibujar();
                else if(menu==5)
                {
                    cout<<"Area: "<<figura.area()<<endl;
                    cout<<"Perimetro: "<<figura.perimetro()<<endl;
                    figura.dibujar();
                }
            }while(menu!=4 && menu!=5);
        }

    }while(opcion!=11);
}



//                    MENU 3D

void menu3D()
{
    int opcion;

    do
    {
        cout<<endl;
        cout<<"======================================"<<endl;
        cout<<"             FIGURAS 3D"<<endl;
        cout<<"======================================"<<endl;
        cout<<"1. Cubo"<<endl;
        cout<<"2. Ortoedro"<<endl;
        cout<<"3. Cilindro"<<endl;
        cout<<"4. Esfera"<<endl;
        cout<<"5. Cono"<<endl;
        cout<<"6. Regresar"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion == 1)
        {
            Cubo figura;
            int menu;
            cout<<"Ingrese el lado: ";
            cin>>figura.lado;

            do
            {
                cout<<endl<<"1. Mostrar area superficial"<<endl;
                cout<<"2. Mostrar volumen"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"4. Ver todos los resultados"<<endl;
                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area superficial: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Volumen: "<<figura.volumen()<<endl;
                else if(menu==4)
                {
                    cout<<"Area superficial: "<<figura.area()<<endl;
                    cout<<"Volumen: "<<figura.volumen()<<endl;
                }
            }while(menu!=3 && menu!=4);
        }
        else if(opcion == 2)
        {
            Ortoedro figura;
            int menu;
            cout<<"Ingrese el largo: ";
            cin>>figura.largo;
            cout<<"Ingrese el ancho: ";
            cin>>figura.ancho;
            cout<<"Ingrese el alto: ";
            cin>>figura.alto;

            do
            {
                cout<<endl<<"1. Mostrar area superficial"<<endl;
                cout<<"2. Mostrar volumen"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"4. Ver todos los resultados"<<endl;
                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area superficial: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Volumen: "<<figura.volumen()<<endl;
                else if(menu==4)
                {
                    cout<<"Area superficial: "<<figura.area()<<endl;
                    cout<<"Volumen: "<<figura.volumen()<<endl;
                }
            }while(menu!=3 && menu!=4);
        }
        else if(opcion == 3)
        {
            Cilindro figura;
            int menu;
            cout<<"Ingrese el radio: ";
            cin>>figura.radio;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;

            do
            {
                cout<<endl<<"1. Mostrar area superficial"<<endl;
                cout<<"2. Mostrar volumen"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"4. Ver todos los resultados"<<endl;
                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area superficial: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Volumen: "<<figura.volumen()<<endl;
                else if(menu==4)
                {
                    cout<<"Area superficial: "<<figura.area()<<endl;
                    cout<<"Volumen: "<<figura.volumen()<<endl;
                }
            }while(menu!=3 && menu!=4);
        }
        else if(opcion == 4)
        {
            Esfera figura;
            int menu;
            cout<<"Ingrese el radio: ";
            cin>>figura.radio;

            do
            {
                cout<<endl<<"1. Mostrar area superficial"<<endl;
                cout<<"2. Mostrar volumen"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"4. Ver todos los resultados"<<endl;
                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area superficial: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Volumen: "<<figura.volumen()<<endl;
                else if(menu==4)
                {
                    cout<<"Area superficial: "<<figura.area()<<endl;
                    cout<<"Volumen: "<<figura.volumen()<<endl;
                }
            }while(menu!=3 && menu!=4);
        }
        else if(opcion == 5)
        {
            Cono figura;
            int menu;
            cout<<"Ingrese el radio: ";
            cin>>figura.radio;
            cout<<"Ingrese la altura: ";
            cin>>figura.altura;
            cout<<"Ingrese la generatriz: ";
            cin>>figura.generatriz;

            do
            {
                cout<<endl<<"1. Mostrar area superficial"<<endl;
                cout<<"2. Mostrar volumen"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"4. Ver todos los resultados"<<endl;
                cout<<"Seleccione: ";
                cin>>menu;

                if(menu==1) cout<<"Area superficial: "<<figura.area()<<endl;
                else if(menu==2) cout<<"Volumen: "<<figura.volumen()<<endl;
                else if(menu==4)
                {
                    cout<<"Area superficial: "<<figura.area()<<endl;
                    cout<<"Volumen: "<<figura.volumen()<<endl;
                }
            }while(menu!=3 && menu!=4);
        }

    }while(opcion!=6);
}

//                  PROGRAMA PRINCIPAL

int main()
{
    int opcion;

    do
    {
        cout<<endl;
        cout<<"****************************************"<<endl;
        cout<<"       MENU PRINCIPAL DE FIGURAS"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"1. Figuras 2D"<<endl;
        cout<<"2. Figuras 3D"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion == 1)
        {
            menu2D();
        }
        else if(opcion == 2)
        {
            menu3D();
        }
        else if(opcion == 3)
        {
            cout<<endl;
            cout<<"Programa finalizado."<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Opcion incorrecta."<<endl;
        }

    } while(opcion != 3);

    return 0;
}
