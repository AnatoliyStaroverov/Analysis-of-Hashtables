#include<iostream>
#include<vector>
#include<fstream>
#include <cstdlib>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>

#include "QuadraticProbing.h"
#include "QuadraticProbing1.h"
#include "QuadraticProbing2.h"

using namespace std;

vector<string> Input_Data_From_Ohenery_File();
vector<string> Input_Data_From_queries_File();

/* ---------------------Functions for the Seperate Simple hash table -----------------*/


HashTable_4<string> InsertIntoQuadProbHT1(vector<string>);
void SearchQuadProbHT1(vector<string>,HashTable_4<string>);
void QuadProbHT_Data_Gathering1(HashTable_4<string>,vector<string>,vector<string>);
void Print_QuadProbHT_Results1(float,float,int);

/*--------------------------------------------------------------------------------------*/

/*-------------------- Functions for the Linear Probing hash Table-------------------*/

HashTable_5<string> InsertIntoQuadProbHT2(vector<string>);
void SearchQuadProbHT2(vector<string>,HashTable_5<string>);
void QuadProbHT_Data_Gathering2(HashTable_5<string>,vector<string>,vector<string>);
void Print_QuadProbHT_Results2(float,float,int);

/*--------------------------------------------------------------------------------------*/

/*-------------------- Functions for the Quadradit Probing hash Table-------------------*/

HashTable_3<string> InsertIntoQuadProbHT3(vector<string>);
void SearchQuadProbH3(vector<string>,HashTable_3<string>);
void QuadProbHT_Data_Gathering3(HashTable_3<string>,vector<string>,vector<string>);
void Print_QuadProbHT_Results3(float,float,int);

/*--------------------------------------------------------------------------------------*/

int main(){
    
    /* Input Data from Ohenery file and queries file. And assign 
       then to a vector of strings.*/
    
   vector<string> DataArray  = Input_Data_From_Ohenery_File();
   vector<string> QueryArray = Input_Data_From_queries_File();
                                                                              
   /* simple hash function type*/
    HashTable_4<string> QuadProbHT1;
    QuadProbHT_Data_Gathering1(QuadProbHT1,DataArray,QueryArray);
    
    /*preflix hash function type*/
    HashTable_5<string>QuadProbHT2;
     QuadProbHT_Data_Gathering2(QuadProbHT2,DataArray,QueryArray);
    
    /* Full-length hash function*/
    HashTable_3<string> QuadProbHT3;
    QuadProbHT_Data_Gathering3(QuadProbHT3,DataArray,QueryArray);
    
    
    
    
    
    return 0;
}


vector<string> Input_Data_From_Ohenery_File(){
    
     /* Open the Ohenry.txt file and imput the data in the file into a vector of strings. */
    vector<string>DataArray;
    string Data;
    
    ifstream Ohenry;
    Ohenry.open("OHenry.txt");
     
    while(Ohenry>>Data){
        
        DataArray.push_back(Data);
    }
    /*------------------------------------------------------------------------------------*/
    
    return DataArray;
}
vector<string>Input_Data_From_queries_File(){
    
      /* Open the queries.txt file and imput the data in the file intoa vector of strings. */
    
    ifstream queries;
    queries.open("queries.txt");
    string keys; 
    
    vector<string>QueryArray;
    
    while(queries>>keys){
        
        QueryArray.push_back(keys);
    }
    /*-------------------------------------------------------------------------------------*/
    return QueryArray;
}

/* --------------------  -------------------------------------------------------------------*/


HashTable_4<string> InsertIntoQuadProbHT1( std:: vector<string> DataArray){
    
     HashTable_4<string> Sep;
  
     int sucessRate = 0;
    
     for(auto it = DataArray.begin();it != DataArray.end();it++){
        
        string temp = *it;
        bool temp1 = Sep.insert(temp);
         
        if(temp1 == true){
            
                sucessRate++;
            }
        
    }
    
    return Sep;
    
    
}
void SearchQuadProbHT1(vector<string>QueryArray,HashTable_4<string>QuadProbHT){
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = QuadProbHT.contains(temp2);     
      }
    
    
}
void QuadProbHT_Data_Gathering1(HashTable_4<string>QuadProbHT,vector<string> DataArray,vector<string>QueryArray){

     /*Recording the total insertion time for all the Data. */
    int start_s = clock();
            QuadProbHT = InsertIntoQuadProbHT1(DataArray);
    int stop_s = clock();
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  QuadProbHT.coll();
    
    
    int start_w = clock();
        SearchQuadProbHT1(QueryArray,QuadProbHT);
    int stop_w = clock();
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_QuadProbHT_Results1(Total_time,time1,Collisions);

}
void Print_QuadProbHT_Results1(float time,float time1, int Collisions){
    
      cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                               Simple hash function "<<endl;
    cout<<"                              "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" TIME RESULTS "<<"                                                             "<<endl;
    cout<< "                                                                          "<<endl;
    cout<<" Average Insertion Time(ALL):        "<< time<< "(Sec)"<< "                               "<<endl;
    cout<<" Average Insertion Time(PER):        "<<(time*1000)/(10377)<<"(ms)"<<"                    "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" Average Search time(ALL):           "<<time1<<"(Sec)"<<"                                 "<<endl;
    cout<<" Average Search Time(PER):           "<<(time1*1000)/(10377)<<"(Ms)"<<"                   "<<endl;
    cout<<"                                                                          "<<endl;
   // cout<<" Successfull Insertions:             "<<sucessRate<<"                             "<<endl;
    cout<<" Number of Collisions:               "<< Collisions <<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
}

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*****************************************************************************************************************************************/

