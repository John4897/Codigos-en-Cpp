#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void AgregarEquipo();
void MostrarInventario();
void BorrarEquipo();
void ModificarEquipo();
void GuardarInventario();
void CargarInventario();
void MostrarAyuda();

struct Equipo {
    int id_equipo;
    char descripcion[100];
    int categoria;
    char nombre_producto[40];
    char estado[2];
    char propietario[40];
    char fecha_compra[12];
    float valor;
};

vector<Equipo> inventario;
const char RutaArchivo[] = "Inventario.bin";

int main(){
	int opcion;
	
    do {
    	system("cls");
        cout << "\t\t--Sistema de Inventario MedTech Innovations--\n\n" << endl;
        cout << "Seleccione una opcion:\n" << endl;
        cout << "1. Agregar equipo" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Borrar equipo" << endl;
        cout << "4. Modificar equipo" << endl;
        cout << "5. Guardar inventario" << endl;
        cout << "6. Cargar inventario" << endl;
        cout << "7. Ayuda" << endl;
        cout << "8. Salir" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                AgregarEquipo();
                break;
            
			case 2:
                MostrarInventario();
                break;
            
			case 3:
                BorrarEquipo();
                break;
            
			case 4:
              ModificarEquipo();
                break;
           
		   	case 5:
                GuardarInventario();
                break;
           
		    case 6:
                CargarInventario();
                break;
           
		   	case 7:
             	MostrarAyuda();
            	break;
            
			case 8:
            	cout << "\nSaliendo del programa...\n" << endl; 
            	break;
                  
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n" << endl;
                system("pause");
                break;
        }
    }while(opcion != 8);
	
	return 0;
}

void AgregarEquipo(){
    Equipo equipo;
    
    system("cls");
    cout << "\t\t=== Agregar Equipo ===\n\n" << endl;
    cout << "Ingrese el ID del equipo: ";
    cin >> equipo.id_equipo;
    cin.ignore();
    cout << "Ingrese la descripcion del equipo: ";
    cin.getline(equipo.descripcion, 100);
    cout << "Ingrese la categoria del equipo (01-07): ";
    cin >> equipo.categoria;
    cin.ignore();
    cout << "Ingrese el nombre del producto: ";
    cin.getline(equipo.nombre_producto, 20);
    cout << "Ingrese el estado del elemento (U para en uso / R para en reparacion / FS para fuera de servicio): ";
    cin >> equipo.estado;
    cin.ignore();
    cout << "Ingrese el propietario: ";
    cin.getline(equipo.propietario, 40);
    cout << "Ingrese la fecha de compra del elemento (dd-mm-yyyy): ";
    cin >> equipo.fecha_compra;
    cout << "Ingrese el precio del nuevo elemento: ";
    cin >> equipo.valor;

    inventario.push_back(equipo);
    cout << "\nEquipo agregado al inventario correctamente.\n" << endl;
    
	system("pause");
}

void MostrarInventario(){
	int i;
	
	system("cls");
    cout << "\t\t=== Inventario MedTech Innovations ===\n\n" << endl;
	
	if(inventario.size() == 0){
		cout << "El inventario esta vacio.\n" << endl;
		system("pause");
	}
	else{
		cout << "=============================" << endl;
		for(i = 0; i < inventario.size(); i++){
			cout << "ID: " << inventario[i].id_equipo << endl;
			cout << "Descripcion: " << inventario[i].descripcion << endl;
			cout << "Categoria: " << inventario[i].categoria << endl;
			cout << "Nombre del producto: " << inventario[i].nombre_producto << endl;
			cout << "Estado: " << inventario[i].estado << endl;
			cout << "Porpietario: " << inventario[i].propietario << endl;
			cout << "Fecha de compra: " << inventario[i].fecha_compra << endl;
			cout << "Valor: " << inventario[i].valor << endl;
			cout << "-----------------------------" << endl;
		}
		cout << endl;
		
		system("pause");
	}
}

void BorrarEquipo(){
	int id, i, x, encontrado = 0;
	
	system("cls");
    cout << "\t\t=== Borrar equipo ===\n\n" << endl;
    
    if(inventario.size() == 0){
    	cout << "No hay ningun equipo en el inventario.\n" << endl;
	}
	else{
		cout << "Ingrese el ID del equipo que desea eliminar del inventario: ";
		cin >> id;
		
		for(i = 0; i < inventario.size(); i++){
			if(id == inventario[i].id_equipo){
				encontrado = 1;
				x = i;
				break;
			}
		}
		
		if(encontrado == 1){
			inventario.erase(inventario.begin() + x);
			cout << "\nEquipo eliminado correctamente.\n" << endl;
		}
		else{
			cout << "\nError: no existe un equipo en el inventario con ese ID.\n" << endl;
		}
	}
    	
    system("pause");
}

