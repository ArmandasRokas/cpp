#include <cmath>
# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using std::cin ; // This allows us to use some ab br ev ia ti on s
using std::cout;                   // For example , we can write cin instead of std :: cin

int findMax(int input[], int n);

int main () // This the main entry of the program
{
    int l,n; 
    cin >> l;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    } 
    
    int max = findMax(input, n);
    
    // Find the values of intervals and create an array, where each elements represents interval
    int k = ceil((double) max/l);
   // cout << "max: "<<  max  << " l: " << l <<" k: " << k << endl;
    int intervals[l];  
    
    // Set all elements to be equal 0
    for(int i = 0; i < l; i++){
        intervals[i] = 0;
    }

    // for each elements check which interval it tilhoerer
    for(int i = 0; i < n; i++){
         int currInterval;   
        for( currInterval = 1; currInterval < l; currInterval++){
            if(input[i] < currInterval*k){
                break;
            }
            // if(input[i]<k){
            //     intervals[0]++;
            //     break;
            // }
            // if(input[i]>x*k && input[i]<(x+1)*k){
            //     intervals[x]++;
            //     break;
            // }
            // if(input[i] > k*(x-1)){
            //     intervals[1]++;
            //     break;
            // }
        }
        intervals[currInterval-1]++;
    }

    for(int i = 0; i < l; i++){
        cout << k*i << ": " << intervals[i] << std::endl;
    }

   // cout << max << endl;
    
    return 0;
}

int findMax(int input[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max<input[i]){
            max = input[i];
        }
    }
    return max;
}