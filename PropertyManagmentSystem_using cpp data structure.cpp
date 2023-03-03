#include<iostream>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;


struct node{
	string name;
	int amount;
	int pricePerUnit;
	string catagory;
	int date;
	int tag;
	node *next;
};

// Nodes used to swap 
node *s1;
node *s2;

//This is the head of the linked list
node *head=NULL;
//This counter variable is used to automatically assign tag number to created nodes
int pos=2;

//##### FUNCTION PROTOTYPING #######

node* createNode();
void loadData();
void intro();

void insertAtBegin();
void insertAtEnd();
void insertAfterNode();
void insertBeforeNode();

void displayData();
void displayDataAt(node*);

void updateMember();
void updateNode();

void error();
// This function handles the errors that may result
int insert();
void about();
void swap();

void deleteFirst();
void deleteLast();
void deleteAtSpecific();

void sortByName();
void sortByTag();
void sortByPrice();
void sortByDate();


void search();
node* searchByTag();
node* searchByName();
node* searchByDate();
node* searchByAmount();


int main(){
	bool running = true;
	int choice;
    //@ In every switch statement we have the same choice variable to nave important memory from declaration
	//Pre-built functions to beautify the outputted text on the console.
	system("color 2f");         //set color of console terminal to green
	system("cls");              // clear console screen


	// Implemented function to load pre-existing data nodes
	//loadData();
  	// Function to display introduction inforamtion
  	intro();

	while(running){

    // Reset the function /Concsole/ to its original state and color
		system("cls");
		system("color 2f");

		cout<<"\n\t\t MENU \n"<<
		"\t-----------------------------\n"<<
		"\t 1. DISPLAY PROPERTY DATA \n\n  "<<
		"\t 2. INSERT NEW PROPERTY DATA\n\n "<<
		"\t 3. SEARCH  PROPERTY \n\n "<<
		"\t 4. DELETE PROPERTY \n\n "<<
		"\t 5. SORT DATABASE \n\n "<<
		"\t 6. UPDATE SPECIFIC DATA POINT \n\n "<<
		"\t 7. ABOUT PROPERTY MANAGEMENT SYSTEM \n ";
    
    choice = insert();

		switch(choice){
			case 1:
				displayData();
				break;
			case 2:
				cout<<"\t 1. INSERT NEW PROPERTY DATA AT BEGINNING\n " <<
						  "\t 2. INSERT NEW PROPERTY DATA AT END\n " <<
					  	"\t 3. INSERT NEW PROPERTY DATA AFTER SPECIFC POINT \n" <<
						  "\t 4. INSERT NEW PROPERTY DATA BEFORE SPECIFC POINT\n ";

                //If invalid input exists the code returns to insert
                insertAgain:
                system("color 2f");

                choice = insert();
        switch(choice){
          case 1 :
            insertAtBegin();
            break;
          case 2:
            insertAtEnd();
            break;
          case 3 :
            insertAfterNode();
            break;
          case 4:
            insertBeforeNode();
            break;
          default:
            // Outputs an error message + sound
            error();
            goto insertAgain;
          }

				break;
			case 3:
			  // Invoke the search function which encapsulates 4 search functions
				search();
				break;
			case 4:
				cout <<"\t 1. DELETE |SELL| THE PROPERTY AT FIRST \n "<<
						  "\t 2. DELETE |SELL| THE PROPERTY AT LAST \n  "<<
					   	"\t 3. DELETE |SELL| THE PROPERTY AT ANY \n ";
				del:
        // Reset color to default after error message
				system("color 2f");
				choice = insert();

				switch(choice){
					case 1:
						deleteFirst();
						break;
					case 2:
						deleteLast();
						break;
					case 3:
						deleteAtSpecific();
						break;
					default:
					    error();
					    goto del;
				}
				break;
			case 5:
				cout<<"\t 1. SORT BY PROPERTY NAME \n"
				   	<<"\t 2. SORT BY TAG \n"
					  <<"\t 3. SORT BY DATE \n"
				  	<<"\t 4. SORT BY PRICE ";
            sort:
            system("color 2f");

		  	choice = insert();
				switch(choice){
					case 1:
						sortByName();
						break;
					case 2:
						sortByTag();
						break;
					case 3:
						sortByDate();
						break;
					case 4:
						sortByPrice();
						break;
					default:
						error();
						goto sort;
				}
				break;
			case 6:
        // Update a specific nodes data
        cout <<"\t 1. Update  nodes specific member \n"
            <<" \t 2. Upadate all the nodes members \n";
        
        update:
        system("color 2f");

        choice = insert();

        if(choice == 1)
          updateMember();
        else if(choice == 2)
          updateNode();
        else{
          error();
          goto update;
        }
				break;

      case 7:
        about();
        break;
			default:
				error();
		}

		cout <<"\n DO YOU WANT TO PERFORM OTHER OPERTAIONS ?  (0 TO EXIT || ANY OTHER KEY TO GO TO MENU )?\n : ";
		choice = insert();
		if (choice == 0)
			break;
	}


}

