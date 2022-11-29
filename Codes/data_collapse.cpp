#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<fstream> 

using namespace std;

int main()
{
    fstream file;
    file.open("500000 steps.dat", ios::in); //opening the first run data file
    if(!file){
        cout << "Error" <<endl; //error_message if the file isn't there
        return 0;
    }

    vector<float> a, b; //two vector arrays to read the data
    float a1, b1; //two intermediate variables to read line by line 
    int number_of_lines_1 = 0;
    while(file >> a1 >> b1)
    {
        a.push_back(a1);
        b.push_back(b1);
        number_of_lines_1++;
    }

    file.close();

    float time_1 = 1.0/accumulate(b.begin(),b.end(),0); //calculation of time from the given formula in Hassan et. al
    float p = 0.5; //regeneration probability; 
    float exponent_1 = 2/(1+p), exponent_2 = (1+p)/(p-1); 

    file.open("data_collapse_1.dat", ios::out);

    for (int i = 0; i < number_of_lines_1; i++)
    {
        file << pow(time_1,exponent_2)*a[i] << " " << log(pow(time_1,exponent_1)*b[i])  << endl;
    }

    file.close();

    file.open("600000 steps.dat", ios::in);
    if(!file){
        cout << "Error" <<endl;
        return 0;
    }

    vector<float> c, d;
    float a2, b2;
    int number_of_lines_2 = 0;
    while(file >> a2 >> b2)
    {
        c.push_back(a2);
        d.push_back(b2);
        number_of_lines_2++;
    }

    file.close();

    float time_2 = 1.0/accumulate(d.begin(),d.end(),0); //calculation of time from the given formula in Hassan et. al

    file.open("data_collapse_2.dat", ios::out);

    for (int i = 0; i < number_of_lines_2; i++)
    {
        file << pow(time_2,exponent_2)*c[i] << " " << log(pow(time_2,exponent_1)*d[i])  << endl;
    }

    file.close();

    file.open("700000 steps.dat", ios::in);
    if(!file){
        cout << "Error" <<endl;
        return 0;
    }

    vector<float> e, f;
    float a3, b3;
    int number_of_lines_3 = 0;
    while(file >> a3 >> b3)
    {
        e.push_back(a3);
        f.push_back(b3);
        number_of_lines_3++;
    }

    file.close();

    float time_3 = 1.0/accumulate(f.begin(),f.end(),0);

    file.open("data_collapse_3.dat", ios::out);

    for (int i = 0; i < number_of_lines_3; i++)
    {
        file << pow(time_3,exponent_2)*e[i] << " " << log(pow(time_3,exponent_1)*f[i])  << endl;
    }

    file.close();

    return 0;
}