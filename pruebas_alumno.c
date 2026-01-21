#include "pa2m.h"
#include "src/tp.h"
#include "src/abb_estructura_privada.h"
#include "src/lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void la_cantidad_de_pokemones_guardados_en_el_struct_es_correcta()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(
		tp_cantidad_pokemon(tp) == 25,
		"La cantidad de pokemones guardados en el struct es correcta");

	tp_destruir(tp);
}

void buscar_pokemon_en_el_arbol()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_buscar_pokemon(tp, "draTINi") != NULL,
		     "Se encontro dratini");
	pa2m_afirmar(tp_buscar_pokemon(tp, "Rattata") != NULL,
		     "Se encontro rattata");
	pa2m_afirmar(tp_buscar_pokemon(tp, "Bulbasaur") != NULL,
		     "Se encontro bulbasaur");
	pa2m_afirmar(tp_buscar_pokemon(tp, "Squirtle") != NULL,
		     "Se encontro squirtle");
	pa2m_afirmar(tp_buscar_pokemon(tp, "Zapdos") != NULL,
		     "Se encontro zapdos");

	tp_destruir(tp);
}

void prueba_para_seleccionar_pokemon_distintos_para_cada_jugador()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_seleccionar_pokemon(tp, JUGADOR_1, "PIkachu"),
		     "Selecciono el pokemon para el primer jugador");
	pa2m_afirmar(tp_seleccionar_pokemon(tp, JUGADOR_2, "Raichu"),
		     "Selecciono el pokemon para el segundo jugador");

	tp_destruir(tp);
}

void selecciono_los_mismos_pokemon_y_devuelve_false()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu"),
		     "Selecciono el pokemon para el primer jugador");
	pa2m_afirmar(
		!tp_seleccionar_pokemon(tp, JUGADOR_2, "pikachu"),
		"Seleccione el mismo pokemon para el segundo jugador y devolvio false");

	tp_destruir(tp);
}

void agregar_obstaculos_y_verificar_longitud()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);
	size_t cantidad =
		tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 4);

	pa2m_afirmar(cantidad == 5, "La cantidad de obstaculos es correcta");

	tp_destruir(tp);
}

void quitar_un_obstaculo_y_verificar_longitud()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	size_t cantidad =
		tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 4);

	pa2m_afirmar(cantidad == 3, "Agregue 3 obstaculos");

	size_t cantidad_removido = tp_quitar_obstaculo(tp, JUGADOR_1, 4);

	pa2m_afirmar(cantidad_removido == 2,
		     "Elimine un obstaculo y quedan solamente 2");

	tp_destruir(tp);
}

void quitar_tres_obstaculos_y_verificar_longitud()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "Pikachu");

	//printf("%s\n",tp_nombres_disponibles(tp));

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);

	size_t cantidad =
		tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 4);

	pa2m_afirmar(cantidad == 9, "Agregue 9 obstaculos");

	tp_quitar_obstaculo(tp, JUGADOR_1, 0);
	tp_quitar_obstaculo(tp, JUGADOR_1, 5);
	size_t cantidad_removido = tp_quitar_obstaculo(tp, JUGADOR_1, 8);

	pa2m_afirmar(cantidad_removido == 6,
		     "Elimine tres elementos y quedan 6");

	tp_destruir(tp);
}

