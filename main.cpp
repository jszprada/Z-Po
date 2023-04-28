#include <iostream>
using namespace std;

void sumtable(int T[][5],const int rows,const int cols){
    int x,y;
    int result;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result=0;
            for(int k=-1;k<2;k++){
                for(int l=-1;l<2;l++){
                    x=i-k;
                    y=j-l;
                    if(x<0 || y<0 || x>=rows || y>=cols){
                        continue;
                    }
                    else if(x==i && y==j){
                        continue;
                    }
                    else{
                        result = result + T[x][y];
                    }
                }
            }
            cout<<result<<" ";
        }
    }
}
bool palindrome(string text){
    char letter;
    string textwithoutspaces="";
    int length = text.length();
    for(int i=0;i<length;i++){
        letter = text[i];
       
      if( isblank(letter)){
        continue;  
      }
      else{
          textwithoutspaces = textwithoutspaces + text[i];
      }
        
       }
      
string alfabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int len=alfabet.length();
    int dl = textwithoutspaces.length();
    int j=dl-1;
    int test1;
    int test2;
    int litera;
    bool palindrom = 1;
    for(int i=0;i<dl/2;i++){
        test1=textwithoutspaces[i];
        test2=textwithoutspaces[j];
        
        for(int k=0;k<len;k++){
            if(test1 == alfabet[k]){
               litera = k;
                break;
            }
        }
            if(litera<26){
                if(test2 == alfabet[litera] || test2 == alfabet[litera+26]){
                    
                }
                else{
                   palindrom = 0; 
                }
            }
            else if(litera>=26){
                if(test2 == alfabet[litera] || test2 == alfabet[litera-26]){
                    
                }
                else{
                   palindrom = 0; 
                }
            }
        j--;
    }
    return palindrom;
    
}

int przesuniecie(int liczba,int ile){
    int mask = 0x1;
    unsigned int dodaw = 0x80000000;
    int wynik;
    for(int i=0;i<ile;i++){
        wynik = liczba & mask;
        cout<<wynik;
        liczba = liczba >> 1;
        if(wynik != 0){
            liczba  = liczba + dodaw;
            cout<<liczba<<endl;
        }
    }
    return liczba;
}

int main(){
    int choice;
    cin>>choice;
    switch(choice){
        case 1:{
            const int rows = 4;
            const int cols = 5;
            int T[rows][cols];
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin>>T[i][j];
                }
            }
            sumtable(T,rows,cols);
            
            
            break;
        }
        case 2:{
            cin.ignore();
            string text;
            getline(cin, text);
            cout<<palindrome(text);
            //funkcja działa dla tekstów bez polskich liter
            break;
            
        }
        case 3:{
            int liczba;
            int ile;
            cin>>liczba;
            cin>>ile;
            cout<<przesuniecie(liczba,ile);
            break;
        }
        default:{
            cout<<"Wrong task number.";
            break;
        }
    }
}