#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEH 200
#define STRLEN 64

typedef enum { COMB_GASOLINA = 1, COMB_GASOIL = 2 } TipoCombustible;

typedef struct
{
    char placa[STRLEN];
    char marca[STRLEN];
    char modelo[STRLEN];
    TipoCombustible tipo_combustible;

    double km_galon_carretera;
    double km_galon_ciudad;
    double costo_gomas;
    double km_gomas;
    double costo_seguro_anual;
    double costo_mantenimiento_por_servicio;
    double km_entre_mantenimientos;
    double costo_vehiculo;
    double vida_util_anos;
    double precio_reventa;
    double km_por_ano_promedio;
} Vehiculo;

double precio_gasolina_por_galon = 272.50;
double precio_gasoil_por_galon   = 221.60;

Vehiculo lista[MAX_VEH];
int n_veh = 0;

const char *FICH_VEH = "vehiculos.dat";
const char *FICH_CONF = "config.dat";

void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void leer_cadena(const char *prompt, char *dest, int len)
{
    printf("%s", prompt);
    if (fgets(dest, len, stdin) != NULL)
    {
        size_t L = strlen(dest);
        if (L > 0 && dest[L-1] == '\n') dest[L-1] = '\0';
    }
    else
    {
        dest[0] = '\0';
    }
}

double leer_double(const char *prompt)
{
    double x;
    char buffer[128];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0.0;
        if (sscanf(buffer, "%lf", &x) == 1) return x;
        printf("Entrada invalida. Intente de nuevo.\n");
    }
}

int leer_int(const char *prompt)
{
    int x;
    char buffer[128];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;
        if (sscanf(buffer, "%d", &x) == 1) return x;
        printf("Entrada invalida. Intente de nuevo.\n");
    }
}

void guardar_vehiculos()
{
    FILE *f = fopen(FICH_VEH, "wb");
    if (!f)
    {
        perror("Error al abrir archivo vehiculos para guardar");
        return;
    }
    fwrite(&n_veh, sizeof(n_veh), 1, f);
    if (n_veh > 0) fwrite(lista, sizeof(Vehiculo), n_veh, f);
    fclose(f);
}

void cargar_vehiculos()
{
    FILE *f = fopen(FICH_VEH, "rb");
    if (!f)
    {
        return;
    }
    if (fread(&n_veh, sizeof(n_veh), 1, f) != 1)
    {
        n_veh = 0;
        fclose(f);
        return;
    }
    if (n_veh > 0 && n_veh <= MAX_VEH) fread(lista, sizeof(Vehiculo), n_veh, f);
    fclose(f);
}

void guardar_config()
{
    FILE *f = fopen(FICH_CONF, "wb");
    if (!f)
    {
        perror("Error al abrir archivo config para guardar");
        return;
    }
    fwrite(&precio_gasolina_por_galon, sizeof(precio_gasolina_por_galon), 1, f);
    fwrite(&precio_gasoil_por_galon, sizeof(precio_gasoil_por_galon), 1, f);
    fclose(f);
}

void cargar_config()
{
    FILE *f = fopen(FICH_CONF, "rb");
    if (!f)
    {
        return;
    }
    fread(&precio_gasolina_por_galon, sizeof(precio_gasolina_por_galon), 1, f);
    fread(&precio_gasoil_por_galon, sizeof(precio_gasoil_por_galon), 1, f);
    fclose(f);
}

void mostrar_vehiculo(const Vehiculo *v, int idx)
{
    printf("---- Vehiculo %d ----\n", idx);
    printf("Placa: %s\n", v->placa);
    printf("Marca: %s\n", v->marca);
    printf("Modelo: %s\n", v->modelo);
    printf("Combustible: %s\n", v->tipo_combustible == COMB_GASOLINA ? "Gasolina" : "Gasoil");
    printf("Km/gal Carretera: %.2f\n", v->km_galon_carretera);
    printf("Km/gal Ciudad:    %.2f\n", v->km_galon_ciudad);
    printf("Costo gomas (juego): %.2f  Duracion km: %.0f\n", v->costo_gomas, v->km_gomas);
    printf("Costo seguro anual: %.2f\n", v->costo_seguro_anual);
    printf("Costo mantenimiento por servicio: %.2f  km entre servicios: %.0f\n", v->costo_mantenimiento_por_servicio, v->km_entre_mantenimientos);
    printf("Costo vehiculo: %.2f  Vida util (años): %.1f  Precio reventa: %.2f\n", v->costo_vehiculo, v->vida_util_anos, v->precio_reventa);
    printf("Km promedio x año: %.0f\n", v->km_por_ano_promedio);
    printf("---------------------\n");
}