void quitar_todos_los_obstaculos_y_verificar_longitud()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 4);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 5);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 6);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 7);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 8);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 9);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 10);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 11);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 12);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 13);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 14);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 15);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 16);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 17);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 18);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 19);

	size_t cantidad =
		tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 20);

	pa2m_afirmar(cantidad == 21, "Agregue 21 obstaculos");

	tp_quitar_obstaculo(tp, JUGADOR_1, 0);
	tp_quitar_obstaculo(tp, JUGADOR_1, 1);
	tp_quitar_obstaculo(tp, JUGADOR_1, 2);
	tp_quitar_obstaculo(tp, JUGADOR_1, 3);
	tp_quitar_obstaculo(tp, JUGADOR_1, 4);
	tp_quitar_obstaculo(tp, JUGADOR_1, 5);
	tp_quitar_obstaculo(tp, JUGADOR_1, 6);
	tp_quitar_obstaculo(tp, JUGADOR_1, 7);
	tp_quitar_obstaculo(tp, JUGADOR_1, 8);
	tp_quitar_obstaculo(tp, JUGADOR_1, 9);
	tp_quitar_obstaculo(tp, JUGADOR_1, 10);
	tp_quitar_obstaculo(tp, JUGADOR_1, 11);
	tp_quitar_obstaculo(tp, JUGADOR_1, 12);
	tp_quitar_obstaculo(tp, JUGADOR_1, 13);
	tp_quitar_obstaculo(tp, JUGADOR_1, 14);
	tp_quitar_obstaculo(tp, JUGADOR_1, 15);
	tp_quitar_obstaculo(tp, JUGADOR_1, 16);
	tp_quitar_obstaculo(tp, JUGADOR_1, 17);
	tp_quitar_obstaculo(tp, JUGADOR_1, 18);
	tp_quitar_obstaculo(tp, JUGADOR_1, 19);

	size_t cantidad_removido = tp_quitar_obstaculo(tp, JUGADOR_1, 20);

	pa2m_afirmar(cantidad_removido == 0,
		     "Elimine todos los obstaculos y quedo vacio");

	tp_destruir(tp);
}

void verificar_si_los_obstaculos_son_los_correctos()
{
	TP *tp = tp_crear("pokemones.txt");

	char *orden_obstaculos = NULL;
	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 3);
	size_t cantidad =
		tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 4);

	pa2m_afirmar(cantidad == 5, "Se agregaron 5 obstaculos");

	orden_obstaculos = tp_obstaculos_pista(tp, JUGADOR_1);

	pa2m_afirmar(orden_obstaculos[0] ==
			     IDENTIFICADOR_OBSTACULO_INTELIGENCIA,
		     "El primer caracter del string es Inteligencia");
	pa2m_afirmar(orden_obstaculos[1] == IDENTIFICADOR_OBSTACULO_FUERZA,
		     "El primer caracter del string es fuerza");
	pa2m_afirmar(orden_obstaculos[2] == IDENTIFICADOR_OBSTACULO_DESTREZA,
		     "El primer caracter del string es destreza");
	pa2m_afirmar(orden_obstaculos[3] ==
			     IDENTIFICADOR_OBSTACULO_INTELIGENCIA,
		     "El primer caracter del string es Inteligencia");
	pa2m_afirmar(orden_obstaculos[4] == IDENTIFICADOR_OBSTACULO_FUERZA,
		     "El primer caracter del string es fuerza");

	tp_quitar_obstaculo(tp, JUGADOR_1, 0);
	tp_quitar_obstaculo(tp, JUGADOR_1, 1);
	tp_quitar_obstaculo(tp, JUGADOR_1, 2);
	tp_quitar_obstaculo(tp, JUGADOR_1, 3);
	tp_quitar_obstaculo(tp, JUGADOR_1, 4);

	free(orden_obstaculos);
	tp_destruir(tp);
}

void elimino_obstaculos_y_verifico_si_el_orden_es_correcto()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 1);

	pa2m_afirmar(tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2) ==
			     3,
		     "Se agregaron 3 obstaculos");

	char *obstaculos = tp_obstaculos_pista(tp, JUGADOR_1);

	pa2m_afirmar(obstaculos[0] == IDENTIFICADOR_OBSTACULO_INTELIGENCIA,
		     "El primer caracter del string es Inteligencia");
	pa2m_afirmar(obstaculos[1] == IDENTIFICADOR_OBSTACULO_DESTREZA,
		     "El primer caracter del string es fuerza");
	pa2m_afirmar(obstaculos[2] == IDENTIFICADOR_OBSTACULO_FUERZA,
		     "El primer caracter del string es fuerza");

	pa2m_afirmar(tp_quitar_obstaculo(tp, JUGADOR_1, 0) == 2,
		     "Elimine el obstaculo inteligencia");
	pa2m_afirmar(tp_quitar_obstaculo(tp, JUGADOR_1, 0) == 1,
		     "Elimine el obstaculo destreza");

	char *obstaculos_actualizado = tp_obstaculos_pista(tp, JUGADOR_1);

	pa2m_afirmar(
		obstaculos_actualizado[0] == IDENTIFICADOR_OBSTACULO_FUERZA,
		"elimine dos obstaculos y ahora el primer caracter del string es fuerza");
	free(obstaculos);
	free(obstaculos_actualizado);
	tp_destruir(tp);
}

