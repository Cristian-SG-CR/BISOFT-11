#include <iostream>
#include <cstdlib>
#include "Equipo.h"
#include "EquipoNode.h"
#include "EquipoList.h"

#include "Categoria.h"
#include "CategoriaNode.h"
#include "CategoriaList.h"

int main() {


    EquipoList equipoList;

    equipoList.agregarEquipo(new Equipo(1, "Equipo A", 2000, 5, "Alquilado"));
    equipoList.agregarEquipo(new Equipo(3, "Equipo C", 2010, 6, "Disponible"));
    equipoList.agregarEquipo(new Equipo(2, "Equipo B", 2020, 4, "Alquilado"));

    CategoriaList categorialista;

    categorialista.agregarCategoria(new Categoria("ACategoria"));
    categorialista.agregarCategoria(new Categoria("CCategoria"));
    categorialista.agregarCategoria(new Categoria("BCategoria"));

    int opc=0;

    std::cout << "\n------------ CEN-PH0 ------------" << std::endl;
    std::cout << "\n Seleccione interfaz \n 1.Administrador \n 2.Usuario" << std::endl;
    std::cin>>opc;

    if(opc==1){
        std::string pass="";
        do{
                system("cls");
                std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR ------------" << std::endl;
                std::cout << "\n Ingrese su contrasena: " << std::endl;
                std::cin>>pass;
        }while(pass!="admin");
        int salida=0;
        while(salida==0){
            system("cls");
            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - MENU PRINCIPAL ------------" << std::endl;
            std::cout << "\n 1.Mantenimiento Equipos\n 2.Mantenimiento Categorias \n 3.Consulta Equipos\n 4.Salir\n" << std::endl;
            std::cin>>opc;
            switch(opc){
            case 1:{
                int opcm1=0;
                int pm1=0;
                while(pm1==0){
                    system("cls");
                    std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - MANT. EQUIPOS ------------" << std::endl;
                    std::cout << "\n 1.Agregar Equipo\n 2.Retirar Equipo\n 3.Consultar Equipo\n 4.Modificar Equipo\n 5.Listar catalogo en forma ascendente por codigo\n 6.Listar catalogo en forma descendente por nombre\n 7.Listar equipos cuya descripcion contenga una hilera especifica\n 8.Listar equipos de un rango de ano especifico\n 9.Listar equipos que cumplan niveles de acidez\n 10.Volver al menu anterior" << std::endl;
                    std::cin>>opcm1;
                        switch(opcm1){
                        case 1:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - AGR. EQUIPO ------------" << std::endl;
                            int codigoeq=0;
                            std::string nomeq="";
                            int anio=0;
                            int nivelacidez=0;

                            std::cout<<"\nIngrese codigo de equipo: "<<std::endl;
                            std::cin>>codigoeq;
                            std::cout<<"\nIngrese nombre de equipo: "<<std::endl;
                            std::cin>>nomeq;
                            std::cout<<"\nIngrese ano del equipo: "<<std::endl;
                            std::cin>>anio;
                            std::cout<<"\nIngrese nivel de acidez del equipo: "<<std::endl;
                            std::cin>>nivelacidez;

                            equipoList.agregarEquipo(new Equipo(codigoeq, nomeq, anio, nivelacidez, "Disponible"));
                            system("pause");
                            break;}

                        case 2:{
                            system("cls");
                            int codigoeq=0;
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - RET. EQUIPO ------------" << std::endl;
                            equipoList.listarCatalogoAscendentePorCodigo();
                            std::cout<<"\nIngrese codigo de equipo que desea retirar: "<<std::endl;
                            std::cin>>codigoeq;
                            equipoList.retirarEquipo(codigoeq);
                            system("pause");
                            break;}

                        case 3:{
                            system("cls");
                            int codigoeq=0;
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - CONS. EQUIPO ------------" << std::endl;
                            equipoList.listarCatalogoAscendentePorCodigo();
                            std::cout<<"\nIngrese codigo de equipo que desea consultar: "<<std::endl;
                            std::cin>>codigoeq;
                            equipoList.consultarEquipo(codigoeq)->toString();
                            system("pause");
                            break;}

                        case 4:{
                            system("cls");
                            int codigoeq=0;
                            int nuevoEs=0;
                            std::string nuevoNom="";

                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - MOD. EQUIPO ------------" << std::endl;
                            equipoList.listarCatalogoAscendentePorCodigo();
                            std::cout<<"\nIngrese codigo de equipo que desea modificar: "<<std::endl;
                            std::cin>>codigoeq;
                            std::cout<<"\nIngrese nuevo nombre del equipo seleccionado: "<<std::endl;
                            std::cin>>nuevoNom;
                            std::cout<<"\nIngrese nuevo estado del equipo seleccionado (1.Disponible, 2.Alquilado): "<<std::endl;
                            std::cin>>nuevoEs;
                            if(nuevoEs==1){equipoList.modificarEquipo(codigoeq, nuevoNom, "Disponible");}else{equipoList.modificarEquipo(codigoeq, nuevoNom, "Alquilado");}
                            std::cout<<"\nEquipo Modificado Exitosamente!"<<std::endl;
                            system("pause");
                            break;}

                        case 5:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - LIST. COD ------------\nAscendente" << std::endl;
                            equipoList.listarCatalogoAscendentePorCodigo();
                            std::cout << "\n----\nDescendente"<<std::endl;
                            equipoList.listarCatalogoDescendentePorCodigo();
                            system("pause");
                            break;}

                        case 6:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - LIST. NOM ------------\nAscendente" << std::endl;
                            equipoList.listarCatalogoAscendentePorNombre();
                            std::cout << "\n----\nDescendente"<<std::endl;
                            equipoList.listarCatalogoDescendentePorNombre();
                            system("pause");
                            break;}

                        case 7:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - DESC. ------------" << std::endl;
                            std::string desc="";
                            std::cout<<"\nIngrese nombre del equipo que desea obtener informacion: "<<std::endl;
                            std::cin>> desc;
                            equipoList.listarEquiposConDescripcion(desc);
                            system("pause");
                            break;}

                        case 8:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - RANGO ANO ------------" << std::endl;
                            int rango1=0;
                            int rango2=0;
                            std::cout<<"\nIngrese rango inferior ano de equipo: "<<std::endl;
                            std::cin>> rango1;
                            std::cout<<"\nIngrese rango superior ano de equipo: "<<std::endl;
                            std::cin>> rango2;
                            equipoList.listarEquiposRangoAnio(rango1,rango2);
                            system("pause");
                            break;}

                        case 9:{
                            system("cls");
                            std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - NIVELES PH ------------" << std::endl;
                            int niv1=0;
                            int niv2=0;
                            std::cout<<"\nIngrese nivel inf. acidez que desea consultar: "<<std::endl;
                            std::cin>> niv1;
                            std::cout<<"\nIngrese nivel sup. acidez que desea consultar: "<<std::endl;
                            std::cin>> niv2;
                            equipoList.listarEquiposPorNivelesAcidez(niv1,niv2);
                            system("pause");
                            break;}

                        case 10:{
                            pm1=1;
                            break;}

                        }
                    }
                break;}

            case 2:{
                int opcm2=0;
                int opc2=0;
                while(opcm2==0){
                    system("cls");
                    std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - MANT. CATEGORIAS ------------" << std::endl;
                    std::cout << "\n 1.Crear categoria\n 2.Eliminar Categoria\n 3.Modificar Categoria\n 4.Consultar Categoria\n 5.Catalogo de categorias\n 6.Agregar equipo a una categoria\n 7.Retirar equipo de una categoria\n 8.Volver al menu anterior" << std::endl;
                    std::cin>>opc2;
                    switch(opc2){
                    case 1:{
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - CREAR CATEGORIA ------------\n" << std::endl;
                        std::string nomCategoria="";
                        std::cout<<"\nIngrese nombre de la nueva Categoria: "<<std::endl;
                        std::cin>> nomCategoria;
                        categorialista.agregarCategoria(new Categoria(nomCategoria));
                        break;}

                    case 2:{
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - ELIM. CATEGORIA ------------\n" << std::endl;
                        categorialista.listarCatalogoCategorias();
                        std::string nomCategoria="";
                        std::cout<<"\nIngrese nombre de la Categoria que desea eliminar: "<<std::endl;
                        std::cin>> nomCategoria;
                        categorialista.eliminarCategoria(nomCategoria);
                        system("pause");
                        break;}

                    case 3:{
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - MODIF. CATEGORIA ------------\n" << std::endl;
                        categorialista.listarCatalogoCategorias();
                        std::string nomCategoria="";
                        std::string nuevoNom="";
                        std::cout<<"\nIngrese nombre de la Categoria que desea modificar: "<<std::endl;
                        std::cin>> nomCategoria;
                        std::cout<<"\nIngrese el nuevo nombre de la Categoria: "<<std::endl;
                        std::cin>> nuevoNom;
                        categorialista.modificarCategoria(nomCategoria, nuevoNom);
                        system("pause");
                        break;}

                    case 4:{
                        system("cls");
                        std::string nomCategoria="";
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - CONS. CATEGORIA ------------\n" << std::endl;
                        categorialista.listarCatalogoCategorias();
                        std::cout<<"\nIngrese nombre de la Categoria que desea consultar: "<<std::endl;
                        std::cin>>nomCategoria;
                        categorialista.consultarCategoria(nomCategoria)->toString();
                        system("pause");
                        break;}

                    case 5:{
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - CAT. CATEGORIA ------------\n" << std::endl;
                        categorialista.listarCatalogoCategorias();
                        system("pause");
                        break;}

                    case 6:{
                        system("cls");
                        std::string nomCategoria="";
                        int codEquipo=0;
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - AGR. EQUIPO CATEGORIA ------------\n" << std::endl;
                        equipoList.listarCatalogoAscendentePorCodigo();
                        std::cout<<"\nIngrese codigo de Equipo que desea asociar: "<<std::endl;
                        std::cin>>codEquipo;
                        Equipo* obtEquipo = equipoList.consultarEquipo(codEquipo);
                        categorialista.listarCatalogoCategorias();
                        std::cout<<"\nIngrese nombre de Categoria que desea asociar: "<<std::endl;
                        std::cin>>nomCategoria;
                        categorialista.agregarEquipoCategoria(obtEquipo,nomCategoria);
                        system("pause");
                        break;}

                    case 7:{
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - RET. EQUIPO CATEGORIA ------------\n" << std::endl;
                        categorialista.retirarEquipoCategoria();
                        system("pause");
                        break;}

                    case 8:{
                        opcm2=1;
                        break;}
                    }
                }
                    break;}

                case 3:{
                    int opc3=0;
                    int opcm3=0;
                    while(opcm3==0){
                        system("cls");
                        std::cout << "\n------------ CEN-PH0 INTERFAZ ADMINISTRADOR - CONS. EQUIPOS ------------" << std::endl;
                        std::cout << "\n 1.Consultar todos los datos de todos los equipos\n 2.Consultar datos de equipos por categorias\n 3.Volver al menu anterior." << std::endl;
                        std::cin>>opc3;
                        switch(opc3){
                            case 1:
                                equipoList.listarCatalogoAscendentePorCodigo();
                                system("pause");
                                break;
                            case 2:
                                categorialista.listarTodo();
                                system("pause");
                                break;
                            case 3:
                                opcm3=1;
                                break;
                        }
                    }
                    break;}

                case 4:{
                    salida=1;
                    break;}
            }
        }
    }else{
        std::cout << "\n------------ CEN-PH0 INTERFAZ USUARIO ------------" << std::endl;
        std::cout << "\n Caracteristica no disponible..." << std::endl;
    }
    return 0;
}
