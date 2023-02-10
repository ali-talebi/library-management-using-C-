#include<iostream>
#include<vector>
using namespace std ; 

class Book{
	
	private : 
		string name_book , name_auther ; 
		int id ; 
		 
	public : 
		
		
		Book(const string &name ,const  string &auther )
		{
			this->name_book = name ; 
			this->name_auther = auther ; 
			this->id  =  this->set_id() ; 
		}
	
		int set_id()
		{
			static int i = 0 ; 
			
			i++ ; 
			return i ; 	
		}
	
		void PrintInformation() const {
			cout << "Name : " << this->name_book << " , Auther : " << this->name_auther << " , Id : " << this->id  << endl ; 
		}
		
		
		void set_Name(const string &new_name ) 
		{
			this->name_book = new_name ; 
		}
	
	
		void set_Auther(const string &new_auther )
		{
			this->name_auther = new_auther ; 
		}


		void printInformation()
		{
			cout << "Name : " << this->name_book << " , Auther : " << this->name_auther << " , ID : " << this->id << endl ;  
		}

		friend class Person ; 
		friend class Lib ; 

};



class Person{
	
	private : 
		string name , family , code ; 
		vector<Book> my_books ; 
		
	public : 
		Person(const string &name , const string &family , const string &code )
		{
			this->name = name ; 
			this->family = family ; 
			this->code = code ; 
		}
		
		
		void add_book(Book &obj )
		{
			my_books.push_back(obj) ; 
		}
		
		
		void remove_book(Book &obj ) 
		{
			int index = 0 ; 
			for(auto iter = my_books.begin() ; iter != my_books.end() ; ++iter )
			{
				
				if ( iter->id == obj.id )
				{
					my_books.erase(my_books.begin() + index ) ; 
				} 
				index++ ; 
			} 
		}


		Book Find_book(const int &number ) 
		{
			
			for(auto iter = my_books.begin() ; iter != my_books.end() ; ++iter )
			{
				if ( iter->id == number ) 
				{
					
					return *iter; 
				}
			}
			throw "This Book Not in Your Account " ; 
		}


		void printInformation()
		{
			cout << "Name : " << this->name << " , Family : " << this->family << " Code : " << this->code << endl ; 
		}
	
	
		void printMyBook()
		{
			for(auto iter =my_books.begin() ; iter != my_books.end() ; ++iter ) 
			{
				cout << "Name Book : " << iter->name_book << " , Auther : " << iter->name_auther << " , ID : " << iter->id << endl ;   	
			} 
			
			
		
		}
		friend class Lib ; 
};


class Lib{

	private : 
		string name , owner ; 
		vector <Person> my_member ; 
		vector <Book> Total_book ; 


	public : 
		Lib(const string name , const string owner )
		{
			this->name = name ; 
			this->owner = owner ; 
		}


		void Get_Member(Person &obj ) 
		{
			my_member.push_back(obj) ; 

		}

		void Get_Book(Book &obj ) 
		{
			Total_book.push_back(obj) ; 
		}

		void Show_Total_Member()
		{
			for(auto iter = my_member.begin() ; iter != my_member.end() ; ++iter ) 
			{
				iter->printInformation() ; 
			}
		}



		void Show_Total_Books() 
		{
			for(auto iter = Total_book.begin() ; iter != Total_book.end() ; ++iter )
			{
				(*iter).printInformation() ; 
			}
		}



		void Select_Book(const string &code )
		{
			int id_select_book ; 
			int flag_1= 0 , flag_2 = 0 ; 
			cout << "Please select a Book , Enter Number ID : " << endl ;
			this->Show_Total_Books() ; 
			cin >> id_select_book ; 
			for(auto iter = my_member.begin() ; iter != my_member.end() ; ++iter )
			{
				if( iter->code == code )
				{
					
					flag_1 = 1 ; 
					for( auto iter2 = Total_book.begin() ; iter2 != Total_book.end() ; ++iter2 ) 
					{
						if( iter2->id == id_select_book )
						{
							iter->add_book(*iter2) ; 
							flag_2 = 1 ; 
						}
					} 
					
					if (flag_2 == 0 )
					{
						throw -2 ; 
					}
						
				}
			}
			if(flag_1 == 0 ) throw -1  ; 
		}



		
		Person Find_Person(const string &code )
		{
			for(auto iter = my_member.begin() ; iter != my_member.end() ; ++iter ) 
			{
				if (iter->code == code )
				{
					return *iter ; 
				}
			}
			
			throw "We Not Found This User Here . " ; 
		}


}; 

int main()
{
	int response , id_book ; 
	string name , family , code ; 
	string name_book , auther_book ; 
	Lib l1("alborz" , "musavi") ; 
	while (true)
	{
		cout << "1.Create Book / 2.Create Person / 3. show Total Member / 4.Show Total Book  / 5.Select Book / 6.Back Book / 7.SHow My Account  /  8.Exit " << endl ; 
		cin >> response ; 
		if (response == 1 ) 
		{
			cout << "Enter Name book : " << endl ; cin >> name_book ; 
			cout << "Enter Auther : " << endl ; cin >> auther_book ; 
			Book b(name_book , auther_book ) ; 
			l1.Get_Book(b) ; 
		}


		else if (response == 2 ) 
		{
			cout << "Enter Name : " << endl ; cin >> name ; 
			cout << "Enter Family : " << endl ; cin >>  family ; 
			cout << "Enter Code Melli : " << endl ; cin >> code ;  
			Person p(name , family ,  code ) ; 
			l1.Get_Member(p) ; 
		}

		else if (response == 3 ) 
		{
			l1.Show_Total_Member() ; 
		}
	

		else if (response == 4 ) 
		{
			l1.Show_Total_Books() ; 
		}


		else if (response == 5 ) 
		{
			try
			{
			
			cout << "please Enter Your Code Melli " << endl ; 
			cin >> code ; 
			l1.Select_Book(code) ; 
			
			
			}
			catch(int i ) 
			{
				if (i == -1 ) {
					cout << "This User Is Not Regist HEre " << endl ; 
				}
				
				else if ( i == -2 ) {
					cout << "This Book IS Not Exist . " << endl ; 
				}
			}
		}
			
			
		
		else if ( response == 6 ) 
		{
			cout << "Please Enter Your Code Melli " << endl ; 
			cin >> code ; 
			try{
			
			Person p = l1.Find_Person(code) ; 
			cout << "Please Enter ID Book " << endl ; 
			cin >> id_book ; 
			Book b   = p.Find_book(id_book)  ; 
			p.remove_book(b) ; 
			
		
			}catch(const char * msg)
			{
				cout << msg << endl ; 
			}
			
		}
		
			
		else if ( response == 7 ) 
		{
			cout << "Please Enter Your Code Melli " << endl ; 
			cin >> code ; 
			try
			{
				Person obj = l1.Find_Person(code) ; 
				obj.printInformation() ; 
				obj.printMyBook() ; 
				
			}
			
			
			catch(const char * msg )
			{
				cout << msg << endl ; 
			}
		}
			
		else if ( response ==   8 ) break ; 
		
		
		cout << endl << " -------------------- New Command -------------------- " << endl ; 
	}
	


}