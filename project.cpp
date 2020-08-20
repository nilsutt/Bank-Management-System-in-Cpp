#include<iostream>
using namespace std;

class ATM{
	private:
		string name;
		int pin;
	
	public:
		void setName(string n){
			name=n;
		}
		void setPin(int P){ 
			pin=P;          
		}
		string getName(){ 
		}
		int getPin(){ 
			return pin;       
		}
	
};

class SavingAccount: public ATM{
	
	private:
		double Deposit;
		double Balance;
		
	public:
	    void setDeposit(double D){ 
	    	Deposit=D;
		}	
	    void setBalance(double B){
	    	Balance=B;
	    	
		}
		double getDeposit(){
			return Deposit;
		}
		double getBalance(){
			return Balance;
		}
		
		void Interest(int money){
			float Service=2;
			Balance=Balance-Service;
		}
		void Withdraw1(){
			int money;
			cout<<"( 2 $ interest is charged for this transaction )"<<endl;
			cout<<"Enter the amount of Money : ";
			cin>>money;
			
			if(Balance-money>=2){
					Balance=Balance-money;
					Interest(money);
					cout<<"Transaction is successfully"<<endl;
			}
				else
				{
					if(Balance==0){
					cout<<"Insufficient Balance!";	
					}
					else{
						cout<<"Insufficient Balance!"<<" "<<"Enter the amount of Money less than "<<(Balance-2)<<endl;
					}
					
				}
		}
			void Deposit1(){
				int money;
				cout<<"Enter the amount of Money : ";
				cin>>money;
				Balance =Balance + money;
				}
			void Display(){
				cout<<endl<<"Balance: "<<Balance<<endl;
				
					}		
};

class ChequeAccount: public ATM{ 
	
	private:
		double Deposit;
		double Balance;
	public:
		void setDeposit(double D){
		Deposit = D;
		}
		void setBalance(double B){
			Balance = B;
		}	
	
		double getDeposit(){
			return Deposit;
		}
		double getBalance(){
			return Balance;
		}
		void Cheque(){
			int money;
			string Bname;
			cout<<"Enter the name of Cheque receiver : ";
			cin>>Bname;
			cout<<"Enter amount of money in the account: ";
			cin>>Balance;
			cout<<"Enter the amount of Money : ";
			cin>>money;
			
				if(money>Balance){
					cout<<"Transaction cannot be done"<<endl;
				}
				else{
					Balance=Balance-money;
					cout<<"The Transaction is successfully"<<endl;
					cout<<endl;
					Display2(Bname,money);
				}	
		}
	void Deposit1(){
		int money;
		string Dname;
		cout<<"Enter the name on the Cheque : ";
		cin>>Dname;
		cout<<"Enter the amount of Cheque: ";
		cin>>money;
		Balance = Balance + money;
		Display1(Dname,money);
	}
	void Display1(string Dname, int money){
		cout<<"Receiver : "<<Dname<<endl;
		cout<<"Money : "<<money<<endl;
	}
	void Display2(string Bname, int money){
		cout<<"Cheque Name : "<<Bname<<endl;
		cout<<"Amount of Cheque : "<<money<<endl;
		cout<<"Balance : "<<Balance<<endl;

	}
};

int main(){
	
	int choice;
	cout<<"1. Counter Teller Login"<<endl;
	cout<<"2. Client Login"<<endl;
	
	cout<<"Choice : ";
	cin>>choice;
	
	switch (choice){
		case 1: {
			ChequeAccount c1;
			string AccName;
			cout<<"Enter Your Name: ";
			cin>>AccName;
			c1.setName(AccName);
			int AccP;
			cout<<"Enter Your Pin: ";
			cin>>AccP;
			c1.setPin(AccP);
			cout<<"********************"<<endl;
			cout<<"Cheque Account Login"<<endl;
			cout<<"********************"<<endl;
			cout<<"Account Name : "<<c1.getName()<<endl;
			
			do{
				cout<<endl<<"1. Deposit Cheque"<<endl
					<<"2. Withdraw through Cheque"<<endl
					<<"3. Exit"<<endl
					<<"Enter your choice : ";
					cin>>choice;
				
				switch(choice){
					case 1:
						c1.Deposit1();
						break;
					case 2:
						c1.Cheque();
						break;
							
				}	
		
			}while(choice!=3);
			break;
		}
		
		case 2: {
			SavingAccount s1;
			string AccName;
			cout<<"********************"<<endl;
			cout<<"Saving Account Login"<<endl;
			cout<<"********************"<<endl;
			cout<<"Enter Account Name: ";
			cin>>AccName;
			s1.setName(AccName);
			int AccP;
			cout<<"Enter Account Pin: ";
			cin>>AccP;
			s1.setPin(AccP);
			
			double AccMoney;
			cout<<"Enter the amount to Deposit: ";
			cin>>AccMoney;
			s1.setBalance(AccMoney);
			
			cout<<"Account Name : "<<s1.getName()<<endl;
			cout<<"Balance : "<<s1.getBalance();
			
			do{
				cout<<endl<<"1. Deposit"<<endl
					<<"2. Withdraw "<<endl
					<<"3. Exit"<<endl
					<<"Enter your choice : ";
					cin>>choice;
					
					switch (choice){
						
						case 1:
							s1.Deposit1();
							s1.Display();
							break;
						case 2:
							s1.Withdraw1();
							s1.Display();
							break;
			
					}
			}while(choice !=3);
			
			break;
		}

	}
return 0;	
}