void listar_vehiculos()
{
    if (n_veh == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    for (int i = 0; i < n_veh; ++i)
    {
        printf("[%d] %s - %s %s\n", i+1, lista[i].placa, lista[i].marca, lista[i].modelo);
    }
}

int buscar_por_placa(const char *placa)
{
    for (int i = 0; i < n_veh; ++i)
    {
        if (strcmp(lista[i].placa, placa) == 0) return i;
    }
    return -1;
}

void crear_vehiculo()
{
    if (n_veh >= MAX_VEH)
    {
        printf("Limite de vehiculos alcanzado.\n");
        return;
    }
    Vehiculo v;
    printf("--- Crear vehiculo (ingrese los datos) ---\n");
    leer_cadena("1) Placa: ", v.placa, STRLEN);
    leer_cadena("2) Marca: ", v.marca, STRLEN);
    leer_cadena("3) Modelo: ", v.modelo, STRLEN);

    int tipo = leer_int("4) Tipo combustible (1-Gasolina, 2-Gasoil): ");
    v.tipo_combustible = (tipo == 2) ? COMB_GASOIL : COMB_GASOLINA;

    v.km_galon_carretera = leer_double("5) Km x galon (carretera): ");
    v.km_galon_ciudad     = leer_double("6) Km x galon (ciudad): ");

    v.costo_gomas = leer_double("7) Costo gomas (precio juego): ");
    v.km_gomas    = leer_double("   Km de duracion de las gomas (ej: 50000): ");

    v.costo_seguro_anual = leer_double("8) Costo seguro por 12 meses: ");

    v.costo_mantenimiento_por_servicio = leer_double("9) Costo mantenimiento por servicio: ");
    v.km_entre_mantenimientos = leer_double("   Cada cuantos km se hace el servicio (ej: 10000): ");

    v.costo_vehiculo = leer_double("10) Costo vehiculo (precio de compra): ");
    v.vida_util_anos = leer_double("11) Vida util en anos (ej: 4): ");
    v.precio_reventa = leer_double("12) Precio de reventa al final de la vida util: ");

    v.km_por_ano_promedio = leer_double("13) Km por ano promedio (ej: 15000): ");

    lista[n_veh++] = v;
    guardar_vehiculos();
    printf("Vehiculo agregado con exito.\n");
}

void borrar_vehiculo()
{
    if (n_veh == 0)
    {
        printf("No hay vehiculos para borrar.\n");
        return;
    }
    char placa[STRLEN];
    leer_cadena("Ingrese la placa del vehiculo a borrar: ", placa, STRLEN);
    int idx = buscar_por_placa(placa);
    if (idx == -1)
    {
        printf("Vehiculo no encontrado.\n");
        return;
    }
    for (int i = idx; i < n_veh - 1; ++i) lista[i] = lista[i+1];
    n_veh--;
    guardar_vehiculos();
    printf("Vehiculo borrado.\n");
}

void modificar_vehiculo()
{
    if (n_veh == 0)
    {
        printf("No hay vehiculos para modificar.\n");
        return;
    }
    char placa[STRLEN];
    leer_cadena("Ingrese la placa del vehiculo a modificar: ", placa, STRLEN);
    int idx = buscar_por_placa(placa);
    if (idx == -1)
    {
        printf("Vehiculo no encontrado.\n");
        return;
    }
    Vehiculo *v = &lista[idx];
    printf("Vehiculo actual:\n");
    mostrar_vehiculo(v, idx+1);

    printf("Ingrese nuevos valores (enter para mantener actual):\n");
    char temp[STRLEN];

    leer_cadena("Nueva Marca: ", temp, STRLEN);
    if (strlen(temp)) strncpy(v->marca, temp, STRLEN);

    leer_cadena("Nuevo Modelo: ", temp, STRLEN);
    if (strlen(temp)) strncpy(v->modelo, temp, STRLEN);

    char buf[128];
    printf("Tipo combustible actual (%d). Presione enter para mantener, 1-Gasolina,2-Gasoil: ", v->tipo_combustible);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        int t;
        if (sscanf(buf, "%d", &t)==1) v->tipo_combustible = (t==2)? COMB_GASOIL: COMB_GASOLINA;
    }

    printf("Km/gal Carretera actual (%.2f). Nuevo: ", v->km_galon_carretera);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf", &d)==1) v->km_galon_carretera = d;
    }

    printf("Km/gal Ciudad actual (%.2f). Nuevo: ", v->km_galon_ciudad);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf", &d)==1) v->km_galon_ciudad = d;
    }

    printf("Costo gomas actual (%.2f). Nuevo: ", v->costo_gomas);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->costo_gomas = d;
    }

    printf("Km gomas actual (%.0f). Nuevo: ", v->km_gomas);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->km_gomas = d;
    }

    printf("Costo seguro anual actual (%.2f). Nuevo: ", v->costo_seguro_anual);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->costo_seguro_anual = d;
    }

    printf("Costo mantenimiento por servicio actual (%.2f). Nuevo: ", v->costo_mantenimiento_por_servicio);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->costo_mantenimiento_por_servicio = d;
    }

    printf("Km entre mantenimientos actual (%.0f). Nuevo: ", v->km_entre_mantenimientos);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->km_entre_mantenimientos = d;
    }

    printf("Costo vehiculo actual (%.2f). Nuevo: ", v->costo_vehiculo);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->costo_vehiculo = d;
    }

    printf("Vida util anos actual (%.1f). Nuevo: ", v->vida_util_anos);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->vida_util_anos = d;
    }

    printf("Precio reventa actual (%.2f). Nuevo: ", v->precio_reventa);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->precio_reventa = d;
    }

    printf("Km x ano promedio actual (%.0f). Nuevo: ", v->km_por_ano_promedio);
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) v->km_por_ano_promedio = d;
    }

    guardar_vehiculos();
    printf("Vehiculo modificado.\n");
}

