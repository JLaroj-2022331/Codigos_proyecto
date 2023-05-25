
//Funcion que devuelve la distancia(entero) medida por el sensor conectado a los pines que especifica.
// como podemos ver esta funcion servira para el uso de 3 ultrasonicos.
int medicion_Distancia(unsigned char _echoPinSensor, unsigned char _trigPinSensor);
int medicion_ultrasonico;
int medicion_Distancia1(unsigned char _echoPinSensor1, unsigned char _trigPinSensor1);
int medicion_ultrasonico1;int medicion_Distancia2(unsigned char _echoPinSensor2, unsigned char _trigPinSensor2);

//se crea una variable para almacenar todas los pines del los leds del rgb.
// se utilizo esto para que el codigo no sea tan largo(aunque ya lo es sdasjda)
int Leds[]= {8,9,10,11,A0,A1};
int distancia = 2;
int distancia2 = 50;
// se crean 2 variables con las que podemos usar para no variar la distancia y que tenga un unico valor para todo)

void setup()
{

  // definimos todos lo pines como entradas o salidas como lo observamos.
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  //se crea una suma para que el resultado de la suma sea un pin de nuestros rgbs 
  //y con esto nos ahorramos tiempo creando variables y definiendo y a la hora de utilizar solo pongamos el resultado de la suma 
  for(int RgbPins = 0; RgbPins < 7; RgbPins++)
  {
  pinMode(Leds [RgbPins], OUTPUT);  
  // y aca es donde definimos todos los pines de los leds en una sola linea de codigo
  }

  
  //Almaceno la distancia medida por el sensor ultrasonico que se encuentra
  //conectado a los pines 3, 2
  
  medicion_ultrasonico = medicion_Distancia(3,2); 
  if (medicion_ultrasonico <= distancia && medicion_ultrasonico > 0)
  {
  digitalWrite(Leds [0], HIGH);
  digitalWrite(Leds [1], LOW); 
  }
  
  else if(medicion_ultrasonico <= distancia2 && medicion_ultrasonico > 5)
  {
  digitalWrite(Leds [0], LOW);
  digitalWrite(Leds [1], HIGH);  
  }


  //Almaceno la distancia medida por el sensor ultrasonico que se encuentra
  //conectado a los pines 5, 4
  
 medicion_ultrasonico1 = medicion_Distancia1(5,4); 
  if (medicion_ultrasonico1 <= distancia && medicion_ultrasonico1 > 7)
  {
  digitalWrite(Leds [2], LOW);
  digitalWrite(Leds [3], HIGH); 
    }
  
  else if(medicion_ultrasonico1 <= distancia2 && medicion_ultrasonico1 > 7)
  {
  digitalWrite(Leds [2], HIGH);
  digitalWrite(Leds [3], LOW);
  }

  
  //Almaceno la distancia medida por el sensor ultrasonico que se encuentra

}  

 //Variable donde almaceno el dato a retornar del ultrasonico numero 1
int medicion_Distancia(unsigned char _echoPinSensor, unsigned char _trigPinSensor)
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
int medicion_Distancia1(unsigned char _echoPinSensor1, unsigned char _trigPinSensor1)
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
