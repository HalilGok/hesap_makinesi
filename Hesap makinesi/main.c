
////////  HESAP MAK�NES�  ///////

///// HAL�L G�K /////// YOUTUBE  //// TAK�P ET ////



#include <main.h>
#include <math.h>
#use fast_io(b)
#use fast_io(d)
#define use_portb_lcd TRUE

#include <lcd.c>

int16 sayi1=0;
int16  sayi=0;
int x=0;
int islem=0;
 int32 sonuc=0;

int sonuc_bul()
{ 
delay_ms(1000);
printf(lcd_putc,"\nsonucunuz=");
 switch (islem)
 {
  case 1:
    sonuc=(sayi1)+(sayi); printf(lcd_putc,"%ld",sonuc);sayi1=0;sayi=0;x=0;islem=0;sonuc=0;break;
  case 2:
    sonuc=sayi1-sayi; printf(lcd_putc,"%ld",sonuc);sayi1=0;sayi=0;x=0;islem=0;sonuc=0; break;
  case 3:
    sonuc=sayi1*sayi; printf(lcd_putc,"%ld",sonuc);sayi1=0;sayi=0;x=0;islem=0;sonuc=0; break;  
  case 4:
    sonuc=sayi1/sayi;printf(lcd_putc,"%ld",sonuc);sayi1=0;sayi=0;x=0;islem=0;sonuc=0; break;
} 
 islem=0;
}
///// HAL�L G�K /////// YOUTUBE  //// TAK�P ET ////
char tus()
{
     output_high(pin_d0);
     if(input(pin_d4)){ while(input(pin_d4)); printf(lcd_putc,"7"); x=7; sayi=sayi*10 +x;  }  // 7
     if(input(pin_d5)){ while(input(pin_d5)); printf(lcd_putc,"8");  x=8; sayi=sayi*10 +x; }   // 8
     if(input(pin_d6)){ while(input(pin_d6)); printf(lcd_putc,"9");  x=9; sayi=sayi*10 +x;}   // 9
     if(input(pin_d7)){ while(input(pin_d7)); printf(lcd_putc,"/");  
      sayi1=sayi;
      islem=4;
      sayi=0;
      
     }   // b�lme
      output_low(pin_d0);
      
      output_high(pin_d1);
     if(input(pin_d4)){ while(input(pin_d4)); printf(lcd_putc,"4"); x=4; sayi=sayi*10 +x;}  // 4
     if(input(pin_d5)){ while(input(pin_d5)); printf(lcd_putc,"5");  x=5; sayi=sayi*10 +x;}   // 5
     if(input(pin_d6)){ while(input(pin_d6)); printf(lcd_putc,"6");  x=6; sayi=sayi*10 +x;}   //6
     if(input(pin_d7)){ while(input(pin_d7)); printf(lcd_putc,"*");
     sayi1=sayi;
     islem=3;
     sayi=0;}  // �arpma
      output_low(pin_d1);
      
      output_high(pin_d2);
     if(input(pin_d4)){ while(input(pin_d4)); printf(lcd_putc,"1"); x=1; sayi=sayi*10 +x;} // 1
     if(input(pin_d5)){ while(input(pin_d5)); printf(lcd_putc,"2");  x=2; sayi=sayi*10 +x;}  //2
     if(input(pin_d6)){ while(input(pin_d6)); printf(lcd_putc,"3");  x=3; sayi=sayi*10 +x;} //3
     if(input(pin_d7)){ while(input(pin_d7)); printf(lcd_putc,"-"); 
     sayi1=sayi;
     islem=2;
     sayi=0;
      } //- ��karma
      output_low(pin_d2);
      
       output_high(pin_d3);
     if(input(pin_d4)){ while(input(pin_d4)); printf(lcd_putc,"\f ON");printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0;} 
     if(input(pin_d5)){ while(input(pin_d5)); printf(lcd_putc,"0"); x=0; sayi=sayi*10 +x;}
     if(input(pin_d6)){ while(input(pin_d6));
     sayi1;
      sonuc_bul();
      }
     if(input(pin_d7)){while(input(pin_d7)); printf(lcd_putc,"+");
     sayi1=sayi;
      islem=1;
      sayi=0;
      
    }
      output_low(pin_d3);
      
      return sayi,sayi1,islem;

}


 ///// HAL�L G�K /////// YOUTUBE  //// TAK�P ET ////
void main()
{

setup_psp(PSP_DISABLED); // PSP birimi devre d���
setup_spi(SPI_SS_DISABLED); // SPI birimi devre d���
setup_timer_1(T1_DISABLED); // T1 zamanlay�c�s� devre d���
setup_timer_2(T2_DISABLED,0,1); // T2 zamanlay�c�s� devre d���
setup_adc_ports(NO_ANALOGS); // ANALOG giri� yok
setup_adc(ADC_OFF); // ADC birimi devre d���
setup_CCP1(CCP_OFF); // CCP1 birimi devre d���
setup_CCP2(CCP_OFF); // CCP2 birimi devre d���

set_tris_b(0x00);
set_tris_d(0xF0);  // ilk d�rt port ��k�� kalan portlar giri�

lcd_init();

   while(TRUE)
   {

 tus();
     
   }

}///// HAL�L G�K /////// YOUTUBE  //// TAK�P ET ////