/*-------------------- Functions for the Linear Probing hash Table-----------------------------------------------------------------------*/

HashTable_5<string> InsertIntoQuadProbHT2(vector<string> DataArray){
    
     HashTable_5<string> Sep2;
  
     int sucessRate = 0;
    
     for(auto it = DataArray.begin();it != DataArray.end();it++){
        
        string temp = *it;
        bool temp1 = Sep2.insert(temp);
         
        if(temp1 == true){
            
                sucessRate++;
            }
        
    }
    
    return Sep2;
}
void SearchQuadProbHT2(vector<string>QueryArray,HashTable_5<string>QuadProbHT){
    
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = QuadProbHT.contains(temp2);     
      }
}
void QuadProbHT_Data_Gathering2(HashTable_5<string>QuadProbHT,vector<string>DataArray,vector<string>QueryArray){
    
     
     /*Recording the total insertion time for all the Data. */
    int start_s = clock();
            QuadProbHT = InsertIntoQuadProbHT2(DataArray);
    int stop_s = clock();
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  QuadProbHT.coll();
    
    
    int start_w = clock();
        SearchQuadProbHT2(QueryArray,QuadProbHT);
    int stop_w = clock();
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_QuadProbHT_Results2(Total_time,time1,Collisions);
    
    
}
void Print_QuadProbHT_Results2(float time,float time1, int Collisions){
    
    
    cout<<"                                  Preflix hash function "<<endl;
    cout<<"                                    "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" TIME RESULTS "<<"                                                             "<<endl;
    cout<< "                                                                          "<<endl;
    cout<<" Average Insertion Time(ALL):        "<< time<< "(Sec)"<< "                               "<<endl;
    cout<<" Average Insertion Time(PER):        "<<(time*1000)/(10377)<<"(ms)"<<"                    "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" Average Search time(ALL):           "<<time1<<"(Sec)"<<"                                 "<<endl;
    cout<<" Average Search Time(PER):           "<<(time1*1000)/(10377)<<"(Ms)"<<"                   "<<endl;
    cout<<"                                                                          "<<endl;
   // cout<<" Successfull Insertions:             "<<sucessRate<<"                             "<<endl;
    cout<<" Number of Collisions:               "<< Collisions <<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
}

/*------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************************************************************************************/
/* ------------------------ Quadratic Ptobing Hashtable functions -----------------------------------------------------------------------------*/

HashTable_3<string> InsertIntoQuadProbHT3(vector<string>DataArray){
    
    
     HashTable_3<string> Sep1;
  
     int sucessRate = 0;
    
     for(auto it = DataArray.begin();it != DataArray.end();it++){
        
        string temp = *it;
        bool temp1 = Sep1.insert(temp);
         
        if(temp1 == true){
            
                sucessRate++;
            }
        
    }
    
    return Sep1;
}
void SearchQuadProbH3(vector<string>QueryArray,HashTable_3<string> QuadProbHT){
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = QuadProbHT.contains(temp2);     
      }
}
void QuadProbHT_Data_Gathering3(HashTable_3<string>QuadProbHT,vector<string> DataArray,vector<string>QueryArray){
    
   /* Recording the total insertion time for all the Data. */
    int start_s = clock();
            QuadProbHT = InsertIntoQuadProbHT3(DataArray);
    int stop_s = clock();
    
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  QuadProbHT.coll();
    
    
    int start_w = clock();
        SearchQuadProbH3(QueryArray,QuadProbHT);
    int stop_w = clock();
    
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_QuadProbHT_Results3(Total_time,time1,Collisions);
    
    
}
void Print_QuadProbHT_Results3(float time,float time1, int Collisions){
  
    cout<<"                                Full-length hash funct "<<endl;
    cout<<"                              "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" TIME RESULTS "<<"                                                             "<<endl;
    cout<< "                                                                          "<<endl;
    cout<<" Average Insertion Time(ALL):        "<< time<< "(Sec)"<< "                               "<<endl;
    cout<<" Average Insertion Time(PER):        "<<(time*1000)/(10377)<<"(ms)"<<"                    "<<endl;
    cout<<"                                                                          "<<endl;
    cout<<" Average Search time(ALL):           "<<time1<<"(Sec)"<<"                                 "<<endl;
    cout<<" Average Search Time(PER):           "<<(time1*1000)/(10377)<<"(Ms)"<<"                   "<<endl;
    cout<<"                                                                          "<<endl;
   // cout<<" Successfull Insertions:             "<<sucessRate<<"                             "<<endl;
    cout<<" Number of Collisions:               "<< Collisions <<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
}
    
/*---------------------------------------------------------------------------------------------------------------------------------------------*/






