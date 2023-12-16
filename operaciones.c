#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int comprobarId(struct empleado empleados[100], int num_emp, int id);

void mostrarMenu(){
  printf("Introduce la opcion que desea realizar: \n");
  printf("1. Alta de empleado\n");
  printf("2. Baja de empleado\n");
  printf("3. Listar empleados\n");
  printf("4. Consultar datos empleado\n");
  printf("5. Modificar sueldo\n");
  printf("6. Modificar horas\n");
  printf("7. Salir\n");

}

void listarEmpleados(struct empleado empleados[100], int num_emp){
  printf("Listando los datos del empleado: \n");
  for(int i=0; i<num_emp; i++){
    printf("Nombre del Empleado: %s\n", empleados[i].nombre);
    printf("ID del Empleado: %d\n", empleados[i].id);
    printf("Sueldo del Empleado: %f\n", empleados[i].sueldo);
    printf("Horas del Empleado: %d\n", empleados[i].horas);
    printf("\n");

  }
}


int alta(struct empleado empleados[100], int num_emp){
int creado=0;
  struct empleado emp;

  fflush(stdin);
  printf("Introduce el numbre y apellido del empleado: \n");
  fgets(emp.nombre, 255, stdin);
  emp.nombre[strlen(emp.nombre)-1]='\0';

  printf("Introduce el ID del empleado: \n");
  scanf("%d", &emp.id);

  printf("Introduce el sueldo del empleado: \n");
  scanf("%f", &emp.sueldo);

  printf("Introduce las horas del empleado: \n");
  scanf("%d", &emp.horas);

  int existe = comprobarId (empleados, num_emp, emp.id);

  if(num_emp < 100){
    if (existe == 0){
      empleados[num_emp] = emp;
      creado=1;
    }else{
      printf("No se puede crear empleado. Id duplicado");
    }

  }else{
    printf("No se puede dar de alta al empleado, Cupo alcanzado");
  }
  return creado;
};

int baja(struct empleado empleados[100], int num_emp){
  int eliminado=0;
  int id, indice;
  printf("Introduce el ID del empleado que deseas eliminar: \n");
  scanf("%d", &id);

  int existe=comprobarId(empleados, num_emp, id);

  if(existe == 1){
    for(int i=0; i<num_emp; i++){
      if(empleados[i].id == id){
        indice=i;
      }
    }
        for(int j=indice; j<num_emp-1; j++){
          empleados[j]=empleados[j+1];
          struct empleado aux;
          empleados[j+1]=aux;
        }
    eliminado=1;
  }else{
    printf("No se puede eliminar empleado. ID no encontrado");
  }
 return eliminado;
}

void consultarDatosEmpleado(struct empleado empleados[100], int num_emp){
  int id;
  printf("Introduce el ID del empleado que deseas consultar: \n");
  scanf("%d", &id);

  int existe=comprobarId(empleados, num_emp, id);

  if(existe == 1){
    for (int i=0; i<num_emp; i++){
      if(empleados[i].id == id){
        printf("Listando datos del empleado con Id: %d\n", empleados[i].id);
        printf("Nombre del Empleado: %s\n", empleados[i].nombre);
        printf("Sueldo del Empleado: %.2f\n", empleados[i].sueldo);
        printf("Horas del Empleado: %d\n", empleados[i].horas);
        printf("\n");
      }
    }
  }else{
    printf("No se puede consultar datos del empleado. ID no encontrado");
  }

}

void modificarSueldo(struct empleado empleados[100], int num_emp){
  int id;
  printf("Introduce el ID del empleado que deseas modificar: \n");
  scanf("%d", &id);

  int existe=comprobarId(empleados, num_emp, id);
  if (existe == 1){
    float nuevoSueldo;
    printf("Introduce el nuevo sueldo del empleado: \n");
    scanf("%f", &nuevoSueldo);
        for (int i=0; i<num_emp; i++){
          if(empleados[i].id == id){
            empleados[i].sueldo = nuevoSueldo;
            printf("Sueldo modificado correctamente");
          }
        }
  }else{
    printf("No se puede modificar sueldo. ID no encontrado");
  }
}

void modificarHoras(struct empleado empleados[100], int num_emp){
  int id;
  printf("Introduce el ID del empleado que deseas modificar: \n");
  scanf("%d", &id);

  int existe=comprobarId(empleados, num_emp, id);
  if (existe == 1){
    int nuevasHoras;
    printf("Introduce las nuevas horas trabajadas del empleado: \n");
    scanf("%d", &nuevasHoras);
    for(int i=0; i<num_emp; i++){
      if(empleados[i].id == id){
        empleados[i].horas = nuevasHoras;
        printf("Horas modificados correctamente");
      }
    }
  }else{
    printf("No se puede modificar horas. ID no encontrado");
  }

}

int comprobarId(struct empleado empleados[100], int num_emp, int id){
int resultado=0;
  for(int i=0; i<num_emp; i++){
    if(empleados[i].id==id){
      resultado=1;
    }
  }
  return resultado;
};
