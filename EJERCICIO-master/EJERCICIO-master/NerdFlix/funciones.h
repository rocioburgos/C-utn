typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
} eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;

} eCliente;

typedef struct
{
    int idCliente;
    int idSerie;
} eClientes_Series;

typedef struct//Para el punto 5
{
    int idSerie;
    int cont;
} eLoser;



int menu();
void cargarSeries(eSerie series[]);
void cargarClientes(eCliente clientes[]);
void cargarCliente_Serie(eClientes_Series clientesSeries[]);
void cargarSeriesLoser(eLoser loser[],eSerie serie[],int S);
void mostrarClienteConSerie(eCliente cliente[],int C,eSerie serie[], int S,eClientes_Series CliSe[],int cs);
void MostrarTodos(eCliente cliente[],int tamC,eSerie serie[],int tamS);
void clientesPorSerie(eCliente cliente[],int C, eSerie serie[], int S, eClientes_Series cliSe[],int cs);
void buscarSerie(eCliente cliente[],int C, eSerie serie[], int S, eClientes_Series cliSe[],int cs);
void menosPopular(eLoser loser[], int L, eClientes_Series cliSe[],int cs, eSerie serie[]);

