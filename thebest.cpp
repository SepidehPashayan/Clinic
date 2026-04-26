#include<iostream>
#include<fstream>
using namespace std;
class date{//sepideh pashayan 402103242
	public:
	    date(int y,int m,int d):year(y),month(m),day(d){}
	protected:
		 int year,month,day;
};
class filing:public date{
	public:
		int count;
		filing(string name,string last_name,string id,int age,int y,int m,int d,int count=0):
		date(y,m,d),name(name),last_name(last_name),id(id),age(age),count(count){}
		void print(){
			cout<<"...patient information..."<<endl;
			cout<<endl;
			cout<<"date : "<<year<<"/"<<month<<"/"<<day<<endl;
			cout<<"name : "<<name<<endl;
			cout<<"last name : "<<last_name<<endl;
			cout<<"id : "<<id<<endl;
			cout<<"age : "<<age<<endl;
			cout<<"count : "<<count<<endl;
			cout<<endl;
		}
		void file(){
			ofstream filing("filing.txt",ios::app);
			filing<<id<<" "<<year<<" "<<month<<" "<<day<<" "<<name<<" "<<last_name<<" "<<age<<" "<<count<<endl;
			cout<<"the case was filed for patient"<<endl;
			cout<<endl;
			filing.close();
		}
	protected:
		string name , last_name,id;
		int age;
};
class search:public filing{
	public:
		    search(string name,string last_name,string id,int age,int y,int m,int d,int count):
		    filing(name,last_name,id,age,y,m,d,count){}
			bool searching(string searchid){
			bool find=false;
			ifstream filing("filing.txt");
			while(filing>>id){
				filing>>year>>month>>day>>name>>last_name>>age>>count;
				if(id==searchid){
			cout<<"...patient information..."<<endl;
			cout<<endl;
			cout<<"date : "<<year<<"/"<<month<<"/"<<day<<endl;
			cout<<"name : "<<name<<endl;
			cout<<"last name : "<<last_name<<endl;
			cout<<"id : "<<id<<endl;
			cout<<"age : "<<age<<endl;
			cout<<"count : "<<count<<endl;
			cout<<endl;
			        find=true;
			        break;
				}
			}
			if(!find)cout<<"\asorry "<<searchid<<" didn't find please file a case"<<endl;
			return find;
		}	
};
class doc{
	public:
		doc(int codedoc,string esm,string jobb):codedoc(codedoc),esm(esm),jobb(jobb){}
		void docjob(){
			cout<<"enter the code :";
			cin>>codedoc;
			cout<<"enter the name :";
			cin>>esm;
			cout<<"enter the job :";
			cin>>jobb;
			ofstream docjob("docjob.txt",ios::app);
			docjob<<codedoc<<" "<<esm<<" "<<jobb<<" "<<endl;
		}
	protected:
		string esm,jobb;
		int codedoc;
};
class doctor:public search,public doc{
	public:
	doctor(string name,string last_name,string id,int age,int y,int m,int d,int count,int codedoc,string esm,string jobb):
	search(name,last_name,id,age,y,m,d,count),doc(codedoc,esm,jobb){}
	void choose_doctor(string searchid){
		ifstream docjob("docjob.txt");
		while(docjob>>codedoc>>esm>>jobb){
			cout<<codedoc<<"."<<esm<<"--->"<<jobb<<endl;
		}
		int code;
		cout<<"please choose a doctor(enter the code) :";
		cin>>code;
		cout<<endl;
		while(docjob>>codedoc>>esm>>jobb){
			if(code==codedoc)cout<<"..."<<codedoc<<"..."<<esm<<"--->"<<jobb<<"..."<<endl;
		}
        
		cout<<endl;
	}
};
class diagnosis:public doctor{
	public:
		diagnosis(string name,string last_name,string id,int age,int y,int m,int d,string information[2000],string diag[1000],string medicine[5],int count,int add,int codedoc,string esm,string jobb):
	    doctor(name,last_name,id,age,y,m,d,count,codedoc,esm,jobb),add(add){medicine[5]=medicine[5];diag[1000]=diag[1000];information[2000]=information[2000];}
	    void print_doctor(string searchid){
	    cout<<"...doctor's diagnosis..."<<endl;
	    cout<<endl;
	    cout<<"\tfor ending enter ; "<<endl;
	    cout<<"information: "<<endl;
	    for(int j=0;j<2000;j++){
	    cin>>information[j];
	    if(information[j]==";")break;}
		cout<<"\tfor ending enter ; "<<endl;
	    cout<<"illness: "<<endl;
	    for(int k=0;k<1000;k++){
	    cin>>diag[k];
	    if(diag[k]==";")break;}
	    cout<<"\tyou can only enter 5 medicine . for ending enter ; "<<endl;
	    cout<<"medicine: ";
	    for(int i=0;i<5;i++){
		cin>>medicine[i];
		if(medicine[i]==";")break;}
	    ifstream filing("filing.txt");
	    while(filing>>id){
				filing>>year>>month>>day>>name>>last_name>>age>>count;
				if(id==searchid){
			cout<<"...patient information..."<<endl;
			cout<<endl;
			cout<<"date : "<<year<<"/"<<month<<"/"<<day<<endl;
			cout<<"name : "<<name<<endl;
			cout<<"last name : "<<last_name<<endl;
			cout<<"id : "<<id<<endl;
			cout<<"age : "<<age<<endl;
			cout<<"count : "<<count+1<<endl;
			cout<<endl;}}
	    cout<<"...doctor's diagnosis..."<<endl;
	    cout<<endl;
	    cout<<"information: "<<endl;
	    for(int j=0;j<2000;j++){
	    if(information[j]==";")break;
	    cout<<information[j]<<" ";
	    if(j%5==0&& j!=0)cout<<endl;
		}
		cout<<endl<<endl;
	    cout<<"illness: "<<endl;
	    for(int k=0;k<1000;k++){
	    if(diag[k]==";")break;
	    cout<<diag[k]<<" ";
	    if(k%5==0&& k!=0)cout<<endl;
		}
		cout<<endl<<endl;
	    cout<<"medicine: ";
	    for(int i=0;i<5;i++){
	    if(medicine[i]==";")break;
		cout<<medicine[i]<<" ";
		}
		cout<<endl<<endl;
	}
	void file_patient(string searchid){
		ofstream patient("patient.txt",ios::app);
		patient<<searchid<<endl;
		for(int j=0;j<2000;j++){
			if(information[j]==";")break;
			patient<<information[j]<<" ";
		}
		patient<<endl;
		for(int k=0;k<1000;k++){
			if(diag[k]==";")break;
			patient<<diag[k]<<" ";
		}
		patient<<endl;
		for(int i=0;i<5;i++){
			if(medicine[i]==";")break;
			patient<<medicine[i]<<" ";
		}
		patient<<endl<<endl;}
	int repair_file(string searchid){
		ifstream filing("filing.txt");
		ofstream temp("temp.txt",ios::app);
		while(filing>>id){
			filing>>year>>month>>day>>name>>last_name>>age>>count;
			if(id!=searchid){
				temp<<id<<" "<<year<<" "<<month<<" "<<day<<" "<<name<<" "<<last_name<<" "<<age<<" "<<count<<endl;
			}
			else {int add=count+1;temp<<id<<" "<<year<<" "<<month<<" "<<day<<" "<<name<<" "<<last_name<<" "<<age<<" "<<add<<endl;}
		}
		filing.close();
		temp.close();
		remove("filing.txt");
		rename("temp.txt","filing.txt");
		return add;
	}
	protected:
		string information[2000],diag[1000],medicine[5];
		int add;
		
};

