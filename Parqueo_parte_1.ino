/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB%AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Estacionamiento automatico
   Dev: Josue David Antonio Laroj Gallina, Pablo Alexander Canel Aguilo, David Del cid 
   carnets: 2022331, 2022344, 2022482
   Fecha: 25 de mayo
*/

// incluimos la libreria 
#include <Servo.h> // libreria que nos permite usar el Servo

// definimos los pines de los 2 servos que utilizaremos 
#define ServoPin 9
#define ServoPin1 10


//Funcion que devuelve la distancia(entero) medida por el sensor conectado a los pines que especifica.
// como podemos ver esta funcion servira para el uso de 2 ultrasonicos.
int medicion_Distancia(unsigned char _echoPinSensor,unsigned char _trigPinSensor);
int medicion_ultrasonico;
int medicion_Distancia1(unsigned char _echoPinSensor1,unsigned char _trigPinSensor1);
int medicion_ultrasonico1;

//tomamos cada uno de los pins del display y las definimos en una sola variable 
int DisplayPins[]= {7,8,11,12,A0,A1,A2};
//variable para realizar la suma 
int suma;
//variable para realizar la resta 
int resta=7;
// cantidad de la distancia que queremos usar
int cantidad = 10;

/*
para que el que lo vaya a cablear no se equivoque 

#define A 7;
$define B 8;
#define C 11;
#define D 12;
#define E A0
#define F A1
#define G A2

pines de los sensores 
pines Echos 3,5
pines Trigger 4,6
*/

// constructor para colocar nombre a nuestro servo motor 
Servo myServo;
Servo myServo1;


void setup()
{
 myServo.attach(ServoPin); 
 myServo1.attach(ServoPin1);
 //iniciamos los 2 servos a 0 grados 
 myServo.write(0);
 myServo1.write(0);

 // definimos los pines de los sensores que usaremos 
 pinMode(3,INPUT);
 pinMode(5,INPUT);
 pinMode(4, OUTPUT);
 pinMode(6, OUTPUT);

}

void loop()
{
//realiza una suma que el resultado es un pin y colocar unicamente el resultado de la suma para usarlo como el numero del pin
 for(int Display = 0; Display < 7; Display++)
 {
// definimos todos los pines con una linea de codigo
 pinMode(DisplayPins [Display], OUTPUT);  
 } 

 
  //Almaceno la distancia medida por el sensor ultrasonico que se encuentra
  //conectado a los pines 3, 4
 medicion_ultrasonico = medicion_Distancia(3,4); 

 if (medicion_ultrasonico <= cantidad && medicion_ultrasonico > 0) {
suma++;
}
// esta suma se hara cuando se encuentre al rango de distancia que hemos colocado 
if(suma>=1000) suma=0;
Serial.print(suma);

//usamos la funcion "Switch Case" para facilitar el trabajo
  switch(suma)
  {
 //aca empieza la funcion switch
 case 0:
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], HIGH);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], LOW);
 delay(500);
 break;
  
 case 1:
 // el servo siempre estara a 90 grados en todos para simular nuestra pluma 
 myServo.write(90);   
 digitalWrite(DisplayPins [0], LOW);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], LOW);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], LOW);
 delay(1000);
 //y cuando pase eso nuestro servo se quedara apagado
 myServo.write(0);
 delay(2000);
 break;
 
 case 2: 
 myServo.write(90); 
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], LOW);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], HIGH);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000);
 myServo.write(0);
 delay(2000);
 break;
  
 case 3:
 myServo.write(90);    
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000);
 myServo.write(0);   
 delay(2000);
 break;  
  
 case 4: 
 myServo.write(90);
 digitalWrite(DisplayPins [0], LOW);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], LOW);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000); 
 myServo.write(0); 
 delay(2000);
 break; 
    
 case 5:
 myServo.write(90);
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], LOW);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000); 
 myServo.write(0);
 delay(2000);
 break; 
    
 case 6: 
 myServo.write(90);
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], LOW);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], HIGH);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000); 
 myServo.write(0); 
 delay(2000);
 break;
  
 case 7:
 delay(2000);
 myServo.write(0);
 break;
//  cuando la suma llege a su limite el contador se reiniciara automaticamente 
}


// esta resta se hara cuando se encuentre al rango de distancia que hemos colocado 
 medicion_ultrasonico1 = medicion_Distancia1(5,6); 
if (medicion_ultrasonico1 <= cantidad && medicion_ultrasonico1> 0) {
resta--;
}

if(resta<=-1000) resta=7;
Serial.print(resta);

  switch(resta)
  //usamos la funcion "Switch Case" para facilitar el trabajo
// y desde aca comienza la funcion Switch 
  {
 case 6:
 myServo1.write(90);
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], LOW);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000); 
 myServo1.write(0); 
 delay(2000);
 myServo1.write(0);
 break;    
 
 case 5:   
 myServo1.write(90);
 digitalWrite(DisplayPins [0], LOW);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], LOW);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000); 
 myServo1.write(0); 
 delay(2000); 
 break;
  
 case 4:
 myServo1.write(90);    
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000);
 myServo1.write(0);   
 delay(2000);
 break;
    
 case 3: 
 myServo1.write(90); 
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], LOW);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], HIGH);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], HIGH);
 delay(1000);
 myServo1.write(0);
 delay(2000);
 break; 
    
 case 2:
 myServo1.write(90);   
 digitalWrite(DisplayPins [0], LOW);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], LOW);
 digitalWrite(DisplayPins [4], LOW);
 digitalWrite(DisplayPins [5], LOW);
 digitalWrite(DisplayPins [6], LOW);
 delay(1000);
 myServo1.write(0);
 delay(2000);
 break;
    
 case 1:
 myServo1.write(90);
 digitalWrite(DisplayPins [0], HIGH);
 digitalWrite(DisplayPins [1], HIGH);
 digitalWrite(DisplayPins [2], HIGH);
 digitalWrite(DisplayPins [3], HIGH);
 digitalWrite(DisplayPins [4], HIGH);
 digitalWrite(DisplayPins [5], HIGH);
 digitalWrite(DisplayPins [6], LOW);
 delay(1000);
 myServo1.write(0);
 delay(2000);
 break;
 // al finalizar con la resta nuestro servo motor se detendra y de forma automatica el valor regresa al valor original listo para usar otra ves
  }
}

//Variable donde almaceno el dato a retornar del ultrasonico numero 1
int medicion_Distancia(unsigned char _echoPinSensor,unsigned char _trigPinSensor)
{

int medicion;
int duracion_echo;

digitalWrite(_trigPinSensor, HIGH);
delayMicroseconds(10);
digitalWrite(_trigPinSensor, LOW);
duracion_echo = pulseIn(_echoPinSensor, HIGH);
medicion = duracion_echo/59;
return medicion; 
}

//Variable donde almaceno el dato a retornar del ultrasonico numero 2
int medicion_Distancia1(unsigned char _echoPinSensor1,unsigned char _trigPinSensor1)
{
int medicion1;
int duracion_echo1;

digitalWrite(_trigPinSensor1, HIGH);
delayMicroseconds(10);
digitalWrite(_trigPinSensor1, LOW);
duracion_echo1 = pulseIn(_echoPinSensor1, HIGH);
medicion1 = duracion_echo1/59;
return medicion1; 
}
