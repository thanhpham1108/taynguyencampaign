#include "tay_nguyen_campaign.h"


////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;
void normalizeinput(int LF1[], int LF2[],int &EXP1, int &EXP2,int &T1, int &T2, int &E)
    
    
    
    // LF1 
{
    for(int i=0;i<17;i++)
    {
        if(LF1[i]>1000)
        LF1[i] = 1000;
        else if (LF1[i]<0)
        LF1[i] = 0;
        if(LF2[i]>1000)
        LF2[i] = 1000;
        else if (LF2[i]<0)
        LF2[i] = 0;

    }
    if ( EXP1 > 600) // EXP1 , EXP1 [0,600]
    EXP1 = 600;
    else if (EXP1 < 0)
    EXP1 = 0;
    if ( EXP2 > 600)
    EXP2 = 600;
    else if (EXP2 < 0)
    EXP2 = 0;
     // T1,T2 [0,3000]
     if ( T1>3000)
        T1 = 3000;
        else if (T1 < 0)
        T1 = 0;
        if ( T2>3000)
        T2 = 3000;
        else if (T2 < 0)
        T2 = 0;
    // E [0,99]
    if ( E>99)
    E=99;
    else if (E<0)
    E=0;
}
// Task 0: Read input file
bool readFile(const string &filename, int LF1[], int LF2[],  int &EXP1, int &EXP2,int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open()) // if the file is not opened
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH)) // read each line of the file
  {
    numLines++;
  }
  ifs.close(); // close the file

  if (numLines < MAX_LINES) // if the number of lines read is less than MAX_LINES
  {
    return false;
  }
// Start 

                // Line 1: Parse LF1 (17 integers)
                {
                    string line(data[0]); // chuyen array data[0] thanh 1 cai string
                 
                    for (unsigned int i = 0; i < line.size(); i++) {
                        if (line[i] == '[' || line[i] == ']')
                            line[i] = ' ';  // thay [] = space 
                    }
                    stringstream ss(line);
                    for (int i = 0; i < 17; i++) {
                        if (!(ss >> LF1[i]))
                            return false; // neu khong tach' duoc thi return false
                        if (ss.peek() == ',' || ss.peek() == ' ') // neu char tiep la ',' hoac ' ' thi bo qua de tach tiep
                            ss.ignore();
                    }
                }

                // Line 2: Parse LF2 (17 integers)
                {
                    string line(data[1]);
                    for (unsigned int i = 0; i < line.size(); i++) {
                        if (line[i] == '[' || line[i] == ']')
                            line[i] = ' ';
                    }
                    stringstream ss(line);
                    for (int i = 0; i < 17; i++) {
                        if (!(ss >> LF2[i]))
                            return false;
                        if (ss.peek() == ',' || ss.peek() == ' ')
                            ss.ignore();
                    }
                }

                // Line 3: Parse EXP1 and EXP2 (2 integers)
                {
                    string line(data[2]);
                    stringstream ss(line);
                    if (!(ss >> EXP1))
                        return false;
                    if (ss.peek() == ',' || ss.peek() == ' ')
                        ss.ignore();
                    if (!(ss >> EXP2))
                        return false;
                }

                // Line 4: Parse T1 and T2 (2 integers)
                {
                    string line(data[3]);
                    stringstream ss(line);
                    if (!(ss >> T1))
                        return false;
                    if (ss.peek() == ',' || ss.peek() == ' ')
                        ss.ignore();
                    if (!(ss >> T2))
                        return false;
                }

                // Line 5: Parse E (1 integer)
                {
                    string line(data[4]);
                    stringstream ss(line);
                    if (!(ss >> E))
                        return false;
                }

                // After extracting values, normalize them according to the rules.
                normalizeinput(LF1, LF2, EXP1, EXP2, T1, T2, E);

                return true;
                }