void gestionar_datos_generales()
{
    printf("Precio actual gasolina por galon: %.2f\n", precio_gasolina_por_galon);
    printf("Precio actual gasoil por galon:   %.2f\n", precio_gasoil_por_galon);
    char buf[128];
    printf("1) Actualizar precio gasolina (enter para mantener): ");
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) precio_gasolina_por_galon = d;
    }
    printf("2) Actualizar precio gasoil (enter para mantener): ");
    if (fgets(buf, sizeof(buf), stdin) && buf[0] != '\n')
    {
        double d;
        if (sscanf(buf, "%lf",&d)==1) precio_gasoil_por_galon = d;
    }
    guardar_config();
    printf("Datos generales actualizados.\n");
}

typedef struct
{
    int vehiculo_idx;
    double km_total;
    double porcentaje_ciudad;
    double km_ciudad;
    double km_carretera;
    double gal_consumidos;
    double costo_combustible;
    double costo_gomas_viaje;
    double costo_seguro_viaje;
    double costo_mantenimiento_viaje;
    double depreciacion_viaje;
    double costo_total_viaje;
    double costo_por_km;
} ViajeContext;

void inicializar_contexto(ViajeContext *ctx)
{
    ctx->vehiculo_idx = -1;
    ctx->km_total = 0.0;
    ctx->porcentaje_ciudad = 0.0;
    ctx->km_ciudad = ctx->km_carretera = 0.0;
    ctx->gal_consumidos = ctx->costo_combustible = 0.0;
    ctx->costo_gomas_viaje = ctx->costo_seguro_viaje = ctx->costo_mantenimiento_viaje = 0.0;
    ctx->depreciacion_viaje = ctx->costo_total_viaje = ctx->costo_por_km = 0.0;
}

