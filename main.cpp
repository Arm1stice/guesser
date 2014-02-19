/*
This program will generate a random number
Then it will guess what the number is
Created by Wyatt Calandro
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
int numFound = 0;
int randomNum(int a) {
    srand(time(0));
    int random = rand() % a + 1;
    return random;
}
void clears()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
double avg(double first, double second){
    if(second == 0){
        return 0;
    }
    return first / second;
}
void statsMode(int max, int trial){
    string unit = " sec";
    unsigned int start = clock();
    while(true){
    unsigned int time = clock();
    int num = randomNum(max);
    clears();
    double total1 = (double((clock() - start)) - (numFound * 1000)) / 1000;
    double average = total1;
    if(total1 >= 86400){
        total1 = total1 / 86400;
        unit = " days";
    }else if(total1 >= 3600){
        total1 = total1 / 3600;
        unit = " hrs";
    }else if(total1 >= 60){
        total1 = total1 / 60;
        unit = " min";
    }else{
        unit = " sec";
    }
    if(numFound == trial){
        clears();
        cout << trial << " trials completed! Here are the results: " << endl;
        cout << "Total time taken: " << total1 << unit << endl;
        cout << "Average Time Per Trial: " << avg(average, numFound) << " sec" << endl;
        return;
    }
    if(max <= 999)
    {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Max: " << max << "|#: -" << "|Current: 0|Found: " << numFound << "|Time: -.-- sec" << endl;
    cout <<  "Total Time: " << total1 << unit << "|Avg: " << avg(average, numFound) << " sec" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    }else{
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Max: " << max << "|#: -" << "|Current: 0|Found: " << numFound << "|Time: -.-- sec" << endl;
    cout << "Total Time: " << total1 << unit << "|Avg: " << avg(average, numFound) << " sec" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    }
    Sleep(1000);
    for(int x = 0; x <= (num + 1); x++){
        if(x != num){
            clears();
            double seconds = (double((clock() - time)) - 1000) / 1000;
            double total = (double((clock() - start)) - (numFound * 1000)) / 1000;
            if(total >= 86400){
                total = total / 86400;
                unit = " days";
            }else if(total >= 3600){
                total = total / 3600;
                unit = " hrs";
            }else if(total >= 60){
                total = total / 60;
                unit = " min";
            }else{
                unit = " sec";
            }
            if(max <= 999){
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Max: " << max << "|#: " << num << "|Current: " << x << "|Found: " << numFound << "|Time: " << seconds << " sec" << endl;
            cout << "Total Time: " << total << unit << "|Avg: " << avg(average, numFound) << " sec" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            Sleep(50);
            }else{
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Max: " << max << "|#: " << num << "|Current: " << x << "|Found: " << numFound << "|Time: " << seconds << " sec" << endl;
            cout << "Total Time: " << total << unit << "|Avg: " << avg(average, numFound) << " sec" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            Sleep(50);
            }
        }else{
            numFound++;
            break;
        }
    }
  }
}
int main() {
    int num = 0;
    int trials = 0;
    string s;
    cout << "  ___  _  _  ____  ____  ____  ____  ____" << endl;
    cout << " / __)/ )( \\(  __)/ ___)/ ___)(  __)(  _ \\ " << endl;
    cout << "| (_ \\) \\/ ( ) _) \\___  \\___ \\ ) _)  )   /" << endl;
    cout << " \\___/\\____/(____)(____/(____/(____)(__\\_)" << endl;
    cout << "Enter the max number to be generated: ";
    cin >> num;
    cout << "Enter the number of trials you want to perform: ";
    cin >> trials;
    cout << endl;
    cout << "Guessing will start in 5 seconds..." << endl;
    cout << "While guessing is in progress, press Ctrl+C to stop the program" << endl;
    Sleep(5000);
    cout << endl;
    statsMode(num, trials);
    cout << "Press ENTER to close the program..." << endl;
    getche();
    return 0;
}