int main(){
	string name,last_name,id,searchid,information[2000],diag[1000],medicine[5],username,password,answer,esm,jobb;
	int age,year,month,day,count,add,codedoc;
	char ans;
	// username is  " sepideh "
	// password is  " 402103242 "
	cout<<"\a...welcome to the clinic...\n";
	cout<<"please enter your username: ";
	cin>>username;
	cout<<"please enter your password: ";
	cin>>password;
	cout<<endl;
	if(username=="sepideh"&&password=="402103242"){
	esc:cout<<"doctor or patient ( d or p ) :";
	cin>>ans;
	while(ans!='p'&&ans!='P'&&ans!='d'&&ans!='D'){
 	cout<<" you have to choose from these two options : ";
 	cin>>ans;
    }
	if(ans=='p'||ans=='P'){
	cout<<"id :";
	cin>>searchid;
	search x(name,last_name,id,age,year,month,day,count);
	doctor y(name,last_name,id,age,year,month,day,count,codedoc,esm,jobb);
	diagnosis y1(name,last_name,id,age,year,month,day,information,diag,medicine,count,add,codedoc,esm,jobb);
	bool found=x.searching(searchid);
	if(found){cout<<"\a\t"<<searchid<<" found"<<endl;
	y.choose_doctor(searchid);
	y1.print_doctor(searchid);
	y1.file_patient(searchid);
	count=y1.repair_file(searchid);
	cout<<"do you want to go back home?: ";
	cin>>answer;
	if(answer=="yes"||answer=="Yes")goto esc;
	else{cout<<"bye have a good day"<<endl; exit(0);}
	}
	else{
	cout<<"name :";
	cin>>name;
	cout<<"last name :";
	cin>>last_name;
	cout<<"id :";
	cin>>id;
	cout<<"age :";
	cin>>age;
	cout<<"date :";
	cin>>year>>month>>day;
	cout<<endl;
	filing x1(name,last_name,id,age,year,month,day,count);
	x1.print();
	x1.file();
	y.choose_doctor(searchid);
	y1.print_doctor(searchid);
	y1.file_patient(searchid);
	count=y1.repair_file(searchid);
	cout<<"do you want to go back home?: ";
	cin>>answer;
	if(answer=="yes"||answer=="Yes")goto esc;
	else{cout<<"bye have a good day"<<endl; exit(0);}
}
}
else if(ans=='d'||ans=='D'){
doc z(codedoc,esm,jobb);
z.docjob();
cout<<"do you want to go back home?: ";
cin>>answer;
if(answer=="yes"||answer=="Yes")goto esc;
else{cout<<"bye have a good day"<<endl; exit(0);}
}
}
else cout<<"\asorry.you can't access the clinic information";
return 17;
}
