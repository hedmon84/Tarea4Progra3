// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo

int inputsize = 14;
void escribir(string nombre_archivo, Mascota*mascota, int posicion) {

    ofstream out(nombre_archivo.c_str(), ios::in|ios::out);

    if(!out.is_open()) {
        out.open(nombre_archivo.c_str());
    }

    out.seekp(posicion* inputsize);
    out.write((char*)&mascota->edad, 4);
    out.write(mascota->nombre.c_str(), 10);
    out.close();

}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo

Mascota* leer(string nombre_archivo, int posicion) {

    int age;
    char name[10];
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion * inputsize);
    in.read((char*)&age, 4);
    in.read(name, 10);
    Mascota *m = new Mascota(age, name);
    return m;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron

vector<Mascota*> leerTodos(string nombre_archivo) {

    vector<Mascota*>respuesta;

    Mascota* newPet;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int byteSize = in.tellg();
    double pets = byteSize/inputsize;
    int age;
    char name[10];

    for (int a = 0; a < pets; a++) {
        in.seekg(a * inputsize);
        in.read((char*)&age, 4);
        in.read(name, 10);
        newPet = new Mascota(age, name);
        respuesta.push_back(newPet);
    }

    in.close();

    return respuesta;
}

int main () {

    //Funcion evaluadora
    evaluar();
    return 0;
}
