#include<bits/stdc++.h>

using namespace std;

int* BubbleSort(int* value);
int* InsertionSort(int* value);
int* SelectionSort(int* value);
int* HeapSort(int* value);
int* MergeSort(int* value);
int* QuickSort(int* value);
int* RadixSort(int* value);

int main()
{
    try
    {
        bool isR = false;
        string nums;
        getline(cin, nums);
        int *value, *original;
        int numsize;

        if(nums.at(0) == 'r')
        {
            isR = true;
            istringstream query(nums);
            string stringbuffer;

            getline(query, stringbuffer, ' ');
            numsize = atoi(stringbuffer.c_str());
            getline(query, stringbuffer, ' ');
            int rminimum = atoi(stringbuffer.c_str());
            getline(query, stringbuffer, ' ');
            int rmaximum = atoi(stringbuffer.c_str());

            srand((unsigned int)time(0));

            value = new int[numsize];
            original = new int[numsize];
            for(int i=0; i<numsize; i++){
                value[i] = rand() % (rmaximum - rminimum + 1) + rminimum ;
                original[i] = value[i];
            } 
        }
        else
        {
            numsize = atoi(nums.c_str());
            value = new int[numsize];
            original = new int[numsize];
            for(int i=0; i<numsize; i++) {
                cin >> value[i];
                original[i] = value[i];
            }
        }
        cout << "--------" << endl;
        while(1)
        {
            char s; cin >> s;
            clock_t start = clock();
            switch(s)
            {
                case 'B':
                    value = BubbleSort(value);
                    break;
                case 'I' :
                    value = InsertionSort(value);
                    break;
                case 'S' :
                    value = SelectionSort(value);
                    break;
                case 'H' :
                    value = HeapSort(value);
                    break;
                case 'M' :
                    value = MergeSort(value);
                    break;
                case 'Q' :
                    value = QuickSort(value);
                    break;
                case 'R' :
                    value = RadixSort(value);
                    break;
                
            }  
            if(isR) cout << clock() - start << " ms" << endl;
            else
            {
                for(int i=0; i<numsize; i++)
                    cout << value[i] << endl;
            }
            cout << "-----------" << endl;
            
        }
        
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}

/// TODO

int* BubbleSort(int* value)
{
    return value;
}
int* InsertionSort(int* value)
{
    return value;
}
int* SelectionSort(int* value)
{
    return value;
}
int* HeapSort(int* value)
{
    return value;
}
int* MergeSort(int* value)
{
    return value;
}
int* QuickSort(int* value)
{
    return value;
}
int* RadixSort(int* value)
{
    return value;
}