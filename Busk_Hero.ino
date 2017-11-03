//The Busk Hero is a digital instrument that uses fret-like buttons to create a tonal
//center, and employs a vibrating string to determine the sounds that are produced.

//Fret buttons
int frets[5] = {37, 36, 35, 34, 33};
boolean currentFretStates[5] = {LOW, LOW, LOW, LOW, LOW};
boolean lastFretStates[5] = {LOW, LOW, LOW, LOW, LOW};

//Plus and minus buttons -- controls reverb amount
int plusVerb = 2;
boolean currentPlusVerbState = LOW;
boolean lastPlusVerbState = LOW;
int minusVerb = 3;
boolean currentMinusVerbState = LOW;
boolean lastMinusVerbState = LOW;

void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(frets[i], INPUT);
  }
  pinMode(plusVerb, INPUT);
  pinMode(minusVerb, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  checkButtons();
}

void checkButtons()
{
  //Check fret buttons
  for (int i = 0; i < 5; i++)
  {
    lastFretStates[i] = currentFretStates[i];
    currentFretStates[i] = digitalRead(frets[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    if (currentFretStates[i] == HIGH && lastFretStates[i] == LOW)
    {
      Serial.print(i);
      Serial.println(" on");
    }
    else if (currentFretStates[i] == LOW && lastFretStates[i] == HIGH)
    {
      Serial.print(i);
      Serial.println(" off");
    }
  }

  //Check plus and minus buttons
  lastPlusVerbState = currentPlusVerbState;
  currentPlusVerbState = digitalRead(2);
  lastMinusVerbState = currentMinusVerbState;
  currentMinusVerbState = digitalRead(3);

  if (currentPlusVerbState == HIGH && lastPlusVerbState == LOW)
  {
    Serial.println("+ on");
  }
  else if (currentPlusVerbState == LOW && lastPlusVerbState == HIGH)
  {
    Serial.println("+ off");
  }
  else if (currentMinusVerbState == HIGH && lastMinusVerbState == LOW)
  {
    Serial.println("- on");
  }
  else if (currentMinusVerbState == LOW && lastMinusVerbState == HIGH)
  {
    Serial.println("- off");
  } 
}


