#include <iostream>
//Libreria para trabajar con archivos.
#include <fstream>
using namespace std;

int main()
{
    string nombre, apellido, carrera;
    int e;
    char r;
    ofstream archivoPrueba;
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    getline (cin, nombreArchivo);
    archivoPrueba.open(nombreArchivo.c_str (), ios::app);
    do
    {
        cout << "\tIngrese el nombre: ";
        getline (cin, nombre, '\n');
        cout << "\tIngrese el apellido: ";
        getline (cin, apellido, '\n');
        cout << "\tIngrese la carrera: ";
        getline (cin, carrera, '\n');
        cout << "\tIngrese la edad: ";
        cin >> e;

        archivoPrueba << nombre << " " << apellido << " " << carrera << " " << e << "\n";
        cout << "Desea agregar otros datos (s/n): ";
        cin >> r;
        cin.ignore ();
    }
    while (r == 's');
    archivoPrueba.close ();

    ifstream archivoLectura ("datos.txt");
    string text;

    while (!archivoLectura.eof ())
    {
        archivoLectura >> nombre >> apellido >> carrera >>e;
            if (!archivoLectura.eof ()){
                getline (archivoLectura, text);
                cout << "*****************************" << "\n";
                cout << "Nombre: " << nombre << "\n";
                cout << "Apellido: " << apellido << "\n";
                cout << "Carrera: " << carrera << "\n";
                cout << "Edad: " << e << "\n";
            }
    }
    archivoLectura.close ();
    return 0;
}