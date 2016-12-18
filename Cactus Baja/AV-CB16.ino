// include the library
#include <Wire.h>
#define REFRESH_TIME 500
#define REFRESH_TIME2 250
#define PIN 2
//pino preto = sinal, vermelho = vcc, azul = gnd
float vel;
int vel2;
long ult_volta;
long ult_volta2;
long cont;
int leitura;
int pulso;
long cont2;
long cont3;
long taux = 0;
long tempo = 0;
long milisegundos = 0;
int segundos = 0;
int decimas = 0;
int cent = 0;
int mil = 0;
unsigned ultimo_tempo = 0;
#include <LiquidCrystal.h>

// initialize the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// the 8 arrays that form each segment of the custom numbers
byte bar1[8] =
{
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100
};
byte bar2[8] =
{
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111
};
byte bar3[8] =
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte bar4[8] =
{
  B11110,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};
byte bar5[8] =
{
  B01111,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00111
};
byte bar6[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte bar7[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01111
};
byte bar8[8] =
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup()
{
  // assignes each segment a write number
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  lcd.createChar(6, bar6);
  lcd.createChar(7, bar7);
  lcd.createChar(8, bar8);

  // sets the LCD's rows and colums:
  pinMode(PIN, INPUT);
  Serial.begin(9600);
  lcd.begin (20, 4);
  lcd.setCursor(5, 0);
  lcd.print("-TESTE AV-");
  lcd.setCursor(0, 2);
  lcd.print("100m: ");
  lcd.setCursor(1, 1);
  lcd.print("30m:");
  lcd.setCursor(5, 1);
  lcd.print("00:000");
  attachInterrupt(0, calc_vel, CHANGE);
  ult_volta = millis();
  ult_volta2 = millis();
  cont = 0;
  cont2 = 0;
  cont3 = 0;
  vel = 0;
  vel2 = 0;
  segundos = 0;
  decimas = 0;
  cent = 0;

}
void calc_vel() {
  cont++;
  cont2++;
  cont3++;
}

void custom0(int col)
{ // uses segments to build the number 0
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom1(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom4(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 2);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 2);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom9(int col)
{
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 2);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void printNumber(int value, int col) {
  if (value == 0) {
    custom0(col);
  } if (value == 1) {
    custom1(col);
  } if (value == 2) {
    custom2(col);
  } if (value == 3) {
    custom3(col);
  } if (value == 4) {
    custom4(col);
  } if (value == 5) {
    custom5(col);
  } if (value == 6) {
    custom6(col);
  } if (value == 7) {
    custom7(col);
  } if (value == 8) {
    custom8(col);
  } if (value == 9) {
    custom9(col);
  }
}

void printRPM(int rpm) {
  int c , d, u, number;
  number = vel2;

  if (number > 99) {
    c = (number - (number % 100)) / 100;
    number = number % 100;
  } else {
    c = 0;
  }

  if (number > 9) {
    d = (number - (number % 10)) / 10;
    number = number % 10;
  } else {
    d = 0;
  }

  u = number;



  printNumber(d, 14);
  printNumber(u, 17);


}

void loop()
{

 // pulso = cont / 2;
 // lcd.setCursor(0, 0);
 // lcd.print(pulso);
  // Verifica se o objeto foi detectado pelo sensor
  if (cont <= 1) {
    // while (pulso <= 1) {
    taux = millis();
    // }
  }
  if ((cont > 2) && (cont <= 409)) //409
  {
    milisegundos = (millis() - taux);

    if (milisegundos < 10) {
      mil = milisegundos;
    } else if (milisegundos >= 10) {
      mil = milisegundos % 10;
    }

    if (milisegundos % 10 == 0) {
      cent++;
      if (cent == 10) {
        cent = 0;
        decimas++;
      }
      if (decimas == 10) {
        decimas = 0;
        segundos++;
      }

      lcd.setCursor(5, 1);
      if (segundos < 10) {
        //Serial.print("0");
        lcd.print("0");
      }
      lcd.print(segundos);
      lcd.print(":");
      //Serial.print(segundos);
      //Serial.print(":");

      lcd.setCursor(8, 1);
      lcd.print(decimas);
      //Serial.print(decimas);
      lcd.setCursor(9, 1);
      lcd.print(cent);
      //Serial.print(cent);
      lcd.setCursor(10, 1);
      lcd.print(mil);
    }
  }
  if (millis() - ult_volta2 >= REFRESH_TIME) {
    vel2 = (3600 * 0.073333 * cont3) / (millis() - ult_volta2);
    //alterar o segundo valor pela circunferencia da coroa em metros
    cont3 = 0;
    ult_volta2 = millis();
    //resto = vel%10;
    //final = (vel-resto);
    //Serial.print(vel);
    //Serial.println(" Km/h");
    printRPM(vel2);
    //delay(700);


  }

  if ((cont > 1) && (cont <= 1363)) {
    if (millis() - ult_volta >= REFRESH_TIME2) {
      vel = (3600 * 0.073333 * cont2) / (millis() - ult_volta);
      //alterar o segundo valor pela circunferencia da coroa em metros
      cont2 = 0;
      ult_volta = millis();
      //resto = vel%10;
      //final = (vel-resto);
      //Serial.print(vel);
      //Serial.println(" Km/h");
      //delay(700);1363
    }
  }

  else {
    lcd.setCursor(5, 2);
    lcd.print(vel);
  }
}