int insert(){
     // Function used to validate input 
    int choice;
    bool running = true;

    while(running){
        cout<<">";
        cin >> choice;
        system("color 2f");
       //If cin input is of type not-int catch and correct the error to prevent fail on run time  
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            error();            //Print out error message
        }else {
            return choice;
            }
    }
}

void loadData(){
    //Creating a dummy node object
    // (head) -> [*][*][*]
	node* data = new node();
	data->name = "Personal Computer";
	data->amount = 15;
	data->catagory = "Accessory";
	data->date = 2020;
	data->pricePerUnit = 35000;
	data->tag = 0;

	head = data;

    //Creating a dummy node object
	node* data1 = new node();
	data1->name = "Automobile(Toyota)";
	data1->amount = 6;
	data1->catagory = "Cars";
	data1->date = 2017;
	data1->pricePerUnit = 700000;
	data1->tag = 1;

	data->next = data1;

    //Creating a dummy node object
	node* data2 = new node();
	data2->name = "Computer programming book";
	data2->amount = 30;
	data2->catagory = "Book";
	data2->date = 2012;
	data2->pricePerUnit = 120;
	data2->tag = 2;

	data1->next = data2;
}

void displayData(){
	node* temp = head;

	if(head == NULL){
		cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU";
	}else{
        cout<<setw(6)<<"TAG"<<setw(30)<<"PROPERTY NAME"<<setw(15)<<"AMOUNT"<<setw(20)<<"PRICE PER UNIT"<<setw(20)<<"CATAGORY"<<setw(20)<<"REGISTRATION DATE"<<endl;
        cout<<"    ========================================================================================================\n";
        while(temp!= NULL){
          // using iomanip's setwidth for foramtting output
        cout<<setw(6)<<temp->tag<<setw(30)<<temp->name<<setw(15)<<temp->amount<<setw(20)<<temp->pricePerUnit<<setw(20)<<temp->catagory<<setw(13)<<temp->date<<endl;

        temp = temp->next;
        }
	}
}

void displayAt(node* data){
	if(data == NULL){
		cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU";
	}else{
        cout << "Property name :  " << data->name << endl;
        cout << "Amount :  " << data->amount << endl;
        cout << "Price per Unit:  " << data->pricePerUnit << " birr"<<endl;
        cout << "Catagory :  " << data->catagory <<endl;
        cout << "Property registration date :  " << data->date << endl;
        cout << "Tag :  " << data->tag << endl<<endl;
	}

}

node* createNode(){
  // Create new node to hold all the struct members data
  node* data = new node();
  cout<< "Enter property name : ";
  cin >> data->name;
  cout<< "Enter the number of item : ";
  data->amount  = insert();   //insert() catchs type error
  cout <<"Enter property price per unit : ";
  data->pricePerUnit = insert();  //insert() catchs type error
  cout <<"Enter the catagory : ";
  cin>>data->catagory;
  cout <<"Enter the date of arrival : ";
  data->date = insert();  //insert() catchs type error

  // Pos is automatically assigned to the new nodes tag number and incremented
  ++pos;
  data->tag = pos;

  return data;

}

void insertAtBegin(){
  if(head == NULL){
		head = createNode();
	}else{
	    node* temp = head;
	    head = createNode();
	    head->next = temp;
  }
}

void insertAtEnd(){
	node* temp = head;

	if(temp == NULL){
		head = createNode();
	}else{
    while(temp->next != NULL){
        temp = temp->next;
    }
	temp->next = createNode();
}
}

