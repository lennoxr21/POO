#include <iostream>
#include <cstdlib>
using namespace std;

class Fraccion
{
public:
    // atributos
    int numerador;
    int denominador;

    // constructor crea la fraccion 0/1
    Fraccion()
    {
        numerador = 0;
        denominador = 1;
    }

    // metodos
    void imprimir()
    {
        cout << numerador << "/" << denominador << endl;
    }

    // Multiplicar: (a/b) * (c/d) = (a*c)/(b*d)
    Fraccion multiplicar(Fraccion a)
    {
        Fraccion resultado = Fraccion();
        resultado.numerador = numerador * a.numerador;
        resultado.denominador = denominador * a.denominador;
        return resultado;
    }

    // Sumar: (a/b) + (c/d) = (a*d + c*b)/(b*d)
    Fraccion sumar(Fraccion a)
    {
        Fraccion resultado = Fraccion();
        resultado.numerador = (numerador * a.denominador) + (a.numerador * denominador);
        resultado.denominador = denominador * a.denominador;
        return resultado;
    }

    // Restar: (a/b) - (c/d) = (a*d - c*b)/(b*d)
    Fraccion restar(Fraccion a)
    {
        Fraccion resultado = Fraccion();
        resultado.numerador = (numerador * a.denominador) - (a.numerador * denominador);
        resultado.denominador = denominador * a.denominador;
        return resultado;
    }

    // Dividir: (a/b) / (c/d) = (a*d)/(b*c)
    Fraccion dividir(Fraccion a)
    {
        Fraccion resultado = Fraccion();
        resultado.numerador = numerador * a.denominador;
        resultado.denominador = denominador * a.numerador;
        return resultado;
    }

    // Simplificar: busca el mayor numero que divide a ambos
    void simplificar()
    {
        // si el denominador es negativo, pasamos el signo al numerador
        if (denominador < 0)
        {
            numerador = -numerador;
            denominador = -denominador;
        }

        int menor;
        if (abs(numerador) <= denominador)
        {
            menor = abs(numerador);
        }
        else
        {
            menor = denominador;
        }

        for (int i = menor; i >= 2; i--)
        {
            if (numerador % i == 0 && denominador % i == 0)
            {
                numerador = numerador / i;
                denominador = denominador / i;
                break;   // el primer divisor comun encontrado es el mayor
            }
        }
    }
};

int main()
{
    Fraccion fraccion_a = Fraccion();
    Fraccion fraccion_b = Fraccion();

    Fraccion resultado_multiplicacion = Fraccion();
    Fraccion resultado_suma = Fraccion();
    Fraccion resultado_resta = Fraccion();
    Fraccion resultado_division = Fraccion();

    // Ingreso de datos
    cout << "Ingrese el numerador de la primera fraccion: ";
    cin >> fraccion_a.numerador;
    cout << "Ingrese el denominador de la primera fraccion: ";
    cin >> fraccion_a.denominador;

    cout << "Ingrese el numerador de la segunda fraccion: ";
    cin >> fraccion_b.numerador;
    cout << "Ingrese el denominador de la segunda fraccion: ";
    cin >> fraccion_b.denominador;

    // El denominador nunca puede ser 0
    if (fraccion_a.denominador == 0 || fraccion_b.denominador == 0)
    {
        cout << "Error: el denominador no puede ser 0." << endl;
        return 1;
    }

    // En esta parte realizamos las operaciones
    resultado_multiplicacion = fraccion_a.multiplicar(fraccion_b);
    resultado_suma = fraccion_a.sumar(fraccion_b);
    resultado_resta = fraccion_a.restar(fraccion_b);

    // La division solo se puede hacer si b no es 0 (b.numerador sera denominador)
    bool division_valida = (fraccion_b.numerador != 0);
    if (division_valida)
    {
        resultado_division = fraccion_a.dividir(fraccion_b);
    }

    // Simplificamos los resultados
    resultado_multiplicacion.simplificar();
    resultado_suma.simplificar();
    resultado_resta.simplificar();
    if (division_valida)
    {
        resultado_division.simplificar();
    }

    // En esta parte se muestran las fracciones originales
    cout << endl << "Fraccion A: ";
    fraccion_a.imprimir();
    cout << "Fraccion B: ";
    fraccion_b.imprimir();

    // En esta parte se imprimen los resultados
    cout << endl << "Multiplicacion: ";
    resultado_multiplicacion.imprimir();

    cout << "Suma: ";
    resultado_suma.imprimir();

    cout << "Resta: ";
    resultado_resta.imprimir();

    cout << "Division: ";
    if (division_valida)
    {
        resultado_division.imprimir();
    }
    else
    {
        cout << "no se puede dividir entre una fraccion con numerador 0" << endl;
    }

    return 0;
}
