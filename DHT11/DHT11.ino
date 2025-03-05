//Humidity & Temperature Sensor: DHT11
//DHT11 specification: https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOoodq5k05CLx921HJe_Ktn6xK4EHAoG6ZxowQMIqFFY5ctZIz5V1

//In this variable we will save the readed values
byte data[5];

//The pin where we connected the DHT11 sensor
int sensorPin=4;

//Function for reciving the data bits from the sensor
bool reciveBits(int pin){

  int i;
  byte temp=0;
  unsigned long time;
  
  //setting everything to zero
  for(i=0;i<5;i++)
    data[i]=0;

  //reciving all the 40 bit
  for(i=0;i<40;i++){

    //the LOW part of bit transfer isn't actually LOW
    //than that means we got some kind of error
    if(digitalRead(pin)==HIGH){
      return false;
    }

    //not to stuck into some kind of infine loop
    time=micros();

    //LOW part of the response should be LOW only for 50 microSec
    while(digitalRead(pin)==LOW){
      if( micros() - time >60){
          return false;
      }
    }

    time=micros();

    //Now transfering the data bit with HIGH 
    //so it shouldn't be longer than 70microSec
    while(digitalRead(pin)==HIGH){
      if( micros() - time >80){
          return false;
      }
    }

    //time more than 28-30 microsec is "1"
    //less is "0"
    if(micros() - time<20){
      //the "0" is the shorter, but it should last for 28-30 microSec
      return false;
    }else if(micros()-time<45){
      //the bit was zero
      temp=0; 
    }else{
      //the bit was one
      temp=1;
    }

    //saving each bit to his own byte in the his position
    data[i/8]= data[i/8] | (temp << (7-(i%8) ));

  }
    temp=data[0]+data[1]+data[2]+data[3];

    //checksum
    if(temp==data[4]){
      return true;
    }
    else{
      return false;
    }
}

//Sending the start signal to the DHT11 module
void startSignal(int pin){

  //We have to overtake the data-bus, so we set the pin as OUTPUT
  pinMode(pin,OUTPUT);

  //set the data-bus to LOW
  digitalWrite(pin,LOW);

  //LOW signal must last atleast 18ms
  //in my case 25ms is not enough
  delayMicroseconds(30000);

  //Letting the pull-up resistor to create the 20-40 microSec HIGH
  pinMode(pin,INPUT);
  }

//Reciving the response signal from the DHT11
bool responseSignal(int pin){

  unsigned long time = micros();

  //waiting for the Sensor to start the response signal
  while (digitalRead(pin) == HIGH) {

    //the DHT11 should start to send the response
    //after 20-40 microsec after the data-bus went back to HIGH
    //from LOW (the startSignal Part)
    if (micros() - time > 50) {  
      return false;
    }
  }

  //after that delay we will be 20 microSec into the HIGH 
  delayMicroseconds(100);
  
  //we want to check also if the HIGH level is set in the 
  //response 
  if(digitalRead(pin)==LOW){
    //error happened
    return false;
  }

  //like that we returing when it's time to recive the bits
  delayMicroseconds(60);

  return true;
}

//Function to call all the functions to get the data
void readSensor(int pin){

  startSignal(pin);

  if(!responseSignal(pin)){
    Serial.println("Bad response signal from the sensor");
    return;
  }

  if(!reciveBits(pin)){
    Serial.println("Bad checksum");
  }
  else{
    Serial.print("Humidty: ");
    Serial.print(data[0]);
    Serial.print(".");
    Serial.print(data[1]);
    Serial.print(" %");
    Serial.println("");
    
    Serial.print("Temperature: ");
    Serial.print(data[2]);
    Serial.print(".");
    Serial.print(data[3]);
    Serial.print(" C");
    Serial.println("");
  }

}

void setup() {
  //bcs the we can't send signal to the sensor in the first 1s
  delay(2000);

  Serial.begin(9600);
}

void loop() {
  readSensor(sensorPin);
  Serial.println("");
  delay(3000);
}