void insertBeforeNode(){
  node* data, *temp = head, *temp2;
  int tag;
  
  cout <<"\nENTER THE TAG NUMBER : ";
  again:
	tag = insert();
   if(tag<=pos){
   	  if(head->tag==tag)
    	insertAtBegin();
	  else{
	    data = createNode();
	    while(temp->tag!=tag){
	        temp2 = temp;
	        temp = temp->next;
	    }
	    data->next = temp;
	    temp2->next = data;
		}
   }
 	else{
		cout<<"THE HIGHEST TAG NUMBER YOU CAN SELLECT IS :"<<pos;
		cout<<"\n please insert again..";
		goto again;
		}
     
}

void insertAfterNode(){
  //Insert after specific tag
  node* data, *temp = head;
  int tag, x ;

  // Display all the property lists  to select tag number
  cout<<"\n DISPLAY DATA TAG NUMBERS ?(0 to display data||any other key to continue..)\n : ";
	x = insert();     
	if (x == 0)
		displayData();
  // prompt user to enter tag number of the node after which a new one will be added to
  cout <<"\nENTER THE TAG NUMBER : ";
	again:
	tag = insert();
	if(tag<=pos){
		data = createNode();   
		while(temp->tag!=tag){
			temp=temp->next;
		}
		//Check if the node containing the tag is located at the end
		if(temp->next == NULL){
			insertAtEnd();
		}else{
			data->next=temp->next;
			temp->next=data;
		}
	 }
	else
	{
		cout<<"THE HIGHEST TAG NUMBER YOU CAN SELLECT IS :"<<pos;
		cout<<"\n please insert again..";
		goto again;
	}


       

}


void updateMember(){
	int x,tag;
	//Start  from the head node
	node* temp = head;
	cout<<"\n\t DISPLAY DATA TO FIND THE TAG NUMBER OF THE PROPERTY YOU WISH TO ADD NEW TO ?( '0' to display data||any other key to continue..)\n : ";
	cin>>x;
	if (x == 0)
		displayData();

	cout <<"\nENTER THE TAG NUMBER : ";
	agn:
	tag = insert();
	
	if(tag<=pos){
		if(temp==NULL)
			cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU\n";

	    //Iterate over all the linked lists
		while(temp->next != NULL){
	        // If the node being searched contains the tag number in question
			if(temp->tag == tag)
				break;
			temp = temp->next;
		}
		insert:
		system("color 2f");
		
		cout<<"\n\t WHAT DO YOU WANT TO UPDATE  ? \n"<<
		"\t 1. PROPERTY NAME \n "<<
		"\t 2. PROPERTY AMOUNT \n"<<
		"\t 3. PROPERTY PRICE PER UNIT \n"<<
		"\t 4. PROPERTY CATAGORY \n"<<
		"\t 5. PROPERTY DATE \n  : ";
		x = insert();

		switch(x){
			case 1 :
				cout<<"ENTER THE PROPERTY NAME : ";
				cin >> temp->name;
				cout<< "\n\t\tVALUE UPDATED !\n";
				break;
			case 2 :
				cout<<"ENTER THE PROPERTY AMOUNT : ";
                temp->amount = insert();
				cout<< "\n\t\tVALUE UPDATED !\n";
				break;
			case 3 :
				cout<<"ENTER THE PROPERTY PRICE PER UNIT : ";
				temp->pricePerUnit = insert();
				cout<< "\n\t\tVALUE UPDATED !\n";
				break;
			case 4 :
				cout<<"ENTER THE PROPERTIES CATAGORY : ";
				cin >> temp->catagory;
				cout<< "\n\t\tVALUE UPDATED !\n";
				break;
			case 5 :
				cout<<"ENTER THE PROPERTY DATE : ";
				temp->date = insert();
				cout<< "\n\t\tVALUE UPDATED !\n";
				break;
      default:
        error();
        goto insert;

		}
	}
	else{
		cout<<"THE HIGHEST TAG NUMBER YOU CAN SELLECT IS :"<<pos;
		cout<<"\n please insert again..";
    	  goto agn;
	  }
}