// Task 1
int gatherForces(int LF1[], int LF2[])
{
  int rankpoint[17]={1,2,3,4,5,7,8,9,10,12,15,18,20,30,40,50,70};
  int sumLF1=0;
  int sumLF2=0;
  
  for(int i=0;i<17;i++)
  {
    sumLF1+=(LF1[i]*rankpoint[i]);

  }
  for(int i=0;i<17;i++)
  {
    sumLF2+=(LF2[i]*rankpoint[i]);
  }

  return (sumLF1+sumLF2);




  // TODO: Implement this function
  return 0;
}
int demsonguyen(const string &s) {
  int count = 0;
  for (char c : s) {
      if (c >= '0' && c <= '9') {  
          count++;
      }
  }
  return count;
}
// Task 2
string determineRightTarget(const string &target)
{
    string BMT = "Buon Ma Thuot";
    string Duclap = "Duc Lap";
    string Daklak = "Dak Lak";
    string NR21 = "National Route 21";
    string NR14 = "National Route 14";

    int count = demsonguyen(target);
    int x = 0, y = 0, z = 0;
    int targetlength = target.length();
    int digitcount = 0;

    // Allocate a char array from target
    int n =target.length();
    char* arr = new char[n + 1];
    for (int i = 0; i < n; i++) {
        arr[i] = target[i];
    }
    arr[n] = '\0'; // Null-terminate the array
    
    string result = "INVALID";  

    if (count == 1)
    {
        // Find the only digit and assign it to x.
        for (int i = 0; i < targetlength; i++)
        {
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                x = arr[i] - '0';
            }
        }
                        if (x >= 0 && x <= 2)
                            result = "DECOY";
                        else if (x == 3)
                            result = BMT;
                        else if (x == 4)
                            result = Duclap;
                        else if (x == 5)
                            result = Daklak;
                        else if (x == 6)
                            result = NR21;
                        else if (x == 7)
                            result = NR14;
                        else if (x == 8 || x == 9)
                            result = "INVALID";
                        
        }

    else if (count == 2)
    {
        // Extract first two digits into x and y.
        for (int i = 0; i < targetlength; i++)
        {
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                if (digitcount == 0)
                    x = arr[i] - '0';
                else if (digitcount == 1)
                    y = arr[i] - '0';
                digitcount++;
                if (digitcount == 2)
                    break;
            }
        }
        int a = x + y;
        while (a >= 5)
        {
            a -= 5;
        }
        int b = a + 3;
        if (b >= 0 && b <= 2)
            result = "DECOY";
        else if (b == 3)
            result = BMT;
        else if (b == 4)
            result = Duclap;
        else if (b == 5)
            result = Daklak;
        else if (b == 6)
            result = NR21;
        else if (b == 7)
            result = NR14;
        else if (b == 8 || b == 9)
            result = "INVALID";
    }
    else if (count == 3)
    {
        // Extract first three digits into x, y, and z.
        for (int i = 0; i < targetlength; i++)
        {
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                if (digitcount == 0)
                    x = arr[i] - '0';
                else if (digitcount == 1)
                    y = arr[i] - '0';
                else if (digitcount == 2)
                    z = arr[i] - '0';
                digitcount++;
                if (digitcount == 3)
                    break;
            }
        }
        int a = x + y + z;
        while (a >= 5)
        {
            a -= 5;
        }
        int b = a + 3;
        if (b >= 0 && b <= 2)
            result = "DECOY";
        else if (b == 3)
            result = BMT;
        else if (b == 4)
            result = Duclap;
        else if (b == 5)
            result = Daklak;
        else if (b == 6)
            result = NR21;
        else if (b == 7)
            result = NR14;
        else if (b == 8 || b == 9)
            result = "INVALID";
    
    }

    else // count == 0 or count >= 4
    {
        result = "INVALID";
    }
    
    // Clean up dynamic memory 
    delete[] arr;

    return result;
}

