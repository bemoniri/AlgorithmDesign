#include<bits/stdc++.h>

using namespace std; 
  
int main() 
{ 
    
    vector< pair <int,int> > vect; 
  
    int number;
    cin>>number;
    
    int radius[number]; 
    int height[number];
    
    for(int j = 1; j <= number; j++){
		cin>>radius[j-1];
		cin>>height[j-1];
	}
    
    int n = sizeof(radius)/sizeof(radius[0]); 
  
    for (int i=0; i<n; i++) 
        vect.push_back( make_pair(radius[i],height[i]) ); 
      
    /*
    for (int i=0; i<n; i++) 
    { 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
    } */
  
    sort(vect.begin(), vect.end()); 
    
    /*cout << "The vector after sort operation is:\n" ; 
    for (int i=0; i<n; i++) 
    {  
        cout << vect[i].first << " "<< vect[i].second << endl; 
    } */
	int num_packs = 0;
	
	for (int i = n-1; i>=0; i--){
		if(vect[i].first != -1){
			int top_height =  vect[i].second;
			for (int j = i-1; j >= 0; j--){
				if(vect[j].first != -1){
					if(vect[j].second<top_height){
						top_height = vect[j].second;
						vect[j].first = -1;
					}
				}
			}		
		}
	}
    
    for (int i=0; i<n; i++) 
    {  
        if (vect[i].first != -1)
			num_packs ++;
    }
    
    cout<<num_packs;
    return 0; 
} 
