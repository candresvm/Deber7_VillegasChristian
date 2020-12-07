/*
 * Deber 7: Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. 
 *          Como estado inicial, la contraseña es de 4 dígitos que son: 4563. 
 * Autor: Armas Paul
 */

#include <EEPROM.h>

int i=0;
int cad; 
int contr = 4563;
String opcion;
String dato; 
String contn;
int contr1;
  
void setup() {
  Serial.begin(9600);
  EEPROM.write(0,contr);
  Serial.println("Ingrese la contraseña");
}

void loop() {
  if(Serial.available()>0){
    dato = Serial.readString();
    cad = dato.toInt();     
    if(cad==contr){ 
      Serial.println("    ");
      Serial.println("Correcto");
      Serial.println("Quiere cambiar la contraseña si o no?");
      delay(4000);
      opcion = Serial.readString();
      if(opcion=="si"){  
        Serial.println("    ");
        Serial.println("Ingrese la nueva contraseña");
        delay(4000);
        contn = Serial.readString(); 
        contr1 = contn.toInt();
        contr = contr1;      
        EEPROM.update(0,contr); 
        Serial.println("    ");
        Serial.println("Contraseña actualizada");
      }
      else{
        Serial.println("    ");
        Serial.println("Contraseña no actualizada");
      }
    }
    else{
      Serial.println("    ");
      Serial.println("Contraseña incorrecto");
    }
  }
}
