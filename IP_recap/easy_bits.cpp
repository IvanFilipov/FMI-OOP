
//условие : да изпринтим всички битове на едно unsigned int число

#include<iostream>

int main(){


  unsigned int num = 1234;

  unsigned int mask = 1;


  for(int i = 31 ; i >= 0 ; i--){

    mask = 1 << i ;

    std:: cout << ((num & mask) ? 1 : 0 );


  }

  return 0 ;
}
