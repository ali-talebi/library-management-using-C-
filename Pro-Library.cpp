#include<iostream>
#include<vector>
using namespace std ; 


int ID_BOOK =  1 ; 
int ID_MEMBER =  1 ; 

class Book
{
	
	private : 
		string Name_book , Author_book ; 
		int ID_BOOK ; 
		
	public : 
			

		Book(string name , string author   ) 
		{ 
			this->Name_book = name ; 
			this->Author_book = author ; 
			
		
		}	
		
		
		
		void set_name(string new_name ) 
		{
			this->Name_book = new_name ; 
		}

		void set_author(string new_author )
		{
			this->Author_book = new_author ; 
		}

		void print_information() const {
			cout  << " Name : " << this->Name_book << " , Author : " << this->Author_book << " , ID : " << this->ID_BOOK << endl  ; 
		}

	friend class 	Member ; 
	friend class Library ; 
	
};


class Member{
	
	private : 

		string Name_person , Family_person ; 
		string code_person ; 
		 
		vector<Book> my_books ; 
		
	public : 
	
		int ID_member ;
		
		Member(string name , string family , string code ) 
		{
			this->Name_person = name ; 
			this->Family_person = family ; 
			this->code_person = code ; 
		}
	
		void add_book(Book &obj ) 
		{
			my_books.push_back(obj) ; 
		}
		
		void remove_book(Book &obj)
		{
			for(auto it = my_books.begin() ; it != my_books.end() ; it++ )
			{
				if (obj.Name_book == (*it).Name_book && obj.Author_book == (*it).Author_book )
				{
					my_books.pop_back() ; 
					cout << " This Book removed ! " << endl ; 
				}
			}
		}


		void printInformation()
		{
			cout << "Name : " << this->Name_person << " , Family : " << this->Family_person << endl ; 
			cout << "Your Books : " << endl ; 
			for(auto it = my_books.begin() ; it != my_books.end() ; ++it ) 
			{
				cout << (*it).Name_book << endl ; 
			}
			
			cout << " ------------------------ " << endl ;
		}
			
		
		
	friend class Library ; 
	
};




class Library{
	
	private :
	 
		vector<Book> Total_books ;
		vector<Member> Total_members ;
		string name , city ; 
		
	public : 
	
		Library(string name , string city )
		{
			this->name = name ; 
			this->city = city ; 
		}
		void Gather_Books(Book &obj ) 
		{	
			obj.ID_BOOK = ::ID_BOOK++ ; 
			Total_books.push_back(obj) ;   
		}
	

	void Gather_Members(Member &obj )
		{
			obj.ID_member = ::ID_MEMBER++ ; 
			Total_members.push_back(obj) ; 
		}



	Book Find_Book_With_Id( int id  )
	{
		for(auto it = Total_books.begin() ; it != Total_books.end() ; ++it ) 
		{
			if (((*it).ID_BOOK == id ) ) 
			{
				return *it ; 
			}
		}
	}
	


	Book Find_Book_With_Name_And_Author( string name , string author )
	{
		for(auto it = Total_books.begin() ; it != Total_books.end() ; ++it ) 
		{
			if (((*it).Name_book == name) && ((*it).Author_book == author ) ) 
			{
				return *it ; 
			}
		}
	}
	
	
	
	Member  Find_Person(string  code  )
	{	

		for(vector<Member>::iterator  it =Total_members.begin() ; it != Total_members.end() ; it++ )
		{
			if ((*it).code_person == code )
			{
				return *it ; 	
			} 
			
		}
		
		
		
	}



	void print_total_books() const 
	{
		for(auto it = Total_books.begin() ; it != Total_books.end() ; ++it )
		{
			(*it).print_information(); 
		}
	}

	void print_total_members()	const 
	{
		for(auto it = Total_members.begin() ; it != Total_members.end() ; ++it )
		{
			cout << (*it).Name_person << " - " << (*it).Family_person << endl  ;  
		}
	}

	
};





int main()
{
	int response_client ; 
	string book_name , auther_book ;  
	string name_member , family_member , code_melli_person ; 
	
	
	Library l1("22-Bahman" , "Shahrood") ; 
	
	while (true) 
	{
		cout << "Plese Select a number and Type It " << endl ; 
		cout << "1.Register Book / 2.Register Member / 3.Find a Book / 4.Get Book " << endl ; 
		cout << "5.Print_Person_INFO / 6.Print Total Books / 7.Print Total Members / 8.Exit " << endl ; 
		cout << " ----- *** --- " << endl ; 
		
		cin >> response_client ; 
		
		if (response_client == 1 ) 
		{
			cout << "type book_name : "   << endl ; cin >> book_name ; 
			cout << "type auther_book : " << endl ; cin >> auther_book ; 
			Book b1( book_name , auther_book ) ; 
			l1.Gather_Books(b1) ; 
			
		} 
		
		else if (response_client == 2 ) 
		{
			cout << "type name_member : " << endl ; cin >> name_member ; 
			cout << "type family_member : " << endl ; cin >> family_member ; 
			cout << "type code_melli_person : " << endl ; cin >> code_melli_person ; 
			Member m1(name_member , family_member , code_melli_person  ) ; 
			l1.Gather_Members(m1) ; 
		}
		
		else if (response_client == 4 ) 
		{
			cout << "type code_melli_person : " << endl ; cin >> code_melli_person ; 
			Member m =  l1.Find_Person(code_melli_person) ; 
			cout << "type book_name : " << endl ; cin >> book_name ; 
			cout << "type auther_book : " << endl ; cin >> auther_book ; 
			
			Book b = l1.Find_Book_With_Name_And_Author(book_name , auther_book  ) ; 
			
			
			m.add_book(b) ; 
			

		}
		
		
		else if (response_client == 5 ) 
		{
			cout << "type code_melli_person : " << endl ; cin >> code_melli_person ; 
			Member m = l1.Find_Person(code_melli_person) ; 
			m.printInformation() ; 
		}
		
		
		else if (response_client == 6 ) 
		{
			l1.print_total_books() ; 
		}
		
		else if (response_client == 7 ) 
		{
			l1.print_total_members() ; 
		}
		else if (response_client == 8 ) break ; 
		
		cout << " -------------- [new command] -------------- "<< endl ; 
	}
}





