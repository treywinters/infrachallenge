#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

using namespace std;
int main(){
    string line;
   ifstream file ("loomings.txt"); 
   vector< pair< string, int> > files_sorted;
   vector<string> files;
   
   if( file.is_open()){
       int total = 1;
       while(getline(file, line)){
           ofstream temp;
           ofstream temp2;
           if(line.length() != 0){
               //creates files for each non empty line in file
               string name = "File-" + to_string(total) + ".txt";
               temp.open(name);
               temp << line << endl;
               files.push_back(name);
               
                //creates the companion hash files
               hash<string> h1;
               string hname = "File-" + to_string(total) + ".hash";
               temp2.open(hname);
               temp2 << h1(line) << endl;
               total ++;
               
                //gets the size of the file and creates a pair of filename and file size
               temp.seekp(0,ios::end);
               int size = temp.tellp();
               
              //creates the sorted list of filenames based on the paired file size
               if(files_sorted.empty()){
                   files_sorted.push_back(pair <string, int>(name, size) );

               }
               else{
                   for( int i = 0; i < files_sorted.size(); i++ ){
                       if( size <= files_sorted[i].second ){
                           vector< pair< string , int > >::iterator it;
                           it= files_sorted.begin();
                           files_sorted.insert( it+i,pair <string, int>(name,size) );
                           break;

                       } 
                       else if( size > files_sorted.back().second) {
                           files_sorted.push_back(pair<string, int> (name, size));
                           break;

                       }
                   }
               }
               
               temp.close();
               temp2.close();
           }

           
          
       }

       string test1;
       string test2;
       ifstream check1;
       ifstream check2;
       string duptext;
       pair<string,string> duplicates;
       
       //checking for the duplicate line in the created files and storing the filenames
       for( int i  = 0 ; i < files_sorted.size(); i ++){
           for ( int j = i; j < files_sorted.size(); j ++){
               if( i == j)
                continue;
            ifstream check1(files_sorted[i].first);
            ifstream check2(files_sorted[j].first);
            getline(check1,test1);
            getline(check2,test2);

               if( test1.compare( test2 )== 0 ){
                   duplicates = pair<string,string>( files_sorted[i].first,files_sorted[j].first);
                   duptext = test1;
                   break;

               }
           
                check1.close();
                check2.close();
           }
       }
       ofstream last1;
       //adding every line from loomings into loomings-clean except for the duplicate
       last1.open("loomings-clean.txt");
       for( int i = 0 ; i < files.size(); i ++){
           ifstream last2;
           string text;
           if(files[i].compare(duplicates.second) != 0){
                last2.open(files[i]);
                getline(last2,text);
                last1<<text<<endl<<endl;
           }
           last2.close();
       }
       last1.close();

       //printing out list of sorted files with their respective file sizes
      	cout<<"< Printing out the sorted list of File Names and File Sizes >"<<endl; 
	for(int i = 0; i < files_sorted.size(); i++){
               cout<< files_sorted[i].first<< " " <<files_sorted[i].second<<endl;
           }
	cout<<endl<<endl;
        //printing the duplicate files and duplicate line
        cout<<"Duplicates : "<<duplicates.first<<" "<<duplicates.second<<endl<<"\n Line: "<<duptext<<endl<<endl;
        
       file.close();
   }
}
