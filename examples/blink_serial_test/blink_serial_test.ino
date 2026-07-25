#define N_LED 3
#define WAIT 100

//ZephyrSerial& ser = Serial;
ZephyrSerial& ser = Serial1;

void setup() {
  ser.begin(115200);
  while (!ser)
    ;

  for (int i = 0; i < N_LED; i++)
    pinMode(i, OUTPUT);
}

int count = 0;

void loop() {
  digitalWrite((count >> 1) % N_LED, !(count & 1));

  ser.print("Hello, world! ");
  ser.println(count++);

  delay(WAIT);
}