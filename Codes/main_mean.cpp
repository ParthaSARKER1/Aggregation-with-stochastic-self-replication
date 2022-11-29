/*This code generates the data for mean size of particles in no. of runs*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<numeric>
#include<random>

using namespace std;

int main()
{
    vector<float> system_1, system_2, system_3; //declaring the system_1 of particles
    int system_size = 50000; //initial size of the system of particles

    system_1.assign(system_size,1); //initializing the particle systems
    system_2.assign(system_size,1);
    system_3.assign(system_size,1);

    int no_of_runs[3] = {20000,20000,20000}; //no. of runs for the simulation 
    float p[3] = {0.5,0.3,0.1}; //probability for regeneration in the algorithm given by Hassan et. al

    /*
    code for generating random int distribution to choose from
    system_1 vector indices
    */
    int min = 0; 
    default_random_engine eng;
    uniform_real_distribution<float> distr_1(0.0,1.0);
    /*
    Next I will apply the main algorithm used in the paper by Hassan et. al
    */
    ofstream file;
    file.open("mean_p=0.5"); //opening a file to write the data

    int successful_steps_1 = 0; //a variable to check whether a step was a valid one
    while(successful_steps_1<=no_of_runs[0])
    {
        uniform_int_distribution<int> distr(min,system_1.size()-1); /*producing a random number engine to generate 
                                                                    random numbers in the range of vector indices*/
        int i = distr(eng); //generating two random indices
        int j = distr(eng);

        if(i!=j) //checking the equality of two indices two remove events of 'self-aggregation'
        {
            system_1[j] += system_1[i]; //main aggregation happens in this step
            system_1[i] = 0; //nullifying one of the sites

            float test = distr_1(eng); //generating a random number in the interval (0,1)
            if(test <= p[0]) //checking the probabilistic generation condition
            {
                system_1[i] = system_1[j]; //probabilistic generation
            } 
            else 
            { 
                system_1.erase(system_1.begin()+i); //removing the zero element
            }
            successful_steps_1+=1; //increasing the variable value by 1 as one successful step has occurred
        }
        float number_of_particles = system_1.size(); //variable to return total number of particles at a step
        float mean_size = accumulate(system_1.begin(),system_1.end(),0)/number_of_particles; //mean size of particles at a step
        float time = 1.0 / number_of_particles;
        file << log(time) << " " << log(mean_size) << endl;
    }

    file.close();
    cout << "1st process ended" <<endl;

    file.open("mean_p=0.3");
    int successful_steps_2 = 0; //a variable to check whether a step was a valid one
    while(successful_steps_2<=no_of_runs[1])
    {
        uniform_int_distribution<int> distr(min,system_2.size()-1); /*producing a random number engine to generate 
                                                                    random numbers in the range of vector indices*/
        int i = distr(eng); //generating two random indices
        int j = distr(eng);

        if(i!=j) //checking the equality of two indices two remove events of 'self-aggregation'
        {
            system_2[j] += system_2[i]; //main aggregation happens in this step
            system_2[i] = 0; //nullifying one of the sites

            float test = distr_1(eng); //generating a random number in the interval (0,1)
            if(test <= p[1]) //checking the probabilistic generation condition
            {
                system_2[i] = system_2[j]; //probabilistic generation
            } 
            else 
            { 
                system_2.erase(system_2.begin()+i); //removing the zero element
            }
            successful_steps_2+=1; //increasing the variable value by 1 as one successful step has occurred
        }

        float number_of_particles = system_2.size(); //variable to return total number of particles at a step
        float mean_size = accumulate(system_2.begin(),system_2.end(),0)/number_of_particles; //mean size of particles at a step
        float time = 1.0 / number_of_particles;
        file << log(time) << " " << log(mean_size) << endl;

    }

    file.close();
    cout << "2nd process ended" << endl;

    file.open("mean_p=0.1");
    int successful_steps_3 = 0; //a variable to check whether a step was a valid one
    while(successful_steps_3<=no_of_runs[2])
    {
        uniform_int_distribution<int> distr(min,system_3.size()-1); /*producing a random number engine to generate 
                                                                    random numbers in the range of vector indices*/
        int i = distr(eng); //generating two random indices
        int j = distr(eng);

        if(i!=j) //checking the equality of two indices two remove events of 'self-aggregation'
        {
            system_3[j] += system_3[i]; //main aggregation happens in this step
            system_3[i] = 0; //nullifying one of the sites

            float test = distr_1(eng); //generating a random number in the interval (0,1)
            if(test <= p[2]) //checking the probabilistic generation condition
            {
                system_3[i] = system_3[j]; //probabilistic generation
            } 
            else 
            { 
                system_3.erase(system_3.begin()+i); //removing the zero element
            }
            successful_steps_3+=1; //increasing the variable value by 1 as one successful step has occurred
        }

        float number_of_particles = system_3.size(); //variable to return total number of particles at a step
        float mean_size = accumulate(system_3.begin(),system_3.end(),0)/number_of_particles; //mean size of particles at a step
        float time = 1.0 / number_of_particles;
        file << log(time) << " " << log(mean_size) << endl;
    }

    file.close();
    cout << "3rd process ended" <<endl;
    return 0;
}