void updateNode(){
  node *temp = head;
  int tag, x;

  cout<<"\n\t DISPLAY DATA TO FIND THE TAG NUMBER OF THE PROPERTY YOU WISH TO ADD NEW TO ?( '0' to display data||any other key to continue..)\n : ";

  x = insert();

	if (x == 0)
		displayData();

	cout <<"\nENTER THE TAG NUMBER : ";
  // insert the tag number of the node to be Updated 
   	again:
	tag = insert();
    if(tag<=pos){
		while(temp->next != NULL){
			// If the node being searched contains the tag number in question
			if(temp->tag == tag)
			break;
			temp = temp->next;
		}

		  cout<< "Enter  property name (new): ";
		  cin >> temp->name;
		  cout<< "Enter the number of item  (new): ";
		  temp->amount  = insert();   //insert() catchs type error
		  cout <<"Enter property price per unit  (new): ";
		  temp->pricePerUnit = insert();  //insert() catchs type error
		  cout <<"Enter the catagory  (new): ";
		  cin>>temp->catagory;
		  cout <<"Enter the date of arrival  (new): ";
		  temp->date = insert(); 
		  cout<<"\n\t PROPERTY UPDATED :)";
	}
	else{
	  	cout<<"THE HIGHEST TAG NUMBER YOU CAN SELLECT IS :"<<pos;
		cout<<"\n please insert again..";
         goto again;
 	}

}

void deleteFirst(){
	node* temp = head;
	if(temp == NULL){
		cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU";
	}else{
		head = head->next;
		delete temp;
		system("color e3");
		cout<<"\n\t\t PROPERTY SOLD!\n";
	}
}

void deleteLast(){
	node* temp = head,*temp2;
	if(temp==NULL){
		cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU";
	}
	while(temp->next !=NULL){
		temp2 = temp;
		temp= temp->next;
	}
	temp2->next = NULL;
	delete temp;
	cout<<"\n\t\tPROPERTY SOLD!\n";
    system("color e3");
}

void deleteAtSpecific(){
	node* temp ,*temp2;
	int x,tag;
	cout<<"\n DISPLAY DATA TO FIND THE TAG NUMBER OF THE PROPERTY YOU WISH TO DELEETE ?(0 to display data||any other key to continue..)\n : ";
	cin>>x;
	if (x == 0)
		displayData();
	cout <<"\nENTER THE TAG NUMBER : ";
	again:
	tag=insert();
	if(tag<=pos){
		if(head==NULL)
			cout<<"NO DATA FOUND. PLEASE INSERT DATA BY SELECTING INSERT IN THE MAIN MENU";
		else if(head->tag==tag){
			temp = head;
			head=head->next;
			delete temp;
			system("e3");
			cout<<"\n\t\tPROPERTY SOLD!\n";
		}
		else{
			temp = head;
			while(temp->tag !=tag){
				 temp2 = temp;
				 temp= temp->next;
			}
			
			temp2->next=temp->next;
			delete temp;
			system("color e3");
			cout<<"\n\t\tPROPERTY SOLD!\n";
		  }
	}
	else{
		cout<<"THE HIGHEST TAG NUMBER YOU CAN SELLECT IS :"<<pos;
		cout<<"\n please insert again..";
   		goto again;
   	}

}

void swap(){
	node *temp;
	temp=new node();
	temp->name=s2->name;
	temp->amount = s2->amount;
	temp->pricePerUnit = s2->pricePerUnit;
	temp->catagory = s2->catagory;
	temp->date = s2->date;
	temp->tag = s2->tag;
	
	s2->name=s1->name;
	s2->amount = s1->amount;
	s2->pricePerUnit = s1->pricePerUnit;
	s2->catagory = s1->catagory;
	s2->date = s1->date;
	s2->tag = s1->tag;
	
	
	s1->name=temp->name;
	s1->amount = temp->amount;
	s1->pricePerUnit = temp->pricePerUnit;
	s1->catagory = temp->catagory;
	s1->date = temp->date;
	s1->tag = temp->tag;

	
	
}

void sortByName(){
	node *temp;
	if(head==NULL)
	cout<<"no data\n";
	else
	{
		s1=head;
		for(;s1->next!=NULL;s1=s1->next)
		for(s2=s1->next;s2!=NULL;s2=s2->next)
			if(s1->name > s2->name)
				swap();
        cout<<"\t SUCCESSFULLY SORTED  BY THEIR SPECIFIC NAME \n";


	}
}

void sortByTag(){
	node *temp;
	if(head==NULL)
		cout<<"NO DATA FOUND ERROR\n";
	else
	{
		s1=head;
		for(;s1->next!=NULL;s1=s1->next)
		for(s2=s1->next;s2!=NULL;s2=s2->next)
			if(s1->tag > s2->tag)
				swap();
				
		cout<<"\t SUCCESSFULLY SORTED  BY THEIR SPECIFIC TAG NUMBER \n";	
	}
}

