#include<iostream>
#include<vector>
using namespace std;
vector<string>nameVec;
vector<int>priceVec;
vector<int>quantVec;

void addFun(){
	string name; int price,quant;
	cout<<"Enter item Name: ";
	cin>>name;
	cout<<"Enter Price of item: ";
	cin>>price;
	cout<<"Enter Quantity of Item: ";
	cin>>quant;
	nameVec.push_back(name);
	priceVec.push_back(price);
	quantVec.push_back(quant);
	cout<<"Item Added Successfuly!"<<endl;
}

void purchaseFun(){
 int total=0;
 vector<string>itemPur;
 vector<int>pricePur;
 vector<int>quantPur;
 vector<int>amountPur;
 
 while(true){
 	int choice;
 	cout<<"Enter 1 to continue or 0 to exit: ";
 	cin>>choice;
 	if(choice==0){
 		break;
	 }
	 string item; int quant;
	cout<<"Enter Item: ";
	cin>>item;
	cout<<"Enter Quantity: ";
	cin>>quant;
	
	bool found=false; 
	bool quantFound=false;
	
	for(int i=0;i<nameVec.size();i++){
		if(item==nameVec[i]){
			found=true;
		 if(quant<=quantVec[i]){
		 	quantFound=true;
		 	quantVec[i]-=quant;
		 	int amount= priceVec[i] * quant;
		 	total += amount;
		 	itemPur.push_back(item);
		 	pricePur.push_back(priceVec[i]);
		 	amountPur.push_back(amount);
		 	quantPur.push_back(quant);
		 	break;
		 	
		 }
		}
		
	}//for
	if(!found){
		cout<<"Item not available!"<<endl;
	}
	else if(!quantFound){
		cout<<"Out of stock"<<endl;
	}
	else{
		system("cls");
		cout<<"Item | Price | quant | Amount"<<endl;
		for(int i=0;i<itemPur.size();i++){
			cout<<itemPur[i]<<"\t"<<pricePur[i]<<"\t"<<
			quantPur[i]<<"\t"<<amountPur[i]<<endl;
		}
		cout<<"----------------------------"<<endl;
		cout<<"Total Bill:.... "<<total<<endl;
		
	}
 }//while
 cout<<" "<<endl;
}

void quantFun(){
	cout<<"Item  | Quantity"<<endl;
	for(int i=0;i<nameVec.size();i++){
		
		cout<<nameVec[i]<<"\t  "<<quantVec[i]<<endl;
	}
	cout<<" "<<endl;
}

int main(){
 while(true){
 	
	cout<<"Super Market Billing System"<<endl;
	cout<<"***************************"<<endl;
	cout<<"1.Add Item In Store."<<endl;
	cout<<"2.Purchase a Item."<<endl;
	cout<<"3.Show Remaining Quantity."<<endl;
	cout<<"4.Exit."<<endl;
	cout<<"Enter Choice: ";
	int choice;
	cin>>choice;
	
	if(choice==1){
		//add item
		system("cls");
		addFun();
	}
	else if(choice==2){
		//purchase item
		system("cls");
		purchaseFun();
	}
	else if(choice==3){
		//show quantity
		quantFun();
	}
	else if(choice==4){
		cout<<"Best of Luck"<<endl;
		break;
	}
	else{
		cout<<"Invalid Input!"<<endl;
	}
	}
	
}
