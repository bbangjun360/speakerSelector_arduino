void setup() {
    delay(100);
    Serial.begin(9600);
    delay(1000);
    Serial.println("START_MASTER");
    Serial.println();
    
  for(int i = 35; i >= 28; i--)
  {
    pinMode(i,OUTPUT); 
    digitalWrite(i, HIGH);
  }
}

void loop() {
  if(Serial.available()){
    String str = Serial.readStringUntil('\n'); 
    //Serial.println(str);
    if(str[0] == 'L'){
      switch(int(str[1]-48)){
        case 1: digitalWrite(35,!(int(str[2]-48))); Serial.println("L1"+String(str[2])); break;
        case 2: digitalWrite(34,!(int(str[2]-48))); Serial.println("L2"+String(str[2])); break;
        case 3: digitalWrite(33,!(int(str[2]-48))); Serial.println("L3"+String(str[2])); break;
        case 4: digitalWrite(32,!(int(str[2]-48))); Serial.println("L4"+String(str[2])); break;
        case 5: digitalWrite(31,!(int(str[2]-48))); Serial.println("L5"+String(str[2])); break;
        case 6: digitalWrite(30,!(int(str[2]-48))); Serial.println("L6"+String(str[2])); break;
        case 7: digitalWrite(29,!(int(str[2]-48))); Serial.println("L7"+String(str[2])); break;
        case 8: digitalWrite(28,!(int(str[2]-48))); Serial.println("L8"+String(str[2])); break;
      }
    }
    else if("AF")
    {
      for(int i = 35; i >= 28; i--)
      {
        digitalWrite(i, HIGH);
      }
      //Serial.println("AF");
    }
    else if("AN"){
      for(int i = 35; i >= 28; i--)
      {
        digitalWrite(i, LOW);
      }
      //Serial.println("AN");
    }
  }
}