void sortByDate(){
	node *temp;
	if(head==NULL)
		cout<<"no data\n";
	else
	{
		s1=head;
		for(;s1->next!=NULL;s1=s1->next)
		for(s2=s1->next;s2!=NULL;s2=s2->next)
			if(s1->date > s2->date)
				swap();
		cout<<"\t SUCCESSFULLY SORTED  BY THEIR SPECIFIC DATES \n";
	}
}

void sortByPrice(){
	node *temp;
	if(head==NULL)
		cout<<"no data\n";
	else
	{
		s1=head;
		for(;s1->next!=NULL;s1=s1->next)
		for(s2=s1->next;s2!=NULL;s2=s2->next)
			if(s1->pricePerUnit > s2->pricePerUnit)
			  swap();
		cout<<"\t SUCCESSFULLY SORTED  BY THEIR PRICE \n";

	}
}

void search(){
	node* temp;
	int choice;
	if(head == NULL){
		cout <<"NO DATA FOUND .PLEASE INSERT NEW DATA BY GOING TO THE MAIN MENU";
	}else{
		cout<< "\n\t 1. SEARCH BY PROPERTY NAME \n"<<
			   "\n\t 2. SEARCH BY PROPERTY TAG \n"<<
			   "\n\t 3. SEARCH BY PROPERTY DATE \n"<<
			   "\n\t 4. SEARCH BY PROPERTY AMOUNT \n : ";
		choice =insert();

		switch(choice){
			case 1:
				temp = searchByName();
				displayAt(temp);
				break;
			case 2:
				temp = searchByTag();
				displayAt(temp);
				break;
			case 3:
				temp = searchByDate();
				displayAt(temp);
				break;
			case 4:
			temp =searchByAmount();
			displayAt(temp);
				break;


	}
}
}

node* searchByName(){
	node* temp = head;
	string name;

	cout<<"ENTER THE PROPERTY NAME :  ";
	cin >> name;

	while(temp!=NULL){
		if(temp->name == name)
			break;
		temp = temp->next;
	}

	return temp;
}

node* searchByTag(){
	node* temp = head;
	int tag;

	cout<<"ENTER THE PROPERTY TAG :  ";
	cin >> tag;

	while(temp!=NULL){
		if(temp->tag == tag)
			break;
		temp = temp->next;
	}

	return temp;
}

node* searchByDate(){
	node* temp = head;
	int date;

	cout<<"ENTER THE PROPERTY DATE :  ";
	cin >> date;

	while(temp!=NULL){
		if(temp->date == date)
			break;
		temp = temp->next;
	}

	return temp;
}

node* searchByAmount(){
	node* temp = head;
	int amount;

	cout<<"ENTER THE PROPERTIES : ";
	amount = insert();

	while(temp!=NULL){
		if(temp->amount == amount)
			break;
		temp = temp->next;
	}

	return temp;
}

void intro(){
	cout<<"\n\t BAHIR DAR UNIVERSITY FACULITY OF COMPUTER AND ELETRICAL ENGINERING \n\n";
	cout<<"\n\tWELL COME TO OUR PROPERTY  MANAGEMENT SYSTEM !!!  \n*";
	cout<<"\t BAHIR-DAR UNIVERSITY \n*\n*";
    cout<<"\n\n\t-************************************-";
	cout<<"\n\t-                                     -";
	cout<<"\n\t-              L      C               -";
	cout<<"\n\t-         L                O          -";
	cout<<"\n\t-      E                      M       -";
	cout<<"\n\t-    W                            E   -";
	cout<<"\n\t-          MANAGEMENT SYSTEM          -";
	cout<<"\n\t---------------------------------------\n\n";
	cout<<endl;
	cout<< "\t\t DEVELOPED BY \n";
	cout<<"*    *********************************\n";
	cout << setw(25)<<"YARED ABEBE"<<setw(16)<<"B\n\n";
	cout<<"************************************************\n";
	for (int i=0; i<3;i++){
       system("color 2a");
       system("color 3b");
       system("color c1");
       system("color b6");
	}	system("color 6");	
	cout<<"\t Press Any Key To Get Stated !!!...\n"<<endl;
	cout<<"\t******************************************\n";
	cin.get();

}

void error(){
    // This is another function that give an error message
    // Gives an error sound
    Beep(1000,900);             // Gives a beep sound with specified frequency, duration(ms)
    system("color 4e");         // Changes color of console to red to indicate error

    cout<<"\n\t\t!!!!!!!!!!! ERROR_..!!!!!!!!!!!!!\n";
    cout<<"\n\t   CHOOSE ONLY THE NUMBER LISTED ON THE ABOVE  MENU  ....\n";
    cout<<": ";
}