string daonguocchuoi(string s)
{
    string result = "";
    for(int i= s.length()-1;i>=0;i--)
    {
        result= result + s[i];
    }
    return result;
}
int mod26(int a)
{
  while(a>=26)
  {
    a=a-26;
  }
  return a;
}
string toLower(string s) {
    string result = s; // Copy the input string
    
    for (unsigned int i = 0; i < result.length(); i++) {
        // If character is an uppercase letter, convert to lowercase
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + ('a' - 'A');
        }
    }
    return result;
}
string decodeTarget(const string &message, int EXP1, int EXP2)
{
  string BMT = "Buon Ma Thuot";
    string Duclap = "Duc Lap";
    string Daklak = "Dak Lak";
    string NR21 = "National Route 21";
    string NR14 = "National Route 14";
    string result="INVALID";
    string lBMT = toLower(BMT);
    string lDuclap = toLower(Duclap);
    string lDaklak = toLower(Daklak);
    string lNR21 = toLower(NR21);
    string lNR14 = toLower(NR14);
if(EXP1 >= 300 && EXP2 >= 300)
 {
  int shift = EXP1 + EXP2;
  shift = mod26(shift);
  int len = message.length();
  char *arr = new char[len + 1];

  // Copy characters from message to arr
  for (int i = 0; i < len; i++) {
      arr[i] = message[i];
  }
  arr[len] = '\0'; // Null-terminate the array

  // Shift characters in arr

  for (int i=0; i<len;i++){ // check if there is a character  in the alphabet
    char c = arr[i];
    if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              (c == ' '))) {
            result = "INVALID";
            break;}
              }



    for (int i =0 ; i < len ; i++){
      if(arr[i] >='a' && arr[i] <= 'z' )
      {arr[i] = mod26(arr[i] - 'a' + shift)+'a';}
      else if(arr[i] >='A' && arr[i] <= 'Z' ){
        arr[i] = mod26(arr[i] - 'A' + shift) + 'A';

      }
    }
   // check if the message is valid or same to BMT, Duclap, Daklak, NR21, NR14
        string shiftedMessage(arr);

        // Check if the message is valid or same as BMT, Duclap, Daklak, NR21, NR14
        if (shiftedMessage == BMT) {
            result = BMT;
        } else if (shiftedMessage== Duclap) {
            result = Duclap;
        } else if (shiftedMessage == Daklak) {
            result = Daklak;
        } else if (shiftedMessage == NR21) {
            result = NR21;
        } else if (shiftedMessage == NR14) {
            result = NR14;
        } else {
            result = "INVALID";
        }

  // Clean up dynamic memory
  delete[] arr;
  
  
  
}


 
                    
 
 
                    else if (EXP1 <300 || EXP2 <300){
                      result = daonguocchuoi(message); 
                      string lowerresult= toLower(result);
                      // check if result == BMT, Duclap, Daklak, NR21, NR14
                      if (lowerresult == lBMT) {
                          result = BMT;
                      } else if (lowerresult == lDuclap) {
                          result = Duclap;
                      } else if (lowerresult == lDaklak) {
                          result = Daklak;
                      } else if (lowerresult == lNR21) {
                          result = NR21;
                      } else if (lowerresult == lNR14) {
                          result = NR14;
                      } else {
                          result = "INVALID";
                      }
                      
                    } 
                      
  // TODO: Implement this function
  return result;
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{

  int maxvalue = 3000;
  int minvalue = 0;
  if(E==0) // truong hop E==0
  {


    long double deltaT1=((LF1/(LF1+LF2))*  (T1+T2) )  * (1+  (EXP1-EXP2)/100);
    long double deltaT2 = ( T1 + T2  ) - deltaT1;
    T1= T1+ (deltaT1);
    T2 = T2 + (deltaT2);





  }
  else if(E>=1&&E<=9) // truong hop 1
  {
    T1 = (T1 - (E * (1.0/100)) * T1);
    T2 = (T2 - (E * (0.5/100)) * T2);
  }
  else if(E>=10 && E<=29)// truong hop 2
  {
     T1= T1+E*50;
     T2= T2+E*50;
  }
  else if ( E>=30 && E<=59 )
  {
    T1 = (T1 + T1 * (E * 0.5/100));
  }
  else if (E >= 60 && E <= 99)
  {
    T1= T1;
    T2=T2;
  }
  if (T1 > maxvalue)
  {
    T1 = maxvalue;
  }
  if (T2 > maxvalue)
  {
    T2 = maxvalue;
  }
  if (T1 < minvalue)
  {
    T1 = minvalue;
  }
  if (T2 < minvalue)
  {
    T2 = minvalue;
  }
  
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
    
    long double sum = (LF1 + LF2) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;


    for (int i = 0; i < 10; i += 2) {   // hang` chan~
        for (int j = 0; j < 10; j++) {    
            
            sum -= ((battleField[i][j] * 2) / 3.0);
        }
    }

    
    for (int i = 1; i < 10; i += 2) {  // hang~ le~ 
        for (int j = 0; j < 10; j++) {    
            
            sum -= ((battleField[i][j] * 3) / 2.0);
        }
    }
    
 
    // Return the final calculated strength.
    return ceil(sum);
}


// Function to perform selection sort on an array
void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
      
      int min_position = i;
      
      
      for (int j = i + 1; j < n; j++) {
          if (a[j] < a[min_position]) {
              min_position = j;
          }
      }
      
     
      if (min_position != i) {
          swap(a[i], a[min_position]);
      }
  }
}
// Task 5
int resupply(int shortfall, int supply[5][5])
{
  int values[25];
  int index = 0;
  
  // 
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          values[index++] = supply[i][j];
      }
  }
  selectionSort(values, 25); 
  
  int minSum = 0; // Khởi tạo minSum; 
  
  // Duyệt qua tất cả các tổ hợp 5 phần tử (từ 25 phần tử) dùng 5 vòng lặp lồng nhau
  for (int i = 0; i < 25 - 4; i++) {
      for (int j = i + 1; j < 25 - 3; j++) {
          for (int k = j + 1; k < 25 - 2; k++) {
              for (int l = k + 1; l < 25 - 1; l++) {
                  for (int m = l + 1; m < 25; m++) {
                      int sum = values[i] + values[j] + values[k] + values[l] + values[m];
                      
                      // Nếu tổng ≥ shortfall và nhỏ hơn minSum hiện có (hoặc minSum vẫn = 0) thì cập nhật minSum
                      if (sum >= shortfall) {
                          if (minSum == 0 || sum < minSum) {
                              minSum = sum;
                          }
                      }
                  }
              }
          }
      }
  }

  // TODO: Implement this function
   
  return minSum;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