void calcular_viaje(ViajeContext *ctx)
{
    if (ctx->vehiculo_idx < 0 || ctx->vehiculo_idx >= n_veh) return;
    Vehiculo *v = &lista[ctx->vehiculo_idx];
    double km_totales = ctx->km_total;
    if (km_totales < 0) km_totales = 0;
    double pct_ciudad = ctx->porcentaje_ciudad;
    if (pct_ciudad < 0) pct_ciudad = 0;
    if (pct_ciudad > 100) pct_ciudad = 100;
    double km_ciudad = km_totales * (pct_ciudad / 100.0);
    double km_carretera = km_totales - km_ciudad;

    ctx->km_ciudad = km_ciudad;
    ctx->km_carretera = km_carretera;

    // Combustible
    double gal_consumidos = 0.0;
    if (v->km_galon_ciudad > 0) gal_consumidos += km_ciudad / v->km_galon_ciudad;
    if (v->km_galon_carretera > 0) gal_consumidos += km_carretera / v->km_galon_carretera;
    ctx->gal_consumidos = gal_consumidos;

    double precio_combustible = (v->tipo_combustible == COMB_GASOLINA) ? precio_gasolina_por_galon : precio_gasoil_por_galon;
    ctx->costo_combustible = gal_consumidos * precio_combustible;

    // Gomas
    ctx->costo_gomas_viaje = 0.0;
    if (v->km_gomas > 0)
    {
        double costo_por_km_gomas = v->costo_gomas / v->km_gomas;
        ctx->costo_gomas_viaje = costo_por_km_gomas * km_totales;
    }

    // Seguro
    ctx->costo_seguro_viaje = 0.0;
    if (v->km_por_ano_promedio > 0)
    {
        double seguro_por_km = v->costo_seguro_anual / v->km_por_ano_promedio;
        ctx->costo_seguro_viaje = seguro_por_km * km_totales;
    }

    // Mantenimiento
    ctx->costo_mantenimiento_viaje = 0.0;
    if (v->km_entre_mantenimientos > 0)
    {
        double mantenimiento_por_km = v->costo_mantenimiento_por_servicio / v->km_entre_mantenimientos;
        ctx->costo_mantenimiento_viaje = mantenimiento_por_km * km_totales;
    }

    // Depreciacion
    ctx->depreciacion_viaje = 0.0;
    double km_total_vida_util = 0.0;
    if (v->km_por_ano_promedio > 0 && v->vida_util_anos > 0)
    {
        km_total_vida_util = v->km_por_ano_promedio * v->vida_util_anos;
    }
    else if (v->vida_util_anos > 0)
    {
        km_total_vida_util = v->vida_util_anos * 15000.0; // fallback
    }
    if (km_total_vida_util > 0)
    {
        double depreciacion_total = v->costo_vehiculo - v->precio_reventa;
        double depres_por_km = depreciacion_total / km_total_vida_util;
        ctx->depreciacion_viaje = depres_por_km * km_totales;
    }

    ctx->costo_total_viaje = ctx->costo_combustible + ctx->costo_gomas_viaje + ctx->costo_seguro_viaje + ctx->costo_mantenimiento_viaje + ctx->depreciacion_viaje;
    ctx->costo_por_km = (km_totales > 0) ? (ctx->costo_total_viaje / km_totales) : 0.0;
}

void mostrar_desglose(ViajeContext *ctx)
{
    if (ctx->vehiculo_idx < 0 || ctx->vehiculo_idx >= n_veh)
    {
        printf("Vehiculo no seleccionado.\n");
        return;
    }
    Vehiculo *v = &lista[ctx->vehiculo_idx];
    printf("\n--- Resultado desglosado del viaje ---\n");
    printf("Vehiculo: %s %s (%s)\n", v->marca, v->modelo, v->placa);
    printf("Km totales viaje: %.2f (%.2f km ciudad, %.2f km carretera)\n", ctx->km_total, ctx->km_ciudad, ctx->km_carretera);
    printf("1) Costo de gomas:        %.2f\n", ctx->costo_gomas_viaje);
    printf("2) Costo de seguro:       %.2f\n", ctx->costo_seguro_viaje);
    printf("3) Costo de combustible:  %.2f  (gal consumidos: %.3f  precio/gal: %.2f)\n", ctx->costo_combustible, ctx->gal_consumidos, (v->tipo_combustible==COMB_GASOLINA?precio_gasolina_por_galon:precio_gasoil_por_galon));
    printf("4) Costo de mantenimiento:%.2f\n", ctx->costo_mantenimiento_viaje);
    printf("5) Costo vehiculo (deprec.): %.2f\n", ctx->depreciacion_viaje);
    printf("--------------------------------------\n");
}

