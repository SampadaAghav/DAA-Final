#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
// this custom comparator funcƟon will allow
// us to compare our vector based on the 
// raƟo of values to weights
bool compare(pair <float, int> p1, pair <float, int> p2) 
{ 
 return p1.first > p2.first; 
} 
int fractional_knapsack(vector <int> weights, vector <int> values, int capacity) 
{ 
 int len = weights.size(); 
 int total_value = 0; 
 // vector to store the items based on their value/weight raƟos
 vector <pair <float, int>> ratio(len, make_pair(0.0, 0)); 
 for(int i = 0; i < len; i++) 
 ratio[i] = make_pair(values[i]/weights[i], i); 

 sort(ratio.begin(), ratio.end(), compare); 
 // start selecƟng the items
 for(int i = 0; i < len; i++) 
 { 
 if(capacity == 0) 
 break; 
 int index = ratio[i].second; 
 if(weights[index] <= capacity) 
 { 
 // we item can fit into the knapsack 
 // hence take the whole of it 
 capacity -= weights[index]; 
 // add the value of this item to the 
 // final answer 
 total_value += values[index]; 
 } 
 else 
 { 
 // this item doesn't fit into the bag 
 // and thus we take a fracƟon of it
 int value_to_consider = values[index] * (float(capacity)/float(weights[index])); 
 total_value += value_to_consider; 
 capacity = 0; 
 } 
 } 
 return total_value; 
} 
int main() 
{ 
 cout << "Enter the weights of the items, press -1 to stop" << endl; 
 vector <int> weights; 
 while(true) 
 { 
 int weight; 
 cin >> weight; 
 if(weight == -1) 
 break; 
 weights.push_back(weight); 
 } 
 cout << "Enter the values of each item, press -1 to stop" << endl; 
 
 vector <int> values; 
 while(true) 
 { 
 int value; 
 cin >> value; 
 if(value == -1) 
 break; 
 values.push_back(value); 
 } 
 cout << "Enter the capacity of the knapsack" << endl; 
 int capacity; 
 cin >> capacity; 
 cout << "The maximum value possible based on current list is: " << fractional_knapsack(weights, values, capacity) 
<< endl; 
}