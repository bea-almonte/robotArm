
unsigned char serial_buf[7]={0,0,0,0,0,0,0};

// Requirements
// (0,0) -> (50,0) -> (50,50) -> (0,50) -> (0,0)
// wait 5 secs
// Repeat
const int8_t RobotAdd = 1;

void Move(int RobotAddress, int xPos, int yPos, int Speed);
void Weld(int RobotAddress);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}


void loop() {
  // put your main code here, to run repeatedly:
// (0,0) -> (50,0) -> (50,50) -> (0,50) -> (0,0)
Move(RobotAdd, 0,0,200);
Weld(RobotAdd);
Move(RobotAdd, 50,0,200);
Weld(RobotAdd);
Move(RobotAdd, 50,50,200);
Weld(RobotAdd);
Move(RobotAdd, 0,50,200);
Weld(RobotAdd);
Move(RobotAdd, 0,0,200);
delay(5000); // wait 5 secs
}

void Move(int RobotAddress, int xPos, int yPos, int Speed) {
  serial_buf[0]=2;
  serial_buf[1]=RobotAddress; //address
  serial_buf[2]=12; // Move
  serial_buf[3]=xPos;  // xPos
  serial_buf[4]=yPos; // yPos
  serial_buf[5]=Speed; // Speed
  serial_buf[6]=serial_buf[1]+serial_buf[2]+serial_buf[3]+serial_buf[4]+serial_buf[5]; // Checksum
  Serial.write(serial_buf,7);
  delay(1000); 
}

void Weld(int RobotAddress) {
  serial_buf[0]=2;
  serial_buf[1]=RobotAddress; //address
  serial_buf[2]=13; // Weld
  serial_buf[3]=0;  // xPos
  serial_buf[4]=0; // yPos
  serial_buf[5]=0; // Speed
  serial_buf[6]=serial_buf[1]+serial_buf[2]+serial_buf[3]+serial_buf[4]+serial_buf[5]; // Checksum
  Serial.write(serial_buf,7);
  delay(1000); 
}
