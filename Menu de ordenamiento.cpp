#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// Cantidad maxima de elementos que puede tener el vector
const int MAX = 1000;
// Vector donde se guardan los numeros originales
int numeros[MAX];

// Vector temporal
// Aqui se copia el vector original antes de aplicar un metodo
// de ordenamiento
int temporal[MAX];

// Vector auxiliar utilizado por Merge Sort
int auxiliar[MAX];
int conteo[MAX];
// Vector que guarda los tiempos de cada metodo
double tiempos[6];

// Cantidad de elementos que tiene el vector
int n = 0;

// Funciones generales
void generarNumeros();
void mostrarNumeros();
void copiarVector();
void mostrarVectorOrdenado();

// Metodos de ordenamiento
void bubbleSort();
void insertionSort();
void selectionSort();
void mergeSort(int inicio, int fin);
void merge(int inicio, int medio, int fin);
void quickSort(int inicio, int fin);
int particion(int inicio, int fin);
void countingSort();

// Funciones del sistema
void ordenarConMetodo();
void compararTodos();
void mostrarResultados();

int main() {

    int opcion;
    // Esto permite que los numeros cambien cada vez que se ejecuta el programa.
    srand(time(0));
    
    // El menu se repite hasta que el usuario elija 6.
    do {
        cout << "\n========================================" << endl;
        cout << "           MENU PRINCIPAL" << endl;
        cout << "========================================" << endl;
        cout << "1. Generar numeros aleatorios" << endl;
        cout << "2. Mostrar numeros generados" << endl;
        cout << "3. Ordenar con un metodo" << endl;
        cout << "4. Comparar todos los metodos" << endl;
        cout << "5. Mostrar resultados" << endl;
        cout << "6. Salir" << endl;
        cout << "========================================" << endl;

        cout << "Elija una opcion: ";
        cin >> opcion;

        // OPCION 1: GENERAR NUMEROS
        if (opcion == 1) {
            generarNumeros();

        // OPCION 2: MOSTRAR NUMEROS
        } else if (opcion == 2) {
            mostrarNumeros();

        // OPCION 3: ORDENAR CON UN METODO
        } else if (opcion == 3) {
            ordenarConMetodo();

        // OPCION 4: COMPARAR TODOS LOS METODOS
        } else if (opcion == 4) {
            if (n == 0) {
                cout << "\nPrimero debe generar los numeros." << endl;
            } else {
                compararTodos();
            }

        // OPCION 5: MOSTRAR RESULTADOS
        } else if (opcion == 5) {
            mostrarResultados();

        // OPCION 6: SALIR
        } else if (opcion == 6) {

            cout << "\nSaliendo del programa..." << endl;

        // OPCION INCORRECTA

        } else {

            cout << "\nOpcion no valida." << endl;
        }

    } while (opcion != 6);
    return 0;
}

// GENERAR NUMEROS ALEATORIOS
void generarNumeros() {

    int maximo;
    // En está parte se pide al usuario cuantos numeros desea generar.
    cout << "\nCuantos numeros desea generar: ";
    cin >> n;

    // Verificamos que la cantidad sea correcta.
    if (n <= 0 || n > MAX) {
        cout << "Cantidad no valida." << endl;

        // Si la cantidad es incorrect dejamos n en cero.
        n = 0;

        return;
    }

    // En está parte se pide el valor maximo que pueden tener los numeros.
    cout << "Valor maximo de los numeros: ";
    cin >> maximo;

    // Verificamos que el valor maximo sea positivo.
    if (maximo < 0) {
        cout << "El valor maximo no puede ser negativo." << endl;
        n = 0;
        return;
    }

    // En está parte se genera los numeros aleatorios.
    for (int i = 0; i < n; i++) {
        // Genera numeros desde 0 hasta maximo.
        numeros[i] = rand() % (maximo + 1);
    }
    cout << "\nNumeros generados correctamente." << endl;
}

// MOSTRAR NUMEROS ORIGINALES

void mostrarNumeros() {

    // Verificamos si ya se generaron numeros.
    if (n == 0) {
        cout << "\nPrimero debe generar los numeros." << endl;
        return;
    }
    cout << "\nNumeros generados:" << endl;
    cout << "[ ";

    // Recorremos el vector y mostramos sus elementos.
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }

    cout << "]" << endl;
}

// COPIAR VECTOR
void copiarVector() {

    // En esta parte se copia todos los elementos del vector original al vector temporal.
    for (int i = 0; i < n; i++) {

        temporal[i] = numeros[i];
    }
}

// MOSTRAR VECTOR ORDENADO
void mostrarVectorOrdenado() {
    cout << "[ ";

    // Mostramos los elementos del vector temporal.
    for (int i = 0; i < n; i++) {

        cout << temporal[i] << " ";
    }
    cout << "]" << endl;
}

// MENU DE METODOS DE ORDENAMIENTO

