#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void saveMedicines(int ID[], string NAME[], float PRICE[], int QUANTITY[], int count)
{
    ofstream file("medicines.txt");
    for (int i = 0; i < count; i++)
{
   file << ID[i] << " "
     << std::quoted(NAME[i]) << " "
     << PRICE[i] << " "
     << QUANTITY[i] << endl; 
}
   file.close();
}
void loadMedicines(int ID[], string NAME[], float PRICE[], int QUANTITY[], int &count)
{
    ifstream file("medicines.txt");
   count = 0;
   while (count < 100 && file >> ID[count] >> std::quoted(NAME[count]) >> PRICE[count] >> QUANTITY[count])
{
    count++;
}
    file.close();
}
int main() {
    int choice;
   
    int count=0;
    int ID[100];
    string NAME[100];
    float PRICE[100];
    int QUANTITY[100];
       loadMedicines(ID, NAME, PRICE, QUANTITY, count);
    cout << "===== PHARMACY MANAGEMENT SYSTEM =====" << endl;
    cout << "1. Add Medicine" << endl;
    cout << "2. Display Medicines" << endl;
    cout << "3. Search Medicine" << endl;
    cout << "4. Update Medicine" << endl;
    cout << "5. Delete Medicine" << endl;
    cout << "6. Create Invoice" << endl;
    cout << "7. Exit" << endl;
      do{
    cout << "Choose an option: ";
    cin >> choice;
       switch(choice){
      case 1: {
    cout << "Add Medicine" << endl;
    if (count >= 100) {
        cout << "Medicine storage is full!" << endl;
        break;
    }
    cout << "Enter Medicine ID: ";
    cin >> ID[count];
    bool duplicate = false;
    for (int i = 0; i < count; i++) {
        if (ID[count] == ID[i]) {
            duplicate = true;
            break;
        }
            }
    if (duplicate == true) {
        cout << "This ID already exists!" << endl;
       }
    else {
        cout << "Enter Medicine Name: ";
        getline(cin >> ws, NAME[count]);
        cout << "Enter Medicine Price: ";
        cin >> PRICE[count];
        cout << "Enter Medicine Quantity: ";
        cin >> QUANTITY[count];
        count++;
        saveMedicines(ID, NAME, PRICE, QUANTITY, count);
      cout << "Medicine added successfully!" << endl;
    }
    break;
}
       case 2:cout<<"Display Medicines"<<endl;
       if(count==0){
       cout<<"No Medicines Available"<<endl;
       }
       else{
       for(int i=0 ; i<count ; i++){
       cout<<"medicine ID is:"<<ID[i]<<endl;
       cout<<"medicine name is:"<<NAME[i]<<endl;
       cout<<"medicine price is:"<<PRICE[i]<<"$"<<endl;
       cout<<"medicine quantity is:"<<QUANTITY[i]<<"units"<<endl;}
       }
       break;
        
       case 3:{
       bool found=false;
       cout<<"Search Medicine"<<endl;
       int SEARCH_ID;
       cout<<"enter ID of medicine"<<endl;
       cin>>SEARCH_ID;
       for(int i=0 ; i<count ; i++ ){ 
       if(SEARCH_ID==ID[i]){
       cout << "Medicine Found!" << endl;
       cout << "Name: " << NAME[i] << endl;
       cout << "Price: " << PRICE[i] << endl;
       cout << "Quantity: " << QUANTITY[i] << endl; 
        found=true;
        break;
            }
         }
         
          if( found==false )
       cout<<"medicine not found!"<<endl;
       break;
       }
       case 4:{
       cout<<"Update Medicine"<<endl;
        bool found=false;
       int UPDATE_ID;
       cout<<"enter medicine ID"<<endl;
       cin>>UPDATE_ID;
       for(int i=0 ; i<count ; i++){
       if(UPDATE_ID==ID[i]){
        found=true; 
        cout<<"enter new medicine name"<<endl;
        getline(cin >> ws, NAME[i]);
        cout<<"enter new medicine price "<<endl;
        cin>>PRICE[i];
        cout<<"enter new medicine quantity"<<endl;
        cin>>QUANTITY[i];
        cout << "Medicine updated successfully!" << endl;
           saveMedicines(ID, NAME, PRICE, QUANTITY, count);
        break; }
           } 
       
       if(found==false)
       cout<<"medicine not found!"<<endl;
       break;
       }
       case 5:{
       int DELETE_ID;
       bool found=false;
       cout<<"Delete Medicine"<<endl;
       cout<<"enter medicine ID that you want delete it:"<<endl;
       cin>>DELETE_ID;
       for(int i=0 ; i<count ; i++){
       if(DELETE_ID==ID[i]){
       found=true;
       for(int j=i ; j<count-1 ; j++){
       ID[j]=ID[j + 1];
       NAME[j] = NAME[j + 1];
       PRICE[j] = PRICE[j + 1];
       QUANTITY[j] = QUANTITY[j + 1];}
       
          count--; 
           saveMedicines(ID, NAME, PRICE, QUANTITY, count);
       cout << "Medicine deleted successfully!" << endl;
       break;
          } 
          }
          if(found == false)
    cout << "Medicine not found!" << endl;
       break;
         }
       case 6:{
       int INVOICE_ID;
        bool found=false;
        float total;
       cout<<"Create Invoice"<<endl;
       cout<<"enter medicine ID "<<endl;
       cin>>INVOICE_ID;
       for(int i=0 ; i<count ; i++){
       if(INVOICE_ID==ID[i]){
       found=true;
       int buyQuantity;
       cout<<"Enter the quantity you want to buy: ";
       cin>>buyQuantity;
       if(buyQuantity<=QUANTITY[i]&&buyQuantity >0){
       total=buyQuantity*PRICE[i];
         QUANTITY[i]-=buyQuantity;
         cout << "Medicine Name: " << NAME[i] << endl;
         cout << "Unit Price: " << PRICE[i] <<"$"<<endl;
         cout << "Quantity: " << buyQuantity << endl;
         cout << "Total: " << total <<"$"<< endl;
             saveMedicines(ID, NAME, PRICE, QUANTITY, count);
                    }
          else {
          cout << "Insufficient stock!" << endl;          
        }
        break;
        }
       }if (found == false) {
    cout << "Medicine not found!" << endl;
       }
       break;
       }
       case 7:cout<<"Thank you for using the Pharmacy Management System!"<<endl;
       break;
       default:cout<<"Invalid choice! Please try again."<<endl;
       break;
       }
    }  while(choice!=7);
    
    return 0;
}