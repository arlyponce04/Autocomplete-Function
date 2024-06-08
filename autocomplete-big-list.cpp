#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    //Checking the Number of Arguments. There has to be 3: program, filename, number!
    if(argc!=3)
    {
        cerr<<"Arguments do not equal 3. "<<endl;
        return 1;
    }

    //Parsing the Second Argument to an integer using stoi
    int num = stoi(argv[2]);

    //Open File and Read Contents
    ifstream file(argv[1]);
    if(!file.is_open())
    {
        cerr<<"Unable to open file."<<endl;
    }
    cout<<"File Opened."<<endl;

    //Use list to store
    list<pair<int, string>> cityList;
    string str;
    int i =0;
    
    /*
    Use stringstream to ignore white space and put the two columns in the text file in a list
    so that we can create our own output
    */
    while(getline(file, str))
    {   
        stringstream ss(str);
        int population;
        string nameCity;

        ss>>population;
        ss.ignore();
        getline(ss, nameCity);

        cityList.push_back(make_pair(population, nameCity));
        i++;
    }
    file.close();

    //Enter Input and Loop Until CTRL-D
    cout<<"Enter the initial letters of a city to find its similarily name cities, ranked by population (this is case-sensitive): "<<endl;
    string city;
    while(cin>>city)
    { 
    cout<<endl;
    cout<<"TOP MATCHES FOR '"<<city<<"' ARE: "<<endl;
    int counter = 1;

    
      for(auto& item : cityList)
        {
            if(item.second.compare(0, city.length(), city) == 0)
            {
                cout<<counter<<") "<<item.second<<" has a population of "<<item.first<<endl;
                counter++;
                if(counter>num)
                {
                    break;
                }
            
            }
        
        }  

    
    
    
    cout<<"\nAnother city? (use CTRL-D to exit)"<<endl;
    }

    //EOF Condition to Satisfy CTRL-D
    if(!cin.eof())
    {
        cerr<<"Input Error.";
    }
    return 0;
}