void ordenarConMetodo() {

    int metodo;

    // Verificamos si existen numeros.
    if (n == 0) {
        cout << "\nPrimero debe generar los numeros." << endl;

        return;
    }

    // En esta parte se reite el submenu hasta elegir regresar.
    do {

        cout << "\n========================================" << endl;
        cout << "       METODOS DE ORDENAMIENTO" << endl;
        cout << "========================================" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Counting Sort" << endl;
        cout << "7. Todos los metodos" << endl;
        cout << "8. Regresar" << endl;
        cout << "========================================" << endl;

        cout << "Elija un metodo: ";
        cin >> metodo;

        // BUBBLE SORT

        if (metodo == 1) {

            copiarVector();

            bubbleSort();

            cout << "\nResultado con Bubble Sort:" << endl;

            mostrarVectorOrdenado();

        // INSERTION SORT

        } else if (metodo == 2) {

            copiarVector();

            insertionSort();

            cout << "\nResultado con Insertion Sort:" << endl;

            mostrarVectorOrdenado();

        // SELECTION SORT

        } else if (metodo == 3) {

            copiarVector();

            selectionSort();

            cout << "\nResultado con Selection Sort:" << endl;

            mostrarVectorOrdenado();

        // MERGE SORT

        } else if (metodo == 4) {

            copiarVector();

            mergeSort(0, n - 1);

            cout << "\nResultado con Merge Sort:" << endl;

            mostrarVectorOrdenado();


        // QUICK SORT

        } else if (metodo == 5) {

            copiarVector();

            quickSort(0, n - 1);

            cout << "\nResultado con Quick Sort:" << endl;

            mostrarVectorOrdenado();

        // COUNTING SORT

        } else if (metodo == 6) {

            copiarVector();

            countingSort();

            cout << "\nResultado con Counting Sort:" << endl;

            mostrarVectorOrdenado();

        // TODOS LOS METODOS
        } else if (metodo == 7) {

            compararTodos();

        // REGRESAR
        } else if (metodo == 8) {
            cout << "\nRegresando al menu principal..." << endl;
        } else {
            cout << "\nOpcion no valida." << endl;
        }

    } while (metodo != 8);
}

// METODO BUBBLE SORT
void bubbleSort() {
    int temp;

    // Recorremos el vector varias veces.
    for (int i = 0; i < n - 1; i++) {

        // Comparamos elementos vecinos.
        for (int j = 0; j < n - 1 - i; j++) {

            // Si el elemento de la izquierda es mayor se intercambia los elementos.
            if (temporal[j] > temporal[j + 1]) {

                temp = temporal[j];

                temporal[j] = temporal[j + 1];

                temporal[j + 1] = temp;
            }
        }
    }
}

// METODO INSERTION SORT

void insertionSort() {

    int actual;
    int j;

    // Comenzamos desde el segundo elemento.
    for (int i = 1; i < n; i++) {

        // Guardamos el elemento que queremos colocar.
        actual = temporal[i];

        // Comenzamos a comparar con el elemento anterior.
        j = i - 1;

        // Mientras el elemento anterior sea mayor lo desplazamos una posicion hacia la derecha.
        while (j >= 0 && temporal[j] > actual) {

            temporal[j + 1] = temporal[j];

            j--;
        }

        // Colocamos el elemento en su posicion correcta.
        temporal[j + 1] = actual;
    }
}

// METODO SELECTION SORT

void selectionSort() {

    int menor;
    int temp;

    // Recorremos el vector.
    for (int i = 0; i < n - 1; i++) {

        // Suponemos que el elemento actual es el menor.
        menor = i;

        // Buscamos un elemento menor.
        for (int j = i + 1; j < n; j++) {

            if (temporal[j] < temporal[menor]) {

                menor = j;
            }
        }

        // Intercambiamos el elemento actual con el menor encontrado.
        temp = temporal[i];

        temporal[i] = temporal[menor];

        temporal[menor] = temp;
    }
}

// MERGE SORT

void mergeSort(int inicio, int fin) {

    // Si inicio es menor que fin significa que tenemos mas de un elemento.
    if (inicio < fin) {

        // Calculamos la posicion central.
        int medio = (inicio + fin) / 2;

        // Ordenamos la mitad izquierda.
        mergeSort(inicio, medio);

        // Ordenamos la mitad derecha.
        mergeSort(medio + 1, fin);

        // Unimos las dos partes ordenadas.
        merge(inicio, medio, fin);
    }
}

// FUNCION MERGE

void merge(int inicio, int medio, int fin) {

    int i = inicio;
    int j = medio + 1;
    int k = inicio;

    // Comparamos los elementos de las dos partes.
    while (i <= medio && j <= fin) {

        // Si el elemento de la izquierda es menor lo colocamos en el vector auxiliar.
        if (temporal[i] < temporal[j]) {

            auxiliar[k] = temporal[i];

            i++;

        } else {

            // Si el elemento de la derecha es menor lo colocamos en el vector auxiliar.
            auxiliar[k] = temporal[j];
            j++;
        }

        k++;
    }

    // Copiamos los elementos que quedaron en la parte izquierda.
    while (i <= medio) {
        auxiliar[k] = temporal[i];
        i++;
        k++;
    }

    // Copiamos los elementos que quedaron en la parte derecha.
    while (j <= fin) {
        auxiliar[k] = temporal[j];
        j++;
        k++;
    }

    // Copiamos el resultado del vector auxiliar nuevamente al vector temporal.
    for (int x = inicio; x <= fin; x++) {

        temporal[x] = auxiliar[x];
    }
}

