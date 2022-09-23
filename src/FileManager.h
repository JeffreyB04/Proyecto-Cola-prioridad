//
// Created by jeffr on 6/9/2022.
//

#ifndef PROYECTODATOS_FILEMANAGER_H
#define PROYECTODATOS_FILEMANAGER_H
#include<fstream>
#include<iostream>
#include "ClienteManager.h"
#include "ColaPrioridad.h"

class FileManager {
public:
    static void saveClientes(ClienteManager& listaCliente, const string& fileName);
    static ostream& writeClientes(ostream& out, const ClienteManager& cliente);
    static ClienteManager loadClientes(const string& filename,ColaPrioridad<Cliente>& queue);

};


#endif //PROYECTODATOS_FILEMANAGER_H
