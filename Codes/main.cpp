/*
 This is the code I am writing to redo the work on stochastic aggregation by Hassan et. al.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<random>

using namespace std;

vector<float> ascending_arrange(vector<float> a)
{
    sort(a.begin(),a.end()); //sorting the input array
    int return_vector_size = *max_element(a.begin(),a.end()); /* the return vector is the number of elements of 
                                                                different sizes of particles so we need this variable
                                                                to get the size */
    vector<float> return_vector;
    return_vector.assign(return_vector_size,0); //declaring and initializing the return vector with all zeroes

    int start = 0, end = a.size(); //initialing the intermediate start and end point

    for(int r=1; r<=return_vector_size; r++) //iterator for getting numbers of different sizes of particles
    {
        for(int s=start; s<=end; s++) //intermediate iterator for getting the number of a particular size of particles
        {
            if(a[s] > r) //the iterator retured a value of input vector which is greater than particular size
            {
                return_vector[r-1] = s - start; // this step counts the aforementioned number
                start = s; //reinitializing the starting point of the 2nd for loop
                break;
            }
        }
    }
    
    return return_vector;
}
  
int main()
{

    vector<float> system_1, system_2, system_3; //declaring the system_1 of particles
    int system_size = 1000000; //initial size of the system of particles

    system_1.assign(system_size,1); //initializing the particle systems
    system_2.assign(system_size,1);
    system_3.assign(system_size,1);

    int no_of_runs[3] = {500000,600000,700000}; //no. of runs for the simulation 
    float p = 0.5; //probability for regeneration in the algorithm given by Hassan et. al

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
            if(test <= p) //checking the probabilistic generation condition
            {
                system_1[i] = system_1[j]; //probabilistic generation
            } 
            else 
            { 
                system_1.erase(system_1.begin()+i); //removing the zero element
            }
            cout << "succesful steps: " << successful_steps_1<< endl;
            successful_steps_1+=1; //increasing the variable value by 1 as one successful step has occurred
        }
    }

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
            if(test <= p) //checking the probabilistic generation condition
            {
                system_2[i] = system_2[j]; //probabilistic generation
            } 
            else 
            { 
                system_2.erase(system_2.begin()+i); //removing the zero element
            }
            cout << "succesful steps: " << successful_steps_2<< endl;
            successful_steps_2+=1; //increasing the variable value by 1 as one successful step has occurred
        }
    }

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
            if(test <= p) //checking the probabilistic generation condition
            {
                system_3[i] = system_3[j]; //probabilistic generation
            } 
            else 
            { 
                system_3.erase(system_3.begin()+i); //removing the zero element
            }
            cout << "succesful steps: " << successful_steps_3<< endl;
            successful_steps_3+=1; //increasing the variable value by 1 as one successful step has occurred
        }
    }
    
    ofstream file;
    file.open("500000 steps.dat"); //opening a file to write the data

    vector<float> final_result_1 = ascending_arrange(system_1); //vector to get the final result in case 2
    int i = 1; //a variable for printing out particle size

    for (auto& v : final_result_1){
        file << i << " " << v << endl; //printing out particle size and respective numbers
        i++;
    }
    file.close();

    file.open("600000 steps.dat"); //opening a file to write the data

    vector<float> final_result_2 = ascending_arrange(system_2); //vector to get the final result in case 2
    int j = 1; //a variable for printing out particle size

    for (auto& v : final_result_2){
        file << j << " " << v << endl; //printing out particle size and respective numbers
        j++;
    }
    file.close();

    file.open("700000 steps.dat"); //opening a file to write the data

    vector<float> final_result_3 = ascending_arrange(system_3); //vector to get the final result in case 3
    int k = 1; //a variable for printing out particle size

    for (auto& v : final_result_3){
        file << k << " " << v << endl; //printing out particle size and respective numbers
        k++;
    }
    file.close();

    return 0;
} 