// QUICK SORT

void quickSort(int inicio, int fin) {

    // Verificamos que existan al menos dos elementos.
    if (inicio < fin) {

        // Colocamos el pivote en su posicion correcta.
        int posicion = particion(inicio, fin);

        // Ordenamos la parte izquierda del pivote.
        quickSort(inicio, posicion - 1);

        // Ordenamos la parte derecha del pivote.
        quickSort(posicion + 1, fin);
    }
}

// FUNCION PARTICION DE QUICK SORT

int particion(int inicio, int fin) {

    // Elegimos el ultimo elemento como pivote.
    int pivote = temporal[fin];

    // i indica la posicion donde terminan los elementos menores que el pivote.
    int i = inicio - 1;

    // Recorremos los elementos anteriores al pivote.
    for (int j = inicio; j < fin; j++) {

        // Si encontramos un elemento menor que el pivote.
        if (temporal[j] < pivote) {
            i++;

            // Intercambiamos los elementos.
            int temp = temporal[i];
            temporal[i] = temporal[j];
            temporal[j] = temp;
        }
    }

    // Colocamos el pivote en su posicion correcta.
    int temp = temporal[i + 1];
    temporal[i + 1] = temporal[fin];
    temporal[fin] = temp;

    // Retornamos la posicion del pivote.
    return i + 1;
}

// COUNTING SORT

void countingSort() {

    int mayor = temporal[0];

    // Buscamos el numero mayor del vector
    for (int i = 1; i < n; i++) {
        if (temporal[i] > mayor) {
            mayor = temporal[i];
        }
    }

    // Inicializamos el vector de conteo.
    for (int i = 0; i <= mayor; i++) {

        conteo[i] = 0;
    }

    // Contamos cuantas veces aparece cada numero.
    for (int i = 0; i < n; i++) {
        conteo[temporal[i]]++;
    }

    // Posicion indica donde colocaremos el siguiente elemento ordenado.
    int posicion = 0;

    // Recorremos el vector de conteo.
    for (int i = 0; i <= mayor; i++) {

        // Mientras el numero siga apareciendo lo colocamos en el vector.
        while (conteo[i] > 0) {
            temporal[posicion] = i;
            posicion++;
            conteo[i]--;
        }
    }
}

// COMPARAR TODOS LOS METODOS

void compararTodos() {

    // Verificamos que existan numeros.
    if (n == 0) {
        cout << "\nPrimero debe generar los numeros." << endl;
        return;
    }
    //tipo de dato para medir el tiemppo
    clock_t inicio;
    clock_t fin;

    
    // BUBBLE SORT

    copiarVector();
    inicio = clock();
    bubbleSort();
    fin = clock();
    tiempos[0] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;

    // INSERTION SORT
    copiarVector();
    inicio = clock();
    insertionSort();
    fin = clock();
    tiempos[1] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;

    // SELECTION SORT
    copiarVector();
    inicio = clock();
    selectionSort();
    fin = clock();
    tiempos[2] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;

    // MERGE SORT
    copiarVector();
    inicio = clock();
    mergeSort(0, n - 1);
    fin = clock();
    tiempos[3] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;

    // QUICK SORT
    copiarVector();
    inicio = clock();
    quickSort(0, n - 1);
    fin = clock();
    tiempos[4] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;

    // COUNTING SORT
    copiarVector();
    inicio = clock();
    countingSort();
    fin = clock();
    tiempos[5] = double(fin - inicio) * 1000 / CLOCKS_PER_SEC;


    // Mostramos los resultados inmediatamente.
    cout << "\n========================================" << endl;
    cout << "       COMPARACION DE METODOS" << endl;
    cout << "========================================" << endl;

    cout << "Bubble Sort:    " << tiempos[0] << " ms" << endl;
    cout << "Insertion Sort: " << tiempos[1] << " ms" << endl;
    cout << "Selection Sort: " << tiempos[2] << " ms" << endl;
    cout << "Merge Sort:     " << tiempos[3] << " ms" << endl;
    cout << "Quick Sort:     " << tiempos[4] << " ms" << endl;
    cout << "Counting Sort:  " << tiempos[5] << " ms" << endl;

    cout << "========================================" << endl;
}


// ============================================================
// MOSTRAR RESULTADOS
// ============================================================

void mostrarResultados() {

    cout << "\n========================================" << endl;
    cout << "             RESULTADOS" << endl;
    cout << "========================================" << endl;

    cout << "Bubble Sort:    " << tiempos[0] << " ms" << endl;
    cout << "Insertion Sort: " << tiempos[1] << " ms" << endl;
    cout << "Selection Sort: " << tiempos[2] << " ms" << endl;
    cout << "Merge Sort:     " << tiempos[3] << " ms" << endl;
    cout << "Quick Sort:     " << tiempos[4] << " ms" << endl;
    cout << "Counting Sort:  " << tiempos[5] << " ms" << endl;

    cout << "========================================" << endl;
}

