void setup() {
  Serial.begin(9600);
  for(int i = 35; i >= 28; i--)
  {
    pinMode(i,OUTPUT); 
    digitalWrite(i, HIGH);
  }
}

void loop() {
  if(Serial.available()){
    String str = Serial.readStringUntil('\n'); 
    if(str[0] == 'L'){
      switch(int(str[1]-48)){
        case 1: digitalWrite(35,!(int(str[2]-48))); break;
        case 2: digitalWrite(34,!(int(str[2]-48))); break;
        case 3: digitalWrite(33,!(int(str[2]-48))); break;
        case 4: digitalWrite(32,!(int(str[2]-48))); break;
        case 5: digitalWrite(31,!(int(str[2]-48))); break;
        case 6: digitalWrite(30,!(int(str[2]-48))); break;
        case 7: digitalWrite(29,!(int(str[2]-48))); break;
        case 8: digitalWrite(28,!(int(str[2]-48))); break;
      }
    }
    else if("AF")
    {
      for(int i = 35; i >= 28; i--)
      {
        digitalWrite(i, HIGH);
      }
    }
    else if("AN"){
      for(int i = 35; i >= 28; i--)
      {
        digitalWrite(i, LOW);
      }
    }
  }
}
