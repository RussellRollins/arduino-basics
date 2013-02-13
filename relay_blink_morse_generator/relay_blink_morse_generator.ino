//connect input of relay to digital pin 1
int device = 1;

//set the "unit" time
int delayTime = 300;


//morse code
//short, or dot is one unit
//long, or dash is three units
//soace between parts of same letter is one unit
//space between letters is three units
//space between words is 7 units.

//morse code encodings of chars A-Z, numerals 0-9,
//as well as '.' (fullstop) ',' (comma) and '?' (query)

//s represents short or dot
//l represents long or dash

//A
// dot dash
char morseA[] = "sl";

//B
// dash dot dot dot
char morseB[] = "lsss";

//C
//dash dot dash dot
char morseC[] = "lsls";

//D
//dash dot dot
char morseD[] = "lss";

//E
//dot
char morseE[] = "s";

//F
//dot dot dash dot
char morseF[] = "ssls";

//G
//dash dash dot
char morseG[] = "lls";

//H
//dot dot dot dot
char morseH[] = "ssss";

//I
//dot dot
char morseI[] = "ss";

//J
//dot dash dash dash
char morseJ[] = "slll";

//K
//dash dot dash
char morseK[] = "lsl";

//L
//dot dash dot dot
char morseL[] = "slss";

//M
//dash dash
char morseM[] = "ll";

//N
//dash dot
char morseN[] = "ls";

//O
//dash dash dash
char morseO[] = "lll";

//P
//dot dash dash dot
char morseP[] = "slls";

//Q
//dash dash dot dash
char morseQ[] = "llsl";

//R
//dot dash dot
char morseR[] = "sls";

//S
//dot dot dot
char morseS[] = "sss";

//T
//dash
char morseT[] = "l";

//U
//dot dot dash
char morseU[] = "ssl";

//V
//dot dot dot dash
char morseV[] = "sssl";

//W
//dot dash dash
char morseW[] = "sll";

//X
//dash dot dot dash
char morseX[] = "lssl";

//Y
//dash dot dash dash
char morseY[] = "lsll";

//Z
//dash dash dot dot
char morseZ[] = "llss";

//0
//dash dash dash dash dash
char morse0[] = "lllll";

//1
//dot dash dash dash dash
char morse1[] = "sllll";

//2
//dot dot dash dash dash
char morse2[] = "sslll";

//3
//dot dot dot dash dash
char morse3[] = "sssll";

//4
//dot dto dot dot dash
char morse4[] = "ssssl";

//5
//dot dot dot dot dot
char morse5[] = "sssss";

//6
//dash dot dot dot dot
char morse6[] = "lssss";

//7
//dash dash dot dot dot
char morse7[] = "llsss";

//8
//dash dash dash dot dot
char morse8[] = "lllss";

//9
//dash dash dash dash dot
char morse9[] = "lllls";

//fullstop
//dot dash dot dash dot dash
char morseFullStop[] = "slslsl";

//comma
//dash dash dot dot dash dash
char morseComma[] = "llssll";

//query
//dot dot dash dash dot dot
char morseQuery[] = "ssllss";


void setup() {                
  // initialize the digital pins as outputs.
  pinMode(device, OUTPUT);
 
 //note that I am using a relay to turn some lights on and off
 //my relay is connected to pin 1 (device)
 //my relay is normally open
 //logic level low closes the switch
 //you may need to adjust these settings to suit your output device
}

// the loop that plays your morse sentence, repeats indefinitely
void loop() {
  
  //pass the string you encode
  //should be lowercase a-z, spaces, commas, question marks, and periods
  codeGen("morse");  
  
}

void shortSig() {
  //when a short signal is to be played
  //close switch
  digitalWrite(device, LOW);
  //wait 1 unit
  delay(delayTime);
  //reopen switch
  digitalWrite(device, HIGH); 
}

void longSig() {
  //when a long signal is to be played
  //close switch
  digitalWrite(device, LOW);
  //wait 3 units
  delay(delayTime * 3);
  //reopen switch
  digitalWrite(device, HIGH);
}

void interSpace() {
  //between parts of a letter, one unit delay
  delay(delayTime);
}

void letterGap() {
  //because of the loop behavior, 1 delay will have occured (interspace gap)
  //already for pause between letters, so delay 2 more
  delay(delayTime * 2);
}

void wordGap() {
  //because of the loop behavior, 3 delays will have occured (letter gap)
  //already for the pause between word the final word and restarting, so delay 2 more
  delay(delayTime * 4);
}

void spaceGap() {
  //when an actual space character is detected, 7 spaces will be needed
  delay(delayTime * 7); 
}

void playCode(char *playChars) {
 //loop through each character in the string of signals
 int j = 0;
 while (playChars[j] != '\0') {
   //if an s play a short, if an l play a long
   if (playChars[j]=='s') {
     shortSig();
   } else if (playChars[j]=='l') {
     longSig();
   }
   //either way, add one space after, for the interspace
   interSpace();
   j++;
 }
 //after all the tones have been played, pause between letters
 letterGap(); 
}

void codeGen(char *someChars) {
  //loop through each character in the string input
  int i = 0;
  while (someChars[i] != '\0') {
    //check to see if the character is a space, if so, play the space gap
    //if not, continue on to playing characters
    if (someChars[i] == ' ') {
      spaceGap(); 
    } else {
    //based on which character is found, play the corresponding code, defined previously  
    switch (someChars[i])
    {
       case 'a':
         playCode(morseA);
         break;
       case 'b':
         playCode(morseB);
         break;
       case 'c':
         playCode(morseC);
         break;
       case 'd':
         playCode(morseD);
         break;
       case 'e':
         playCode(morseE);
         break;
       case 'f':
         playCode(morseF);
         break;
       case 'g':
         playCode(morseG);
         break;
       case 'h':
         playCode(morseH);
         break;
       case 'i':
         playCode(morseI);
         break;
       case 'j':
         playCode(morseJ);
         break;
       case 'k':
         playCode(morseK);
         break;
       case 'l':
         playCode(morseL);
         break;
       case 'm':
         playCode(morseM);
         break;
       case 'n':
         playCode(morseN);
         break;
       case 'o':
         playCode(morseO);
         break;
       case 'p':
         playCode(morseP);
         break;
       case 'q':
         playCode(morseQ);
         break;
       case 'r':
         playCode(morseR);
         break;
       case 's':
         playCode(morseS);
         break;
       case 't':
         playCode(morseT);
         break;
       case 'u':
         playCode(morseU);
         break;
       case 'v':
         playCode(morseV);
         break;
       case 'w':
         playCode(morseW);
         break;
       case 'x':
         playCode(morseX);
         break;
       case 'y':
         playCode(morseY);
         break;
       case 'z':
         playCode(morseZ);
         break;
       case '0':
         playCode(morse0);
         break;
       case '1':
         playCode(morse1);
         break;
       case '2':
         playCode(morse2);
         break;
       case '3':
         playCode(morse3);
         break;
       case '4':
         playCode(morse4);
         break;
       case '5':
         playCode(morse5);
         break;
       case '6':
         playCode(morse6);
         break;
       case '7':
         playCode(morse7);
         break;
       case '8':
         playCode(morse8);
         break;
       case '9':
         playCode(morse9);
         break;
       case '.':
         playCode(morseFullStop);
         break;
       case ',':
         playCode(morseComma);
         break;
       case '?':
         playCode(morseQuery);
         break;  
    }} 
   i++; 
  }
  //after all letters have been played, play the word gap and prepare to go again.
  wordGap();
}