void about(){
	system("cls");
	system("color 5f");
	
	cout << " \tP.M.S v1.0 \t -- ፳፻፲፬| ፭ |፳፪\n";
	cout << "\t";
	cout<<"\n THIS SOFTWARE WAS DEVELOPED AS A MEANS FOR COMPANIES TO MANAGE THEIR PROPERTY THROUGH ARCIEVING ALL THEIR PROPERTY DATA INTO ONE CENTRALIZED DATABASE. TERMS AND CONDITIONS ARE APPLIED FULLY TO THE USER OF THIS SOFTWARE AS IMPLRMENTED BY THE DEVELOPERES. BY USING THIS SOFTWARE YOU AGREE TO THE TERMS AND CONDITIONS ENFORCED. AS SUCH THE DEVELOPERS ARE NOT ENTITELED TO ANY LEGAL IN ACCORDANCE WITH THE USE OF THE SOTWARE. \n\nWITH VAST AMOUNT OF FUNCTIONALITY EMBEDED IN THE SOFTWARE IN ITSELF(WITH OUT NO THIRD PARTIES SOFTWARES INVOLVED) COMPANY HEADS/ADMINISTRATORS/ CAN EFFECTIVELY : \n"<<
	"\t* INSERT NEW PROPERTY IN THEIR DATABASE, \n"<<
	"\t* DELETE OR REMOVE PROPERTIES WHICH HAVE BEEN SOLD OR PROPERTIES WHICH ARE OF NO USE TO THE COMPANY \n"<<
	"\t* SORT THE PROPERTIES REGISTERED ACCORDING TO SOME DEFAULT PARAMETERS(WHICH CAN BE SEEN BY SELECTING DETAIL IN THE NEXT MENU) \n"<<
	"\t* DISPLAY ALL THE PROPERTIES FOUND IN THE DATABASE\n"<<
	"\t* SEARCH FOR SPECIFIC PROPERTY USING DEFAULT PARAMETERS(WHICH CAN BE SEEN BY SELECTING DETAIL IN THE NEXT MENU";
	cout<<"\n\t\t DISPLAY DETAILS (0-display)?\n";
	if(insert() == 0 ){
	cout << "THIS ARE THE DEFAULT FUNCTIONALITIES EMEBEDED IN THE SYSTEM\n";
	cout <<"\n\n1. DISPLAY PROPERTY DATA\n\n"<<
	"\t1.1 DISPLAY ALL PROPERTY \n"<<
	"\t1.2 DISPLAY SPECIFIC PROPERTY\n"<<
	"\n\n2. INSERT NEW PROPERTY DATA\n\n"<<
	"\t2.1. INSERT NEW PROPERTY DATA AT BEGINNING \n"<<
	"\t2.2. INSERT NEW PROPERTY DATA AT END\n"<<
	"\t2.3. INSERT NEW PROPERTY DATA AFTER SPECIFC POINT\n"<<
	"\t2.4. INSERT NEW PROPERTY DATA BEFORE SPECIFC POINT\n"<<
	"\n\n3. SEARCH  PROPERTY\n\n"<<
	"\t3.1. SEARCH BY PROPERTY NAME \n"<<
	"\t3.2. SEARCH BY PROPERTY TAG \n"<<
	"\t3.3. SEARCH BY PROPERTY DATE \n"<<
	"\t3.4. SEARCH BY PROPERTY AMOUNT \n "<<
	"\n\n4. DELETE PROPERTY\n\n"<<
	"\t4.1. DELETE |SELL| THE PROPERTY AT FIRST \n "<<
	"\t4.2. DELETE |SELL| THE PROPERTY AT LAST \n "<< 
	"\t4.3. DELETE |SELL| THE PROPERTY AT ANY \n"<< 
	"\n\n5. SORT DATABASE\n\n"<<
	"\t5.1. SORT BY PROPERTY NAME \n"<<
	"\t5.2. SORT BY TAG \n"<<
	"\t5.3. SORT BY DATE \n"<<
	"\t5.4. SORT BY PRICE \n "<<
	"\n\n6. UPDATE SPECIFIC DATA POINT\n\n"<<
	"\t6.1. Update  nodes specific member \n"<<
	"\t6.2. Upadate all the nodes members \n";
}
}
