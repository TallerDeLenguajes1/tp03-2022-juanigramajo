#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
} typedef Producto;

struct Cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;
} typedef Cliente;


void cargarClientes(Cliente *clientes, int cantClientes);
void cargarCliente(Cliente *cliente, int idCliente);
void cargarProductos(Producto *pProductos, int cantProductos);
void mostrarClientes(Cliente *clientes, int cantClientes);
void mostrarCliente(Cliente *cliente, int idCliente);
float precioFinal(Producto *pProductos, int idProductos);
float costoTotal(Producto producto);

int main(){

    srand(time(NULL));

    int cantClientes;
    Cliente *clientes;


    printf("\nIndique la cantidad de clientes a ingresar: ");
    scanf("%d", &cantClientes);

    while (cantClientes < 1 || cantClientes > 5) {
        printf("\n\nError de formato, indique la cantidad de clientes a ingresar: ");
        scanf("%d", &cantClientes);
    }

    fflush(stdin);
    

    clientes = (Cliente*)malloc(sizeof(Cliente)*cantClientes);

    cargarClientes(clientes, cantClientes);

    mostrarClientes(clientes, cantClientes);


    for (int i=0; i<cantClientes; i++){

        free(clientes[i].nombreCliente);

        for (int j=0; j<clientes->cantidadProductosAPedir; j++)
        {
            free(clientes[i].productos[j].tipoProducto);
        }
        
        free(clientes[i].productos);

    }
    
    free(clientes);

    return 0;
}


void cargarClientes(Cliente *clientes, int cantClientes){

    printf("\n\n------CARGA DE DATOS------");

    for (int i=0; i<cantClientes; i++){

        printf("\n------Cliente [%d]------", i+1);
        
        cargarCliente(clientes, i+1);

        clientes++;
    }

}

void cargarCliente(Cliente *cliente, int idCliente){

    cliente->clienteID = idCliente;

    char *buffer = (char*)malloc(60*sizeof(char));
    printf("\nNombre del cliente: ");
    gets(buffer);

    cliente->nombreCliente = (char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(cliente->nombreCliente, buffer);


    cliente->cantidadProductosAPedir = rand()%5 + 1;

    cliente->productos = (Producto*)malloc(cliente->cantidadProductosAPedir*sizeof(Producto));
    
    cargarProductos(cliente->productos, cliente->cantidadProductosAPedir);

    free(buffer);
}

void cargarProductos(Producto *pProductos, int cantProductos){

    int tipo;

    for (int i=0; i<cantProductos; i++){

        pProductos[i].productoID = i+1;

        pProductos[i].cantidad = rand()%10 + 1;

        tipo = rand()%5;

        pProductos[i].tipoProducto = (char*)malloc((strlen(TiposProductos[tipo])+1)*sizeof(char));

        strcpy(pProductos[i].tipoProducto, TiposProductos[tipo]);

        pProductos[i].precioUnitario = rand()%91 + 10;

    }

}

void mostrarClientes(Cliente *clientes, int cantClientes){

    printf("\n\n------MUESTRA DE DATOS------");

    for (int i=0; i<cantClientes; i++){

        mostrarCliente(clientes, i+1);
        clientes++;
    }
    
}

void mostrarCliente(Cliente *cliente, int idCliente){

    float pfinal;

    printf("\n\n------Cliente ID [%d]------", idCliente);

    printf("\nNombre: %s", cliente->nombreCliente);
  
    printf("\nTiene %d productos: ", cliente->cantidadProductosAPedir);

    pfinal = precioFinal(cliente->productos,cliente->cantidadProductosAPedir);

    printf("\n\n---Total de su compra: $%.2f ---\n", pfinal);

}

float precioFinal(Producto *pProductos, int idProductos){

    float total = 0;

    for (int i=0; i<idProductos; i++){

        printf("\n\nProducto: [%d]\nTipo: %s  |  Precio unitario: $%.2f  |  Cantidad: %d  |  Costo total: $%.2f", pProductos[i].productoID, pProductos[i].tipoProducto, pProductos[i].precioUnitario, pProductos[i].cantidad, costoTotal(pProductos[i]));

        total = total + costoTotal(pProductos[i]);

    }
    
    return total;
}

float costoTotal(Producto producto){

    return producto.cantidad*producto.precioUnitario;
}

