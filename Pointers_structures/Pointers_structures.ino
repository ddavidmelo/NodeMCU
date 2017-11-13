struct info  {
  char name[10];
  int age;
  int number;
};

int address = 0x000;
int num = 2;
struct info *p = (struct info*) malloc(num * sizeof(struct info));

void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i < num; ++i)
   {
    switch (i) {
    case 0:
      strcpy( (*(p+i)).name, "David" );
      (*(p+i)).age=23;
      (*(p+i)).number=8456;
      address = &(*(p+i));     
      break;
    case 1:
      strcpy( (*(p+i)).name, "Raul" );
      (*(p+i)).age=93;
      (*(p+i)).number=0032;
      address = &(*(p+i));    
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
    Serial.print("Struct pointer Address: ");
    Serial.println(address);
    Serial.println("Info: ");
    Serial.println((*(p+i)).name);
    Serial.println((*(p+i)).age);
    Serial.println((*(p+i)).number);
    Serial.println("-----------------------------");
   }
   delay(500);
}