void tiempo_que_tarde_el_pokemon_en_recorrer_la_pista_segun_sus_atributos()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);

	pa2m_afirmar(
		tp_calcular_tiempo_pista(tp, JUGADOR_1) == 3,
		"Las unidades de tiempo para recorrer la pista FIDF con pikachu es 3");

	tp_destruir(tp);
}

void recorro_la_pista_pero_hay_elementos_repetidos_seguidos_verifico_si_el_tiempo_es_correcto()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 3);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 4);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 5);

	pa2m_afirmar(
		tp_calcular_tiempo_pista(tp, JUGADOR_1) == 3,
		"Las unidades de tiempo para recorrer la pista FFFIDF con pikachu es 6");

	tp_destruir(tp);
}

void selecciono_pikachu_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);

	char *tiempos = tp_tiempo_por_obstaculo(tp, JUGADOR_1);

	pa2m_afirmar(tiempos[0] == '0', "El resultado es 0");
	pa2m_afirmar(tiempos[1 * 2] == '2', "El resultado es 2");
	pa2m_afirmar(tiempos[2 * 2] == '1', "El resultado es 1");
	pa2m_afirmar(tiempos[3 * 2] == '0', "El resultado es 0");
	pa2m_afirmar(tp_calcular_tiempo_pista(tp, JUGADOR_1) == 3,
		     "Se calculo bien el tiempo para cada obstaculo");

	free(tiempos);
	tp_destruir(tp);
}

void selecciono_pikachu_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo_hay_repetidos()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachu");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 3);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 4);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 5);

	char *tiempos = tp_tiempo_por_obstaculo(tp, JUGADOR_1);

	pa2m_afirmar(tiempos[0] == '0', "El resultado es 0");
	pa2m_afirmar(tiempos[1 * 2] == '0', "El resultado es 0");
	pa2m_afirmar(tiempos[2 * 2] == '0', "El resultado es 0");
	pa2m_afirmar(tiempos[3 * 2] == '2', "El resultado es 2");
	pa2m_afirmar(tiempos[4 * 2] == '1', "El resultado es 1");
	pa2m_afirmar(tiempos[5 * 2] == '0', "El resultado es 0");
	pa2m_afirmar(
		tp_calcular_tiempo_pista(tp, JUGADOR_1) == 3,
		"Se calculo bien el tiempo para cada obstaculo, habiendo repetidos");

	free(tiempos);
	tp_destruir(tp);
}

void selecciono_Meowth_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo_hay_repetidos()
{
	TP *tp = tp_crear("pokemones.txt");

	tp_seleccionar_pokemon(tp, JUGADOR_1, "Meowth");

	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 0);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 1);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 2);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_FUERZA, 3);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 4);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_DESTREZA, 5);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 6);
	tp_agregar_obstaculo(tp, JUGADOR_1, OBSTACULO_INTELIGENCIA, 7);

	char *tiempos = tp_tiempo_por_obstaculo(tp, JUGADOR_1);

	pa2m_afirmar(tiempos[0] == '4', "El resultado es 4");
	pa2m_afirmar(tiempos[1 * 2] == '5', "El resultado es 5");
	pa2m_afirmar(tiempos[2 * 2] == '5', "El resultado es 5");
	pa2m_afirmar(tiempos[3 * 2] == '4', "El resultado es 4");
	pa2m_afirmar(tiempos[4 * 2] == '4', "El resultado es 4");
	pa2m_afirmar(tiempos[5 * 2] == '3', "El resultado es 3");
	pa2m_afirmar(tiempos[6 * 2] == '5', "El resultado es 5");
	pa2m_afirmar(tiempos[7 * 2] == '4', "El resultado es 4");

	pa2m_afirmar(
		tp_calcular_tiempo_pista(tp, JUGADOR_1) == 34,
		"EL resultado es 34, Se calculo bien el tiempo para cada obstaculo, habiendo repetidos");

	free(tiempos);
	tp_destruir(tp);
}

