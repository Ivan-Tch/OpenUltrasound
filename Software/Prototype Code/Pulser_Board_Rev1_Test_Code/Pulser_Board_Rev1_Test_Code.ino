//Ultrasound Pulser Test

//Define Pins

//Channel A
/* Channel A pins are on Port A of Arduino Mega 

   Port A6 - CLAMPA (GND) 
   Port A5 - NEG2A (LOW - VPP1-VNN1 - HIGH-VPP2-VNN2)
   Port A4 - POS2A (HIGH- VPP1-VNN1 - LOW -VPP2-VNN2)
   Port A3 - NEG1A 
   Port A2 - POS1A 
   Port A1 - SEL (GND)
   Port A0 - EN (VLL) 
*/


//Channel B
/* Channel B pins are on Port C of Arduino Mega 
  Port C4 - POS1B
  Port C3 - NEG1B
  Port C2 - POS2B
  Port C1 - NEG2B
  Port C0 - CLAMPB (GND)
*/ 

String readString;

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRC = 0xFF;
  Serial.begin(9600); 
}

void loop() {

  //Set Port A and C low -  idle mode
  PORTA = 0x00;
  PORTC = 0x00;  
  
  
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }  

  readString.trim();
  
  if (readString.length() >0) {
    
    //------------------ 4.7 kHz --------------------------------------//
    if (readString == "PA47")
    {
      Serial.println("Pulse Channel A at 4.7 kHz ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      while(1)
      {
      PORTA = 0b00010101; // Pulse High Vpp1
      delayMicroseconds(106);
      PORTA = 0b00011001; // Pulse Low Vnn1
      delayMicroseconds(106);
      PORTA = 0b00010101; // Pulse High Vpp1
      delayMicroseconds(106);
      PORTA = 0b00011001; // Pulse Low Vnn1
      delayMicroseconds(106);
      PORTA = 0b00010001; // Return to zero 
      delayMicroseconds(106);
      }
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA47T")
    {
      Serial.println("Pulse Channel A at 4.7 kHz for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
     
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(106);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(106);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(106);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(106);
      
      PORTA = 0b00010001; // No Pulse
      PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
      
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(106);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(106);
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(106);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(106);
      
      PORTA = 0b00010001; // Return to zero 
      delayMicroseconds(106);
      
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB47")
    {
      Serial.println("Pulse Channel B at 4.7 kHz for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(106);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(106);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(106);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(106);
      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(106);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB47T")
    {
      Serial.println("Pulse Channel B at 4.7 kHz for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(106);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(106);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(106);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(106);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(106);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(106);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(106);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(106);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(106);
        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }
    //----------------------------------------------------------------//

    
    //---------------------  27 kHz ----------------------------------// 
    if (readString == "PA27")
    {
      Serial.println("Pulse Channel A at 27 kHz for two cycles ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
    
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(18);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(18);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(18);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(18);

      PORTA = 0b00010001; // Return to zero 
      delayMicroseconds(18);
      
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA27T")
    {
      Serial.println("Pulse Channel A at 27 kHz for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
     
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(18);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(18);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(18);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(18);
      
      PORTA = 0b00010001; // No Pulse
      PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
      
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(18);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(18);
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(18);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(18);

      PORTA = 0b00010001; // Return to zero 
      delayMicroseconds(18);

      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB27")
    {
      Serial.println("Pulse Channel B at 27 kHz for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(18);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(18);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(18); 
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(18);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(18);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB27T")
    {
      Serial.println("Pulse Channel B at 27 kHz for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(18);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(18);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(18);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(18);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(18);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(18);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(18);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(18);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(18);
        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }


    //---------------------  25 kHz ----------------------------------// 
    if (readString == "PA25")
    {
      Serial.println("Pulse Channel A at 25 kHz for two cycles ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      int i = 0;
      while(1)
      {
        
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(20);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(20);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(20);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(20);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(20);
      
      }
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA25T")
    {
      Serial.println("Pulse Channel A at 25 kHz for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A

      while(1)
      {
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(20);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(20);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(20);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(20);
      
      PORTA = 0b00010001; // No Pulse
      PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
      
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(20);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(20);
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(20);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(20);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(20);
      
      delay(100);
      
      }
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB25")
    {
      Serial.println("Pulse Channel B for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
   
       
      
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(20);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(20);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(20); 
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(20);
      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(20);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB25T")
    {
      Serial.println("Pulse Channel B for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(20);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(20);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(20);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(20);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(20);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(20);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(20);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(20);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(20);
        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

 //---------------------  12 kHz ----------------------------------// 
    if (readString == "PA12")
    {
      Serial.println("Pulse Channel A for two cycles ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      int i = 0;
      while(1)
      {
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(41);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(41);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(41);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(41);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(41);
      }
      
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA12T")
    {
      Serial.println("Pulse Channel A for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
     
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(41);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(41);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(41);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(41);
      
      PORTA = 0b00010001; // No Pulse
      PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
      
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(41);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(41);
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(41);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(41);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(41);

      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB12")
    {
      Serial.println("Pulse Channel B for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(41);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(41);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(41); 
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(41);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(41);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB12T")
    {
      Serial.println("Pulse Channel B for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(41);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(41);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(41);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(41);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(41);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(41);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(41);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(41);

      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(41);
        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }


    //---------------------  8.8 kHz ----------------------------------// 
    if (readString == "PA88")
    {
      Serial.println("Pulse Channel A for two cycles ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      int i = 0;
      while(1)
      {
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(58);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(58);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(58);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(58);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(58);
   
      
      }
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA88T")
    {
      Serial.println("Pulse Channel A for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      while(1)
      {
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(58);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(58);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(58);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(58);
      
      PORTA = 0b00010001; // No Pulse
      PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
      
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(58);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(58);
      PORTA = 0b00100101; // Pulse High Vpp2 
      delayMicroseconds(58);
      PORTA = 0b00101001; // Pulse Low Vnn2 
      delayMicroseconds(58);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(58);

      delay(10);
      
      }
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB88")
    {
      Serial.println("Pulse Channel B for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(57);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(57);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(57); 
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(57);
      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(57);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB88T")
    {
      Serial.println("Pulse Channel B for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(57);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(57);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(57);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(57);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(57);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(57);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(57);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(57);
      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(57);
        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }
    
   //---------------------  11.5 kHz ----------------------------------// 
    if (readString == "PA115")
    {
      Serial.println("Pulse Channel A for two cycles ");
      PORTA = 0b00100001; //1 - Enable - High POS2A
      int i = 0;
      
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(43);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(43);
      PORTA = 0b00010101; //2 - Pulse High Vpp1
      delayMicroseconds(43);
      PORTA = 0b00011001; //3 - Pulse Low Vnn1
      delayMicroseconds(43);
      PORTA = 0b00010001; // Return to zero
      delayMicroseconds(43);
      
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }
    
    if (readString == "PA115T")
    {
      Serial.println("Pulse Channel A for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A

      while(1)
      {
        PORTA = 0b00010101; //2 - Pulse High Vpp1
        delayMicroseconds(43);
        PORTA = 0b00011001; //3 - Pulse Low Vnn1
        delayMicroseconds(43);
        PORTA = 0b00010101; //2 - Pulse High Vpp1
        delayMicroseconds(43);
        PORTA = 0b00011001; //3 - Pulse Low Vnn1
        delayMicroseconds(43);
        PORTA = 0b00010001; // Return to zero
        
        PORTA = 0b00010001; // No Pulse
        PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
        
        PORTA = 0b00100101; // Pulse High Vpp2 
        delayMicroseconds(43);
        PORTA 
        = 0b00101001; // Pulse Low Vnn2 
        delayMicroseconds(43);
        PORTA = 0b00100101; // Pulse High Vpp2 
        delayMicroseconds(43);
        PORTA = 0b00101001; // Pulse Low Vnn2 
        delayMicroseconds(43);

        PORTA = 0b00010001; // Return to zero
        delayMicroseconds(43);
        
        delay(100);
      }
      
      PORTA = 0b00100001; //4  - No Pulsing 
      PORTA = 0b00000000; //10 - Disable Channel A
      
      Serial.println("End");
      
    }

    if (readString == "PB115")
    {
      Serial.println("Pulse Channel B for two cycles ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(43);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(43);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(43); 
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(43);
      PORTC = 0b00000100; // Return to Zero 
      delayMicroseconds(43);
        
      PORTC = 0b00000100; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }

    if (readString == "PB115T")
    {
      Serial.println("Pulse Channel B for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
     
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(43);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(43);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(43);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(43);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(43);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(43);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(43);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(43);

      PORTC = 0b00000100; // Return to Zero 
      delayMicroseconds(43);

        
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
      
    }
  //------------------------- 150 kHz -----------------------------------------//
  if (readString == "PA150T")
    {
      Serial.println("Pulse Channel A for two cycles high and two cycles at lower voltage ");
      PORTA = 0b00100001; //1 - Enable - High POS2A

      while(1)
      {
        PORTA = 0b00010101; //2 - Pulse High Vpp1
        delayMicroseconds(3);
        PORTA = 0b00011001; //3 - Pulse Low Vnn1
        delayMicroseconds(3);
        PORTA = 0b00010101; //2 - Pulse High Vpp1
        delayMicroseconds(3);
        PORTA = 0b00011001; //3 - Pulse Low Vnn1
        delayMicroseconds(3);
        
        PORTA = 0b00010001; // No Pulse
        PORTA = 0b00100001; // Switch off POS2A Switch on NEG2A
        
        PORTA = 0b00100101; // Pulse High Vpp2 
        delayMicroseconds(3);
        PORTA = 0b00101001; // Pulse Low Vnn2 
        delayMicroseconds(3);
        PORTA = 0b00100101; // Pulse High Vpp2 
        delayMicroseconds(3);
        PORTA = 0b00101001; // Pulse Low Vnn2 
        delayMicroseconds(3);

        PORTA = 0b00010001; // Return to zero
        delayMicroseconds(3);
        
        delay(100);
      }
    }
    
    if (readString == "PB150T")
    {
      Serial.println("Pulse Channel B for two cycles high and two cycles low ");
      PORTA = 0x01; // Set the Enable Pin High, and Select pin LOW
      PORTC = 0b00000100; //1 - Enable - High POS2A
      while(1) 
      {
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(3);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(3);
      PORTC = 0b00010100; //2 - Pulse High 
      delayMicroseconds(3);
      PORTC = 0b00001100; //3 - Pulse Low
      delayMicroseconds(3);
      
      PORTC = 0b00000100; // No Pulse 
      PORTC = 0b00000010; // Switch Off POS2B Switch On NEG2B
      
      PORTC = 0b00010010; // Pulse High Vpp2 
      delayMicroseconds(3);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(3);
      PORTC = 0b00010010; // Pulse High Vpp2
      delayMicroseconds(3);
      PORTC = 0b00001010; // Pulse Low Vnn2
      delayMicroseconds(3);
      PORTC = 0b00000100; // Return to Zero
      delayMicroseconds(3);
    
      delay(100); // Generate a pulse 10 times a second
      
      }
      PORTC = 0b00000010; //4  - No Pulsing 
      PORTC = 0b00000000; //10 - Disable Channel B
      PORTA = 0x00;
      
      Serial.println("End");
    }
  readString="";
  }
}