void ModificarEquipo(){
	int id, i, x, encontrado = 0;
	
	system("cls");
    cout << "\t\t=== Modificar Equipo ===\n\n" << endl;
	if(inventario.size() == 0){
		cout << "No hay ningun equipo en el inventario.\n" << endl;
	}
	else{
		cout << "Ingrese el ID del equipo que desea modificar: ";
		cin >> id;
		
		for(i = 0; i < inventario.size(); i++){
			if(id == inventario[i].id_equipo){
				encontrado = 1;
				x = i;
				break;
			}
		}
		
		if(encontrado == 1){
			cout << "Ingrese el nuevo ID del equipo: ";
    		cin >> inventario[i].id_equipo;
    		cin.ignore();
    		cout << "Ingrese la nueva descripcion del equipo: ";
    		cin.getline(inventario[i].descripcion, 100);
    		cout << "Ingrese la nueva categoria del equipo (01-07): ";
    		cin >> inventario[i].categoria;
    		cin.ignore();
    		cout << "Ingrese el nuevo nombre del producto: ";
    		cin.getline(inventario[i].nombre_producto, 20);
    		cout << "Ingrese el nuevo estado del elemento (U para en uso / R para en reparacion / FS para fuera de servicio): ";
    		cin >> inventario[i].estado;
    		cin.ignore();
    		cout << "Ingrese el nuevo propietario: ";
    		cin.getline(inventario[i].propietario, 40);
    		cout << "Ingrese la nueva fecha de compra del elemento (dd-mm-yyyy): ";
    		cin >> inventario[i].fecha_compra;
    		cout << "Ingrese el nuevo precio del nuevo elemento: ";
    		cin >> inventario[i].valor;
		}
		else{
			cout << "\nError: no existe un equipo en el inventario con ese ID." << endl;
		}
	}
	cout << endl;
	
	system("pause");
}

void GuardarInventario(){
	int i;
	
	system("cls");
    cout << "\t\t=== Guardar Inventario ===\n\n" << endl;
    
    if(inventario.size() == 0){
    	cout << "El inventario esta vacio.\n" << endl;
	}
	else{
		FILE* Archivo = fopen(RutaArchivo, "wb");
	
		if(Archivo != NULL){
			Equipo Equipo_aux;
		
			for(i = 0; i < inventario.size(); i++){
				Equipo_aux = inventario[i];

				fwrite(&Equipo_aux, sizeof(Equipo), 1, Archivo);
			}
		
			cout << "El inventario se ha guardado.\n" << endl;
		}
		else{
			cout << "Error al abrir el archivo.\n" << endl;
		}
		fclose(Archivo);
	}
	
	system("pause");	
}

void CargarInventario(){
	int i;
	
	system("cls");
    cout << "\t\t=== Cargar Inventario ===\n\n" << endl;
	
	FILE* Archivo = fopen(RutaArchivo, "rb");
	
	if(Archivo != NULL){
		for(i = 0; i < inventario.size(); i++){
			inventario.erase(inventario.begin());
		}
		
		Equipo Equipo_aux;
		
		while(fread(&Equipo_aux, sizeof(Equipo), 1, Archivo) == 1){
			inventario.push_back(Equipo_aux);
		}
		cout << "El inventario se ha cargado.\n" << endl;
	}
	else{
		cout << "Error al abrir el archivo.\n" << endl;
	}
	
	fclose(Archivo);
	
	system("pause");
}

void MostrarAyuda(){
	char opcion;
	
	system("cls");
    cout << "\t\t=== Ayuda ===\n\n" << endl;
    cout << "1. Agregar equipo: Permite agregar un nuevo equipo al inventario." << endl;
    cout << "2. Mostrar inventario: Muestra todos los equipos en el inventario." << endl;
    cout << "3. Borrar equipo: Permite eliminar un equipo existente en el inventario." << endl;
    cout << "4. Modificar equipo: Permite modificar un equipo existente en el inventario." << endl;
    cout << "5. Guardar inventario: Permite guardar el inventario en un archivo .txt." << endl;
    cout << "6. Cargar inventario: Permite cargar el inventario desde un archivo .txt." << endl;
    cout << "7. Ayuda: Muestra una breve descripcion de cada opcion del menu principal." << endl;
    cout << "8. Salir: Cierra el programa.\n\n" << endl;
    cout << "Presione 1 para ver informacion mas detallada o cualquier otra tecla para volver al menu principal: ";
    cin >> opcion;
    
    if(opcion == '1'){
    	system("cls");
    	cout << "\t\t=== Agregar equipo ===\n\n" << endl;
    	cout << "ID: Identificacion unica para cada equipo en el inventario." << endl;
    	cout << "Descripcion: Permite descripciones mas detalladas." << endl;
    	cout << "Categoria: Numero que representa la categoria del equipo:" << endl;
    	cout << "   01. Equipo de Diagnostico = Ecograficos, Equipos rayos x, tomografos..." << endl;
   		cout << "   02. Equipo de Tratamiento = Respiradores, Bomba de infusion, laseres terapeuticos..." << endl;
    	cout << "   03. Equipo de Moritorizacion = Monitor signos vitales, electriocardiografos, monitor presion arterial..." << endl;
    	cout << "   04. Equipo de Instrumental Quirurgico = bisturis, pinzas, tijeras..." << endl;
    	cout << "   05. Equipo de Laboratorio = Centrifugas, microoscopios, espectrofotometros..." << endl;
    	cout << "   06. Equipo de Mobiliario clinico = Camas hospitaliarias, mesas de examen, sillas de ruedas..." << endl;
    	cout << "   07. Dispositivos medicos especializados = Marcapasos, protesis, implantes...\n" << endl;
    	cout << "Estado: Estado representado por codigos cortos ('U' para en uso, 'R' para en reparacion, 'FS' para fuera de servicio)" << endl;
    	cout << "Propietario: Nombre del propietario o departamento al que pertenece el equipo." << endl;
    	cout << "Fecha de compra: Fecha de compra del equipo en formato dd-mm-yyyy." << endl;
    	cout << "Valor: Valor monetario del equipo, representando su costo de adquisicion.\n" << endl;
    	
		system("pause");
	}
}
