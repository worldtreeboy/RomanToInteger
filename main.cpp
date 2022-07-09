#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;



int romanToInt(string s)
{

   int sum = 0;
   //char str[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for(int i = 0; i < s.size(); i++)
   {
      if( (s.at(i) != 'I') && (s.at(i) != 'V') && (s.at(i) != 'X') && (s.at(i) != 'L') && (s.at(i) != 'C') && (s.at(i) != 'D') && (s.at(i) != 'M'))
      {
         throw invalid_argument("string must be only consist of 'I', 'V', 'X', 'L', 'C', 'D', 'M' ");
      }
   }

   s.insert(0, " ");
    s.insert(1, " ");
   for(int i = 1; i < s.size()  ; i++)
   {
      if(s.at(i) == 'I')
      {
         sum += 1;
      }
      else if(s.at(i) == 'V')
      {
         sum += 5;
         if(s.at(i - 1) == 'I')
         {
            sum -= 2;
         }
      }
      else if(s.at(i) == 'X')
      {
         sum += 10;
         if(s.at(i - 1) == 'I')
         {
            sum -= 2;
         }
      }
      else if(s.at(i) == 'L')
      {
          sum += 50;
          if(s.at(i - 1) == 'X')
          {
              sum -= 20;
          }
      }
      else if(s.at(i) == 'C')
      {
          sum += 100;
          if(s.at(i - 1) == 'X')
          {
              sum -= 20;
          }
      }
      else if(s.at(i) == 'D')
      {
          sum += 500;
          if(s.at(i - 1) == 'C')
          {
              sum -= 200;
          }
      }
      else if(s.at(i) == 'M')
      {
          sum += 1000;
          if(s.at(i - 1) == 'D')
          {
              sum -= 1000;
          }
          if(s.at(i - 1) == 'C')
          {
              sum -= 200;
          }
      }
   }


   return sum;

}

int main()
{
   string roman;
   cout << "Please enter a roman numeral: ";
   while(cin >> roman)
   {
       cout <<  romanToInt(roman) << endl;
       cout << "Please enter a roman numeral: ";
   }




}
