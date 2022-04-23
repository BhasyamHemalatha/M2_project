void SevenSegment(uint8_t count,uint8_t dp, uint8_t dec_hex)
{
   if(count <dec_hex)
   {
      switch (count)
      {
         case 0:
         PORT_7_SEGMENT=0b10001000;
         break;

         case 1:
         PORT_7_SEGMENT=0b10111110;
         break;

         case 2:
         PORT_7_SEGMENT=0b00011001;
         break;

         case 3:
         PORT_7_SEGMENT=0b00011100;
         break;

         case 4:
         PORT_7_SEGMENT=0b00101110;
         break;

         case 5:
         PORT_7_SEGMENT=0b01001100;
         break;

         case 6:
         PORT_7_SEGMENT=0b01001000;
         break;

         case 7:
         PORT_7_SEGMENT=0b10111100;
         break;

         case 8:
         PORT_7_SEGMENT=0b00001000;
         break;

         case 9:
         PORT_7_SEGMENT=0b00001100;
         break;
		 //hex only 
		 case 10:
         PORT_7_SEGMENT=0b00101000;  //A
         break;
		 case 11:
         PORT_7_SEGMENT=0b01001010;  //b
         break;
		 case 12:
         PORT_7_SEGMENT=0b11001001;  //C
         break;
		 case 13:
         PORT_7_SEGMENT=0b00011010;  //d
         break;
		 case 14:
         PORT_7_SEGMENT=0b01001001;  //E
         break;
		 case 15:
         PORT_7_SEGMENT=0b01101001;  //F
         break;
      }
      if(dp)
      {
         //if decimal point should be displayed make DP bit Low
         PORT_7_SEGMENT&=0b11110111;
      }
   }
   else
   {

      PORT_7_SEGMENT=0b11011111;
   }
}

int main()
{
   //Setup
   DDR_7_SEGMENT=0xFF;    //All output
   PORT_7_SEGMENT=0xFF;   //All segments off

   uint8_t count=0;
   uint8_t dec_hex=16; //change to 10 for decimal

   while(1)  //loop forever
   {
      SevenSegment(count,0, dec_hex);

      count++;
      if(count==dec_hex)  
      {
         count=0;
      }
      _delay_ms(1000);
   }
}