void menu_calculo_viaje()
{
    ViajeContext ctx;
    inicializar_contexto(&ctx);
    while (1)
    {
        printf("\n--- CALCULO COSTO VIAJE ---\n");
        printf("1) Seleccionar vehiculo\n");
        printf("2) Ingresar kilometros del viaje (ida y vuelta)\n");
        printf("3) Ingresar porcentaje de km en ciudad (0-100)\n");
        printf("4) Resultado desglosado\n");
        printf("5) Resultado - Costo por km\n");
        printf("6) Resultado - Costo total viaje\n");
        printf("0) Volver\n");
        int opt = leer_int("Seleccione opcion: ");
        if (opt == 0) break;
        switch (opt)
        {
        case 1:
            if (n_veh == 0)
            {
                printf("No hay vehiculos. Cree uno primero.\n");
                break;
            }
            listar_vehiculos();
            ctx.vehiculo_idx = leer_int("Seleccione el numero del vehiculo (ej: 1): ") - 1;
            if (ctx.vehiculo_idx < 0 || ctx.vehiculo_idx >= n_veh)
            {
                printf("Seleccion invalida.\n");
                ctx.vehiculo_idx = -1;
            }
            else printf("Vehiculo seleccionado.\n");
            break;
        case 2:
            ctx.km_total = leer_double("Ingrese kilometros totales del viaje: ");
            printf("Km totales actualizados: %.2f\n", ctx.km_total);
            break;
        case 3:
            ctx.porcentaje_ciudad = leer_double("Ingrese porcentaje de km en ciudad (0-100): ");
            if (ctx.porcentaje_ciudad < 0) ctx.porcentaje_ciudad = 0;
            if (ctx.porcentaje_ciudad > 100) ctx.porcentaje_ciudad = 100;
            printf("Porcentaje ciudad: %.2f%%\n", ctx.porcentaje_ciudad);
            break;
        case 4:
            if (ctx.vehiculo_idx == -1)
            {
                printf("Seleccione un vehiculo primero.\n");
                break;
            }
            if (ctx.km_total <= 0)
            {
                printf("Ingrese kilometros del viaje primero.\n");
                break;
            }
            calcular_viaje(&ctx);
            mostrar_desglose(&ctx);
            break;
        case 5:
            if (ctx.vehiculo_idx == -1 || ctx.km_total <= 0)
            {
                printf("Seleccione vehiculo e ingrese km primero.\n");
                break;
            }
            calcular_viaje(&ctx);
            printf("Resultado - Costo por km: %.4f\n", ctx.costo_por_km);
            break;
        case 6:
            if (ctx.vehiculo_idx == -1 || ctx.km_total <= 0)
            {
                printf("Seleccione vehiculo e ingrese km primero.\n");
                break;
            }
            calcular_viaje(&ctx);
            printf("Resultado - Costo total viaje: %.2f\n", ctx.costo_total_viaje);
            break;
        default:
            printf("Opcion invalida.\n");
        }
    }
}

void menu()
{
    while (1)
    {
        printf("\nPrograma de gestion de gastos de vehiculo por km\n");
        printf("1. Gestion de vehiculo\n");
        printf("2. Gestion de datos generales (combustible)\n");
        printf("3. Calculo costo viaje\n");
        printf("4. Listar vehiculos\n");
        printf("0. Salir\n");
        int opt = leer_int("Seleccione opcion: ");
        switch (opt)
        {
        case 1:
        {
            printf("\n-- Gestion de vehiculo --\n");
            printf("1) Crear\n2) Borrar\n3) Modificar\n4) Mostrar detalle\n0) Volver\n");
            int s = leer_int("Seleccione: ");
            if (s == 1) crear_vehiculo();
            else if (s == 2) borrar_vehiculo();
            else if (s == 3) modificar_vehiculo();
            else if (s == 4)
            {
                char placa[STRLEN];
                leer_cadena("Ingrese placa para ver detalle: ", placa, STRLEN);
                int idx = buscar_por_placa(placa);
                if (idx == -1) printf("No encontrado.\n");
                else mostrar_vehiculo(&lista[idx], idx+1);
            }
            break;
        }
        case 2:
        {
            printf("\n-- Gestion de datos generales --\n");
            printf("1) Costo combustible gasolina\n2) Costo combustible gasoil\n0) Volver\n");
            int s = leer_int("Seleccione: ");
            if (s == 1 || s == 2) gestionar_datos_generales();
            break;
        }
        case 3:
calcular_viaje:
            menu_calculo_viaje();
            break;
        case 4:
            listar_vehiculos();
            break;
        case 0:
            printf("Saliendo...\n");
            return;
        default:
            printf("Opcion invalida.\n");
        }
    }
}

int main()
{
    cargar_config();
    cargar_vehiculos();

    if (n_veh == 0)
    {
        Vehiculo ejemplo =
        {
            .placa = "ABC123",
            .marca = "Toyota",
            .modelo = "Corolla",
            .tipo_combustible = COMB_GASOLINA,
            .km_galon_carretera = 18.0,
            .km_galon_ciudad = 12.0,
            .costo_gomas = 400.0,
            .km_gomas = 50000.0,
            .costo_seguro_anual = 600.0,
            .costo_mantenimiento_por_servicio = 200.0,
            .km_entre_mantenimientos = 10000.0,
            .costo_vehiculo = 1000000.0,
            .vida_util_anos = 4.0,
            .precio_reventa = 300000.0,
            .km_por_ano_promedio = 15000.0
        };
        lista[n_veh++] = ejemplo;
        guardar_vehiculos();
    }

    printf("Proyecto final : Gestion de costo por km\n");
    menu();
    return 0;
}
