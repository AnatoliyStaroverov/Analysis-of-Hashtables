#include<iostream>
#include<vector>
#include<fstream>
#include <cstdlib>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>

#include"SeperateChaining.h"
#include"LinearProbing.h"
#include"QuadraticProbing.h"

using namespace std;


vector<string> Input_Data_From_Ohenery_File();
vector<string> Input_Data_From_queries_File();

/* ---------------------Functions for the Seperate Chaining hash table -----------------*/

int Get_SucRate(int Rate);
HashTable_1<string> InsertIntoChainingHT(vector<string>);
void SearchChainingHT(vector<string>,HashTable_1<string>);
void ChainingHT_Data_Gathering(HashTable_1<string>,vector<string>,vector<string>);
void Print_ChainingHT_Results(float,float,int);

/*--------------------------------------------------------------------------------------*/

/*-------------------- Functions for the Linear Probing hash Table-------------------*/

HashTable_2<string> InsertIntoLinearProbHT(vector<string>);
void SearchLinearProbHT(vector<string>,HashTable_2<string>);
void LinearProbHT_Data_Gathering(HashTable_2<string>,vector<string>,vector<string>);
void Print_LinearProbHT_Results(float,float,int);

/*--------------------------------------------------------------------------------------*/

/*-------------------- Functions for the Quadradit Probing hash Table-------------------*/

HashTable_3<string> InsertIntoQuadProbHT(vector<string>);
void SearchQuadProbH(vector<string>,HashTable_3<string>);
void QuadProbHT_Data_Gathering(HashTable_3<string>,vector<string>,vector<string>);
void Print_QuadProbHT_Results(float,float,int);

/*--------------------------------------------------------------------------------------*/

int main(){
    
   /* Input Data from Ohenery file and queries file. And assign 
       then to a vector of strings.*/
    
   vector<string> DataArray  = Input_Data_From_Ohenery_File();
   vector<string> QueryArray = Input_Data_From_queries_File();
                                                                              
   /*SeperateChainning HashTable:  */
    HashTable_1<string> ChainingHT;
    ChainingHT_Data_Gathering(ChainingHT,DataArray,QueryArray);
    
    /*Linear Probing Hash Table   */
    HashTable_2<string>LinearProbHT;
     LinearProbHT_Data_Gathering(LinearProbHT,DataArray,QueryArray);
    
    /* QuadraticProbing Hashtable: */
    HashTable_3<string> QuadProbHT;
    QuadProbHT_Data_Gathering(QuadProbHT,DataArray,QueryArray);
    
    
    
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

/* -------------------- Seperation by Chaining Hashtable functions -------------------------------------------------------------------*/

int Get_SucRate(int Rate){ return Rate;}
HashTable_1<string> InsertIntoChainingHT( std:: vector<string> DataArray){
    
     HashTable_1<string> Sep;
  
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
void SearchChainingHT(vector<string>QueryArray,HashTable_1<string>ChainingHT){
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = ChainingHT.contains(temp2);     
      }
    
    
}
void ChainingHT_Data_Gathering(HashTable_1<string>ChainingHT,vector<string> DataArray,vector<string>QueryArray){

     /*Recording the total insertion time for all the Data. */
    int start_s = clock();
            ChainingHT = InsertIntoChainingHT(DataArray);
    int stop_s = clock();
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  ChainingHT.coll();
    
    
    int start_w = clock();
        SearchChainingHT(QueryArray,ChainingHT);
    int stop_w = clock();
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_ChainingHT_Results(Total_time,time1,Collisions);

}
void Print_ChainingHT_Results(float time,float time1, int Collisions){
    
      cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                                  HashTable"<<endl;
    cout<<"                              SeperateChaining"<<endl;
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

HashTable_2<string> InsertIntoLinearProbHT(vector<string> DataArray){
    
     HashTable_2<string> Sep2;
  
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
void SearchLinearProbHT(vector<string>QueryArray,HashTable_2<string>LinearProbHT){
    
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = LinearProbHT.contains(temp2);     
      }
}
void LinearProbHT_Data_Gathering(HashTable_2<string>LinearProbHT,vector<string>DataArray,vector<string>QueryArray){
    
     
     /*Recording the total insertion time for all the Data. */
    int start_s = clock();
            LinearProbHT = InsertIntoLinearProbHT(DataArray);
    int stop_s = clock();
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  LinearProbHT.coll();
    
    
    int start_w = clock();
        SearchLinearProbHT(QueryArray,LinearProbHT);
    int stop_w = clock();
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_LinearProbHT_Results(Total_time,time1,Collisions);
    
    
}
void Print_LinearProbHT_Results(float time,float time1, int Collisions){
    
    
    cout<<"                                  HashTable"<<endl;
    cout<<"                                Linear Probing"<<endl;
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

HashTable_3<string> InsertIntoQuadProbHT(vector<string>DataArray){
    
    
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
void SearchQuadProbH(vector<string>QueryArray,HashTable_3<string> QuadProbHT){
    
      for(auto it = QueryArray.begin();it != QueryArray.end();it++){
          
          string temp2 = *it;
          bool temp3 = QuadProbHT.contains(temp2);     
      }
}
void QuadProbHT_Data_Gathering(HashTable_3<string>QuadProbHT,vector<string> DataArray,vector<string>QueryArray){
    
   /* Recording the total insertion time for all the Data. */
    int start_s = clock();
            QuadProbHT = InsertIntoQuadProbHT(DataArray);
    int stop_s = clock();
    
    float Total_time = (stop_s-start_s) / double(CLOCKS_PER_SEC)*100;
    
    int Collisions =  QuadProbHT.coll();
    
    
    int start_w = clock();
        SearchQuadProbH(QueryArray,QuadProbHT);
    int stop_w = clock();
    
     float time1 = (stop_w-start_w)/double(CLOCKS_PER_SEC)*100;

    Print_QuadProbHT_Results(Total_time,time1,Collisions);
    
    
}
void Print_QuadProbHT_Results(float time,float time1, int Collisions){
  
    cout<<"                                  HashTable"<<endl;
    cout<<"                              Quadratic Probing"<<endl;
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