void usar_un_archivo_null_devuelve_NULL()
{
	TP *tp = tp_crear(NULL);

	pa2m_afirmar(tp == NULL, "El archivo es NULL, devuelvo NULL");

	tp_destruir(tp);
}

void si_el_tp_es_NULL_a_cantidad_de_pokemones_es_cero()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_cantidad_pokemon(NULL) == 0,
		     "El tp es NULL, la cantidad de pokemones es 0");

	tp_destruir(tp);
}

void pokemon_inexistente_devuelve_null()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_seleccionar_pokemon(tp, JUGADOR_1, "pikachuu") == false,
		     "El pokemon no existe, devuelve false");

	tp_destruir(tp);
}

void los_nombres_disponibles_recibe_null_devuelve_null()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_nombres_disponibles(NULL) == NULL,
		     "El tp es NULL, devuelve NULL");

	tp_destruir(tp);
}

void el_obstaculo_o_la_posicion_son_invalidas_devuelvo_null()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_agregar_obstaculo(NULL, JUGADOR_1, 0, 0) == 0,
		     "no puedo agregar un obstaculo");

	tp_destruir(tp);
}

void no_puedo_calcular_el_tiempo_de_una_pista_vacia()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(tp_calcular_tiempo_pista(NULL, JUGADOR_1) == 0,
		     "No puedo calcular el tiempo de una pista vacia");

	tp_destruir(tp);
}

void no_puedo_calcular_el_tiempo_de_cada_obstaculo_de_una_pista_vacia()
{
	TP *tp = tp_crear("pokemones.txt");

	pa2m_afirmar(
		tp_tiempo_por_obstaculo(NULL, JUGADOR_1) == NULL,
		"No puedo calcular el tiempo de cada obstaculo de una pista vacia");

	tp_destruir(tp);
}

int main()
{
	pa2m_nuevo_grupo("SE VERIFICA LA CANTIDAD DE POKEMONES");
	la_cantidad_de_pokemones_guardados_en_el_struct_es_correcta();
	pa2m_nuevo_grupo("PRUEBAS DE BUSQUEDA DEL POKEMON POR SU NOMBRE");
	buscar_pokemon_en_el_arbol();
	pa2m_nuevo_grupo("PRUEBA DE SELECCIONAR");
	prueba_para_seleccionar_pokemon_distintos_para_cada_jugador();
	selecciono_los_mismos_pokemon_y_devuelve_false();
	pa2m_nuevo_grupo("PRUEBAS DE OBSTACULOS");
	agregar_obstaculos_y_verificar_longitud();
	quitar_un_obstaculo_y_verificar_longitud();
	quitar_tres_obstaculos_y_verificar_longitud();
	quitar_todos_los_obstaculos_y_verificar_longitud();
	pa2m_nuevo_grupo("PRUEBAS RESPECTO A LA PISTA");
	verificar_si_los_obstaculos_son_los_correctos();
	elimino_obstaculos_y_verifico_si_el_orden_es_correcto();
	pa2m_nuevo_grupo("PRUEBAS RESPECTO AL TIEMPO");
	tiempo_que_tarde_el_pokemon_en_recorrer_la_pista_segun_sus_atributos();
	recorro_la_pista_pero_hay_elementos_repetidos_seguidos_verifico_si_el_tiempo_es_correcto();
	selecciono_pikachu_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo();
	selecciono_pikachu_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo_hay_repetidos();
	selecciono_Meowth_recorro_la_pista_y_verifico_que_el_string_csv_sea_correcto_por_cada_obstaculo_hay_repetidos();
	pa2m_nuevo_grupo("PRUEBAS CON NULL");
	usar_un_archivo_null_devuelve_NULL();
	si_el_tp_es_NULL_a_cantidad_de_pokemones_es_cero();
	pokemon_inexistente_devuelve_null();
	los_nombres_disponibles_recibe_null_devuelve_null();
	el_obstaculo_o_la_posicion_son_invalidas_devuelvo_null();
	no_puedo_calcular_el_tiempo_de_una_pista_vacia();
	no_puedo_calcular_el_tiempo_de_cada_obstaculo_de_una_pista_vacia();
	/*
	*/

	return pa2m_mostrar_reporte();
}