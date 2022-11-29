#include<iostream>
#include<vector>
#include<cmath>
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

    file.open("1st_run_log.dat", ios::out);

    for (int i = 0; i < number_of_lines_1; i++)
    {
        file << a[i] << " " << log(b[i])  << endl;
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

    file.open("2nd_run_log.dat", ios::out);

    for (int i = 0; i < number_of_lines_2; i++)
    {
        file << c[i] << " " << log(d[i])  << endl;
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

    file.open("3rd_run_log.dat", ios::out);

    for (int i = 0; i < number_of_lines_3; i++)
    {
        file << e[i] << " " << log(f[i])  << endl;
    }

    file.close();
}