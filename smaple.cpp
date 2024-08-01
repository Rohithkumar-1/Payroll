#include<iostream>
#include<string>
using namespace std;
class Manager{
	private:
		int id,d,m,y;
		string name,dept,phno;
		long double bs,hsa,da,fa,fs;
	public:
		void Employee(){
			cout<<"\n\n----ENTER THE BASIC DETAILS OF EMPLOYEE----\n";
			cout<<"\nID:\t ";
			cin>>id;
			cin.ignore(); 
			cout<<"Name:\t ";
			getline(cin, name);
			cout<<"DOB (dd/mm/yyyy):";
			cin>>d>>m>>y;
			cin.ignore(); 
			cout<<"Department:   ";
			getline(cin, dept);
			cout<<"Phone Number: ";
			cin>>phno;
			cout<<"Basic salary: ";
			cin>>bs;
			cout<<"\nSucessfully added the employee details !...\n";
		}
		long double CalculateFinalSalary(){
			
				hsa = (bs*3.25)/100;
				da = (bs*4.5)/100;
				fa = (bs*1.75)/100;
				fs = bs - hsa - da - fa;
			
		}
		void display(){
			cout<<"\n\nID\t\t:"<<id;
			cout<<"\nName\t\t:"<<name;
			cout<<"\nDOB\t\t:"<<d<<"/"<<m<<"/"<<y;
			cout<<"\nDepartment      :"<<dept;
			cout<<"\nPhone Number    :"<<phno;
			cout<<"\nFinal Salary    :"<<fs<<"\n\n";
		}
		int getId() {
        return id;
    	}
};
int main(){
	Manager Emp[100];
	int i,choice,n=0,iden;
	string pawo = "PayRoll25",pw;
	do{
	cout<<"\n\nChoose your choice:-\n";
	cout<<"'1'-> Add Employee\n";
	cout<<"'2'-> Display Employee details\n";
	cout<<"'3'-> Remove Employee\n";
	cout<<"'4'-> Modified Employee Details\n";
	cout<<"'5'-> Show all Employee Details\n";
	cout<<"'6'-> Exit\n";
	cout<<"\nChoose your option:";
	cin>>choice;
			switch(choice){
				
				case 1:
					cout<<"\nOnly Admin can add the employee!\n";
					cout<<"Enter the password:";
					cin>>pw;
					if(pw==pawo){
					n++;
					Emp[n].Employee();
					Emp[n].CalculateFinalSalary();
						}
					else
					cout<<"\nPassword is incorrect, Try again !...\n";
					break;

				case 2:
					cout<<"\nEnter your ID:";
					cin>>iden;
					for(i=1;i<=n;i++){
						if (Emp[i].getId() == iden){
							cout<<"\n----DETAILS OF EMPLOYEE----\n";
							Emp[i].display();
							break;
								}
						cout<<"Sorry! Check employee ID.\n";
						}
						break;
						
				case 3:
					cout<<"\nOnly Admin can Remove the employee!\n";
					cout<<"Enter the password:";
					cin>>pw;
					if(pw == pawo){
					cout<<"\nEnter Removed Employee ID:";
					cin>>iden;
					bool found = false;
                			for (int i = 1; i <= n; i++) {
                    			if (Emp[i].getId() == iden) {
                        			found = true;
                        			for (int j = i; j < n; j++) {
                            			Emp[j] = Emp[j + 1];
                        				}
                       				 n--;
                        			cout << "Employee removed successfully.\n";
                        			break;
                   					 }
               					 }
                				if (!found) {
                  				  cout << "Employee with ID " << iden << " not found.\n";
               						 }
           						 } else {
               			 cout << "Password is incorrect, Try again!...\n\n";
          							  }	
          					break;				  
          							  
				case 4:
					cout<<"\nOnly Admin can modify the details of employee!\n";
					cout<<"Enter the password:";
					cin>>pw;
					if(pw == pawo){
					cout<<"\nEnter Employee ID want to modify:";
					cin>>iden;
					for (int i = 1; i <= n; i++) {
                    	if (Emp[i].getId() == iden){
                    		Emp[i].Employee();
							Emp[i].CalculateFinalSalary();
							cout<<"Successfully Modified Your Employee details.";
							break;
							}
                		}
                	cout<<"Sorry! Check employee ID.\n";
                	}
                	else
                	cout << "Password is incorrect, Try again!...\n\n";
					break;
				
				case 5:
					if(n!=0){
					cout<<"\n----DETAILS OF ALL EMPLOYEES----\n";
                	for(i=1;i<=n;i++){
                		Emp[i].display();
						}
					}
					break;
					
				case 6:
                	cout << "Exiting program.\n";
                	break;

            	default:
                	cout << "\n Invalid choice, please try again.\n";	
					break;		
				}
			}while(choice!=6);
			
	return 0;
}